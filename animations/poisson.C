#include "TRandom.h"
#include "TCanvas.h"
#include "TH1D.h"
#include "TROOT.h"
#include "TSystem.h"

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

void poisson(){
  //
  // Example of statistical errors in MC calculation of PI
  //
  gROOT->Reset();
  auto c1 = new TCanvas("poisson","Examples of the Poisson distribution: Mean = 1,2,3,5,10,25",850,550);
  c1->SetFillColor(18);
  c1->Divide(2,3);
  
  const Int_t MAXCOINS = 50;
  
  TH1D *fH_1 = new TH1D("mean_of_1","Mean=1",21,-0.5,20.5);    fH_1->SetLineWidth(2);
  TH1D *fH_2 = new TH1D("mean_of_2","Mean=2",21,-0.5,20.5);    fH_2->SetLineWidth(2);
  TH1D *fH_3 = new TH1D("mean_of_3","Mean=3",21,-0.5,20.5);    fH_3->SetLineWidth(2);
  TH1D *fH_5 = new TH1D("mean_of_5","Mean=5",21,-0.5,20.5);    fH_5->SetLineWidth(2);
  TH1D *fH_10 = new TH1D("mean_of_10","Mean=10",21,-0.5,20.5); fH_10->SetLineWidth(2);
  TH1D *fH_25 = new TH1D("mean_of_10","Mean=10",41,-0.5,40.5); fH_25->SetLineWidth(2);

  auto fH_1_cdf = (TH1D*)fH_1->Clone("CDF");
  auto fH_2_cdf = (TH1D*)fH_2->Clone("CDF");
  auto fH_3_cdf = (TH1D*)fH_3->Clone("CDF");
  auto fH_5_cdf = (TH1D*)fH_5->Clone("CDF");
  auto fH_10_cdf = (TH1D*)fH_10->Clone("CDF");
  auto fH_25_cdf = (TH1D*)fH_25->Clone("CDF");
    
  const Int_t N_EXPT = 500;

  gSystem->Unlink("poisson_movie.gif"); // delete old file
  for (Int_t n_expt=1; n_expt<N_EXPT; n_expt++){
    fH_1->Fill((Float_t)gRandom->Poisson(1));
    fH_2->Fill((Float_t)gRandom->Poisson(2));
    fH_3->Fill((Float_t)gRandom->Poisson(3));
    fH_5->Fill((Float_t)gRandom->Poisson(5));
    fH_10->Fill((Float_t)gRandom->Poisson(10));
    fH_25->Fill((Float_t)gRandom->Poisson(25));

    hist2cdf(fH_1,fH_1_cdf);
    hist2cdf(fH_2,fH_2_cdf);
    hist2cdf(fH_3,fH_3_cdf);
    hist2cdf(fH_5,fH_5_cdf);
    hist2cdf(fH_10,fH_10_cdf);
    hist2cdf(fH_25,fH_25_cdf);


    if (n_expt<N_EXPT-1 && n_expt>=50 && (n_expt+1)%5) continue;
    if (n_expt>200 && (n_expt+1)%10) continue;
    
    c1->cd(1); draw2(fH_1,fH_1_cdf);
    c1->cd(2); draw2(fH_2,fH_2_cdf);
    c1->cd(3); draw2(fH_3,fH_3_cdf);
    c1->cd(4); draw2(fH_5,fH_5_cdf);
    c1->cd(5); draw2(fH_10,fH_10_cdf);
    c1->cd(6); draw2(fH_25,fH_25_cdf);


    gSystem->Sleep((N_EXPT-n_expt)/10);
    c1->Update();
    c1->Print("poisson_movie.gif+20"); 
  }
  c1->Print("poisson_movie.gif+500");
}

