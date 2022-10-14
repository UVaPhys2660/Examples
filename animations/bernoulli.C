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
}

void bernoulli(Float_t prob=0.5){
  //
  // Example of statistical errors in MC calculation of PI
  //
  //  gROOT->Reset();
  TCanvas *c1 = new TCanvas
    ("c1","Example of the Bernoulli distribution: Flip of a Fair Coin",
     600,500);
  c1->SetFillColor(18);
  c1->Divide(2,1);
  
  TH1D *fH_1coin = new TH1D("Sample Distro.","1 Coin Tails/Heads",2,-0.5,1.5);
  fH_1coin->SetMinimum(0);
  fH_1coin->SetLineWidth(2);
  fH_1coin->SetNdivisions(2);
  //const char *results[2] = {"tails","heads"};
  //fH_1coin->LabelsOption("v");
  
  TH1D *fH_1coin_cdf = (TH1D*)fH_1coin->Clone("CDF (apprx)");
  fH_1coin_cdf->SetTitle("Cumulative Dist.");
  fH_1coin_cdf->SetLineColor(kRed);
  fH_1coin_cdf->SetLineWidth(2);

  const Int_t N_EXPT = 500;

  gSystem->Unlink("bernoulli_movie.gif"); // delete old file
  for (Int_t n_expt=0; n_expt<N_EXPT; n_expt++){
    Float_t result = (Float_t)gRandom->Binomial(1, prob);
    //fH_1coin->Fill(results[(int)result],result);
    fH_1coin->Fill(result);
    hist2cdf(fH_1coin,fH_1coin_cdf);
    if ((n_expt==N_EXPT-1)  || (n_expt<25) || !(n_expt%10))
    {
      c1->cd(1);
      fH_1coin->Draw();
      c1->cd(2);
      fH_1coin_cdf->Draw();
      gSystem->Sleep(N_EXPT-n_expt);
      c1->Update();
      c1->Print("bernoulli_movie.gif+20");
    }
  }
  c1->Print("bernoulli_movie.gif++500");
}

