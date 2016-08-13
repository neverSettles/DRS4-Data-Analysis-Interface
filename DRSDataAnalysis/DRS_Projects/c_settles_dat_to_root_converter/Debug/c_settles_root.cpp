//
// ********************************************************************************
// *               DRS4 binary data analysis program                              *
// *                                                                              *
// *  This is a analysis program written initially to analyze the                 *
// *  data from DRS4 for PSI muon beam compression experiment.                    *
// *  It can be used for any experiments. List of experiments using it:           *
// *  1) Muon Beam Compression at PSI, Oct 2011                                   *
// *  2) Development of PSF Tracker at ETH, Nov 2011                              *
// *                                                                              *
// *  Documentation of DRS4 can be found at                                       *
// *  http://drs.web.psi.ch/docs/manual_rev31.pdf                                 *
// *                                                                              *
// *  Author : Kim Siang KHAW (ETH Zurich, 27.10.2011)                            *
// *  Contact : khaw@phys.ethz.ch                                                 *
// *                                                                              *
// *  History:                                                                    *
// *  1st Edition : Basic histograms for visualization implemented. (27.10.2011)  *
// *  2nd Edition : Tree and Branches are implemented. (02.11.2011)               *
// *              : Compare [0-100]bins and [101-200]bins for RMS and mean        *
// *                calculations.                                                 *
// *              : Flagging events with more than one peak. (13.11.2011)         *
// *  3rd Edition : Calculation of area below the pulse are implemented.          *
// *                (23.11.2011)                                                  *
// *  3.1 Edition : First 10 events from CH1 and CH2 are saved. S/N are           *
// *                calculated.                                                   *
// *                (12.12.2011)                                                  *
// *                                                                              *
// ********************************************************************************
//

// include std libraries
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>

// include ROOT libraries
#include "TH1.h"
#include "TH2.h"
#include "TF1.h"
#include "TTree.h"
#include "TChain.h"
#include "TGraph.h"
#include "TStyle.h"
#include "TFolder.h"
#include "TCanvas.h"
#include "TRandom.h"
#include "TMath.h"
#include "TFile.h"
#include "TSystem.h"
#include "TProfile.h"

using namespace std;

#pragma warning(disable : 4996)
void c_settles_root(int argc, char **argv)
{
	main(int argc, char **argv);
}

int main(int argc, char **argv)
{

	cout <<
		"********************************************************************" <<
		endl;
	cout <<
		"*****              Welcome to DRS4 data analysis               *****" <<
		endl;
	cout <<
		"********************************************************************" <<
		endl;
	cout << endl;

	ifstream file;		// read file directly

	if (argc == 2)
	{
		file.open(argv[1], ios::in | ios::binary);
		cout << ">> Opening file " << argv[1] << " ......" << endl;
		cout << endl;
		if (!file.is_open())
		{			// terminate if the file can't be opened
			cerr << "!! File open error:" << argv[1] << endl;
			return 1;
		}
	}

	else
	{				// terminate if there is no input file or more than 1 input file
		cerr << "!! No input file" << endl;
		return 1;
	}

	// automatically change XXXX.dat to XXXX.root
	int file_len = strlen(argv[1]);
	string filename = argv[1];
	filename.replace(file_len - 3, 3, "root");

	// input file from DRS4, (obsolete, data file is now 1st argument of the exe prog)
	// ifstream file ("no-He-aligned.dat", ios::in | ios::binary);

	// create a new rootfile here
	TFile *treefile = new TFile((char *)filename.c_str(), "recreate");
	cout << ">> Creating rootfile " << filename << " ......" << endl;
	cout << endl;

	// Save waveform of 1st 5 events
	TH1F *CH1event1 = new TH1F("CH1event1", "CH1event1", 1024, 0, 1024);
	TH1F *CH1event2 = new TH1F("CH1event2", "CH1event2", 1024, 0, 1024);
	TH1F *CH1event3 = new TH1F("CH1event3", "CH1event3", 1024, 0, 1024);
	TH1F *CH1event4 = new TH1F("CH1event4", "CH1event4", 1024, 0, 1024);
	TH1F *CH1event5 = new TH1F("CH1event5", "CH1event5", 1024, 0, 1024);

	TH1F *CH2event1 = new TH1F("CH2event1", "CH2event1", 1024, 0, 1024);
	TH1F *CH2event2 = new TH1F("CH2event2", "CH2event2", 1024, 0, 1024);
	TH1F *CH2event3 = new TH1F("CH2event3", "CH2event3", 1024, 0, 1024);
	TH1F *CH2event4 = new TH1F("CH2event4", "CH2event4", 1024, 0, 1024);
	TH1F *CH2event5 = new TH1F("CH2event5", "CH2event5", 1024, 0, 1024);

	TH1F *CH3event1 = new TH1F("CH3event1", "CH3event1", 1024, 0, 1024);
	TH1F *CH3event2 = new TH1F("CH3event2", "CH3event2", 1024, 0, 1024);
	TH1F *CH3event3 = new TH1F("CH3event3", "CH3event3", 1024, 0, 1024);
	TH1F *CH3event4 = new TH1F("CH3event4", "CH3event4", 1024, 0, 1024);
	TH1F *CH3event5 = new TH1F("CH3event5", "CH3event5", 1024, 0, 1024);

	TH1F *CH4event1 = new TH1F("CH4event1", "CH4event1", 1024, 0, 1024);
	TH1F *CH4event2 = new TH1F("CH4event2", "CH4event2", 1024, 0, 1024);
	TH1F *CH4event3 = new TH1F("CH4event3", "CH4event3", 1024, 0, 1024);
	TH1F *CH4event4 = new TH1F("CH4event4", "CH4event4", 1024, 0, 1024);
	TH1F *CH4event5 = new TH1F("CH4event5", "CH4event5", 1024, 0, 1024);

	// Define some simple structures
	struct Time_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct NewTime_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct Amplitude_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct Area_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct Mean_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct RMS_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct SoverN_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct RC_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};


	Float_t TimeScale;

	struct Dt_t
	{
		Float_t ch1;
		Float_t ch2;
		Float_t ch3;
		Float_t ch4;
	};

	struct Flag_t
	{
		Bool_t good_entrance;
		Bool_t good_P1;
		Bool_t good_P2;
		Bool_t multipeak_ch1;
		Bool_t multipeak_ch2;
		Bool_t multipeak_ch3;
		Bool_t multipeak_ch4;
	};

	struct Event_t
	{
		Int_t event;
	};


	// define time and amplitude to be fill in tree
	Time_t peaktime;
	NewTime_t newtime;
	Amplitude_t amplitude;
	Area_t area;
	Mean_t mean;
	RMS_t rms;
	SoverN_t sovern;
	Dt_t dt;
	Flag_t flag;
	Event_t event;

	float c1[1024];
	float c2[1024];
	float c3[1024];
	float c4[1024];

	int t1[1024];
	int t2[1024];
	int t3[1024];
	int t4[1024];

	// Create a ROOT Tree
	TTree *tree =
		new TTree("T", "An example of ROOT tree with a few branches");
	tree->Branch("event", &event, "event/I");
	tree->Branch("peaktime", &peaktime, "ch1:ch2:ch3:ch4");
	tree->Branch("amplitude", &amplitude, "ch1:ch2:ch3:ch4");
	tree->Branch("mean", &mean, "ch1:ch2:ch3:ch4");
	tree->Branch("RMS", &rms, "ch1:ch2:ch3:ch4");

	
	tree->Branch("TimeScale", &TimeScale, "TimeScale"); //Added both of these lines

	tree->Branch("c1", c1, "c1[1024]/F");
	tree->Branch("c2", c2, "c2[1024]/F");
	tree->Branch("c3", c3, "c3[1024]/F");
	tree->Branch("c4", c4, "c4[1024]/F");

	tree->Branch("t1", t1, "t1[1024]/I");
	tree->Branch("t2", t2, "t2[1024]/I");
	tree->Branch("t3", t3, "t3[1024]/I");
	tree->Branch("t4", t4, "t4[1024]/I");

	char EventHeader[5];
	int SerialNumber;
	short Date[8];
	float EventTime[1024];
	char ChannelHeader[5];
	//  unsigned short RawChannelData[1024];
	unsigned short ChannelDataRaw[1024];
	float ScalerData;
	unsigned short ChannelData[1024];
	float ChannelDataVoltage[1024];
	bool loopchannel = true;
	bool endoffile = false;
	int n(0);
	double time1(0);
	clock_t start = clock();
	time_t realtime;

	cout << ">> Start reading file" << argv[1] << " ......" << endl;
	cout << endl;


	// Read additional headers introduced in v5 of DRS software
	char tmpFileHeader[5];
	file.read((char *)&tmpFileHeader, 4);
	cout << "tmpFileHeader: ";
	cout << tmpFileHeader << std::endl;

	// Read additional headers introduced in v5 of DRS software
	char tmpTimeHeader[5];
	file.read((char *)&tmpTimeHeader, 4);
	cout << "tmpTimeHeader: "; //Added
	cout << tmpTimeHeader << "\n";
	char tmpBoardSerialNumber[5];
	file.read((char *)&tmpBoardSerialNumber, 4);
	cout << "tmpBoardSerialNumber: " << tmpBoardSerialNumber << endl; // Added


	char tmpChannel1Header[5];
	file.read((char *)&tmpChannel1Header, 4);
	cout << "tmpChannelHeader: "; //Added
	cout << tmpChannel1Header << "\n";
	float tmpEventTime[1024];
	file.read((char *)&tmpEventTime, 4096);

	TimeScale = tmpEventTime[0];

	/*
	char tmpChannel2Header[5];
	file.read((char *)&tmpChannel2Header, 4);
	cout << "tmpChannel2Header: ";
	cout << tmpChannel2Header << "\n";
	file.read((char *)&tmpEventTime, 4096);

	char tmpChannel3Header[5];
	file.read((char *)&tmpChannel3Header, 4);
	cout << "tmpChannel3Header: ";
	cout << tmpChannel3Header << "\n";
	file.read((char *)&tmpEventTime, 4096);

	char tmpChannel4Header[5];
	file.read((char *)&tmpChannel4Header, 4);
	cout << "tmpChannel4Header: ";
	cout << tmpChannel4Header << "\n";
	file.read((char *)&tmpEventTime, 4096);

	*/
	// Read event header
	file.read((char *)&EventHeader, 4);
	EventHeader[4] = '\0';

	cout << EventHeader << "\n";
	cout << "\nSTART\n";

	while (!endoffile)
	{				// event loop

		// Count Event, show the progress every 1000 events
		if (n % 1000 == 0)
		{
			time(&realtime);
			cout << ">> Processing event No." << n << ", Time elapsed : " <<
				(double)(clock() -
				start) /
				CLOCKS_PER_SEC << " secs, Current time : " << ctime(&realtime) <<
				endl;
			//start = clock ();
		}


		++n;			//  n + 1

		event.event = n;

		// Read serial number
		file.read((char *)&SerialNumber, 4);



		// Read date (YY/MM/DD/HH/mm/ss/ms/rr)
		file.read((char *)&Date, 16);
		/*
		RC = Date[7]; //Added by Settles
		cout << "(RC) = " << RC << endl;
		cout << "Date[7] (RC) = " << Date[7] << endl;
		cout << "Data[6] (RC) = " << Date[6] << endl;
		cout << "Date[5] (RC) = " << Date[5] << endl;
		cout << "Date[4] (RC) = " << Date[4] << endl;
		cout << "Date[3] (RC) = " << Date[3] << endl;
		cout << "Date[2] (RC) = " << Date[2] << endl;
		cout << "Date[1] (RC) = " << Date[1] << endl;
		cout << "Date[0] (RC) = " << Date[0] << endl;
		*/

		//        int LastTime;
		//        int CurrentTime;
		//        int PassedTime;
		//        int RunTime;

		// calculate time since last event in milliseconds
		//        LastTime = CurrentTime;
		//        CurrentTime =
		//          Date[3] * 3600000 + Date[4] * 60000 + Date[5] * 1000 + Date[6];

		// Read event times
		//cout << "BOARD\n";
		char tmpBoardNumber[5];
		file.read((char *)&tmpBoardNumber, 4);
		//cout << tmpBoardNumber << "\n";

		//cout << "TRIGGER\n";
		char tmpTriggerCell[5];
		file.read((char *)&tmpTriggerCell, 4);
		//cout << tmpTriggerCell << "\n";

		while (loopchannel)	// loop all available channels. When reach end of event, will be stopped.
		{

			// Read channel header
			file.read((char *)&ChannelHeader, 4);
			ChannelHeader[4] = '\0';
			//std::cout << "Channel Header in File Reader : " << ChannelHeader << std::endl; // Deleted this

			if (strcmp(ChannelHeader, "EHDR") == 0)
			{
				break;
			}

			else if (file.eof())
			{
				endoffile = true;
				break;
			}

			file.read((char *)&ScalerData, 4);

			// get amplitude of each channel
			file.read((char *)&ChannelDataRaw, 2048);

			for (int i = 0; i < 1024; i++)
			{
				ChannelData[i] = ChannelDataRaw[i];
				ChannelDataVoltage[i] = ChannelDataRaw[i] / 65535. - 0.5;
			}

			//for (int i = 450; i < 550; i++) {
			//	std::cout << "don EventTime: " << i << " " << tmpEventTime[i] << " " <<ChannelDataRaw[i] <<" " <<ChannelDataVoltage[i] <<endl;
				
			//}

			// Find the base line using average 
			double v_RMS[5];

			for (int j = 0; j < 5; j++)
			{
				v_RMS[j] = TMath::RMS(&ChannelData[j * 200], &ChannelData[(j + 1) * 200]);	// calculate RMS for 5 sections
				//          cout<<"v_RMS["<<j<<"] : "<<v_RMS[j]<<endl;
			}

			int index_v_RMS = TMath::LocMin(5, v_RMS);	// locate the section for minimum RMS 
			double vRMS = v_RMS[index_v_RMS];	// use RMS in that section
			double vmean = TMath::Mean(&ChannelData[index_v_RMS * 200], &ChannelData[(index_v_RMS + 1) * 200]);	// use mean in that section

			// Find Max and Min of the Channel data (Voltage)
			int index_min = TMath::LocMin(1024, ChannelData);	// return index of the min
			double vmin = ChannelData[index_min];	// return value of the vmin
			double tmin = EventTime[index_min];	// return value of the tmin

			//std::cout << "About to enter channel 1" << std::endl;
			//std::cout << "don Char:" << ChannelHeader << std::endl; //Deleted this
			//std::cout << "don String:" << (string)ChannelHeader << std::endl; //Deleted This

			//cout << "CHeader: " << ChannelHeader << " n: " << n << endl;
			if (strcmp(ChannelHeader, "C001") == 0)
			{
				for (int i = 0; i < 1024; i++)
				{
					if (n == 1)
					{
						//cout << "Don!" << i <<" " << ChannelDataVoltage[i]<< endl;
						CH1event1->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 2)
					{
						CH1event2->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 3)
					{
						CH1event3->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 4)
					{
						CH1event4->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 5)
					{
						CH1event5->Fill(i, ChannelDataVoltage[i]);
					}
				}


				// Fill in the tree for ch1
				amplitude.ch1 = vmean - vmin;
				peaktime.ch1 = tmin;
				mean.ch1 = vmean;
				rms.ch1 = vRMS;

				for (int i = 0; i < 1024; i++)
				{
					c1[i] = ChannelDataVoltage[i];
					t1[i] = i;
					//std::cout<<"KKK "<<c1[i]<<" "<<t1[i]<<" "<<event.event<<std::endl; // Deleted this
				}
			}			// end of channel 1

			else if (strcmp(ChannelHeader, "C002") == 0)
			{
				for (int i = 0; i < 1024; i++)
				{
					if (n == 1)
					{
						CH2event1->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 2)
					{
						CH2event2->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 3)
					{
						CH2event3->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 4)
					{
						CH2event4->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 5)
					{
						CH2event5->Fill(i, ChannelDataVoltage[i]);
					}
				}


				// Fill in the tree for ch2
				amplitude.ch2 = vmean - vmin;
				peaktime.ch2 = tmin;
				mean.ch2 = vmean;
				rms.ch2 = vRMS;

				for (int i = 0; i < 1024; i++)
				{
					c2[i] = ChannelDataVoltage[i];
					t2[i] = i;
					// std::cout<<"KKK "<<c1[i]<<" "<<ChannelDataVoltage[i]<<std::endl;
				}
			}			// end of channel 2

			else if (strcmp(ChannelHeader, "C003") == 0)
			{
				for (int i = 0; i < 1024; i++)
				{
					if (n == 1)
					{
						CH3event1->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 2)
					{
						CH3event2->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 3)
					{
						CH3event3->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 4)
					{
						CH3event4->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 5)
					{
						CH3event5->Fill(i, ChannelDataVoltage[i]);
					}
				}


				// Fill in the tree for ch3
				amplitude.ch3 = vmean - vmin;
				peaktime.ch3 = tmin;
				mean.ch3 = vmean;
				rms.ch3 = vRMS;

				for (int i = 0; i < 1024; i++)
				{
					c3[i] = ChannelDataVoltage[i];
					t3[i] = i;
					// std::cout<<"KKK "<<c1[i]<<" "<<ChannelDataVoltage[i]<<std::endl;
				}

			}			// end of channel 3



			else if (strcmp(ChannelHeader, "C004") == 0)
			{
				for (int i = 0; i < 1024; i++)
				{
					if (n == 1)
					{
						CH4event1->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 2)
					{
						CH4event2->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 3)
					{
						CH4event3->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 4)
					{
						CH4event4->Fill(i, ChannelDataVoltage[i]);
					}
					if (n == 5)
					{
						CH4event5->Fill(i, ChannelDataVoltage[i]);
					}
				}


				// Fill in the tree for ch4
				amplitude.ch4 = vmean - vmin;
				peaktime.ch4 = tmin;
				mean.ch4 = vmean;
				rms.ch4 = vRMS;

				for (int i = 0; i < 1024; i++)
				{
					c4[i] = ChannelDataVoltage[i];
					t4[i] = i;
					// std::cout<<"KKK "<<c1[i]<<" "<<ChannelDataVoltage[i]<<std::endl;
				}
			}			// end of channel 4
		}			// end of channel loop

		tree->Fill();		// fill the tree event by event 

		if (file.eof())
		{
			cout << ">> Reach End of the file .... " << endl;
			cout << ">> Total event no." << n << endl;
			endoffile = true;
			break;
		}
	}				// end of event loop

	//  tree->Print ();
	cout << "The tree was saved." << endl;
	treefile->Write();
	treefile->Close();
	cout << "The treefile was saved." << endl;


	file.close();

	//     ofile1.close ();
	//     ofile2.close ();
	//     ofile3.close ();
	//     ofile4.close ();

	return 0;

}

/*

int main(int argc, char argv[])
{
	return 0;
}
*/
