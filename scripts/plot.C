///////////////////////////////////////////////////////////////////////////////
// HistDir and FiguresDir have to be defined before init_local_files.C
//
///////////////////////////////////////////////////////////////////////////////
const char* FiguresDir         = "/projects/mu2e/app/users/murat/notes/mu2e-36375.su2020_reconstruction/figures";
const char* su2020_HistDir     = "/projects/mu2e/hist/su2020";

#include <string.h>
#include "Stntuple/scripts/stn_catalog.hh"
#include "Stntuple/scripts/plot_hist_1D.C"
#include "Stntuple/scripts/plot_hist_2D.C"

stn_catalog*   catalog;

#include "init_local.C"

//-----------------------------------------------------------------------------
void init() {
  catalog = new stn_catalog("my");
  
  stn_book* book;

  book = new stn_book("su2020",su2020_HistDir);
  init_local(book);
  catalog->AddBook(book);

  printf(" after init_local\n");
}

//-----------------------------------------------------------------------------
void plot(int Figure, int Print = 0) {
  hist_data_t hd[10];

  init();

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
  
}
