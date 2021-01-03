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
//-----------------------------------------------------------------------------
void plot_pid(int Figure, int Print = 0) {
  hist_data_t hd[10];

//-----------------------------------------------------------------------------
// fig  300: trk_101/E/P - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 300) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "pid_emuana_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna","trk_101/ep");
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
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna","trk_101/ep");
    hd[1].fNewName     = "electrons, E/P";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;
    
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
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/ncr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
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
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, ncr";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.65;
    
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
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/seed_fr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
    hd[0].fNewName     = "muons, ncr";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "N(crystals)";
    hd[0].fXMin        =  0.;
    hd[0].fXMax        = 30.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.55; hd[0].fStatBoxYMin = 0.65; hd[0].fStatBoxXMax = 0.80; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_seed_fr",Figure);
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, ncr";
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
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/tch_dt";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
    hd[0].fNewName     = "muons, #DeltaT";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYMax        =  15000.;
    hd[0].fXMin        = -5.;
    hd[0].fXMax        =  5.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_tch_dt",Figure);
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, #DeltaT";
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
// fig  304 trk_101/tch_dz - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 304) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/tch_dz";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
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
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, #DeltaZ";
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
// fig  305 trk_101/tch_dr - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 305) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/tch_dr";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
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
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
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
// fig  306 trk_101/path - electrons vs muons
//-----------------------------------------------------------------------------
  if      (Figure == 306) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/path";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
    hd[0].fNewName     = "muons, path";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "path, mm";
    hd[0].fYMax        =  25000.;
    // hd[0].fXMin        = -200.;
    // hd[0].fXMax        =  500.;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_path",Figure);
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, path";
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
// fig  307 trk_101/pidmvaout - output of the PID MVA 
//-----------------------------------------------------------------------------
  if      (Figure == 307) {
   
    const char* dsid   = "su2020.mumi0s61b0";
    const char* dsid2  = "su2020.ele00s61b0";
    const char* job    = "pid_emuana_1070";
    const char* hist   = "trk_101/pidmvaout";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"EmuAna",hist);
    hd[0].fNewName     = "muons, PID";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "path, mm";
    //    hd[0].fYMax        =  25000.;
    hd[0].fXMin        = -1.;
    hd[0].fXMax        =  1.1;
    hd[0].fLabel       = "muons";
    hd[0].fYLogScale   = 1;
    hd[0].fMarkerColor = kRed+1;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.45; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.70; hd[1].fStatBoxYMax=0.65;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_pid_emuana_1070_trk_101_pidmvaout",Figure);
			      
    hd[0].fPlotLabel   = "";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,job,"EmuAna",hist);
    hd[1].fNewName     = "electrons, PID";
    hd[1].fLabel       = "electrons";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fDrawOpt     = "hist"; 
    hd[1].fStatBoxXMin = 0.45; hd[1].fStatBoxYMin = 0.40; hd[1].fStatBoxXMax = 0.70; hd[1].fStatBoxYMax=0.65;
   
    int nhist = 2;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
}

#endif
