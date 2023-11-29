#define Finale_MC_cxx
#include "AnalizeMuonTester.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

//function
Double_t gaussian(Double_t *x, Double_t *par);
Double_t gaussianCombined(Double_t *x, Double_t *par);
Double_t DoubleSidedCrystalballFunction(Double_t *x, Double_t *par);
Double_t DoubleSidedCrystalballFunction2(Double_t *x, Double_t *par);
void fitter_Gauss(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *ey1);
void fitter(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt);
void fitter2(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt);
void fitter3(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt);
void fitter4(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt);
void fitter5(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt);
void myfit(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1);
void myfit2(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1);
void myfit2_custom(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1);
void FitPol1(TGraph* graph1,TGraph* graph2);
void FitPol1_multi(TGraph* graph1,TGraph* graph2,TGraph* graph3,TGraph* graph4);
TH1F* MergeHistograms(TH1F* histogram1, TH1F* histogram2);

void Finale_MC()
{
//Opening the results file
   //TFile *f1 = new TFile("MuonTester_Res_452573.root"); //Real Data
   TFile *f1 = new TFile("MuonTester_Res_MC_ParticleGun.root"); //Simulated Data

// At this point we declare the output root file with the histograms we need
   //TFile *rfile  = new TFile( "FinaleHistograms_Scaled.root","RECREATE"); //When Scaled
   TFile *rfile  = new TFile( "MC_FinaleHistograms.root","RECREATE"); //When Unscaled

   TH1F *h_mmOnTrackResidualTrack_PCB1 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB1");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB1");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB1");
   TH1F *h_mmOnTrackResidualTrack_PCB2 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB2");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB2");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB2");
   TH1F *h_mmOnTrackResidualTrack_PCB3 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB3");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB3");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB3");
   TH1F *h_mmOnTrackResidualTrack_PCB4 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB4");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB4");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB4");
   TH1F *h_mmOnTrackResidualTrack_PCB5 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB5");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB5");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB5");
   TH1F *h_mmOnTrackResidualTrack_PCB6 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB6");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB6");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB6");
   TH1F *h_mmOnTrackResidualTrack_PCB7 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB7");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB7");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB7");
   TH1F *h_mmOnTrackResidualTrack_PCB8 = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB8");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB8");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB8");

   TH1F *h_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB1");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB1");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB1");
   TH1F *h_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB2");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB2");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB2");
   TH1F *h_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB3");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB3");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB3");
   TH1F *h_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB4");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB4");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB4");
   TH1F *h_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB5");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB5");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB5");
   TH1F *h_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB6");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB6");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB6");
   TH1F *h_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB7");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB7");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB7");
   TH1F *h_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB8");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB8");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB8");

//eta

   TH1F *h_mmOnTrackResidualTrack_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta1");
   TH1F *h_eta_mmOnTrackResidualTrack_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta1");
   TH1F *h_mmOnTrackResidualTrack_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta2");
   TH1F *h_eta_mmOnTrackResidualTrack_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta2");
   TH1F *h_mmOnTrackResidualTrack_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta3");
   TH1F *h_eta_mmOnTrackResidualTrack_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta3");
   TH1F *h_mmOnTrackResidualTrack_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta4");
   TH1F *h_eta_mmOnTrackResidualTrack_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta4");
   TH1F *h_mmOnTrackResidualTrack_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta5");
   TH1F *h_eta_mmOnTrackResidualTrack_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta5");
   TH1F *h_mmOnTrackResidualTrack_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta6");
   TH1F *h_eta_mmOnTrackResidualTrack_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta6");
   TH1F *h_mmOnTrackResidualTrack_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta7");
   TH1F *h_eta_mmOnTrackResidualTrack_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta7");
   TH1F *h_mmOnTrackResidualTrack_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta8");
   TH1F *h_eta_mmOnTrackResidualTrack_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta8");
   TH1F *h_mmOnTrackResidualTrack_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta9");
   TH1F *h_eta_mmOnTrackResidualTrack_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta9");
   TH1F *h_mmOnTrackResidualTrack_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta10");
   TH1F *h_eta_mmOnTrackResidualTrack_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta10");
   TH1F *h_mmOnTrackResidualTrack_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta11");
   TH1F *h_eta_mmOnTrackResidualTrack_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta11");
   TH1F *h_mmOnTrackResidualTrack_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta12");
   TH1F *h_eta_mmOnTrackResidualTrack_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta12");
   TH1F *h_mmOnTrackResidualTrack_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta13");
   TH1F *h_eta_mmOnTrackResidualTrack_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta13");
   TH1F *h_mmOnTrackResidualTrack_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrack_eta14");
   TH1F *h_eta_mmOnTrackResidualTrack_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrack_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_eta14");

   TH1F *h_mmOnTrackResidualTrackMS_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta1");
   TH1F *h_mmOnTrackResidualTrackMS_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta2");
   TH1F *h_mmOnTrackResidualTrackMS_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta3");
   TH1F *h_mmOnTrackResidualTrackMS_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta4");
   TH1F *h_mmOnTrackResidualTrackMS_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta5");
   TH1F *h_mmOnTrackResidualTrackMS_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta6");
   TH1F *h_mmOnTrackResidualTrackMS_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta7");
   TH1F *h_mmOnTrackResidualTrackMS_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta8");
   TH1F *h_mmOnTrackResidualTrackMS_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta9");
   TH1F *h_mmOnTrackResidualTrackMS_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta10");
   TH1F *h_mmOnTrackResidualTrackMS_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta11");
   TH1F *h_mmOnTrackResidualTrackMS_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta12");
   TH1F *h_mmOnTrackResidualTrackMS_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta13");
   TH1F *h_mmOnTrackResidualTrackMS_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_eta14");

///Phi01

   TH1F *h_mmOnTrackResidualTrackPhi01_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi01_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi01_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi01_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi01_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi01_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta14");

///Phi02

   TH1F *h_mmOnTrackResidualTrackPhi02_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi02_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi02_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi02_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi02_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi02_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta14");

///Phi03

   TH1F *h_mmOnTrackResidualTrackPhi03_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi03_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi03_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi03_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi03_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi03_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta14");
///Phi04

   TH1F *h_mmOnTrackResidualTrackPhi04_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi04_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi04_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi04_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi04_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi04_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta14");

///Phi05

   TH1F *h_mmOnTrackResidualTrackPhi05_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi05_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi05_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi05_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi05_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi05_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta14");

///Phi06

   TH1F *h_mmOnTrackResidualTrackPhi06_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi06_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi06_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi06_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi06_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi06_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta14");

///Phi07

   TH1F *h_mmOnTrackResidualTrackPhi07_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi07_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi07_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi07_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi07_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi07_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta14");

///Phi08

   TH1F *h_mmOnTrackResidualTrackPhi08_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackPhi08_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackPhi08_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackPhi08_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSPhi08_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSPhi08_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta14");

///LargeSector

   TH1F *h_mmOnTrackResidualTrackLargeSector_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackLargeSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackLargeSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackLargeSector_eta14");

   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSLargeSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta14");

///SmallSector

   TH1F *h_mmOnTrackResidualTrackSmallSector_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackSmallSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackSmallSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackSmallSector_eta14");

   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta9 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta9 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta10 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta10 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta11 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta11 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta12 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta12 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta13 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta13 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta14 = (TH1F *)f1->Get("mmOnTrackResidualTrackMSSmallSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta14 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta14");

///theta

   TH1F *h_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB1_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB1_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB1_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB2_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB2_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB2_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB3_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB3_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB3_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB4_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB4_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB4_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB5_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB5_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB5_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB6_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB6_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB6_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB7_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB7_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB7_theta");
   TH1F *h_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)f1->Get("mmOnTrackResidualTrack_PCB8_theta");
   TH1F *h_eta_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_PCB8_theta");
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_PCB8_theta");

   TH1F *h_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB1_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB1_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB1_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB2_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB2_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB2_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB3_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB3_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB3_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB4_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB4_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB4_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB5_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB5_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB5_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB6_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB6_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB6_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB7_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB7_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB7_theta");
   TH1F *h_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_PCB8_theta");
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_PCB8_theta");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_PCB8_theta");

//phi

   TH1F *h_mmOnTrackResidualTrack_phi1 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi1");
   TH1F *h_eta_mmOnTrackResidualTrack_phi1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi1");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi1");
   TH1F *h_mmOnTrackResidualTrack_phi2 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi2");
   TH1F *h_eta_mmOnTrackResidualTrack_phi2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi2");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi2");
   TH1F *h_mmOnTrackResidualTrack_phi3 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi3");
   TH1F *h_eta_mmOnTrackResidualTrack_phi3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi3");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi3");
   TH1F *h_mmOnTrackResidualTrack_phi4 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi4");
   TH1F *h_eta_mmOnTrackResidualTrack_phi4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi4");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi4");
   TH1F *h_mmOnTrackResidualTrack_phi5 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi5");
   TH1F *h_eta_mmOnTrackResidualTrack_phi5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi5");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi5");
   TH1F *h_mmOnTrackResidualTrack_phi6 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi6");
   TH1F *h_eta_mmOnTrackResidualTrack_phi6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi6");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi6");
   TH1F *h_mmOnTrackResidualTrack_phi7 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi7");
   TH1F *h_eta_mmOnTrackResidualTrack_phi7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi7");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi7");
   TH1F *h_mmOnTrackResidualTrack_phi8 = (TH1F *)f1->Get("mmOnTrackResidualTrack_phi8");
   TH1F *h_eta_mmOnTrackResidualTrack_phi8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrack_phi8");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrack_phi8");

   TH1F *h_mmOnTrackResidualTrackMS_phi1 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi1");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi1 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi1");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi1 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi1");
   TH1F *h_mmOnTrackResidualTrackMS_phi2 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi2");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi2 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi2");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi2 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi2");
   TH1F *h_mmOnTrackResidualTrackMS_phi3 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi3");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi3 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi3");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi3 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi3");
   TH1F *h_mmOnTrackResidualTrackMS_phi4 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi4");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi4 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi4");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi4 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi4");
   TH1F *h_mmOnTrackResidualTrackMS_phi5 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi5");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi5 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi5");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi5 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi5");
   TH1F *h_mmOnTrackResidualTrackMS_phi6 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi6");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi6 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi6");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi6 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi6");
   TH1F *h_mmOnTrackResidualTrackMS_phi7 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi7");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi7 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi7");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi7 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi7");
   TH1F *h_mmOnTrackResidualTrackMS_phi8 = (TH1F *)f1->Get("mmOnTrackResidualTrackMS_phi8");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi8 = (TH1F *)f1->Get("eta_mmOnTrackResidualTrackMS_phi8");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi8 = (TH1F *)f1->Get("stereo_mmOnTrackResidualTrackMS_phi8");

//position

  TH1F *h_x12_eta01 = (TH1F *)f1->Get("x12_eta01");
  TH1F *h_x12_eta02 = (TH1F *)f1->Get("x12_eta02");
  TH1F *h_x12_eta03 = (TH1F *)f1->Get("x12_eta03");
  TH1F *h_x12_eta04 = (TH1F *)f1->Get("x12_eta04");
  TH1F *h_x12_eta05 = (TH1F *)f1->Get("x12_eta05");
  TH1F *h_x12_eta06 = (TH1F *)f1->Get("x12_eta06");
  TH1F *h_x12_eta07 = (TH1F *)f1->Get("x12_eta07");
  TH1F *h_x12_eta08 = (TH1F *)f1->Get("x12_eta08");
  TH1F *h_x12_eta09 = (TH1F *)f1->Get("x12_eta09");
  TH1F *h_x12_eta10 = (TH1F *)f1->Get("x12_eta10");
  TH1F *h_x12_eta11 = (TH1F *)f1->Get("x12_eta11");
  TH1F *h_x12_eta12 = (TH1F *)f1->Get("x12_eta12");
  TH1F *h_x12_eta13 = (TH1F *)f1->Get("x12_eta13");
  TH1F *h_x12_eta14 = (TH1F *)f1->Get("x12_eta14");

  TH1F *h_x12_eta1 = MergeHistograms(h_x12_eta01,h_x12_eta02);
  TH1F *h_x12_eta2 = MergeHistograms(h_x12_eta03,h_x12_eta04);
  TH1F *h_x12_eta3 = MergeHistograms(h_x12_eta05,h_x12_eta06);
  TH1F *h_x12_eta4 = MergeHistograms(h_x12_eta07,h_x12_eta08);
  TH1F *h_x12_eta5 = MergeHistograms(h_x12_eta09,h_x12_eta10);
  TH1F *h_x12_eta6 = MergeHistograms(h_x12_eta11,h_x12_eta12);
  TH1F *h_x12_eta7 = MergeHistograms(h_x12_eta13,h_x12_eta14);

  TH1F *h_x12_qpcb01 = (TH1F *)f1->Get("x12_qpcb01");
  TH1F *h_x12_qpcb02 = (TH1F *)f1->Get("x12_qpcb02");
  TH1F *h_x12_qpcb03 = (TH1F *)f1->Get("x12_qpcb03");
  TH1F *h_x12_qpcb04 = (TH1F *)f1->Get("x12_qpcb04");
  TH1F *h_x12_qpcb05 = (TH1F *)f1->Get("x12_qpcb05");
  TH1F *h_x12_qpcb06 = (TH1F *)f1->Get("x12_qpcb06");
  TH1F *h_x12_qpcb07 = (TH1F *)f1->Get("x12_qpcb07");
  TH1F *h_x12_qpcb08 = (TH1F *)f1->Get("x12_qpcb08");

   TH1F *h_x12R = (TH1F *)f1->Get("x12R");
   TH1F *h_x121R = (TH1F *)f1->Get("x121R");
   TH1F *h_x341R = (TH1F *)f1->Get("x341R");
   TH1F *h_x122R = (TH1F *)f1->Get("x122R");
   TH1F *h_x342R = (TH1F *)f1->Get("x342R");
   TH1F *h_x34R = (TH1F *)f1->Get("x34R");

   /* TH1F *h_x12R_MS = (TH1F *)f1->Get("x12R_MS");
   TH1F *h_x13R_MS = (TH1F *)f1->Get("x13R_MS");
   TH1F *h_x14R_MS = (TH1F *)f1->Get("x14R_MS");
   TH1F *h_x23R_MS = (TH1F *)f1->Get("x23R_MS");
   TH1F *h_x24R_MS = (TH1F *)f1->Get("x24R_MS");
   TH1F *h_x34R_MS = (TH1F *)f1->Get("x34R_MS"); */

///////////////////////////////////////////////////////////// At this point we scale the histograms //////////////////////////////////////////////////////////////////////////////////

  /* h_mmOnTrackResidualTrack_PCB1->Scale(1./h_mmOnTrackResidualTrack_PCB1->Integral());
  h_eta_mmOnTrackResidualTrack_PCB1->Scale(1./h_eta_mmOnTrackResidualTrack_PCB1->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB1->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB1->Integral());
  h_mmOnTrackResidualTrack_PCB2->Scale(1./h_mmOnTrackResidualTrack_PCB2->Integral());
  h_eta_mmOnTrackResidualTrack_PCB2->Scale(1./h_eta_mmOnTrackResidualTrack_PCB2->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB2->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB2->Integral());
  h_mmOnTrackResidualTrack_PCB3->Scale(1./h_mmOnTrackResidualTrack_PCB3->Integral());
  h_eta_mmOnTrackResidualTrack_PCB3->Scale(1./h_eta_mmOnTrackResidualTrack_PCB3->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB3->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB3->Integral());
  h_mmOnTrackResidualTrack_PCB4->Scale(1./h_mmOnTrackResidualTrack_PCB4->Integral());
  h_eta_mmOnTrackResidualTrack_PCB4->Scale(1./h_eta_mmOnTrackResidualTrack_PCB4->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB4->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB4->Integral());
  h_mmOnTrackResidualTrack_PCB5->Scale(1./h_mmOnTrackResidualTrack_PCB5->Integral());
  h_eta_mmOnTrackResidualTrack_PCB5->Scale(1./h_eta_mmOnTrackResidualTrack_PCB5->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB5->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB5->Integral());
  h_mmOnTrackResidualTrack_PCB6->Scale(1./h_mmOnTrackResidualTrack_PCB6->Integral());
  h_eta_mmOnTrackResidualTrack_PCB6->Scale(1./h_eta_mmOnTrackResidualTrack_PCB6->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB6->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB6->Integral());
  h_mmOnTrackResidualTrack_PCB7->Scale(1./h_mmOnTrackResidualTrack_PCB7->Integral());
  h_eta_mmOnTrackResidualTrack_PCB7->Scale(1./h_eta_mmOnTrackResidualTrack_PCB7->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB7->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB7->Integral());
  h_mmOnTrackResidualTrack_PCB8->Scale(1./h_mmOnTrackResidualTrack_PCB8->Integral());
  h_eta_mmOnTrackResidualTrack_PCB8->Scale(1./h_eta_mmOnTrackResidualTrack_PCB8->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB8->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB8->Integral());

  h_mmOnTrackResidualTrackMS_PCB1->Scale(1./h_mmOnTrackResidualTrackMS_PCB1->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB1->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB1->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB1->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB1->Integral());
  h_mmOnTrackResidualTrackMS_PCB2->Scale(1./h_mmOnTrackResidualTrackMS_PCB2->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB2->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB2->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB2->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB2->Integral());
  h_mmOnTrackResidualTrackMS_PCB3->Scale(1./h_mmOnTrackResidualTrackMS_PCB3->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB3->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB3->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB3->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB3->Integral());
  h_mmOnTrackResidualTrackMS_PCB4->Scale(1./h_mmOnTrackResidualTrackMS_PCB4->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB4->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB4->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB4->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB4->Integral());
  h_mmOnTrackResidualTrackMS_PCB5->Scale(1./h_mmOnTrackResidualTrackMS_PCB5->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB5->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB5->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB5->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB5->Integral());
  h_mmOnTrackResidualTrackMS_PCB6->Scale(1./h_mmOnTrackResidualTrackMS_PCB6->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB6->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB6->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB6->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB6->Integral());
  h_mmOnTrackResidualTrackMS_PCB7->Scale(1./h_mmOnTrackResidualTrackMS_PCB7->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB7->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB7->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB7->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB7->Integral());
  h_mmOnTrackResidualTrackMS_PCB8->Scale(1./h_mmOnTrackResidualTrackMS_PCB8->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB8->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB8->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB8->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB8->Integral());

  h_mmOnTrackResidualTrack_eta1->Scale(1./h_mmOnTrackResidualTrack_eta1->Integral());
  h_eta_mmOnTrackResidualTrack_eta1->Scale(1./h_eta_mmOnTrackResidualTrack_eta1->Integral());
  h_stereo_mmOnTrackResidualTrack_eta1->Scale(1./h_stereo_mmOnTrackResidualTrack_eta1->Integral());
  h_mmOnTrackResidualTrack_eta2->Scale(1./h_mmOnTrackResidualTrack_eta2->Integral());
  h_eta_mmOnTrackResidualTrack_eta2->Scale(1./h_eta_mmOnTrackResidualTrack_eta2->Integral());
  h_stereo_mmOnTrackResidualTrack_eta2->Scale(1./h_stereo_mmOnTrackResidualTrack_eta2->Integral());
  h_mmOnTrackResidualTrack_eta3->Scale(1./h_mmOnTrackResidualTrack_eta3->Integral());
  h_eta_mmOnTrackResidualTrack_eta3->Scale(1./h_eta_mmOnTrackResidualTrack_eta3->Integral());
  h_stereo_mmOnTrackResidualTrack_eta3->Scale(1./h_stereo_mmOnTrackResidualTrack_eta3->Integral());
  h_mmOnTrackResidualTrack_eta4->Scale(1./h_mmOnTrackResidualTrack_eta4->Integral());
  h_eta_mmOnTrackResidualTrack_eta4->Scale(1./h_eta_mmOnTrackResidualTrack_eta4->Integral());
  h_stereo_mmOnTrackResidualTrack_eta4->Scale(1./h_stereo_mmOnTrackResidualTrack_eta4->Integral());
  h_mmOnTrackResidualTrack_eta5->Scale(1./h_mmOnTrackResidualTrack_eta5->Integral());
  h_eta_mmOnTrackResidualTrack_eta5->Scale(1./h_eta_mmOnTrackResidualTrack_eta5->Integral());
  h_stereo_mmOnTrackResidualTrack_eta5->Scale(1./h_stereo_mmOnTrackResidualTrack_eta5->Integral());
  h_mmOnTrackResidualTrack_eta6->Scale(1./h_mmOnTrackResidualTrack_eta6->Integral());
  h_eta_mmOnTrackResidualTrack_eta6->Scale(1./h_eta_mmOnTrackResidualTrack_eta6->Integral());
  h_stereo_mmOnTrackResidualTrack_eta6->Scale(1./h_stereo_mmOnTrackResidualTrack_eta6->Integral());
  h_mmOnTrackResidualTrack_eta7->Scale(1./h_mmOnTrackResidualTrack_eta7->Integral());
  h_eta_mmOnTrackResidualTrack_eta7->Scale(1./h_eta_mmOnTrackResidualTrack_eta7->Integral());
  h_stereo_mmOnTrackResidualTrack_eta7->Scale(1./h_stereo_mmOnTrackResidualTrack_eta7->Integral());
  h_mmOnTrackResidualTrack_eta8->Scale(1./h_mmOnTrackResidualTrack_eta8->Integral());
  h_eta_mmOnTrackResidualTrack_eta8->Scale(1./h_eta_mmOnTrackResidualTrack_eta8->Integral());
  h_stereo_mmOnTrackResidualTrack_eta8->Scale(1./h_stereo_mmOnTrackResidualTrack_eta8->Integral());
  h_mmOnTrackResidualTrack_eta9->Scale(1./h_mmOnTrackResidualTrack_eta9->Integral());
  h_eta_mmOnTrackResidualTrack_eta9->Scale(1./h_eta_mmOnTrackResidualTrack_eta9->Integral());
  h_stereo_mmOnTrackResidualTrack_eta9->Scale(1./h_stereo_mmOnTrackResidualTrack_eta9->Integral());
  h_mmOnTrackResidualTrack_eta10->Scale(1./h_mmOnTrackResidualTrack_eta10->Integral());
  h_eta_mmOnTrackResidualTrack_eta10->Scale(1./h_eta_mmOnTrackResidualTrack_eta10->Integral());
  h_stereo_mmOnTrackResidualTrack_eta10->Scale(1./h_stereo_mmOnTrackResidualTrack_eta10->Integral());
  h_mmOnTrackResidualTrack_eta11->Scale(1./h_mmOnTrackResidualTrack_eta11->Integral());
  h_eta_mmOnTrackResidualTrack_eta11->Scale(1./h_eta_mmOnTrackResidualTrack_eta11->Integral());
  h_stereo_mmOnTrackResidualTrack_eta11->Scale(1./h_stereo_mmOnTrackResidualTrack_eta11->Integral());
  h_mmOnTrackResidualTrack_eta12->Scale(1./h_mmOnTrackResidualTrack_eta12->Integral());
  h_eta_mmOnTrackResidualTrack_eta12->Scale(1./h_eta_mmOnTrackResidualTrack_eta12->Integral());
  h_stereo_mmOnTrackResidualTrack_eta12->Scale(1./h_stereo_mmOnTrackResidualTrack_eta12->Integral());
  h_mmOnTrackResidualTrack_eta13->Scale(1./h_mmOnTrackResidualTrack_eta13->Integral());
  h_eta_mmOnTrackResidualTrack_eta13->Scale(1./h_eta_mmOnTrackResidualTrack_eta13->Integral());
  h_stereo_mmOnTrackResidualTrack_eta13->Scale(1./h_stereo_mmOnTrackResidualTrack_eta13->Integral());
  h_mmOnTrackResidualTrack_eta14->Scale(1./h_mmOnTrackResidualTrack_eta14->Integral());
  h_eta_mmOnTrackResidualTrack_eta14->Scale(1./h_eta_mmOnTrackResidualTrack_eta14->Integral());
  h_stereo_mmOnTrackResidualTrack_eta14->Scale(1./h_stereo_mmOnTrackResidualTrack_eta14->Integral());

  h_mmOnTrackResidualTrackMS_eta1->Scale(1./h_mmOnTrackResidualTrackMS_eta1->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta1->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta1->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta1->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta1->Integral());
  h_mmOnTrackResidualTrackMS_eta2->Scale(1./h_mmOnTrackResidualTrackMS_eta2->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta2->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta2->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta2->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta2->Integral());
  h_mmOnTrackResidualTrackMS_eta3->Scale(1./h_mmOnTrackResidualTrackMS_eta3->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta3->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta3->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta3->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta3->Integral());
  h_mmOnTrackResidualTrackMS_eta4->Scale(1./h_mmOnTrackResidualTrackMS_eta4->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta4->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta4->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta4->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta4->Integral());
  h_mmOnTrackResidualTrackMS_eta5->Scale(1./h_mmOnTrackResidualTrackMS_eta5->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta5->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta5->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta5->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta5->Integral());
  h_mmOnTrackResidualTrackMS_eta6->Scale(1./h_mmOnTrackResidualTrackMS_eta6->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta6->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta6->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta6->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta6->Integral());
  h_mmOnTrackResidualTrackMS_eta7->Scale(1./h_mmOnTrackResidualTrackMS_eta7->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta7->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta7->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta7->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta7->Integral());
  h_mmOnTrackResidualTrackMS_eta8->Scale(1./h_mmOnTrackResidualTrackMS_eta8->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta8->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta8->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta8->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta8->Integral());
  h_mmOnTrackResidualTrackMS_eta9->Scale(1./h_mmOnTrackResidualTrackMS_eta9->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta9->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta9->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta9->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta9->Integral());
  h_mmOnTrackResidualTrackMS_eta10->Scale(1./h_mmOnTrackResidualTrackMS_eta10->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta10->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta10->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta10->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta10->Integral());
  h_mmOnTrackResidualTrackMS_eta11->Scale(1./h_mmOnTrackResidualTrackMS_eta11->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta11->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta11->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta11->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta11->Integral());
  h_mmOnTrackResidualTrackMS_eta12->Scale(1./h_mmOnTrackResidualTrackMS_eta12->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta12->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta12->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta12->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta12->Integral());
  h_mmOnTrackResidualTrackMS_eta13->Scale(1./h_mmOnTrackResidualTrackMS_eta13->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta13->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta13->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta13->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta13->Integral());
  h_mmOnTrackResidualTrackMS_eta14->Scale(1./h_mmOnTrackResidualTrackMS_eta14->Integral());
  h_eta_mmOnTrackResidualTrackMS_eta14->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta14->Integral());
  h_stereo_mmOnTrackResidualTrackMS_eta14->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta14->Integral());

  h_mmOnTrackResidualTrack_PCB1_theta->Scale(1./h_mmOnTrackResidualTrack_PCB1_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB1_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB1_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB1_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB1_theta->Integral());
  h_mmOnTrackResidualTrack_PCB2_theta->Scale(1./h_mmOnTrackResidualTrack_PCB2_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB2_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB2_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB2_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB2_theta->Integral());
  h_mmOnTrackResidualTrack_PCB3_theta->Scale(1./h_mmOnTrackResidualTrack_PCB3_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB3_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB3_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB3_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB3_theta->Integral());
  h_mmOnTrackResidualTrack_PCB4_theta->Scale(1./h_mmOnTrackResidualTrack_PCB4_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB4_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB4_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB4_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB4_theta->Integral());
  h_mmOnTrackResidualTrack_PCB5_theta->Scale(1./h_mmOnTrackResidualTrack_PCB5_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB5_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB5_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB5_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB5_theta->Integral());
  h_mmOnTrackResidualTrack_PCB6_theta->Scale(1./h_mmOnTrackResidualTrack_PCB6_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB6_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB6_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB6_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB6_theta->Integral());
  h_mmOnTrackResidualTrack_PCB7_theta->Scale(1./h_mmOnTrackResidualTrack_PCB7_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB7_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB7_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB7_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB7_theta->Integral());
  h_mmOnTrackResidualTrack_PCB8_theta->Scale(1./h_mmOnTrackResidualTrack_PCB8_theta->Integral());
  h_eta_mmOnTrackResidualTrack_PCB8_theta->Scale(1./h_eta_mmOnTrackResidualTrack_PCB8_theta->Integral());
  h_stereo_mmOnTrackResidualTrack_PCB8_theta->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB8_theta->Integral());

  h_mmOnTrackResidualTrackMS_PCB1_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB1_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB1_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB1_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB1_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB1_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB2_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB2_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB2_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB2_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB2_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB2_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB3_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB3_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB3_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB3_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB3_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB3_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB4_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB4_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB4_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB4_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB4_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB4_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB5_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB5_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB5_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB5_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB5_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB5_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB6_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB6_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB6_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB6_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB6_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB6_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB7_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB7_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB7_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB7_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB7_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB7_theta->Integral());
  h_mmOnTrackResidualTrackMS_PCB8_theta->Scale(1./h_mmOnTrackResidualTrackMS_PCB8_theta->Integral());
  h_eta_mmOnTrackResidualTrackMS_PCB8_theta->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB8_theta->Integral());
  h_stereo_mmOnTrackResidualTrackMS_PCB8_theta->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB8_theta->Integral());

  h_x12_eta01->Scale(1./h_x12_eta01->Integral());
  h_x12_eta02->Scale(1./h_x12_eta02->Integral());
  h_x12_eta03->Scale(1./h_x12_eta03->Integral());
  h_x12_eta04->Scale(1./h_x12_eta04->Integral());
  h_x12_eta05->Scale(1./h_x12_eta05->Integral());
  h_x12_eta06->Scale(1./h_x12_eta06->Integral());
  h_x12_eta07->Scale(1./h_x12_eta07->Integral());
  h_x12_eta08->Scale(1./h_x12_eta08->Integral());
  h_x12_eta09->Scale(1./h_x12_eta09->Integral());
  h_x12_eta10->Scale(1./h_x12_eta10->Integral());
  h_x12_eta11->Scale(1./h_x12_eta11->Integral());
  h_x12_eta12->Scale(1./h_x12_eta12->Integral());
  h_x12_eta13->Scale(1./h_x12_eta13->Integral());
  h_x12_eta14->Scale(1./h_x12_eta14->Integral());

  h_x12_qpcb01->Scale(1./h_x12_qpcb01->Integral());
  h_x12_qpcb02->Scale(1./h_x12_qpcb02->Integral());
  h_x12_qpcb03->Scale(1./h_x12_qpcb03->Integral());
  h_x12_qpcb04->Scale(1./h_x12_qpcb04->Integral());
  h_x12_qpcb05->Scale(1./h_x12_qpcb05->Integral());
  h_x12_qpcb06->Scale(1./h_x12_qpcb06->Integral());
  h_x12_qpcb07->Scale(1./h_x12_qpcb07->Integral());
  h_x12_qpcb08->Scale(1./h_x12_qpcb08->Integral());

  h_x12R->Scale(1./h_x12R->Integral());
  h_x121R->Scale(1./h_x121R->Integral());
  h_x341R->Scale(1./h_x341R->Integral());
  h_x122R->Scale(1./h_x122R->Integral());
  h_x342R->Scale(1./h_x342R->Integral());
  h_x34R->Scale(1./h_x34R->Integral()); */

///////////////////////////////////////////////////////////// At this point we fit the histograms ///////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////// sigma per PCB

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta[8];
   Double_t* psigma1_MS_eta = sigma1_MS_eta;
   Double_t esigma1_MS_eta[8];
   Double_t* pesigma1_MS_eta = esigma1_MS_eta;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_CB[8];
   Double_t* psigma1_MS_eta_CB = sigma1_MS_eta_CB;
   Double_t esigma1_MS_eta_CB[8];
   Double_t* pesigma1_MS_eta_CB = esigma1_MS_eta_CB;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_Gauss[8];
   Double_t* psigma1_MS_eta_Gauss = sigma1_MS_eta_Gauss;
   Double_t esigma1_MS_eta_Gauss[8];
   Double_t* pesigma1_MS_eta_Gauss = esigma1_MS_eta_Gauss;

   // For the Sigma2 for MS eta strips
   Double_t sigma2_MS_eta[8];
   Double_t* psigma2_MS_eta = sigma2_MS_eta;
   Double_t esigma2_MS_eta[8];
   Double_t* pesigma2_MS_eta = esigma2_MS_eta;

   // For the Combined Sigma for MS eta strips
   Double_t sigmat_MS_eta[8];
   Double_t* psigmat_MS_eta = sigmat_MS_eta;
   Double_t esigmat_MS_eta[8];
   Double_t* pesigmat_MS_eta = esigmat_MS_eta;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo[8];
   Double_t* psigma1_MS_stereo = sigma1_MS_stereo;
   Double_t esigma1_MS_stereo[8];
   Double_t* pesigma1_MS_stereo = esigma1_MS_stereo;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_CB[8];
   Double_t* psigma1_MS_stereo_CB = sigma1_MS_stereo_CB;
   Double_t esigma1_MS_stereo_CB[8];
   Double_t* pesigma1_MS_stereo_CB = esigma1_MS_stereo_CB;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_Gauss[8];
   Double_t* psigma1_MS_stereo_Gauss = sigma1_MS_stereo_Gauss;
   Double_t esigma1_MS_stereo_Gauss[8];
   Double_t* pesigma1_MS_stereo_Gauss = esigma1_MS_stereo_Gauss;

   // For the Sigma2 for MS stereo strips
   Double_t sigma2_MS_stereo[8];
   Double_t* psigma2_MS_stereo = sigma2_MS_stereo;
   Double_t esigma2_MS_stereo[8];
   Double_t* pesigma2_MS_stereo = esigma2_MS_stereo;

   // For the Combined Sigma for MS stereo strips
   Double_t sigmat_MS_stereo[8];
   Double_t* psigmat_MS_stereo = sigmat_MS_stereo;
   Double_t esigmat_MS_stereo[8];
   Double_t* pesigmat_MS_stereo = esigmat_MS_stereo;

   /* //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB1, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB2, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB3, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB4, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB5, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB6, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB7, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB8, -0.3,0.3, psigma1_MS_eta_Gauss++, pesigma1_MS_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB1, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB2, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB3, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB4, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB5, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB6, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB7, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB8, -0.3,0.3, psigma1_MS_stereo_Gauss++, pesigma1_MS_stereo_Gauss++); */
   
   //Crystal Ball Fit
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB1, -0.2,0.2, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB2, -0.1,0.1, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB3, -0.1,0.1, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-2.2,2.2
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB4, -0.2,0.2, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-2.5,2.5
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB5, -.9,.9, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-2.5,2.2
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB6, -0.1,0.1, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-3.8,4
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB7, -0.1,0.1, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-3,3
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB8, -.9,.9, psigma1_MS_eta_CB++, pesigma1_MS_eta_CB++);//-5,5

   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB1, -0.05,0.05, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-2.5,2.5
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB2, -0.05,0.05, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-1.8,1.8
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB3, -0.1,0.1, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-2.5,2.5
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB4, -0.1,0.1, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-2.5,2.1
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB5, -0.1,0.1, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-3,2.1
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB6, -0.1,0.1, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-2.3,2.3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB7, -0.05,0.05, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB8, -.9,.9, psigma1_MS_stereo_CB++, pesigma1_MS_stereo_CB++);//-5,5

   /* //Double-Gauss Fit
   fitter(h_eta_mmOnTrackResidualTrackMS_PCB1, -0.2,0.2, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-2.5,2.5 || -1.1,1.1
   fitter(h_eta_mmOnTrackResidualTrackMS_PCB2, -0.12,0.12, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-1.8,1.8
   fitter2(h_eta_mmOnTrackResidualTrackMS_PCB3, -0.22,0.22, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-2.3,2.3
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB4, -0.2,0.2, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-2.7,2.7
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB5, -0.2,0.2, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-3,3
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB6, -0.42,0.42, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-3.2,3.2
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB7, -0.5,0.5, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-6,6 || -2.1,2.1
   fitter5(h_eta_mmOnTrackResidualTrackMS_PCB8, -0.5,0.5, psigma1_MS_eta++, psigma2_MS_eta++, psigmat_MS_eta++, pesigma1_MS_eta++, pesigma2_MS_eta++, pesigmat_MS_eta++);//-6,6

   fitter(h_stereo_mmOnTrackResidualTrackMS_PCB1, -0.12,0.12, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-2.5,2.5
   fitter(h_stereo_mmOnTrackResidualTrackMS_PCB2, -0.2,0.2, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-1.9,1.9
   fitter2(h_stereo_mmOnTrackResidualTrackMS_PCB3, -0.04,0.04, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-2.3,2.3
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB4, -0.06,0.06, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-2.6,2.6
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB5, -0.2,0.2, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-3,3
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB6, -0.5,0.5, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-3.2,3.2
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB7, -0.5,0.5, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-2,2
   fitter5(h_stereo_mmOnTrackResidualTrackMS_PCB8, -0.48,0.48, psigma1_MS_stereo++, psigma2_MS_stereo++, psigmat_MS_stereo++, pesigma1_MS_stereo++, pesigma2_MS_stereo++, pesigmat_MS_stereo++);//-8,8
 */ 
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_MS[8];
   Double_t* psigma1_MS = sigma1_MS;
   Double_t esigma1_MS[8];
   Double_t* pesigma1_MS = esigma1_MS;

   // For the Sigma1 for strips
   Double_t sigma1_MS_CB[8];
   Double_t* psigma1_MS_CB = sigma1_MS_CB;
   Double_t esigma1_MS_CB[8];
   Double_t* pesigma1_MS_CB = esigma1_MS_CB;

   // For the Sigma1 for strips
   Double_t sigma1_MS_Gauss[8];
   Double_t* psigma1_MS_Gauss = sigma1_MS_Gauss;
   Double_t esigma1_MS_Gauss[8];
   Double_t* pesigma1_MS_Gauss = esigma1_MS_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_MS[8];
   Double_t* psigma2_MS = sigma2_MS;
   Double_t esigma2_MS[8];
   Double_t* pesigma2_MS = esigma2_MS;

   // For the Combined Sigma for strips
   Double_t sigmat_MS[8];
   Double_t* psigmat_MS = sigmat_MS;
   Double_t esigmat_MS[8];
   Double_t* pesigmat_MS = esigmat_MS;

   /* //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB1, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB2, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB3, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB4, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB5, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB6, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB7, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB8, -0.3,0.3, psigma1_MS_Gauss++, pesigma1_MS_Gauss++); */

   //Crystal Ball Fit
   myfit2(h_mmOnTrackResidualTrackMS_PCB1, -0.2,0.2, psigma1_MS_CB++, pesigma1_MS_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrackMS_PCB2, -0.1,0.1, psigma1_MS_CB++, pesigma1_MS_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrackMS_PCB3, -0.1,0.1, psigma1_MS_CB++, pesigma1_MS_CB++);//-2.2,2.2
   myfit2(h_mmOnTrackResidualTrackMS_PCB4, -0.1,0.1, psigma1_MS_CB++, pesigma1_MS_CB++);//-2.5,2.5
   myfit2(h_mmOnTrackResidualTrackMS_PCB5, -0.2,0.2, psigma1_MS_CB++, pesigma1_MS_CB++);//-2.7,2.7
   myfit2(h_mmOnTrackResidualTrackMS_PCB6, -0.1,0.1, psigma1_MS_CB++, pesigma1_MS_CB++);//-3,3
   myfit2(h_mmOnTrackResidualTrackMS_PCB7, -0.05,0.05, psigma1_MS_CB++, pesigma1_MS_CB++);//-3,3.5
   myfit2(h_mmOnTrackResidualTrackMS_PCB8, -3.5,3.5, psigma1_MS_CB++, pesigma1_MS_CB++);//-3.5,3.5

   /* //Double-Gauss Fit
   fitter(h_mmOnTrackResidualTrackMS_PCB1, -0.05,0.05, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-1.35,1.35
   fitter(h_mmOnTrackResidualTrackMS_PCB2, -0.05,0.05, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-1.8,1.8
   fitter2(h_mmOnTrackResidualTrackMS_PCB3, -0.1,0.1, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-2.4,2.4
   fitter3(h_mmOnTrackResidualTrackMS_PCB4, -0.1,0.1, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-2.7,2.7
   fitter3(h_mmOnTrackResidualTrackMS_PCB5, -0.1,0.1, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-2,2
   fitter3(h_mmOnTrackResidualTrackMS_PCB6, -0.2,0.2, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-3.2,3.2
   fitter3(h_mmOnTrackResidualTrackMS_PCB7, -0.3,0.3, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-3.3,3.3
   fitter5(h_mmOnTrackResidualTrackMS_PCB8, -0.5,0.5, psigma1_MS++, psigma2_MS++, psigmat_MS++, pesigma1_MS++, pesigma2_MS++, pesigmat_MS++);//-4,4 || -2.1,2.1
 */
// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_eta[8];
   Double_t* psigma1_eta = sigma1_eta;
   Double_t esigma1_eta[8];
   Double_t* pesigma1_eta = esigma1_eta;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_CB[8];
   Double_t* psigma1_eta_CB = sigma1_eta_CB;
   Double_t esigma1_eta_CB[8];
   Double_t* pesigma1_eta_CB = esigma1_eta_CB;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_Gauss[8];
   Double_t* psigma1_eta_Gauss = sigma1_eta_Gauss;
   Double_t esigma1_eta_Gauss[8];
   Double_t* pesigma1_eta_Gauss = esigma1_eta_Gauss;

   // For the Sigma2 for eta strips
   Double_t sigma2_eta[8];
   Double_t* psigma2_eta = sigma2_eta;
   Double_t esigma2_eta[8];
   Double_t* pesigma2_eta = esigma2_eta;

   // For the Combined Sigma for eta strips
   Double_t sigmat_eta[8];
   Double_t* psigmat_eta = sigmat_eta;
   Double_t esigmat_eta[8];
   Double_t* pesigmat_eta = esigmat_eta;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo[8];
   Double_t* psigma1_stereo = sigma1_stereo;
   Double_t esigma1_stereo[8];
   Double_t* pesigma1_stereo = esigma1_stereo;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_CB[8];
   Double_t* psigma1_stereo_CB = sigma1_stereo_CB;
   Double_t esigma1_stereo_CB[8];
   Double_t* pesigma1_stereo_CB = esigma1_stereo_CB;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_Gauss[8];
   Double_t* psigma1_stereo_Gauss = sigma1_stereo_Gauss;
   Double_t esigma1_stereo_Gauss[8];
   Double_t* pesigma1_stereo_Gauss = esigma1_stereo_Gauss;

   // For the Sigma2 for stereo strips
   Double_t sigma2_stereo[8];
   Double_t* psigma2_stereo = sigma2_stereo;
   Double_t esigma2_stereo[8];
   Double_t* pesigma2_stereo = esigma2_stereo;

   // For the Combined Sigma for stereo strips
   Double_t sigmat_stereo[8];
   Double_t* psigmat_stereo = sigmat_stereo;
   Double_t esigmat_stereo[8];
   Double_t* pesigmat_stereo = esigmat_stereo;

   /* //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB1, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB2, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB3, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB4, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB5, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB6, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB7, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB8, -0.3,0.3, psigma1_eta_Gauss++, pesigma1_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB1, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB2, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB3, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB4, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB5, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB6, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB7, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB8, -0.3,0.3, psigma1_stereo_Gauss++, pesigma1_stereo_Gauss++); */

   //Crystal Ball Fit
   myfit(h_eta_mmOnTrackResidualTrack_PCB1, -0.05,0.05, psigma1_eta_CB++, pesigma1_eta_CB++);//-1.4,1.4
   myfit(h_eta_mmOnTrackResidualTrack_PCB2, -0.1,0.1, psigma1_eta_CB++, pesigma1_eta_CB++);//-1,1
   myfit(h_eta_mmOnTrackResidualTrack_PCB3, -0.1,0.1, psigma1_eta_CB++, pesigma1_eta_CB++);//-1.6,1.6
   myfit(h_eta_mmOnTrackResidualTrack_PCB4, -0.15,0.15, psigma1_eta_CB++, pesigma1_eta_CB++);//-2,2
   myfit(h_eta_mmOnTrackResidualTrack_PCB5, -0.1,0.1, psigma1_eta_CB++, pesigma1_eta_CB++);//-4,4
   myfit(h_eta_mmOnTrackResidualTrack_PCB6, -0.5,0.5, psigma1_eta_CB++, pesigma1_eta_CB++);//-2.2,2.2
   myfit(h_eta_mmOnTrackResidualTrack_PCB7, -0.1,0.1, psigma1_eta_CB++, pesigma1_eta_CB++);//-2.4,2.4
   myfit(h_eta_mmOnTrackResidualTrack_PCB8, -0.1,0.1, psigma1_eta_CB++, pesigma1_eta_CB++);//-3,3

   myfit(h_stereo_mmOnTrackResidualTrack_PCB1, -0.05,0.05, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-4,4
   myfit(h_stereo_mmOnTrackResidualTrack_PCB2, -0.1,0.1, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-4,4
   myfit(h_stereo_mmOnTrackResidualTrack_PCB3, -0.1,0.1, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-1.6,1.6
   myfit(h_stereo_mmOnTrackResidualTrack_PCB4, -0.1,0.1, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-2,2
   myfit(h_stereo_mmOnTrackResidualTrack_PCB5, -0.1,0.1, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-3,3
   myfit(h_stereo_mmOnTrackResidualTrack_PCB6, -0.5,0.5, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-2.2,2.2
   myfit(h_stereo_mmOnTrackResidualTrack_PCB7, -0.05,0.05, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-2.4,2.4
   myfit(h_stereo_mmOnTrackResidualTrack_PCB8, -0.1,0.1, psigma1_stereo_CB++, pesigma1_stereo_CB++);//-3,3

   /* //Double-Gauss Fit
   fitter(h_eta_mmOnTrackResidualTrack_PCB1, -0.19,0.19, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-1.5,1.5
   fitter(h_eta_mmOnTrackResidualTrack_PCB2, -0.18,0.18, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-1.5,1.5
   fitter2(h_eta_mmOnTrackResidualTrack_PCB3, -0.18,0.18, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-1.7,1.7
   fitter3(h_eta_mmOnTrackResidualTrack_PCB4, -0.46,0.46, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-2,2
   fitter3(h_eta_mmOnTrackResidualTrack_PCB5, -0.22,0.22, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-2.6,2.4
   fitter3(h_eta_mmOnTrackResidualTrack_PCB6, -0.5,0.5, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-2.4,2.4
   fitter3(h_eta_mmOnTrackResidualTrack_PCB7, -0.22,0.22, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-2,2
   fitter5(h_eta_mmOnTrackResidualTrack_PCB8, -0.38,0.38, psigma1_eta++, psigma2_eta++, psigmat_eta++, pesigma1_eta++, pesigma2_eta++, pesigmat_eta++);//-3.9,3.9

   fitter(h_stereo_mmOnTrackResidualTrack_PCB1, -0.19,0.19, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-3,3
   fitter(h_stereo_mmOnTrackResidualTrack_PCB2, -0.22,0.22, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-2.5,2.5
   fitter2(h_stereo_mmOnTrackResidualTrack_PCB3, -0.28,0.28, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-1.8,1.7
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB4, -0.12,0.12, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-2.2,2.2
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB5, -0.05,0.05, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-2.4,2.2
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB6, -0.34,0.34, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-2.4,2.4
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB7, -0.5,0.5, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-3,3
   fitter5(h_stereo_mmOnTrackResidualTrack_PCB8, -0.5,0.5, psigma1_stereo++, psigma2_stereo++, psigmat_stereo++, pesigma1_stereo++, pesigma2_stereo++, pesigmat_stereo++);//-3.5,3.5
 */
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1[8];
   Double_t* psigma1 = sigma1;
   Double_t esigma1[8];
   Double_t* pesigma1 = esigma1;

   // For the Sigma1 for strips
   Double_t sigma1_CB[8];
   Double_t* psigma1_CB = sigma1_CB;
   Double_t esigma1_CB[8];
   Double_t* pesigma1_CB = esigma1_CB;

   // For the Sigma1 for strips
   Double_t sigma1_Gauss[8];
   Double_t* psigma1_Gauss = sigma1_Gauss;
   Double_t esigma1_Gauss[8];
   Double_t* pesigma1_Gauss = esigma1_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2[8];
   Double_t* psigma2 = sigma2;
   Double_t esigma2[8];
   Double_t* pesigma2 = esigma2;

   // For the Combined Sigma for strips
   Double_t sigmat[8];
   Double_t* psigmat = sigmat;
   Double_t esigmat[8];
   Double_t* pesigmat = esigmat;

   /* //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB1, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB2, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB3, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB4, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB5, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB6, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB7, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB8, -0.3,0.3, psigma1_Gauss++, pesigma1_Gauss++); */

   //Crystal Ball Fit
   myfit(h_mmOnTrackResidualTrack_PCB1, -0.4,0.4, psigma1_CB++, pesigma1_CB++);//-1.4,1.4
   myfit(h_mmOnTrackResidualTrack_PCB2, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-3,3
   myfit(h_mmOnTrackResidualTrack_PCB3, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-4,4
   myfit(h_mmOnTrackResidualTrack_PCB4, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-2,2
   myfit(h_mmOnTrackResidualTrack_PCB5, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-2.2,1.8
   myfit(h_mmOnTrackResidualTrack_PCB6, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-2.2,2.2
   myfit(h_mmOnTrackResidualTrack_PCB7, -0.1,0.1, psigma1_CB++, pesigma1_CB++);//-2.4,2.4
   myfit(h_mmOnTrackResidualTrack_PCB8, -0.3,0.3, psigma1_CB++, pesigma1_CB++);//-2.1,2.1

   /* //Double-Gauss Fit
   fitter(h_mmOnTrackResidualTrack_PCB1, -0.125,0.125, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-1.5,1.5
   fitter(h_mmOnTrackResidualTrack_PCB2, -0.14,0.14, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-1.6,1.6
   fitter2(h_mmOnTrackResidualTrack_PCB3, -0.24,0.24, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-1.8,1.8
   fitter3(h_mmOnTrackResidualTrack_PCB4, -0.34,0.34, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-2,2
   fitter3(h_mmOnTrackResidualTrack_PCB5, -0.125,0.125, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-2.2,2.2
   fitter3(h_mmOnTrackResidualTrack_PCB6, -0.5,0.5, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-2.4,2.4
   fitter3(h_mmOnTrackResidualTrack_PCB7, -0.48,0.48, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-4,4
   fitter4(h_mmOnTrackResidualTrack_PCB8, -0.4,0.4, psigma1++, psigma2++, psigmat++, pesigma1++, pesigma2++, pesigmat++);//-6,6
 */

//////////////////////////////////////////////////////////////////////////////// sigma per theta   

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_theta[8];
   Double_t* psigma1_MS_eta_theta = sigma1_MS_eta_theta;
   Double_t esigma1_MS_eta_theta[8];
   Double_t* pesigma1_MS_eta_theta = esigma1_MS_eta_theta;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_theta_CB[8];
   Double_t* psigma1_MS_eta_theta_CB = sigma1_MS_eta_theta_CB;
   Double_t esigma1_MS_eta_theta_CB[8];
   Double_t* pesigma1_MS_eta_theta_CB = esigma1_MS_eta_theta_CB;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_theta_Gauss[8];
   Double_t* psigma1_MS_eta_theta_Gauss = sigma1_MS_eta_theta_Gauss;
   Double_t esigma1_MS_eta_theta_Gauss[8];
   Double_t* pesigma1_MS_eta_theta_Gauss = esigma1_MS_eta_theta_Gauss;

   // For the Sigma2 for MS eta strips
   Double_t sigma2_MS_eta_theta[8];
   Double_t* psigma2_MS_eta_theta = sigma2_MS_eta_theta;
   Double_t esigma2_MS_eta_theta[8];
   Double_t* pesigma2_MS_eta_theta = esigma2_MS_eta_theta;

   // For the Combined Sigma for MS eta strips
   Double_t sigmat_MS_eta_theta[8];
   Double_t* psigmat_MS_eta_theta = sigmat_MS_eta_theta;
   Double_t esigmat_MS_eta_theta[8];
   Double_t* pesigmat_MS_eta_theta = esigmat_MS_eta_theta;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_theta[8];
   Double_t* psigma1_MS_stereo_theta = sigma1_MS_stereo_theta;
   Double_t esigma1_MS_stereo_theta[8];
   Double_t* pesigma1_MS_stereo_theta = esigma1_MS_stereo_theta;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_theta_CB[8];
   Double_t* psigma1_MS_stereo_theta_CB = sigma1_MS_stereo_theta_CB;
   Double_t esigma1_MS_stereo_theta_CB[8];
   Double_t* pesigma1_MS_stereo_theta_CB = esigma1_MS_stereo_theta_CB;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_theta_Gauss[8];
   Double_t* psigma1_MS_stereo_theta_Gauss = sigma1_MS_stereo_theta_Gauss;
   Double_t esigma1_MS_stereo_theta_Gauss[8];
   Double_t* pesigma1_MS_stereo_theta_Gauss = esigma1_MS_stereo_theta_Gauss;

   // For the Sigma2 for MS stereo strips
   Double_t sigma2_MS_stereo_theta[8];
   Double_t* psigma2_MS_stereo_theta = sigma2_MS_stereo_theta;
   Double_t esigma2_MS_stereo_theta[8];
   Double_t* pesigma2_MS_stereo_theta = esigma2_MS_stereo_theta;

   // For the Combined Sigma for MS stereo strips
   Double_t sigmat_MS_stereo_theta[8];
   Double_t* psigmat_MS_stereo_theta = sigmat_MS_stereo_theta;
   Double_t esigmat_MS_stereo_theta[8];
   Double_t* pesigmat_MS_stereo_theta = esigmat_MS_stereo_theta;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB1_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB2_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB3_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB4_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB5_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB6_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB7_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_PCB8_theta, -0.2,0.2, psigma1_MS_eta_theta_Gauss++, pesigma1_MS_eta_theta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB1_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB2_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB3_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB4_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB5_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB6_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB7_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_PCB8_theta, -0.1,0.1, psigma1_MS_stereo_theta_Gauss++, pesigma1_MS_stereo_theta_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB1_theta, -0.2,0.2, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB2_theta, -0.2,0.2, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-1.6,1.6
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB3_theta, -0.1,0.1, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-2,2
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB4_theta, -0.1,0.1, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-2.5,2.5
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB5_theta, -0.1,0.1, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-2.8,2.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB6_theta, -0.1,0.1, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-3,3.5
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB7_theta, -0.05,0.05, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-3,3
   myfit2(h_eta_mmOnTrackResidualTrackMS_PCB8_theta, -0.5,0.5, psigma1_MS_eta_theta_CB++, pesigma1_MS_eta_theta_CB++);//-4.5,4.5

   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB1_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-2,2
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB2_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-1.6,1.6
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB3_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-2,2
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB4_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-2.5,2.5
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB5_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-2.8,2.8
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB6_theta, -0.1,0.1, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-3.5,4
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB7_theta, -0.05,0.05, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_PCB8_theta, -0.5,0.5, psigma1_MS_stereo_theta_CB++, pesigma1_MS_stereo_theta_CB++);//-4,4 */

   /* //Double-Gauss Fit
   fitter(h_eta_mmOnTrackResidualTrackMS_PCB1_theta, -0.045,0.045, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-1.65,1.7
   fitter2(h_eta_mmOnTrackResidualTrackMS_PCB2_theta, -0.18,0.18, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-2,2
   fitter4(h_eta_mmOnTrackResidualTrackMS_PCB3_theta, -0.24,0.24, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-2.5,2.5
   fitter4(h_eta_mmOnTrackResidualTrackMS_PCB4_theta, -0.15,0.15, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-2.6,2.5
   fitter4(h_eta_mmOnTrackResidualTrackMS_PCB5_theta, -0.17,0.17, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-2.8,3
   fitter4(h_eta_mmOnTrackResidualTrackMS_PCB6_theta, -0.38,0.38, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-3.3,3.2
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB7_theta, -0.2,0.2, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-2.5,2.5
   fitter3(h_eta_mmOnTrackResidualTrackMS_PCB8_theta, -0.5,0.5, psigma1_MS_eta_theta++, psigma2_MS_eta_theta++, psigmat_MS_eta_theta++, pesigma1_MS_eta_theta++, pesigma2_MS_eta_theta++, pesigmat_MS_eta_theta++);//-4,4

   fitter(h_stereo_mmOnTrackResidualTrackMS_PCB1_theta, -0.115,0.115, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-2.5,2.5
   fitter2(h_stereo_mmOnTrackResidualTrackMS_PCB2_theta, -0.18,0.18, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-2,2
   fitter4(h_stereo_mmOnTrackResidualTrackMS_PCB3_theta, -0.44,0.44, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-2.4,2.3
   fitter4(h_stereo_mmOnTrackResidualTrackMS_PCB4_theta, -0.15,0.15, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-2.6,2.6
   fitter4(h_stereo_mmOnTrackResidualTrackMS_PCB5_theta, -0.17,0.17, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-3,3
   fitter4(h_stereo_mmOnTrackResidualTrackMS_PCB6_theta, -0.26,0.26, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-3.6,3.6
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB7_theta, -0.5,0.5, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-2.4,2.4
   fitter3(h_stereo_mmOnTrackResidualTrackMS_PCB8_theta, -0.5,0.5, psigma1_MS_stereo_theta++, psigma2_MS_stereo_theta++, psigmat_MS_stereo_theta++, pesigma1_MS_stereo_theta++, pesigma2_MS_stereo_theta++, pesigmat_MS_stereo_theta++);//-3.8,3.8
 */
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_theta[8];
   Double_t* psigma1_MS_theta = sigma1_MS_theta;
   Double_t esigma1_MS_theta[8];
   Double_t* pesigma1_MS_theta = esigma1_MS_theta;

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_theta_CB[8];
   Double_t* psigma1_MS_theta_CB = sigma1_MS_theta_CB;
   Double_t esigma1_MS_theta_CB[8];
   Double_t* pesigma1_MS_theta_CB = esigma1_MS_theta_CB;

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_theta_Gauss[8];
   Double_t* psigma1_MS_theta_Gauss = sigma1_MS_theta_Gauss;
   Double_t esigma1_MS_theta_Gauss[8];
   Double_t* pesigma1_MS_theta_Gauss = esigma1_MS_theta_Gauss;

   // For the Sigma2 for MS strips
   Double_t sigma2_MS_theta[8];
   Double_t* psigma2_MS_theta = sigma2_MS_theta;
   Double_t esigma2_MS_theta[8];
   Double_t* pesigma2_MS_theta = esigma2_MS_theta;

   // For the Combined Sigma for MS strips
   Double_t sigmat_MS_theta[8];
   Double_t* psigmat_MS_theta = sigmat_MS_theta;
   Double_t esigmat_MS_theta[8];
   Double_t* pesigmat_MS_theta = esigmat_MS_theta;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB1_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB2_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB3_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB4_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB5_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB6_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB7_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_PCB8_theta, -0.2,0.2, psigma1_MS_theta_Gauss++, pesigma1_MS_theta_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_mmOnTrackResidualTrackMS_PCB1_theta, -0.2,0.2, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrackMS_PCB2_theta, -0.1,0.1, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-1.5,1.5
   myfit2(h_mmOnTrackResidualTrackMS_PCB3_theta, -0.1,0.1, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-2,2
   myfit2(h_mmOnTrackResidualTrackMS_PCB4_theta, -0.1,0.1, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-2.5,2.5
   myfit2(h_mmOnTrackResidualTrackMS_PCB5_theta, -0.1,0.1, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-2.8,2.8
   myfit2(h_mmOnTrackResidualTrackMS_PCB6_theta, -0.1,0.1, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-3,3
   myfit2(h_mmOnTrackResidualTrackMS_PCB7_theta, -0.05,0.05, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-3,3
   myfit2(h_mmOnTrackResidualTrackMS_PCB8_theta, -0.05,0.05, psigma1_MS_theta_CB++, pesigma1_MS_theta_CB++);//-4,3.9 */

   /* //Double-Gauss Fit
   fitter(h_mmOnTrackResidualTrackMS_PCB1_theta, -0.04,0.04, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-2,2
   fitter2(h_mmOnTrackResidualTrackMS_PCB2_theta, -0.12,0.12, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-2,2
   fitter4(h_mmOnTrackResidualTrackMS_PCB3_theta, -0.04,0.04, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-2.3,2.3
   fitter4(h_mmOnTrackResidualTrackMS_PCB4_theta, -0.06,0.06, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-2.6,2.6
   fitter4(h_mmOnTrackResidualTrackMS_PCB5_theta, -0.164,0.164, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-3,3
   fitter4(h_mmOnTrackResidualTrackMS_PCB6_theta, -0.5,0.5, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-3.3,3.2
   fitter3(h_mmOnTrackResidualTrackMS_PCB7_theta, -0.5,0.5, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-3.4,3.4
   fitter3(h_mmOnTrackResidualTrackMS_PCB8_theta, -0.5,0.5, psigma1_MS_theta++, psigma2_MS_theta++, psigmat_MS_theta++, pesigma1_MS_theta++, pesigma2_MS_theta++, pesigmat_MS_theta++);//-3.8,3.8
 */

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_theta[8];
   Double_t* psigma1_eta_theta = sigma1_eta_theta;
   Double_t esigma1_eta_theta[8];
   Double_t* pesigma1_eta_theta = esigma1_eta_theta;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_theta_CB[8];
   Double_t* psigma1_eta_theta_CB = sigma1_eta_theta_CB;
   Double_t esigma1_eta_theta_CB[8];
   Double_t* pesigma1_eta_theta_CB = esigma1_eta_theta_CB;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_theta_Gauss[8];
   Double_t* psigma1_eta_theta_Gauss = sigma1_eta_theta_Gauss;
   Double_t esigma1_eta_theta_Gauss[8];
   Double_t* pesigma1_eta_theta_Gauss = esigma1_eta_theta_Gauss;

   // For the Sigma2 for eta strips
   Double_t sigma2_eta_theta[8];
   Double_t* psigma2_eta_theta = sigma2_eta_theta;
   Double_t esigma2_eta_theta[8];
   Double_t* pesigma2_eta_theta = esigma2_eta_theta;

   // For the Combined Sigma for eta strips
   Double_t sigmat_eta_theta[8];
   Double_t* psigmat_eta_theta = sigmat_eta_theta;
   Double_t esigmat_eta_theta[8];
   Double_t* pesigmat_eta_theta = esigmat_eta_theta;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_theta[8];
   Double_t* psigma1_stereo_theta = sigma1_stereo_theta;
   Double_t esigma1_stereo_theta[8];
   Double_t* pesigma1_stereo_theta = esigma1_stereo_theta;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_theta_CB[8];
   Double_t* psigma1_stereo_theta_CB = sigma1_stereo_theta_CB;
   Double_t esigma1_stereo_theta_CB[8];
   Double_t* pesigma1_stereo_theta_CB = esigma1_stereo_theta_CB;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_theta_Gauss[8];
   Double_t* psigma1_stereo_theta_Gauss = sigma1_stereo_theta_Gauss;
   Double_t esigma1_stereo_theta_Gauss[8];
   Double_t* pesigma1_stereo_theta_Gauss = esigma1_stereo_theta_Gauss;

   // For the Sigma2 for stereo strips
   Double_t sigma2_stereo_theta[8];
   Double_t* psigma2_stereo_theta = sigma2_stereo_theta;
   Double_t esigma2_stereo_theta[8];
   Double_t* pesigma2_stereo_theta = esigma2_stereo_theta;

   // For the Combined Sigma for stereo strips
   Double_t sigmat_stereo_theta[8];
   Double_t* psigmat_stereo_theta = sigmat_stereo_theta;
   Double_t esigmat_stereo_theta[8];
   Double_t* pesigmat_stereo_theta = esigmat_stereo_theta;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB1_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB2_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB3_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB4_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB5_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB6_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB7_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_PCB8_theta, -0.2,0.2, psigma1_eta_theta_Gauss++, pesigma1_eta_theta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB1_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB2_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB3_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB4_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB5_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB6_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB7_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_PCB8_theta, -0.1,0.1, psigma1_stereo_theta_Gauss++, pesigma1_stereo_theta_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_eta_mmOnTrackResidualTrack_PCB1_theta, -0.15,0.15, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.4,1.4
   myfit2(h_eta_mmOnTrackResidualTrack_PCB2_theta, -0.1,0.1, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.6,1.6
   myfit2(h_eta_mmOnTrackResidualTrack_PCB3_theta, -0.1,0.1, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.5,1.5
   myfit2(h_eta_mmOnTrackResidualTrack_PCB4_theta, -0.1,0.1, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.4,1.4
   myfit2(h_eta_mmOnTrackResidualTrack_PCB5_theta, -0.1,0.1, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.5,1.5
   myfit2(h_eta_mmOnTrackResidualTrack_PCB6_theta, -0.15,0.15, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrack_PCB7_theta, -0.05,0.05, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-1.6,1.6
   myfit2(h_eta_mmOnTrackResidualTrack_PCB8_theta, -0.15,0.15, psigma1_eta_theta_CB++, pesigma1_eta_theta_CB++);//-4,5

   myfit2(h_stereo_mmOnTrackResidualTrack_PCB1_theta, -0.15,0.15, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-1.6,1.6
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB2_theta, -0.1,0.1, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-1.6,1.6
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB3_theta, -0.1,0.1, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-1.5,1.5
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB4_theta, -0.1,0.1, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-1.4,1.4
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB5_theta, -0.15,0.15, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-2.2,2.2
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB6_theta, -0.15,0.15, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-3,2
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB7_theta, -0.05,0.05, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrack_PCB8_theta, -0.05,0.05, psigma1_stereo_theta_CB++, pesigma1_stereo_theta_CB++);//-4,4 */

   /* //Double-Gauss Fit
   fitter(h_eta_mmOnTrackResidualTrack_PCB1_theta, -0.064,0.064, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.4,1.4
   fitter2(h_eta_mmOnTrackResidualTrack_PCB2_theta, -0.26,0.26, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.6,1.6
   fitter3(h_eta_mmOnTrackResidualTrack_PCB3_theta, -0.24,0.24, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.5,1.5
   fitter3(h_eta_mmOnTrackResidualTrack_PCB4_theta, -0.2,0.2, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.4,1.4
   fitter3(h_eta_mmOnTrackResidualTrack_PCB5_theta, -0.12,0.12, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.5,1.5
   fitter4(h_eta_mmOnTrackResidualTrack_PCB6_theta, -0.5,0.5, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.8,1.8
   fitter3(h_eta_mmOnTrackResidualTrack_PCB7_theta, -0.5,0.5, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-1.6,1.6
   fitter3(h_eta_mmOnTrackResidualTrack_PCB8_theta, -0.5,0.5, psigma1_eta_theta++, psigma2_eta_theta++, psigmat_eta_theta++, pesigma1_eta_theta++, pesigma2_eta_theta++, pesigmat_eta_theta++);//-4,5

   fitter(h_stereo_mmOnTrackResidualTrack_PCB1_theta, -0.064,0.064, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-1.6,1.6
   fitter2(h_stereo_mmOnTrackResidualTrack_PCB2_theta, -0.23,0.23, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-1.6,1.6
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB3_theta, -0.26,0.26, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-1.5,1.5
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB4_theta, -0.07,0.07, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-1.4,1.4
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB5_theta, -0.06,0.06, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-2.2,2.2
   fitter4(h_stereo_mmOnTrackResidualTrack_PCB6_theta, -0.38,0.38, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-3,2
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB7_theta, -0.5,0.5, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-3,3
   fitter3(h_stereo_mmOnTrackResidualTrack_PCB8_theta, -0.53,0.53, psigma1_stereo_theta++, psigma2_stereo_theta++, psigmat_stereo_theta++, pesigma1_stereo_theta++, pesigma2_stereo_theta++, pesigmat_stereo_theta++);//-4,4
 */
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_theta[8];
   Double_t* psigma1_theta = sigma1_theta;
   Double_t esigma1_theta[8];
   Double_t* pesigma1_theta = esigma1_theta;

   // For the Sigma1 for strips
   Double_t sigma1_theta_CB[8];
   Double_t* psigma1_theta_CB = sigma1_theta_CB;
   Double_t esigma1_theta_CB[8];
   Double_t* pesigma1_theta_CB = esigma1_theta_CB;

   // For the Sigma1 for strips
   Double_t sigma1_theta_Gauss[8];
   Double_t* psigma1_theta_Gauss = sigma1_theta_Gauss;
   Double_t esigma1_theta_Gauss[8];
   Double_t* pesigma1_theta_Gauss = esigma1_theta_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_theta[8];
   Double_t* psigma2_theta = sigma2_theta;
   Double_t esigma2_theta[8];
   Double_t* pesigma2_theta = esigma2_theta;

   // For the Combined Sigma for strips
   Double_t sigmat_theta[8];
   Double_t* psigmat_theta = sigmat_theta;
   Double_t esigmat_theta[8];
   Double_t* pesigmat_theta = esigmat_theta;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB1_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB2_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB3_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB4_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB5_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB6_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB7_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_PCB8_theta, -0.2,0.2, psigma1_theta_Gauss++, pesigma1_theta_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_mmOnTrackResidualTrack_PCB1_theta, -0.07,0.07, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.5,1.5
   myfit2(h_mmOnTrackResidualTrack_PCB2_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.1,1.1
   myfit2(h_mmOnTrackResidualTrack_PCB3_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrack_PCB4_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.4,1.4
   myfit2(h_mmOnTrackResidualTrack_PCB5_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.5,1.5
   myfit2(h_mmOnTrackResidualTrack_PCB6_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrack_PCB7_theta, -0.1,0.1, psigma1_theta_CB++, pesigma1_theta_CB++);//-1.6,1.6
   myfit2(h_mmOnTrackResidualTrack_PCB8_theta, -0.15,0.15, psigma1_theta_CB++, pesigma1_theta_CB++);//-3.5,3.5 */

   /* //Double-Gauss Fit
   fitter(h_mmOnTrackResidualTrack_PCB1_theta, -0.06,0.06, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.5,1.5
   fitter2(h_mmOnTrackResidualTrack_PCB2_theta, -0.15,0.15, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.1,1.1
   fitter3(h_mmOnTrackResidualTrack_PCB3_theta, -0.27,0.27, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.8,1.8
   fitter3(h_mmOnTrackResidualTrack_PCB4_theta, -0.23,0.23, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.4,1.4
   fitter3(h_mmOnTrackResidualTrack_PCB5_theta, -0.119,0.119, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.5,1.5
   fitter4(h_mmOnTrackResidualTrack_PCB6_theta, -0.26,0.26, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.8,1.8
   fitter3(h_mmOnTrackResidualTrack_PCB7_theta, -0.45,0.45, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-1.6,1.6
   fitter3(h_mmOnTrackResidualTrack_PCB8_theta, -0.5,0.5, psigma1_theta++, psigma2_theta++, psigmat_theta++, pesigma1_theta++, pesigma2_theta++, pesigmat_theta++);//-3.5,3.5
 */

/////////////////////////////////////////////////////////////////////////////////////////// sigma per eta

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_eta[14];
   Double_t* psigma1_MS_eta_eta = sigma1_MS_eta_eta;
   Double_t esigma1_MS_eta_eta[14];
   Double_t* pesigma1_MS_eta_eta = esigma1_MS_eta_eta;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_eta_CB[14];
   Double_t* psigma1_MS_eta_eta_CB = sigma1_MS_eta_eta_CB;
   Double_t esigma1_MS_eta_eta_CB[14];
   Double_t* pesigma1_MS_eta_eta_CB = esigma1_MS_eta_eta_CB;

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_eta_Gauss[14];
   Double_t* psigma1_MS_eta_eta_Gauss = sigma1_MS_eta_eta_Gauss;
   Double_t esigma1_MS_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_eta_eta_Gauss = esigma1_MS_eta_eta_Gauss;

   // For the Sigma2 for MS eta strips
   Double_t sigma2_MS_eta_eta[14];
   Double_t* psigma2_MS_eta_eta = sigma2_MS_eta_eta;
   Double_t esigma2_MS_eta_eta[14];
   Double_t* pesigma2_MS_eta_eta = esigma2_MS_eta_eta;

   // For the Combined Sigma for MS eta strips
   Double_t sigmat_MS_eta_eta[14];
   Double_t* psigmat_MS_eta_eta = sigmat_MS_eta_eta;
   Double_t esigmat_MS_eta_eta[14];
   Double_t* pesigmat_MS_eta_eta = esigmat_MS_eta_eta;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_eta[14];
   Double_t* psigma1_MS_stereo_eta = sigma1_MS_stereo_eta;
   Double_t esigma1_MS_stereo_eta[14];
   Double_t* pesigma1_MS_stereo_eta = esigma1_MS_stereo_eta;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_eta_CB[14];
   Double_t* psigma1_MS_stereo_eta_CB = sigma1_MS_stereo_eta_CB;
   Double_t esigma1_MS_stereo_eta_CB[14];
   Double_t* pesigma1_MS_stereo_eta_CB = esigma1_MS_stereo_eta_CB;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_stereo_eta_Gauss = sigma1_MS_stereo_eta_Gauss;
   Double_t esigma1_MS_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_stereo_eta_Gauss = esigma1_MS_stereo_eta_Gauss;

   // For the Sigma2 for MS stereo strips
   Double_t sigma2_MS_stereo_eta[14];
   Double_t* psigma2_MS_stereo_eta = sigma2_MS_stereo_eta;
   Double_t esigma2_MS_stereo_eta[14];
   Double_t* pesigma2_MS_stereo_eta = esigma2_MS_stereo_eta;

   // For the Combined Sigma for MS stereo strips
   Double_t sigmat_MS_stereo_eta[14];
   Double_t* psigmat_MS_stereo_eta = sigmat_MS_stereo_eta;
   Double_t esigmat_MS_stereo_eta[14];
   Double_t* pesigmat_MS_stereo_eta = esigmat_MS_stereo_eta;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta1, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta2, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta3, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta4, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta5, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta6, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta7, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta8, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta9, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);   
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta10, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);  
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta11, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);  
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta12, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta13, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++); 
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_eta14, -0.3,0.3, psigma1_MS_eta_eta_Gauss++, pesigma1_MS_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta1, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta2, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta3, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta4, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta5, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta6, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta7, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta8, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta9, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta10, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++); 
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta11, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta12, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);  
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta13, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);  
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_eta14, -0.3,0.3, psigma1_MS_stereo_eta_Gauss++, pesigma1_MS_stereo_eta_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta1, -.73,.73, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-3.5,3.5
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta2, -0.05,0.05, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-3,3
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta3, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-3.8,3.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta4, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2.6,2.6
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta5, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2.4,2.4
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta6, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2.5,2.5
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta7, -0.05,0.05, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2.3,2.3
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta8, -0.09,0.09, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2,2
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta9, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-1.9,1.9
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta10, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta11, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-1.7,1.7
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta12, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-1.9,1.9
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta13, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-1.8,1.8
   myfit2(h_eta_mmOnTrackResidualTrackMS_eta14, -0.1,0.1, psigma1_MS_eta_eta_CB++, pesigma1_MS_eta_eta_CB++);//-2,2

   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta1, -.73,.73, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-3.5,3.5
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta2, -0.05,0.05, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta3, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-3.8,3.8
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta4, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2.6,2.6
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta5, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2.4,2.4
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta6, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta7, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-3,3
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta8, -0.15,0.15, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2.7,2.7
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta9, -0.13,0.13, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-1.9,1.9
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta10, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-1.8,1.8
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta11, -0.15,0.15, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-1.7,1.7
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta12, -.47,.47, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2.7,2.7
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta13, -0.15,0.15, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2,2
   myfit2(h_stereo_mmOnTrackResidualTrackMS_eta14, -0.1,0.1, psigma1_MS_stereo_eta_CB++, pesigma1_MS_stereo_eta_CB++);//-2,2 */

   /* //Double-Gauss Fit
   fitter5(h_eta_mmOnTrackResidualTrackMS_eta1, -0.5,0.5, psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-4,3.8
   fitter4(h_eta_mmOnTrackResidualTrackMS_eta2,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-3,3
   fitter4(h_eta_mmOnTrackResidualTrackMS_eta3,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-3.8,3.8
   fitter4(h_eta_mmOnTrackResidualTrackMS_eta4,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2.6,2.6
   fitter3(h_eta_mmOnTrackResidualTrackMS_eta5,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2.4,2.4
   fitter3(h_eta_mmOnTrackResidualTrackMS_eta6,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2.5,2.5
   fitter3(h_eta_mmOnTrackResidualTrackMS_eta7, -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2.3,2.3
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta8,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2,2
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta9,  -0.42,0.42,psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-1.9,1.9
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta10, -0.42,0.42, psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-1.8,1.8
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta11, -0.42,0.42, psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-1.7,1.7
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta12, -0.42,0.42, psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-1.6,1.7
   fitter2(h_eta_mmOnTrackResidualTrackMS_eta13, -0.42,0.42, psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-1.8,1.8
   fitter(h_eta_mmOnTrackResidualTrackMS_eta14, -0.42,0.42 , psigma1_MS_eta_eta++, psigma2_MS_eta_eta++, psigmat_MS_eta_eta++, pesigma1_MS_eta_eta++, pesigma2_MS_eta_eta++, pesigmat_MS_eta_eta++);//-2.6,1.55

   fitter5(h_stereo_mmOnTrackResidualTrackMS_eta1, -0.5,0.5, psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-3.5,3.5
   fitter4(h_stereo_mmOnTrackResidualTrackMS_eta2,  -0.42,0.42,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-3,3
   fitter4(h_stereo_mmOnTrackResidualTrackMS_eta3,  -0.45,0.45,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2,2
   fitter4(h_stereo_mmOnTrackResidualTrackMS_eta4,  -0.42,0.42,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2.6,2.6
   fitter3(h_stereo_mmOnTrackResidualTrackMS_eta5,  -0.42,0.42,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2.4,2.4
   fitter3(h_stereo_mmOnTrackResidualTrackMS_eta6,  -0.48,0.48,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-3,3
   fitter3(h_stereo_mmOnTrackResidualTrackMS_eta7,  -0.42,0.42,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-3,3
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta8,  -0.42,0.42,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2.7,2.7
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta9,  -0.44,0.44,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-1.9,1.9
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta10, -0.42,0.42, psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-1.8,1.8
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta11, -0.42,0.42, psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-1.7,1.7
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta12, -0.42,0.42, psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-1.8,2.5
   fitter2(h_stereo_mmOnTrackResidualTrackMS_eta13, -0.42,0.42, psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2,2
   fitter(h_stereo_mmOnTrackResidualTrackMS_eta14,  -0.42,0.42 ,psigma1_MS_stereo_eta++, psigma2_MS_stereo_eta++, psigmat_MS_stereo_eta++, pesigma1_MS_stereo_eta++, pesigma2_MS_stereo_eta++, pesigmat_MS_stereo_eta++);//-2,2
 */

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Eta[14];
   Double_t* psigma1_MS_Eta = sigma1_MS_Eta;
   Double_t esigma1_MS_Eta[14];
   Double_t* pesigma1_MS_Eta = esigma1_MS_Eta;

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Eta_CB[14];
   Double_t* psigma1_MS_Eta_CB = sigma1_MS_Eta_CB;
   Double_t esigma1_MS_Eta_CB[14];
   Double_t* pesigma1_MS_Eta_CB = esigma1_MS_Eta_CB;

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Eta_Gauss[14];
   Double_t* psigma1_MS_Eta_Gauss = sigma1_MS_Eta_Gauss;
   Double_t esigma1_MS_Eta_Gauss[14];
   Double_t* pesigma1_MS_Eta_Gauss = esigma1_MS_Eta_Gauss;

   // For the Sigma2 for MS strips
   Double_t sigma2_MS_Eta[14];
   Double_t* psigma2_MS_Eta = sigma2_MS_Eta;
   Double_t esigma2_MS_Eta[14];
   Double_t* pesigma2_MS_Eta = esigma2_MS_Eta;

   // For the Combined Sigma for MS strips
   Double_t sigmat_MS_Eta[14];
   Double_t* psigmat_MS_Eta = sigmat_MS_Eta;
   Double_t esigmat_MS_Eta[14];
   Double_t* pesigmat_MS_Eta = esigmat_MS_Eta;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta1, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-4,4
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta2, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-3,3
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta3, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-3.2,3.3
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta4, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.8,1.8
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta5, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.75,1.75
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta6, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-2.7,2.7
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta7, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-3,3
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta8, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-2,2
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta9, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.9,1.9   
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta10, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.8,1.8   
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta11, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.7,1.7   
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta12, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.65,1.65   
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta13, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.25,1.25   
   fitter_Gauss(h_mmOnTrackResidualTrackMS_eta14, -0.3,0.3, psigma1_MS_Eta_Gauss++, pesigma1_MS_Eta_Gauss++);//-1.7,1.7

   /* //Crystal Ball Fit
   myfit2(h_mmOnTrackResidualTrackMS_eta1, -0.66,0.66, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-3.1,3.1
   myfit2(h_mmOnTrackResidualTrackMS_eta2, -0.05,0.05, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-3,3
   myfit2(h_mmOnTrackResidualTrackMS_eta3, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-3.8,3.8
   myfit2(h_mmOnTrackResidualTrackMS_eta4, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-4,4
   myfit2(h_mmOnTrackResidualTrackMS_eta5, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-4,4
   myfit2(h_mmOnTrackResidualTrackMS_eta6, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-2.5,2.5
   myfit2(h_mmOnTrackResidualTrackMS_eta7, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-3,3
   myfit2(h_mmOnTrackResidualTrackMS_eta8, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-2,2
   myfit2(h_mmOnTrackResidualTrackMS_eta9, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-1.9,1.9
   myfit2(h_mmOnTrackResidualTrackMS_eta10, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-1.8,1.8
   myfit2(h_mmOnTrackResidualTrackMS_eta11, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-1.7,1.7
   myfit2(h_mmOnTrackResidualTrackMS_eta12, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-3.1,3.1
   myfit2(h_mmOnTrackResidualTrackMS_eta13, -0.1,0.1, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-2.5,2.5
   myfit2(h_mmOnTrackResidualTrackMS_eta14, -0.098,0.098, psigma1_MS_Eta_CB++, pesigma1_MS_Eta_CB++);//-1.7,1.7 */

   /* //Double-Gauss Fit
   fitter5(h_mmOnTrackResidualTrackMS_eta1, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-4,4
   fitter4(h_mmOnTrackResidualTrackMS_eta2, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-3,3
   fitter4(h_mmOnTrackResidualTrackMS_eta3, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-3.2,3.3
   fitter3(h_mmOnTrackResidualTrackMS_eta4, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.8,1.8
   fitter3(h_mmOnTrackResidualTrackMS_eta5, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.75,1.75
   fitter3(h_mmOnTrackResidualTrackMS_eta6, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-2.7,2.7
   fitter3(h_mmOnTrackResidualTrackMS_eta7, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-3,3
   fitter2(h_mmOnTrackResidualTrackMS_eta8, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-2,2
   fitter2(h_mmOnTrackResidualTrackMS_eta9, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.9,1.9
   fitter2(h_mmOnTrackResidualTrackMS_eta10, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.8,1.8
   fitter2(h_mmOnTrackResidualTrackMS_eta11, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.7,1.7
   fitter2(h_mmOnTrackResidualTrackMS_eta12, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.65,1.65
   fitter2(h_mmOnTrackResidualTrackMS_eta13, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.25,1.25
   fitter(h_mmOnTrackResidualTrackMS_eta14, -0.3,0.3, psigma1_MS_Eta++, psigma2_MS_Eta++, psigmat_MS_Eta++, pesigma1_MS_Eta++, pesigma2_MS_Eta++, pesigmat_MS_Eta++);//-1.7,1.7
 */ 

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_eta[14];
   Double_t* psigma1_eta_eta = sigma1_eta_eta;
   Double_t esigma1_eta_eta[14];
   Double_t* pesigma1_eta_eta = esigma1_eta_eta;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_eta_CB[14];
   Double_t* psigma1_eta_eta_CB = sigma1_eta_eta_CB;
   Double_t esigma1_eta_eta_CB[14];
   Double_t* pesigma1_eta_eta_CB = esigma1_eta_eta_CB;

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_eta_Gauss[14];
   Double_t* psigma1_eta_eta_Gauss = sigma1_eta_eta_Gauss;
   Double_t esigma1_eta_eta_Gauss[14];
   Double_t* pesigma1_eta_eta_Gauss = esigma1_eta_eta_Gauss;

   // For the Sigma2 for eta strips
   Double_t sigma2_eta_eta[14];
   Double_t* psigma2_eta_eta = sigma2_eta_eta;
   Double_t esigma2_eta_eta[14];
   Double_t* pesigma2_eta_eta = esigma2_eta_eta;

   // For the Combined Sigma for eta strips
   Double_t sigmat_eta_eta[14];
   Double_t* psigmat_eta_eta = sigmat_eta_eta;
   Double_t esigmat_eta_eta[14];
   Double_t* pesigmat_eta_eta = esigmat_eta_eta;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_eta[14];
   Double_t* psigma1_stereo_eta = sigma1_stereo_eta;
   Double_t esigma1_stereo_eta[14];
   Double_t* pesigma1_stereo_eta = esigma1_stereo_eta;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_eta_CB[14];
   Double_t* psigma1_stereo_eta_CB = sigma1_stereo_eta_CB;
   Double_t esigma1_stereo_eta_CB[14];
   Double_t* pesigma1_stereo_eta_CB = esigma1_stereo_eta_CB;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_eta_Gauss[14];
   Double_t* psigma1_stereo_eta_Gauss = sigma1_stereo_eta_Gauss;
   Double_t esigma1_stereo_eta_Gauss[14];
   Double_t* pesigma1_stereo_eta_Gauss = esigma1_stereo_eta_Gauss;

   // For the Sigma2 for stereo strips
   Double_t sigma2_stereo_eta[14];
   Double_t* psigma2_stereo_eta = sigma2_stereo_eta;
   Double_t esigma2_stereo_eta[14];
   Double_t* pesigma2_stereo_eta = esigma2_stereo_eta;

   // For the Combined Sigma for stereo strips
   Double_t sigmat_stereo_eta[14];
   Double_t* psigmat_stereo_eta = sigmat_stereo_eta;
   Double_t esigmat_stereo_eta[14];
   Double_t* pesigmat_stereo_eta = esigmat_stereo_eta;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta1, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-4,4
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta2, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-3,3
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta3, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-3.2,3.3
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta4, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.8,1.8
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta5, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.75,1.75
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta6, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-2.7,2.7
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta7, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-3,3
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta8, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-2,2
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta9, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.9,1.9   
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta10, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.8,1.8   
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta11, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.7,1.7   
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta12, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.65,1.65   
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta13, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.25,1.25   
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_eta14, -0.3,0.3, psigma1_eta_eta_Gauss++, pesigma1_eta_eta_Gauss++);//-1.7,1.7

   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta1, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-4,4
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta2, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-3,3
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta3, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-3.2,3.3
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta4, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.8,1.8
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta5, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.75,1.75
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta6, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-2.7,2.7
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta7, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-3,3
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta8, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-2,2
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta9, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.9,1.9   
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta10, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.8,1.8   
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta11, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.7,1.7   
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta12, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.65,1.65   
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta13, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.25,1.25   
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_eta14, -0.3,0.3, psigma1_stereo_eta_Gauss++, pesigma1_stereo_eta_Gauss++);//-1.7,1.7

   /* //Crystal Ball Fit
   myfit2(h_eta_mmOnTrackResidualTrack_eta1, -0.2,0.2, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-7,7
   myfit2(h_eta_mmOnTrackResidualTrack_eta2, -0.05,0.05, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-2.2,2.2
   myfit2(h_eta_mmOnTrackResidualTrack_eta3, -0.05,0.05, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-6,6
   myfit2(h_eta_mmOnTrackResidualTrack_eta4, -0.2,0.2, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-2.2,2.2
   myfit2(h_eta_mmOnTrackResidualTrack_eta5, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-6,6
   myfit2(h_eta_mmOnTrackResidualTrack_eta6, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-5,5
   myfit2(h_eta_mmOnTrackResidualTrack_eta7, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1,1
   myfit2(h_eta_mmOnTrackResidualTrack_eta8, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1.2,1.2
   myfit2(h_eta_mmOnTrackResidualTrack_eta9, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1.5,1.5
   myfit2(h_eta_mmOnTrackResidualTrack_eta10, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-0.5,0.5
   myfit2(h_eta_mmOnTrackResidualTrack_eta11, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-0.5,0.5
   myfit2(h_eta_mmOnTrackResidualTrack_eta12, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1.3,1.3
   myfit2(h_eta_mmOnTrackResidualTrack_eta13, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1.4,1.4
   myfit2(h_eta_mmOnTrackResidualTrack_eta14, -0.1,0.1, psigma1_eta_eta_CB++, pesigma1_eta_eta_CB++);//-1.5,1.5

   myfit2(h_stereo_mmOnTrackResidualTrack_eta1, -0.05,0.05, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-8,8
   myfit2(h_stereo_mmOnTrackResidualTrack_eta2, -0.05,0.05, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-2.2,2.2
   myfit2(h_stereo_mmOnTrackResidualTrack_eta3, -0.05,0.05, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-2.5,2.5
   myfit2(h_stereo_mmOnTrackResidualTrack_eta4, -0.27,0.27, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-2.2,2.2
   myfit2(h_stereo_mmOnTrackResidualTrack_eta5, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-6,6
   myfit2(h_stereo_mmOnTrackResidualTrack_eta6, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-5,5
   myfit2(h_stereo_mmOnTrackResidualTrack_eta7, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.3,1.3
   myfit2(h_stereo_mmOnTrackResidualTrack_eta8, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.3,1.3
   myfit2(h_stereo_mmOnTrackResidualTrack_eta9, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.5,1.5
   myfit2(h_stereo_mmOnTrackResidualTrack_eta10, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-0.8,0.8
   myfit2(h_stereo_mmOnTrackResidualTrack_eta11, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1,1
   myfit2(h_stereo_mmOnTrackResidualTrack_eta12, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.3,1.3
   myfit2(h_stereo_mmOnTrackResidualTrack_eta13, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.4,1.4
   myfit2(h_stereo_mmOnTrackResidualTrack_eta14, -0.1,0.1, psigma1_stereo_eta_CB++, pesigma1_stereo_eta_CB++);//-1.5,1.5 */

   /* //Double-Gauss Fit
   fitter5(h_eta_mmOnTrackResidualTrack_eta1, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-4,4
   fitter4(h_eta_mmOnTrackResidualTrack_eta2, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-2.2,2.2
   fitter4(h_eta_mmOnTrackResidualTrack_eta3, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-2.6,2.3
   fitter4(h_eta_mmOnTrackResidualTrack_eta4, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-2.2,2.2
   fitter3(h_eta_mmOnTrackResidualTrack_eta5, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.3,1.3
   fitter3(h_eta_mmOnTrackResidualTrack_eta6, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.55,1.55
   fitter3(h_eta_mmOnTrackResidualTrack_eta7, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1,1
   fitter2(h_eta_mmOnTrackResidualTrack_eta8, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.2,1.2
   fitter2(h_eta_mmOnTrackResidualTrack_eta9, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.5,1.5
   fitter2(h_eta_mmOnTrackResidualTrack_eta10, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-0.5,0.5
   fitter2(h_eta_mmOnTrackResidualTrack_eta11, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-0.5,0.5
   fitter2(h_eta_mmOnTrackResidualTrack_eta12, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.3,1.3
   fitter2(h_eta_mmOnTrackResidualTrack_eta13, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-1.4,1.4
   fitter2(h_eta_mmOnTrackResidualTrack_eta14, -0.5,0.5, psigma1_eta_eta++, psigma2_eta_eta++, psigmat_eta_eta++, pesigma1_eta_eta++, pesigma2_eta_eta++, pesigmat_eta_eta++);//-2,2

   fitter5(h_stereo_mmOnTrackResidualTrack_eta1, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-8,8
   fitter4(h_stereo_mmOnTrackResidualTrack_eta2, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-2.2,2.2
   fitter4(h_stereo_mmOnTrackResidualTrack_eta3, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-2.5,2.5
   fitter4(h_stereo_mmOnTrackResidualTrack_eta4, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-2.2,2.2
   fitter3(h_stereo_mmOnTrackResidualTrack_eta5, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-2.2,2.2
   fitter3(h_stereo_mmOnTrackResidualTrack_eta6, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-5,5
   fitter3(h_stereo_mmOnTrackResidualTrack_eta7, -0.5,0.5,psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1.3,1.3
   fitter2(h_stereo_mmOnTrackResidualTrack_eta8, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1.3,1.3
   fitter2(h_stereo_mmOnTrackResidualTrack_eta9, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1.5,1.5
   fitter2(h_stereo_mmOnTrackResidualTrack_eta10, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-0.8,0.8
   fitter2(h_stereo_mmOnTrackResidualTrack_eta11, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1,1
   fitter2(h_stereo_mmOnTrackResidualTrack_eta12, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1.3,1.3
   fitter2(h_stereo_mmOnTrackResidualTrack_eta13, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-1.4,1.4
   fitter2(h_stereo_mmOnTrackResidualTrack_eta14, -0.5,0.5, psigma1_stereo_eta++, psigma2_stereo_eta++, psigmat_stereo_eta++, pesigma1_stereo_eta++, pesigma2_stereo_eta++, pesigmat_stereo_eta++);//-2.5,2.5
 */
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_Eta[14];
   Double_t* psigma1_Eta = sigma1_Eta;
   Double_t esigma1_Eta[14];
   Double_t* pesigma1_Eta = esigma1_Eta;

   // For the Sigma1 for strips
   Double_t sigma1_Eta_CB[14];
   Double_t* psigma1_Eta_CB = sigma1_Eta_CB;
   Double_t esigma1_Eta_CB[14];
   Double_t* pesigma1_Eta_CB = esigma1_Eta_CB;

   // For the Sigma1 for strips
   Double_t sigma1_Eta_Gauss[14];
   Double_t* psigma1_Eta_Gauss = sigma1_Eta_Gauss;
   Double_t esigma1_Eta_Gauss[14];
   Double_t* pesigma1_Eta_Gauss = esigma1_Eta_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_Eta[14];
   Double_t* psigma2_Eta = sigma2_Eta;
   Double_t esigma2_Eta[14];
   Double_t* pesigma2_Eta = esigma2_Eta;

   // For the Combined Sigma for strips
   Double_t sigmat_Eta[14];
   Double_t* psigmat_Eta = sigmat_Eta;
   Double_t esigmat_Eta[14];
   Double_t* pesigmat_Eta = esigmat_Eta;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrack_eta1, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-4,4
   fitter_Gauss(h_mmOnTrackResidualTrack_eta2, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-3,3
   fitter_Gauss(h_mmOnTrackResidualTrack_eta3, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-3.2,3.3
   fitter_Gauss(h_mmOnTrackResidualTrack_eta4, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.8,1.8
   fitter_Gauss(h_mmOnTrackResidualTrack_eta5, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.75,1.75
   fitter_Gauss(h_mmOnTrackResidualTrack_eta6, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-2.7,2.7
   fitter_Gauss(h_mmOnTrackResidualTrack_eta7, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-3,3
   fitter_Gauss(h_mmOnTrackResidualTrack_eta8, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-2,2
   fitter_Gauss(h_mmOnTrackResidualTrack_eta9, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.9,1.9   
   fitter_Gauss(h_mmOnTrackResidualTrack_eta10, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.8,1.8   
   fitter_Gauss(h_mmOnTrackResidualTrack_eta11, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.7,1.7   
   fitter_Gauss(h_mmOnTrackResidualTrack_eta12, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.65,1.65   
   fitter_Gauss(h_mmOnTrackResidualTrack_eta13, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.25,1.25   
   fitter_Gauss(h_mmOnTrackResidualTrack_eta14, -0.3,0.3, psigma1_Eta_Gauss++, pesigma1_Eta_Gauss++);//-1.7,1.7

   //Crystal Ball Fit
   myfit2(h_mmOnTrackResidualTrack_eta1, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-2.5,2.5
   myfit2(h_mmOnTrackResidualTrack_eta2, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-2.2,2.2
   myfit2(h_mmOnTrackResidualTrack_eta3, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-4,4
   myfit2(h_mmOnTrackResidualTrack_eta4, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-2.2,2.2
   //myfit2(h_mmOnTrackResidualTrack_eta5, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-2,2
   //myfit2(h_mmOnTrackResidualTrack_eta6, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-5,5
   //myfit2(h_mmOnTrackResidualTrack_eta7, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-5,5
   myfit2_custom(h_mmOnTrackResidualTrack_eta5, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-2,2
   myfit2_custom(h_mmOnTrackResidualTrack_eta6, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-5,5
   myfit2_custom(h_mmOnTrackResidualTrack_eta7, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-5,5
   myfit2(h_mmOnTrackResidualTrack_eta8, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1.5,1.5
   myfit2(h_mmOnTrackResidualTrack_eta9, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1.5,1.5
   myfit2(h_mmOnTrackResidualTrack_eta10, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1,1
   myfit2(h_mmOnTrackResidualTrack_eta11, -0.15,0.15, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-4,4
   myfit2(h_mmOnTrackResidualTrack_eta12, -.12,.12, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1.3,1.3
   myfit2(h_mmOnTrackResidualTrack_eta13, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1.4,1.4
   myfit2(h_mmOnTrackResidualTrack_eta14, -0.1,0.1, psigma1_Eta_CB++, pesigma1_Eta_CB++);//-1.5,1.5

   //Double-Gauss Fit
   fitter5(h_mmOnTrackResidualTrack_eta1, -0.5,0.5, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-3.7,3.3
   fitter4(h_mmOnTrackResidualTrack_eta2, -0.5,0.5, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-2.2,2.2
   fitter4(h_mmOnTrackResidualTrack_eta3, -0.45,0.45, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-4,4
   fitter4(h_mmOnTrackResidualTrack_eta4, -0.42,0.42, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.5,1.5
   fitter3(h_mmOnTrackResidualTrack_eta5, -0.4,0.4, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.4,1.4
   fitter3(h_mmOnTrackResidualTrack_eta6, -0.42,0.42, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-5,5
   fitter3(h_mmOnTrackResidualTrack_eta7, -0.38,0.38, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.9,1.9
   fitter2(h_mmOnTrackResidualTrack_eta8, -0.3,0.3, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.5,1.5
   fitter2(h_mmOnTrackResidualTrack_eta9, -0.3,0.3, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.5,1.5   
   fitter2(h_mmOnTrackResidualTrack_eta10, -0.4,0.4, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1,1   
   fitter2(h_mmOnTrackResidualTrack_eta11, -0.4,0.4, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-4,4   
   fitter2(h_mmOnTrackResidualTrack_eta12, -0.48,0.48, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.3,1.3   
   fitter2(h_mmOnTrackResidualTrack_eta13, -0.5,0.5, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.4,1.4   
   fitter2(h_mmOnTrackResidualTrack_eta14, -0.42,0.42, psigma1_Eta++, psigma2_Eta++, psigmat_Eta++, pesigma1_Eta++, pesigma2_Eta++, pesigmat_Eta++);//-1.5,1.5


///Phi01
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi01_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi01_eta_eta_Gauss = sigma1_MS_Phi01_eta_eta_Gauss;
   Double_t esigma1_MS_Phi01_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi01_eta_eta_Gauss = esigma1_MS_Phi01_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi01_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi01_stereo_eta_Gauss = sigma1_MS_Phi01_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi01_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi01_stereo_eta_Gauss = esigma1_MS_Phi01_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta1, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta2, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta3, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta4, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta5, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta6, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta7, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta8, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta9, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta10, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta11, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta12, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta13, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi01_eta14, -0.3,0.3, psigma1_MS_Phi01_eta_eta_Gauss++, pesigma1_MS_Phi01_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta1, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta2, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta3, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta4, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta5, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta6, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta7, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta8, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta9, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta10, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta11, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta12, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta13, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi01_eta14, -0.3,0.3, psigma1_MS_Phi01_stereo_eta_Gauss++, pesigma1_MS_Phi01_stereo_eta_Gauss++);

///Phi02
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi02_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi02_eta_eta_Gauss = sigma1_MS_Phi02_eta_eta_Gauss;
   Double_t esigma1_MS_Phi02_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi02_eta_eta_Gauss = esigma1_MS_Phi02_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi02_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi02_stereo_eta_Gauss = sigma1_MS_Phi02_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi02_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi02_stereo_eta_Gauss = esigma1_MS_Phi02_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta1, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta2, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta3, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta4, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta5, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta6, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta7, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta8, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta9, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta10, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta11, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta12, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta13, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi02_eta14, -0.3,0.3, psigma1_MS_Phi02_eta_eta_Gauss++, pesigma1_MS_Phi02_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta1, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta2, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta3, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta4, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta5, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta6, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta7, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta8, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta9, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta10, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta11, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta12, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta13, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi02_eta14, -0.3,0.3, psigma1_MS_Phi02_stereo_eta_Gauss++, pesigma1_MS_Phi02_stereo_eta_Gauss++);

///Phi03
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi03_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi03_eta_eta_Gauss = sigma1_MS_Phi03_eta_eta_Gauss;
   Double_t esigma1_MS_Phi03_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi03_eta_eta_Gauss = esigma1_MS_Phi03_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi03_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi03_stereo_eta_Gauss = sigma1_MS_Phi03_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi03_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi03_stereo_eta_Gauss = esigma1_MS_Phi03_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta1, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta2, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta3, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta4, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta5, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta6, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta7, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta8, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta9, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta10, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta11, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta12, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta13, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi03_eta14, -0.3,0.3, psigma1_MS_Phi03_eta_eta_Gauss++, pesigma1_MS_Phi03_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta1, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta2, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta3, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta4, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta5, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta6, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta7, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta8, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta9, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta10, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta11, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta12, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta13, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi03_eta14, -0.3,0.3, psigma1_MS_Phi03_stereo_eta_Gauss++, pesigma1_MS_Phi03_stereo_eta_Gauss++);

///Phi04
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi04_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi04_eta_eta_Gauss = sigma1_MS_Phi04_eta_eta_Gauss;
   Double_t esigma1_MS_Phi04_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi04_eta_eta_Gauss = esigma1_MS_Phi04_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi04_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi04_stereo_eta_Gauss = sigma1_MS_Phi04_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi04_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi04_stereo_eta_Gauss = esigma1_MS_Phi04_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta1, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta2, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta3, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta4, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta5, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta6, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta7, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta8, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta9, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta10, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta11, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta12, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta13, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi04_eta14, -0.3,0.3, psigma1_MS_Phi04_eta_eta_Gauss++, pesigma1_MS_Phi04_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta1, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta2, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta3, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta4, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta5, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta6, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta7, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta8, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta9, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta10, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta11, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta12, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta13, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi04_eta14, -0.3,0.3, psigma1_MS_Phi04_stereo_eta_Gauss++, pesigma1_MS_Phi04_stereo_eta_Gauss++);

///Phi05
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi05_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi05_eta_eta_Gauss = sigma1_MS_Phi05_eta_eta_Gauss;
   Double_t esigma1_MS_Phi05_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi05_eta_eta_Gauss = esigma1_MS_Phi05_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi05_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi05_stereo_eta_Gauss = sigma1_MS_Phi05_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi05_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi05_stereo_eta_Gauss = esigma1_MS_Phi05_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta1, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta2, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta3, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta4, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta5, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta6, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta7, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta8, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta9, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta10, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta11, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta12, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta13, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi05_eta14, -0.3,0.3, psigma1_MS_Phi05_eta_eta_Gauss++, pesigma1_MS_Phi05_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta1, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta2, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta3, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta4, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta5, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta6, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta7, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta8, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta9, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta10, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta11, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta12, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta13, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi05_eta14, -0.3,0.3, psigma1_MS_Phi05_stereo_eta_Gauss++, pesigma1_MS_Phi05_stereo_eta_Gauss++);

///Phi06
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi06_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi06_eta_eta_Gauss = sigma1_MS_Phi06_eta_eta_Gauss;
   Double_t esigma1_MS_Phi06_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi06_eta_eta_Gauss = esigma1_MS_Phi06_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi06_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi06_stereo_eta_Gauss = sigma1_MS_Phi06_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi06_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi06_stereo_eta_Gauss = esigma1_MS_Phi06_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta1, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta2, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta3, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta4, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta5, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta6, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta7, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta8, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta9, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta10, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta11, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta12, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta13, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi06_eta14, -0.3,0.3, psigma1_MS_Phi06_eta_eta_Gauss++, pesigma1_MS_Phi06_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta1, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta2, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta3, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta4, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta5, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta6, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta7, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta8, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta9, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta10, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta11, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta12, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta13, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi06_eta14, -0.3,0.3, psigma1_MS_Phi06_stereo_eta_Gauss++, pesigma1_MS_Phi06_stereo_eta_Gauss++);

///Phi07
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi07_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi07_eta_eta_Gauss = sigma1_MS_Phi07_eta_eta_Gauss;
   Double_t esigma1_MS_Phi07_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi07_eta_eta_Gauss = esigma1_MS_Phi07_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi07_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi07_stereo_eta_Gauss = sigma1_MS_Phi07_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi07_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi07_stereo_eta_Gauss = esigma1_MS_Phi07_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta1, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta2, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta3, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta4, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta5, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta6, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta7, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta8, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta9, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta10, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta11, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta12, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta13, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi07_eta14, -0.3,0.3, psigma1_MS_Phi07_eta_eta_Gauss++, pesigma1_MS_Phi07_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta1, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta2, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta3, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta4, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta5, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta6, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta7, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta8, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta9, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta10, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta11, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta12, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta13, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi07_eta14, -0.3,0.3, psigma1_MS_Phi07_stereo_eta_Gauss++, pesigma1_MS_Phi07_stereo_eta_Gauss++);

///Phi08
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_Phi08_eta_eta_Gauss[14];
   Double_t* psigma1_MS_Phi08_eta_eta_Gauss = sigma1_MS_Phi08_eta_eta_Gauss;
   Double_t esigma1_MS_Phi08_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi08_eta_eta_Gauss = esigma1_MS_Phi08_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_Phi08_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_Phi08_stereo_eta_Gauss = sigma1_MS_Phi08_stereo_eta_Gauss;
   Double_t esigma1_MS_Phi08_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_Phi08_stereo_eta_Gauss = esigma1_MS_Phi08_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta1, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta2, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta3, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta4, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta5, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta6, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta7, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta8, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta9, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta10, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta11, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta12, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta13, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSPhi08_eta14, -0.3,0.3, psigma1_MS_Phi08_eta_eta_Gauss++, pesigma1_MS_Phi08_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta1, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta2, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta3, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta4, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta5, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta6, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta7, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta8, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta9, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta10, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta11, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta12, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta13, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSPhi08_eta14, -0.3,0.3, psigma1_MS_Phi08_stereo_eta_Gauss++, pesigma1_MS_Phi08_stereo_eta_Gauss++);

///Phi01
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi01_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi01_Eta_Gauss = sigma1_MS_Phi01_Eta_Gauss;
   Double_t esigma1_MS_Phi01_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi01_Eta_Gauss = esigma1_MS_Phi01_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta1, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta2, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta3, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta4, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta5, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta6, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta7, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta8, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta9, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta10, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta11, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta12, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta13, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi01_eta14, -0.3,0.3, psigma1_MS_Phi01_Eta_Gauss++, pesigma1_MS_Phi01_Eta_Gauss++);

///Phi02
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi02_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi02_Eta_Gauss = sigma1_MS_Phi02_Eta_Gauss;
   Double_t esigma1_MS_Phi02_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi02_Eta_Gauss = esigma1_MS_Phi02_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta1, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta2, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta3, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta4, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta5, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta6, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta7, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta8, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta9, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta10, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta11, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta12, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta13, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi02_eta14, -0.3,0.3, psigma1_MS_Phi02_Eta_Gauss++, pesigma1_MS_Phi02_Eta_Gauss++);

///Phi03
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi03_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi03_Eta_Gauss = sigma1_MS_Phi03_Eta_Gauss;
   Double_t esigma1_MS_Phi03_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi03_Eta_Gauss = esigma1_MS_Phi03_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta1, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta2, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta3, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta4, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta5, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta6, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta7, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta8, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta9, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta10, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta11, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta12, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta13, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi03_eta14, -0.3,0.3, psigma1_MS_Phi03_Eta_Gauss++, pesigma1_MS_Phi03_Eta_Gauss++);

///Phi04
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi04_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi04_Eta_Gauss = sigma1_MS_Phi04_Eta_Gauss;
   Double_t esigma1_MS_Phi04_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi04_Eta_Gauss = esigma1_MS_Phi04_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta1, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta2, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta3, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta4, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta5, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta6, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta7, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta8, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta9, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta10, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta11, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta12, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta13, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi04_eta14, -0.3,0.3, psigma1_MS_Phi04_Eta_Gauss++, pesigma1_MS_Phi04_Eta_Gauss++);

///Phi05
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi05_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi05_Eta_Gauss = sigma1_MS_Phi05_Eta_Gauss;
   Double_t esigma1_MS_Phi05_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi05_Eta_Gauss = esigma1_MS_Phi05_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta1, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta2, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta3, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta4, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta5, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta6, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta7, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta8, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta9, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta10, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta11, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta12, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta13, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi05_eta14, -0.3,0.3, psigma1_MS_Phi05_Eta_Gauss++, pesigma1_MS_Phi05_Eta_Gauss++);

///Phi06
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi06_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi06_Eta_Gauss = sigma1_MS_Phi06_Eta_Gauss;
   Double_t esigma1_MS_Phi06_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi06_Eta_Gauss = esigma1_MS_Phi06_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta1, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta2, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta3, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta4, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta5, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta6, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta7, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta8, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta9, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta10, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta11, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta12, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta13, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi06_eta14, -0.3,0.3, psigma1_MS_Phi06_Eta_Gauss++, pesigma1_MS_Phi06_Eta_Gauss++);

///Phi07
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi07_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi07_Eta_Gauss = sigma1_MS_Phi07_Eta_Gauss;
   Double_t esigma1_MS_Phi07_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi07_Eta_Gauss = esigma1_MS_Phi07_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta1, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta2, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta3, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta4, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta5, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta6, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta7, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta8, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta9, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta10, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta11, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta12, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta13, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi07_eta14, -0.3,0.3, psigma1_MS_Phi07_Eta_Gauss++, pesigma1_MS_Phi07_Eta_Gauss++);

///Phi08
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi08_Eta_Gauss[14];
   Double_t* psigma1_MS_Phi08_Eta_Gauss = sigma1_MS_Phi08_Eta_Gauss;
   Double_t esigma1_MS_Phi08_Eta_Gauss[14];
   Double_t* pesigma1_MS_Phi08_Eta_Gauss = esigma1_MS_Phi08_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta1, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta2, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta3, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta4, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta5, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta6, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta7, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta8, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta9, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta10, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta11, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta12, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta13, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSPhi08_eta14, -0.3,0.3, psigma1_MS_Phi08_Eta_Gauss++, pesigma1_MS_Phi08_Eta_Gauss++);

///Phi01
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_Phi01_eta_eta_Gauss[14];
   Double_t* psigma1_Phi01_eta_eta_Gauss = sigma1_Phi01_eta_eta_Gauss;
   Double_t esigma1_Phi01_eta_eta_Gauss[14];
   Double_t* pesigma1_Phi01_eta_eta_Gauss = esigma1_Phi01_eta_eta_Gauss;

   // For the Sigma1 for stereo strips
   Double_t sigma1_Phi01_stereo_eta_Gauss[14];
   Double_t* psigma1_Phi01_stereo_eta_Gauss = sigma1_Phi01_stereo_eta_Gauss;
   Double_t esigma1_Phi01_stereo_eta_Gauss[14];
   Double_t* pesigma1_Phi01_stereo_eta_Gauss = esigma1_Phi01_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta1, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta2, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta3, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta4, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta5, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta6, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta7, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta8, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta9, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta10, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta11, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta12, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta13, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackPhi01_eta14, -0.3,0.3, psigma1_Phi01_eta_eta_Gauss++, pesigma1_Phi01_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta1, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta2, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta3, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta4, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta5, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta6, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta7, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta8, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta9, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta10, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta11, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta12, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta13, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackPhi01_eta14, -0.3,0.3, psigma1_Phi01_stereo_eta_Gauss++, pesigma1_Phi01_stereo_eta_Gauss++);

///Phi01
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_Phi01_Eta_Gauss[14];
   Double_t* psigma1_Phi01_Eta_Gauss = sigma1_Phi01_Eta_Gauss;
   Double_t esigma1_Phi01_Eta_Gauss[14];
   Double_t* pesigma1_Phi01_Eta_Gauss = esigma1_Phi01_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta1, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta2, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta3, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta4, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta5, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta6, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta7, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta8, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta9, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta10, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta11, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta12, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta13, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackPhi01_eta14, -0.3,0.3, psigma1_Phi01_Eta_Gauss++, pesigma1_Phi01_Eta_Gauss++);

   /* // Define the number of strips, Phi values, and eta values
   const int numStrips = 14;
   const int numPhis = 8;
   const int numEtas = 14;

   // Define arrays to store the Sigma1 values
   Double_t sigma1_Phi_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_Phi_Gauss[numPhis][numEtas][numStrips];
   Double_t sigma1_MS_Phi_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_MS_Phi_Gauss[numPhis][numEtas][numStrips];
   Double_t sigma1_Phi_Eta_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_Phi_Eta_Gauss[numPhis][numEtas][numStrips];
   Double_t sigma1_MS_Phi_Eta_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_MS_Phi_Eta_Gauss[numPhis][numEtas][numStrips];
   Double_t sigma1_Phi_Stereo_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_Phi_Stereo_Gauss[numPhis][numEtas][numStrips];
   Double_t sigma1_MS_Phi_Stereo_Gauss[numPhis][numEtas][numStrips];
   Double_t esigma1_MS_Phi_Stereo_Gauss[numPhis][numEtas][numStrips];

   for (int phiIndex = 1; phiIndex <= numPhis; ++phiIndex) {
      for (int etaIndex = 1; etaIndex <= numEtas; ++etaIndex) {
         // Generate histogram names
         TString HistName = Form("h_mmOnTrackResidualTrackPhi%02d_eta%02d", phiIndex, etaIndex);
         TString etaHistName = Form("h_eta_mmOnTrackResidualTrackPhi%02d_eta%02d", phiIndex, etaIndex);
         TString stereoHistName = Form("h_stereo_mmOnTrackResidualTrackPhi%02d_eta%02d", phiIndex, etaIndex);
         TString MSHistName = Form("h_mmOnTrackResidualTrackMSPhi%02d_eta%02d", phiIndex, etaIndex);
         TString MSetaHistName = Form("h_eta_mmOnTrackResidualTrackMSPhi%02d_eta%02d", phiIndex, etaIndex);
         TString MSstereoHistName = Form("h_stereo_mmOnTrackResidualTrackMSPhi%02d_eta%02d", phiIndex, etaIndex);

         // Declare arrays and pointers for Sigma1 values
         Double_t sigma1_Phi_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_Phi_Gauss = sigma1_Phi_Gauss;
         Double_t esigma1_Phi_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_Phi_Gauss = esigma1_Phi_Gauss;
         Double_t sigma1_MS_Phi_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_MS_Phi_Gauss = sigma1_MS_Phi_Gauss;
         Double_t esigma1_MS_Phi_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_MS_Phi_Gauss = esigma1_MS_Phi_Gauss;
         Double_t sigma1_Phi_Eta_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_Phi_Eta_Gauss = sigma1_Phi_Eta_Gauss;
         Double_t esigma1_Phi_Eta_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_Phi_Eta_Gauss = esigma1_Phi_Eta_Gauss;
         Double_t sigma1_MS_Phi_Eta_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_MS_Phi_Eta_Gauss = sigma1_MS_Phi_Eta_Gauss;
         Double_t esigma1_MS_Phi_Eta_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_MS_Phi_Eta_Gauss = esigma1_MS_Phi_Eta_Gauss;
         Double_t sigma1_Phi_Stereo_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_Phi_Stereo_Gauss = sigma1_Phi_Stereo_Gauss;
         Double_t esigma1_Phi_Stereo_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_Phi_Stereo_Gauss = esigma1_Phi_Stereo_Gauss;
         Double_t sigma1_MS_Phi_Stereo_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* psigma1_MS_Phi_Stereo_Gauss = sigma1_MS_Phi_Stereo_Gauss;
         Double_t esigma1_MS_Phi_Stereo_Gauss[phiIndex-1][etaIndex-1][numStrips];
         Double_t* pesigma1_MS_Phi_Stereo_Gauss = esigma1_MS_Phi_Stereo_Gauss;

         // Fill the arrays with the Sigma1 values using histogram names
         fitter_Gauss(HistName, -0.3, 0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
         fitter_Gauss(stereoHistName, -0.3, 0.3, psigma1_Phi_Stereo_Gauss++, pesigma1_Phi_Stereo_Gauss++);
         fitter_Gauss(etaHistName, -0.3, 0.3, psigma1_Phi_Eta_Gauss++, pesigma1_Phi_Eta_Gauss++);
         fitter_Gauss(MSHistName, -0.3, 0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
         fitter_Gauss(MSstereoHistName, -0.3, 0.3, psigma1_MS_Phi_Stereo_Gauss++, pesigma1_MS_Phi_Stereo_Gauss++);
         fitter_Gauss(MSetaHistName, -0.3, 0.3, psigma1_MS_Phi_Eta_Gauss++, pesigma1_MS_Phi_Eta_Gauss++);
      }
   } */

///LargeSector
   // The arrays below will be filled with the MS Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_LargeSector_eta_eta_Gauss[14];
   Double_t* psigma1_MS_LargeSector_eta_eta_Gauss = sigma1_MS_LargeSector_eta_eta_Gauss;
   Double_t esigma1_MS_LargeSector_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_LargeSector_eta_eta_Gauss = esigma1_MS_LargeSector_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_LargeSector_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_LargeSector_stereo_eta_Gauss = sigma1_MS_LargeSector_stereo_eta_Gauss;
   Double_t esigma1_MS_LargeSector_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_LargeSector_stereo_eta_Gauss = esigma1_MS_LargeSector_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta1, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta2, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta3, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta4, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta5, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta6, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta7, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta8, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta9, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta10, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta11, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta12, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta13, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSLargeSector_eta14, -0.3,0.3, psigma1_MS_LargeSector_eta_eta_Gauss++, pesigma1_MS_LargeSector_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14, -0.3,0.3, psigma1_MS_LargeSector_stereo_eta_Gauss++, pesigma1_MS_LargeSector_stereo_eta_Gauss++);

///LargeSector
   // The arrays below will be filled with the MS Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_LargeSector_Eta_Gauss[14];
   Double_t* psigma1_MS_LargeSector_Eta_Gauss = sigma1_MS_LargeSector_Eta_Gauss;
   Double_t esigma1_MS_LargeSector_Eta_Gauss[14];
   Double_t* pesigma1_MS_LargeSector_Eta_Gauss = esigma1_MS_LargeSector_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta1, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta2, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta3, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta4, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta5, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta6, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta7, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta8, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta9, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta10, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta11, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta12, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta13, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSLargeSector_eta14, -0.3,0.3, psigma1_MS_LargeSector_Eta_Gauss++, pesigma1_MS_LargeSector_Eta_Gauss++);


///LargeSector
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_LargeSector_eta_eta_Gauss[14];
   Double_t* psigma1_LargeSector_eta_eta_Gauss = sigma1_LargeSector_eta_eta_Gauss;
   Double_t esigma1_LargeSector_eta_eta_Gauss[14];
   Double_t* pesigma1_LargeSector_eta_eta_Gauss = esigma1_LargeSector_eta_eta_Gauss;

   // For the Sigma1 for stereo strips
   Double_t sigma1_LargeSector_stereo_eta_Gauss[14];
   Double_t* psigma1_LargeSector_stereo_eta_Gauss = sigma1_LargeSector_stereo_eta_Gauss;
   Double_t esigma1_LargeSector_stereo_eta_Gauss[14];
   Double_t* pesigma1_LargeSector_stereo_eta_Gauss = esigma1_LargeSector_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta1, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta2, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta3, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta4, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta5, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta6, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta7, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta8, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta9, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta10, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta11, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta12, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta13, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackLargeSector_eta14, -0.3,0.3, psigma1_LargeSector_eta_eta_Gauss++, pesigma1_LargeSector_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta1, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta2, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta3, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta4, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta5, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta6, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta7, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta8, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta9, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta10, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta11, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta12, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta13, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackLargeSector_eta14, -0.3,0.3, psigma1_LargeSector_stereo_eta_Gauss++, pesigma1_LargeSector_stereo_eta_Gauss++);

///LargeSector
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_LargeSector_Eta_Gauss[14];
   Double_t* psigma1_LargeSector_Eta_Gauss = sigma1_LargeSector_Eta_Gauss;
   Double_t esigma1_LargeSector_Eta_Gauss[14];
   Double_t* pesigma1_LargeSector_Eta_Gauss = esigma1_LargeSector_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta1, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta2, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta3, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta4, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta5, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta6, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta7, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta8, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta9, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta10, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta11, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta12, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta13, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackLargeSector_eta14, -0.3,0.3, psigma1_LargeSector_Eta_Gauss++, pesigma1_LargeSector_Eta_Gauss++);

///SmallSector
   // The arrays below will be filled with the MS Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_SmallSector_eta_eta_Gauss[14];
   Double_t* psigma1_MS_SmallSector_eta_eta_Gauss = sigma1_MS_SmallSector_eta_eta_Gauss;
   Double_t esigma1_MS_SmallSector_eta_eta_Gauss[14];
   Double_t* pesigma1_MS_SmallSector_eta_eta_Gauss = esigma1_MS_SmallSector_eta_eta_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_SmallSector_stereo_eta_Gauss[14];
   Double_t* psigma1_MS_SmallSector_stereo_eta_Gauss = sigma1_MS_SmallSector_stereo_eta_Gauss;
   Double_t esigma1_MS_SmallSector_stereo_eta_Gauss[14];
   Double_t* pesigma1_MS_SmallSector_stereo_eta_Gauss = esigma1_MS_SmallSector_stereo_eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta1, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta2, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta3, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta4, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta5, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta6, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta7, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta8, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta9, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta10, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta11, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta12, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta13, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMSSmallSector_eta14, -0.3,0.3, psigma1_MS_SmallSector_eta_eta_Gauss++, pesigma1_MS_SmallSector_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14, -0.3,0.3, psigma1_MS_SmallSector_stereo_eta_Gauss++, pesigma1_MS_SmallSector_stereo_eta_Gauss++);

///SmallSector
   // The arrays below will be filled with the MS Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_SmallSector_Eta_Gauss[14];
   Double_t* psigma1_MS_SmallSector_Eta_Gauss = sigma1_MS_SmallSector_Eta_Gauss;
   Double_t esigma1_MS_SmallSector_Eta_Gauss[14];
   Double_t* pesigma1_MS_SmallSector_Eta_Gauss = esigma1_MS_SmallSector_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta1, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta2, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta3, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta4, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta5, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta6, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta7, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta8, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta9, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta10, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta11, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta12, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta13, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMSSmallSector_eta14, -0.3,0.3, psigma1_MS_SmallSector_Eta_Gauss++, pesigma1_MS_SmallSector_Eta_Gauss++);


///SmallSector
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_SmallSector_eta_eta_Gauss[14];
   Double_t* psigma1_SmallSector_eta_eta_Gauss = sigma1_SmallSector_eta_eta_Gauss;
   Double_t esigma1_SmallSector_eta_eta_Gauss[14];
   Double_t* pesigma1_SmallSector_eta_eta_Gauss = esigma1_SmallSector_eta_eta_Gauss;

   // For the Sigma1 for stereo strips
   Double_t sigma1_SmallSector_stereo_eta_Gauss[14];
   Double_t* psigma1_SmallSector_stereo_eta_Gauss = sigma1_SmallSector_stereo_eta_Gauss;
   Double_t esigma1_SmallSector_stereo_eta_Gauss[14];
   Double_t* pesigma1_SmallSector_stereo_eta_Gauss = esigma1_SmallSector_stereo_eta_Gauss;

/*    //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta1, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta2, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta3, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta4, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta5, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta6, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta7, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta8, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta9, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta10, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta11, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta12, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta13, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackSmallSector_eta14, -0.3,0.3, psigma1_SmallSector_eta_eta_Gauss++, pesigma1_SmallSector_eta_eta_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta1, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta2, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta3, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta4, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta5, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta6, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta7, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta8, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta9, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta10, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta11, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta12, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta13, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackSmallSector_eta14, -0.3,0.3, psigma1_SmallSector_stereo_eta_Gauss++, pesigma1_SmallSector_stereo_eta_Gauss++);
 */
///SmallSector
   // The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_SmallSector_Eta_Gauss[14];
   Double_t* psigma1_SmallSector_Eta_Gauss = sigma1_SmallSector_Eta_Gauss;
   Double_t esigma1_SmallSector_Eta_Gauss[14];
   Double_t* pesigma1_SmallSector_Eta_Gauss = esigma1_SmallSector_Eta_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta1, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta2, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta3, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta4, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta5, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta6, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta7, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta8, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta9, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta10, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta11, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta12, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta13, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackSmallSector_eta14, -0.3,0.3, psigma1_SmallSector_Eta_Gauss++, pesigma1_SmallSector_Eta_Gauss++);

//////////////////////////////////////////////////////////////////////////////////////////////////////////// sigma per pos
//12

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_pos12pcb[8];
   Double_t* psigma1_pos12pcb = sigma1_pos12pcb;
   Double_t esigma1_pos12pcb[8];
   Double_t* pesigma1_pos12pcb = esigma1_pos12pcb;

   // For the Sigma1 for strips
   Double_t sigma1_pos12pcb_CB[8];
   Double_t* psigma1_pos12pcb_CB = sigma1_pos12pcb_CB;
   Double_t esigma1_pos12pcb_CB[8];
   Double_t* pesigma1_pos12pcb_CB = esigma1_pos12pcb_CB;

   // For the Sigma1 for strips
   Double_t sigma1_pos12pcb_Gauss[8];
   Double_t* psigma1_pos12pcb_Gauss = sigma1_pos12pcb_Gauss;
   Double_t esigma1_pos12pcb_Gauss[8];
   Double_t* pesigma1_pos12pcb_Gauss = esigma1_pos12pcb_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_pos12pcb[8];
   Double_t* psigma2_pos12pcb = sigma2_pos12pcb;
   Double_t esigma2_pos12pcb[8];
   Double_t* pesigma2_pos12pcb = esigma2_pos12pcb;

   // For the Combined Sigma for strips
   Double_t sigmat_pos12pcb[8];
   Double_t* psigmat_pos12pcb = sigmat_pos12pcb;
   Double_t esigmat_pos12pcb[8];
   Double_t* pesigmat_pos12pcb = esigmat_pos12pcb;

   //Gauss Fit
   fitter_Gauss(h_x12_qpcb08, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb07, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb06, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb05, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb04, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb03, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb02, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);
   fitter_Gauss(h_x12_qpcb01, -0.2,0.2, psigma1_pos12pcb_Gauss++, pesigma1_pos12pcb_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_x12_qpcb08, -.15,.15, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-0.5,0.6
   myfit2(h_x12_qpcb07, -.15,.15, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-0.5,0.5 || -0.9,0.9
   myfit2(h_x12_qpcb06, -.1,.1, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-2,2
   myfit(h_x12_qpcb05, -.2,.2, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-0.4,0.5
   myfit(h_x12_qpcb04, -.2,.2, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-2,1.5
   myfit(h_x12_qpcb03, -.15,.15, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-2.2,2
   myfit(h_x12_qpcb02, -.2,.3, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-2,1.6
   myfit(h_x12_qpcb01, -.2,.2, psigma1_pos12pcb_CB++, pesigma1_pos12pcb_CB++);//-2.2,2.2 */

   /* //Double-Gauss Fit
   fitter(h_x12_qpcb08, -.1,.1, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-1.5,1.5 || -10,10
   fitter(h_x12_qpcb07, -.15,.15, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-1.5,1.5 || -7,7
   fitter(h_x12_qpcb06, -.2,.2, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-1.1,1.1 || -5,5
   fitter(h_x12_qpcb05, -.2,.2, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-1.4,1.4
   fitter(h_x12_qpcb04, -.4,.5, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-2,2
   fitter2(h_x12_qpcb03, -.3,.3, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-2,2
   fitter2(h_x12_qpcb02, -.4,.4, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-2.3,2.3
   fitter2(h_x12_qpcb01, -.5,.5, psigma1_pos12pcb++, psigma2_pos12pcb++, psigmat_pos12pcb++, pesigma1_pos12pcb++, pesigma2_pos12pcb++, pesigmat_pos12pcb++);//-2.6,2.6
 */
// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta[14];
   Double_t* psigma1_pos12eta = sigma1_pos12eta;
   Double_t esigma1_pos12eta[14];
   Double_t* pesigma1_pos12eta = esigma1_pos12eta;

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta_CB[14];
   Double_t* psigma1_pos12eta_CB = sigma1_pos12eta_CB;
   Double_t esigma1_pos12eta_CB[14];
   Double_t* pesigma1_pos12eta_CB = esigma1_pos12eta_CB;

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta_Gauss[14];
   Double_t* psigma1_pos12eta_Gauss = sigma1_pos12eta_Gauss;
   Double_t esigma1_pos12eta_Gauss[14];
   Double_t* pesigma1_pos12eta_Gauss = esigma1_pos12eta_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_pos12eta[14];
   Double_t* psigma2_pos12eta = sigma2_pos12eta;
   Double_t esigma2_pos12eta[14];
   Double_t* pesigma2_pos12eta = esigma2_pos12eta;

   // For the Combined Sigma for strips
   Double_t sigmat_pos12eta[14];
   Double_t* psigmat_pos12eta = sigmat_pos12eta;
   Double_t esigmat_pos12eta[14];
   Double_t* pesigmat_pos12eta = esigmat_pos12eta;

   //Gauss Fit
   fitter_Gauss(h_x12_eta01, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta02, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta03, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta04, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta05, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta06, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta07, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta08, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta09, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta10, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta11, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta12, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta13, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);
   fitter_Gauss(h_x12_eta14, -0.3,0.3, psigma1_pos12eta_Gauss++, pesigma1_pos12eta_Gauss++);

   /* //Crystal Ball Fit
   myfit(h_x12_eta01, -0.5,0.5, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-2,2.4
   myfit(h_x12_eta02, -0.1,0.1, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-1.9,1.9
   myfit(h_x12_eta03, -0.1,0.1, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-2,2
   myfit(h_x12_eta04, -0.4,0.4, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-2.4,2.2
   myfit(h_x12_eta05, -0.1,0.1, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-2,1
   myfit(h_x12_eta06, -0.4,0.4, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-1.8,1.8
   myfit(h_x12_eta07, -0.35,0.35, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-1,0.7
   myfit(h_x12_eta08, -0.28,0.28, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-0.5,0.6
   myfit(h_x12_eta09, -0.25,0.25, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-0.4,0.4
   myfit(h_x12_eta10, -0.25,0.25, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-0.4,0.5
   myfit(h_x12_eta11, -0.25,0.25, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-0.8,0.85
   myfit(h_x12_eta12, -0.15,0.15, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-0.7,0.7
   myfit(h_x12_eta13, -0.25,0.25, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-1.1,1.1
   myfit(h_x12_eta14, -0.25,0.25, psigma1_pos12eta_CB++, pesigma1_pos12eta_CB++);//-2,3 */

   /* //Double-Gauss Fit
   fitter(h_x12_eta01, -0.5,0.5, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-3,3
   fitter(h_x12_eta02, -0.5,0.5, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-4,4
   fitter(h_x12_eta03, -0.5,0.5, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-2.4,2.4
   fitter(h_x12_eta04, -0.5,0.5, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-2.3,2
   fitter(h_x12_eta05, -0.5,0.5, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-2.1,2.1
   fitter(h_x12_eta06, -0.48,0.48, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-2,2
   fitter2(h_x12_eta07, -0.42,0.42, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.8,1.8
   fitter2(h_x12_eta08, -0.48,0.48, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.7,1.7
   fitter2(h_x12_eta09, -0.38,0.38, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.5,1.5
   fitter2(h_x12_eta10, -0.4,0.4, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.2,1.2
   fitter2(h_x12_eta11, -0.32,0.32, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.2,1.2
   fitter2(h_x12_eta12, -0.3,0.3, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-1.2,1.2
   fitter2(h_x12_eta13, -0.24,0.24, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-0.5,0.55
   fitter2(h_x12_eta14, -0.2,0.2, psigma1_pos12eta++, psigma2_pos12eta++, psigmat_pos12eta++, pesigma1_pos12eta++, pesigma2_pos12eta++, pesigmat_pos12eta++);//-0.3,0.31
 */
// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta_short[7];
   Double_t* psigma1_pos12eta_short = sigma1_pos12eta_short;
   Double_t esigma1_pos12eta_short[7];
   Double_t* pesigma1_pos12eta_short = esigma1_pos12eta_short;

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta_short_CB[7];
   Double_t* psigma1_pos12eta_short_CB = sigma1_pos12eta_CB;
   Double_t esigma1_pos12eta_short_CB[7];
   Double_t* pesigma1_pos12eta_short_CB = esigma1_pos12eta_short_CB;

   // For the Sigma1 for strips
   Double_t sigma1_pos12eta_short_Gauss[7];
   Double_t* psigma1_pos12eta_short_Gauss = sigma1_pos12eta_short_Gauss;
   Double_t esigma1_pos12eta_short_Gauss[7];
   Double_t* pesigma1_pos12eta_short_Gauss = esigma1_pos12eta_short_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_pos12eta_short[7];
   Double_t* psigma2_pos12eta_short = sigma2_pos12eta_short;
   Double_t esigma2_pos12eta_short[7];
   Double_t* pesigma2_pos12eta_short = esigma2_pos12eta_short;

   // For the Combined Sigma for strips
   Double_t sigmat_pos12eta_short[7];
   Double_t* psigmat_pos12eta_short = sigmat_pos12eta_short;
   Double_t esigmat_pos12eta_short[7];
   Double_t* pesigmat_pos12eta_short = esigmat_pos12eta_short;

   //Gauss Fit
   fitter_Gauss(h_x12_eta1, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta2, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta3, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta4, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta5, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta6, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);
   fitter_Gauss(h_x12_eta7, -0.3,0.3, psigma1_pos12eta_short_Gauss++, pesigma1_pos12eta_short_Gauss++);

   /* //Crystal Ball Fit
   myfit(h_x12_eta1, -0.5,0.5, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-2,2.4
   myfit(h_x12_eta2, -0.1,0.1, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-1.9,1.9
   myfit(h_x12_eta3, -0.1,0.1, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-2,2
   myfit(h_x12_eta4, -0.4,0.4, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-2.4,2.2
   myfit(h_x12_eta5, -0.1,0.1, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-2,1
   myfit(h_x12_eta6, -0.4,0.4, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-1.8,1.8
   myfit(h_x12_eta7, -0.35,0.35, psigma1_pos12eta_short_CB++, pesigma1_pos12eta_short_CB++);//-1,0.7 */

   /* //Double-Gauss Fit
   fitter(h_x12_eta1, -0.5,0.5, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-3,3
   fitter(h_x12_eta2, -0.5,0.5, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-4,4
   fitter(h_x12_eta3, -0.5,0.5, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-2.4,2.4
   fitter(h_x12_eta4, -0.5,0.5, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-2.3,2
   fitter(h_x12_eta5, -0.5,0.5, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-2.1,2.1
   fitter(h_x12_eta6, -0.48,0.48, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-2,2
   fitter2(h_x12_eta7, -0.42,0.42, psigma1_pos12eta_short++, psigma2_pos12eta_short++, psigmat_pos12eta_short++, pesigma1_pos12eta_short++, pesigma2_pos12eta_short++, pesigmat_pos12eta_short++);//-1.8,1.8
 */
//ALL
/* 
// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_pos[6];
   Double_t* psigma1_MS_pos = sigma1_MS_pos;
   Double_t esigma1_MS_pos[6];
   Double_t* pesigma1_MS_pos = esigma1_MS_pos;

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_pos_CB[6];
   Double_t* psigma1_MS_pos_CB = sigma1_MS_pos_CB;
   Double_t esigma1_MS_pos_CB[6];
   Double_t* pesigma1_MS_pos_CB = esigma1_MS_pos_CB;

   // For the Sigma2 for MS strips
   Double_t sigma2_MS_pos[6];
   Double_t* psigma2_MS_pos = sigma2_MS_pos;
   Double_t esigma2_MS_pos[6];
   Double_t* pesigma2_MS_pos = esigma2_MS_pos;

   // For the Combined Sigma for MS strips
   Double_t sigmat_MS_pos[6];
   Double_t* psigmat_MS_pos = sigmat_MS_pos;
   Double_t esigmat_MS_pos[6];
   Double_t* pesigmat_MS_pos = esigmat_MS_pos;


   //Crystal Ball Fit
   myfit2(h_x12R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-0.5,0.6
   myfit2(h_x121R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-0.5,0.5 || -0.9,0.9
   myfit2(h_x341R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-2,2
   myfit2(h_x122R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-0.4,0.5
   myfit2(h_x342R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-2,1.5
   myfit2(h_x34R_MS, -0.1,0.1, psigma1_MS_pos_CB++, pesigma1_MS_pos_CB++);//-2.2,2 
   
   //Double-Gauss Fit
   //h_x12R_MS->Rebin(2);
   fitter(h_x12R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-1.5,1.5 || -10,10
   //h_x121R_MS->Rebin(3);
   fitter(h_x121R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-1.5,1.5 || -7,7
   //h_x341R_MS->Rebin(3);
   fitter(h_x341R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-1.1,1.1 || -5,5
   //h_x122R_MS->Rebin(3);
   fitter(h_x122R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-1.4,1.4
   //h_x342R_MS->Rebin(4);
   fitter(h_x342R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-2,2
   //h_x34R_MS->Rebin(2);
   fitter2(h_x34R_MS, -0.1,0.1, psigma1_MS_pos++, psigma2_MS_pos++, psigmat_MS_pos++, pesigma1_MS_pos++, pesigma2_MS_pos++, pesigmat_MS_pos++);//-2,2
 */

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_pos[6];
   Double_t* psigma1_pos = sigma1_pos;
   Double_t esigma1_pos[6];
   Double_t* pesigma1_pos = esigma1_pos;

   // For the Sigma1 for strips
   Double_t sigma1_pos_CB[6];
   Double_t* psigma1_pos_CB = sigma1_pos_CB;
   Double_t esigma1_pos_CB[6];
   Double_t* pesigma1_pos_CB = esigma1_pos_CB;

   // For the Sigma1 for MS strips
   Double_t sigma1_pos_Gauss[6];
   Double_t* psigma1_pos_Gauss = sigma1_pos_Gauss;
   Double_t esigma1_pos_Gauss[6];
   Double_t* pesigma1_pos_Gauss = esigma1_pos_Gauss;

   // For the Sigma2 for strips
   Double_t sigma2_pos[6];
   Double_t* psigma2_pos = sigma2_pos;
   Double_t esigma2_pos[6];
   Double_t* pesigma2_pos = esigma2_pos;

   // For the Combined Sigma for strips
   Double_t sigmat_pos[6];
   Double_t* psigmat_pos = sigmat_pos;
   Double_t esigmat_pos[6];
   Double_t* pesigmat_pos = esigmat_pos;

   //Gauss Fit
   fitter_Gauss(h_x12R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);
   fitter_Gauss(h_x121R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);
   fitter_Gauss(h_x341R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);
   fitter_Gauss(h_x122R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);
   fitter_Gauss(h_x342R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);
   fitter_Gauss(h_x34R, -0.3,0.3, psigma1_pos_Gauss++, pesigma1_pos_Gauss++);

   /* //Crystal Ball Fit
   myfit2(h_x12R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-0.5,0.6
   myfit2(h_x121R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-0.5,0.5 || -0.9,0.9
   myfit2(h_x341R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-2,2
   myfit2(h_x122R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-0.4,0.5
   myfit2(h_x342R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-2,1.5
   myfit2(h_x34R, -0.1,0.1, psigma1_pos_CB++, pesigma1_pos_CB++);//-2.2,2 */
   
   /* //Double-Gauss Fit
   fitter(h_x12R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-1.5,1.5 || -10,10
   fitter(h_x121R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-1.5,1.5 || -7,7
   fitter(h_x341R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-1.1,1.1 || -5,5
   fitter(h_x122R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-1.4,1.4
   fitter(h_x342R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-2,2
   fitter2(h_x34R, -0.1,0.1, psigma1_pos++, psigma2_pos++, psigmat_pos++, pesigma1_pos++, pesigma2_pos++, pesigmat_pos++);//-2,2
 */
/////////////////////////////////////////////////////////////////////////////////////////// sigma per phi

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS eta strips
   Double_t sigma1_MS_eta_Phi_Gauss[8];
   Double_t* psigma1_MS_eta_Phi_Gauss = sigma1_MS_eta_Phi_Gauss;
   Double_t esigma1_MS_eta_Phi_Gauss[8];
   Double_t* pesigma1_MS_eta_Phi_Gauss = esigma1_MS_eta_Phi_Gauss;

   // For the Sigma1 for MS stereo strips
   Double_t sigma1_MS_stereo_Phi_Gauss[8];
   Double_t* psigma1_MS_stereo_Phi_Gauss = sigma1_MS_stereo_Phi_Gauss;
   Double_t esigma1_MS_stereo_Phi_Gauss[8];
   Double_t* pesigma1_MS_stereo_Phi_Gauss = esigma1_MS_stereo_Phi_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi1, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi2, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi3, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi4, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi5, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi6, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi7, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrackMS_phi8, -0.3,0.3, psigma1_MS_eta_Phi_Gauss++, pesigma1_MS_eta_Phi_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi1, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi2, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi3, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi4, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi5, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi6, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi7, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrackMS_phi8, -0.3,0.3, psigma1_MS_stereo_Phi_Gauss++, pesigma1_MS_stereo_Phi_Gauss++);

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for MS strips
   Double_t sigma1_MS_Phi_Gauss[8];
   Double_t* psigma1_MS_Phi_Gauss = sigma1_MS_Phi_Gauss;
   Double_t esigma1_MS_Phi_Gauss[8];
   Double_t* pesigma1_MS_Phi_Gauss = esigma1_MS_Phi_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi1, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi2, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi3, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi4, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi5, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi6, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi7, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrackMS_phi8, -0.3,0.3, psigma1_MS_Phi_Gauss++, pesigma1_MS_Phi_Gauss++);

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for eta strips
   Double_t sigma1_eta_Phi_Gauss[8];
   Double_t* psigma1_eta_Phi_Gauss = sigma1_eta_Phi_Gauss;
   Double_t esigma1_eta_Phi_Gauss[8];
   Double_t* pesigma1_eta_Phi_Gauss = esigma1_eta_Phi_Gauss;

   // For the Sigma1 for stereo strips
   Double_t sigma1_stereo_Phi_Gauss[8];
   Double_t* psigma1_stereo_Phi_Gauss = sigma1_stereo_Phi_Gauss;
   Double_t esigma1_stereo_Phi_Gauss[8];
   Double_t* pesigma1_stereo_Phi_Gauss = esigma1_stereo_Phi_Gauss;

   //Gauss Fit
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi1, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi2, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi3, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi4, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi5, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi6, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi7, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);
   fitter_Gauss(h_eta_mmOnTrackResidualTrack_phi8, -0.3,0.3, psigma1_eta_Phi_Gauss++, pesigma1_eta_Phi_Gauss++);

   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi1, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi2, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi3, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi4, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi5, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi6, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi7, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);
   fitter_Gauss(h_stereo_mmOnTrackResidualTrack_phi8, -0.3,0.3, psigma1_stereo_Phi_Gauss++, pesigma1_stereo_Phi_Gauss++);

// The arrays below will be filled with the Sigma values 

   // For the Sigma1 for strips
   Double_t sigma1_Phi_Gauss[8];
   Double_t* psigma1_Phi_Gauss = sigma1_Phi_Gauss;
   Double_t esigma1_Phi_Gauss[8];
   Double_t* pesigma1_Phi_Gauss = esigma1_Phi_Gauss;

   //Gauss Fit
   fitter_Gauss(h_mmOnTrackResidualTrack_phi1, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi2, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi3, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi4, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi5, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi6, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi7, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);
   fitter_Gauss(h_mmOnTrackResidualTrack_phi8, -0.3,0.3, psigma1_Phi_Gauss++, pesigma1_Phi_Gauss++);

////////////////////////////////////////////////////// Plotting /////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////Canvas #1
    TLegend *leg = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c1 = new TCanvas("c1", "Sigma per PCB MS", 800, 600);
    //c1->Divide(2,4);// will contain multiple graphs

    double_t PCB[8]={1,2,3,4,5,6,7,8};

    /* TGraphErrors *Sigma1_MS_eta_Gauss = new TGraphErrors(8,PCB,sigma1_MS_eta_Gauss,0,esigma1_MS_eta_Gauss);//eta
    Sigma1_MS_eta_Gauss->SetTitle("Sigma per PCB MS");
    Sigma1_MS_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_eta_Gauss->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_Gauss = new TGraphErrors(8,PCB,sigma1_MS_stereo_Gauss,0,esigma1_MS_stereo_Gauss);//stereo
    Sigma1_MS_stereo_Gauss->SetTitle("Sigma per PCB MS");
    Sigma1_MS_stereo_Gauss->SetMarkerStyle(22);
    Sigma1_MS_stereo_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_stereo_Gauss->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_stereo_Gauss, "Stereo Strips Gauss", "p"); */

    TGraphErrors *Sigma1_MS_eta_CB = new TGraphErrors(8,PCB,sigma1_MS_eta_CB,0,esigma1_MS_eta_CB);//eta
    Sigma1_MS_eta_CB->SetTitle("Sigma per PCB MS");
    Sigma1_MS_eta_CB->SetMarkerStyle(21);
    Sigma1_MS_eta_CB->SetMarkerColor(kViolet);
    Sigma1_MS_eta_CB->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_eta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_MS_stereo_CB = new TGraphErrors(8,PCB,sigma1_MS_stereo_CB,0,esigma1_MS_stereo_CB);//stereo
    Sigma1_MS_stereo_CB->SetTitle("Sigma per PCB MS");
    Sigma1_MS_stereo_CB->SetMarkerStyle(21);
    Sigma1_MS_stereo_CB->SetMarkerColor(kGreen);
    Sigma1_MS_stereo_CB->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_stereo_CB, "Stereo Strips Crystal Ball", "p");

    /* TGraphErrors *Sigma1_MS_eta = new TGraphErrors(8,PCB,sigma1_MS_eta,0,esigma1_MS_eta);//eta
    Sigma1_MS_eta->SetTitle("Sigma per PCB MS");
    Sigma1_MS_eta->SetMarkerStyle(20);
    Sigma1_MS_eta->SetMarkerColor(kRed);
    Sigma1_MS_eta->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_eta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo = new TGraphErrors(8,PCB,sigma1_MS_stereo,0,esigma1_MS_stereo);//stereo
    Sigma1_MS_stereo->SetTitle("Sigma per PCB MS");
    Sigma1_MS_stereo->SetMarkerStyle(20);
    Sigma1_MS_stereo->SetMarkerColor(kBlue);
    Sigma1_MS_stereo->SetMarkerSize(1.5);
    leg->AddEntry(Sigma1_MS_stereo, "Stereo Strips Double Gauss", "p"); */

    /* Sigma1_MS_stereo_Gauss->Draw("APSAME");
    Sigma1_MS_eta_Gauss->Draw("PSAME"); */
    Sigma1_MS_stereo_CB->Draw("APSAME");
    Sigma1_MS_eta_CB->Draw("PSAME");
    /* Sigma1_MS_stereo->Draw("APSAME");
    Sigma1_MS_eta->Draw("PSAME"); */
    leg->Draw();
    

    // Set the axis titles
    Sigma1_MS_eta_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_stereo_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_CB->GetYaxis()->SetTitle("Resolution (mm)");
    /* Sigma1_MS_eta->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_stereo->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS_eta_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_stereo_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_Gauss->GetYaxis()->SetTitle("Resolution (mm)"); */
    gPad->SetTickx();
    gPad->SetTicky();

    TLatex t1;
    t1.DrawLatex(4,.5, "ATLAS Simulated Data");
    c1->Update();
///////////////////////////////////////////////////////Canvas #101
    TLegend *leg101 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c101 = new TCanvas("c101", "Sigma per PCB MS", 800, 600);

    /* TGraphErrors *Sigma1_MS_Gauss = new TGraphErrors(8,PCB,sigma1_MS_Gauss,0,esigma1_MS_Gauss);
    Sigma1_MS_Gauss->SetTitle("Sigma per PCB MS");
    Sigma1_MS_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Gauss->SetMarkerSize(1.5);
    leg101->AddEntry(Sigma1_MS_Gauss, "Gauss", "p"); */

    TGraphErrors *Sigma1_MS_CB = new TGraphErrors(8,PCB,sigma1_MS_CB,0,esigma1_MS_CB);
    Sigma1_MS_CB->SetTitle("Sigma per PCB MS");
    Sigma1_MS_CB->SetMarkerStyle(21);
    Sigma1_MS_CB->SetMarkerColor(kViolet);
    Sigma1_MS_CB->SetMarkerSize(1.5);
    leg101->AddEntry(Sigma1_MS_CB, "Crystal Ball", "p");

    /* TGraphErrors *Sigma1_MS = new TGraphErrors(8,PCB,sigma1_MS,0,esigma1_MS);
    Sigma1_MS->SetTitle("Sigma per PCB MS");
    Sigma1_MS->SetMarkerStyle(20);
    Sigma1_MS->SetMarkerColor(kRed);
    Sigma1_MS->SetMarkerSize(1.5);
    leg101->AddEntry(Sigma1_MS, "Double Gauss", "p"); */
    
    //Sigma1_MS_Gauss->Draw("APSAME");
    Sigma1_MS_CB->Draw("APSAME"); 
    //Sigma1_MS->Draw("APSAME");
    leg101->Draw();   

    // Set the axis titles
    Sigma1_MS_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_CB->GetYaxis()->SetTitle("Resolution (mm)");
    /* Sigma1_MS->GetXaxis()->SetTitle("PCB");
    Sigma1_MS->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_MS_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Gauss->GetYaxis()->SetTitle("Resolution (mm)"); */
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(4,.5, "ATLAS Simulated Data");
    c101->Update();
///////////////////////////////////////////////////////Canvas #2
    TLegend *leg2 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c2 = new TCanvas("c2", "Sigma per PCB", 800, 600);

    /* TGraphErrors *Sigma1_eta_Gauss = new TGraphErrors(8,PCB,sigma1_eta_Gauss,0,esigma1_eta_Gauss);//eta
    Sigma1_eta_Gauss->SetTitle("Sigma per PCB");
    Sigma1_eta_Gauss->SetMarkerStyle(22);
    Sigma1_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_eta_Gauss->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_stereo_Gauss = new TGraphErrors(8,PCB,sigma1_stereo_Gauss,0,esigma1_stereo_Gauss);//stereo
    Sigma1_stereo_Gauss->SetTitle("Sigma per PCB");
    Sigma1_stereo_Gauss->SetMarkerStyle(22);
    Sigma1_stereo_Gauss->SetMarkerColor(kSpring);
    Sigma1_stereo_Gauss->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_stereo_Gauss, "Stereo Strips Gauss", "p"); */
    
    TGraphErrors *Sigma1_eta_CB = new TGraphErrors(8,PCB,sigma1_eta_CB,0,esigma1_eta_CB);//eta
    Sigma1_eta_CB->SetTitle("Sigma per PCB");
    Sigma1_eta_CB->SetMarkerStyle(21);
    Sigma1_eta_CB->SetMarkerColor(kViolet);
    Sigma1_eta_CB->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_eta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_stereo_CB = new TGraphErrors(8,PCB,sigma1_stereo_CB,0,esigma1_stereo_CB);//stereo
    Sigma1_stereo_CB->SetTitle("Sigma per PCB");
    Sigma1_stereo_CB->SetMarkerStyle(21);
    Sigma1_stereo_CB->SetMarkerColor(kGreen);
    Sigma1_stereo_CB->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_stereo_CB, "Stereo Strips Crystal Ball", "p");

    /* TGraphErrors *Sigma1_eta = new TGraphErrors(8,PCB,sigma1_eta,0,esigma1_eta);//eta
    Sigma1_eta->SetTitle("Sigma per PCB");
    Sigma1_eta->SetMarkerStyle(20);
    Sigma1_eta->SetMarkerColor(kRed);
    Sigma1_eta->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_eta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_stereo = new TGraphErrors(8,PCB,sigma1_stereo,0,esigma1_stereo);//stereo
    Sigma1_stereo->SetTitle("Sigma per PCB");
    Sigma1_stereo->SetMarkerStyle(20);
    Sigma1_stereo->SetMarkerColor(kBlue);
    Sigma1_stereo->SetMarkerSize(1.5);
    leg2->AddEntry(Sigma1_stereo, "Stereo Strips Double Gauss", "p"); */

    /* Sigma1_stereo_Gauss->Draw("APSAME");
    Sigma1_eta_Gauss->Draw("PSAME"); */
    Sigma1_stereo_CB->Draw("APSAME");
    Sigma1_eta_CB->Draw("PSAME");
    /* Sigma1_stereo->Draw("APSAME");
    Sigma1_eta->Draw("PSAME"); */
    leg2->Draw();
    
    // Set the axis titles
    Sigma1_eta_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_stereo_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_CB->GetYaxis()->SetTitle("Resolution (mm)");
    /* Sigma1_eta->GetXaxis()->SetTitle("PCB");
    Sigma1_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo->GetXaxis()->SetTitle("PCB");
    Sigma1_stereo->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_eta_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_stereo_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_Gauss->GetYaxis()->SetTitle("Resolution (mm)"); */
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(4,.5, "ATLAS Simulated Data");
    c2->Update();
///////////////////////////////////////////////////////Canvas #201
    TLegend *leg201 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c201 = new TCanvas("c201", "Sigma per PCB", 800, 600);

    /* TGraphErrors *Sigma1_Gauss = new TGraphErrors(8,PCB,sigma1_Gauss,0,esigma1_Gauss);
    Sigma1_Gauss->SetTitle("Sigma per PCB");
    Sigma1_Gauss->SetMarkerStyle(22);
    Sigma1_Gauss->SetMarkerColor(kOrange);
    Sigma1_Gauss->SetMarkerSize(1.5);
    leg201->AddEntry(Sigma1_Gauss, "Gauss", "p"); */
    
    TGraphErrors *Sigma1_CB = new TGraphErrors(8,PCB,sigma1_CB,0,esigma1_CB);
    Sigma1_CB->SetTitle("Sigma per PCB");
    Sigma1_CB->SetMarkerStyle(21);
    Sigma1_CB->SetMarkerColor(kViolet);
    Sigma1_CB->SetMarkerSize(1.5);
    leg201->AddEntry(Sigma1_CB, "Crystal Ball", "p");
    
    /* TGraphErrors *Sigma1 = new TGraphErrors(8,PCB,sigma1,0,esigma1);
    Sigma1->SetTitle("Sigma per PCB");
    Sigma1->SetMarkerStyle(20);
    Sigma1->SetMarkerColor(kRed);
    Sigma1->SetMarkerSize(1.5);
    leg201->AddEntry(Sigma1, "Double Gauss", "p"); */

    //Sigma1_Gauss->Draw("APSAME");
    Sigma1_CB->Draw("APSAME");
    //Sigma1->Draw("APSAME");
    leg201->Draw();

    // Set the axis titles
    Sigma1_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_CB->GetYaxis()->SetTitle("Resolution (mm)");
    /* Sigma1->GetXaxis()->SetTitle("PCB");
    Sigma1->GetYaxis()->SetRangeUser(0,.6);
    Sigma1->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_Gauss->GetYaxis()->SetTitle("Resolution (mm)"); */
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(4,.5, "ATLAS Simulated Data");
    c201->Update();
///////////////////////////////////////////////////////Canvas #3
    TLegend *leg3 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c3 = new TCanvas("c3", "Sigma per Theta MS", 800, 600);

    double_t rad = 57.2957795;
    double_t THETA[8]={0.155*rad,0.205*rad,0.255*rad,0.305*rad,0.355*rad,0.405*rad,0.455*rad,0.505*rad};//{0.15,0.2,0.25,0.3,0.35,0.4,0.45,0.5}
    double_t ETHETA[8]={0.005*rad,0.005*rad,0.005*rad,0.005*rad,0.005*rad,0.005*rad,0.005*rad,0.005*rad};

    TGraphErrors *Sigma1_MS_eta_theta_Gauss = new TGraphErrors(8,THETA,sigma1_MS_eta_theta_Gauss,ETHETA,esigma1_MS_eta_theta_Gauss);//eta
    Sigma1_MS_eta_theta_Gauss->SetTitle("Sigma per Theta MS");
    Sigma1_MS_eta_theta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_eta_theta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_eta_theta_Gauss->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_eta_theta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_theta_Gauss = new TGraphErrors(8,THETA,sigma1_MS_stereo_theta_Gauss,ETHETA,esigma1_MS_stereo_theta_Gauss);//stereo
    Sigma1_MS_stereo_theta_Gauss->SetTitle("Sigma per Theta MS");
    Sigma1_MS_stereo_theta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_stereo_theta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_stereo_theta_Gauss->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_stereo_theta_Gauss, "Stereo Strips Gauss", "p");
    
    /* TGraphErrors *Sigma1_MS_eta_theta_CB = new TGraphErrors(8,THETA,sigma1_MS_eta_theta_CB,ETHETA,esigma1_MS_eta_theta_CB);//eta
    Sigma1_MS_eta_theta_CB->SetTitle("Sigma per Theta MS");
    Sigma1_MS_eta_theta_CB->SetMarkerStyle(21);
    Sigma1_MS_eta_theta_CB->SetMarkerColor(kViolet);
    Sigma1_MS_eta_theta_CB->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_eta_theta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_MS_stereo_theta_CB = new TGraphErrors(8,THETA,sigma1_MS_stereo_theta_CB,ETHETA,esigma1_MS_stereo_theta_CB);//stereo
    Sigma1_MS_stereo_theta_CB->SetTitle("Sigma per Theta MS");
    Sigma1_MS_stereo_theta_CB->SetMarkerStyle(21);
    Sigma1_MS_stereo_theta_CB->SetMarkerColor(kGreen);
    Sigma1_MS_stereo_theta_CB->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_stereo_theta_CB, "Stereo Strips Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_MS_eta_theta = new TGraphErrors(8,THETA,sigma1_MS_eta_theta,ETHETA,esigma1_MS_eta_theta);//eta
    Sigma1_MS_eta_theta->SetTitle("Sigma per Theta MS");
    Sigma1_MS_eta_theta->SetMarkerStyle(20);
    Sigma1_MS_eta_theta->SetMarkerColor(kRed);
    Sigma1_MS_eta_theta->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_eta_theta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_theta = new TGraphErrors(8,THETA,sigma1_MS_stereo_theta,ETHETA,esigma1_MS_stereo_theta);//stereo
    Sigma1_MS_stereo_theta->SetTitle("Sigma per Theta MS");
    Sigma1_MS_stereo_theta->SetMarkerStyle(20);
    Sigma1_MS_stereo_theta->SetMarkerColor(kBlue);
    Sigma1_MS_stereo_theta->SetMarkerSize(1.5);
    leg3->AddEntry(Sigma1_MS_stereo_theta, "Stereo Strips Double Gauss", "p"); */

    Sigma1_MS_stereo_theta_Gauss->Draw("APSAME");
    Sigma1_MS_eta_theta_Gauss->Draw("PSAME");
    /* Sigma1_MS_stereo_theta_CB->Draw("PSAME");
    Sigma1_MS_eta_theta_CB->Draw("PSAME"); */
    /* Sigma1_MS_stereo_theta->Draw("APSAME");
    Sigma1_MS_eta_theta->Draw("PSAME"); */
    leg3->Draw();
   
    // Set the axis titles
    /* Sigma1_MS_eta_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_eta_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_eta_theta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_stereo_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_stereo_theta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS_eta_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_eta_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_eta_theta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_stereo_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_stereo_theta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_MS_eta_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_eta_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_eta_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_stereo_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_stereo_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(18,.5, "ATLAS Simulated Data");
    c3->Update();
   ///////////////////////////////////////////////////////Canvas #301
    TLegend *leg301 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c301 = new TCanvas("c301", "Sigma per Theta MS", 800, 600);

    TGraphErrors *Sigma1_MS_theta_Gauss = new TGraphErrors(8,THETA,sigma1_MS_theta_Gauss,ETHETA,esigma1_MS_theta_Gauss);
    Sigma1_MS_theta_Gauss->SetTitle("Sigma per Theta MS");
    Sigma1_MS_theta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_theta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_theta_Gauss->SetMarkerSize(1.5);
    leg301->AddEntry(Sigma1_MS_theta_Gauss, "Gauss", "p");

    /* TGraphErrors *Sigma1_MS_theta_CB = new TGraphErrors(8,THETA,sigma1_MS_theta_CB,ETHETA,esigma1_MS_theta_CB);
    Sigma1_MS_theta_CB->SetTitle("Sigma per Theta MS");
    Sigma1_MS_theta_CB->SetMarkerStyle(21);
    Sigma1_MS_theta_CB->SetMarkerColor(kViolet);
    Sigma1_MS_theta_CB->SetMarkerSize(1.5);
    leg301->AddEntry(Sigma1_MS_theta_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_MS_theta = new TGraphErrors(8,THETA,sigma1_MS_theta,ETHETA,esigma1_MS_theta);
    Sigma1_MS_theta->SetTitle("Sigma per Theta MS");
    Sigma1_MS_theta->SetMarkerStyle(20);
    Sigma1_MS_theta->SetMarkerColor(kRed);
    Sigma1_MS_theta->SetMarkerSize(1.5);
    leg301->AddEntry(Sigma1_MS_theta, "Double Gauss", "p"); */
    
    Sigma1_MS_theta_Gauss->Draw("APSAME");
    //Sigma1_MS_theta_CB->Draw("PSAME");
    //Sigma1_MS_theta->Draw("APSAME");
    leg301->Draw();  

    // Set the axis titles
    /* Sigma1_MS_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_theta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_theta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_MS_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_MS_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_MS_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(18,.5, "ATLAS Simulated Data");
    c301->Update();
///////////////////////////////////////////////////////Canvas #4
    TLegend *leg4 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c4 = new TCanvas("c4", "Sigma per Theta", 800, 600);

    TGraphErrors *Sigma1_eta_theta_Gauss = new TGraphErrors(8,THETA,sigma1_eta_theta_Gauss,ETHETA,esigma1_eta_theta_Gauss);//eta
    Sigma1_eta_theta_Gauss->SetTitle("Sigma per Theta");
    Sigma1_eta_theta_Gauss->SetMarkerStyle(22);
    Sigma1_eta_theta_Gauss->SetMarkerColor(kOrange);
    Sigma1_eta_theta_Gauss->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_eta_theta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_stereo_theta_Gauss = new TGraphErrors(8,THETA,sigma1_stereo_theta_Gauss,ETHETA,esigma1_stereo_theta_Gauss);//stereo
    Sigma1_stereo_theta_Gauss->SetTitle("Sigma per Theta");
    Sigma1_stereo_theta_Gauss->SetMarkerStyle(22);
    Sigma1_stereo_theta_Gauss->SetMarkerColor(kSpring);
    Sigma1_stereo_theta_Gauss->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_stereo_theta_Gauss, "Stereo Strips Gauss", "p");
    
    /* TGraphErrors *Sigma1_eta_theta_CB = new TGraphErrors(8,THETA,sigma1_eta_theta_CB,ETHETA,esigma1_eta_theta_CB);//eta
    Sigma1_eta_theta_CB->SetTitle("Sigma per Theta");
    Sigma1_eta_theta_CB->SetMarkerStyle(21);
    Sigma1_eta_theta_CB->SetMarkerColor(kViolet);
    Sigma1_eta_theta_CB->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_eta_theta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_stereo_theta_CB = new TGraphErrors(8,THETA,sigma1_stereo_theta_CB,ETHETA,esigma1_stereo_theta_CB);//stereo
    Sigma1_stereo_theta_CB->SetTitle("Sigma per Theta");
    Sigma1_stereo_theta_CB->SetMarkerStyle(21);
    Sigma1_stereo_theta_CB->SetMarkerColor(kGreen);
    Sigma1_stereo_theta_CB->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_stereo_theta_CB, "Stereo Strips Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_eta_theta = new TGraphErrors(8,THETA,sigma1_eta_theta,ETHETA,esigma1_eta_theta);//eta
    Sigma1_eta_theta->SetTitle("Sigma per Theta");
    Sigma1_eta_theta->SetMarkerStyle(20);
    Sigma1_eta_theta->SetMarkerColor(kRed);
    Sigma1_eta_theta->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_eta_theta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_stereo_theta = new TGraphErrors(8,THETA,sigma1_stereo_theta,ETHETA,esigma1_stereo_theta);//stereo
    Sigma1_stereo_theta->SetTitle("Sigma per Theta");
    Sigma1_stereo_theta->SetMarkerStyle(20);
    Sigma1_stereo_theta->SetMarkerColor(kBlue);
    Sigma1_stereo_theta->SetMarkerSize(1.5);
    leg4->AddEntry(Sigma1_stereo_theta, "Stereo Strips Double Gauss", "p"); */

    Sigma1_stereo_theta_Gauss->Draw("APSAME");
    Sigma1_eta_theta_Gauss->Draw("PSAME");
    /* Sigma1_stereo_theta_CB->Draw("PSAME");
    Sigma1_eta_theta_CB->Draw("PSAME"); */
    /* Sigma1_stereo_theta->Draw("APSAME");
    Sigma1_eta_theta->Draw("PSAME"); */
    leg4->Draw();

    // Set the axis titles
    /* Sigma1_eta_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_eta_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_eta_theta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_stereo_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_stereo_theta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_eta_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_eta_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_eta_theta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_stereo_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_stereo_theta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_eta_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_eta_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_eta_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_stereo_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_stereo_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(18,.5, "ATLAS Simulated Data");
    c4->Update();
   ///////////////////////////////////////////////////////Canvas #401
    TLegend *leg401 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c401 = new TCanvas("c401", "Sigma per Theta", 800, 600);

    TGraphErrors *Sigma1_theta_Gauss = new TGraphErrors(8,THETA,sigma1_theta_Gauss,ETHETA,esigma1_theta_Gauss);
    Sigma1_theta_Gauss->SetTitle("Sigma per Theta");
    Sigma1_theta_Gauss->SetMarkerStyle(22);
    Sigma1_theta_Gauss->SetMarkerColor(kOrange);
    Sigma1_theta_Gauss->SetMarkerSize(1.5);
    leg401->AddEntry(Sigma1_theta_Gauss, "Gauss", "p");
    
    /* TGraphErrors *Sigma1_theta_CB = new TGraphErrors(8,THETA,sigma1_theta_CB,ETHETA,esigma1_theta_CB);
    Sigma1_theta_CB->SetTitle("Sigma per Theta");
    Sigma1_theta_CB->SetMarkerStyle(21);
    Sigma1_theta_CB->SetMarkerColor(kViolet);
    Sigma1_theta_CB->SetMarkerSize(1.5);
    leg401->AddEntry(Sigma1_theta_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_theta = new TGraphErrors(8,THETA,sigma1_theta,ETHETA,esigma1_theta);
    Sigma1_theta->SetTitle("Sigma per Theta");
    Sigma1_theta->SetMarkerStyle(20);
    Sigma1_theta->SetMarkerColor(kRed);
    Sigma1_theta->SetMarkerSize(1.5);
    leg401->AddEntry(Sigma1_theta, "Double Gauss", "p"); */
    
    Sigma1_theta_Gauss->Draw("APSAME");
    //Sigma1_theta_CB->Draw("PSAME");
    //Sigma1_theta->Draw("APSAME");
    leg401->Draw();

    // Set the axis titles
    /* Sigma1_theta_CB->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_theta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_theta_CB->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_theta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_theta->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_theta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_theta->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_theta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_theta_Gauss->GetXaxis()->SetTitle("THETA (deg)");
    Sigma1_theta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_theta_Gauss->GetXaxis()->SetLimits(0.,0.6*rad);
    Sigma1_theta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(18,.5, "ATLAS Simulated Data");
    c401->Update();
///////////////////////////////////////////////////////Canvas #5
    TLegend *leg5 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c5 = new TCanvas("c5", "Sigma per Eta MS", 800, 600);

    double_t ETA[14]={1.35,1.45,1.55,1.65,1.75,1.85,1.95,2.05,2.15,2.25,2.35,2.45,2.55,2.65};//1.3,1.4,1.5,1.6,1.7,1.8,1.9,2.,2.1,2.2,2.3,2.4,2.5,2.6
    double_t EETA[14]={0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05,0.05};

    TGraphErrors *Sigma1_MS_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_eta_eta_Gauss,EETA,esigma1_MS_eta_eta_Gauss);//eta
    Sigma1_MS_eta_eta_Gauss->SetTitle("Sigma per Eta MS");
    Sigma1_MS_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_eta_eta_Gauss->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_stereo_eta_Gauss,EETA,esigma1_MS_stereo_eta_Gauss);//stereo
    Sigma1_MS_stereo_eta_Gauss->SetTitle("Sigma per Eta MS");
    Sigma1_MS_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    /* TGraphErrors *Sigma1_MS_eta_eta_CB = new TGraphErrors(14,ETA,sigma1_MS_eta_eta_CB,EETA,esigma1_MS_eta_eta_CB);//eta
    Sigma1_MS_eta_eta_CB->SetTitle("Sigma per Eta MS");
    Sigma1_MS_eta_eta_CB->SetMarkerStyle(21);
    Sigma1_MS_eta_eta_CB->SetMarkerColor(kViolet);
    Sigma1_MS_eta_eta_CB->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_eta_eta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_MS_stereo_eta_CB = new TGraphErrors(14,ETA,sigma1_MS_stereo_eta_CB,EETA,esigma1_MS_stereo_eta_CB);//stereo
    Sigma1_MS_stereo_eta_CB->SetTitle("Sigma per Eta MS");
    Sigma1_MS_stereo_eta_CB->SetMarkerStyle(21);
    Sigma1_MS_stereo_eta_CB->SetMarkerColor(kGreen);
    Sigma1_MS_stereo_eta_CB->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_stereo_eta_CB, "Stereo Strips Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_MS_eta_eta = new TGraphErrors(14,ETA,sigma1_MS_eta_eta,EETA,esigma1_MS_eta_eta);//eta
    Sigma1_MS_eta_eta->SetTitle("Sigma per Eta MS");
    Sigma1_MS_eta_eta->SetMarkerStyle(20);
    Sigma1_MS_eta_eta->SetMarkerColor(kRed);
    Sigma1_MS_eta_eta->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_eta_eta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_eta = new TGraphErrors(14,ETA,sigma1_MS_stereo_eta,EETA,esigma1_MS_stereo_eta);//stereo
    Sigma1_MS_stereo_eta->SetTitle("Sigma per Eta MS");
    Sigma1_MS_stereo_eta->SetMarkerStyle(20);
    Sigma1_MS_stereo_eta->SetMarkerColor(kBlue);
    Sigma1_MS_stereo_eta->SetMarkerSize(1.5);
    leg5->AddEntry(Sigma1_MS_stereo_eta, "Stereo Strips Double Gauss", "p"); */

    Sigma1_MS_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_eta_eta_Gauss->Draw("PSAME");
    /* Sigma1_MS_stereo_eta_CB->Draw("PSAME");
    Sigma1_MS_eta_eta_CB->Draw("PSAME"); */
    /* Sigma1_MS_stereo_eta->Draw("APSAME");
    Sigma1_MS_eta_eta->Draw("PSAME"); */
    leg5->Draw();
    
    // Set the axis titles
    /* Sigma1_MS_eta_eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_eta_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_eta_eta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_stereo_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_stereo_eta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS_eta_eta->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_eta_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_eta_eta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_eta->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_stereo_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_stereo_eta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_MS_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c5->Update();
///////////////////////////////////////////////////////Canvas #501
    TLegend *leg501 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c501 = new TCanvas("c501", "Sigma per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS__eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Eta_Gauss,EETA,esigma1_MS_Eta_Gauss);
    Sigma1_MS__eta_Gauss->SetTitle("Sigma per Eta MS");
    Sigma1_MS__eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS__eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS__eta_Gauss->SetMarkerSize(1.5);
    leg501->AddEntry(Sigma1_MS__eta_Gauss, "Gauss", "p");

    /* TGraphErrors *Sigma1_MS__eta_CB = new TGraphErrors(14,ETA,sigma1_MS_Eta_CB,EETA,esigma1_MS_Eta_CB);
    Sigma1_MS__eta_CB->SetTitle("Sigma per Eta MS");
    Sigma1_MS__eta_CB->SetMarkerStyle(21);
    Sigma1_MS__eta_CB->SetMarkerColor(kViolet);
    Sigma1_MS__eta_CB->SetMarkerSize(1.5);
    leg501->AddEntry(Sigma1_MS__eta_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_MS__eta = new TGraphErrors(14,ETA,sigma1_MS_Eta,EETA,esigma1_MS_Eta);
    Sigma1_MS__eta->SetTitle("Sigma per Eta MS");
    Sigma1_MS__eta->SetMarkerStyle(20);
    Sigma1_MS__eta->SetMarkerColor(kRed);
    Sigma1_MS__eta->SetMarkerSize(1.5);
    leg501->AddEntry(Sigma1_MS__eta, "Double Gauss", "p"); */
   
    Sigma1_MS__eta_Gauss->Draw("APSAME");
    //Sigma1_MS__eta_CB->Draw("PSAME");
    //Sigma1_MS__eta->Draw("APSAME");
    leg501->Draw();
    
    // Set the axis titles
    /* Sigma1_MS__eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_MS__eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS__eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS__eta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_MS__eta->GetXaxis()->SetTitle("ETA");
    Sigma1_MS__eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS__eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS__eta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_MS__eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS__eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS__eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS__eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c501->Update();
///////////////////////////////////////////////////////Canvas #6
    TLegend *leg6 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c6 = new TCanvas("c6", "Sigma per Eta", 800, 600);

    TGraphErrors *Sigma1_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_eta_eta_Gauss,EETA,esigma1_eta_eta_Gauss);//eta
    Sigma1_eta_eta_Gauss->SetTitle("Sigma per Eta");
    Sigma1_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_eta_eta_Gauss->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_stereo_eta_Gauss,EETA,esigma1_stereo_eta_Gauss);//stereo
    Sigma1_stereo_eta_Gauss->SetTitle("Sigma per Eta");
    Sigma1_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    /* TGraphErrors *Sigma1_eta_eta_CB = new TGraphErrors(14,ETA,sigma1_eta_eta_CB,EETA,esigma1_eta_eta_CB);//eta
    Sigma1_eta_eta_CB->SetTitle("Sigma per Eta");
    Sigma1_eta_eta_CB->SetMarkerStyle(21);
    Sigma1_eta_eta_CB->SetMarkerColor(kViolet);
    Sigma1_eta_eta_CB->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_eta_eta_CB, "Eta Strips Crystal Ball", "p");

    TGraphErrors *Sigma1_stereo_eta_CB = new TGraphErrors(14,ETA,sigma1_stereo_eta_CB,EETA,esigma1_stereo_eta_CB);//stereo
    Sigma1_stereo_eta_CB->SetTitle("Sigma per Eta");
    Sigma1_stereo_eta_CB->SetMarkerStyle(21);
    Sigma1_stereo_eta_CB->SetMarkerColor(kGreen);
    Sigma1_stereo_eta_CB->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_stereo_eta_CB, "Stereo Strips Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_eta_eta = new TGraphErrors(14,ETA,sigma1_eta_eta,EETA,esigma1_eta_eta);//eta
    Sigma1_eta_eta->SetTitle("Sigma per Eta");
    Sigma1_eta_eta->SetMarkerStyle(20);
    Sigma1_eta_eta->SetMarkerColor(kRed);
    Sigma1_eta_eta->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_eta_eta, "Eta Strips Double Gauss", "p");

    TGraphErrors *Sigma1_stereo_eta = new TGraphErrors(14,ETA,sigma1_stereo_eta,EETA,esigma1_stereo_eta);//stereo
    Sigma1_stereo_eta->SetTitle("Sigma per Eta");
    Sigma1_stereo_eta->SetMarkerStyle(20);
    Sigma1_stereo_eta->SetMarkerColor(kBlue);
    Sigma1_stereo_eta->SetMarkerSize(1.5);
    leg6->AddEntry(Sigma1_stereo_eta, "Stereo Strips Double Gauss", "p"); */

    Sigma1_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_eta_eta_Gauss->Draw("PSAME");
    /* Sigma1_stereo_eta_CB->Draw("PSAME");
    Sigma1_eta_eta_CB->Draw("PSAME"); */
    /* Sigma1_stereo_eta->Draw("APSAME");
    Sigma1_eta_eta->Draw("PSAME"); */
    leg6->Draw();

    // Set the axis titles
    /* Sigma1_eta_eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_eta_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_eta_eta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_stereo_eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_stereo_eta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_eta_eta->GetXaxis()->SetTitle("ETA");
    Sigma1_eta_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_eta_eta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_eta->GetXaxis()->SetTitle("ETA");
    Sigma1_stereo_eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_stereo_eta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c6->Update();
///////////////////////////////////////////////////////Canvas #601
    TLegend *leg601 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c601 = new TCanvas("c601", "Sigma per Eta", 800, 600);

    TGraphErrors *Sigma1__eta_Gauss = new TGraphErrors(14,ETA,sigma1_Eta_Gauss,EETA,esigma1_Eta_Gauss);
    Sigma1__eta_Gauss->SetTitle("Sigma per Eta");
    Sigma1__eta_Gauss->SetMarkerStyle(22);
    Sigma1__eta_Gauss->SetMarkerColor(kOrange);
    Sigma1__eta_Gauss->SetMarkerSize(1.5);
    leg601->AddEntry(Sigma1__eta_Gauss, "Gauss", "p");

    TGraphErrors *Sigma1__eta_CB = new TGraphErrors(14,ETA,sigma1_Eta_CB,EETA,esigma1_Eta_CB);
    Sigma1__eta_CB->SetTitle("Sigma per Eta");
    Sigma1__eta_CB->SetMarkerStyle(21);
    Sigma1__eta_CB->SetMarkerColor(kViolet);
    Sigma1__eta_CB->SetMarkerSize(1.5);
    leg601->AddEntry(Sigma1__eta_CB, "Crystal Ball", "p");

    TGraphErrors *Sigma1__eta = new TGraphErrors(14,ETA,sigma1_Eta,EETA,esigma1_Eta);
    Sigma1__eta->SetTitle("Sigma per Eta");
    Sigma1__eta->SetMarkerStyle(20);
    Sigma1__eta->SetMarkerColor(kRed);
    Sigma1__eta->SetMarkerSize(1.5);
    leg601->AddEntry(Sigma1__eta, "Double Gauss", "p");
    
    Sigma1__eta_Gauss->Draw("APSAME");
    Sigma1__eta_CB->Draw("PSAME");
    Sigma1__eta->Draw("PSAME");
    leg601->Draw();

    // Set the axis titles
    Sigma1__eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1__eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1__eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1__eta_CB->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1__eta->GetXaxis()->SetTitle("ETA");
    Sigma1__eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1__eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1__eta->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1__eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1__eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1__eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1__eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c601->Update();
///////////////////////////////////////////////////////Canvas #71
    TLegend *leg71 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c71 = new TCanvas("c71", "Sigma Phi01 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi01_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi01_eta_eta_Gauss,EETA,esigma1_MS_Phi01_eta_eta_Gauss);//eta
    Sigma1_MS_Phi01_eta_eta_Gauss->SetTitle("Sigma Phi01 per Eta MS");
    Sigma1_MS_Phi01_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi01_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi01_eta_eta_Gauss->SetMarkerSize(1.5);
    leg71->AddEntry(Sigma1_MS_Phi01_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi01_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi01_stereo_eta_Gauss,EETA,esigma1_MS_Phi01_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi01_stereo_eta_Gauss->SetTitle("Sigma Phi01 per Eta MS");
    Sigma1_MS_Phi01_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi01_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi01_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg71->AddEntry(Sigma1_MS_Phi01_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi01_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi01_eta_eta_Gauss->Draw("PSAME");
    leg71->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi01_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi01_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi01_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi01_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi01_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi01_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi01_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi01_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c71->Update();
///////////////////////////////////////////////////////Canvas #72
    TLegend *leg72 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c72 = new TCanvas("c72", "Sigma Phi02 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi02_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi02_eta_eta_Gauss,EETA,esigma1_MS_Phi02_eta_eta_Gauss);//eta
    Sigma1_MS_Phi02_eta_eta_Gauss->SetTitle("Sigma Phi02 per Eta MS");
    Sigma1_MS_Phi02_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi02_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi02_eta_eta_Gauss->SetMarkerSize(1.5);
    leg72->AddEntry(Sigma1_MS_Phi02_eta_eta_Gauss, "Eta Strips Gauss", "p");
    
    TGraphErrors *Sigma1_MS_Phi02_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi02_stereo_eta_Gauss,EETA,esigma1_MS_Phi02_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi02_stereo_eta_Gauss->SetTitle("Sigma Phi02 per Eta MS");
    Sigma1_MS_Phi02_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi02_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi02_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg72->AddEntry(Sigma1_MS_Phi01_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi02_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi02_eta_eta_Gauss->Draw("PSAME");
    leg72->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi02_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi02_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi02_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi02_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi02_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi02_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi02_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi02_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c72->Update();
///////////////////////////////////////////////////////Canvas #73
    TLegend *leg73 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c73 = new TCanvas("c73", "Sigma Phi03 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi03_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi03_eta_eta_Gauss,EETA,esigma1_MS_Phi03_eta_eta_Gauss);//eta
    Sigma1_MS_Phi03_eta_eta_Gauss->SetTitle("Sigma Phi03 per Eta MS");
    Sigma1_MS_Phi03_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi03_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi03_eta_eta_Gauss->SetMarkerSize(1.5);
    leg73->AddEntry(Sigma1_MS_Phi03_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi03_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi03_stereo_eta_Gauss,EETA,esigma1_MS_Phi03_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi03_stereo_eta_Gauss->SetTitle("Sigma Phi03 per Eta MS");
    Sigma1_MS_Phi03_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi03_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi03_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg73->AddEntry(Sigma1_MS_Phi03_stereo_eta_Gauss, "Stereo Strips Gauss", "p");
 
    Sigma1_MS_Phi03_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi03_eta_eta_Gauss->Draw("PSAME");
    leg73->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi03_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi03_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi03_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi03_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi03_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi03_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi03_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi03_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c73->Update();
///////////////////////////////////////////////////////Canvas #74
    TLegend *leg74 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c74 = new TCanvas("c74", "Sigma Phi04 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi04_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi04_eta_eta_Gauss,EETA,esigma1_MS_Phi04_eta_eta_Gauss);//eta
    Sigma1_MS_Phi04_eta_eta_Gauss->SetTitle("Sigma Phi04 per Eta MS");
    Sigma1_MS_Phi04_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi04_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi04_eta_eta_Gauss->SetMarkerSize(1.5);
    leg74->AddEntry(Sigma1_MS_Phi04_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi04_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi04_stereo_eta_Gauss,EETA,esigma1_MS_Phi04_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi04_stereo_eta_Gauss->SetTitle("Sigma Phi04 per Eta MS");
    Sigma1_MS_Phi04_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi04_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi04_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg74->AddEntry(Sigma1_MS_Phi04_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi04_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi04_eta_eta_Gauss->Draw("PSAME");
    leg74->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi04_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi04_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi04_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi04_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi04_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi04_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi04_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi04_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c74->Update();
///////////////////////////////////////////////////////Canvas #75
    TLegend *leg75 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c75 = new TCanvas("c75", "Sigma Phi05 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi05_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi05_eta_eta_Gauss,EETA,esigma1_MS_Phi05_eta_eta_Gauss);//eta
    Sigma1_MS_Phi05_eta_eta_Gauss->SetTitle("Sigma Phi05 per Eta MS");
    Sigma1_MS_Phi05_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi05_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi05_eta_eta_Gauss->SetMarkerSize(1.5);
    leg75->AddEntry(Sigma1_MS_Phi05_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi05_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi05_stereo_eta_Gauss,EETA,esigma1_MS_Phi05_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi05_stereo_eta_Gauss->SetTitle("Sigma Phi05 per Eta MS");
    Sigma1_MS_Phi05_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi05_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi05_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg75->AddEntry(Sigma1_MS_Phi05_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi05_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi05_eta_eta_Gauss->Draw("PSAME");
    leg75->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi05_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi05_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi05_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi05_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi05_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi05_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi05_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi05_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c75->Update();
///////////////////////////////////////////////////////Canvas #76
    TLegend *leg76 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c76 = new TCanvas("c76", "Sigma Phi06 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi06_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi06_eta_eta_Gauss,EETA,esigma1_MS_Phi06_eta_eta_Gauss);//eta
    Sigma1_MS_Phi06_eta_eta_Gauss->SetTitle("Sigma Phi06 per Eta MS");
    Sigma1_MS_Phi06_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi06_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi06_eta_eta_Gauss->SetMarkerSize(1.5);
    leg76->AddEntry(Sigma1_MS_Phi06_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi06_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi06_stereo_eta_Gauss,EETA,esigma1_MS_Phi06_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi06_stereo_eta_Gauss->SetTitle("Sigma Phi06 per Eta MS");
    Sigma1_MS_Phi06_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi06_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi06_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg76->AddEntry(Sigma1_MS_Phi06_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi06_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi06_eta_eta_Gauss->Draw("PSAME");
    leg76->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi06_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi06_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi06_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi06_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi06_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi06_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi06_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi06_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c76->Update();
///////////////////////////////////////////////////////Canvas #77
    TLegend *leg77 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c77 = new TCanvas("c77", "Sigma Phi07 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi07_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi07_eta_eta_Gauss,EETA,esigma1_MS_Phi07_eta_eta_Gauss);//eta
    Sigma1_MS_Phi07_eta_eta_Gauss->SetTitle("Sigma Phi07 per Eta MS");
    Sigma1_MS_Phi07_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi07_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi07_eta_eta_Gauss->SetMarkerSize(1.5);
    leg77->AddEntry(Sigma1_MS_Phi07_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi07_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi07_stereo_eta_Gauss,EETA,esigma1_MS_Phi07_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi07_stereo_eta_Gauss->SetTitle("Sigma Phi07 per Eta MS");
    Sigma1_MS_Phi07_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi07_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi07_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg77->AddEntry(Sigma1_MS_Phi07_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_Phi07_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi07_eta_eta_Gauss->Draw("PSAME");
    leg77->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi07_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi07_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi07_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi07_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi07_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi07_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi07_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi07_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c77->Update();
///////////////////////////////////////////////////////Canvas #78
    TLegend *leg78 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c78 = new TCanvas("c78", "Sigma Phi08 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi08_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi08_eta_eta_Gauss,EETA,esigma1_MS_Phi08_eta_eta_Gauss);//eta
    Sigma1_MS_Phi08_eta_eta_Gauss->SetTitle("Sigma Phi08 per Eta MS");
    Sigma1_MS_Phi08_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi08_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi08_eta_eta_Gauss->SetMarkerSize(1.5);
    leg78->AddEntry(Sigma1_MS_Phi08_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_Phi08_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi08_stereo_eta_Gauss,EETA,esigma1_MS_Phi08_stereo_eta_Gauss);//stereo
    Sigma1_MS_Phi08_stereo_eta_Gauss->SetTitle("Sigma Phi08 per Eta MS");
    Sigma1_MS_Phi08_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi08_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_Phi08_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg78->AddEntry(Sigma1_MS_Phi08_stereo_eta_Gauss, "Stereo Strips Gauss", "p");
 
    Sigma1_MS_Phi08_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi08_eta_eta_Gauss->Draw("PSAME");
    leg78->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi08_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi08_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi08_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi08_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_Phi08_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi08_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi08_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi08_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c78->Update();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////Canvas #7
    TLegend *leg7 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c7 = new TCanvas("c7", "Sigma Phi Sectors per Eta MS", 800, 600);

    Sigma1_MS_Phi01_eta_eta_Gauss->SetMarkerStyle(21);
    leg7->AddEntry(Sigma1_MS_Phi01_eta_eta_Gauss, "Eta Strips Gauss Phi01", "p");
    Sigma1_MS_Phi01_stereo_eta_Gauss->SetMarkerStyle(21);
    leg7->AddEntry(Sigma1_MS_Phi01_stereo_eta_Gauss, "Stereo Strips Gauss Phi01", "p");
    Sigma1_MS_Phi02_eta_eta_Gauss->SetMarkerStyle(22);
    leg7->AddEntry(Sigma1_MS_Phi02_eta_eta_Gauss, "Eta Strips Gauss Phi02", "p");
    Sigma1_MS_Phi02_stereo_eta_Gauss->SetMarkerStyle(22);
    leg7->AddEntry(Sigma1_MS_Phi02_stereo_eta_Gauss, "Stereo Strips Gauss Phi02", "p");
    Sigma1_MS_Phi03_eta_eta_Gauss->SetMarkerStyle(23);
    leg7->AddEntry(Sigma1_MS_Phi03_eta_eta_Gauss, "Eta Strips Gauss Phi03", "p");
    Sigma1_MS_Phi03_stereo_eta_Gauss->SetMarkerStyle(23);
    leg7->AddEntry(Sigma1_MS_Phi03_stereo_eta_Gauss, "Stereo Strips Gauss Phi03", "p");
    Sigma1_MS_Phi04_eta_eta_Gauss->SetMarkerStyle(24);
    leg7->AddEntry(Sigma1_MS_Phi04_eta_eta_Gauss, "Eta Strips Gauss Phi04", "p");
    Sigma1_MS_Phi04_stereo_eta_Gauss->SetMarkerStyle(24);
    leg7->AddEntry(Sigma1_MS_Phi04_stereo_eta_Gauss, "Stereo Strips Gauss Phi04", "p");
    Sigma1_MS_Phi05_eta_eta_Gauss->SetMarkerStyle(25);
    leg7->AddEntry(Sigma1_MS_Phi05_eta_eta_Gauss, "Eta Strips Gauss Phi05", "p");
    Sigma1_MS_Phi05_stereo_eta_Gauss->SetMarkerStyle(25);
    leg7->AddEntry(Sigma1_MS_Phi05_stereo_eta_Gauss, "Stereo Strips Gauss Phi05", "p");
    Sigma1_MS_Phi06_eta_eta_Gauss->SetMarkerStyle(26);
    leg7->AddEntry(Sigma1_MS_Phi06_eta_eta_Gauss, "Eta Strips Gauss Phi06", "p");
    Sigma1_MS_Phi06_stereo_eta_Gauss->SetMarkerStyle(26);
    leg7->AddEntry(Sigma1_MS_Phi06_stereo_eta_Gauss, "Stereo Strips Gauss Phi06", "p");
    Sigma1_MS_Phi07_eta_eta_Gauss->SetMarkerStyle(27);
    leg7->AddEntry(Sigma1_MS_Phi07_eta_eta_Gauss, "Eta Strips Gauss Phi07", "p");
    Sigma1_MS_Phi07_stereo_eta_Gauss->SetMarkerStyle(27);
    leg7->AddEntry(Sigma1_MS_Phi07_stereo_eta_Gauss, "Stereo Strips Gauss Phi07", "p");
    Sigma1_MS_Phi08_eta_eta_Gauss->SetMarkerStyle(28);
    leg7->AddEntry(Sigma1_MS_Phi08_eta_eta_Gauss, "Eta Strips Gauss Phi08", "p");
    Sigma1_MS_Phi08_stereo_eta_Gauss->SetMarkerStyle(28);
    leg7->AddEntry(Sigma1_MS_Phi08_stereo_eta_Gauss, "Stereo Strips Gauss Phi08", "p");

    Sigma1_MS_Phi01_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_Phi01_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi02_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi02_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi03_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi03_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi04_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi04_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi05_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi05_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi06_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi06_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi07_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi07_eta_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi08_stereo_eta_Gauss->Draw("PSAME");
    Sigma1_MS_Phi08_eta_eta_Gauss->Draw("PSAME");
    
    //leg7->Update();
    leg7->Draw();
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c7->Update();
///////////////////////////////////////////////////////Canvas #79
    TLegend *leg79 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c79 = new TCanvas("c79", "Sigma Small Sectors per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_SmallSector_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_SmallSector_eta_eta_Gauss,EETA,esigma1_MS_SmallSector_eta_eta_Gauss);//eta
    Sigma1_MS_SmallSector_eta_eta_Gauss->SetTitle("Sigma Small Sectors per Eta MS");
    Sigma1_MS_SmallSector_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_SmallSector_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_SmallSector_eta_eta_Gauss->SetMarkerSize(1.5);
    leg79->AddEntry(Sigma1_MS_SmallSector_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_SmallSector_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_SmallSector_stereo_eta_Gauss,EETA,esigma1_MS_SmallSector_stereo_eta_Gauss);//stereo
    Sigma1_MS_SmallSector_stereo_eta_Gauss->SetTitle("Sigma Small Sectors per Eta MS");
    Sigma1_MS_SmallSector_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_SmallSector_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_SmallSector_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg79->AddEntry(Sigma1_MS_SmallSector_stereo_eta_Gauss, "Stereo Strips Gauss", "p");
 
    Sigma1_MS_SmallSector_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_SmallSector_eta_eta_Gauss->Draw("PSAME");
    leg79->Draw();
    
    // Set the axis titles
    Sigma1_MS_SmallSector_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_SmallSector_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_SmallSector_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_SmallSector_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_SmallSector_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_SmallSector_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_SmallSector_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_SmallSector_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c79->Update();
///////////////////////////////////////////////////////Canvas #710
    TLegend *leg710 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c710 = new TCanvas("c710", "Sigma Large Sectors per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_LargeSector_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_LargeSector_eta_eta_Gauss,EETA,esigma1_MS_LargeSector_eta_eta_Gauss);//eta
    Sigma1_MS_LargeSector_eta_eta_Gauss->SetTitle("Sigma Large Sectors per Eta MS");
    Sigma1_MS_LargeSector_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_LargeSector_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_LargeSector_eta_eta_Gauss->SetMarkerSize(1.5);
    leg710->AddEntry(Sigma1_MS_LargeSector_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_LargeSector_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_LargeSector_stereo_eta_Gauss,EETA,esigma1_MS_LargeSector_stereo_eta_Gauss);//stereo
    Sigma1_MS_LargeSector_stereo_eta_Gauss->SetTitle("Sigma Large Sectors per Eta MS");
    Sigma1_MS_LargeSector_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_LargeSector_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_LargeSector_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg710->AddEntry(Sigma1_MS_LargeSector_stereo_eta_Gauss, "Stereo Strips Gauss", "p");
 
    Sigma1_MS_LargeSector_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_MS_LargeSector_eta_eta_Gauss->Draw("PSAME");
    leg710->Draw();
    
    // Set the axis titles
    Sigma1_MS_LargeSector_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_LargeSector_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_LargeSector_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_LargeSector_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_LargeSector_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_LargeSector_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_LargeSector_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_LargeSector_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c710->Update();
///////////////////////////////////////////////////////Canvas #701
    TLegend *leg701 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c701 = new TCanvas("c701", "Sigma Phi01 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi01_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi01_Eta_Gauss,EETA,esigma1_MS_Phi01_Eta_Gauss);
    Sigma1_MS_Phi01_Eta_Gauss->SetTitle("Sigma Phi01 per Eta MS");
    Sigma1_MS_Phi01_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi01_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi01_Eta_Gauss->SetMarkerSize(1.5);
    leg701->AddEntry(Sigma1_MS_Phi01_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi01_Eta_Gauss->Draw("APSAME");
    leg701->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi01_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi01_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi01_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi01_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c701->Update();
///////////////////////////////////////////////////////Canvas #702
    TLegend *leg702 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c702 = new TCanvas("c702", "Sigma Phi02 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi02_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi02_Eta_Gauss,EETA,esigma1_MS_Phi02_Eta_Gauss);
    Sigma1_MS_Phi02_Eta_Gauss->SetTitle("Sigma Phi02 per Eta MS");
    Sigma1_MS_Phi02_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi02_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi02_Eta_Gauss->SetMarkerSize(1.5);
    leg702->AddEntry(Sigma1_MS_Phi02_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi02_Eta_Gauss->Draw("APSAME");
    leg702->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi02_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi02_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi02_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi02_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c702->Update();
///////////////////////////////////////////////////////Canvas #703
    TLegend *leg703 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c703 = new TCanvas("c703", "Sigma Phi03 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi03_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi03_Eta_Gauss,EETA,esigma1_MS_Phi03_Eta_Gauss);
    Sigma1_MS_Phi03_Eta_Gauss->SetTitle("Sigma Phi03 per Eta MS");
    Sigma1_MS_Phi03_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi03_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi03_Eta_Gauss->SetMarkerSize(1.5);
    leg703->AddEntry(Sigma1_MS_Phi02_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi03_Eta_Gauss->Draw("APSAME");
    leg703->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi03_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi03_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi03_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi03_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c703->Update();
///////////////////////////////////////////////////////Canvas #704
    TLegend *leg704 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c704 = new TCanvas("c704", "Sigma Phi04 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi04_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi04_Eta_Gauss,EETA,esigma1_MS_Phi04_Eta_Gauss);
    Sigma1_MS_Phi04_Eta_Gauss->SetTitle("Sigma Phi04 per Eta MS");
    Sigma1_MS_Phi04_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi04_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi04_Eta_Gauss->SetMarkerSize(1.5);
    leg704->AddEntry(Sigma1_MS_Phi02_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi04_Eta_Gauss->Draw("APSAME");
    leg704->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi04_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi04_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi04_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi04_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c704->Update();
///////////////////////////////////////////////////////Canvas #705
    TLegend *leg705 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c705 = new TCanvas("c705", "Sigma Phi05 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi05_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi05_Eta_Gauss,EETA,esigma1_MS_Phi05_Eta_Gauss);
    Sigma1_MS_Phi05_Eta_Gauss->SetTitle("Sigma Phi05 per Eta MS");
    Sigma1_MS_Phi05_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi05_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi05_Eta_Gauss->SetMarkerSize(1.5);
    leg705->AddEntry(Sigma1_MS_Phi02_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi05_Eta_Gauss->Draw("APSAME");
    leg705->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi05_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi05_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi05_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi05_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c705->Update();
///////////////////////////////////////////////////////Canvas #706
    TLegend *leg706 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c706 = new TCanvas("c706", "Sigma Phi06 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi06_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi06_Eta_Gauss,EETA,esigma1_MS_Phi06_Eta_Gauss);
    Sigma1_MS_Phi06_Eta_Gauss->SetTitle("Sigma Phi06 per Eta MS");
    Sigma1_MS_Phi06_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi06_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi06_Eta_Gauss->SetMarkerSize(1.5);
    leg706->AddEntry(Sigma1_MS_Phi02_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi06_Eta_Gauss->Draw("APSAME");
    leg706->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi06_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi06_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi06_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi06_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c706->Update();
///////////////////////////////////////////////////////Canvas #707
    TLegend *leg707 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c707 = new TCanvas("c707", "Sigma Phi07 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi07_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi07_Eta_Gauss,EETA,esigma1_MS_Phi07_Eta_Gauss);
    Sigma1_MS_Phi07_Eta_Gauss->SetTitle("Sigma Phi07 per Eta MS");
    Sigma1_MS_Phi07_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi07_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi07_Eta_Gauss->SetMarkerSize(1.5);
    leg707->AddEntry(Sigma1_MS_Phi07_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi07_Eta_Gauss->Draw("APSAME");
    leg707->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi07_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi07_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi07_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi07_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c707->Update();
///////////////////////////////////////////////////////Canvas #708
    TLegend *leg708 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c708 = new TCanvas("c708", "Sigma Phi08 per Eta MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi08_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_MS_Phi08_Eta_Gauss,EETA,esigma1_MS_Phi08_Eta_Gauss);
    Sigma1_MS_Phi08_Eta_Gauss->SetTitle("Sigma Phi02 per Eta MS");
    Sigma1_MS_Phi08_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi08_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi08_Eta_Gauss->SetMarkerSize(1.5);
    leg708->AddEntry(Sigma1_MS_Phi08_Eta_Gauss, "Gauss", "p");

    Sigma1_MS_Phi08_Eta_Gauss->Draw("APSAME");
    leg708->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi08_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_MS_Phi08_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_MS_Phi08_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_MS_Phi08_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c708->Update();
///////////////////////////////////////////////////////Canvas #717
    TLegend *leg717 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c717 = new TCanvas("c717", "Sigma Phi01 per Eta", 800, 600);

    TGraphErrors *Sigma1_Phi01_eta_eta_Gauss = new TGraphErrors(14,ETA,sigma1_Phi01_eta_eta_Gauss,EETA,esigma1_Phi01_eta_eta_Gauss);//eta
    Sigma1_Phi01_eta_eta_Gauss->SetTitle("Sigma Phi01 per Eta");
    Sigma1_Phi01_eta_eta_Gauss->SetMarkerStyle(22);
    Sigma1_Phi01_eta_eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_Phi01_eta_eta_Gauss->SetMarkerSize(1.5);
    leg717->AddEntry(Sigma1_Phi01_eta_eta_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_Phi01_stereo_eta_Gauss = new TGraphErrors(14,ETA,sigma1_Phi01_stereo_eta_Gauss,EETA,esigma1_Phi01_stereo_eta_Gauss);//stereo
    Sigma1_Phi01_stereo_eta_Gauss->SetTitle("Sigma Phi01 per Eta");
    Sigma1_Phi01_stereo_eta_Gauss->SetMarkerStyle(22);
    Sigma1_Phi01_stereo_eta_Gauss->SetMarkerColor(kSpring);
    Sigma1_Phi01_stereo_eta_Gauss->SetMarkerSize(1.5);
    leg717->AddEntry(Sigma1_Phi01_stereo_eta_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_Phi01_stereo_eta_Gauss->Draw("APSAME");
    Sigma1_Phi01_eta_eta_Gauss->Draw("PSAME");
    leg717->Draw();

    // Set the axis titles
    Sigma1_Phi01_eta_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_Phi01_eta_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_Phi01_eta_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_Phi01_eta_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_Phi01_stereo_eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_Phi01_stereo_eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_Phi01_stereo_eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_Phi01_stereo_eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c717->Update();
///////////////////////////////////////////////////////Canvas #7701
    TLegend *leg7701 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c7701 = new TCanvas("c7701", "Sigma Phi01 per Eta", 800, 600);

    TGraphErrors *Sigma1_Phi01_Eta_Gauss = new TGraphErrors(14,ETA,sigma1_Phi01_Eta_Gauss,EETA,esigma1_Phi01_Eta_Gauss);
    Sigma1_Phi01_Eta_Gauss->SetTitle("Sigma Phi01 per Eta");
    Sigma1_Phi01_Eta_Gauss->SetMarkerStyle(22);
    Sigma1_Phi01_Eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_Phi01_Eta_Gauss->SetMarkerSize(1.5);
    leg7701->AddEntry(Sigma1_Phi01_Eta_Gauss, "Gauss", "p");

    Sigma1_Phi01_Eta_Gauss->Draw("APSAME");
    leg7701->Draw();

    // Set the axis titles
    Sigma1_Phi01_Eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_Phi01_Eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_Phi01_Eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_Phi01_Eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c7701->Update();
   ///////////////////////////////////////////////////////Canvas #82
    TLegend *leg82 = new TLegend(0.1,0.7,0.3,0.9);
    TCanvas *c82= new TCanvas("c82", "Sigma per PCB position x12 2 Layers", 800, 600);

    TGraphErrors *Sigma1_posx12pcb_Gauss = new TGraphErrors(8,PCB,sigma1_pos12pcb_Gauss,0,esigma1_pos12pcb_Gauss);
    Sigma1_posx12pcb_Gauss->SetTitle("Sigma per PCB position x12 2 Layers");
    Sigma1_posx12pcb_Gauss->SetMarkerStyle(22);
    Sigma1_posx12pcb_Gauss->SetMarkerColor(kOrange);
    Sigma1_posx12pcb_Gauss->SetMarkerSize(1.5);
    leg82->AddEntry(Sigma1_posx12pcb_Gauss, "Gauss", "p");
    
    /* TGraphErrors *Sigma1_posx12pcb_CB = new TGraphErrors(8,PCB,sigma1_pos12pcb_CB,0,esigma1_pos12pcb_CB);
    Sigma1_posx12pcb_CB->SetTitle("Sigma per PCB position x12 2 Layers");
    Sigma1_posx12pcb_CB->SetMarkerStyle(21);
    Sigma1_posx12pcb_CB->SetMarkerColor(kViolet);
    Sigma1_posx12pcb_CB->SetMarkerSize(1.5);
    leg82->AddEntry(Sigma1_posx12pcb_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_posx12pcb = new TGraphErrors(8,PCB,sigma1_pos12pcb,0,esigma1_pos12pcb);
    Sigma1_posx12pcb->SetTitle("Sigma per PCB position x12 2 Layers");
    Sigma1_posx12pcb->SetMarkerStyle(20);
    Sigma1_posx12pcb->SetMarkerColor(kRed);
    Sigma1_posx12pcb->SetMarkerSize(1.5);
    leg82->AddEntry(Sigma1_posx12pcb, "Double Gauss", "p"); */
    
    Sigma1_posx12pcb_Gauss->Draw("APSAME");
    //Sigma1_posx12pcb_CB->Draw("PSAME");
    //Sigma1_posx12pcb->Draw("APSAME");
    leg82->Draw();
    
    // Set the axis titles
    /* Sigma1_posx12pcb_CB->GetXaxis()->SetTitle("PCB");
    Sigma1_posx12pcb_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12pcb_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_posx12pcb->GetXaxis()->SetTitle("PCB");
    Sigma1_posx12pcb->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12pcb->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_posx12pcb_Gauss->GetXaxis()->SetTitle("PCB");
    Sigma1_posx12pcb_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12pcb_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(4,.5, "ATLAS Simulated Data");
    c82->Update();
   ///////////////////////////////////////////////////////Canvas #802
    TLegend *leg802 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c802 = new TCanvas("c802", "Sigma per eta position x12 2 Layers", 800, 600);

    TGraphErrors *Sigma1_posx12eta_Gauss = new TGraphErrors(14,ETA,sigma1_pos12eta_Gauss,EETA,esigma1_pos12eta_Gauss);
    Sigma1_posx12eta_Gauss->SetTitle("Sigma per eta position x12 2 Layers");
    Sigma1_posx12eta_Gauss->SetMarkerStyle(22);
    Sigma1_posx12eta_Gauss->SetMarkerColor(kOrange);
    Sigma1_posx12eta_Gauss->SetMarkerSize(1.5);
    leg802->AddEntry(Sigma1_posx12eta_Gauss, "Gauss", "p");
    
    /* TGraphErrors *Sigma1_posx12eta_CB = new TGraphErrors(14,ETA,sigma1_pos12eta_CB,EETA,esigma1_pos12eta_CB);
    Sigma1_posx12eta_CB->SetTitle("Sigma per eta position x12 2 Layers");
    Sigma1_posx12eta_CB->SetMarkerStyle(21);
    Sigma1_posx12eta_CB->SetMarkerColor(kViolet);
    Sigma1_posx12eta_CB->SetMarkerSize(1.5);
    leg802->AddEntry(Sigma1_posx12eta_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_posx12eta = new TGraphErrors(14,ETA,sigma1_pos12eta,EETA,esigma1_pos12eta);
    Sigma1_posx12eta->SetTitle("Sigma per eta position x12 2 Layers");
    Sigma1_posx12eta->SetMarkerStyle(20);
    Sigma1_posx12eta->SetMarkerColor(kRed);
    Sigma1_posx12eta->SetMarkerSize(1.5);
    leg802->AddEntry(Sigma1_posx12eta, "Double Gauss", "p"); */
    
    Sigma1_posx12eta_Gauss->Draw("APSAME");
    //Sigma1_posx12eta_CB->Draw("PSAME");
    //Sigma1_posx12eta->Draw("APSAME");
    leg802->Draw();
    
    // Set the axis titles
    /* Sigma1_posx12eta_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_posx12eta->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_posx12eta_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c802->Update();
      ///////////////////////////////////////////////////////Canvas #803
    TLegend *leg803 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c803 = new TCanvas("c803", "Sigma per eta position short x12 2 Layers", 800, 600);

    double_t ETA_s[7]={1.35,1.55,1.75,1.95,2.15,2.35,2.55};
    double_t EETA_s[7]={0.05,0.05,0.05,0.05,0.05,0.05,0.05};

    TGraphErrors *Sigma1_posx12eta_short_Gauss = new TGraphErrors(7,ETA_s,sigma1_pos12eta_short_Gauss,EETA_s,esigma1_pos12eta_short_Gauss);
    Sigma1_posx12eta_short_Gauss->SetTitle("Sigma per eta position short x12 2 Layers");
    Sigma1_posx12eta_short_Gauss->SetMarkerStyle(22);
    Sigma1_posx12eta_short_Gauss->SetMarkerColor(kOrange);
    Sigma1_posx12eta_short_Gauss->SetMarkerSize(1.5);
    leg803->AddEntry(Sigma1_posx12eta_short_Gauss, "Gauss", "p");
    
    /* TGraphErrors *Sigma1_posx12eta_short_CB = new TGraphErrors(7,ETA_s,sigma1_pos12eta_short_CB,EETA_s,esigma1_pos12eta_short_CB);
    Sigma1_posx12eta_short_CB->SetTitle("Sigma per eta position short x12 2 Layers");
    Sigma1_posx12eta_short_CB->SetMarkerStyle(21);
    Sigma1_posx12eta_short_CB->SetMarkerColor(kViolet);
    Sigma1_posx12eta_short_CB->SetMarkerSize(1.5);
    leg803->AddEntry(Sigma1_posx12eta_short_CB, "Crystal Ball", "p"); */

    /* TGraphErrors *Sigma1_posx12eta_short = new TGraphErrors(7,ETA_s,sigma1_pos12eta_short,EETA_s,esigma1_pos12eta_short);
    Sigma1_posx12eta_short->SetTitle("Sigma per eta position short x12 2 Layers");
    Sigma1_posx12eta_short->SetMarkerStyle(20);
    Sigma1_posx12eta_short->SetMarkerColor(kRed);
    Sigma1_posx12eta_short->SetMarkerSize(1.5);
    leg803->AddEntry(Sigma1_posx12eta_short, "Double Gauss", "p"); */
    
    Sigma1_posx12eta_short_Gauss->Draw("APSAME");
    //Sigma1_posx12eta_short_CB->Draw("PSAME");
    //Sigma1_posx12eta_short->Draw("APSAME");
    leg803->Draw();
    
    // Set the axis titles
    /* Sigma1_posx12eta_short_CB->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta_short_CB->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta_short_CB->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta_short_CB->GetYaxis()->SetTitle("Resolution (mm)"); */
    /* Sigma1_posx12eta_short->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta_short->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta_short->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta_short->GetYaxis()->SetTitle("Resolution (mm)"); */
    Sigma1_posx12eta_short_Gauss->GetXaxis()->SetTitle("ETA");
    Sigma1_posx12eta_short_Gauss->GetYaxis()->SetRangeUser(0,.6);
    Sigma1_posx12eta_short_Gauss->GetXaxis()->SetLimits(60./rad,3);
    Sigma1_posx12eta_short_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(110/rad,.5, "ATLAS Simulated Data");
    c803->Update();
   ///////////////////////////////////////////////////////Canvas #9
   /* TLegend *leg9 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c9 = new TCanvas("c9", "Sigma per position 2 Layers", 800, 600);

    double_t POS[6]={120,121,341,122,342,340};

    TGraphErrors *Sigma1_pos_CB = new TGraphErrors(6,POS,sigma1_pos_CB,0,esigma1_pos_CB);
    Sigma1_pos_CB->SetTitle("Sigma per position 2 Layers");
    Sigma1_pos_CB->SetMarkerStyle(21);
    Sigma1_pos_CB->SetMarkerColor(kViolet);
    Sigma1_pos_CB->SetMarkerSize(1.5);
    leg9->AddEntry(Sigma1_pos_CB, "Crystal Ball", "p");

    TGraphErrors *Sigma1_pos = new TGraphErrors(6,POS,sigma1_pos,0,esigma1_pos);
    Sigma1_pos->SetTitle("Sigma per eta position x12 2 Layers");
    Sigma1_pos->SetMarkerStyle(20);
    Sigma1_pos->SetMarkerColor(kRed);
    Sigma1_pos->SetMarkerSize(1.5);
    leg9->AddEntry(Sigma1_pos, "Double Gauss", "p");
    
    Sigma1_pos_CB->Draw("APSAME");
    Sigma1_pos->Draw("PSAME");
    leg9->Draw();
    
    // Set the axis titles
    Sigma1_pos_CB->GetXaxis()->SetTitle("POS");
    Sigma1_pos_CB->GetYaxis()->SetRangeUser(0,1);
    //Sigma1_pos_CB->GetXaxis()->SetLimits(0.,2.7);
    //Sigma1_pos_CB->GetYaxis()->SetTitle("Sigma");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(200,.5, "ATLAS Simulated Data");
    c9->Update();
   ///////////////////////////////////////////////////////Canvas #10
    TLegend *leg10 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c10 = new TCanvas("c10", "Sigma MS per position 2 Layers", 800, 600);

    TGraphErrors *Sigma1_MS_pos_CB = new TGraphErrors(6,POS,sigma1_MS_pos_CB,0,esigma1_MS_pos_CB);
    Sigma1_MS_pos_CB->SetTitle("Sigma MS per position 2 Layers");
    Sigma1_MS_pos_CB->SetMarkerStyle(21);
    Sigma1_MS_pos_CB->SetMarkerColor(kViolet);
    Sigma1_MS_pos_CB->SetMarkerSize(1.5);
    leg10->AddEntry(Sigma1_MS_pos_CB, "Crystal Ball Simulation", "p");

    TGraphErrors *Sigma1_MS_pos = new TGraphErrors(6,POS,sigma1_MS_pos,0,esigma1_MS_pos);
    //Sigma1_MS_pos->SetTitle("Sigma per eta position x12 2 Layers");
    Sigma1_MS_pos->SetMarkerStyle(20);
    Sigma1_MS_pos->SetMarkerColor(kRed);
    Sigma1_MS_pos->SetMarkerSize(1.5);
    leg10->AddEntry(Sigma1_MS_pos, "Double Gauss Simulation", "p");
    
    Sigma1_MS_pos_CB->Draw("APSAME");
    Sigma1_MS_pos->Draw("PSAME");
    leg10->Draw();
    
    // Set the axis titles
    Sigma1_MS_pos_CB->GetXaxis()->SetTitle("POS");
    Sigma1_MS_pos_CB->GetYaxis()->SetRangeUser(0.,0.6);
    //Sigma1_pos_CB->GetXaxis()->SetLimits(0.,2.7);
    //Sigma1_pos_CB->GetYaxis()->SetTitle("Sigma");
    gPad->SetTickx();
    gPad->SetTicky();
    c10->Update(); */
///////////////////////////////////////////////////////Canvas #11
    TLegend *leg11 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c11 = new TCanvas("c11", "Sigma per Phi MS", 800, 600);

    double_t PHI[8]={0.39375*rad,0.7875*rad,1.18125*rad,1.575*rad,1.96875*rad,2.3625*rad,2.75625*rad,3.15*rad};
    double_t EPHI[8]={0.00005*rad,0.00005*rad,0.00005*rad,0.00005*rad,0.00005*rad,0.00005*rad,0.00005*rad,0.00005*rad};

    TGraphErrors *Sigma1_MS_eta_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_MS_eta_Phi_Gauss,EPHI,esigma1_MS_eta_Phi_Gauss);//eta
    Sigma1_MS_eta_Phi_Gauss->SetTitle("Sigma per Phi MS");
    Sigma1_MS_eta_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_MS_eta_Phi_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_eta_Phi_Gauss->SetMarkerSize(1.5);
    leg11->AddEntry(Sigma1_MS_eta_Phi_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_MS_stereo_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_MS_stereo_Phi_Gauss,EPHI,esigma1_MS_stereo_Phi_Gauss);//stereo
    Sigma1_MS_stereo_Phi_Gauss->SetTitle("Sigma per Phi MS");
    Sigma1_MS_stereo_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_MS_stereo_Phi_Gauss->SetMarkerColor(kSpring);
    Sigma1_MS_stereo_Phi_Gauss->SetMarkerSize(1.5);
    leg11->AddEntry(Sigma1_MS_stereo_Phi_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_MS_stereo_Phi_Gauss->Draw("APSAME");
    Sigma1_MS_eta_Phi_Gauss->Draw("PSAME");
    leg11->Draw();
    
    // Set the axis titles
    Sigma1_MS_eta_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_MS_eta_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_MS_eta_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_MS_eta_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_MS_stereo_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_MS_stereo_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_MS_stereo_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_MS_stereo_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(80,.1, "ATLAS Simulated Data");
    c11->Update();
///////////////////////////////////////////////////////Canvas #1101
    TLegend *leg1101 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c1101 = new TCanvas("c1101", "Sigma per Phi MS", 800, 600);

    TGraphErrors *Sigma1_MS_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_MS_Phi_Gauss,EPHI,esigma1_MS_Phi_Gauss);
    Sigma1_MS_Phi_Gauss->SetTitle("Sigma per Phi MS");
    Sigma1_MS_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_MS_Phi_Gauss->SetMarkerColor(kOrange);
    Sigma1_MS_Phi_Gauss->SetMarkerSize(1.5);
    leg1101->AddEntry(Sigma1_MS_Phi_Gauss, "Gauss", "p");
   
    Sigma1_MS_Phi_Gauss->Draw("APSAME");
    leg1101->Draw();
    
    // Set the axis titles
    Sigma1_MS_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_MS_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_MS_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_MS_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(80,.1, "ATLAS Simulated Data");
    c1101->Update();
///////////////////////////////////////////////////////Canvas #12
    TLegend *leg12 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c12 = new TCanvas("c12", "Sigma per Phi", 800, 600);

    TGraphErrors *Sigma1_eta_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_eta_Phi_Gauss,EPHI,esigma1_eta_Phi_Gauss);//eta
    Sigma1_eta_Phi_Gauss->SetTitle("Sigma per Phi");
    Sigma1_eta_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_eta_Phi_Gauss->SetMarkerColor(kOrange);
    Sigma1_eta_Phi_Gauss->SetMarkerSize(1.5);
    leg12->AddEntry(Sigma1_eta_Phi_Gauss, "Eta Strips Gauss", "p");

    TGraphErrors *Sigma1_stereo_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_stereo_Phi_Gauss,EPHI,esigma1_stereo_Phi_Gauss);//stereo
    Sigma1_stereo_Phi_Gauss->SetTitle("Sigma per Phi");
    Sigma1_stereo_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_stereo_Phi_Gauss->SetMarkerColor(kSpring);
    Sigma1_stereo_Phi_Gauss->SetMarkerSize(1.5);
    leg12->AddEntry(Sigma1_stereo_Phi_Gauss, "Stereo Strips Gauss", "p");

    Sigma1_stereo_Phi_Gauss->Draw("APSAME");
    Sigma1_eta_Phi_Gauss->Draw("PSAME");
    leg12->Draw();
    
    // Set the axis titles
    Sigma1_eta_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_eta_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_eta_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_eta_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    Sigma1_stereo_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_stereo_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_stereo_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_stereo_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(80,.1, "ATLAS Simulated Data");
    c12->Update();
///////////////////////////////////////////////////////Canvas #1201
    TLegend *leg1201 = new TLegend(0.1,0.1,0.3,0.3);
    TCanvas *c1201 = new TCanvas("c1201", "Sigma per Phi", 800, 600);

    TGraphErrors *Sigma1_Phi_Gauss = new TGraphErrors(8,PHI,sigma1_Phi_Gauss,EPHI,esigma1_Phi_Gauss);
    Sigma1_Phi_Gauss->SetTitle("Sigma per Phi MS");
    Sigma1_Phi_Gauss->SetMarkerStyle(22);
    Sigma1_Phi_Gauss->SetMarkerColor(kOrange);
    Sigma1_Phi_Gauss->SetMarkerSize(1.5);
    leg1201->AddEntry(Sigma1_Phi_Gauss, "Gauss", "p");
   
    Sigma1_Phi_Gauss->Draw("APSAME");
    leg1201->Draw();
    
    // Set the axis titles
    Sigma1_Phi_Gauss->GetXaxis()->SetTitle("PHI");
    Sigma1_Phi_Gauss->GetYaxis()->SetRangeUser(0,.25);
    Sigma1_Phi_Gauss->GetXaxis()->SetLimits(0,3.3*rad);
    Sigma1_Phi_Gauss->GetYaxis()->SetTitle("Resolution (mm)");
    gPad->SetTickx();
    gPad->SetTicky();

    t1.DrawLatex(80,.1, "ATLAS Simulated Data");
    c1201->Update();

gStyle->SetOptStat(0);
gStyle->SetOptFit(11);

// At this point we Print our histograms
//MC
   c1->Print("MC/SigmaMSperPCB.pdf");
   c101->Print("MC/SigmaMSperPCB_AllStrips.pdf");
   c2->Print("MC/SigmaperPCB.pdf");
   c201->Print("MC/SigmaperPCB_AllStrips.pdf");
   c3->Print("MC/SigmaMSperTheta.pdf");
   c301->Print("MC/SigmaMSperTheta_AllStrips.pdf");
   c4->Print("MC/SigmaperTheta.pdf");
   c401->Print("MC/SigmaperTheta_AllStrips.pdf");
   c5->Print("MC/SigmaMSperEta.pdf");
   c501->Print("MC/SigmaMSperEta_AllStrips.pdf");
   c6->Print("MC/SigmaperEta.pdf");
   c601->Print("MC/SigmaperEta_AllStrips.pdf");
   c7->Print("MC/SigmaMSAllPhiSectorsperEta.pdf");
   c71->Print("MC/SigmaMSPhi01perEta.pdf");
   c701->Print("MC/SigmaMSPhi01perEta_AllStrips.pdf");
   c72->Print("MC/SigmaMSPhi02perEta.pdf");
   c702->Print("MC/SigmaMSPhi02perEta_AllStrips.pdf");
   c73->Print("MC/SigmaMSPhi03perEta.pdf");
   c703->Print("MC/SigmaMSPhi03perEta_AllStrips.pdf");
   c74->Print("MC/SigmaMSPhi04perEta.pdf");
   c704->Print("MC/SigmaMSPhi04perEta_AllStrips.pdf");
   c75->Print("MC/SigmaMSPhi05perEta.pdf");
   c705->Print("MC/SigmaMSPhi05perEta_AllStrips.pdf");
   c76->Print("MC/SigmaMSPhi06perEta.pdf");
   c706->Print("MC/SigmaMSPhi06perEta_AllStrips.pdf");
   c77->Print("MC/SigmaMSPhi07perEta.pdf");
   c707->Print("MC/SigmaMSPhi07perEta_AllStrips.pdf");
   c78->Print("MC/SigmaMSPhi08perEta.pdf");
   c708->Print("MC/SigmaMSPhi08perEta_AllStrips.pdf");
   c79->Print("MC/SigmaMSSmallSectorperEta.pdf");
   c710->Print("MC/SigmaMSLargeSectorperEta.pdf");
   c717->Print("MC/SigmaPhi01perEta.pdf");
   c7701->Print("MC/SigmaPhi01perEta_AllStrips.pdf");
   c82->Print("MC/SigmaperPCBPos12_2layers_etaStrips.pdf");
   c802->Print("MC/SigmaperETAPos12_2layers_etaStrips.pdf");
   c803->Print("MC/SigmaperETAPos12_short_2layers_etaStrips.pdf");
   //c9->Print("MC/SigmaperPOS_etaStrips.pdf");
   //c10->Print("MC/SigmaMSperPOS_etaStrips.pdf");
   c11->Print("MC/SigmaMSperPhi.pdf");
   c1101->Print("MC/SigmaMSperPhi_AllStrips.pdf");
   c12->Print("MC/SigmaperPhi.pdf");
   c1201->Print("MC/SigmaperPhi_AllStrips.pdf");
//Data
   /* c1->Print("Data/SigmaMSperPCB.pdf");
   c101->Print("Data/SigmaMSperPCB_AllStrips.pdf");
   c2->Print("Data/SigmaperPCB.pdf");
   c201->Print("Data/SigmaperPCB_AllStrips.pdf");
   c3->Print("Data/SigmaMSperTheta.pdf");
   c301->Print("Data/SigmaMSperTheta_AllStrips.pdf");
   c4->Print("Data/SigmaperTheta.pdf");
   c401->Print("Data/SigmaperTheta_AllStrips.pdf");
   c5->Print("Data/SigmaMSperEta.pdf");
   c501->Print("Data/SigmaMSperEta_AllStrips.pdf");
   c6->Print("Data/SigmaperEta.pdf");
   c601->Print("Data/SigmaperEta_AllStrips.pdf");
   c82->Print("Data/SigmaperPCBPos12_2layers_etaStrips.pdf");
   c802->Print("Data/SigmaperETAPos12_2layers_etaStrips.pdf");
   c9->Print("Data/SigmaperPOS_etaStrips.pdf"); */
   //c10->Print("Data/SigmaMSperPOS_etaStrips.pdf");

//ETA Position x12
   h_x12_eta01->Write();
   h_x12_eta02->Write();
   h_x12_eta03->Write();
   h_x12_eta04->Write();
   h_x12_eta05->Write();
   h_x12_eta06->Write();
   h_x12_eta07->Write();
   h_x12_eta08->Write();
   h_x12_eta09->Write();
   h_x12_eta10->Write();
   h_x12_eta11->Write();
   h_x12_eta12->Write();
   h_x12_eta13->Write();
   h_x12_eta14->Write();
//ETA Position short x12
   h_x12_eta1->Write();
   h_x12_eta2->Write();
   h_x12_eta3->Write();
   h_x12_eta4->Write();
   h_x12_eta5->Write();
   h_x12_eta6->Write();
   h_x12_eta7->Write();
//PCB Position x12
   h_x12_qpcb01->Write();
   h_x12_qpcb02->Write();
   h_x12_qpcb03->Write();
   h_x12_qpcb04->Write();
   h_x12_qpcb05->Write();
   h_x12_qpcb06->Write();
   h_x12_qpcb07->Write();
   h_x12_qpcb08->Write();   
//POS
   h_x12R->Write();
   h_x121R->Write();
   h_x341R->Write();
   h_x122R->Write();
   h_x342R->Write();
   h_x34R->Write();

   /* h_x12R_MS->Write();
   h_x121R_MS->Write();
   h_x341R_MS->Write();
   h_x122R_MS->Write();
   h_x342R_MS->Write();
   h_x34R_MS->Write(); */

//PCB
   h_mmOnTrackResidualTrack_PCB1->Write();
   h_eta_mmOnTrackResidualTrack_PCB1->Write();
   h_stereo_mmOnTrackResidualTrack_PCB1->Write();
	h_mmOnTrackResidualTrack_PCB2->Write();
   h_eta_mmOnTrackResidualTrack_PCB2->Write();
   h_stereo_mmOnTrackResidualTrack_PCB2->Write();
	h_mmOnTrackResidualTrack_PCB3->Write();
   h_eta_mmOnTrackResidualTrack_PCB3->Write();
   h_stereo_mmOnTrackResidualTrack_PCB3->Write();
	h_mmOnTrackResidualTrack_PCB4->Write();
   h_eta_mmOnTrackResidualTrack_PCB4->Write();
   h_stereo_mmOnTrackResidualTrack_PCB4->Write();
	h_mmOnTrackResidualTrack_PCB5->Write();
   h_eta_mmOnTrackResidualTrack_PCB5->Write();
   h_stereo_mmOnTrackResidualTrack_PCB5->Write();
	h_mmOnTrackResidualTrack_PCB6->Write();
   h_eta_mmOnTrackResidualTrack_PCB6->Write();
   h_stereo_mmOnTrackResidualTrack_PCB6->Write();
	h_mmOnTrackResidualTrack_PCB7->Write();
   h_eta_mmOnTrackResidualTrack_PCB7->Write();
   h_stereo_mmOnTrackResidualTrack_PCB7->Write();
	h_mmOnTrackResidualTrack_PCB8->Write();
   h_eta_mmOnTrackResidualTrack_PCB8->Write();
   h_stereo_mmOnTrackResidualTrack_PCB8->Write();

   h_mmOnTrackResidualTrackMS_PCB1->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB1->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB1->Write();
	h_mmOnTrackResidualTrackMS_PCB2->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB2->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB2->Write();
	h_mmOnTrackResidualTrackMS_PCB3->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB3->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB3->Write();
	h_mmOnTrackResidualTrackMS_PCB4->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB4->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB4->Write();
	h_mmOnTrackResidualTrackMS_PCB5->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB5->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB5->Write();
	h_mmOnTrackResidualTrackMS_PCB6->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB6->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB6->Write();
	h_mmOnTrackResidualTrackMS_PCB7->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB7->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB7->Write();
	h_mmOnTrackResidualTrackMS_PCB8->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB8->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB8->Write();

//eta
   h_mmOnTrackResidualTrack_eta1->Write();
   h_eta_mmOnTrackResidualTrack_eta1->Write();
   h_stereo_mmOnTrackResidualTrack_eta1->Write();
	h_mmOnTrackResidualTrack_eta2->Write();
   h_eta_mmOnTrackResidualTrack_eta2->Write();
   h_stereo_mmOnTrackResidualTrack_eta2->Write();
   h_mmOnTrackResidualTrack_eta3->Write();
   h_eta_mmOnTrackResidualTrack_eta3->Write();
   h_stereo_mmOnTrackResidualTrack_eta3->Write();
   h_mmOnTrackResidualTrack_eta4->Write();
   h_eta_mmOnTrackResidualTrack_eta4->Write();
   h_stereo_mmOnTrackResidualTrack_eta4->Write();
   h_mmOnTrackResidualTrack_eta5->Write();
   h_eta_mmOnTrackResidualTrack_eta5->Write();
   h_stereo_mmOnTrackResidualTrack_eta5->Write();
   h_mmOnTrackResidualTrack_eta6->Write();
   h_eta_mmOnTrackResidualTrack_eta6->Write();
   h_stereo_mmOnTrackResidualTrack_eta6->Write();
   h_mmOnTrackResidualTrack_eta7->Write();
   h_eta_mmOnTrackResidualTrack_eta7->Write();
   h_stereo_mmOnTrackResidualTrack_eta7->Write();
   h_mmOnTrackResidualTrack_eta8->Write();
   h_eta_mmOnTrackResidualTrack_eta8->Write();
   h_stereo_mmOnTrackResidualTrack_eta8->Write();
   h_mmOnTrackResidualTrack_eta9->Write();
   h_eta_mmOnTrackResidualTrack_eta9->Write();
   h_stereo_mmOnTrackResidualTrack_eta9->Write();
   h_mmOnTrackResidualTrack_eta10->Write();
   h_eta_mmOnTrackResidualTrack_eta10->Write();
   h_stereo_mmOnTrackResidualTrack_eta10->Write();
   h_mmOnTrackResidualTrack_eta11->Write();
   h_eta_mmOnTrackResidualTrack_eta11->Write();
   h_stereo_mmOnTrackResidualTrack_eta11->Write();
   h_mmOnTrackResidualTrack_eta12->Write();
   h_eta_mmOnTrackResidualTrack_eta12->Write();
   h_stereo_mmOnTrackResidualTrack_eta12->Write();
   h_mmOnTrackResidualTrack_eta13->Write();
   h_eta_mmOnTrackResidualTrack_eta13->Write();
   h_stereo_mmOnTrackResidualTrack_eta13->Write();
   h_mmOnTrackResidualTrack_eta14->Write();
   h_eta_mmOnTrackResidualTrack_eta14->Write();
   h_stereo_mmOnTrackResidualTrack_eta14->Write();
   
   h_mmOnTrackResidualTrackMS_eta1->Write();
   h_eta_mmOnTrackResidualTrackMS_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta1->Write();
	h_mmOnTrackResidualTrackMS_eta2->Write();
   h_eta_mmOnTrackResidualTrackMS_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta2->Write();
   h_mmOnTrackResidualTrackMS_eta3->Write();
   h_eta_mmOnTrackResidualTrackMS_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta3->Write();
   h_mmOnTrackResidualTrackMS_eta4->Write();
   h_eta_mmOnTrackResidualTrackMS_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta4->Write();
   h_mmOnTrackResidualTrackMS_eta5->Write();
   h_eta_mmOnTrackResidualTrackMS_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta5->Write();
   h_mmOnTrackResidualTrackMS_eta6->Write();
   h_eta_mmOnTrackResidualTrackMS_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta6->Write();
   h_mmOnTrackResidualTrackMS_eta7->Write();
   h_eta_mmOnTrackResidualTrackMS_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta7->Write();
   h_mmOnTrackResidualTrackMS_eta8->Write();
   h_eta_mmOnTrackResidualTrackMS_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta8->Write();
   h_mmOnTrackResidualTrackMS_eta9->Write();
   h_eta_mmOnTrackResidualTrackMS_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta9->Write();
   h_mmOnTrackResidualTrackMS_eta10->Write();
   h_eta_mmOnTrackResidualTrackMS_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta10->Write();
   h_mmOnTrackResidualTrackMS_eta11->Write();
   h_eta_mmOnTrackResidualTrackMS_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta11->Write();
   h_mmOnTrackResidualTrackMS_eta12->Write();
   h_eta_mmOnTrackResidualTrackMS_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta12->Write();
   h_mmOnTrackResidualTrackMS_eta13->Write();
   h_eta_mmOnTrackResidualTrackMS_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta13->Write();
   h_mmOnTrackResidualTrackMS_eta14->Write();
   h_eta_mmOnTrackResidualTrackMS_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMS_eta14->Write();
///Phi01
   h_mmOnTrackResidualTrackPhi01_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta1->Write();
	h_mmOnTrackResidualTrackPhi01_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta2->Write();
   h_mmOnTrackResidualTrackPhi01_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta3->Write();
   h_mmOnTrackResidualTrackPhi01_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta4->Write();
   h_mmOnTrackResidualTrackPhi01_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta5->Write();
   h_mmOnTrackResidualTrackPhi01_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta6->Write();
   h_mmOnTrackResidualTrackPhi01_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta7->Write();
   h_mmOnTrackResidualTrackPhi01_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta8->Write();
   h_mmOnTrackResidualTrackPhi01_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta9->Write();
   h_mmOnTrackResidualTrackPhi01_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta10->Write();
   h_mmOnTrackResidualTrackPhi01_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta11->Write();
   h_mmOnTrackResidualTrackPhi01_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta12->Write();
   h_mmOnTrackResidualTrackPhi01_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta13->Write();
   h_mmOnTrackResidualTrackPhi01_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi01_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi01_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi01_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi01_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi01_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi01_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi01_eta14->Write();
///Phi02
   h_mmOnTrackResidualTrackPhi02_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta1->Write();
	h_mmOnTrackResidualTrackPhi02_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta2->Write();
   h_mmOnTrackResidualTrackPhi02_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta3->Write();
   h_mmOnTrackResidualTrackPhi02_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta4->Write();
   h_mmOnTrackResidualTrackPhi02_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta5->Write();
   h_mmOnTrackResidualTrackPhi02_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta6->Write();
   h_mmOnTrackResidualTrackPhi02_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta7->Write();
   h_mmOnTrackResidualTrackPhi02_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta8->Write();
   h_mmOnTrackResidualTrackPhi02_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta9->Write();
   h_mmOnTrackResidualTrackPhi02_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta10->Write();
   h_mmOnTrackResidualTrackPhi02_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta11->Write();
   h_mmOnTrackResidualTrackPhi02_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta12->Write();
   h_mmOnTrackResidualTrackPhi02_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta13->Write();
   h_mmOnTrackResidualTrackPhi02_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi02_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi02_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi02_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi02_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi02_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi02_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi02_eta14->Write();
///Phi03
   h_mmOnTrackResidualTrackPhi03_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta1->Write();
	h_mmOnTrackResidualTrackPhi03_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta2->Write();
   h_mmOnTrackResidualTrackPhi03_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta3->Write();
   h_mmOnTrackResidualTrackPhi03_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta4->Write();
   h_mmOnTrackResidualTrackPhi03_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta5->Write();
   h_mmOnTrackResidualTrackPhi03_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta6->Write();
   h_mmOnTrackResidualTrackPhi03_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta7->Write();
   h_mmOnTrackResidualTrackPhi03_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta8->Write();
   h_mmOnTrackResidualTrackPhi03_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta9->Write();
   h_mmOnTrackResidualTrackPhi03_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta10->Write();
   h_mmOnTrackResidualTrackPhi03_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta11->Write();
   h_mmOnTrackResidualTrackPhi03_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta12->Write();
   h_mmOnTrackResidualTrackPhi03_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta13->Write();
   h_mmOnTrackResidualTrackPhi03_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi03_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi03_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi03_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi03_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi03_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi03_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi03_eta14->Write();
///Phi04
   h_mmOnTrackResidualTrackPhi04_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta1->Write();
	h_mmOnTrackResidualTrackPhi04_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta2->Write();
   h_mmOnTrackResidualTrackPhi04_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta3->Write();
   h_mmOnTrackResidualTrackPhi04_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta4->Write();
   h_mmOnTrackResidualTrackPhi04_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta5->Write();
   h_mmOnTrackResidualTrackPhi04_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta6->Write();
   h_mmOnTrackResidualTrackPhi04_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta7->Write();
   h_mmOnTrackResidualTrackPhi04_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta8->Write();
   h_mmOnTrackResidualTrackPhi04_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta9->Write();
   h_mmOnTrackResidualTrackPhi04_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta10->Write();
   h_mmOnTrackResidualTrackPhi04_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta11->Write();
   h_mmOnTrackResidualTrackPhi04_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta12->Write();
   h_mmOnTrackResidualTrackPhi04_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta13->Write();
   h_mmOnTrackResidualTrackPhi04_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi04_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi04_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi04_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi04_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi04_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi04_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi04_eta14->Write();
///Phi05
   h_mmOnTrackResidualTrackPhi05_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta1->Write();
	h_mmOnTrackResidualTrackPhi05_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta2->Write();
   h_mmOnTrackResidualTrackPhi05_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta3->Write();
   h_mmOnTrackResidualTrackPhi05_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta4->Write();
   h_mmOnTrackResidualTrackPhi05_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta5->Write();
   h_mmOnTrackResidualTrackPhi05_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta6->Write();
   h_mmOnTrackResidualTrackPhi05_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta7->Write();
   h_mmOnTrackResidualTrackPhi05_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta8->Write();
   h_mmOnTrackResidualTrackPhi05_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta9->Write();
   h_mmOnTrackResidualTrackPhi05_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta10->Write();
   h_mmOnTrackResidualTrackPhi05_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta11->Write();
   h_mmOnTrackResidualTrackPhi05_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta12->Write();
   h_mmOnTrackResidualTrackPhi05_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta13->Write();
   h_mmOnTrackResidualTrackPhi05_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi05_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi05_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi05_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi05_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi05_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi05_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi05_eta14->Write();
///Phi06
   h_mmOnTrackResidualTrackPhi06_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta1->Write();
	h_mmOnTrackResidualTrackPhi06_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta2->Write();
   h_mmOnTrackResidualTrackPhi06_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta3->Write();
   h_mmOnTrackResidualTrackPhi06_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta4->Write();
   h_mmOnTrackResidualTrackPhi06_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta5->Write();
   h_mmOnTrackResidualTrackPhi06_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta6->Write();
   h_mmOnTrackResidualTrackPhi06_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta7->Write();
   h_mmOnTrackResidualTrackPhi06_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta8->Write();
   h_mmOnTrackResidualTrackPhi06_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta9->Write();
   h_mmOnTrackResidualTrackPhi06_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta10->Write();
   h_mmOnTrackResidualTrackPhi06_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta11->Write();
   h_mmOnTrackResidualTrackPhi06_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta12->Write();
   h_mmOnTrackResidualTrackPhi06_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta13->Write();
   h_mmOnTrackResidualTrackPhi06_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi06_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi06_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi06_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi06_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi06_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi06_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi06_eta14->Write();
///Phi07
   h_mmOnTrackResidualTrackPhi07_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta1->Write();
	h_mmOnTrackResidualTrackPhi07_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta2->Write();
   h_mmOnTrackResidualTrackPhi07_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta3->Write();
   h_mmOnTrackResidualTrackPhi07_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta4->Write();
   h_mmOnTrackResidualTrackPhi07_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta5->Write();
   h_mmOnTrackResidualTrackPhi07_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta6->Write();
   h_mmOnTrackResidualTrackPhi07_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta7->Write();
   h_mmOnTrackResidualTrackPhi07_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta8->Write();
   h_mmOnTrackResidualTrackPhi07_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta9->Write();
   h_mmOnTrackResidualTrackPhi07_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta10->Write();
   h_mmOnTrackResidualTrackPhi07_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta11->Write();
   h_mmOnTrackResidualTrackPhi07_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta12->Write();
   h_mmOnTrackResidualTrackPhi07_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta13->Write();
   h_mmOnTrackResidualTrackPhi07_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi07_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi07_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi07_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi07_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi07_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi07_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi07_eta14->Write();
///Phi08
   h_mmOnTrackResidualTrackPhi08_eta1->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta1->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta1->Write();
	h_mmOnTrackResidualTrackPhi08_eta2->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta2->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta2->Write();
   h_mmOnTrackResidualTrackPhi08_eta3->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta3->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta3->Write();
   h_mmOnTrackResidualTrackPhi08_eta4->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta4->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta4->Write();
   h_mmOnTrackResidualTrackPhi08_eta5->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta5->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta5->Write();
   h_mmOnTrackResidualTrackPhi08_eta6->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta6->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta6->Write();
   h_mmOnTrackResidualTrackPhi08_eta7->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta7->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta7->Write();
   h_mmOnTrackResidualTrackPhi08_eta8->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta8->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta8->Write();
   h_mmOnTrackResidualTrackPhi08_eta9->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta9->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta9->Write();
   h_mmOnTrackResidualTrackPhi08_eta10->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta10->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta10->Write();
   h_mmOnTrackResidualTrackPhi08_eta11->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta11->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta11->Write();
   h_mmOnTrackResidualTrackPhi08_eta12->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta12->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta12->Write();
   h_mmOnTrackResidualTrackPhi08_eta13->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta13->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta13->Write();
   h_mmOnTrackResidualTrackPhi08_eta14->Write();
   h_eta_mmOnTrackResidualTrackPhi08_eta14->Write();
   h_stereo_mmOnTrackResidualTrackPhi08_eta14->Write();
   
   h_mmOnTrackResidualTrackMSPhi08_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta1->Write();
	h_mmOnTrackResidualTrackMSPhi08_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta2->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta3->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta4->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta5->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta6->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta7->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta8->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta9->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta10->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta11->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta12->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta13->Write();
   h_mmOnTrackResidualTrackMSPhi08_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSPhi08_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSPhi08_eta14->Write();
///LargeSector
   h_mmOnTrackResidualTrackLargeSector_eta1->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta1->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta1->Write();
	h_mmOnTrackResidualTrackLargeSector_eta2->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta2->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta2->Write();
   h_mmOnTrackResidualTrackLargeSector_eta3->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta3->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta3->Write();
   h_mmOnTrackResidualTrackLargeSector_eta4->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta4->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta4->Write();
   h_mmOnTrackResidualTrackLargeSector_eta5->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta5->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta5->Write();
   h_mmOnTrackResidualTrackLargeSector_eta6->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta6->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta6->Write();
   h_mmOnTrackResidualTrackLargeSector_eta7->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta7->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta7->Write();
   h_mmOnTrackResidualTrackLargeSector_eta8->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta8->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta8->Write();
   h_mmOnTrackResidualTrackLargeSector_eta9->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta9->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta9->Write();
   h_mmOnTrackResidualTrackLargeSector_eta10->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta10->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta10->Write();
   h_mmOnTrackResidualTrackLargeSector_eta11->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta11->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta11->Write();
   h_mmOnTrackResidualTrackLargeSector_eta12->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta12->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta12->Write();
   h_mmOnTrackResidualTrackLargeSector_eta13->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta13->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta13->Write();
   h_mmOnTrackResidualTrackLargeSector_eta14->Write();
   h_eta_mmOnTrackResidualTrackLargeSector_eta14->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta14->Write();
   
   h_mmOnTrackResidualTrackMSLargeSector_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1->Write();
	h_mmOnTrackResidualTrackMSLargeSector_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13->Write();
   h_mmOnTrackResidualTrackMSLargeSector_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSLargeSector_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14->Write();
///SmallSector
   h_mmOnTrackResidualTrackSmallSector_eta1->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta1->Write();
   h_stereo_mmOnTrackResidualTrackLargeSector_eta1->Write();
	h_mmOnTrackResidualTrackSmallSector_eta2->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta2->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta2->Write();
   h_mmOnTrackResidualTrackSmallSector_eta3->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta3->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta3->Write();
   h_mmOnTrackResidualTrackSmallSector_eta4->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta4->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta4->Write();
   h_mmOnTrackResidualTrackSmallSector_eta5->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta5->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta5->Write();
   h_mmOnTrackResidualTrackSmallSector_eta6->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta6->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta6->Write();
   h_mmOnTrackResidualTrackSmallSector_eta7->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta7->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta7->Write();
   h_mmOnTrackResidualTrackSmallSector_eta8->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta8->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta8->Write();
   h_mmOnTrackResidualTrackSmallSector_eta9->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta9->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta9->Write();
   h_mmOnTrackResidualTrackSmallSector_eta10->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta10->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta10->Write();
   h_mmOnTrackResidualTrackSmallSector_eta11->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta11->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta11->Write();
   h_mmOnTrackResidualTrackSmallSector_eta12->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta12->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta12->Write();
   h_mmOnTrackResidualTrackSmallSector_eta13->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta13->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta13->Write();
   h_mmOnTrackResidualTrackSmallSector_eta14->Write();
   h_eta_mmOnTrackResidualTrackSmallSector_eta14->Write();
   h_stereo_mmOnTrackResidualTrackSmallSector_eta14->Write();
   
   h_mmOnTrackResidualTrackMSSmallSector_eta1->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta1->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1->Write();
	h_mmOnTrackResidualTrackMSSmallSector_eta2->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta2->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta3->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta3->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta4->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta4->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta5->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta5->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta6->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta6->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta7->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta7->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta8->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta8->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta9->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta9->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta10->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta10->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta11->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta11->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta12->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta12->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta13->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta13->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13->Write();
   h_mmOnTrackResidualTrackMSSmallSector_eta14->Write();
   h_eta_mmOnTrackResidualTrackMSSmallSector_eta14->Write();
   h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14->Write();
//theta
   h_mmOnTrackResidualTrack_PCB1_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB1_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB1_theta->Write();
	h_mmOnTrackResidualTrack_PCB2_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB2_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB2_theta->Write();
	h_mmOnTrackResidualTrack_PCB3_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB3_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB3_theta->Write();
	h_mmOnTrackResidualTrack_PCB4_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB4_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB4_theta->Write();
	h_mmOnTrackResidualTrack_PCB5_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB5_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB5_theta->Write();
	h_mmOnTrackResidualTrack_PCB6_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB6_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB6_theta->Write();
	h_mmOnTrackResidualTrack_PCB7_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB7_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB7_theta->Write();
	h_mmOnTrackResidualTrack_PCB8_theta->Write();
   h_eta_mmOnTrackResidualTrack_PCB8_theta->Write();
   h_stereo_mmOnTrackResidualTrack_PCB8_theta->Write();
   
   h_mmOnTrackResidualTrackMS_PCB1_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB1_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB1_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB2_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB2_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB2_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB3_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB3_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB3_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB4_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB4_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB4_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB5_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB5_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB5_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB6_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB6_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB6_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB7_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB7_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB7_theta->Write();
	h_mmOnTrackResidualTrackMS_PCB8_theta->Write();
   h_eta_mmOnTrackResidualTrackMS_PCB8_theta->Write();
   h_stereo_mmOnTrackResidualTrackMS_PCB8_theta->Write();
//phi
   h_mmOnTrackResidualTrack_phi1->Write();
   h_eta_mmOnTrackResidualTrack_phi1->Write();
   h_stereo_mmOnTrackResidualTrack_phi1->Write();
	h_mmOnTrackResidualTrack_phi2->Write();
   h_eta_mmOnTrackResidualTrack_phi2->Write();
   h_stereo_mmOnTrackResidualTrack_phi2->Write();
	h_mmOnTrackResidualTrack_phi3->Write();
   h_eta_mmOnTrackResidualTrack_phi3->Write();
   h_stereo_mmOnTrackResidualTrack_phi3->Write();
	h_mmOnTrackResidualTrack_phi4->Write();
   h_eta_mmOnTrackResidualTrack_phi4->Write();
   h_stereo_mmOnTrackResidualTrack_phi4->Write();
	h_mmOnTrackResidualTrack_phi5->Write();
   h_eta_mmOnTrackResidualTrack_phi5->Write();
   h_stereo_mmOnTrackResidualTrack_phi5->Write();
	h_mmOnTrackResidualTrack_phi6->Write();
   h_eta_mmOnTrackResidualTrack_phi6->Write();
   h_stereo_mmOnTrackResidualTrack_phi6->Write();
	h_mmOnTrackResidualTrack_phi7->Write();
   h_eta_mmOnTrackResidualTrack_phi7->Write();
   h_stereo_mmOnTrackResidualTrack_phi7->Write();
	h_mmOnTrackResidualTrack_phi8->Write();
   h_eta_mmOnTrackResidualTrack_phi8->Write();
   h_stereo_mmOnTrackResidualTrack_phi8->Write();
   
   h_mmOnTrackResidualTrackMS_phi1->Write();
   h_eta_mmOnTrackResidualTrackMS_phi1->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi1->Write();
	h_mmOnTrackResidualTrackMS_phi2->Write();
   h_eta_mmOnTrackResidualTrackMS_phi2->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi2->Write();
	h_mmOnTrackResidualTrackMS_phi3->Write();
   h_eta_mmOnTrackResidualTrackMS_phi3->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi3->Write();
	h_mmOnTrackResidualTrackMS_phi4->Write();
   h_eta_mmOnTrackResidualTrackMS_phi4->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi4->Write();
	h_mmOnTrackResidualTrackMS_phi5->Write();
   h_eta_mmOnTrackResidualTrackMS_phi5->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi5->Write();
	h_mmOnTrackResidualTrackMS_phi6->Write();
   h_eta_mmOnTrackResidualTrackMS_phi6->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi6->Write();
	h_mmOnTrackResidualTrackMS_phi7->Write();
   h_eta_mmOnTrackResidualTrackMS_phi7->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi7->Write();
	h_mmOnTrackResidualTrackMS_phi8->Write();
   h_eta_mmOnTrackResidualTrackMS_phi8->Write();
   h_stereo_mmOnTrackResidualTrackMS_phi8->Write();

//graphs
   //c1
   /* Sigma1_MS_eta_Gauss->Write();
   Sigma1_MS_stereo_Gauss->Write(); */
   Sigma1_MS_eta_CB->Write();
   Sigma1_MS_stereo_CB->Write();
   /* Sigma1_MS_eta->Write();
   Sigma1_MS_stereo->Write(); */
   //c101
   //Sigma1_MS_Gauss->Write();
   Sigma1_MS_CB->Write();
   //Sigma1_MS->Write();
   //c2
   /* Sigma1_eta_Gauss->Write();
   Sigma1_stereo_Gauss->Write(); */
   Sigma1_eta_CB->Write();
   Sigma1_stereo_CB->Write();
   /* Sigma1_eta->Write();
   Sigma1_stereo->Write(); */
   //c201
   //Sigma1_Gauss->Write();
   Sigma1_CB->Write();
   //Sigma1->Write();
   //c3
   Sigma1_MS_eta_theta_Gauss->Write();
   Sigma1_MS_stereo_theta_Gauss->Write();
   /* Sigma1_MS_eta_theta_CB->Write();
   Sigma1_MS_stereo_theta_CB->Write(); */
   /* Sigma1_MS_eta_theta->Write();
   Sigma1_MS_stereo_theta->Write(); */
   //c301
   Sigma1_MS_theta_Gauss->Write();
   //Sigma1_MS_theta_CB->Write();
   //Sigma1_MS_theta->Write();
   //c4
   Sigma1_eta_theta_Gauss->Write();
   Sigma1_stereo_theta_Gauss->Write();
   /* Sigma1_eta_theta_CB->Write();
   Sigma1_stereo_theta_CB->Write(); */
   /* Sigma1_eta_theta->Write();
   Sigma1_stereo_theta->Write(); */
   //c401
   Sigma1_theta_Gauss->Write();
   //Sigma1_theta_CB->Write();
   //Sigma1_theta->Write();
   //c5
   Sigma1_MS_eta_eta_Gauss->Write();
   Sigma1_MS_stereo_eta_Gauss->Write();
   /* Sigma1_MS_eta_eta_CB->Write();
   Sigma1_MS_stereo_eta_CB->Write(); */
   /* Sigma1_MS_eta_eta->Write();
   Sigma1_MS_stereo_eta->Write(); */
   //c501
   Sigma1_MS__eta_Gauss->Write();
   //Sigma1_MS__eta_CB->Write();
   //Sigma1_MS__eta->Write();
   //c6
   Sigma1_eta_eta_Gauss->Write();
   Sigma1_stereo_eta_Gauss->Write();
   /* Sigma1_eta_eta_CB->Write();
   Sigma1_stereo_eta_CB->Write(); */
   /* Sigma1_eta_eta->Write();
   Sigma1_stereo_eta->Write(); */
   //c601
   Sigma1__eta_Gauss->Write();
   Sigma1__eta_CB->Write();
   Sigma1__eta->Write();
   //71
   Sigma1_MS_Phi01_eta_eta_Gauss->Write();
   Sigma1_MS_Phi01_stereo_eta_Gauss->Write();
   //72
   Sigma1_MS_Phi02_eta_eta_Gauss->Write();
   Sigma1_MS_Phi02_stereo_eta_Gauss->Write();
   //73
   Sigma1_MS_Phi03_eta_eta_Gauss->Write();
   Sigma1_MS_Phi03_stereo_eta_Gauss->Write();
   //74
   Sigma1_MS_Phi04_eta_eta_Gauss->Write();
   Sigma1_MS_Phi04_stereo_eta_Gauss->Write();
   //75
   Sigma1_MS_Phi05_eta_eta_Gauss->Write();
   Sigma1_MS_Phi05_stereo_eta_Gauss->Write();
   //76
   Sigma1_MS_Phi06_eta_eta_Gauss->Write();
   Sigma1_MS_Phi06_stereo_eta_Gauss->Write();
   //77
   Sigma1_MS_Phi07_eta_eta_Gauss->Write();
   Sigma1_MS_Phi07_stereo_eta_Gauss->Write();
   //78
   Sigma1_MS_Phi08_eta_eta_Gauss->Write();
   Sigma1_MS_Phi08_stereo_eta_Gauss->Write();
   //79
   Sigma1_MS_SmallSector_eta_eta_Gauss->Write();
   Sigma1_MS_SmallSector_stereo_eta_Gauss->Write();
   //710
   Sigma1_MS_LargeSector_eta_eta_Gauss->Write();
   Sigma1_MS_LargeSector_stereo_eta_Gauss->Write();
   //701
   Sigma1_MS_Phi01_Eta_Gauss->Write();
   //702
   Sigma1_MS_Phi02_Eta_Gauss->Write();
   //703
   Sigma1_MS_Phi03_Eta_Gauss->Write();
   //704
   Sigma1_MS_Phi04_Eta_Gauss->Write();
   //705
   Sigma1_MS_Phi05_Eta_Gauss->Write();
   //706
   Sigma1_MS_Phi06_Eta_Gauss->Write();
   //707
   Sigma1_MS_Phi07_Eta_Gauss->Write();
   //708
   Sigma1_MS_Phi08_Eta_Gauss->Write();
   //717
   Sigma1_Phi01_eta_eta_Gauss->Write();
   Sigma1_Phi01_stereo_eta_Gauss->Write();
   //7701
   Sigma1_Phi01_Eta_Gauss->Write();
   //c82
   Sigma1_posx12pcb_Gauss->Write();
   //Sigma1_posx12pcb_CB->Write();
   //Sigma1_posx12pcb->Write();
   //C802
   Sigma1_posx12eta_Gauss->Write();
   //Sigma1_posx12eta_CB->Write();
   //Sigma1_posx12eta->Write();
   //C803
   Sigma1_posx12eta_short_Gauss->Write();
   //Sigma1_posx12eta_short_CB->Write();
   //Sigma1_posx12eta_short->Write();
   //c9
   /* Sigma1_pos_CB->Write();
   Sigma1_pos->Write(); */
   //c11
   Sigma1_MS_eta_Phi_Gauss->Write();
   Sigma1_MS_stereo_Phi_Gauss->Write();
   //c1101
   Sigma1_MS_Phi_Gauss->Write();
   //c12
   Sigma1_eta_Phi_Gauss->Write();
   Sigma1_stereo_Phi_Gauss->Write();
   //c1201
   Sigma1_Phi_Gauss->Write();
 
   rfile->Close();
   f1->Close();

}

//----------------------------------------------------------------------------------
void FitPol1(TGraph* graph1,TGraph* graph2)
{
   TF1* pol1F = new TF1("pol1F", "[0]*x +[2]");

   pol1F->SetParameters(1.0,1.0);

   graph1->Fit(pol1F, "");
   graph2->Fit(pol1F, "+");
}

void FitPol1_multi(TGraph* graph1,TGraph* graph2,TGraph* graph3,TGraph* graph4)
{
   TF1* pol1F = new TF1("pol1F", "[0]*x +[2]");

   pol1F->SetParameters(1.0,1.0);

   graph1->Fit(pol1F, "");
   graph2->Fit(pol1F, "");
   graph3->Fit(pol1F, "");
   graph4->Fit(pol1F, "");
}

Double_t gaussian(Double_t *x, Double_t *par)
{
  return par[0] * exp(-(TMath::Power((x[0] - par[1])/par[2], 2)/2.0));
}
Double_t gaussianCombined(Double_t *x, Double_t *par)
{
 
  return par[0]*((par[1] * exp(-(TMath::Power((x[0] - par[2])/par[3], 2)/2.0))/(par[3]*sqrt(2*TMath::Pi()))) + ((1-par[1]) * exp(-(TMath::Power((x[0] - par[4])/par[5], 2)/2.0))/(par[5]*sqrt(2*TMath::Pi()))));
  //return par[0]*(exp(-0.5*TMath::Power(((x[0]-par[1])/par[2]),2))/(sqrt(2*TMath::Pi())*par[2]) + exp(-0.5*TMath::Power(((x[0]-par[3])/(par[4]*par[2])),2))/(sqrt(2*TMath::Pi())*(par[4]*par[2])));
}
double DoubleSidedCrystalballFunction(double *x, double *par)
 { 
   double alpha_l = par[0]; 
   double alpha_h = par[1]; 
   double n_l     = par[2]; 
   double n_h     = par[3]; 
   double mean	= par[4]; 
   double sigma	= par[5];
   double N	= par[6];
   float t = (x[0]-mean)/sigma;
   double result;
   double fact1TLessMinosAlphaL = alpha_l/n_l;
   double fact2TLessMinosAlphaL = (n_l/alpha_l) - alpha_l -t;
   double fact1THighMinosAlphaH = alpha_h/n_h;
   double fact2THighMinosAlphaH = -((n_h/alpha_h) - alpha_h -t);
//   double fact1THihgerAlphaH = alpha_h/n_h;
//   double fact2THigherAlphaH = (n_h/alpha_h) - alpha_h +t;
   
   if (-alpha_l <= t && alpha_h >= t)
     {
       result = exp(-0.5*t*t);
     }
   else if (t < -alpha_l)
     {
       
       result = exp(-0.5*alpha_l*alpha_l)*pow(fact1TLessMinosAlphaL*fact2TLessMinosAlphaL, -n_l);
       
     }
   else if (t > alpha_h)
     {
       result = exp(-0.5*alpha_h*alpha_h)*pow(fact1THighMinosAlphaH*fact2THighMinosAlphaH, -n_h);
       
     }
   return N*result;
 }
 double DoubleSidedCrystalballFunction2(double *x, double *par)
 { 
   double alpha_l = par[0]; 
   double alpha_h = alpha_l; 
   double n_l     = par[1]; 
   double n_h     = n_l; 
   double mean	= par[2]; 
   double sigma	= par[3];
   double N	= par[4];
   float t = (x[0]-mean)/sigma;
   double result;
   double fact1TLessMinosAlphaL = alpha_l/n_l;
   double fact2TLessMinosAlphaL = (n_l/alpha_l) - alpha_l -t;
   double fact1THighMinosAlphaH = alpha_h/n_h;
   double fact2THighMinosAlphaH = -((n_h/alpha_h) - alpha_h -t);
//   double fact1THihgerAlphaH = alpha_h/n_h;
//   double fact2THigherAlphaH = (n_h/alpha_h) - alpha_h +t;
   
   if (-alpha_l <= t && alpha_h >= t)
     {
       result = exp(-0.5*t*t);
     }
   else if (t < -alpha_l)
     {
       
       result = exp(-0.5*alpha_l*alpha_l)*pow(fact1TLessMinosAlphaL*fact2TLessMinosAlphaL, -n_l);
       
     }
   else if (t > alpha_h)
     {
       result = exp(-0.5*alpha_h*alpha_h)*pow(fact1THighMinosAlphaH*fact2THighMinosAlphaH, -n_h);
       
     }
   return N*result;
 }

void fitter_Gauss(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *ey1)
{  
   TF1 *total = new TF1("total", "gaus", -0.2, 0.2);
   total->SetParNames("Amplitude ", "Mean", "Sigma");
   total->SetLineColor(kViolet);

   //x->Rebin(2);//Uncomment if you are using rebin

   Double_t par[3];
   par[0]= x->GetEntries();
   par[1]=0;
   par[2]=0.3;
   total->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();


    /* x->Fit("total","");
    x->Fit("total",""); */
    x->Fit("total","","", mean - 0.2, mean + 0.2);
    double mu = total->GetParameter(1);
    double sigma = abs(total->GetParameter(2));
    //x->Fit("total","","", mu - 1.5*sigma, mu + 1.5*sigma);
    x->Fit("total","","", mu - 2*sigma, mu + 2*sigma);


   *y1 = abs(total->GetParameter(2));// gets the sigma1 values
   *ey1 = total->GetParError(2);// gets the sigma1 error
   

   x->Draw("e1");

   total->Draw("same");
   std::cout << std::endl; total->Print();
}

void fitter(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt)
{  
   TF1 *g1 = new TF1("g1", "gausn", -0.1, 0.1);//gaus
   TF1 *g2 = new TF1("g2", "gausn", -4, 4);

   //TF1 *total = new TF1("total", "gaus(0) + gaus(3)", -10, 10);
   //TF1 *total = new TF1("total", "gausn(0) + gausn(3)", -10, 10);
   TF1 *total = new TF1("total", gaussianCombined, -4, 4, 6);
   /* total->SetParNames("Constant 1", "Mean 1", "Sigma 1",
                     "Constant 2", "Mean 2", "Sigma 2"); */
   total->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   total->SetLineColor(kViolet);

   x->Rebin(2);//Uncomment if you are using rebin

   //fitting 
   //x->Fit(g1,""); //gaus 1 ||, "R"
   
   //x->Fit(g2,""); //gaus 2 ||, "R"

   Double_t par[6];
   par[0]= x->GetEntries();
   par[1]=0.8;
   par[2]=0;
   par[3]=0.3;
   par[4]=0;
   par[5]=3;
   /* g1->GetParameters(&par[0]);
   g3->GetParameters(&par[3]); */
   total->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      x->Fit(total, ""); //doublegaus
      x->Fit("total","","", -i, i);
      //x->Fit("total","EM","", down, up);
      
      double chi2 = total->GetChisquare();
      int ndf = total->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   x->Fit(total, ""); //doublegaus
   x->Fit("total","","", -best_fit, best_fit); */
   /* x->Fit(total, "EM"); //doublegaus
   x->Fit("total","EM","", -best_fit, best_fit); */

   /* x->Fit(total, "EM"); //doublegaus
   //x->Fit("total","EM","", down, up);
	x->Fit("total","EM","", down, up); */
   x->Fit(total, ""); //doublegaus
   x->Fit("total","","", mean - 1, mean + 1);


   *y1 = abs(total->GetParameter(3));// gets the sigma1 values
   *ey1 = total->GetParError(3);// gets the sigma1 error
   *y2 = total->GetParameter(5);// gets the sigma2 values
   *ey2 = total->GetParError(5);// gets the sigma2 error
   *yt = (total->GetParameter(3))*(total->GetParameter(1))+(total->GetParameter(5))*(1-(total->GetParameter(1)));// gets the weighted sigma
   *eyt = sqrt(TMath::Power((total->GetParameter(1))*(total->GetParError(3)), 2)+TMath::Power((1-(total->GetParameter(1)))*(total->GetParError(5)), 2));// gets the weighted sigma error


   x->Draw("e1");

   total->Draw("same");

   std::cout << std::endl; total->Print();
}

void fitter2(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt)
{  
   TF1 *g1 = new TF1("g1", "gausn", -0.2, 0.2);//gaus
   TF1 *g2 = new TF1("g2", "gausn", -5, 5);

   //TF1 *total2 = new TF1("total2", "gaus(0) + gaus(3)", -10, 10);
   //TF1 *total2 = new TF1("total2", "gausn(0) + gausn(3)", -10, 10);
   TF1 *total2 = new TF1("total2", gaussianCombined, -5, 5, 6);
   /* total2->SetParNames("Constant 1", "Mean 1", "Sigma 1",
                     "Constant 2", "Mean 2", "Sigma 2"); */
   total2->SetParNames("Amplitude ","Ratio", "Mean 1",
                     "Sigma 1","Mean 2", "Sigma 2");
   total2->SetLineColor(kViolet);

   x->Rebin(2);//Uncomment if you are using rebin

   //fitting 
   //x->Fit(g1,""); //gaus 1 ||, "R"
   
   //x->Fit(g2,""); //gaus 2 ||, "R"

   Double_t par[6];
   par[0]= x->GetEntries();
   par[1]=0.8;
   par[2]=0;
   par[3]=0.3;
   par[4]=0;
   par[5]=3;
   /* g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]); */
   total2->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      x->Fit(total2, ""); //doublegaus
      x->Fit("total2","","", -i, i);
      //x->Fit("total","EM","", down, up);
      
      double chi2 = total2->GetChisquare();
      int ndf = total2->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   x->Fit(total2, ""); //doublegaus
   x->Fit("total2","","", -best_fit, best_fit); */
   /* x->Fit(total2, "EM"); //doublegaus
   x->Fit("total2","EM","", -best_fit, best_fit); */

   /* x->Fit(total2, "EM"); //doublegaus
   //x->Fit("total2","EM","", down, up);
	x->Fit("total2","EM","", down, up); */

   x->Fit(total2, ""); //doublegaus
   x->Fit("total2","","", mean-1, mean+1);

   *y1 = abs(total2->GetParameter(3));// gets the sigma1 values
   *ey1 = total2->GetParError(3);// gets the sigma1 error
   *y2 = total2->GetParameter(5);// gets the sigma2 values
   *ey2 = total2->GetParError(5);// gets the sigma2 error
   *yt = (total2->GetParameter(3))*(total2->GetParameter(1))+(total2->GetParameter(5))*(1-(total2->GetParameter(1)));// gets the weighted sigma
   *eyt = sqrt(TMath::Power((total2->GetParameter(1))*(total2->GetParError(3)), 2)+TMath::Power((1-(total2->GetParameter(1)))*(total2->GetParError(5)), 2));// gets the weighted sigma error

   x->Draw("e1");

   total2->Draw("same");

   std::cout << std::endl; total2->Print();
}

void fitter3(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt)
{  
   TF1 *g1 = new TF1("g1", "gausn", -0.3, 0.3);//gaus
   TF1 *g2 = new TF1("g2", "gausn", -6, 6);

   //TF1 *total3 = new TF1("total2", "gaus(0) + gaus(3)", -10, 10);
   //TF1 *total3 = new TF1("total2", "gausn(0) + gausn(3)", -10, 10);
   TF1 *total3= new TF1("total3", gaussianCombined, -6, 6, 6);
   /* total3->SetParNames("Constant 1", "Mean 1", "Sigma 1",
                     "Constant 2", "Mean 2", "Sigma 2"); */
   total3->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   total3->SetLineColor(kViolet);

   x->Rebin(2);//Uncomment if you are using rebin

   //fitting 
   //x->Fit(g1,""); //gaus 1 ||, "R"
   
   //x->Fit(g2,""); //gaus 2 ||, "R"

   Double_t par[6];
   par[0]= x->GetEntries();
   par[1]=0.8;
   par[2]=0;
   par[3]=0.3;
   par[4]=0;
   par[5]=3;
   /* g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]); */
   total3->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      x->Fit(total3, ""); //doublegaus
      x->Fit("total3","","", -i, i);
      //x->Fit("total","EM","", down, up);
      
      double chi2 = total3->GetChisquare();
      int ndf = total3->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   x->Fit(total3, ""); //doublegaus
   x->Fit("total3","","", -best_fit, best_fit); */
   /* x->Fit(total3, "EM"); //doublegaus
   x->Fit("total3","EM","", -best_fit, best_fit); */

   /* x->Fit(total3, "EM"); //doublegaus
   //x->Fit("total3",""," ", down, up);
	x->Fit("total3","EM"," ", down, up); */

   x->Fit(total3, ""); //doublegaus
   x->Fit("total3","","", mean-1, mean+1);

   *y1 = abs(total3->GetParameter(3));// gets the sigma1 values
   *ey1 = total3->GetParError(3);// gets the sigma1 error
   *y2 = total3->GetParameter(5);// gets the sigma2 values
   *ey2 = total3->GetParError(5);// gets the sigma2 error
   *yt = (total3->GetParameter(3))*(total3->GetParameter(1))+(total3->GetParameter(5))*(1-(total3->GetParameter(1)));// gets the weighted sigma
   *eyt = sqrt(TMath::Power((total3->GetParameter(1))*(total3->GetParError(3)), 2)+TMath::Power((1-(total3->GetParameter(1)))*(total3->GetParError(5)), 2));// gets the weighted sigma error


   x->Draw("e1");

   total3->Draw("same");

   std::cout << std::endl; total3->Print();
}

void fitter4(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt)
{  
   TF1 *g1 = new TF1("g1", "gausn", -0.4, 0.4);//gaus
   TF1 *g2 = new TF1("g2", "gausn", -7, 7);

   //TF1 *total4 = new TF1("total4", "gaus(0) + gaus(3)", -10, 10);
   //TF1 *total4 = new TF1("total4", "gausn(0) + gausn(3)", -10, 10);
   TF1 *total4= new TF1("total4", gaussianCombined, -7, 7, 6);
   /* total3->SetParNames("Constant 1", "Mean 1", "Sigma 1",
                     "Constant 2", "Mean 2", "Sigma 2"); */
   total4->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   total4->SetLineColor(kViolet);

   x->Rebin(2);//Uncomment if you are using rebin

   //fitting 
   //x->Fit(g1,""); //gaus 1 ||, "R"
   
   //x->Fit(g2,""); //gaus 2 ||, "R"

   Double_t par[6];
   par[0]= x->GetEntries();
   par[1]=0.8;
   par[2]=0;
   par[3]=0.3;
   par[4]=0;
   par[5]=3;
   /* g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]); */
   total4->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      x->Fit(total4, ""); //doublegaus
      x->Fit("total4","","", -i, i);
      //x->Fit("total","EM","", down, up);
      
      double chi2 = total4->GetChisquare();
      int ndf = total4->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   x->Fit(total4, ""); //doublegaus
   x->Fit("total4","","", -best_fit, best_fit); */
   /* x->Fit(total4, "EM"); //doublegaus
   x->Fit("total4","EM","", -best_fit, best_fit); */
   

   /* x->Fit(total4, "EM"); //doublegaus
   //x->Fit("total4","EM"," ", down, up);
	x->Fit("total4","EM"," ", down, up); */

   x->Fit(total4, ""); //doublegaus
   x->Fit("total4","","", mean-1, mean+1);

   *y1 = abs(total4->GetParameter(3));// gets the sigma1 values
   *ey1 = total4->GetParError(3);// gets the sigma1 error
   *y2 = total4->GetParameter(5);// gets the sigma2 values
   *ey2 = total4->GetParError(5);// gets the sigma2 error
   *yt = (total4->GetParameter(3))*(total4->GetParameter(1))+(total4->GetParameter(5))*(1-(total4->GetParameter(1)));// gets the weighted sigma
   *eyt = sqrt(TMath::Power((total4->GetParameter(1))*(total4->GetParError(3)), 2)+TMath::Power((1-(total4->GetParameter(1)))*(total4->GetParError(5)), 2));// gets the weighted sigma error


   x->Draw("e1");

   total4->Draw("same");

   std::cout << std::endl; total4->Print();
}

void fitter5(TH1F *x, Double_t down, Double_t up, Double_t *y1, Double_t *y2, Double_t *yt, Double_t *ey1, Double_t *ey2, Double_t *eyt)
{  
   TF1 *g1 = new TF1("g1", "gausn", -0.5, 0.5);//gaus
   TF1 *g2 = new TF1("g2", "gausn", -8, 8);

   //TF1 *total5 = new TF1("total5", "gaus(0) + gaus(3)", -10, 10);
   //TF1 *total5 = new TF1("total5", "gausn(0) + gausn(3)", -10, 10);
   TF1 *total5= new TF1("total5", gaussianCombined, -8, 8, 6);
   /* total5->SetParNames("Constant 1", "Mean 1", "Sigma 1",
                     "Constant 2", "Mean 2", "Sigma 2"); */
   total5->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   total5->SetLineColor(kViolet);

   x->Rebin(2);//Uncomment if you are using rebin

   //fitting 
   //x->Fit(g1,""); //gaus 1 ||, "R"
   
   //x->Fit(g2,""); //gaus 2 ||, "R"

   Double_t par[6];
   par[0]= x->GetEntries();
   par[1]=0.8;
   par[2]=0;
   par[3]=0.3;
   par[4]=0;
   par[5]=3;
   /* g1->GetParameters(&par[0]);
   g2->GetParameters(&par[3]); */
   total5->SetParameters(par);

   double best_fit = 0; 
   double best_prob = 0;
   double mean = x->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      x->Fit(total5, ""); //doublegaus
      x->Fit("total5","","", -i, i);
      //x->Fit("total","EM","", down, up);
      
      double chi2 = total5->GetChisquare();
      int ndf = total5->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   x->Fit(total5, ""); //doublegaus
   x->Fit("total5","","", -best_fit, best_fit); */
   /* x->Fit(total5, "EM"); //doublegaus
   x->Fit("total5","EM","", -best_fit, best_fit); */
   

   /* x->Fit(total5, "EM"); //doublegaus
   //x->Fit("total5","EM"," ", down, up);
	x->Fit("total5","EM"," ", down, up); */

   x->Fit(total5, ""); //doublegaus
   x->Fit("total5","","", mean-1, mean+1);

   *y1 = abs(total5->GetParameter(3));// gets the sigma1 values
   *ey1 = total5->GetParError(3);// gets the sigma1 error
   *y2 = total5->GetParameter(5);// gets the sigma2 values
   *ey2 = total5->GetParError(5);// gets the sigma2 error
   *yt = (total5->GetParameter(3))*(total5->GetParameter(1))+(total5->GetParameter(5))*(1-(total5->GetParameter(1)));// gets the weighted sigma
   *eyt = sqrt(TMath::Power((total5->GetParameter(1))*(total5->GetParError(3)), 2)+TMath::Power((1-(total5->GetParameter(1)))*(total5->GetParError(5)), 2));// gets the weighted sigma error


   x->Draw("e1");

   total5->Draw("same");

   std::cout << std::endl; total5->Print();
}

//void myfit(TH1F *histo, Double_t down, Double_t up, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1, Double_t *y2, Double_t *ey2) 
void myfit(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1) 
{
	//histo->Rebin(2);

/* 	TF1 *func_gaus = new TF1("fit_gaus",gaussianCombined,-5.,5.,6);
	func_gaus->SetParameters(1000000.,0.8,0.,0.3,0.,5.);
	func_gaus->SetParLimits(2,-0.1,0.1);
	func_gaus->SetParLimits(3,0.,1.0);	
	func_gaus->SetParLimits(4,-1.0,1.0);
	func_gaus->SetParLimits(5,0.3,10.0);	

   func_gaus->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");

   func_gaus->SetLineColor(kRed);
 */	
	TF1 *func = new TF1("fit_CB",DoubleSidedCrystalballFunction,-5.,5.,7);
	func->SetParameters(1.3,1.3,1.,1.,histo->GetMean(), histo->GetRMS(),histo->Integral(-5, 5));
	func->SetParLimits(4,-0.5,0.5);	
	func->SetParLimits(5,0.,1.);

   func->SetParNames("Amplitude Lower ","Amplitude Higher ","norm Lower ",
                     "norm Higher ","Mean","Sigma","Norm ");	
   
   func->SetLineColor(kViolet);

   histo->Rebin(2);//Uncomment if you are using rebin

   double best_fit = 0; 
   double best_prob = 0;
   double mean = histo->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      histo->Fit("fit_CB","","", -i, i);
      histo->Fit("fit_CB","","", -i, i);
      //histo->Fit("total","EM","", down, up);
      
      double chi2 = func->GetChisquare();
      int ndf = func->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   histo->Fit("fit_CB","","", -best_fit, best_fit);
   histo->Fit("fit_CB","","", -best_fit, best_fit); */
   /* histo->Fit("fit_CB","EM","", -best_fit, best_fit);
   histo->Fit("fit_CB","EM","", -best_fit, best_fit); */

   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
	
	//histo->Fit("fit_gaus","+"," ", down, up);
	/* histo->Fit("fit_CB"," "," ", down_CB, up_CB);
   histo->Fit("fit_CB"," "," ", down_CB, up_CB); */	
	histo->Draw("same");

   /* *y2 = func_gaus->GetParameter(3);// gets the sigma values
   *ey2 = func_gaus->GetParError(3);// gets the sigma error
 */
   *y1 = abs(func->GetParameter(5));// gets the sigma values
   *ey1 = func->GetParError(5);// gets the sigma error

}

//void myfit2(TH1F *histo, Double_t down, Double_t up, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1, Double_t *y2, Double_t *ey2)
void myfit2(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1) 
{
	//histo->Rebin(2);

	/* TF1 *func2_gaus = new TF1("fit_gaus",gaussianCombined,-5.,5.,6);
	func2_gaus->SetParameters(1000000.,0.8,0.,0.3,0.,5.);
	func2_gaus->SetParLimits(2,-0.1,0.1);
	func2_gaus->SetParLimits(3,0.,1.0);	
	func2_gaus->SetParLimits(4,-1.0,1.0);
	func2_gaus->SetParLimits(5,0.3,10.0);	

   func2_gaus->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   
   func2_gaus->SetLineColor(kRed);
	 */
	TF1 *func2 = new TF1("fit_CB",DoubleSidedCrystalballFunction2,-5.,5.,5);
	func2->SetParameters(1.3,1.,histo->GetMean(), histo->GetRMS(),histo->Integral(-5, 5));
	func2->SetParLimits(2,-0.5,0.5);	
	func2->SetParLimits(3,0.,1.);

   func2->SetParNames("Amplitude ","Norm ", "Mean ", "Sigma ");

   func2->SetLineColor(kViolet);

   histo->Rebin(2);//Uncomment if you are using rebin

   double best_fit = 0; 
   double best_prob = 0;
   double mean = histo->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      histo->Fit("fit_CB","","", -i, i);
      histo->Fit("fit_CB","","", -i, i);
      //histo->Fit("total","EM","", down, up);
      
      double chi2 = func2->GetChisquare();
      int ndf = func2->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   histo->Fit("fit_CB","","", -best_fit, best_fit);
   histo->Fit("fit_CB","","", -best_fit, best_fit); */
   /* histo->Fit("fit_CB","EM","", -best_fit, best_fit);
   histo->Fit("fit_CB","EM","", -best_fit, best_fit); */

   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
	
	//histo->Fit("fit_gaus","+"," ", down, up);
	/* histo->Fit("fit_CB"," "," ", down_CB, up_CB);
   histo->Fit("fit_CB"," "," ", down_CB, up_CB);	 */
	histo->Draw("same");

   /* *y2 = func2_gaus->GetParameter(3);// gets the sigma values
    *ey2 = func2_gaus->GetParError(3);// gets the sigma error
*/
   *y1 = abs(func2->GetParameter(3));// gets the sigma values
   *ey1 = func2->GetParError(3);// gets the sigma error

}
void myfit2_custom(TH1F *histo, Double_t down_CB, Double_t up_CB, Double_t *y1, Double_t *ey1) 
{
	//histo->Rebin(2);

	/* TF1 *func2_gaus = new TF1("fit_gaus",gaussianCombined,-5.,5.,6);
	func2_gaus->SetParameters(1000000.,0.8,0.,0.3,0.,5.);
	func2_gaus->SetParLimits(2,-0.1,0.1);
	func2_gaus->SetParLimits(3,0.,1.0);	
	func2_gaus->SetParLimits(4,-1.0,1.0);
	func2_gaus->SetParLimits(5,0.3,10.0);	

   func2_gaus->SetParNames("Amplitude ","Ratio", "Mean 1", "Sigma 1",
                      "Mean 2", "Sigma 2");
   
   func2_gaus->SetLineColor(kRed);
	 */
	TF1 *func2 = new TF1("fit_CB",DoubleSidedCrystalballFunction2,-5.,5.,5);
	func2->SetParameters(1.3,1.,histo->GetMean(), .25,histo->Integral(-5, 5));//histo->GetRMS()
	func2->SetParLimits(2,-0.5,0.5);	
	func2->SetParLimits(3,0.,1.);
   func2->SetParLimits(4,.2,.3);

   func2->SetParNames("Amplitude ","Norm ", "Mean ", "Sigma ");

   func2->SetLineColor(kViolet);

   histo->Rebin(2);//Uncomment if you are using rebin

   double best_fit = 0; 
   double best_prob = 0;
   double mean = histo->GetMean();

   //for(float i=0.5; i>0.04; i -=  0.01)
   /* for(float i=1; i>0.04; i -=  0.01)
   {
      histo->Fit("fit_CB","","", -i, i);
      histo->Fit("fit_CB","","", -i, i);
      //histo->Fit("total","EM","", down, up);
      
      double chi2 = func2->GetChisquare();
      int ndf = func2->GetNDF();
      // Calculate the probability of the fitting being correct based on chi-squared test.
      double probability = TMath::Prob(chi2, ndf);
      if(abs(probability-1)>best_prob)
      {
         best_prob = probability;
         best_fit = i;
      } 
   }
   histo->Fit("fit_CB","","", -best_fit, best_fit);
   histo->Fit("fit_CB","","", -best_fit, best_fit); */
   /* histo->Fit("fit_CB","EM","", -best_fit, best_fit);
   histo->Fit("fit_CB","EM","", -best_fit, best_fit); */

   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
   histo->Fit("fit_CB","","", mean-0.5, mean + 0.5);
	
	//histo->Fit("fit_gaus","+"," ", down, up);
	/* histo->Fit("fit_CB"," "," ", down_CB, up_CB);
   histo->Fit("fit_CB"," "," ", down_CB, up_CB);	 */
	histo->Draw("same");

   /* *y2 = func2_gaus->GetParameter(3);// gets the sigma values
    *ey2 = func2_gaus->GetParError(3);// gets the sigma error
*/
   *y1 = abs(func2->GetParameter(3));// gets the sigma values
   *ey1 = func2->GetParError(3);// gets the sigma error

}
TH1F* MergeHistograms(TH1F* histogram1, TH1F* histogram2) 
{
    if (!histogram1 || !histogram2) {
        return nullptr;
    }

    int nBins = histogram1->GetNbinsX();
    double xMin = histogram1->GetXaxis()->GetXmin();
    double xMax = histogram1->GetXaxis()->GetXmax();

    TH1F* mergedHistogram = new TH1F("mergedHistogram", "Merged Histogram", nBins, xMin, xMax);

    for (int bin = 1; bin <= nBins; ++bin) {
        double content = histogram1->GetBinContent(bin) + histogram2->GetBinContent(bin);
        mergedHistogram->SetBinContent(bin, content);
    }

    return mergedHistogram;
}