///////////////////////////////////////////////////////////////////////////////
// mu- --> e- channel
// plot DIO bgr vs CE efficiency for different ANN trainings as a function of the 
// operational point (cut on the ANN score variable)
///////////////////////////////////////////////////////////////////////////////
#include "Stntuple/val/stntuple_val_functions.hh"
#include "TGraph.h"

TGraph* gr_par_cele0s51b1(nullptr);
TGraph* gr_par_cele0s51b2(nullptr);

TGraph* gr_dar_cele0s51b1(nullptr);
TGraph* gr_dar_cele0s51b2(nullptr);
//-----------------------------------------------------------------------------
// check various operational points of the PAR ANN-based track selection
// use default offline ANN training
// two different efficiencies for 'b1' and 'b2' datasets, in both cases use 'b1' background 
// integral over [103.85,105.1]
//
// histogram 100*(i+1)+10+j : cut on the ANN score at 0.05*j
// 126: PAR, cut at PAR ANN score at 0.8
// 214: DAR, cut at DAR ANN score at 0.2
// Index: 0:PAR, 1:DAR
//-----------------------------------------------------------------------------
int make_mumem_performance_plot(const char* HistDir, const char* SigDsID, const char* BgrDsID, int Index, TGraph** Graph) {

  TString fn_dio = Form("%s/su2020/su2020.%s.track_comp_use_mva_ffff_1070.hist",HistDir,BgrDsID);
  TString fn_sig = Form("%s/su2020/su2020.%s.track_comp_use_mva_ffff_1070.hist",HistDir,SigDsID);

  float dio_integral[2][20], sig_integral[2][20];

  // i=0: PAR; i=1:DAR
  
  for (int i=0; i<2; i++) {
    dio_integral[i][0]= 1;
    dio_integral[i][1]= 1;

    for (int j=2; j<20; j++) {
      TString hn_dio = Form("trk_%3i/pdio",100*(i+1)+10+j);

      TH1F* h_dio = gh1(fn_dio.Data(),"TrackComp",hn_dio.Data());
      
      dio_integral[i][j] = h_dio->Integral(78,100);
      
      TString hn_sig = Form("trk_%3i/p",100*(i+1)+10+j);
      
      TH1F* h_sig = gh1(fn_sig.Data(),"TrackComp",hn_sig.Data());
      
      sig_integral[i][j] = h_sig->Integral(478,500);
    }
  }

  float x[100], y[100];
  
  for (int j=2;j<20; j++) {
    float rs = sig_integral[Index][j]/sig_integral[0][16];
    float rb = dio_integral[Index][j]/dio_integral[0][16];
    printf("j=%3i, sig, dio : %12.3e  %12.3e %12.3e %12.3e %12.3e %12.3e\n",j,
	   sig_integral[0][j],dio_integral[0][j],
	   sig_integral[Index][j],dio_integral[Index][j],
	   rs,rb
	   );

    x[j-2] = rs;
    y[j-2] = rb;
  }

  if (*Graph) delete (*Graph);
  *Graph = new TGraph(18,x,y);
  
  (*Graph)->SetTitle(Form("DIO_{ANN}/DIO_{ANN}^{offline}(%s) vs CE_{ANN}/CE_{ANN}^{offline}(%s)",BgrDsID,SigDsID));
  (*Graph)->GetXaxis()->SetRangeUser(0.5,1.1999);
  (*Graph)->GetXaxis()->SetTitle("CE_{ANN}/CE_{ANN}^{offline}");
  (*Graph)->GetYaxis()->SetTitle("DIO_{ANN}//DIO_{ANN}^{offline}");
  
  return 0;
}

//-----------------------------------------------------------------------------
// background: DIO in [103.85,105.1]
// plot name: mumep_trq_ann_signal_vs_background.eps
//-----------------------------------------------------------------------------
void optimize_mumem() {
  
  const char* HistDirDefault = "/projects/mu2e/hist/su2020";
  char        HistDir[200];

  sprintf(HistDir,"%s",gEnv->GetValue("mu2e.HistDir",HistDirDefault));
  
  int index = 1; // DAR
  make_mumem_performance_plot(HistDir, "cele0s51b1", "fele2s51b1", index, &gr_dar_cele0s51b1);
  make_mumem_performance_plot(HistDir, "cele0s51b2", "fele2s51b1", index, &gr_dar_cele0s51b2);

  index = 0;

  make_mumem_performance_plot(HistDir, "cele0s51b1", "fele2s51b1", index, &gr_par_cele0s51b1);
  make_mumem_performance_plot(HistDir, "cele0s51b2", "fele2s51b1", index, &gr_par_cele0s51b2);

  //  gPad->Clear();

  TCanvas* c = new TCanvas("c_opt_mumem","c_opt_mumem",1100,1000);

  if (gPad) {
    gPad->SetGridx(1);
    gPad->SetGridy(1);
  }
  
  gr_dar_cele0s51b1->SetMarkerStyle(20);
  gr_dar_cele0s51b1->Draw("alp");
  
  gr_dar_cele0s51b2->SetMarkerStyle(20);
  gr_dar_cele0s51b2->SetLineColor  (kRed+2);
  gr_dar_cele0s51b2->SetMarkerColor(kRed+2);
  gr_dar_cele0s51b2->Draw("lp,same");
  
  gr_par_cele0s51b1->SetMarkerStyle(24);
  gr_par_cele0s51b1->Draw("lp,same");

  gr_par_cele0s51b2->SetMarkerStyle(24);
  gr_par_cele0s51b2->SetLineColor  (kRed+2);
  gr_par_cele0s51b2->SetMarkerColor(kRed+2);
  gr_par_cele0s51b2->Draw("lp,same");
}
