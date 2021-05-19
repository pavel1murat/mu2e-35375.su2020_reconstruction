#ifndef __plot_tid_C__
#define __plot_tid_C__

//-----------------------------------------------------------------------------
// Figures : 200-299
//
// fig  200: ID_1/D0      : cele0s51b0
// fig  201: ID_1/tdip    : cele0s51b0
// fig  202: ID_1/trq     : cele0s51b0
// ...
// fig  222: ID_1/trq     : cele0s51b2
// fig  231: trk_200/dpf  : ele00s51b0/1070 vs pos00s51b0/1070 vs ele00s51b0/170
// fig  232: tid_1/rmax_1 : cele0s61b1 vs cry31s51b0
// fig  233: tid_1/t0err_1: cele0s61b1 vs cry31s51b0
//-----------------------------------------------------------------------------
void plot_tid(int Figure, int Print = 0) {
  hist_data_t hd[10];

//-----------------------------------------------------------------------------
// fig  200: ID_1/D0 for cele0s51b0
//-----------------------------------------------------------------------------
  if      (Figure == 200) {
   
    const char* dsid   = "su2020.cele0s51b0";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_0");
    hd[0].fNewName     = "CE D0";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "track D0, mm";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_d0",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.15; hd[0].fLegendYMin = 0.35; hd[0].fLegendXMax = 0.35; hd[0].fLegendYMax=0.50;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_1");
    hd[1].fNewName     = "CE D0";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_4");
    hd[2].fNewName     = "CE D0";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  201: ID_1/tdip for cele0s51b0
//-----------------------------------------------------------------------------
  if      (Figure == 201) {
   
    const char* dsid   = "su2020.cele0s51b0";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_0");
    hd[0].fNewName     = "CE tan #lambda";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "tan #lambda";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_tid_su2020_track_ana_dar_11_1070_tid_1_tandip",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  202: ID_1/trq for cele0s51b0
//-----------------------------------------------------------------------------
  if      (Figure == 202) {
   
    const char* dsid   = "su2020.cele0s51b0";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_0");
    hd[0].fNewName     = "CE TRQ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "S_{TRQ}";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_trq",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  210: ID_1/D0 for cele0s51b1
//-----------------------------------------------------------------------------
  if      (Figure == 210) {
   
    const char* dsid   = "su2020.cele0s51b1";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_0");
    hd[0].fNewName     = "CE D0";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "track D0, mm";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_d0",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.15; hd[0].fLegendYMin = 0.35; hd[0].fLegendXMax = 0.35; hd[0].fLegendYMax=0.50;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_1");
    hd[1].fNewName     = "CE D0";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_4");
    hd[2].fNewName     = "CE D0";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  211: ID_1/tdip for cele0s51b1
//-----------------------------------------------------------------------------
  if      (Figure == 211) {
   
    const char* dsid   = "su2020.cele0s51b1";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_0");
    hd[0].fNewName     = "CE tan #lambda";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "tan #lambda";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_tid_su2020_track_ana_dar_11_1070_tid_1_tandip",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  212: ID_1/trq for cele0s51b1
//-----------------------------------------------------------------------------
  if      (Figure == 212) {
   
    const char* dsid   = "su2020.cele0s51b1";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_0");
    hd[0].fNewName     = "CE TRQ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "S_{TRQ}";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_trq",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  220: ID_1/D0 for cele0s51b2
//-----------------------------------------------------------------------------
  if      (Figure == 220) {
   
    const char* dsid   = "su2020.cele0s51b2";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_0");
    hd[0].fNewName     = "CE D0";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "track D0, mm";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_d0",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.15; hd[0].fLegendYMin = 0.35; hd[0].fLegendXMax = 0.35; hd[0].fLegendYMax=0.50;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_1");
    hd[1].fNewName     = "CE D0";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/d0_4");
    hd[2].fNewName     = "CE D0";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  221: ID_1/tdip for cele0s51b2
//-----------------------------------------------------------------------------
  if      (Figure == 221) {
   
    const char* dsid   = "su2020.cele0s51b2";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_0");
    hd[0].fNewName     = "CE tan #lambda";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "tan #lambda";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_tid_su2020_track_ana_dar_11_1070_tid_1_tandip",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/tandip_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  222: ID_1/trq for cele0s51b2
//-----------------------------------------------------------------------------
  if      (Figure == 222) {
   
    const char* dsid   = "su2020.cele0s51b2";
    const char* job    = "su2020_track_ana_dar_11_1070";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_0");
    hd[0].fNewName     = "CE TRQ";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "S_{TRQ}";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "103 < P < 105";
    hd[0].fYLogScale   = 0;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_track_ana_dar_11_1070_tid_1_trq",Figure);
			      
    hd[0].fPlotLabel   = dsid;
    hd[0].fLegendXMin  = 0.45; hd[0].fLegendYMin = 0.75; hd[0].fLegendXMax = 0.65; hd[0].fLegendYMax=0.90;

    hd[1]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_1");
    hd[1].fNewName     = "CE tan #lambda";
    hd[1].fLabel       = "N-1 cuts";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,job,"su2020_TrackAna","tid_1/trkqual_4");
    hd[2].fNewName     = "CE tan #lambda";
    hd[2].fLabel       = "N cuts";
    hd[2].fLineColor   = kBlue+2;
    hd[2].fFillColor   = kBlue+2;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  231: trk_200/dpf ID_1/trq for cele0s51b2
//-----------------------------------------------------------------------------
  if      (Figure == 231) {
    const char* dsid   = "su2020.ele00s61b0";

    hd[0]              = hist_data_t(catalog,"su2020",dsid,"su2020_mva_test_dar_1070","su2020_TrackAna","trk_200/dpf");
    hd[0].fNewName     = "105 MeV e-, ANN training: 105 MeV e-";
    hd[0].fRebin       = 1;
    hd[0].fXAxisTitle  = "#Delta P";
    // hd[0].fXMin        = -10.;
    // hd[0].fXMax        = 10.;
    hd[0].fLabel       = "105 MeV e-, ANN training: 105 MeV e-";
    hd[0].fYLogScale   = 1;
    hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    hd[0].fStatBoxXMin = 0.65; hd[0].fStatBoxYMin = 0.70; hd[0].fStatBoxXMax = 0.9; hd[0].fStatBoxYMax=0.90;

    hd[0].fCanvasName  = Form("Figure_%04i",Figure);
    hd[0].fPlotName    = Form("figure_%05i_su2020_mva_test_dar",Figure);
			      
    hd[0].fPlotLabel   = "track selection with different ANNs";
    hd[0].fLegendXMin  = 0.12; hd[0].fLegendYMin = 0.55; hd[0].fLegendXMax = 0.46; hd[0].fLegendYMax=0.70;

    const char* dsid2   = "su2020.pos00s51b0";

    hd[1]              = hist_data_t(catalog,"su2020",dsid2,"su2020_mva_test_dar_1070","su2020_TrackAna","trk_200/dpf");
    hd[1].fNewName     = "105 MeV e+, ANN training: 105 MeV e-";
    hd[1].fLabel       = "105 MeV e+, ANN training: 105 MeV e-";
    hd[1].fLineColor   = kBlue+2;
    hd[1].fLineWidth   = 2;
    hd[1].fDrawOpt     = "hist";
    hd[1].fStatBoxXMin = 0.65; hd[1].fStatBoxYMin = 0.50; hd[1].fStatBoxXMax = 0.9; hd[1].fStatBoxYMax=0.70;
    
    hd[2]              = hist_data_t(catalog,"su2020",dsid,"su2020_mva_test_dar_0170","su2020_TrackAna","trk_200/dpf");
    hd[2].fNewName     = "105 MeV e-, ANN training:  92 MeV e+";
    hd[2].fLabel       = "105 MeV e-, ANN training:  92 MeV e+";
    hd[2].fLineColor   = kBlue-1;
    hd[2].fFillColor   = kBlue-1;
    hd[2].fFillStyle   = 3001;
    hd[2].fDrawOpt     = "hist";
    hd[2].fStatBoxXMin = 0.65; hd[2].fStatBoxYMin = 0.30; hd[2].fStatBoxXMax = 0.9; hd[2].fStatBoxYMax=0.50;
    
    int nhist = 3;
    plot_hist_1d(hd,nhist,-1);

    hd[0].fCanvas->Modified();
    hd[0].fCanvas->Update();

    // TArrow* arr = new TArrow(200,100,200,20,0.015);
    // arr->Draw();

    if (Print == 1) hd[0].fCanvas->Print(hd[0].fOutputFn.Data()) ;
  }
//-----------------------------------------------------------------------------
// fig  232: tid_1/rmax_1 : cele0s61b1 vs cry31s51b0
//-----------------------------------------------------------------------------
  if      (Figure == 232) {
    plot_data_t  p(2);
    
    const char* dsid1   = "su2020.cele0s61b1";
    const char* dsid2   = "su2020.cry33s51b0";

    p.hd[0]              = hist_data_t(catalog,"su2020",dsid1,"su2020_track_ana.1011","su2020_TrackAna","tid_1/rmax_1");
    p.hd[0].fNewName     = "105 MeV e-";
    p.hd[0].fLabel       = "105 MeV e-";
    p.hd[0].fRebin       = 1;
    p.hd[0].fYLogScale   = 1;
    p.hd[0].fMarkerColor = kRed+1;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    hd[0].fDrawOpt     = "hist";
    p.hd[0].fStatBoxXMin = 0.65; p.hd[0].fStatBoxYMin = 0.70; p.hd[0].fStatBoxXMax = 0.9; p.hd[0].fStatBoxYMax=0.90;

    p.hd[1]              = hist_data_t(catalog,"su2020",dsid2,"su2020_track_ana.1010","su2020_TrackAna","tid_1/rmax_1");
    p.hd[1].fNewName     = "e-, cry33s51b0";
    p.hd[1].fLabel       = "e-, cry33s51b0";
    p.hd[1].fLineColor   = kBlue+2;
    p.hd[1].fLineWidth   = 1;
    p.hd[1].fDrawOpt     = "hist";
    p.hd[1].fScale       = 2;
    p.hd[1].fStatBoxXMin = 0.65; p.hd[1].fStatBoxYMin = 0.50; p.hd[1].fStatBoxXMax = 0.9; p.hd[1].fStatBoxYMax=0.70;
    
    p.fXMin              = 300.;
    p.fXMax              = 800.;
    p.fXAxisTitle        = "R_{max}, mm";
    p.fCanvasName        = Form("Figure_%04i",Figure);
    p.fName              = Form("figure_%05i_tid_1_rmax_1",Figure);
    p.fLabel             = "track selection with different ANNs";
    p.fLegendXMin        = 0.12; p.fLegendYMin = 0.55; p.fLegendXMax = 0.4; p.fLegendYMax=0.70;

    plot_hist_1d(&p,-1);

    TArrow* arr = new TArrow(680,500,680,100,0.015);
    arr->SetLineColor(kRed);
    arr->SetLineWidth(2);
    arr->Draw();

    if (Print == 1) p.print() ;
  }
//-----------------------------------------------------------------------------
// fig  233: tid_1/t0err_1 : cele0s61b1 vs cry31s51b0
//-----------------------------------------------------------------------------
  if      (Figure == 233) {
    plot_data_t  p(1);
    
    const char* dsid1   = "su2020.cele0s61b1";
    const char* dsid2   = "su2020.cry33s51b0";

    p.hd[0]              = hist_data_t(catalog,"su2020",dsid1,"su2020_track_ana.1011","su2020_TrackAna","tid_1/t0err_1");
    p.hd[0].fNewName     = "105 MeV e-";
    p.hd[0].fLabel       = "105 MeV e-";
    p.hd[0].fRebin       = 1;
    p.hd[0].fYLogScale   = 1;
    p.hd[0].fLineColor = kBlue+2;
    // hd[0].fMarkerStyle = 20;
    // hd[0].fMarkerSize  = 0.8;
    p.hd[0].fDrawOpt     = "hist";
    p.hd[0].fStatBoxXMin = 0.65; p.hd[0].fStatBoxYMin = 0.70; p.hd[0].fStatBoxXMax = 0.9; p.hd[0].fStatBoxYMax=0.90;

    // p.fXMin              = 300.;
    // p.fXMax              = 800.;
    p.fXAxisTitle        = "#sigma_{T0}, ns";
    p.fCanvasName        = Form("Figure_%04i",Figure);
    p.fName              = Form("figure_%05i_tid_1_t0err_1",Figure);
    p.fLabel             = "track #sigma_{T0}";
    p.fLegendXMin        = 0.30; p.fLegendYMin = 0.65; p.fLegendXMax = 0.6; p.fLegendYMax=0.70;

    plot_hist_1d(&p,-1);

    TArrow* arr = new TArrow(0.9,2500,0.9,200,0.015);
    arr->SetLineColor(kRed);
    arr->SetLineWidth(2);
    arr->Draw();

    if (Print == 1) p.print() ;
  }
}

#endif
