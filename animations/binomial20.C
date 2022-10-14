
#include "TSystem.h"
#include "TRandom.h"
#include "TCanvas.h"
#include "TH1D.h"

void hist2cdf(TH1D* h, TH1D *cdf){
  double sum=0;
  double integral=h->Integral();
  cdf->Reset();
  for (int i=1; i<=h->GetNbinsX(); i++){
    sum+=h->GetBinContent(i);
    cdf->SetBinContent(i,sum/integral);
  }
  cdf->SetLineColor(kRed);
}

void draw2(TH1D* h1, TH1D* h2){
  h1->Draw();
  Float_t rightmax = h1->GetMaximum();
  h2->SetLineColor(kRed);
  h2->Scale(rightmax);
  h2->Draw("samel");
}


void binomial20(){
  //
  // Example of statistical errors in MC calculation of PI
  //
  TCanvas *c1 = new TCanvas
    ("binomial2","Examples of the Binomial distribution: Flip 20 Coins p=0.05,0.1,0.2,0.3,0.4,0.5",
     750,750);
  c1->SetFillColor(18);
  c1->Divide(2,3);

  TH1D *fH_10p50 = new TH1D("fH_10p50","p50",21,-0.5,20.5);
  fH_10p50->SetMinimum(0);
  fH_10p50->SetLineWidth(2);
  TH1D *fH_10p50_cdf = (TH1D*)fH_10p50->Clone("CDF");

  TH1D *fH_10p40 = new TH1D("fH_10p40","p40",21,-0.5,20.5);
  fH_10p40->SetMinimum(0);
  fH_10p40->SetLineWidth(2);
  TH1D *fH_10p40_cdf = (TH1D*)fH_10p40->Clone("CDF");

  TH1D *fH_10p30 = new TH1D("fH_10p30","p30",21,-0.5,20.5);
  fH_10p30->SetMinimum(0);
  fH_10p30->SetLineWidth(2);
  TH1D *fH_10p30_cdf = (TH1D*)fH_10p30->Clone("CDF");

  TH1D *fH_10p20 = new TH1D("fH_10p20","p20",21,-0.5,20.5);
  fH_10p20->SetMinimum(0);
  fH_10p20->SetLineWidth(2);
  TH1D *fH_10p20_cdf = (TH1D*)fH_10p20->Clone("CDF");

  TH1D *fH_10p10 = new TH1D("fH_10p10","p10",21,-0.5,20.5);
  fH_10p10->SetMinimum(0);
  fH_10p10->SetLineWidth(2);
  TH1D *fH_10p10_cdf = (TH1D*)fH_10p10->Clone("CDF");

  TH1D *fH_10p05 = new TH1D("fH_10p05","p05",21,-0.5,20.5);
  fH_10p05->SetMinimum(0);
  fH_10p05->SetLineWidth(2);
  TH1D *fH_10p05_cdf = (TH1D*)fH_10p05->Clone("CDF");

  const Int_t N_EXPT = 500;

  gSystem->Unlink("binomial20_movie.gif"); // delete old file
  for (Int_t n_expt=0; n_expt<N_EXPT; n_expt++){
    fH_10p50->Fill((Float_t)gRandom->Binomial(20, 0.50));
    fH_10p40->Fill((Float_t)gRandom->Binomial(20, 0.40));
    fH_10p30->Fill((Float_t)gRandom->Binomial(20, 0.30));
    fH_10p20->Fill((Float_t)gRandom->Binomial(20, 0.20));
    fH_10p10->Fill((Float_t)gRandom->Binomial(20, 0.10));
    fH_10p05->Fill((Float_t)gRandom->Binomial(20, 0.05));

    hist2cdf(fH_10p50,fH_10p50_cdf);
    hist2cdf(fH_10p40,fH_10p40_cdf);
    hist2cdf(fH_10p30,fH_10p30_cdf);
    hist2cdf(fH_10p20,fH_10p20_cdf);
    hist2cdf(fH_10p10,fH_10p10_cdf);
    hist2cdf(fH_10p05,fH_10p05_cdf);
    

    if (n_expt<N_EXPT-1 && n_expt>=50 && (n_expt+1)%5) continue;

    c1->cd(1); draw2(fH_10p05,fH_10p05_cdf);
    c1->cd(2); draw2(fH_10p10,fH_10p10_cdf);
    c1->cd(3); draw2(fH_10p20,fH_10p20_cdf);
    c1->cd(4); draw2(fH_10p30,fH_10p30_cdf);
    c1->cd(5); draw2(fH_10p40,fH_10p40_cdf);
    c1->cd(6); draw2(fH_10p50,fH_10p50_cdf);

    gSystem->Sleep((N_EXPT-n_expt)/4);
    c1->Update();
    c1->Print("binomial20_movie.gif+20"); 
  }
  c1->Print("binomial20_movie.gif++500");
}

