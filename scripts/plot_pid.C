#ifndef __plot_pid_C__
#define __plot_pid_C__

#include "plot_pid.C"

//-----------------------------------------------------------------------------
// Figure : 300-399
// fig  300: trk_101/E/P - electrons vs muons
// fig  301: trk_101/ncr - electrons vs muons
// fig  302: trk_101/seedfr - electrons vs muons
// fig  303 trk_101/tch_dt - electrons vs muons
// fig  304 trk_101/tch_dz - electrons vs muons
// fig  305 trk_101/tch_dr - electrons vs muons
// fig  306 trk_101/path   - electrons vs muons
//
// Figure 310: PID<0.5 vs PID>0.5
// ----------
// fig  310: cele0s51b1 trk_110 vs trk_111 TCH_DR 
// fig  311: cele0s51b1 trk_110 vs trk_111 E/P
// fig  312: cele0s51b1 trk_110 vs trk_111 rmax
// fig  313: cele0s51b1 trk_110 vs trk_111 TCH_DT
//
// fig  321  mumi0s61b0 vs mumi1s51b0 trk_200/tch_ep
// fig  322  mumi0s61b0 vs mumi1s51b0 trk_200/tch_dt
//
// fig  331  mumi1s51s0 vs ele01s51s0 trk_219/pidmvaout
//-----------------------------------------------------------------------------
void plot_pid(int Figure, int Print = 0) {
  hist_data_t hd[10];

//-----------------------------------------------------------------------------
// fig  300: trk_101/E/P - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 300) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_200/ep");
    hd[0].fNewName     = "muons, E/P";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "E(cluster)/P";
    hd[0].fXMin        = -10.;
    hd[0].fXMax        = 10.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_ep",Figure);
			      
    hd[0].fPlotLabel   = " ";  // to make an empty plot label 

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"su2020_TrackAna","trk_200/ep");
    hd[1].fNewName     = "electrons, E/P";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
    
    int nhist = 2;
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
// fig  301: trk_101/ncr - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 301) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/ncr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, ncr";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "N(crystals)";
    hd[0].fXMin        =  0.;
    hd[0].fXMax        = 30.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_ncr",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, ncr";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  302: trk_101/ncr - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 302) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/seed_fr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, E_{seed}/E";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "E_{seed}/E";
    hd[0].fXMin        =  0.;
    hd[0].fXMax        = 30.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.55; hd[0].fStatBoxYMin = 0.65; hd[0].fStatBoxXMax = 0.80; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_seed_fr",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, E_{seed}/E";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.55; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.80; hd[1].fStatBoxYMax=0.65;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  303 trk_101/tch_dt - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 303) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/tch_dt";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, #DeltaT";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYMax        =  20000.;
    hd[0].fXMin        = -5.;
    hd[0].fXMax        =  5.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_tch_dt",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, #DeltaT";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  304 trk_101/tch_dz - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 304) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";  // 1000*1(DAR)+100*0(105 MeV/c)+10*1(on-the fly)

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/tch_dz";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, #DeltaT";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta Z, mm";
    // hd[0].fYMax        =  25000.;
    hd[0].fXMin        = -200.;
    hd[0].fXMax        =  500.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_tch_dz",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, #DeltaZ";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  305 trk_200/tch_dr - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 305) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/tch_dr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, #DeltaR";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta R, mm";
    hd[0].fYMax        =  10000.;
    // hd[0].fXMin        = -200.;
    // hd[0].fXMax        =  500.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_tch_dr",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, #DeltaR";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.65;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  306 trk_200/path - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 306) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";

    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/path";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, path";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "path, mm";
    hd[0].fYMax        =  35000.;
    // hd[0].fXMin        = -200.;
    // hd[0].fXMax        =  500.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_path",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, path";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
    
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  307 trk_200/pidmvaout - output of the PID MVA 
//-----------------------------------------------------------------------------
  if      (Figure == 307) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "su2020_track_ana_1010";
    
    const char* module = "su2020_TrackAna";
    const char* hist   = "trk_200/pidmvaout";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,hist);
    hd[0].fNewName     = "muons, PID";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "PID ANN score, S_{PID}";
    //    hd[0].fYMax        =  25000.;
    hd[0].fXMin        = -0.2;
    hd[0].fXMax        =  1.199;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 1;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_pidmvaout",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,module,hist);
    hd[1].fNewName     = "electrons, PID";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxYMin = 0.54; hd[1].fStatBoxYMax=0.72;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  310: cele0s61b1 trk_110 vs trk_111 TCH_DR
//-----------------------------------------------------------------------------
  if      (Figure == 310) {
   
    const char* dsid   = "su2020.cele0s61b1";    const char* job    = "pid_emuana_1012";
    const char* dsid2  = "su2020.mumi0s61b0";    const char* job2   = "pid_emuana_1010";
    const char* module = "EmuAna";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,module,"trk_110/tch_dr");
    hd[0].fNewName     = "DR, PID>0.5";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "DR, mm";
    hd[0].fYMax        = 10000;
    // hd[0].fXMin        = -1.;
    // hd[0].fXMax        =  1.1;
    hd[0].fLabel       = "electrons, PID > 0.5";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_trk_110_vs_111_tch_dr",Figure);

    hd[0].fLegendXMin = 0.70; hd[0].fLegendYMin = 0.30; hd[0].fLegendXMax = 0.90; hd[0].fLegendYMax=0.40;
			      
    hd[0].fPlotLabel   = dsid;

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,module,"trk_111/tch_dr");
    hd[1].fNewName     = "DR, PID<0.5";
    hd[1].fLabel       = "muons    , PID < 0.5";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;

    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_111/tch_dr");
    hd[2].fNewName     = "DR, PID<0.5";
    hd[2].fLabel       = "electrons, PID < 0.5";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3003;
    hd[2].fDrawOpt     = "hist"; 
    hd[2].fStatBoxXMin = 0.70; hd[2].fStatBoxYMin = 0.45; hd[2].fStatBoxXMax = 0.90; hd[2].fStatBoxYMax=0.60;
    hd[2].fScale       = 2;
   
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  311: cele0s51b1 trk_110 vs trk_111 E/P
//-----------------------------------------------------------------------------
  if      (Figure == 311) {
   
    const char* dsid   = "su2020.cele0s61b1"; const char* job    = "pid_emuana_1012";
    const char* dsid2  = "su2020.mumi0s61b0"; const char* job2   = "pid_emuana_1010";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_110/ep");
    hd[0].fNewName     = "E/P, PID>0.5";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "DR, mm";
    hd[0].fYMax        = 12000;
    // hd[0].fXMin        = -1.;
    // hd[0].fXMax        =  1.1;
    hd[0].fLabel       = "electrons, PID > 0.5";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fLegendXMin = 0.70; hd[0].fLegendYMin = 0.30; hd[0].fLegendXMax = 0.90; hd[0].fLegendYMax=0.40;
			      
    hd[0].fCanvasName  = Form("Figure_%04i",Figure);

    hd[0].fPlotLabel   = dsid;
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_trk_110_vs_111_ep",Figure);

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,"EmuAna","trk_111/ep");
    hd[1].fNewName     = "E/P, PID<0.5";
    hd[1].fLabel       = "muons    , PID < 0.5";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;

    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_111/ep");
    hd[2].fNewName     = "E/P, PID<0.5";
    hd[2].fLabel       = "electrons, PID < 0.5";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3003;
    hd[2].fDrawOpt     = "hist"; 
    hd[2].fStatBoxXMin = 0.70; hd[2].fStatBoxYMin = 0.45; hd[2].fStatBoxXMax = 0.90; hd[2].fStatBoxYMax=0.60;
    hd[2].fScale       = 2;
   
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  312: cele0s51b1 trk_110 vs trk_111 rmax
//-----------------------------------------------------------------------------
  if      (Figure == 312) {
   
    const char* dsid   = "su2020.cele0s61b1"; const char* job    = "pid_emuana_1012";
    const char* dsid2  = "su2020.mumi0s61b0"; const char* job2   = "pid_emuana_1010";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_110/rmax");
    hd[0].fNewName     = "electrons, PID>0.5";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "Rmax, mm";
    hd[0].fYMax        = 10000.;
    hd[0].fXMin        = 400.;
    hd[0].fXMax        = 800;
    hd[0].fLabel       = "electrons, PID>0.5";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_trk_110_vs_111_rmax",Figure);
			      
    hd[0].fPlotLabel   = dsid;

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,"EmuAna","trk_111/rmax");
    hd[1].fNewName     = "muons, PID<0.5";
    hd[1].fLabel       = "muons, PID<0.5";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;
   
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_111/rmax");
    hd[2].fNewName     = "electrons, PID<0.5";
    hd[2].fLabel       = "electrons, PID<0.5";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3003;
    hd[2].fDrawOpt     = "hist"; 
    hd[2].fStatBoxXMin = 0.70; hd[2].fStatBoxYMin = 0.45; hd[2].fStatBoxXMax = 0.90; hd[2].fStatBoxYMax=0.60;
    hd[2].fScale       = 2;

    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  313: cele0s51b1 trk_110 vs trk_111 TCH_DT
//-----------------------------------------------------------------------------
  if      (Figure == 313) {
   
    const char* dsid   = "su2020.cele0s61b1"; const char* job    = "pid_emuana_1012";
    const char* dsid2  = "su2020.mumi0s61b0"; const char* job2   = "pid_emuana_1010";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_110/tch_dt");
    hd[0].fNewName     = "electrons, PID>0.5";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "Dt, ns";
    hd[0].fYMin        = 0.1;
    hd[0].fYMax        = 16000;
    hd[0].fXMin        = -8.;
    hd[0].fXMax        =  4;
    hd[0].fLabel       = "electrons, PID>0.5";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_trk_110_vs_111_tch_dt",Figure);
			      
    hd[0].fPlotLabel   = dsid;

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,"EmuAna","trk_111/tch_dt");
    hd[1].fNewName     = "muons, PID<0.5";
    hd[1].fLabel       = "muons, PID<0.5";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;
   
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_111/tch_dt");
    hd[2].fNewName     = "electrons, PID<0.5";
    hd[2].fLabel       = "electrons, PID<0.5";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3003;
    hd[2].fDrawOpt     = "hist"; 
    hd[2].fStatBoxXMin = 0.70; hd[2].fStatBoxYMin = 0.45; hd[2].fStatBoxXMax = 0.90; hd[2].fStatBoxYMax=0.60;
    hd[2].fScale       = 2;

    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  321: mumi0s61b0 vs mumi1s51b0 trk_200/ep (105 MeV/c vs 92 MeV/c)
//-----------------------------------------------------------------------------
  if      (Figure == 321) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.mumi1s51b0";
    const char* job    = "su2020_track_ana_10_1070";
    const char* job2   = "su2020_track_ana_10_1170";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_200/ep");
    hd[0].fNewName     = "mu-, 105 MeV/c ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "E/P";
    // hd[0].fYMin        = 0.1;
    // hd[0].fYMax        = 16000;
    // hd[0].fXMin        = -8.;
    // hd[0].fXMax        =  4;
    hd[0].fLabel       = " ";
    hd[0].fYLogScale   = 1;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    //    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_trk_200_ep",Figure);
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,"su2020_TrackAna","trk_200/ep");
    hd[1].fNewName     = "mu-, 92 MeV/c";
    hd[1].fLabel       = "";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  322: mumi0s61b0 vs mumi1s51b0 trk_200/dt
//-----------------------------------------------------------------------------
  if      (Figure == 322) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.mumi1s51b0";
    const char* job    = "su2020_track_ana_10_1070";
    const char* job2   = "su2020_track_ana_10_1170";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_200/dt");
    hd[0].fNewName     = "mu-, 105 MeV/c ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#DeltaT, ns";
    // hd[0].fYMin        = 0.1;
    // hd[0].fYMax        = 16000;
    // hd[0].fXMin        = -8.;
    // hd[0].fXMax        =  4;
    hd[0].fLabel       = "";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    //    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_trk_200_dt",Figure);
			      
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job2,"su2020_TrackAna","trk_200/dt");
    hd[1].fNewName     = "mu-, 92 MeV/c";
    hd[1].fLabel       = "";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 2;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  331  mumi1s51s0 vs ele01s51s0 trk_219/pidmvaout
//-----------------------------------------------------------------------------
  if      (Figure == 331) {
   
    const char* dsid   = "su2020.pos01s51b0";
    const char* dsid2  = "su2020.mupl1s51b0";
    const char* job    = "su2020_track_ana_1110";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_219/pidmvaout");
    hd[0].fNewName     = "e+, 92 MeV/c ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "S_{PID}";
    // hd[0].fYMin        = 0.1;
    // hd[0].fYMax        = 16000;
    hd[0].fXMin        = -0.2;
    hd[0].fXMax        =  1.199;
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fLabel       = "";   // no legend
    //    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_1110_trk_219_pidmvaout",Figure);
    hd[0].fPlotLabel   = " ";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"su2020_TrackAna","trk_219/pidmvaout");
    hd[1].fNewName     = "mu+, 92 MeV/c";
    hd[1].fLabel       = "";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 1;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  332  mumi1s51s0 vs ele01s51s0 trk_219/pidmvaout log scale
//-----------------------------------------------------------------------------
  if      (Figure == 332) {
   
    const char* dsid   = "su2020.pos01s51b0";
    const char* dsid2  = "su2020.mupl1s51b0";
    const char* job    = "su2020_track_ana_1110";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_219/pidmvaout");
    hd[0].fNewName     = "e+, 92 MeV/c ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "S_{PID}";
    hd[0].fYMin        = 0.1;
    hd[0].fYMax        = 3.e5;
    hd[0].fXMin        = -0.2;
    hd[0].fXMax        =  1.199;
    hd[0].fYLogScale   = 1;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.70; hd[0].fStatBoxYMin = 0.75; hd[0].fStatBoxXMax = 0.90; hd[0].fStatBoxYMax=0.90;

    hd[0].fLabel       = "";  // no legend
    //    hd[0].fLegendXMin = 0.35; hd[0].fLegendYMin = 0.40; hd[0].fLegendXMax = 0.55; hd[0].fLegendYMax=0.60;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_1110_trk_219_pidmvaout_log",Figure);
    hd[0].fPlotLabel   = " ";   // empty plot label

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"su2020_TrackAna","trk_219/pidmvaout");
    hd[1].fNewName     = "mu+, 92 MeV/c";
    hd[1].fLabel       = "";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.70; hd[1].fStatBoxYMin = 0.60; hd[1].fStatBoxXMax = 0.90; hd[1].fStatBoxYMax=0.75;
    hd[1].fScale       = 1;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
}

#endif
