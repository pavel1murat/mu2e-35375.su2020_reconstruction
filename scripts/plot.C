///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
//
// fig  111: trk_276/dPf - DIO-weighted dPf for tracks with P > 103.6 MeV/c,
// fig  116: comparison of trk_214/dPf and trk_122/dPf - same efficiency
// fig  121: conversions vs dio 
// fig  122: dio two batch
// fig  127: dio two batch, muon stopping rate match cd3
// fig  123: dio one batch
// fig  128: dio one batch, muon stopping rate match cd3
// fig  124: dio 1batch and 2batch,scaled to gen event number
//
//
// fig  130-140 : track cluster timing offsets
// fig  160-170:  DIO plots and mupl2 plots
// fig  200-299 - track ID 
//
// fig  300-399 - particle (e/mu) ID 
//
///////////////////////////////////////////////////////////////////////////////
const char* Mu2eNotesDir        = "/mu2e/data/projects/su2020/notes";     // mu2egpvm*
const char* Mu2eHistDir         = "/mu2e/data/projects/su2020/hist";      // mu2egpvm*

const char* NoteRepo            = "mu2e-36375.su2020_reconstruction";

char  FiguresDir    [500] = "";
char  su2020_HistDir[500] = "";

#include <stdio.h>
#include <string.h>
#include "Stntuple/scripts/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"

#include "su2020/ana/scripts/fit_asymm_gauss.C"
#include "su2020/ana/scripts/fit_cb2_asymm.C"

stn_catalog*   catalog;           // has to be global

#include "init_local_datasets.C"

#include "plot_tid.C"                     // track quality ID
#include "plot_pid.C"                     // particle (e/mu) separation
#include "plot_tcl_dt_offsets.C"          // dt offsets
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
  init_local_datasets(book);
  catalog->AddBook(book);
  
  printf(" after init_local\n");
}

//-----------------------------------------------------------------------------
void plot(int Figure, int Print = 0) {
  hist_data_t hd[10];

  init();

  if ((Figure >= 130) && (Figure < 140)) plot_tcl_dt_offsets(Figure,Print);
  if ((Figure >= 200) && (Figure < 300)) plot_tid           (Figure,Print);
  if ((Figure >= 300) && (Figure < 400)) plot_pid           (Figure,Print);
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

//-----------------------------------------------------------------------------
// fig  121: conversions vs dio 
//-----------------------------------------------------------------------------
  if      (Figure == 121) {
    const char* dsid    = "su2020.cele0s61b2";
    const char* dsid2   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_10_1070","su2020_TrackAna","trk_2010/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1/1.7*1.e-18;
    hd[0].fRebin       = 2;
    hd[0].fXAxisTitle  = "#Delta P, MeV/c";
    hd[0].fXMin        = 102.;
    hd[0].fXMax        = 106.;
    hd[0].fLabel       = "#Delta P";
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_cele0s51b2_track_comp_ffff_1070_trk_214_vs_126_dpf",Figure);
			      
    hd[0].fPlotLabel   = "dataset: cele0s61b2(red) and fele2s51b1(blue)";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2013/p");
    hd[1].fNewName     = "DAR_MVA > 0.8";
    hd[1].fRebin       = 2;
    hd[1].fDrawOpt     = "hist";
    // hd[1].fScale       = 1;        // 2:normalize to the same area as hd[0]
    hd[0].fDrawOpt     = "pe";
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
// fig  122:  dio two batch 
//-----------------------------------------------------------------------------
  if      (Figure == 122) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2013/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 2.232*1.e12/10;//1.59e-3 is the PT to ST muon stopping rate
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 103.875;
    hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "dio_2batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_ffff_1070_trk_2013_p",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1;Scaled to 3.6e20 POT";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  127:  dio two batch, muon stopping rate match cd3 
//-----------------------------------------------------------------------------
  if      (Figure == 127) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2013/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 2.640*1.e12/10;//1.88e-3 is the PT to ST muon stopping rate
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 103.875;
    hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "dio_2batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_ffff_1070_trk_2013_p",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1;To compare with cd3";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  123:  dio one batch 
//-----------------------------------------------------------------------------
  if      (Figure == 123) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2012/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 2.232*1.e12/10;//1.59e-3 is the PT to ST muon stopping rate
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 103.875;
    hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "dio_1batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_ffff_1070_trk_2013_p",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1;Scaled to 3.6e20 POT";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  128:  dio one batch, muon stopping rate match cd3
//-----------------------------------------------------------------------------
  if      (Figure == 128) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2012/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 2.640*1.e12/10;//1.59e-3 is the PT to ST muon stopping rate
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 103.875;
    hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "dio_1batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_ffff_1070_trk_2013_p",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1; To compare with cd3";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  124:  dio one batch vs two batch; scaled to gen number 
//-----------------------------------------------------------------------------
  if      (Figure == 124) {
    const char* dsid    = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_12_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2012/p");
    hd[0].fNewName     = "DIO_1batch";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 103.875;
    hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "dio_1batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_ffff_1070_trk_2013_p",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1;1e7 flat e-";
    
    hd[1]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_12_1070","su2020_TrackAna","trk_2013/p");
    hd[1].fNewName     = "DIO_2batch;re-weighted";
    hd[1].fRebin       = 1;
    hd[1].fDrawOpt     = "hist";
    hd[1].fScale       = 1;        // 2:normalize to the same area as hd[0]
    hd[1].fLabel       = "dio_2batch";
    hd[1].fDrawOpt     = "pe";
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
// fig  161:  cele with fit_cb2_asymm
//-----------------------------------------------------------------------------
  if      (Figure == 161) {
    const char* dsid    = "su2020.cele0s61b2";
    const char* ana_job = "su2020_track_ana_02_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_02_1070","su2020_TrackAna","trk_2011/p");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 104;
    hd[0].fXMax        = 106;
    hd[0].fYMin        = 1;
    hd[0].fYMax        =1000000;
    hd[0].fLabel       = "CE_2batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_cele0s61b2_track_ana_ffff_1070_trk_2011_p",Figure);
    hd[0].fPlotLabel   = "dataset:cele0s61b2;";
   hd[0].fStatBoxXMin = 0.6; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.99; hd[1].fStatBoxYMax=0.99;
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    cb2_asymm x("x");

    x.fit(hd[0].fHist,104.5,103,106.1,-1);

    // hd[0].fHist->SetStats(0);
    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }

//-----------------------------------------------------------------------------
// fig  162:  mupl3(52.8MeV e+) with fit_cb2_asymm
//-----------------------------------------------------------------------------
  if      (Figure == 162) {
    const char* dsid    = "su2020.mupl3s51b0";
    const char* ana_job = "su2020_track_ana_00_ffff";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_00_ffff","su2020_TrackAna","trk_3010/p_2");
    hd[0].fNewName     = "DAR_MVA > 0.2";
    hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "P, MeV/c";
    hd[0].fYAxisTitle  = "N Events per 50keV/c";
    hd[0].fXMin        = 52;
    hd[0].fXMax        = 54;
    hd[0].fYMin        = 1;
    hd[0].fYMax        =1000000;
    hd[0].fLabel       = "52.8MeV e+";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fDrawOpt     = "pe";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_mupl3s51b0_track_ana_10_ffff_trk_2011_p",Figure);
    hd[0].fPlotLabel   = "dataset:mupl3s51b0;";
   hd[0].fStatBoxXMin = 0.6; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.99; hd[1].fStatBoxYMax=0.99;
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    cb2_asymm x("x");

    x.fit(hd[0].fHist,52.3,51,54,-1);

    // hd[0].fHist->SetStats(0);
    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }

//-----------------------------------------------------------------------------
// fig  167:  dio two batch vs one batch instantaneous rate; All sim events
//-----------------------------------------------------------------------------
  if      (Figure == 167) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_11_1070","su2020_TrackAna","evt_0/inst_lumi_0");
    hd[0].fNewName     = "1-batch DIO";
    // hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1;//
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "Instantaneous Intensity;POT/pulse";
    hd[0].fYAxisTitle  = "";
    // hd[0].fXMin        = 103.875;
    // hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "1batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.4;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_11_1070_evt_0_inst_lumi",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1";

    hd[1]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_11_1070","su2020_TrackAna","evt_0/inst_lumi_2");
    hd[1].fNewName     = "2-batch;re-weighted";
    // hd[1].fYLogScale   = 1;
    hd[1].fScale       = 1;//
    hd[1].fRebin       = 1;
    hd[1].fXAxisTitle  = "Instantaneous Intensity;POT/pulse";
    hd[1].fYAxisTitle  = "";
    // hd[0].fXMin        = 103.875;
    // hd[0].fXMax        = 105.075;
    hd[1].fLabel       = "2batch";
    hd[1].fLabelXMin   = 0.15;
    hd[0].fDrawOpt     = "pe";
    // hd[1].fDrawOpt     = "hist";
    // hd[1].fScale       = 1;        // 2:normalize to the same area as hd[0]
    // hd[1].fMarkerStyle = 20;
    // hd[1].fMarkerColor = kBlue+2;
    hd[1].fLineColor   = kBlue+2;
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;

    hd[1].fCanvasName  = Form("Figure_%04i",Figure);
    hd[1].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_11_1070_evt_0_inst_lumi",Figure);
    hd[1].fPlotLabel   = "dataset:fele2s51b1";
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }

//-----------------------------------------------------------------------------
// fig  166:  dio two batch vs one batch instantaneous rate; DIO bkg events
//-----------------------------------------------------------------------------
  if      (Figure == 166) {
    const char* dsid   = "su2020.fele2s51b1";
    const char* ana_job = "su2020_track_ana_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_11_1070","su2020_TrackAna","trk_2012/inst_lumi_3");
    hd[0].fNewName     = "1-batch DIO";
    // hd[0].fYLogScale   = 1;
    hd[0].fScale       = 1;//
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "Instantaneous Intensity;POT/pulse";
    hd[0].fYAxisTitle  = "";
    // hd[0].fXMin        = 103.875;
    // hd[0].fXMax        = 105.075;
    hd[0].fLabel       = "1batch";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kRed+2;
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.4;
    hd[0].fMarkerColor = kRed+2;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_11_1070_evt_0_inst_lumi",Figure);
    hd[0].fPlotLabel   = "dataset:fele2s51b1";

    hd[1]              = hist_data_t(catalog,"su2020",dsid,"su2020_track_ana_11_1070","su2020_TrackAna","trk_2012/inst_lumi_5");
    hd[1].fNewName     = "2-batch;re-weighted";
    // hd[1].fYLogScale   = 1;
    hd[1].fScale       = 1;//
    hd[1].fRebin       = 1;
    hd[1].fXAxisTitle  = "Instantaneous Intensity;POT/pulse";
    hd[1].fYAxisTitle  = "";
    // hd[0].fXMin        = 103.875;
    // hd[0].fXMax        = 105.075;
    hd[1].fLabel       = "2batch";
    hd[1].fLabelXMin   = 0.15;
    hd[0].fDrawOpt     = "pe";
    // hd[1].fDrawOpt     = "hist";
    // hd[1].fScale       = 1;        // 2:normalize to the same area as hd[0]
    // hd[1].fMarkerStyle = 20;
    // hd[1].fMarkerColor = kBlue+2;
    hd[1].fLineColor   = kBlue+2;
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;

    hd[1].fCanvasName  = Form("Figure_%04i",Figure);
    hd[1].fPlotName    = Form("figure_%05i_fele2s51b1_track_ana_11_1070_trk_2012_inst_lumi",Figure);
    hd[1].fPlotLabel   = "dataset:fele2s51b1";
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }

}
