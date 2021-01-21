///////////////////////////////////////////////////////////////////////////////
// mu- --> e- channel
// plot DIO bgr vs CE efficiency for different ANN trainings as a function of the 
// operational point (cut on the ANN score variable)
///////////////////////////////////////////////////////////////////////////////
#include "Stntuple/val/stntuple_val_functions.hh"
#include "TGraph.h"

TGraph* gr_par_cpos0s51b1(nullptr);
TGraph* gr_par_cpos0s51b2(nullptr);

TGraph* gr_dar_cpos0s51b1(nullptr);
TGraph* gr_dar_cpos0s51b2(nullptr);

char        HistDir[200];
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
// for mu- --> ep consider a measure of background the 'dpf' integral above 1 MeV
//-----------------------------------------------------------------------------
int make_mumep_performance_plot(const char* SigDsID, const char* BgrDsID, int Index, TGraph** Graph) {

  TString fn_sig = Form("%s/su2020/su2020.%s.track_comp_use_mva_ffff_1170.hist",HistDir,SigDsID);
  TString fn_bgr = Form("%s/su2020/su2020.%s.track_comp_use_mva_ffff_1170.hist",HistDir,BgrDsID);

  float bgr_integral[2][20], sig_integral[2][20];

  // i=0: PAR; i=1:DAR
  
  for (int i=0; i<2; i++) {
    bgr_integral[i][0]= 1;
    bgr_integral[i][1]= 1;

    for (int j=2; j<20; j++) {
      TString hn_bgr = Form("trk_%3i/dpf",100*(i+1)+10+j);

      TH1F* h_bgr    = gh1(fn_bgr.Data(),"TrackComp",hn_bgr.Data());
      
      bgr_integral[i][j] = h_bgr->Integral(601,1000);   // background: integrate DPF over [+1,+5]
      
      TString hn_sig = Form("trk_%3i/p",100*(i+1)+10+j);
      
      TH1F* h_sig = gh1(fn_sig.Data(),"TrackComp",hn_sig.Data());
      
      sig_integral[i][j] = h_sig->Integral(211,250);  // signal: integrate over [90.5,92.5]
    }
  }

  float x[100], y[100];
  
  for (int j=2;j<20; j++) {
    float rs = sig_integral[Index][j]/sig_integral[0][16];
    float rb = bgr_integral[Index][j]/bgr_integral[0][16];
    printf("j=%3i, sig, bgr : %12.3e  %12.3e %12.3e %12.3e %12.3e %12.3e\n",j,
	   sig_integral[0][j],bgr_integral[0][j],
	   sig_integral[Index][j],bgr_integral[Index][j],
	   rs,rb
	   );

    x[j-2] = rs;
    y[j-2] = rb;
  }

  if (*Graph) delete (*Graph);
  *Graph = new TGraph(18,x,y);
  
  (*Graph)->SetTitle(Form("BGR/Bgr0 vs Sig/Sig0 for %s",SigDsID));
  (*Graph)->GetXaxis()->SetRangeUser(0.5,1.1999);
  (*Graph)->GetXaxis()->SetTitle("Sig_{ANN}/Sig_{ANN}^{offline}");
  (*Graph)->GetYaxis()->SetTitle("BGR_{ANN}/BGR_{ANN}^{offline}");
  
  return 0;
}

//-----------------------------------------------------------------------------
// plot name: mumep_trq_ann_signal_vs_background.eps
// background: tail of the resolution plot
//-----------------------------------------------------------------------------
void optimize_mumep() {
  const char* HistDirDefault = "/projects/mu2e/hist/su2020";

  sprintf(HistDir,"%s",gEnv->GetValue("mu2e.HistDir",HistDirDefault));
  
  int index = 0;     // PAR
  make_mumep_performance_plot("cpos0s51b1", "cpos0s51b1", index, &gr_par_cpos0s51b1);

  index = 1;         // DAR
  make_mumep_performance_plot("cpos0s51b1", "cpos0s51b1", index, &gr_dar_cpos0s51b1);

  TCanvas* c = new TCanvas("c_opt_mumep","c_opt_mumep",1100,1000);
  if (gPad) {
    gPad->SetGridx(1);
    gPad->SetGridy(1);
  }
  
  gr_dar_cpos0s51b1->SetLineColor  (kRed+2);
  gr_dar_cpos0s51b1->SetMarkerColor(kRed+2);
  gr_dar_cpos0s51b1->SetMarkerStyle  (20);
  gr_dar_cpos0s51b1->SetMarkerSize   (1);
  gr_dar_cpos0s51b1->GetYaxis()->SetRangeUser(0.01,6.);
  gr_dar_cpos0s51b1->Draw("alp");
 
  gr_par_cpos0s51b1->SetMarkerStyle  (25);
  gr_par_cpos0s51b1->SetMarkerSize   (1);
  gr_par_cpos0s51b1->Draw("lp,same");

  TLegend* leg = new TLegend(0.15,0.5,0.45,0.75);
  leg->AddEntry(gr_dar_cpos0s51b1,"DAR cpos0s51b1:fpos2s51b1");
  leg->AddEntry(gr_par_cpos0s51b2,"PAR cpos0s51b2:fpos2s51b1");

  leg->Draw();
}
