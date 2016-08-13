#define Integration_cxx
#include "Integration.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <string>

void Integration::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L Integration.C
//      Root > Integration t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch


   if (fChain == 0) return;
   
  
   
   TString origPath = PathName;
   string temp = origPath;
   temp = temp.substr(0, temp.size() - 5);
   TString newPath = temp;

   //cout << "newPath: " << newPath << " origPath.Substring(0, origPath.Length() - 5): " << origPath.SubString(0, origPath.Length() - 5) << endl; //For Debugging
   newPath += "_Analyzed.root";

   //Added
   TFile* myfile = new TFile(newPath, "RECREATE");

   //cerr << "newpath " << newPath << endl;


   TH1F* integralhist = new TH1F("integralhist", "Integral underneath specified range", 200, -5, 5);
   TH1F* pedestal = new TH1F("pedestal", "Pedestal Histogram", 200, -5, 5);
   TH1F* subtractedIntegral = new TH1F("subtractedIntegral", "Subtracted Integral: Area - noise", 200, -5, 5);
   TH2F* donIntegral = new TH2F("donIntegral", "X: Raw Int, Y: Pedestal", 200, -5, 5, 200, -5, 5);
   TH2F* eventonint = new TH2F("eventonint", "X: event #, Y: Integral", 5000, 0, 5000, 200, -5, 5);
   TH2F* eventonped = new TH2F("eventonped", "X: event #, Y: Pedestal", 5000, 0, 5000, 200, -5, 5);
   //TH2F* meanEvent = new TH2F("meanEvent", "X: time, Y: voltage", ) // Waiting for help with this
   double oldpedestal = 0;


   
   //Added to program

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
   
	  if (jentry % 100  == 0) {
		  cout <<"Analyzing event # " << jentry << endl;
	  }

	  //***********************************************************************
	  //			Integrating One at a time
	  //***********************************************************************
	  double intvariable = 0;
	  for (int i = LowIntegral; i < HighIntegral; i++) {
		  intvariable += c1[i];
	  }

	  integralhist->Fill(intvariable);

	  //cout << "Var: " << intvariable << endl;

	  //***********************************************************************
	  //			Pedestal Subtraction
	  //***********************************************************************
	  double pedvariable = 0;
	  for (int i = LowPedestal; i < HighPedestal; i++) {
		  pedvariable += c1[i];
	  }
	  pedestal->Fill(pedvariable);
	  //cout << "Var: " << intvariable << endl;
	  
	  //if(pedestal - oldpedestal > 1){
	  //cout <<"Event #" <<jentry <<" has a prior pedestal to current pedestal difference of > 1. " <<endl;
	  //}

	  oldpedestal = pedestal; //Added to find out the difference between pedestal figures event by event


	  //***********************************************************************
	  //			Subtracting Pedestal from Integral
	  //***********************************************************************

	  double ratioSigtoPed = (HighIntegral - LowIntegral) / (HighPedestal - LowPedestal);
	  double subtracted = intvariable - pedvariable * ratioSigtoPed;

	  subtractedIntegral->Fill(subtracted);


	  //***********************************************************************
	  //			Evaluating Raw Integral vs Pedestal for clarification
	  //***********************************************************************

	  donIntegral->Fill(intvariable, pedvariable);

	  eventonint->Fill(event,intvariable);
	  eventonped->Fill(event,pedvariable);

   }
   
   //cout << "Var: " << intvariable << endl;
   //cout << "Got to end of Loop" << endl;

   //***********************************************************************
   //						Displaying to Root Browser
   //***********************************************************************
   //Canvas_1->Divide(1, 2);
   //Canvas_1->cd(1);
   //integralhist->Draw();
   //Canvas_1->cd(2);
   //pedestal->Draw();
   integralhist->Write();
   pedestal->Write();
   subtractedIntegral->Write();
   donIntegral->Write();
   eventonint->Write();
   eventonped->Write();
   //cout << "Got to end of program" << endl;
   //myfile->Write();
   //cout << "wrote File" << endl;
   myfile->Close();
  // getchar();

}
