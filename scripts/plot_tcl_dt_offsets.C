#ifndef __plot_tcl_dt_offsets_C__
#define __plot_tcl_dt_offsets_C__

//-----------------------------------------------------------------------------
// Figure : 130-140
//
// fig  131: timing offsets default fit
// fig  132: timing offsets with large cluster errors trk_101/tch_dt
// fig  133: corrected timing offsets with large cluster errors trk_101/tch_dt
// fig  139: corrected timing offsets with default cluster errors trk_101/tch_dt
//
//-----------------------------------------------------------------------------
void plot_tcl_dt_offsets(int Figure, int Print = 0) {
  hist_data_t hd[10];

//-----------------------------------------------------------------------------
// fig  131:  timing offsets - default
//-----------------------------------------------------------------------------
  if      (Figure == 131) {
    const char* dsid   = "su2020.su_stntuple_p1_000_ele00";
    const char* job    = "su2020_track_ana_par";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","trk_200/dt");
    hd[0].fNewName     = "PAR_MVA > 0.8";
    hd[0].fYLogScale   = 0;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYAxisTitle  = "N Events per 100 ps";
    hd[0].fXMin        = -10;
    hd[0].fXMax        =   9.9999;
    hd[0].fLabel       = "";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fDrawOpt     = "hist";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;
    hd[0].fStatBoxYMin = 0.6;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_ele00s51b0_su2020_track_ana_trk_200_dt",Figure);
    hd[0].fPlotLabel   = "#DeltaT = T(trk)-T(cl), 105 MeV/c e- , offline default";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fHist->Fit("gaus","","");
    hd[0].fHist->GetFunction("gaus")->Draw("same");

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  132:  timing offsets with large cluster errors trk_101/tch_dt
//-----------------------------------------------------------------------------
  if      (Figure == 132) {
    const char* dsid   = "su2020.su_stntuple_p02_dar_002_ele00";
    const char* job    = "pid_emuana";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"Emu","trk_101/tch_dt");
    hd[0].fNewName     = "PAR_MVA > 0.8";
    hd[0].fYLogScale   = 0;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYAxisTitle  = "N Events per 100 ps";
    hd[0].fXMin        = -10;
    hd[0].fXMax        =   9.9999;
    hd[0].fLabel       = "";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fDrawOpt     = "hist";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;
    hd[0].fStatBoxYMin = 0.6;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_ele00s51b0_pid_emuana_trk_101_dt",Figure);
    hd[0].fPlotLabel   = "#DeltaT = T(trk)-T(cl), 105 MeV/c e- , cluster large errors";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fHist->Fit("gaus","","",-2.6,-0.6);
    hd[0].fHist->GetFunction("gaus")->Draw("same");

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  133:  corrected timing offsets with large cluster errors trk_101/tch_dt
//-----------------------------------------------------------------------------
  if      (Figure == 133) {
    const char* dsid   = "su2020.su_stntuple_p02_dar_003_ele00";
    const char* job    = "pid_emuana";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"Emu","trk_101/tch_dt");
    hd[0].fNewName     = "PAR_MVA > 0.8";
    hd[0].fYLogScale   = 0;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYAxisTitle  = "N Events per 100 ps";
    hd[0].fXMin        = -10;
    hd[0].fXMax        =   9.9999;
    hd[0].fLabel       = "";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fDrawOpt     = "hist";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;
    hd[0].fStatBoxYMin = 0.6;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_ele00s51b0_pid_emuana_trk_101_dt",Figure);
    hd[0].fPlotLabel   = "#DeltaT = T(trk)-T(cl), 105 MeV/c e- , large errors, corrected cluster time";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fHist->Fit("gaus","","",-1.3,1.3);
    hd[0].fHist->GetFunction("gaus")->Draw("same");

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  139:  corrected timing offsets with large cluster errors trk_101/tch_dt
//-----------------------------------------------------------------------------
  if      (Figure == 139) {
    const char* dsid   = "su2020.su_stntuple_p02_dar_009_ele00";
    const char* job    = "pid_emuana";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"Emu","trk_101/tch_dt");
    hd[0].fNewName     = "PAR_MVA > 0.8";
    hd[0].fYLogScale   = 0;
    hd[0].fScale       = 1;
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta T, ns";
    hd[0].fYAxisTitle  = "N Events per 100 ps";
    hd[0].fXMin        = -10;
    hd[0].fXMax        =   9.9999;
    hd[0].fLabel       = "";
    hd[0].fLabelXMin   = 0.15;
    hd[0].fLineColor   = kBlue+2;
    hd[0].fDrawOpt     = "hist";
    hd[0].fMarkerStyle = 20;
    hd[0].fMarkerSize  = 0.8;
    hd[0].fMarkerColor = kRed+2;
    hd[0].fStatBoxYMin = 0.6;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_ele00s51b0_pid_emuana_trk_101_dt",Figure);
    hd[0].fPlotLabel   = "#DeltaT = T(trk)-T(cl), 105 MeV/c e- , large errors, corrected cluster time";
    
    int nhist = 1;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fHist->Fit("gaus","","",-1.,-0.1);
    hd[0].fHist->GetFunction("gaus")->Draw("same");

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
}

#endif
