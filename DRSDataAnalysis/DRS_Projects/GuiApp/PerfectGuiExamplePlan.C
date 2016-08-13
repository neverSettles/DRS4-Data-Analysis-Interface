// Mainframe macro generated from application: root
// By ROOT version 5.34/36 on 2016-08-04 21:57:25

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
#ifndef ROOT_TGColorSelect
#include "TGColorSelect.h"
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
#ifndef ROOT_TGSplitter
#include "TGSplitter.h"
#endif
#ifndef ROOT_TGStatusBar
#include "TGStatusBar.h"
#endif
#ifndef ROOT_TGListTree
#include "TGListTree.h"
#endif
#ifndef ROOT_TGuiBldGeometryFrame
#include "TGuiBldGeometryFrame.h"
#endif
#ifndef ROOT_TGToolTip
#include "TGToolTip.h"
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

#include "Riostream.h"

void PerfectGui()
{

   // main frame
   TGMainFrame *fMainFrame2272 = new TGMainFrame(gClient->GetRoot(),10,10,kMainFrame | kVerticalFrame);
   fMainFrame2272->SetName("fMainFrame2272");
   fMainFrame2272->SetLayoutBroken(kTRUE);
   TGTextButton *BrowseButton = new TGTextButton(fMainFrame2272,"Browse...",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   BrowseButton->SetTextJustify(36);
   BrowseButton->SetMargins(0,0,0,0);
   BrowseButton->SetWrapLength(-1);
   BrowseButton->Resize(91,24);
   fMainFrame2272->AddFrame(BrowseButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   BrowseButton->MoveResize(376,8,91,24);

   TGFont *ufont;         // will reflect user font changes
   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   TGGC   *uGC;           // will reflect user GC changes
   // graphics context changes
   GCValues_t valath;
   valath.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valath.fForeground);
   gClient->GetColorByName("#e8e8e8",valath.fBackground);
   valath.fFillStyle = kFillSolid;
   valath.fFont = ufont->GetFontHandle();
   valath.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valath, kTRUE);
   TGTextEntry *FilePath = new TGTextEntry(fMainFrame2272, new TGTextBuffer(31),-1,uGC->GetGC(),ufont->GetFontStruct(),kSunkenFrame | kOwnBackground);
   FilePath->SetMaxLength(4096);
   FilePath->SetAlignment(kTextLeft);
   FilePath->SetText("");
   FilePath->Resize(360,FilePath->GetDefaultHeight());
   fMainFrame2272->AddFrame(FilePath, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   FilePath->MoveResize(8,8,360,22);
   TGTextButton *ConvertButton = new TGTextButton(fMainFrame2272,"Convert binary (DRS) to root",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   ConvertButton->SetTextJustify(36);
   ConvertButton->SetMargins(0,0,0,0);
   ConvertButton->SetWrapLength(-1);
   ConvertButton->Resize(192,24);
   fMainFrame2272->AddFrame(ConvertButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ConvertButton->MoveResize(0,40,192,24);
   TGTextButton *ViewButton = new TGTextButton(fMainFrame2272,"View Root Histogram",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   ViewButton->SetTextJustify(36);
   ViewButton->SetMargins(0,0,0,0);
   ViewButton->SetWrapLength(-1);
   ViewButton->Resize(152,24);
   fMainFrame2272->AddFrame(ViewButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   ViewButton->MoveResize(8,72,152,24);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valLabel;
   valLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valLabel.fForeground);
   gClient->GetColorByName("#e8e8e8",valLabel.fBackground);
   valLabel.fFillStyle = kFillSolid;
   valLabel.fFont = ufont->GetFontHandle();
   valLabel.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valLabel, kTRUE);
   TGLabel *RangeLabel = new TGLabel(fMainFrame2272,"Enter the Integration ranges for the lower noise range, upper noise range, lower signal range, and upper signal range.",uGC->GetGC());
   RangeLabel->SetTextJustify(36);
   RangeLabel->SetMargins(0,0,0,0);
   RangeLabel->SetWrapLength(-1);
   fMainFrame2272->AddFrame(RangeLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   RangeLabel->MoveResize(0,240,664,24);

   // embedded canvas
   TRootEmbeddedCanvas *HistCanvas = new TRootEmbeddedCanvas(0,fMainFrame2272,446,128,kSunkenFrame);
   HistCanvas->SetName("HistCanvas");
   Int_t wHistCanvas = HistCanvas->GetCanvasWindowId();
   TCanvas *c126 = new TCanvas("c126", 10, 10, wHistCanvas);
   HistCanvas->AdoptCanvas(c126);
   fMainFrame2272->AddFrame(HistCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   HistCanvas->MoveResize(10,104,446,128);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valabel;
   valabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valabel.fForeground);
   gClient->GetColorByName("#e8e8e8",valabel.fBackground);
   valabel.fFillStyle = kFillSolid;
   valabel.fFont = ufont->GetFontHandle();
   valabel.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valabel, kTRUE);
   TGLabel *LowNLabel = new TGLabel(fMainFrame2272,"Lower Noise Range",uGC->GetGC());
   LowNLabel->SetTextJustify(36);
   LowNLabel->SetMargins(0,0,0,0);
   LowNLabel->SetWrapLength(-1);
   fMainFrame2272->AddFrame(LowNLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LowNLabel->MoveResize(8,272,112,18);
   TGNumberEntry *LowNNum = new TGNumberEntry(fMainFrame2272, (Double_t) 0,13,-1,(TGNumberFormat::EStyle) 5);
   LowNNum->SetName("LowNNum");
   fMainFrame2272->AddFrame(LowNNum, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LowNNum->MoveResize(10,296,110,22);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valLabel;
   valLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valLabel.fForeground);
   gClient->GetColorByName("#e8e8e8",valLabel.fBackground);
   valLabel.fFillStyle = kFillSolid;
   valLabel.fFont = ufont->GetFontHandle();
   valLabel.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valLabel, kTRUE);
   TGLabel *HighNLabel = new TGLabel(fMainFrame2272,"Higher Noise Range",uGC->GetGC());
   HighNLabel->SetTextJustify(36);
   HighNLabel->SetMargins(0,0,0,0);
   HighNLabel->SetWrapLength(-1);
   fMainFrame2272->AddFrame(HighNLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   HighNLabel->MoveResize(144,272,112,18);
   TGNumberEntry *HighNNum = new TGNumberEntry(fMainFrame2272, (Double_t) 0,13,-1,(TGNumberFormat::EStyle) 5);
   HighNNum->SetName("HighNNum");
   fMainFrame2272->AddFrame(HighNNum, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   HighNNum->MoveResize(136,296,110,22);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valgLabel;
   valgLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valgLabel.fForeground);
   gClient->GetColorByName("#e8e8e8",valgLabel.fBackground);
   valgLabel.fFillStyle = kFillSolid;
   valgLabel.fFont = ufont->GetFontHandle();
   valgLabel.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valgLabel, kTRUE);
   TGLabel *LowSigLabel = new TGLabel(fMainFrame2272,"Lower Signal Range",uGC->GetGC());
   LowSigLabel->SetTextJustify(36);
   LowSigLabel->SetMargins(0,0,0,0);
   LowSigLabel->SetWrapLength(-1);
   fMainFrame2272->AddFrame(LowSigLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LowSigLabel->MoveResize(272,272,112,18);
   TGNumberEntry *LowSignalNum = new TGNumberEntry(fMainFrame2272, (Double_t) 0,13,-1,(TGNumberFormat::EStyle) 5);
   LowSignalNum->SetName("LowSignalNum");
   fMainFrame2272->AddFrame(LowSignalNum, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   LowSignalNum->MoveResize(272,296,110,22);
   TGNumberEntry *HighSignalNum = new TGNumberEntry(fMainFrame2272, (Double_t) 0,13,-1,(TGNumberFormat::EStyle) 5);
   HighSignalNum->SetName("HighSignalNum");
   fMainFrame2272->AddFrame(HighSignalNum, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   HighSignalNum->MoveResize(400,296,110,22);

   ufont = gClient->GetFont("-*-helvetica-medium-r-*-*-12-*-*-*-*-*-iso8859-1");

   // graphics context changes
   GCValues_t valigLabel;
   valigLabel.fMask = kGCForeground | kGCBackground | kGCFillStyle | kGCFont | kGCGraphicsExposures;
   gClient->GetColorByName("#000000",valigLabel.fForeground);
   gClient->GetColorByName("#e8e8e8",valigLabel.fBackground);
   valigLabel.fFillStyle = kFillSolid;
   valigLabel.fFont = ufont->GetFontHandle();
   valigLabel.fGraphicsExposures = kFALSE;
   uGC = gClient->GetGC(&valigLabel, kTRUE);
   TGLabel *HighSigLabel = new TGLabel(fMainFrame2272,"Higher Signal Range",uGC->GetGC());
   HighSigLabel->SetTextJustify(36);
   HighSigLabel->SetMargins(0,0,0,0);
   HighSigLabel->SetWrapLength(-1);
   fMainFrame2272->AddFrame(HighSigLabel, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   HighSigLabel->MoveResize(400,272,128,18);
   TGTextButton *GenerateButton = new TGTextButton(fMainFrame2272,"Generate and view analyzed file",-1,TGTextButton::GetDefaultGC()(),TGTextButton::GetDefaultFontStruct(),kRaisedFrame);
   GenerateButton->SetTextJustify(36);
   GenerateButton->SetMargins(0,0,0,0);
   GenerateButton->SetWrapLength(-1);
   GenerateButton->Resize(200,24);
   fMainFrame2272->AddFrame(GenerateButton, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   GenerateButton->MoveResize(8,328,200,24);

   // embedded canvas
   TRootEmbeddedCanvas *SigCanvas = new TRootEmbeddedCanvas(0,fMainFrame2272,296,296,kSunkenFrame);
   SigCanvas->SetName("SigCanvas");
   Int_t wSigCanvas = SigCanvas->GetCanvasWindowId();
   TCanvas *c127 = new TCanvas("c127", 10, 10, wSigCanvas);
   SigCanvas->AdoptCanvas(c127);
   fMainFrame2272->AddFrame(SigCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   SigCanvas->MoveResize(8,360,296,296);

   // embedded canvas
   TRootEmbeddedCanvas *PedCanvas = new TRootEmbeddedCanvas(0,fMainFrame2272,296,296,kSunkenFrame);
   PedCanvas->SetName("PedCanvas");
   Int_t wPedCanvas = PedCanvas->GetCanvasWindowId();
   TCanvas *c128 = new TCanvas("c128", 10, 10, wPedCanvas);
   PedCanvas->AdoptCanvas(c128);
   fMainFrame2272->AddFrame(PedCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   PedCanvas->MoveResize(320,360,296,296);

   // embedded canvas
   TRootEmbeddedCanvas *SigMinusPedCanvas = new TRootEmbeddedCanvas(0,fMainFrame2272,600,312,kSunkenFrame);
   SigMinusPedCanvas->SetName("SigMinusPedCanvas");
   Int_t wSigMinusPedCanvas = SigMinusPedCanvas->GetCanvasWindowId();
   TCanvas *c129 = new TCanvas("c129", 10, 10, wSigMinusPedCanvas);
   SigMinusPedCanvas->AdoptCanvas(c129);
   fMainFrame2272->AddFrame(SigMinusPedCanvas, new TGLayoutHints(kLHintsLeft | kLHintsTop,2,2,2,2));
   SigMinusPedCanvas->MoveResize(16,664,600,312);

   fMainFrame2272->SetMWMHints(kMWMDecorAll,
                        kMWMFuncAll,
                        kMWMInputModeless);
   fMainFrame2272->MapSubwindows();

   fMainFrame2272->Resize(fMainFrame2272->GetDefaultSize());
   fMainFrame2272->MapWindow();
   fMainFrame2272->Resize(767,1010);
}  
