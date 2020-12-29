//
#include "Stntuple/val/stntuple_val_functions.hh"
#include "TGraph.h"

TGraph* gr_par_cele0s51b1(nullptr);
TGraph* gr_par_cele0s51b2(nullptr);

TGraph* gr_cele0s51b1(nullptr);
TGraph* gr_cele0s51b2(nullptr);

//-----------------------------------------------------------------------------
// check various operational points of the PAR ANN-based track selection
//-----------------------------------------------------------------------------
int par_performance(const char* SigDsID, TGraph** Graph) {

  TString fn_dio = "/projects/mu2e/hist/su2020/su2020.fele2s51b1.track_comp_use_mva_ffff_1070.hist";
  TString fn_sig = Form("/projects/mu2e/hist/su2020/su2020.%s.track_comp_use_mva_ffff_1070.hist",SigDsID);

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
    float rs = sig_integral[0][j]/sig_integral[0][16];
    float rb = dio_integral[0][j]/dio_integral[0][16];
    printf("j=%3i, sig, dio : %12.3e  %12.3e %12.3e %12.3e %12.3e %12.3e\n",j,
	   sig_integral[0][j],dio_integral[0][j],
	   sig_integral[1][j],dio_integral[1][j],
	   rs,rb
	   );

    x[j-2] = rs;
    y[j-2] = rb;
  }

  if (*Graph) delete (*Graph);
  *Graph = new TGraph(18,x,y);
  
  (*Graph)->SetTitle(Form("DIO bgr vs signal efficiency for %s",SigDsID));
  (*Graph)->GetXaxis()->SetRangeUser(0.5,1.1999);
  (*Graph)->GetXaxis()->SetTitle("Eff(ANN)/Eff(offline ANN)");
  (*Graph)->GetYaxis()->SetTitle("DIO(ANN)/DIO(offline ANN)");
  (*Graph)->SetMarkerStyle(20);
  
  return 0;
}

//-----------------------------------------------------------------------------
int optimize_performance_point(const char* SigDsID, TGraph** Graph) {

  TString fn_dio("/projects/mu2e/hist/su2020/su2020.fele2s51b1.track_comp_use_mva_ffff_1070.hist");
  TString fn_sig = Form("/projects/mu2e/hist/su2020/su2020.%s.track_comp_use_mva_ffff_1070.hist",SigDsID);

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
    float rs = sig_integral[1][j]/sig_integral[0][16];
    float rb = dio_integral[1][j]/dio_integral[0][16];
    printf("j=%3i, sig, dio : %12.3e  %12.3e %12.3e %12.3e %12.3e %12.3e\n",j,
	   sig_integral[0][j],dio_integral[0][j],
	   sig_integral[1][j],dio_integral[1][j],
	   rs,rb
	   );

    x[j-2] = rs;
    y[j-2] = rb;
  }

  if (*Graph) delete (*Graph);
  *Graph = new TGraph(18,x,y);
  
  (*Graph)->SetTitle(Form("DIO bgr vs signal efficiency for %s",SigDsID));
  (*Graph)->GetXaxis()->SetRangeUser(0.5,1.1999);
  (*Graph)->GetXaxis()->SetTitle("Eff(ANN)/Eff(offline ANN)");
  (*Graph)->GetYaxis()->SetTitle("DIO(ANN)/DIO(offline ANN)");
  (*Graph)->SetMarkerStyle(20);
  
  return 0;
}

//-----------------------------------------------------------------------------
void optimize() {
  
  optimize_performance_point("cele0s51b1", &gr_cele0s51b1);
  optimize_performance_point("cele0s51b2", &gr_cele0s51b2);
  par_performance           ("cele0s51b1", &gr_par_cele0s51b1);
  par_performance           ("cele0s51b2", &gr_par_cele0s51b2);
  
  //  gPad->Clear();

  if (gPad) {
    gPad->SetGridx(1);
    gPad->SetGridy(1);
  }
  
  gr_cele0s51b1->Draw("alp");
  
  gr_cele0s51b2->SetLineColor  (kRed+2);
  gr_cele0s51b2->SetMarkerColor(kRed+2);
  
  gr_cele0s51b2->Draw("lp,same");
  
  gr_par_cele0s51b1->Draw("lp,same");

  gr_par_cele0s51b2->SetLineColor  (kRed+2);
  gr_par_cele0s51b2->SetMarkerColor(kRed+2);
  
  gr_par_cele0s51b2->Draw("lp,same");
}
