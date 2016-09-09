// Mainframe macro generated from application: root
// By ROOT version 5.34/36 on 2016-08-04 21:28:17

//Developed by Christopher Settles
//Fermilab Summer Intern 2016
//Waubonsee Community College

#ifndef ROOT_TGDockableFrame
#include "TGDockableFrame.h"
#endif
#ifndef ROOT_TGMenu
#include "TGMenu.h"
#endif
#ifndef ROOT_TGMdiDecorFrame
#include "TGMdiDecorFrame.h"
#endif
#ifndef ROOT_TG3DLine
#include "TG3DLine.h"
#endif
#ifndef ROOT_TGMdiFrame
#include "TGMdiFrame.h"
#endif
#ifndef ROOT_TGMdiMainFrame
#include "TGMdiMainFrame.h"
#endif
#ifndef ROOT_TGMdiMenu
#include "TGMdiMenu.h"
#endif
#ifndef ROOT_TGListBox
#include "TGListBox.h"
#endif
#ifndef ROOT_TGNumberEntry
#include "TGNumberEntry.h"
#endif
#ifndef ROOT_TGScrollBar
#include "TGScrollBar.h"
#endif
#ifndef ROOT_TGComboBox
#include "TGComboBox.h"
#endif
#ifndef ROOT_TGuiBldHintsEditor
#include "TGuiBldHintsEditor.h"
#endif
#ifndef ROOT_TGuiBldNameFrame
#include "TGuiBldNameFrame.h"
#endif
#ifndef ROOT_TGFrame
#include "TGFrame.h"
#endif
#ifndef ROOT_TGFileDialog
#include "TGFileDialog.h"
#endif
#ifndef ROOT_TGResourcePool
#include "TGResourcePool.h"
#endif
#ifndef ROOT_TGShutter
#include "TGShutter.h"
#endif
#ifndef ROOT_TGButtonGroup
#include "TGButtonGroup.h"
#endif
#ifndef ROOT_TGCanvas
#include "TGCanvas.h"
#endif
#ifndef ROOT_TGFSContainer
#include "TGFSContainer.h"
#endif
#ifndef ROOT_TGFontDialog
#include "TGFontDialog.h"
#endif
#ifndef ROOT_TGuiBldEditor
#include "TGuiBldEditor.h"
#endif
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
#endif
#ifndef ROOT_TGProgressBar
#include "TGProgressBar.h"
#endif
#ifndef ROOT_TGTextEdit
#include "TGTextEdit.h"
#endif
#ifndef ROOT_TGButton
#include "TGButton.h"
#endif
#ifndef ROOT_TGFSComboBox
#include "TGFSComboBox.h"
#endif
#ifndef ROOT_TGLabel
#include "TGLabel.h"
#endif
#ifndef ROOT_TGMsgBox
#include "TGMsgBox.h"
#endif
#ifndef ROOT_TRootGuiBuilder
#include "TRootGuiBuilder.h"
#endif
#ifndef ROOT_TGTab
#include "TGTab.h"
#endif
#ifndef ROOT_TGListView
#include "TGListView.h"
#endif
#ifndef ROOT_TGTextEntry
#include "TGTextEntry.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGView
#include "TGView.h"
#endif
#ifndef ROOT_TGIcon
#include "TGIcon.h"
#endif
#ifndef ROOT_TGDoubleSlider
#include "TGDoubleSlider.h"
#endif
#ifndef ROOT_TGToolBar
#include "TGToolBar.h"
#endif
#ifndef ROOT_TRootEmbeddedCanvas
#include "TRootEmbeddedCanvas.h"
#endif
#ifndef ROOT_TCanvas
#include "TCanvas.h"
#endif
#ifndef ROOT_TGuiBldDragManager
#include "TGuiBldDragManager.h"
#endif
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGObject
#include "TGObject.h"
#endif
#ifndef ROOT_TROOT
#include "TROOT.h"
#endif

#include "Riostream.h"

#include <TGClient.h>
#include <TGButton.h>
#include <TGFrame.h>
#include <TTree.h>
#include <string>
#include <stdio.h>

class MyMainFrame : public TGMainFrame {

private:
	TGCompositeFrame *fCframe;
	TGTextButton     *fBrowse, *fExit, *ConvertButton, *ViewButton, *GenerateButton, *ViewPedButton, *ViewSigButton, *ViewSigMPedButton;
	TGTextEntry		*FilePath;
	TGNumberEntry *LowNoiseNum, *HighNoiseNum, *LowSignalNum, *HighSignalNum;
	TH1F PedHist, SigHist, SigMPedHist, AvgHist;
	bool MacroLoaded;
	

public:
	MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h);
	virtual ~MyMainFrame();
	// slots
	void ChangeStartLabel();
	void ChangePauseLabel();

	ClassDef(MyMainFrame, 0)
};

/*
void MyMainFrame::ChangeStartLabel()
{
	// Slot connected to the Clicked() signal.
	// It will toggle labels "Start" and "Stop".

	fBrowse->SetState(kButtonDown);
	if (!start) {
		fBrowse->SetText("&Stop");
		start = kTRUE;
	}
	else {
		fBrowse->SetText("&Start");
		start = kFALSE;
	}
	fBrowse->SetState(kButtonUp);
}

void MyMainFrame::ChangePauseLabel()
{
	// Slot connected to the Clicked() signal.
	// It will toggle labels "Resume" and "Pause".

	fPause->SetState(kButtonDown);
	if (!pause) {
		fPause->SetText("&Resume");
		pause = kTRUE;
	}
	else {
		fPause->SetText("&Pause");
		pause = kFALSE;
	}
	fPause->SetState(kButtonUp);
}

*/

//***********************************************************************
//			Controls for Generate Button
//***********************************************************************
void MyMainFrame::GenerateClicked()
{
	//TString path = "\"F:\\DRS_Projects\\c_settles_root\\Debug\\c_settles_root.exe\" ";
	//path += FilePath->GetText();

	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += ".root";
	cout << rootpath << endl; // For Debugging

	TString newrootpath = rootpath;

	TFile *f = new TFile(newrootpath);
	if ((!f) || f->IsZombie()) { delete f; return; } // just a precaution
	TTree* T; 
	f->GetObject("T", T);
	if (!T) { delete f; return; } // just a precaution
	
	cout << "Debug 1" << endl;
	int lowSig = (int)LowSignalNum->GetNumber();
	int highSig = (int)HighSignalNum->GetNumber();
	int lowNoise = (int)LowNoiseNum->GetNumber();
	int highNoise = (int)HighNoiseNum->GetNumber();

	cout << "Low sig: " << lowSig << " High Sig: " << highSig << " Low Noise: " << lowNoise << " High Noise: " << highNoise << endl;

	if (!MacroLoaded) 
	{
		gROOT->LoadMacro("C:\\DRSDataAnalysis\\DRS_Projects\\Integration\\Integration.C");
		MacroLoaded = true;
	}
	//printf("Printf: Integration integral(\"%s\" , %i, %i, %i, %i );", rootpath, lowSig, highSig, lowNoise, highNoise);
	//cout << "Issue: " << sprintf(newrootpath, "Integration integral(\"%s\" , %i, %i, %i, %i );", rootpath, lowSig, highSig, lowNoise, highNoise) << endl;


	char command[500];
	sprintf(command, "Integration integral(\"%s\" , %i, %i, %i, %i );", rootpath.c_str(), lowSig, highSig, lowNoise, highNoise);
	puts(command);
	cout << "command: " << command << endl;
	gROOT->ProcessLineSync(command);
	//gROOT->ProcessLineSync(sprintf("Integration integral(\"%s\", %i, %i, %i, %i );",  rootpath, lowSig, highSig, lowNoise, highNoise));
	//gRoot->ProcessLineSync("integral.Loop()");
	cout << "Generation of analyzed file complete." << endl;

}

//***********************************************************************
//			Controls for ViewPed Button
//***********************************************************************
void MyMainFrame::ViewPedClicked()
{
	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += "_Analyzed.root";
	cout << rootpath << endl; // For Debugging
	TString newrootpath = rootpath;

	TFile f(newrootpath);
	TH1F *ptrhist = NULL;
	f.GetObject("pedestal", ptrhist);
	PedHist =  * ( (TH1F*) ptrhist->Clone());
	PedHist.SetName("Pedestal Histogram");
	TCanvas *PedCanvas = new TCanvas("PedCanvas", "Pedestal Canvas" , 900,600);

	PedHist.Draw();
	PedCanvas->Update();

}

//***********************************************************************
//			Controls for ViewSig Button
//***********************************************************************
void MyMainFrame::ViewSigClicked()
{
	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += "_Analyzed.root";
	cout << rootpath << endl; // For Debugging

	TString newrootpath = rootpath;


	TFile f(newrootpath);
	TH1F *ptrhist = NULL;
	f.GetObject("integralhist", ptrhist);
	SigHist = *((TH1F*)ptrhist->Clone());
	SigHist.SetName("Signal Histogram");
	TCanvas *SigCanvas = new TCanvas("SigCanvas", "Signal Canvas", 900, 600);
	SigHist.Draw();

	SigCanvas->Update();

}

//***********************************************************************
//			Controls for ViewSigMPed Button
//***********************************************************************
void MyMainFrame::ViewSigMPedClicked()
{
	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += "_Analyzed.root";
	cout << rootpath << endl; // For Debugging

	TString newrootpath = rootpath;


	TFile f(newrootpath);
	TH1F *ptrhist = NULL;
	f.GetObject("subtractedIntegral", ptrhist);
	SigMPedHist = *((TH1F*)ptrhist->Clone());
	SigMPedHist.SetName("Signal Minus Pedestal");

	TCanvas *SigMPedCanvas = new TCanvas("SigMPedCanvas", "Signal minus pedestal Canvas", 900, 600);
	SigMPedHist.Draw();
	SigMPedCanvas->Update();
}

//***********************************************************************
//			Controls for View Button
//***********************************************************************
void MyMainFrame::ViewClicked()
{
	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += ".root";
	cout << rootpath << endl; // For Debugging

	TString newrootpath;
	newrootpath = rootpath;

	TFile f(newrootpath);
	TTree* mytree = NULL;
	f.GetObject("T", mytree);
	TCanvas *HistCanvas = new TCanvas("HistCanvas", "Histogram of 1000 events", 900, 600);
	mytree->Draw("c1:t1");
	//CH1event1->Draw();
	HistCanvas->Update();

}

//***********************************************************************
//			Controls for ViewAverage Button
//***********************************************************************
void MyMainFrame::ViewAverageClicked()
{
	string rootpath = FilePath->GetText();
	rootpath = rootpath.substr(0, rootpath.length() - 4);
	rootpath += "_Analyzed.root";
	cout << rootpath << endl; // For Debugging
	TString newrootpath = rootpath;

	TFile f(newrootpath);
	TH1F *ptrhist = NULL;
	f.GetObject("average", ptrhist);
	AvgHist = *((TH1F*)ptrhist->Clone());
	AvgHist.SetName("Average of all events");
	TCanvas *AvgCanvas = new TCanvas("AvgCanvas", "Average Canvas", 900, 600);

	AvgHist.Draw();
	AvgCanvas->Update();
}
//***********************************************************************
//			Controls for Browse Button
//***********************************************************************
void MyMainFrame::BrowseClicked()
{
	//cout << "Button was clicked" << endl;

	const char *filetypes[] = { "Binary (DRS) Files", "*.dat",
	"All files",     "*",
	0,               0 };

	static TString dir(".");
	TGFileInfo fi;
	fi.fFileTypes = filetypes;
	fi.fIniDir = "C:\\DRSDataAnalysis\\DRS_Data";
	printf("fIniDir = %s\n", fi.fIniDir);
	new TGFileDialog(gClient->GetRoot(), this, kFDOpen, &fi);
	printf("Open file: %s (dir: %s)\n", fi.fFilename, fi.fIniDir);
	dir = fi.fIniDir;
	FilePath->SetText(fi.fFilename);

	if ( strlen(FilePath->GetText()) != 0)
	{
		ConvertClicked();
		ViewClicked();
	}
	else {
		cout << "No file selected!" << endl;
	}
}

//***********************************************************************
//			Controls for Convert Button
//***********************************************************************

void MyMainFrame::ConvertClicked()
{
	//gROOT->Macro("c_settles_root.cpp(1,\"file path\")");
	//gROOT->ProcessLine(".x c_settles_root.cpp(1,\"file path\")");
	cout << "Starting conversion..." << endl;
	TString path = "\"C:\\DRSDataAnalysis\\DRS_Projects\\c_settles_dat_to_root_converter\\Release\\c_settles_root.exe\" ";
	path += FilePath->GetText();
	system(path);
	cout << "Conversion complete!" << endl;
}

//***********************************************************************
//***********************************************************************
//***********************************************************************
//***********************************************************************
//***********************************************************************
//						Frame Controls
//***********************************************************************
//***********************************************************************
//***********************************************************************
//***********************************************************************
//***********************************************************************

MyMainFrame::MyMainFrame(const TGWindow *p, UInt_t w, UInt_t h) :
	TGMainFrame(p, w, h)
{
	
	TGFont *ufont;         // will reflect user font changes
	ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

	TGGC   *uGC;           // will reflect user GC changes
						   // graphics context changes

	MacroLoaded = false;

	//***********************************************************************
	//			Controls for Browse Button
	//***********************************************************************
	GCValues_t valigLabel;
	valigLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valigLabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valigLabel.fBackground);
	valigLabel.fFillStyle = kFillSolid;
	valigLabel.fFont = ufont->GetFontHandle();
	valigLabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valigLabel, kTRUE);
	TGLabel *Browselabel = new TGLabel(this, "Selecting a file will automatically convert it to root, and display the initial histogram. ", uGC->GetGC());
	Browselabel->SetTextJustify(36);
	Browselabel->SetMargins(0, 0, 0, 0);
	Browselabel->SetWrapLength(-1);
	this->AddFrame(Browselabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	Browselabel->MoveResize(400, 272, 128, 18);


	fBrowse = new TGTextButton(this, "&Browse for DRS Binary (.dat) file......");
	fBrowse->Connect("Clicked()", "MyMainFrame", this, "BrowseClicked()");
	//fCframe->AddFrame(fBrowse, new TGLayoutHints(kLHintsTop | kLHintsRight,3, 2, 2, 2)); // Don't need to add a new frame
	AddFrame(fBrowse, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	fBrowse->SetToolTipText("Click to browse for binary files you wish to convert to root.");

	

	//***********************************************************************
	//			Controls for FilePath Text Field
	//***********************************************************************

	GCValues_t valath;
	valath.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valath.fForeground);
	gClient->GetColorByName("#e8e8e8", valath.fBackground);
	valath.fFillStyle = kFillSolid;
	valath.fFont = ufont->GetFontHandle();
	valath.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valath, kTRUE);

	FilePath = new TGTextEntry(this, new TGTextBuffer(31), -1, uGC->GetGC(), ufont->GetFontStruct(), kSunkenFrame | kOwnBackground);
	FilePath->SetMaxLength(4096);
	FilePath->SetAlignment(kTextLeft);
	FilePath->SetText("");
	FilePath->Resize(360, FilePath->GetDefaultHeight());

	AddFrame(FilePath, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	FilePath->MoveResize(8, 8, 360, 22);

	//fCframe->AddFrame(FilePath, new TGLayoutHints(100,0,0,0));
	//Now adding the Text field to the Frame directly instead of adding an additional frame to avoid confusion
	//AddFrame(fCframe, new TGLayoutHints(2, 2, 5, 18)); // Don't need to use an additional frame anymore



	//***********************************************************************
	//			Controls for Convert Button
	//***********************************************************************

	/*
	ConvertButton = new TGTextButton(this, "Convert binary (DRS) to root", -1, TGTextButton::GetDefaultGC()(), TGTextButton::GetDefaultFontStruct(), kRaisedFrame);
	ConvertButton->SetTextJustify(36);
	ConvertButton->SetMargins(0, 0, 0, 0);
	ConvertButton->SetWrapLength(-1);
	ConvertButton->Resize(192, 24);
	this->AddFrame(ConvertButton, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	ConvertButton->MoveResize(0, 40, 192, 24);*/

	ConvertButton = new TGTextButton(this, "Convert binary (DRS) to root");
	ConvertButton->Connect("Clicked()", "MyMainFrame", this, "ConvertClicked()");
	AddFrame(ConvertButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ConvertButton->SetToolTipText("Click to convert the DRS binary file to root");


	//***********************************************************************
	//			Controls for View Button
	//***********************************************************************

	ViewButton = new TGTextButton(this, "View ROOT histogram");
	ViewButton->Connect("Clicked()", "MyMainFrame", this, "ViewClicked()");
	AddFrame(ViewButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ViewButton->SetToolTipText("Click to view the histogram of voltage vs time * events");

	//***********************************************************************
	//			Controls for Labels and Number Fields
	//***********************************************************************\

	GCValues_t valLabel;
	valLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valLabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valLabel.fBackground);
	valLabel.fFillStyle = kFillSolid;
	valLabel.fFont = ufont->GetFontHandle();
	valLabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valLabel, kTRUE);
	TGLabel *RangeLabel = new TGLabel(this, "Enter the Integration ranges for the lower noise range, upper noise range, lower signal range, and upper signal range.", uGC->GetGC());
	RangeLabel->SetTextJustify(36);
	RangeLabel->SetMargins(0, 0, 0, 0);
	RangeLabel->SetWrapLength(-1);
	this->AddFrame(RangeLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	RangeLabel->MoveResize(0, 240, 664, 24);
		

	
	//Lower Pedestal Range
	GCValues_t valabel;
	valabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valabel.fBackground);
	valabel.fFillStyle = kFillSolid;
	valabel.fFont = ufont->GetFontHandle();
	valabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valabel, kTRUE);
	TGLabel *LowNLabel = new TGLabel(this, "Lower Noise Range", uGC->GetGC());
	LowNLabel->SetTextJustify(36);
	LowNLabel->SetMargins(0, 0, 0, 0);
	LowNLabel->SetWrapLength(-1);
	this->AddFrame(LowNLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	LowNLabel->MoveResize(8, 272, 112, 18);
	LowNoiseNum = new TGNumberEntry(this, (Double_t)0, 13, -1, (TGNumberFormat::EStyle) 5);
	LowNoiseNum->SetName("LowNoiseNum");
	this->AddFrame(LowNoiseNum, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	LowNoiseNum->MoveResize(10, 296, 110, 22);

	ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");



	//Higher Pedestal Range
	GCValues_t valLabel;
	valLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valLabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valLabel.fBackground);
	valLabel.fFillStyle = kFillSolid;
	valLabel.fFont = ufont->GetFontHandle();
	valLabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valLabel, kTRUE);
	TGLabel *HighNLabel = new TGLabel(this, "Higher Noise Range", uGC->GetGC());
	HighNLabel->SetTextJustify(36);
	HighNLabel->SetMargins(0, 0, 0, 0);
	HighNLabel->SetWrapLength(-1);
	this->AddFrame(HighNLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	HighNLabel->MoveResize(144, 272, 112, 18);
	HighNoiseNum = new TGNumberEntry(this, (Double_t)0, 13, -1, (TGNumberFormat::EStyle) 5);
	HighNoiseNum->SetName("HighNoiseNum");
	this->AddFrame(HighNoiseNum, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	HighNoiseNum->MoveResize(136, 296, 110, 22);

	ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");
	//Lower Signal Range
	GCValues_t valgLabel;
	valgLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valgLabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valgLabel.fBackground);
	valgLabel.fFillStyle = kFillSolid;
	valgLabel.fFont = ufont->GetFontHandle();
	valgLabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valgLabel, kTRUE);
	TGLabel *LowSigLabel = new TGLabel(this, "Lower Signal Range", uGC->GetGC());
	LowSigLabel->SetTextJustify(36);
	LowSigLabel->SetMargins(0, 0, 0, 0);
	LowSigLabel->SetWrapLength(-1);
	this->AddFrame(LowSigLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	LowSigLabel->MoveResize(272, 272, 112, 18);
	LowSignalNum = new TGNumberEntry(this, (Double_t)0, 13, -1, (TGNumberFormat::EStyle) 5);
	LowSignalNum->SetName("LowSignalNum");
	this->AddFrame(LowSignalNum, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	LowSignalNum->MoveResize(272, 296, 110, 22);

	//Higher Signal Range
	GCValues_t valigLabel;
	valigLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
	gClient->GetColorByName("#000000", valigLabel.fForeground);
	gClient->GetColorByName("#e8e8e8", valigLabel.fBackground);
	valigLabel.fFillStyle = kFillSolid;
	valigLabel.fFont = ufont->GetFontHandle();
	valigLabel.fGraphicsExposures = kFALSE;
	uGC = gClient->GetGC(&valigLabel, kTRUE);
	TGLabel *HighSigLabel = new TGLabel(this, "Higher Signal Range", uGC->GetGC());
	HighSigLabel->SetTextJustify(36);
	HighSigLabel->SetMargins(0, 0, 0, 0);
	HighSigLabel->SetWrapLength(-1);
	this->AddFrame(HighSigLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	HighSigLabel->MoveResize(400, 272, 128, 18);
	HighSignalNum = new TGNumberEntry(this, (Double_t)0, 13, -1, (TGNumberFormat::EStyle) 5);
	HighSignalNum->SetName("HighSignalNum");
	this->AddFrame(HighSignalNum, new TGLayoutHints(kLHintsLeft | kLHintsTop, 2, 2, 2, 2));
	HighSignalNum->MoveResize(400, 296, 110, 22);

	ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

	///////////////////////////////////////////////////////Setting Default Values //////////////////////////////////////////////
	int const defaultLowNoise = 100;

	char defaultLowNoiseS[100]; sprintf(defaultLowNoiseS, "%i", defaultLowNoise);
	LowNoiseNum->SetText(defaultLowNoiseS);

	int const defaultHighNoise = 300;

	char defaultHighNoiseS[100]; sprintf(defaultHighNoiseS, "%i", defaultHighNoise);
	HighNoiseNum->SetText(defaultHighNoiseS);

	int const defaultLowSignal = 700;

	char defaultLowSignalS[100]; sprintf(defaultLowSignalS, "%i", defaultLowSignal);
	LowSignalNum->SetText(defaultLowSignalS);

	int const defaultHighSignal = 900;

	char defaultHighSignalS[100]; sprintf(defaultHighSignalS, "%i", defaultHighSignal);
	HighSignalNum->SetText(defaultHighSignalS);

	//***********************************************************************
	//			Controls for Generate Button
	//***********************************************************************

	GenerateButton = new TGTextButton(this, "Generate analyzed root file");
	GenerateButton->Connect("Clicked()", "MyMainFrame", this, "GenerateClicked()");
	AddFrame(GenerateButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	GenerateButton->SetToolTipText("Click to generate the analyzed root file containing the pedestal integral, signal integral, and signal - pedestal integral.");

	//***********************************************************************
	//			Controls for ViewPed Button
	//***********************************************************************

	ViewPedButton = new TGTextButton(this, "View Pedestal");
	ViewPedButton->Connect("Clicked()", "MyMainFrame", this, "ViewPedClicked()");
	AddFrame(ViewPedButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ViewPedButton->SetToolTipText("View Pedestal distribution from generated file.");

	//***********************************************************************
	//			Controls for ViewSig Button
	//***********************************************************************

	ViewSigButton = new TGTextButton(this, "View Signal");
	ViewSigButton->Connect("Clicked()", "MyMainFrame", this, "ViewSigClicked()");
	AddFrame(ViewSigButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ViewSigButton->SetToolTipText("View Singal distribution from generated file.");

	//***********************************************************************
	//			Controls for ViewSigMPed Button
	//***********************************************************************

	ViewSigMPedButton = new TGTextButton(this, "View Noise Subtracted from Signal");
	ViewSigMPedButton->Connect("Clicked()", "MyMainFrame", this, "ViewSigMPedClicked()");
	AddFrame(ViewSigMPedButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ViewSigMPedButton->SetToolTipText("View Singal - Noise distribution from generated file.");

	//***********************************************************************
	//			Controls for ViewAverage Button
	//***********************************************************************

	ViewAverageButton = new TGTextButton(this, "View Average of all events");
	ViewAverageButton->Connect("Clicked()", "MyMainFrame", this, "ViewAverageClicked()");
	AddFrame(ViewAverageButton, new TGLayoutHints(kLHintsTop | kLHintsLeft, 5, 5, 2, 2));
	ViewAverageButton->SetToolTipText("View Average of all events");


	//***********************************************************************
	//			Controls for Exit Button
	//***********************************************************************
	fExit = new TGTextButton(this, "&Exit ", "gApplication->Terminate(0)");
	AddFrame(fExit, new TGLayoutHints(kLHintsTop, 5, 5, 2, 2));

	/*
	start = kFALSE;

	fPause = new TGTextButton(fCframe, "&Pause");
	fPause->Connect("Clicked()", "MyMainFrame", this, "ChangePauseLabel()");
	fPause->SetToolTipText("Click to toggle the button label (Pause/Resume)");
	fCframe->AddFrame(fPause, new TGLayoutHints(kLHintsTop | kLHintsExpandX,
		3, 2, 2, 2));
	pause = kFALSE;
	*/

	
	//***********************************************************************
	//			Controls for General Window Management
	//***********************************************************************
	SetWindowName("DRS4 Data Analysis");

	MapSubwindows();
	Resize(GetDefaultSize());
	MapWindow();
}


MyMainFrame::~MyMainFrame()
{
	// Clean up all widgets, frames and layouthints that were used
	fCframe->Cleanup();
	Cleanup();
}


void GuiApp()
{
	//Open the GUI Class
	//gROOT->LoadMacro("Integration.C");
	new MyMainFrame(gClient->GetRoot(), 600, 500);

}
