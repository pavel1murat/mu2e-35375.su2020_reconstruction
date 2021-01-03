///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
//
// fig  111: trk_276/dPf - DIO-weighted dPf for tracks with P > 103.6 MeV/c,
// fig  116: comparison of trk_214/dPf and trk_122/dPf - same efficiency
//
// fig  200-299 - track ID 
//
// fig  300-399 - particle (e/mu) ID 
//
///////////////////////////////////////////////////////////////////////////////
const char* Mu2eNotesDir        = "/projects/mu2e/app/users/murat/notes";     // mu2egpvm*
const char* Mu2eHistDir         = "/projects/mu2e/data/users/murat/hist";     // mu2egpvm*

const char* NoteRepo            = "mu2e-36375.su2020_reconstruction";

char  FiguresDir    [500] = "";
char  su2020_HistDir[500] = "";

#include <stdio.h>
#include <string.h>
#include "Stntuple/scripts/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"

#include "murat/scripts/fit_asymm_gauss.C"

stn_catalog*   catalog;           // has to be global

#include "init_local.C"
//-----------------------------------------------------------------------------
// real [machine-dependent] values of Mu2eNotesDir and Mu2eHistDir 
// should be defined in .rootrc
// it is assumed that the note has been checed out into $mu2e.NotesDir/$NoteRepo
// and all needed histograms are located in $mu2e.HistDir/su2020
//-----------------------------------------------------------------------------
void init() {
  stn_book* book;

  const char* notes_dir = gEnv->GetValue("mu2e.NotesDir",Mu2eNotesDir);
  sprintf(FiguresDir,"%s/%s/figures",notes_dir,NoteRepo);

  const char* hist_dir = gEnv->GetValue("mu2e.HistDir",Mu2eHistDir);
  sprintf(su2020_HistDir,"%s/su2020",hist_dir);
  

  catalog = new stn_catalog("my");
  
  book = new stn_book("su2020",su2020_HistDir);
  init_local(book);
  catalog->AddBook(book);
  
  printf(" after init_local\n");
}

#include "plot_pid.C"

//-----------------------------------------------------------------------------
void plot(int Figure, int Print = 0) {
  hist_data_t hd[10];

  init();

  if ((Figure >= 300) && (Figure < 400)) plot_pid(Figure,Print);
//-----------------------------------------------------------------------------
// fig    1: trk_200/dPf - DIO-weighted dPf for tracks with P > 103.6 MeV/c
//-----------------------------------------------------------------------------
  if      (Figure == 1) {
   
    const char* dsid    = "su2020.su_stntuple_p1_000_ele00";
    const char* ana_job = "su2020_track_ana_par";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"su2020_TrackAna","trk_200/dt");
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "dt, ns";
    hd[0].fXMin        = -10.;
    hd[0].fXMax        = 10.;
    hd[0].fLabel       = "delta(T)";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_ele00_05_15_su2020_track_ana_par",Figure);
			      
    hd[0].fPlotLabel   = "";

    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    // hd[0].fHist->Fit("gaus","w","",-1.8,-0.3);
    // hd[1].fHist->Fit("gaus","w","",-5.0, 2.0);
    // hd[1].fHist->GetFunction("gaus")->SetLineColor(kBlue+2);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }

//-----------------------------------------------------------------------------
// fig  111: trk_276/dPf - DIO-weighted dPf for tracks with P > 103.6 MeV/c,
//           to compare to mu2e-4595
//-----------------------------------------------------------------------------
  if      (Figure == 111) {
   
    const char* dsid    = "su2020.fele2s51b1";
    const char* ana_job = "track_comp_use_mva_ffff_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_276/dpf");
    hd[0].fRebin       = 5;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -2.;
    hd[0].fXMax        =  3.;
    hd[0].fLabel       = "#Delta P";
    hd[0].fLegendXMin  = 0.15;
    hd[0].fLegendYMin  = 0.4;
    hd[0].fLegendXMax  = 0.35;
    hd[0].fLegendYMax  = 0.45;
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kBlue+2;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_comp_ffff_1070_trk_276_dpf",Figure);
			      
    hd[0].fPlotLabel   = " ";

    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    // hd[0].fHist->Fit("gaus","w","",-1.8,-0.3);
    // hd[1].fHist->Fit("gaus","w","",-5.0, 2.0);
    // hd[1].fHist->GetFunction("gaus")->SetLineColor(kBlue+2);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  112: trk_126/dPf - for _nocorr 
//-----------------------------------------------------------------------------
  if      (Figure == 112) {
   
    const char* dsid    = "su2020.fele2s51b1";
    const char* ana_job = "track_comp_ffff_1070_nocorr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_126/dpf");
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -1.;
    hd[0].fXMax        =  1.;
    hd[0].fLabel       = "#Delta P";
    hd[0].fLegendXMin  = 0.15;
    hd[0].fLegendYMin  = 0.4;
    hd[0].fLegendXMax  = 0.35;
    hd[0].fLegendYMax  = 0.45;
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kBlue+2;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_comp_ffff_1070_nocorr_trk_126_dpf",Figure);
    hd[0].fStatBoxXMin = 0.6;
    hd[0].fStatBoxYMin = 0.4;
			      
    hd[0].fPlotLabel   = " ";

    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    fit_asymm_gauss(hd[0].fHist,4.5e4,-0.033,0.13,0.11,-0.16,0.07);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  113: trk_214/dPf - for _nocorr 
//-----------------------------------------------------------------------------
  if      (Figure == 113) {
   
    const char* dsid    = "su2020.fele2s51b1";
    const char* ana_job = "track_comp_use_mva_ffff_1070_nocorr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_214/dpf");
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -1.;
    hd[0].fXMax        =  1.;
    hd[0].fLabel       = "#Delta P";
    hd[0].fLegendXMin  = 0.15;
    hd[0].fLegendYMin  = 0.4;
    hd[0].fLegendXMax  = 0.35;
    hd[0].fLegendYMax  = 0.45;
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kBlue+2;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fStatBoxXMin = 0.6;
    hd[0].fStatBoxYMin = 0.4;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_comp_ffff_1070_nocorr_trk_214_dpf",Figure);
			      
    hd[0].fPlotLabel   = " ";

    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    fit_asymm_gauss(hd[0].fHist,4.5e4,-0.033,0.13,0.11,-0.16,0.08);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  114: comparison of trk_214/dPf and trk_126/dPf - same background
//-----------------------------------------------------------------------------
  if      (Figure == 114) {
    const char* dsid    = "su2020.cele0s51b2";
    const char* ana_job = "track_comp_use_mva_ffff_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_214/dpf");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fRebin       = 2;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -3.;
    hd[0].fXMax        =  3.;
    hd[0].fLabel       = "#Delta P";
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "hist";
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    // hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_cele0s51b2_track_comp_ffff_1070_trk_214_vs_126_dpf",Figure);
			      
    hd[0].fPlotLabel   = "dataset: cele0s51b2";

    hd[1]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_126/dpf");
    hd[1].fNewName     = "DAP_MVA > 0.8";
    hd[1].fRebin       = 2;
    hd[1].fDrawOpt     = "hist";
    // hd[1].fMarkerStyle = 20;
    // hd[1].fMarkerColor = kBlue+2;
    hd[1].fLineColor   = kBlue+2;
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  115: comparison of trk_216/dPf and trk_126/dPf
//-----------------------------------------------------------------------------
  if      (Figure == 115) {
    const char* dsid    = "su2020.cele0s51b2";
    const char* ana_job = "track_comp_use_mva_ffff_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_216/dpf");
    hd[0].fYLogScale   = 1;
    hd[0].fRebin       = 2;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -3.;
    hd[0].fXMax        =  3.;
    hd[0].fLabel       = "#Delta P";
    //    hd[0].fMarkerColor = kRed+2;
    hd[0].fLineColor   = kRed+2;
    //    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_cele0s51b2_track_comp_ffff_1070_trk_216_vs_126_dpf",Figure);
			      
    hd[0].fPlotLabel   = " ";
    hd[0].fDrawOpt     = "hist";

    hd[1]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_126/dpf");
    hd[1].fRebin       = 2;
    //    hd[1].fMarkerStyle = 20;
    //    hd[1].fMarkerColor = kBlue+2;
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  116: comparison of trk_214/dPf and trk_122/dPf - same efficiency
//-----------------------------------------------------------------------------
  if      (Figure == 116) {
    const char* dsid    = "su2020.cele0s51b2";
    const char* ana_job = "track_comp_use_mva_ffff_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_214/dpf");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fRebin       = 2;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = -3.;
    hd[0].fXMax        =  3.;
    hd[0].fLabel       = "#Delta P";
    //    hd[0].fMarkerColor = kRed+2;
    hd[0].fLineColor   = kRed+2;
    //    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_cele0s51b2_track_comp_ffff_1070_trk_214_vs_122_dpf",Figure);
			      
    hd[0].fPlotLabel   = "dataset: cele0s51b2";
    hd[0].fDrawOpt     = "hist";

    hd[1]              = hist_data_t(catalog,"su2020",dsid,ana_job,"TrackComp","trk_122/dpf");
    hd[1].fNewName     = "PAR_MVA > 0.4";
    hd[1].fRebin       = 2;
    //    hd[1].fMarkerStyle = 20;
    //    hd[1].fMarkerColor = kBlue+2;
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
  
}
