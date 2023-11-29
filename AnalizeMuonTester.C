#define AnalizeMuonTester_cxx
#include "AnalizeMuonTester.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>


void AnalizeMuonTester::Loop()
{
//   In a ROOT session, you can do:
//      root> .L AnalizeMuonTester.C
//      root> AnalizeMuonTester t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
//

//     This is the loop skeleton where:
//    jentry is the global entry number in the chain
//    ientry is the entry number in the current Tree
//  Note that the argument to GetEntry must be:
//    jentry for TChain::GetEntry
//    ientry for TTree::GetEntry and TBranch::GetEntry
//
//       To read only selected branches, Insert statements like:
// METHOD1:
    fChain->SetBranchStatus("*",0);  // disable all branches
/*
    fChain->SetBranchStatus("IDTracks_pt",1);  // activate branchname
    fChain->SetBranchStatus("IDTracks_eta",1);  // activate branchname
	 fChain->SetBranchStatus("IDTracks_phi",1);  // activate branchname
    fChain->SetBranchStatus("METracks_pt",1);  // activate branchname
    fChain->SetBranchStatus("METracks_eta",1);  // activate branchname
	 fChain->SetBranchStatus("METracks_phi",1);  // activate branchname
*/
    fChain->SetBranchStatus("mmOnTrackResidualTrack",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrackResidualTrackMS",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_MuonLink",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_channel",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_gas_gap",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_multiplet",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrackNStrips",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_stationEta",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_stationIndex",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrack_stationPhi",1);  // activate branchname

    fChain->SetBranchStatus("stgcOnTrackResidualTrack",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrackResidualTrackMS",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_MuonLink",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_channel",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_gas_gap",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_multiplet",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrackNStrips",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_stationEta",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_stationIndex",1);  // activate branchname
    fChain->SetBranchStatus("stgcOnTrack_stationPhi",1);  // activate branchname

    fChain->SetBranchStatus("MSTracks_pt",1);  // activate branchname
    fChain->SetBranchStatus("MSTracks_eta",1);  // activate branchname
	 fChain->SetBranchStatus("MSTracks_phi",1);  // activate branchname
	
	 fChain->SetBranchStatus("muons_pt",1);  // activate branchname
    fChain->SetBranchStatus("muons_eta",1);  // activate branchname
	 fChain->SetBranchStatus("muons_phi",1);  // activate branchname

    fChain->SetBranchStatus("mmOnTrackLocalPos_x",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrackLocalPos_y",1);  // activate branchname

    fChain->SetBranchStatus("mmOnTrackGlobalPos_x",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrackGlobalPos_y",1);  // activate branchname
    fChain->SetBranchStatus("mmOnTrackGlobalPos_z",1);  // activate branchname

    fChain->SetBranchStatus("muons_MSLink",1);   // activate branchname
	 fChain->SetBranchStatus("muons_isBad",1);   // activate branchname

// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch

// At this point we declare the output root file with the histograms we need
   TFile *rfile  = new TFile( "OutputHistograms.root","RECREATE");
//////////////////////////////////////////////////MicroMegas
   TH1F *h_mmOnTrackResidualTrack = new TH1F("mmOnTrackResidualTrack","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrackMS = new TH1F("mmOnTrackResidualTrackMS","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_pt20 = new TH1F("mmOnTrackResidualTrack_pt20","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrackMS_pt20 = new TH1F("mmOnTrackResidualTrackMS_pt20","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_ST1 = new TH1F("mmOnTrackResidualTrack_ST1","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_ST2 = new TH1F("mmOnTrackResidualTrack_ST2","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrackMS_ST1 = new TH1F("mmOnTrackResidualTrackMS_ST1","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_ST2 = new TH1F("mmOnTrackResidualTrackMS_ST2","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_ST1 = new TH1F("eta_mmOnTrackResidualTrack_ST1","eta mm OnTrackResidualTrack ST1 ", 8000,-20,20);
   TH1F *h_eta_mmOnTrackResidualTrack_ST2 = new TH1F("eta_mmOnTrackResidualTrack_ST2","eta mm OnTrackResidualTrack ST2 ", 4000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_ST1 = new TH1F("eta_mmOnTrackResidualTrackMS_ST1","eta mm OnTrackResidualTrack MS ST1 ", 8000,-20,20);
   TH1F *h_eta_mmOnTrackResidualTrackMS_ST2 = new TH1F("eta_mmOnTrackResidualTrackMS_ST2","eta mm OnTrackResidualTrack MS ST2 ", 4000,-10,10);

   TH1F *h_mmOnTrackResidualTrack_PhiST1 = new TH1F("mmOnTrackResidualTrack_PhiST1","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST2 = new TH1F("mmOnTrackResidualTrack_PhiST2","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST3 = new TH1F("mmOnTrackResidualTrack_PhiST3","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST4 = new TH1F("mmOnTrackResidualTrack_PhiST4","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST5 = new TH1F("mmOnTrackResidualTrack_PhiST5","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST6 = new TH1F("mmOnTrackResidualTrack_PhiST6","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST7 = new TH1F("mmOnTrackResidualTrack_PhiST7","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrack_PhiST8 = new TH1F("mmOnTrackResidualTrack_PhiST8","mm OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST1 = new TH1F("mmOnTrackResidualTrackMS_PhiST1","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST2 = new TH1F("mmOnTrackResidualTrackMS_PhiST2","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST3 = new TH1F("mmOnTrackResidualTrackMS_PhiST3","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST4 = new TH1F("mmOnTrackResidualTrackMS_PhiST4","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST5 = new TH1F("mmOnTrackResidualTrackMS_PhiST5","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST6 = new TH1F("mmOnTrackResidualTrackMS_PhiST6","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST7 = new TH1F("mmOnTrackResidualTrackMS_PhiST7","mm OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_PhiST8 = new TH1F("mmOnTrackResidualTrackMS_PhiST8","mm OnTrackResidualTrack MS ", 4000,-10,10);

   TH1F *h_mmOnTrackResidualTrack_PCB1 = new TH1F("mmOnTrackResidualTrack_PCB1","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB1 = new TH1F("eta_mmOnTrackResidualTrack_PCB1","eta mm OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB1 = new TH1F("stereo_mmOnTrackResidualTrack_PCB1","stereo mm OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB2 = new TH1F("mmOnTrackResidualTrack_PCB2","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB2 = new TH1F("eta_mmOnTrackResidualTrack_PCB2","eta mm OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB2 = new TH1F("stereo_mmOnTrackResidualTrack_PCB2","stereo mm OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB3 = new TH1F("mmOnTrackResidualTrack_PCB3","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB3 = new TH1F("eta_mmOnTrackResidualTrack_PCB3","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB3 = new TH1F("stereo_mmOnTrackResidualTrack_PCB3","stereo mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_mmOnTrackResidualTrack_PCB4 = new TH1F("mmOnTrackResidualTrack_PCB4","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB4 = new TH1F("eta_mmOnTrackResidualTrack_PCB4","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB4 = new TH1F("stereo_mmOnTrackResidualTrack_PCB4","stereo mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_mmOnTrackResidualTrack_PCB5 = new TH1F("mmOnTrackResidualTrack_PCB5","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB5 = new TH1F("eta_mmOnTrackResidualTrack_PCB5","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB5 = new TH1F("stereo_mmOnTrackResidualTrack_PCB5","stereo mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_mmOnTrackResidualTrack_PCB6 = new TH1F("mmOnTrackResidualTrack_PCB6","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB6 = new TH1F("eta_mmOnTrackResidualTrack_PCB6","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB6 = new TH1F("stereo_mmOnTrackResidualTrack_PCB6","stereo mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_mmOnTrackResidualTrack_PCB7 = new TH1F("mmOnTrackResidualTrack_PCB7","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB7 = new TH1F("eta_mmOnTrackResidualTrack_PCB7","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB7 = new TH1F("stereo_mmOnTrackResidualTrack_PCB7","stereo mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_mmOnTrackResidualTrack_PCB8 = new TH1F("mmOnTrackResidualTrack_PCB8","mm OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB8 = new TH1F("eta_mmOnTrackResidualTrack_PCB8","eta mm OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB8 = new TH1F("stereo_mmOnTrackResidualTrack_PCB8","stereo mm OnTrackResidualTrack ", 1000,-5,5);

   TH1F *h_mmOnTrackResidualTrackMS_PCB1 = new TH1F("mmOnTrackResidualTrackMS_PCB1","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB1","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB1","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB2 = new TH1F("mmOnTrackResidualTrackMS_PCB2","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB2","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB2","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB3 = new TH1F("mmOnTrackResidualTrackMS_PCB3","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB3","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB3","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB4 = new TH1F("mmOnTrackResidualTrackMS_PCB4","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB4","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB4","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB5 = new TH1F("mmOnTrackResidualTrackMS_PCB5","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB5","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB5","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB6 = new TH1F("mmOnTrackResidualTrackMS_PCB6","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB6","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB6","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB7 = new TH1F("mmOnTrackResidualTrackMS_PCB7","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB7","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB7","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB8 = new TH1F("mmOnTrackResidualTrackMS_PCB8","mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8 = new TH1F("eta_mmOnTrackResidualTrackMS_PCB8","eta mm OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8 = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB8","stereo mm OnTrackResidualTrack MS ", 1200,-6,6);

   TH1F *h_mmOnTrack_channel = new TH1F("mmOnTrack_channel","mm OnTrack channel ", 5100,0,5100);
   TH1F *h_mmOnTrack_channel_pt20 =  new TH1F("mmOnTrack_channel_pt20","mm OnTrack channel ", 5100,0,5100);
   TH1F *h_mmOnTrack_stationEta =  new TH1F("mmOnTrack_stationEta","mm OnTrack station Eta ", 8,-4,4);
   TH1F *h_mmOnTrack_stationPhi =  new TH1F("mmOnTrack_stationPhi","mm OnTrack station Phi ", 9,0,9);

   TH1F *h_mmOnTrack_gas_gap = new TH1F("mmOnTrack_gas_gap","mm OnTrack gas gap",6,0,6); 

   TH1F *h_mmhitmuons_theta = new TH1F("MMhitmuons_theta","MM hit muons theta",50,0.1,0.6);
   TH1F *h_mmhitmuons_phi = new TH1F("mmhitmuons_phi","mm hit muons phi",320,0,3.2);

//eta

   TH1F *h_mmOnTrackResidualTrack_eta1 = new TH1F("mmOnTrackResidualTrack_eta1","mm OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta1 = new TH1F("eta_mmOnTrackResidualTrack_eta1","eta mm OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta1 = new TH1F("stereo_mmOnTrackResidualTrack_eta1","stereo mm OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta2 = new TH1F("mmOnTrackResidualTrack_eta2","mm OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta2 = new TH1F("eta_mmOnTrackResidualTrack_eta2","eta mm OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta2 = new TH1F("stereo_mmOnTrackResidualTrack_eta2","stereo mm OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta3 = new TH1F("mmOnTrackResidualTrack_eta3","mm OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta3 = new TH1F("eta_mmOnTrackResidualTrack_eta3","eta mm OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta3 = new TH1F("stereo_mmOnTrackResidualTrack_eta3","stereo mm OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta4 = new TH1F("mmOnTrackResidualTrack_eta4","mm OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta4 = new TH1F("eta_mmOnTrackResidualTrack_eta4","eta mm OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta4 = new TH1F("stereo_mmOnTrackResidualTrack_eta4","stereo mm OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta5 = new TH1F("mmOnTrackResidualTrack_eta5","mm OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta5 = new TH1F("eta_mmOnTrackResidualTrack_eta5","eta mm OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta5 = new TH1F("stereo_mmOnTrackResidualTrack_eta5","stereo mm OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta6 = new TH1F("mmOnTrackResidualTrack_eta6","mm OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta6 = new TH1F("eta_mmOnTrackResidualTrack_eta6","eta mm OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta6 = new TH1F("stereo_mmOnTrackResidualTrack_eta6","stereo mm OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta7 = new TH1F("mmOnTrackResidualTrack_eta7","mm OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta7 = new TH1F("eta_mmOnTrackResidualTrack_eta7","eta mm OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta7 = new TH1F("stereo_mmOnTrackResidualTrack_eta7","stereo mm OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta8 = new TH1F("mmOnTrackResidualTrack_eta8","mm OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta8 = new TH1F("eta_mmOnTrackResidualTrack_eta8","eta mm OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta8 = new TH1F("stereo_mmOnTrackResidualTrack_eta8","stereo mm OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta9 = new TH1F("mmOnTrackResidualTrack_eta9","mm OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta9 = new TH1F("eta_mmOnTrackResidualTrack_eta9","eta mm OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta9 = new TH1F("stereo_mmOnTrackResidualTrack_eta9","stereo mm OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta10 = new TH1F("mmOnTrackResidualTrack_eta10","mm OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta10 = new TH1F("eta_mmOnTrackResidualTrack_eta10","eta mm OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta10 = new TH1F("stereo_mmOnTrackResidualTrack_eta10","stereo mm OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta11 = new TH1F("mmOnTrackResidualTrack_eta11","mm OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_eta11 = new TH1F("eta_mmOnTrackResidualTrack_eta11","eta mm OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta11 = new TH1F("stereo_mmOnTrackResidualTrack_eta11","stereo mm OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_eta12 = new TH1F("mmOnTrackResidualTrack_eta12","mm OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_eta12 = new TH1F("eta_mmOnTrackResidualTrack_eta12","eta mm OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta12 = new TH1F("stereo_mmOnTrackResidualTrack_eta12","stereo mm OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_eta13 = new TH1F("mmOnTrackResidualTrack_eta13","mm OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_eta13 = new TH1F("eta_mmOnTrackResidualTrack_eta13","eta mm OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta13 = new TH1F("stereo_mmOnTrackResidualTrack_eta13","stereo mm OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_eta14 = new TH1F("mmOnTrackResidualTrack_eta14","mm OnTrackResidualTrack eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_eta14 = new TH1F("eta_mmOnTrackResidualTrack_eta14","eta mm OnTrackResidualTrack eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_eta14 = new TH1F("stereo_mmOnTrackResidualTrack_eta14","stereo mm OnTrackResidualTrack eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMS_eta1 = new TH1F("mmOnTrackResidualTrackMS_eta1","mm OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta1 = new TH1F("eta_mmOnTrackResidualTrackMS_eta1","eta mm OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta1","stereo mm OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_eta2 = new TH1F("mmOnTrackResidualTrackMS_eta2","mm OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta2 = new TH1F("eta_mmOnTrackResidualTrackMS_eta2","eta mm OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta2","stereo mm OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_eta3 = new TH1F("mmOnTrackResidualTrackMS_eta3","mm OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta3 = new TH1F("eta_mmOnTrackResidualTrackMS_eta3","eta mm OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta3","stereo mm OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_eta4 = new TH1F("mmOnTrackResidualTrackMS_eta4","mm OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta4 = new TH1F("eta_mmOnTrackResidualTrackMS_eta4","eta mm OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta4","stereo mm OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_eta5 = new TH1F("mmOnTrackResidualTrackMS_eta5","mm OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta5 = new TH1F("eta_mmOnTrackResidualTrackMS_eta5","eta mm OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta5","stereo mm OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta6 = new TH1F("mmOnTrackResidualTrackMS_eta6","mm OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta6 = new TH1F("eta_mmOnTrackResidualTrackMS_eta6","eta mm OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta6","stereo mm OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta7 = new TH1F("mmOnTrackResidualTrackMS_eta7","mm OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta7 = new TH1F("eta_mmOnTrackResidualTrackMS_eta7","eta mm OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta7","stereo mm OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta8 = new TH1F("mmOnTrackResidualTrackMS_eta8","mm OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta8 = new TH1F("eta_mmOnTrackResidualTrackMS_eta8","eta mm OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta8","stereo mm OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta9 = new TH1F("mmOnTrackResidualTrackMS_eta9","mm OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta9 = new TH1F("eta_mmOnTrackResidualTrackMS_eta9","eta mm OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta9","stereo mm OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta10 = new TH1F("mmOnTrackResidualTrackMS_eta10","mm OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta10 = new TH1F("eta_mmOnTrackResidualTrackMS_eta10","eta mm OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta10","stereo mm OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta11 = new TH1F("mmOnTrackResidualTrackMS_eta11","mm OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta11 = new TH1F("eta_mmOnTrackResidualTrackMS_eta11","eta mm OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta11","stereo mm OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta12 = new TH1F("mmOnTrackResidualTrackMS_eta12","mm OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta12 = new TH1F("eta_mmOnTrackResidualTrackMS_eta12","eta mm OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta12","stereo mm OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMS_eta13 = new TH1F("mmOnTrackResidualTrackMS_eta13","mm OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta13 = new TH1F("eta_mmOnTrackResidualTrackMS_eta13","eta mm OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta13","stereo mm OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMS_eta14 = new TH1F("mmOnTrackResidualTrackMS_eta14","mm OnTrackResidualTrack MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMS_eta14 = new TH1F("eta_mmOnTrackResidualTrackMS_eta14","eta mm OnTrackResidualTrack MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMS_eta14","stereo mm OnTrackResidualTrack MS eta14 ", 400,-2,2);

///Phi01

   TH1F *h_mmOnTrackResidualTrackPhi01_eta1 = new TH1F("mmOnTrackResidualTrackPhi01_eta1","mm OnTrackResidualTrackPhi01 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta1","eta mm OnTrackResidualTrackPhi01 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta1","stereo mm OnTrackResidualTrackPhi01 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta2 = new TH1F("mmOnTrackResidualTrackPhi01_eta2","mm OnTrackResidualTrackPhi01 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta2","eta mm OnTrackResidualTrackPhi01 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta2","stereo mm OnTrackResidualTrackPhi01 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta3 = new TH1F("mmOnTrackResidualTrackPhi01_eta3","mm OnTrackResidualTrackPhi01 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta3","eta mm OnTrackResidualTrackPhi01 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta3","stereo mm OnTrackResidualTrackPhi01 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta4 = new TH1F("mmOnTrackResidualTrackPhi01_eta4","mm OnTrackResidualTrackPhi01 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta4","eta mm OnTrackResidualTrackPhi01 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta4","stereo mm OnTrackResidualTrackPhi01 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta5 = new TH1F("mmOnTrackResidualTrackPhi01_eta5","mm OnTrackResidualTrackPhi01 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta5","eta mm OnTrackResidualTrackPhi01 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta5","stereo mm OnTrackResidualTrackPhi01 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta6 = new TH1F("mmOnTrackResidualTrackPhi01_eta6","mm OnTrackResidualTrackPhi01 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta6","eta mm OnTrackResidualTrackPhi01 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta6","stereo mm OnTrackResidualTrackPhi01 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta7 = new TH1F("mmOnTrackResidualTrackPhi01_eta7","mm OnTrackResidualTrackPhi01 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta7","eta mm OnTrackResidualTrackPhi01 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta7","stereo mm OnTrackResidualTrackPhi01 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta8 = new TH1F("mmOnTrackResidualTrackPhi01_eta8","mm OnTrackResidualTrackPhi01 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta8","eta mm OnTrackResidualTrackPhi01 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta8","stereo mm OnTrackResidualTrackPhi01 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta9 = new TH1F("mmOnTrackResidualTrackPhi01_eta9","mm OnTrackResidualTrackPhi01 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta9","eta mm OnTrackResidualTrackPhi01 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta9","stereo mm OnTrackResidualTrackPhi01 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta10 = new TH1F("mmOnTrackResidualTrackPhi01_eta10","mm OnTrackResidualTrackPhi01 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta10","eta mm OnTrackResidualTrackPhi01 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta10","stereo mm OnTrackResidualTrackPhi01 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta11 = new TH1F("mmOnTrackResidualTrackPhi01_eta11","mm OnTrackResidualTrackPhi01 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta11","eta mm OnTrackResidualTrackPhi01 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta11","stereo mm OnTrackResidualTrackPhi01 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta12 = new TH1F("mmOnTrackResidualTrackPhi01_eta12","mm OnTrackResidualTrackPhi01 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta12","eta mm OnTrackResidualTrackPhi01 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta12","stereo mm OnTrackResidualTrackPhi01 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta13 = new TH1F("mmOnTrackResidualTrackPhi01_eta13","mm OnTrackResidualTrackPhi01 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta13","eta mm OnTrackResidualTrackPhi01 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta13","stereo mm OnTrackResidualTrackPhi01 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi01_eta14 = new TH1F("mmOnTrackResidualTrackPhi01_eta14","mm OnTrackResidualTrackPhi01 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi01_eta14","eta mm OnTrackResidualTrackPhi01 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi01_eta14","stereo mm OnTrackResidualTrackPhi01 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta1","mm OnTrackResidualTrackPhi01 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta1","eta mm OnTrackResidualTrackPhi01 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta1","stereo mm OnTrackResidualTrackPhi01 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta2","mm OnTrackResidualTrackPhi01 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta2","eta mm OnTrackResidualTrackPhi01 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta2","stereo mm OnTrackResidualTrackPhi01 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta3","mm OnTrackResidualTrackPhi01 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta3","eta mm OnTrackResidualTrackPhi01 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta3","stereo mm OnTrackResidualTrackPhi01 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta4","mm OnTrackResidualTrackPhi01 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta4","eta mm OnTrackResidualTrackPhi01 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta4","stereo mm OnTrackResidualTrackPhi01 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta5","mm OnTrackResidualTrackPhi01 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta5","eta mm OnTrackResidualTrackPhi01 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta5","stereo mm OnTrackResidualTrackPhi01 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta6","mm OnTrackResidualTrackPhi01 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta6","eta mm OnTrackResidualTrackPhi01 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta6","stereo mm OnTrackResidualTrackPhi01 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta7","mm OnTrackResidualTrackPhi01 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta7","eta mm OnTrackResidualTrackPhi01 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta7","stereo mm OnTrackResidualTrackPhi01 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta8","mm OnTrackResidualTrackPhi01 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta8","eta mm OnTrackResidualTrackPhi01 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta8","stereo mm OnTrackResidualTrackPhi01 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta9","mm OnTrackResidualTrackPhi01 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta9","eta mm OnTrackResidualTrackPhi01 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta9","stereo mm OnTrackResidualTrackPhi01 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta10","mm OnTrackResidualTrackPhi01 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta10","eta mm OnTrackResidualTrackPhi01 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta10","stereo mm OnTrackResidualTrackPhi01 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta11","mm OnTrackResidualTrackPhi01 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta11","eta mm OnTrackResidualTrackPhi01 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta11","stereo mm OnTrackResidualTrackPhi01 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta12","mm OnTrackResidualTrackPhi01 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta12","eta mm OnTrackResidualTrackPhi01 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta12","stereo mm OnTrackResidualTrackPhi01 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta13","mm OnTrackResidualTrackPhi01 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta13","eta mm OnTrackResidualTrackPhi01 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta13","stereo mm OnTrackResidualTrackPhi01 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi01_eta14","mm OnTrackResidualTrackPhi01 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi01_eta14","eta mm OnTrackResidualTrackPhi01 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi01_eta14","stereo mm OnTrackResidualTrackPhi01 MS eta14 ", 400,-2,2);

///Phi02

   TH1F *h_mmOnTrackResidualTrackPhi02_eta1 = new TH1F("mmOnTrackResidualTrackPhi02_eta1","mm OnTrackResidualTrackPhi02 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta1","eta mm OnTrackResidualTrackPhi02 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta1","stereo mm OnTrackResidualTrackPhi02 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta2 = new TH1F("mmOnTrackResidualTrackPhi02_eta2","mm OnTrackResidualTrackPhi02 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta2","eta mm OnTrackResidualTrackPhi02 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta2","stereo mm OnTrackResidualTrackPhi02 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta3 = new TH1F("mmOnTrackResidualTrackPhi02_eta3","mm OnTrackResidualTrackPhi02 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta3","eta mm OnTrackResidualTrackPhi02 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta3","stereo mm OnTrackResidualTrackPhi02 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta4 = new TH1F("mmOnTrackResidualTrackPhi02_eta4","mm OnTrackResidualTrackPhi02 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta4","eta mm OnTrackResidualTrackPhi02 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta4","stereo mm OnTrackResidualTrackPhi02 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta5 = new TH1F("mmOnTrackResidualTrackPhi02_eta5","mm OnTrackResidualTrackPhi02 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta5","eta mm OnTrackResidualTrackPhi02 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta5","stereo mm OnTrackResidualTrackPhi02 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta6 = new TH1F("mmOnTrackResidualTrackPhi02_eta6","mm OnTrackResidualTrackPhi02 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta6","eta mm OnTrackResidualTrackPhi02 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta6","stereo mm OnTrackResidualTrackPhi02 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta7 = new TH1F("mmOnTrackResidualTrackPhi02_eta7","mm OnTrackResidualTrackPhi02 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta7","eta mm OnTrackResidualTrackPhi02 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta7","stereo mm OnTrackResidualTrackPhi02 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta8 = new TH1F("mmOnTrackResidualTrackPhi02_eta8","mm OnTrackResidualTrackPhi02 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta8","eta mm OnTrackResidualTrackPhi02 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta8","stereo mm OnTrackResidualTrackPhi02 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta9 = new TH1F("mmOnTrackResidualTrackPhi02_eta9","mm OnTrackResidualTrackPhi02 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta9","eta mm OnTrackResidualTrackPhi02 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta9","stereo mm OnTrackResidualTrackPhi02 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta10 = new TH1F("mmOnTrackResidualTrackPhi02_eta10","mm OnTrackResidualTrackPhi02 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta10","eta mm OnTrackResidualTrackPhi02 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta10","stereo mm OnTrackResidualTrackPhi02 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta11 = new TH1F("mmOnTrackResidualTrackPhi02_eta11","mm OnTrackResidualTrackPhi02 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta11","eta mm OnTrackResidualTrackPhi02 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta11","stereo mm OnTrackResidualTrackPhi02 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta12 = new TH1F("mmOnTrackResidualTrackPhi02_eta12","mm OnTrackResidualTrackPhi02 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta12","eta mm OnTrackResidualTrackPhi02 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta12","stereo mm OnTrackResidualTrackPhi02 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta13 = new TH1F("mmOnTrackResidualTrackPhi02_eta13","mm OnTrackResidualTrackPhi02 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta13","eta mm OnTrackResidualTrackPhi02 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta13","stereo mm OnTrackResidualTrackPhi02 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi02_eta14 = new TH1F("mmOnTrackResidualTrackPhi02_eta14","mm OnTrackResidualTrackPhi02 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi02_eta14","eta mm OnTrackResidualTrackPhi02 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi02_eta14","stereo mm OnTrackResidualTrackPhi02 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta1","mm OnTrackResidualTrackPhi02 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta1","eta mm OnTrackResidualTrackPhi02 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta1","stereo mm OnTrackResidualTrackPhi02 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta2","mm OnTrackResidualTrackPhi02 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta2","eta mm OnTrackResidualTrackPhi02 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta2","stereo mm OnTrackResidualTrackPhi02 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta3","mm OnTrackResidualTrackPhi02 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta3","eta mm OnTrackResidualTrackPhi02 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta3","stereo mm OnTrackResidualTrackPhi02 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta4","mm OnTrackResidualTrackPhi02 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta4","eta mm OnTrackResidualTrackPhi02 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta4","stereo mm OnTrackResidualTrackPhi02 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta5","mm OnTrackResidualTrackPhi02 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta5","eta mm OnTrackResidualTrackPhi02 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta5","stereo mm OnTrackResidualTrackPhi02 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta6","mm OnTrackResidualTrackPhi02 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta6","eta mm OnTrackResidualTrackPhi02 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta6","stereo mm OnTrackResidualTrackPhi02 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta7","mm OnTrackResidualTrackPhi02 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta7","eta mm OnTrackResidualTrackPhi02 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta7","stereo mm OnTrackResidualTrackPhi02 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta8","mm OnTrackResidualTrackPhi02 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta8","eta mm OnTrackResidualTrackPhi02 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta8","stereo mm OnTrackResidualTrackPhi02 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta9","mm OnTrackResidualTrackPhi02 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta9","eta mm OnTrackResidualTrackPhi02 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta9","stereo mm OnTrackResidualTrackPhi02 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta10","mm OnTrackResidualTrackPhi02 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta10","eta mm OnTrackResidualTrackPhi02 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta10","stereo mm OnTrackResidualTrackPhi02 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta11","mm OnTrackResidualTrackPhi02 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta11","eta mm OnTrackResidualTrackPhi02 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta11","stereo mm OnTrackResidualTrackPhi02 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta12","mm OnTrackResidualTrackPhi02 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta12","eta mm OnTrackResidualTrackPhi02 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta12","stereo mm OnTrackResidualTrackPhi02 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta13","mm OnTrackResidualTrackPhi02 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta13","eta mm OnTrackResidualTrackPhi02 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta13","stereo mm OnTrackResidualTrackPhi02 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi02_eta14","mm OnTrackResidualTrackPhi02 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi02_eta14","eta mm OnTrackResidualTrackPhi02 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi02_eta14","stereo mm OnTrackResidualTrackPhi02 MS eta14 ", 400,-2,2);

///Phi03

   TH1F *h_mmOnTrackResidualTrackPhi03_eta1 = new TH1F("mmOnTrackResidualTrackPhi03_eta1","mm OnTrackResidualTrackPhi03 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta1","eta mm OnTrackResidualTrackPhi03 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta1","stereo mm OnTrackResidualTrackPhi03 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta2 = new TH1F("mmOnTrackResidualTrackPhi03_eta2","mm OnTrackResidualTrackPhi03 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta2","eta mm OnTrackResidualTrackPhi03 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta2","stereo mm OnTrackResidualTrackPhi03 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta3 = new TH1F("mmOnTrackResidualTrackPhi03_eta3","mm OnTrackResidualTrackPhi03 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta3","eta mm OnTrackResidualTrackPhi03 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta3","stereo mm OnTrackResidualTrackPhi03 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta4 = new TH1F("mmOnTrackResidualTrackPhi03_eta4","mm OnTrackResidualTrackPhi03 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta4","eta mm OnTrackResidualTrackPhi03 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta4","stereo mm OnTrackResidualTrackPhi03 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta5 = new TH1F("mmOnTrackResidualTrackPhi03_eta5","mm OnTrackResidualTrackPhi03 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta5","eta mm OnTrackResidualTrackPhi03 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta5","stereo mm OnTrackResidualTrackPhi03 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta6 = new TH1F("mmOnTrackResidualTrackPhi03_eta6","mm OnTrackResidualTrackPhi03 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta6","eta mm OnTrackResidualTrackPhi03 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta6","stereo mm OnTrackResidualTrackPhi03 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta7 = new TH1F("mmOnTrackResidualTrackPhi03_eta7","mm OnTrackResidualTrackPhi03 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta7","eta mm OnTrackResidualTrackPhi03 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta7","stereo mm OnTrackResidualTrackPhi03 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta8 = new TH1F("mmOnTrackResidualTrackPhi03_eta8","mm OnTrackResidualTrackPhi03 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta8","eta mm OnTrackResidualTrackPhi03 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta8","stereo mm OnTrackResidualTrackPhi03 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta9 = new TH1F("mmOnTrackResidualTrackPhi03_eta9","mm OnTrackResidualTrackPhi03 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta9","eta mm OnTrackResidualTrackPhi03 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta9","stereo mm OnTrackResidualTrackPhi03 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta10 = new TH1F("mmOnTrackResidualTrackPhi03_eta10","mm OnTrackResidualTrackPhi03 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta10","eta mm OnTrackResidualTrackPhi03 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta10","stereo mm OnTrackResidualTrackPhi03 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta11 = new TH1F("mmOnTrackResidualTrackPhi03_eta11","mm OnTrackResidualTrackPhi03 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta11","eta mm OnTrackResidualTrackPhi03 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta11","stereo mm OnTrackResidualTrackPhi03 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta12 = new TH1F("mmOnTrackResidualTrackPhi03_eta12","mm OnTrackResidualTrackPhi03 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta12","eta mm OnTrackResidualTrackPhi03 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta12","stereo mm OnTrackResidualTrackPhi03 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta13 = new TH1F("mmOnTrackResidualTrackPhi03_eta13","mm OnTrackResidualTrackPhi03 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta13","eta mm OnTrackResidualTrackPhi03 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta13","stereo mm OnTrackResidualTrackPhi03 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi03_eta14 = new TH1F("mmOnTrackResidualTrackPhi03_eta14","mm OnTrackResidualTrackPhi03 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi03_eta14","eta mm OnTrackResidualTrackPhi03 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi03_eta14","stereo mm OnTrackResidualTrackPhi03 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta1","mm OnTrackResidualTrackPhi03 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta1","eta mm OnTrackResidualTrackPhi03 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta1","stereo mm OnTrackResidualTrackPhi03 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta2","mm OnTrackResidualTrackPhi03 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta2","eta mm OnTrackResidualTrackPhi03 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta2","stereo mm OnTrackResidualTrackPhi03 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta3","mm OnTrackResidualTrackPhi03 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta3","eta mm OnTrackResidualTrackPhi03 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta3","stereo mm OnTrackResidualTrackPhi03 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta4","mm OnTrackResidualTrackPhi03 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta4","eta mm OnTrackResidualTrackPhi03 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta4","stereo mm OnTrackResidualTrackPhi03 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta5","mm OnTrackResidualTrackPhi03 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta5","eta mm OnTrackResidualTrackPhi03 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta5","stereo mm OnTrackResidualTrackPhi03 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta6","mm OnTrackResidualTrackPhi03 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta6","eta mm OnTrackResidualTrackPhi03 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta6","stereo mm OnTrackResidualTrackPhi03 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta7","mm OnTrackResidualTrackPhi03 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta7","eta mm OnTrackResidualTrackPhi03 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta7","stereo mm OnTrackResidualTrackPhi03 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta8","mm OnTrackResidualTrackPhi03 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta8","eta mm OnTrackResidualTrackPhi03 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta8","stereo mm OnTrackResidualTrackPhi03 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta9","mm OnTrackResidualTrackPhi03 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta9","eta mm OnTrackResidualTrackPhi03 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta9","stereo mm OnTrackResidualTrackPhi03 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta10","mm OnTrackResidualTrackPhi03 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta10","eta mm OnTrackResidualTrackPhi03 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta10","stereo mm OnTrackResidualTrackPhi03 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta11","mm OnTrackResidualTrackPhi03 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta11","eta mm OnTrackResidualTrackPhi03 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta11","stereo mm OnTrackResidualTrackPhi03 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta12","mm OnTrackResidualTrackPhi03 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta12","eta mm OnTrackResidualTrackPhi03 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta12","stereo mm OnTrackResidualTrackPhi03 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta13","mm OnTrackResidualTrackPhi03 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta13","eta mm OnTrackResidualTrackPhi03 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta13","stereo mm OnTrackResidualTrackPhi03 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi03_eta14","mm OnTrackResidualTrackPhi03 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi03_eta14","eta mm OnTrackResidualTrackPhi03 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi03_eta14","stereo mm OnTrackResidualTrackPhi03 MS eta14 ", 400,-2,2);
///Phi04

   TH1F *h_mmOnTrackResidualTrackPhi04_eta1 = new TH1F("mmOnTrackResidualTrackPhi04_eta1","mm OnTrackResidualTrackPhi04 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta1","eta mm OnTrackResidualTrackPhi04 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta1","stereo mm OnTrackResidualTrackPhi04 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta2 = new TH1F("mmOnTrackResidualTrackPhi04_eta2","mm OnTrackResidualTrackPhi04 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta2","eta mm OnTrackResidualTrackPhi04 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta2","stereo mm OnTrackResidualTrackPhi04 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta3 = new TH1F("mmOnTrackResidualTrackPhi04_eta3","mm OnTrackResidualTrackPhi04 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta3","eta mm OnTrackResidualTrackPhi04 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta3","stereo mm OnTrackResidualTrackPhi04 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta4 = new TH1F("mmOnTrackResidualTrackPhi04_eta4","mm OnTrackResidualTrackPhi04 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta4","eta mm OnTrackResidualTrackPhi04 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta4","stereo mm OnTrackResidualTrackPhi04 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta5 = new TH1F("mmOnTrackResidualTrackPhi04_eta5","mm OnTrackResidualTrackPhi04 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta5","eta mm OnTrackResidualTrackPhi04 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta5","stereo mm OnTrackResidualTrackPhi04 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta6 = new TH1F("mmOnTrackResidualTrackPhi04_eta6","mm OnTrackResidualTrackPhi04 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta6","eta mm OnTrackResidualTrackPhi04 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta6","stereo mm OnTrackResidualTrackPhi04 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta7 = new TH1F("mmOnTrackResidualTrackPhi04_eta7","mm OnTrackResidualTrackPhi04 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta7","eta mm OnTrackResidualTrackPhi04 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta7","stereo mm OnTrackResidualTrackPhi04 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta8 = new TH1F("mmOnTrackResidualTrackPhi04_eta8","mm OnTrackResidualTrackPhi04 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta8","eta mm OnTrackResidualTrackPhi04 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta8","stereo mm OnTrackResidualTrackPhi04 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta9 = new TH1F("mmOnTrackResidualTrackPhi04_eta9","mm OnTrackResidualTrackPhi04 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta9","eta mm OnTrackResidualTrackPhi04 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta9","stereo mm OnTrackResidualTrackPhi04 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta10 = new TH1F("mmOnTrackResidualTrackPhi04_eta10","mm OnTrackResidualTrackPhi04 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta10","eta mm OnTrackResidualTrackPhi04 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta10","stereo mm OnTrackResidualTrackPhi04 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta11 = new TH1F("mmOnTrackResidualTrackPhi04_eta11","mm OnTrackResidualTrackPhi04 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta11","eta mm OnTrackResidualTrackPhi04 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta11","stereo mm OnTrackResidualTrackPhi04 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta12 = new TH1F("mmOnTrackResidualTrackPhi04_eta12","mm OnTrackResidualTrackPhi04 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta12","eta mm OnTrackResidualTrackPhi04 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta12","stereo mm OnTrackResidualTrackPhi04 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta13 = new TH1F("mmOnTrackResidualTrackPhi04_eta13","mm OnTrackResidualTrackPhi04 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta13","eta mm OnTrackResidualTrackPhi04 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta13","stereo mm OnTrackResidualTrackPhi04 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi04_eta14 = new TH1F("mmOnTrackResidualTrackPhi04_eta14","mm OnTrackResidualTrackPhi04 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi04_eta14","eta mm OnTrackResidualTrackPhi04 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi04_eta14","stereo mm OnTrackResidualTrackPhi04 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta1","mm OnTrackResidualTrackPhi04 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta1","eta mm OnTrackResidualTrackPhi04 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta1","stereo mm OnTrackResidualTrackPhi04 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta2","mm OnTrackResidualTrackPhi04 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta2","eta mm OnTrackResidualTrackPhi04 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta2","stereo mm OnTrackResidualTrackPhi04 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta3","mm OnTrackResidualTrackPhi04 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta3","eta mm OnTrackResidualTrackPhi04 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta3","stereo mm OnTrackResidualTrackPhi04 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta4","mm OnTrackResidualTrackPhi04 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta4","eta mm OnTrackResidualTrackPhi04 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta4","stereo mm OnTrackResidualTrackPhi04 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta5","mm OnTrackResidualTrackPhi04 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta5","eta mm OnTrackResidualTrackPhi04 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta5","stereo mm OnTrackResidualTrackPhi04 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta6","mm OnTrackResidualTrackPhi04 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta6","eta mm OnTrackResidualTrackPhi04 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta6","stereo mm OnTrackResidualTrackPhi04 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta7","mm OnTrackResidualTrackPhi04 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta7","eta mm OnTrackResidualTrackPhi04 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta7","stereo mm OnTrackResidualTrackPhi04 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta8","mm OnTrackResidualTrackPhi04 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta8","eta mm OnTrackResidualTrackPhi04 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta8","stereo mm OnTrackResidualTrackPhi04 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta9","mm OnTrackResidualTrackPhi04 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta9","eta mm OnTrackResidualTrackPhi04 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta9","stereo mm OnTrackResidualTrackPhi04 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta10","mm OnTrackResidualTrackPhi04 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta10","eta mm OnTrackResidualTrackPhi04 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta10","stereo mm OnTrackResidualTrackPhi04 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta11","mm OnTrackResidualTrackPhi04 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta11","eta mm OnTrackResidualTrackPhi04 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta11","stereo mm OnTrackResidualTrackPhi04 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta12","mm OnTrackResidualTrackPhi04 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta12","eta mm OnTrackResidualTrackPhi04 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta12","stereo mm OnTrackResidualTrackPhi04 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta13","mm OnTrackResidualTrackPhi04 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta13","eta mm OnTrackResidualTrackPhi04 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta13","stereo mm OnTrackResidualTrackPhi04 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi04_eta14","mm OnTrackResidualTrackPhi04 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi04_eta14","eta mm OnTrackResidualTrackPhi04 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi04_eta14","stereo mm OnTrackResidualTrackPhi04 MS eta14 ", 400,-2,2);

///Phi05

   TH1F *h_mmOnTrackResidualTrackPhi05_eta1 = new TH1F("mmOnTrackResidualTrackPhi05_eta1","mm OnTrackResidualTrackPhi05 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta1","eta mm OnTrackResidualTrackPhi05 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta1","stereo mm OnTrackResidualTrackPhi05 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta2 = new TH1F("mmOnTrackResidualTrackPhi05_eta2","mm OnTrackResidualTrackPhi05 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta2","eta mm OnTrackResidualTrackPhi05 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta2","stereo mm OnTrackResidualTrackPhi05 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta3 = new TH1F("mmOnTrackResidualTrackPhi05_eta3","mm OnTrackResidualTrackPhi05 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta3","eta mm OnTrackResidualTrackPhi05 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta3","stereo mm OnTrackResidualTrackPhi05 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta4 = new TH1F("mmOnTrackResidualTrackPhi05_eta4","mm OnTrackResidualTrackPhi05 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta4","eta mm OnTrackResidualTrackPhi05 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta4","stereo mm OnTrackResidualTrackPhi05 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta5 = new TH1F("mmOnTrackResidualTrackPhi05_eta5","mm OnTrackResidualTrackPhi05 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta5","eta mm OnTrackResidualTrackPhi05 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta5","stereo mm OnTrackResidualTrackPhi05 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta6 = new TH1F("mmOnTrackResidualTrackPhi05_eta6","mm OnTrackResidualTrackPhi05 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta6","eta mm OnTrackResidualTrackPhi05 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta6","stereo mm OnTrackResidualTrackPhi05 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta7 = new TH1F("mmOnTrackResidualTrackPhi05_eta7","mm OnTrackResidualTrackPhi05 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta7","eta mm OnTrackResidualTrackPhi05 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta7","stereo mm OnTrackResidualTrackPhi05 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta8 = new TH1F("mmOnTrackResidualTrackPhi05_eta8","mm OnTrackResidualTrackPhi05 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta8","eta mm OnTrackResidualTrackPhi05 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta8","stereo mm OnTrackResidualTrackPhi05 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta9 = new TH1F("mmOnTrackResidualTrackPhi05_eta9","mm OnTrackResidualTrackPhi05 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta9","eta mm OnTrackResidualTrackPhi05 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta9","stereo mm OnTrackResidualTrackPhi05 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta10 = new TH1F("mmOnTrackResidualTrackPhi05_eta10","mm OnTrackResidualTrackPhi05 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta10","eta mm OnTrackResidualTrackPhi05 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta10","stereo mm OnTrackResidualTrackPhi05 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta11 = new TH1F("mmOnTrackResidualTrackPhi05_eta11","mm OnTrackResidualTrackPhi05 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta11","eta mm OnTrackResidualTrackPhi05 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta11","stereo mm OnTrackResidualTrackPhi05 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta12 = new TH1F("mmOnTrackResidualTrackPhi05_eta12","mm OnTrackResidualTrackPhi05 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta12","eta mm OnTrackResidualTrackPhi05 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta12","stereo mm OnTrackResidualTrackPhi05 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta13 = new TH1F("mmOnTrackResidualTrackPhi05_eta13","mm OnTrackResidualTrackPhi05 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta13","eta mm OnTrackResidualTrackPhi05 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta13","stereo mm OnTrackResidualTrackPhi05 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi05_eta14 = new TH1F("mmOnTrackResidualTrackPhi05_eta14","mm OnTrackResidualTrackPhi05 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi05_eta14","eta mm OnTrackResidualTrackPhi05 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi05_eta14","stereo mm OnTrackResidualTrackPhi05 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta1","mm OnTrackResidualTrackPhi05 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta1","eta mm OnTrackResidualTrackPhi05 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta1","stereo mm OnTrackResidualTrackPhi05 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta2","mm OnTrackResidualTrackPhi05 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta2","eta mm OnTrackResidualTrackPhi05 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta2","stereo mm OnTrackResidualTrackPhi05 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta3","mm OnTrackResidualTrackPhi05 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta3","eta mm OnTrackResidualTrackPhi05 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta3","stereo mm OnTrackResidualTrackPhi05 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta4","mm OnTrackResidualTrackPhi05 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta4","eta mm OnTrackResidualTrackPhi05 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta4","stereo mm OnTrackResidualTrackPhi05 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta5","mm OnTrackResidualTrackPhi05 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta5","eta mm OnTrackResidualTrackPhi05 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta5","stereo mm OnTrackResidualTrackPhi05 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta6","mm OnTrackResidualTrackPhi05 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta6","eta mm OnTrackResidualTrackPhi05 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta6","stereo mm OnTrackResidualTrackPhi05 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta7","mm OnTrackResidualTrackPhi05 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta7","eta mm OnTrackResidualTrackPhi05 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta7","stereo mm OnTrackResidualTrackPhi05 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta8","mm OnTrackResidualTrackPhi05 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta8","eta mm OnTrackResidualTrackPhi05 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta8","stereo mm OnTrackResidualTrackPhi05 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta9","mm OnTrackResidualTrackPhi05 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta9","eta mm OnTrackResidualTrackPhi05 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta9","stereo mm OnTrackResidualTrackPhi05 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta10","mm OnTrackResidualTrackPhi05 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta10","eta mm OnTrackResidualTrackPhi05 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta10","stereo mm OnTrackResidualTrackPhi05 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta11","mm OnTrackResidualTrackPhi05 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta11","eta mm OnTrackResidualTrackPhi05 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta11","stereo mm OnTrackResidualTrackPhi05 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta12","mm OnTrackResidualTrackPhi05 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta12","eta mm OnTrackResidualTrackPhi05 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta12","stereo mm OnTrackResidualTrackPhi05 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta13","mm OnTrackResidualTrackPhi05 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta13","eta mm OnTrackResidualTrackPhi05 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta13","stereo mm OnTrackResidualTrackPhi05 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi05_eta14","mm OnTrackResidualTrackPhi05 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi05_eta14","eta mm OnTrackResidualTrackPhi05 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi05_eta14","stereo mm OnTrackResidualTrackPhi05 MS eta14 ", 400,-2,2);

///Phi06

   TH1F *h_mmOnTrackResidualTrackPhi06_eta1 = new TH1F("mmOnTrackResidualTrackPhi06_eta1","mm OnTrackResidualTrackPhi06 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta1","eta mm OnTrackResidualTrackPhi06 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta1","stereo mm OnTrackResidualTrackPhi06 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta2 = new TH1F("mmOnTrackResidualTrackPhi06_eta2","mm OnTrackResidualTrackPhi06 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta2","eta mm OnTrackResidualTrackPhi06 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta2","stereo mm OnTrackResidualTrackPhi06 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta3 = new TH1F("mmOnTrackResidualTrackPhi06_eta3","mm OnTrackResidualTrackPhi06 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta3","eta mm OnTrackResidualTrackPhi06 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta3","stereo mm OnTrackResidualTrackPhi06 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta4 = new TH1F("mmOnTrackResidualTrackPhi06_eta4","mm OnTrackResidualTrackPhi06 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta4","eta mm OnTrackResidualTrackPhi06 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta4","stereo mm OnTrackResidualTrackPhi06 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta5 = new TH1F("mmOnTrackResidualTrackPhi06_eta5","mm OnTrackResidualTrackPhi06 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta5","eta mm OnTrackResidualTrackPhi06 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta5","stereo mm OnTrackResidualTrackPhi06 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta6 = new TH1F("mmOnTrackResidualTrackPhi06_eta6","mm OnTrackResidualTrackPhi06 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta6","eta mm OnTrackResidualTrackPhi06 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta6","stereo mm OnTrackResidualTrackPhi06 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta7 = new TH1F("mmOnTrackResidualTrackPhi06_eta7","mm OnTrackResidualTrackPhi06 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta7","eta mm OnTrackResidualTrackPhi06 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta7","stereo mm OnTrackResidualTrackPhi06 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta8 = new TH1F("mmOnTrackResidualTrackPhi06_eta8","mm OnTrackResidualTrackPhi06 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta8","eta mm OnTrackResidualTrackPhi06 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta8","stereo mm OnTrackResidualTrackPhi06 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta9 = new TH1F("mmOnTrackResidualTrackPhi06_eta9","mm OnTrackResidualTrackPhi06 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta9","eta mm OnTrackResidualTrackPhi06 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta9","stereo mm OnTrackResidualTrackPhi06 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta10 = new TH1F("mmOnTrackResidualTrackPhi06_eta10","mm OnTrackResidualTrackPhi06 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta10","eta mm OnTrackResidualTrackPhi06 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta10","stereo mm OnTrackResidualTrackPhi06 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta11 = new TH1F("mmOnTrackResidualTrackPhi06_eta11","mm OnTrackResidualTrackPhi06 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta11","eta mm OnTrackResidualTrackPhi06 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta11","stereo mm OnTrackResidualTrackPhi06 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta12 = new TH1F("mmOnTrackResidualTrackPhi06_eta12","mm OnTrackResidualTrackPhi06 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta12","eta mm OnTrackResidualTrackPhi06 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta12","stereo mm OnTrackResidualTrackPhi06 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta13 = new TH1F("mmOnTrackResidualTrackPhi06_eta13","mm OnTrackResidualTrackPhi06 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta13","eta mm OnTrackResidualTrackPhi06 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta13","stereo mm OnTrackResidualTrackPhi06 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi06_eta14 = new TH1F("mmOnTrackResidualTrackPhi06_eta14","mm OnTrackResidualTrackPhi06 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi06_eta14","eta mm OnTrackResidualTrackPhi06 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi06_eta14","stereo mm OnTrackResidualTrackPhi06 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta1","mm OnTrackResidualTrackPhi06 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta1","eta mm OnTrackResidualTrackPhi06 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta1","stereo mm OnTrackResidualTrackPhi06 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta2","mm OnTrackResidualTrackPhi06 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta2","eta mm OnTrackResidualTrackPhi06 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta2","stereo mm OnTrackResidualTrackPhi06 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta3","mm OnTrackResidualTrackPhi06 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta3","eta mm OnTrackResidualTrackPhi06 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta3","stereo mm OnTrackResidualTrackPhi06 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta4","mm OnTrackResidualTrackPhi06 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta4","eta mm OnTrackResidualTrackPhi06 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta4","stereo mm OnTrackResidualTrackPhi06 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta5","mm OnTrackResidualTrackPhi06 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta5","eta mm OnTrackResidualTrackPhi06 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta5","stereo mm OnTrackResidualTrackPhi06 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta6","mm OnTrackResidualTrackPhi06 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta6","eta mm OnTrackResidualTrackPhi06 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta6","stereo mm OnTrackResidualTrackPhi06 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta7","mm OnTrackResidualTrackPhi06 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta7","eta mm OnTrackResidualTrackPhi06 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta7","stereo mm OnTrackResidualTrackPhi06 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta8","mm OnTrackResidualTrackPhi06 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta8","eta mm OnTrackResidualTrackPhi06 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta8","stereo mm OnTrackResidualTrackPhi06 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta9","mm OnTrackResidualTrackPhi06 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta9","eta mm OnTrackResidualTrackPhi06 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta9","stereo mm OnTrackResidualTrackPhi06 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta10","mm OnTrackResidualTrackPhi06 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta10","eta mm OnTrackResidualTrackPhi06 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta10","stereo mm OnTrackResidualTrackPhi06 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta11","mm OnTrackResidualTrackPhi06 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta11","eta mm OnTrackResidualTrackPhi06 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta11","stereo mm OnTrackResidualTrackPhi06 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta12","mm OnTrackResidualTrackPhi06 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta12","eta mm OnTrackResidualTrackPhi06 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta12","stereo mm OnTrackResidualTrackPhi06 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta13","mm OnTrackResidualTrackPhi06 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta13","eta mm OnTrackResidualTrackPhi06 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta13","stereo mm OnTrackResidualTrackPhi06 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi06_eta14","mm OnTrackResidualTrackPhi06 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi06_eta14","eta mm OnTrackResidualTrackPhi06 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi06_eta14","stereo mm OnTrackResidualTrackPhi06 MS eta14 ", 400,-2,2);

///Phi07

   TH1F *h_mmOnTrackResidualTrackPhi07_eta1 = new TH1F("mmOnTrackResidualTrackPhi07_eta1","mm OnTrackResidualTrackPhi07 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta1","eta mm OnTrackResidualTrackPhi07 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta1","stereo mm OnTrackResidualTrackPhi07 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta2 = new TH1F("mmOnTrackResidualTrackPhi07_eta2","mm OnTrackResidualTrackPhi07 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta2","eta mm OnTrackResidualTrackPhi07 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta2","stereo mm OnTrackResidualTrackPhi07 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta3 = new TH1F("mmOnTrackResidualTrackPhi07_eta3","mm OnTrackResidualTrackPhi07 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta3","eta mm OnTrackResidualTrackPhi07 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta3","stereo mm OnTrackResidualTrackPhi07 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta4 = new TH1F("mmOnTrackResidualTrackPhi07_eta4","mm OnTrackResidualTrackPhi07 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta4","eta mm OnTrackResidualTrackPhi07 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta4","stereo mm OnTrackResidualTrackPhi07 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta5 = new TH1F("mmOnTrackResidualTrackPhi07_eta5","mm OnTrackResidualTrackPhi07 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta5","eta mm OnTrackResidualTrackPhi07 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta5","stereo mm OnTrackResidualTrackPhi07 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta6 = new TH1F("mmOnTrackResidualTrackPhi07_eta6","mm OnTrackResidualTrackPhi07 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta6","eta mm OnTrackResidualTrackPhi07 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta6","stereo mm OnTrackResidualTrackPhi07 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta7 = new TH1F("mmOnTrackResidualTrackPhi07_eta7","mm OnTrackResidualTrackPhi07 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta7","eta mm OnTrackResidualTrackPhi07 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta7","stereo mm OnTrackResidualTrackPhi07 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta8 = new TH1F("mmOnTrackResidualTrackPhi07_eta8","mm OnTrackResidualTrackPhi07 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta8","eta mm OnTrackResidualTrackPhi07 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta8","stereo mm OnTrackResidualTrackPhi07 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta9 = new TH1F("mmOnTrackResidualTrackPhi07_eta9","mm OnTrackResidualTrackPhi07 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta9","eta mm OnTrackResidualTrackPhi07 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta9","stereo mm OnTrackResidualTrackPhi07 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta10 = new TH1F("mmOnTrackResidualTrackPhi07_eta10","mm OnTrackResidualTrackPhi07 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta10","eta mm OnTrackResidualTrackPhi07 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta10","stereo mm OnTrackResidualTrackPhi07 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta11 = new TH1F("mmOnTrackResidualTrackPhi07_eta11","mm OnTrackResidualTrackPhi07 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta11","eta mm OnTrackResidualTrackPhi07 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta11","stereo mm OnTrackResidualTrackPhi07 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta12 = new TH1F("mmOnTrackResidualTrackPhi07_eta12","mm OnTrackResidualTrackPhi07 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta12","eta mm OnTrackResidualTrackPhi07 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta12","stereo mm OnTrackResidualTrackPhi07 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta13 = new TH1F("mmOnTrackResidualTrackPhi07_eta13","mm OnTrackResidualTrackPhi07 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta13","eta mm OnTrackResidualTrackPhi07 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta13","stereo mm OnTrackResidualTrackPhi07 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi07_eta14 = new TH1F("mmOnTrackResidualTrackPhi07_eta14","mm OnTrackResidualTrackPhi07 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi07_eta14","eta mm OnTrackResidualTrackPhi07 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi07_eta14","stereo mm OnTrackResidualTrackPhi07 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta1","mm OnTrackResidualTrackPhi07 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta1","eta mm OnTrackResidualTrackPhi07 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta1","stereo mm OnTrackResidualTrackPhi07 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta2","mm OnTrackResidualTrackPhi07 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta2","eta mm OnTrackResidualTrackPhi07 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta2","stereo mm OnTrackResidualTrackPhi07 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta3","mm OnTrackResidualTrackPhi07 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta3","eta mm OnTrackResidualTrackPhi07 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta3","stereo mm OnTrackResidualTrackPhi07 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta4","mm OnTrackResidualTrackPhi07 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta4","eta mm OnTrackResidualTrackPhi07 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta4","stereo mm OnTrackResidualTrackPhi07 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta5","mm OnTrackResidualTrackPhi07 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta5","eta mm OnTrackResidualTrackPhi07 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta5","stereo mm OnTrackResidualTrackPhi07 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta6","mm OnTrackResidualTrackPhi07 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta6","eta mm OnTrackResidualTrackPhi07 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta6","stereo mm OnTrackResidualTrackPhi07 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta7","mm OnTrackResidualTrackPhi07 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta7","eta mm OnTrackResidualTrackPhi07 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta7","stereo mm OnTrackResidualTrackPhi07 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta8","mm OnTrackResidualTrackPhi07 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta8","eta mm OnTrackResidualTrackPhi07 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta8","stereo mm OnTrackResidualTrackPhi07 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta9","mm OnTrackResidualTrackPhi07 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta9","eta mm OnTrackResidualTrackPhi07 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta9","stereo mm OnTrackResidualTrackPhi07 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta10","mm OnTrackResidualTrackPhi07 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta10","eta mm OnTrackResidualTrackPhi07 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta10","stereo mm OnTrackResidualTrackPhi07 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta11","mm OnTrackResidualTrackPhi07 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta11","eta mm OnTrackResidualTrackPhi07 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta11","stereo mm OnTrackResidualTrackPhi07 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta12","mm OnTrackResidualTrackPhi07 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta12","eta mm OnTrackResidualTrackPhi07 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta12","stereo mm OnTrackResidualTrackPhi07 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta13","mm OnTrackResidualTrackPhi07 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta13","eta mm OnTrackResidualTrackPhi07 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta13","stereo mm OnTrackResidualTrackPhi07 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi07_eta14","mm OnTrackResidualTrackPhi07 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi07_eta14","eta mm OnTrackResidualTrackPhi07 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi07_eta14","stereo mm OnTrackResidualTrackPhi07 MS eta14 ", 400,-2,2);
///Phi08

   TH1F *h_mmOnTrackResidualTrackPhi08_eta1 = new TH1F("mmOnTrackResidualTrackPhi08_eta1","mm OnTrackResidualTrackPhi08 eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta1 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta1","eta mm OnTrackResidualTrackPhi08 eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta1 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta1","stereo mm OnTrackResidualTrackPhi08 eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta2 = new TH1F("mmOnTrackResidualTrackPhi08_eta2","mm OnTrackResidualTrackPhi08 eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta2 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta2","eta mm OnTrackResidualTrackPhi08 eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta2 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta2","stereo mm OnTrackResidualTrackPhi08 eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta3 = new TH1F("mmOnTrackResidualTrackPhi08_eta3","mm OnTrackResidualTrackPhi08 eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta3 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta3","eta mm OnTrackResidualTrackPhi08 eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta3 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta3","stereo mm OnTrackResidualTrackPhi08 eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta4 = new TH1F("mmOnTrackResidualTrackPhi08_eta4","mm OnTrackResidualTrackPhi08 eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta4 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta4","eta mm OnTrackResidualTrackPhi08 eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta4 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta4","stereo mm OnTrackResidualTrackPhi08 eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta5 = new TH1F("mmOnTrackResidualTrackPhi08_eta5","mm OnTrackResidualTrackPhi08 eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta5 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta5","eta mm OnTrackResidualTrackPhi08 eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta5 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta5","stereo mm OnTrackResidualTrackPhi08 eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta6 = new TH1F("mmOnTrackResidualTrackPhi08_eta6","mm OnTrackResidualTrackPhi08 eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta6 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta6","eta mm OnTrackResidualTrackPhi08 eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta6 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta6","stereo mm OnTrackResidualTrackPhi08 eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta7 = new TH1F("mmOnTrackResidualTrackPhi08_eta7","mm OnTrackResidualTrackPhi08 eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta7 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta7","eta mm OnTrackResidualTrackPhi08 eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta7 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta7","stereo mm OnTrackResidualTrackPhi08 eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta8 = new TH1F("mmOnTrackResidualTrackPhi08_eta8","mm OnTrackResidualTrackPhi08 eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta8 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta8","eta mm OnTrackResidualTrackPhi08 eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta8 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta8","stereo mm OnTrackResidualTrackPhi08 eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta9 = new TH1F("mmOnTrackResidualTrackPhi08_eta9","mm OnTrackResidualTrackPhi08 eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta9 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta9","eta mm OnTrackResidualTrackPhi08 eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta9 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta9","stereo mm OnTrackResidualTrackPhi08 eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta10 = new TH1F("mmOnTrackResidualTrackPhi08_eta10","mm OnTrackResidualTrackPhi08 eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta10 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta10","eta mm OnTrackResidualTrackPhi08 eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta10 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta10","stereo mm OnTrackResidualTrackPhi08 eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta11 = new TH1F("mmOnTrackResidualTrackPhi08_eta11","mm OnTrackResidualTrackPhi08 eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta11 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta11","eta mm OnTrackResidualTrackPhi08 eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta11 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta11","stereo mm OnTrackResidualTrackPhi08 eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta12 = new TH1F("mmOnTrackResidualTrackPhi08_eta12","mm OnTrackResidualTrackPhi08 eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta12 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta12","eta mm OnTrackResidualTrackPhi08 eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta12 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta12","stereo mm OnTrackResidualTrackPhi08 eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta13 = new TH1F("mmOnTrackResidualTrackPhi08_eta13","mm OnTrackResidualTrackPhi08 eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta13 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta13","eta mm OnTrackResidualTrackPhi08 eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta13 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta13","stereo mm OnTrackResidualTrackPhi08 eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackPhi08_eta14 = new TH1F("mmOnTrackResidualTrackPhi08_eta14","mm OnTrackResidualTrackPhi08 eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta14 = new TH1F("eta_mmOnTrackResidualTrackPhi08_eta14","eta mm OnTrackResidualTrackPhi08 eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta14 = new TH1F("stereo_mmOnTrackResidualTrackPhi08_eta14","stereo mm OnTrackResidualTrackPhi08 eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta1 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta1","mm OnTrackResidualTrackPhi08 MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta1","eta mm OnTrackResidualTrackPhi08 MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta1","stereo mm OnTrackResidualTrackPhi08 MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta2 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta2","mm OnTrackResidualTrackPhi08 MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta2","eta mm OnTrackResidualTrackPhi08 MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta2","stereo mm OnTrackResidualTrackPhi08 MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta3 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta3","mm OnTrackResidualTrackPhi08 MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta3","eta mm OnTrackResidualTrackPhi08 MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta3","stereo mm OnTrackResidualTrackPhi08 MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta4 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta4","mm OnTrackResidualTrackPhi08 MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta4","eta mm OnTrackResidualTrackPhi08 MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta4","stereo mm OnTrackResidualTrackPhi08 MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta5 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta5","mm OnTrackResidualTrackPhi08 MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta5","eta mm OnTrackResidualTrackPhi08 MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta5","stereo mm OnTrackResidualTrackPhi08 MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta6 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta6","mm OnTrackResidualTrackPhi08 MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta6","eta mm OnTrackResidualTrackPhi08 MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta6","stereo mm OnTrackResidualTrackPhi08 MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta7 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta7","mm OnTrackResidualTrackPhi08 MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta7","eta mm OnTrackResidualTrackPhi08 MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta7","stereo mm OnTrackResidualTrackPhi08 MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta8 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta8","mm OnTrackResidualTrackPhi08 MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta8","eta mm OnTrackResidualTrackPhi08 MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta8","stereo mm OnTrackResidualTrackPhi08 MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta9 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta9","mm OnTrackResidualTrackPhi08 MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta9","eta mm OnTrackResidualTrackPhi08 MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta9","stereo mm OnTrackResidualTrackPhi08 MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta10 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta10","mm OnTrackResidualTrackPhi08 MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta10","eta mm OnTrackResidualTrackPhi08 MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta10","stereo mm OnTrackResidualTrackPhi08 MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta11 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta11","mm OnTrackResidualTrackPhi08 MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta11","eta mm OnTrackResidualTrackPhi08 MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta11","stereo mm OnTrackResidualTrackPhi08 MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta12 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta12","mm OnTrackResidualTrackPhi08 MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta12","eta mm OnTrackResidualTrackPhi08 MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta12","stereo mm OnTrackResidualTrackPhi08 MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta13 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta13","mm OnTrackResidualTrackPhi08 MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta13","eta mm OnTrackResidualTrackPhi08 MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta13","stereo mm OnTrackResidualTrackPhi08 MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta14 = new TH1F("mmOnTrackResidualTrackMSPhi08_eta14","mm OnTrackResidualTrackPhi08 MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSPhi08_eta14","eta mm OnTrackResidualTrackPhi08 MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSPhi08_eta14","stereo mm OnTrackResidualTrackPhi08 MS eta14 ", 400,-2,2);

///LargeSector

   TH1F *h_mmOnTrackResidualTrackLargeSector_eta1 = new TH1F("mmOnTrackResidualTrackLargeSector_eta1","mm OnTrackResidualTrackLargeSector eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta1 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta1","eta mm OnTrackResidualTrackLargeSector eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta1 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta1","stereo mm OnTrackResidualTrackLargeSector eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta2 = new TH1F("mmOnTrackResidualTrackLargeSector_eta2","mm OnTrackResidualTrackLargeSector eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta2 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta2","eta mm OnTrackResidualTrackLargeSector eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta2 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta2","stereo mm OnTrackResidualTrackLargeSector eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta3 = new TH1F("mmOnTrackResidualTrackLargeSector_eta3","mm OnTrackResidualTrackLargeSector eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta3 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta3","eta mm OnTrackResidualTrackLargeSector eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta3 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta3","stereo mm OnTrackResidualTrackLargeSector eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta4 = new TH1F("mmOnTrackResidualTrackLargeSector_eta4","mm OnTrackResidualTrackLargeSector eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta4 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta4","eta mm OnTrackResidualTrackLargeSector eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta4 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta4","stereo mm OnTrackResidualTrackLargeSector eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta5 = new TH1F("mmOnTrackResidualTrackLargeSector_eta5","mm OnTrackResidualTrackLargeSector eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta5 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta5","eta mm OnTrackResidualTrackLargeSector eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta5 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta5","stereo mm OnTrackResidualTrackLargeSector eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta6 = new TH1F("mmOnTrackResidualTrackLargeSector_eta6","mm OnTrackResidualTrackLargeSector eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta6 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta6","eta mm OnTrackResidualTrackLargeSector eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta6 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta6","stereo mm OnTrackResidualTrackLargeSector eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta7 = new TH1F("mmOnTrackResidualTrackLargeSector_eta7","mm OnTrackResidualTrackLargeSector eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta7 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta7","eta mm OnTrackResidualTrackLargeSector eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta7 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta7","stereo mm OnTrackResidualTrackLargeSector eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta8 = new TH1F("mmOnTrackResidualTrackLargeSector_eta8","mm OnTrackResidualTrackLargeSector eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta8 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta8","eta mm OnTrackResidualTrackLargeSector eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta8 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta8","stereo mm OnTrackResidualTrackLargeSector eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta9 = new TH1F("mmOnTrackResidualTrackLargeSector_eta9","mm OnTrackResidualTrackLargeSector eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta9 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta9","eta mm OnTrackResidualTrackLargeSector eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta9 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta9","stereo mm OnTrackResidualTrackLargeSector eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta10 = new TH1F("mmOnTrackResidualTrackLargeSector_eta10","mm OnTrackResidualTrackLargeSector eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta10 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta10","eta mm OnTrackResidualTrackLargeSector eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta10 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta10","stereo mm OnTrackResidualTrackLargeSector eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta11 = new TH1F("mmOnTrackResidualTrackLargeSector_eta11","mm OnTrackResidualTrackLargeSector eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta11 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta11","eta mm OnTrackResidualTrackLargeSector eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta11 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta11","stereo mm OnTrackResidualTrackLargeSector eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta12 = new TH1F("mmOnTrackResidualTrackLargeSector_eta12","mm OnTrackResidualTrackLargeSector eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta12 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta12","eta mm OnTrackResidualTrackLargeSector eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta12 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta12","stereo mm OnTrackResidualTrackLargeSector eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta13 = new TH1F("mmOnTrackResidualTrackLargeSector_eta13","mm OnTrackResidualTrackLargeSector eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta13 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta13","eta mm OnTrackResidualTrackLargeSector eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta13 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta13","stereo mm OnTrackResidualTrackLargeSector eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta14 = new TH1F("mmOnTrackResidualTrackLargeSector_eta14","mm OnTrackResidualTrackLargeSector eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta14 = new TH1F("eta_mmOnTrackResidualTrackLargeSector_eta14","eta mm OnTrackResidualTrackLargeSector eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta14 = new TH1F("stereo_mmOnTrackResidualTrackLargeSector_eta14","stereo mm OnTrackResidualTrackLargeSector eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta1 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta1","mm OnTrackResidualTrackLargeSector MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta1","eta mm OnTrackResidualTrackLargeSector MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta1","stereo mm OnTrackResidualTrackLargeSector MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta2 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta2","mm OnTrackResidualTrackLargeSector MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta2","eta mm OnTrackResidualTrackLargeSector MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta2","stereo mm OnTrackResidualTrackLargeSector MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta3 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta3","mm OnTrackResidualTrackLargeSector MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta3","eta mm OnTrackResidualTrackLargeSector MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta3","stereo mm OnTrackResidualTrackLargeSector MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta4 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta4","mm OnTrackResidualTrackLargeSector MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta4","eta mm OnTrackResidualTrackLargeSector MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta4","stereo mm OnTrackResidualTrackLargeSector MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta5 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta5","mm OnTrackResidualTrackLargeSector MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta5","eta mm OnTrackResidualTrackLargeSector MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta5","stereo mm OnTrackResidualTrackLargeSector MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta6 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta6","mm OnTrackResidualTrackLargeSector MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta6","eta mm OnTrackResidualTrackLargeSector MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta6","stereo mm OnTrackResidualTrackLargeSector MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta7 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta7","mm OnTrackResidualTrackLargeSector MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta7","eta mm OnTrackResidualTrackLargeSector MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta7","stereo mm OnTrackResidualTrackLargeSector MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta8 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta8","mm OnTrackResidualTrackLargeSector MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta8","eta mm OnTrackResidualTrackLargeSector MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta8","stereo mm OnTrackResidualTrackLargeSector MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta9 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta9","mm OnTrackResidualTrackLargeSector MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta9","eta mm OnTrackResidualTrackLargeSector MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta9","stereo mm OnTrackResidualTrackLargeSector MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta10 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta10","mm OnTrackResidualTrackLargeSector MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta10","eta mm OnTrackResidualTrackLargeSector MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta10","stereo mm OnTrackResidualTrackLargeSector MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta11 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta11","mm OnTrackResidualTrackLargeSector MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta11","eta mm OnTrackResidualTrackLargeSector MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta11","stereo mm OnTrackResidualTrackLargeSector MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta12 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta12","mm OnTrackResidualTrackLargeSector MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta12","eta mm OnTrackResidualTrackLargeSector MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta12","stereo mm OnTrackResidualTrackLargeSector MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta13 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta13","mm OnTrackResidualTrackLargeSector MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta13","eta mm OnTrackResidualTrackLargeSector MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta13","stereo mm OnTrackResidualTrackLargeSector MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta14 = new TH1F("mmOnTrackResidualTrackMSLargeSector_eta14","mm OnTrackResidualTrackLargeSector MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSLargeSector_eta14","eta mm OnTrackResidualTrackLargeSector MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSLargeSector_eta14","stereo mm OnTrackResidualTrackLargeSector MS eta14 ", 400,-2,2);

///SmallSector

   TH1F *h_mmOnTrackResidualTrackSmallSector_eta1 = new TH1F("mmOnTrackResidualTrackSmallSector_eta1","mm OnTrackResidualTrackSmallSector eta1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta1 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta1","eta mm OnTrackResidualTrackSmallSector eta1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta1 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta1","stereo mm OnTrackResidualTrackSmallSector eta1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta2 = new TH1F("mmOnTrackResidualTrackSmallSector_eta2","mm OnTrackResidualTrackSmallSector eta2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta2 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta2","eta mm OnTrackResidualTrackSmallSector eta2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta2 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta2","stereo mm OnTrackResidualTrackSmallSector eta2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta3 = new TH1F("mmOnTrackResidualTrackSmallSector_eta3","mm OnTrackResidualTrackSmallSector eta3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta3 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta3","eta mm OnTrackResidualTrackSmallSector eta3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta3 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta3","stereo mm OnTrackResidualTrackSmallSector eta3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta4 = new TH1F("mmOnTrackResidualTrackSmallSector_eta4","mm OnTrackResidualTrackSmallSector eta4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta4 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta4","eta mm OnTrackResidualTrackSmallSector eta4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta4 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta4","stereo mm OnTrackResidualTrackSmallSector eta4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta5 = new TH1F("mmOnTrackResidualTrackSmallSector_eta5","mm OnTrackResidualTrackSmallSector eta5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta5 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta5","eta mm OnTrackResidualTrackSmallSector eta5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta5 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta5","stereo mm OnTrackResidualTrackSmallSector eta5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta6 = new TH1F("mmOnTrackResidualTrackSmallSector_eta6","mm OnTrackResidualTrackSmallSector eta6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta6 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta6","eta mm OnTrackResidualTrackSmallSector eta6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta6 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta6","stereo mm OnTrackResidualTrackSmallSector eta6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta7 = new TH1F("mmOnTrackResidualTrackSmallSector_eta7","mm OnTrackResidualTrackSmallSector eta7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta7 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta7","eta mm OnTrackResidualTrackSmallSector eta7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta7 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta7","stereo mm OnTrackResidualTrackSmallSector eta7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta8 = new TH1F("mmOnTrackResidualTrackSmallSector_eta8","mm OnTrackResidualTrackSmallSector eta8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta8 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta8","eta mm OnTrackResidualTrackSmallSector eta8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta8 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta8","stereo mm OnTrackResidualTrackSmallSector eta8 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta9 = new TH1F("mmOnTrackResidualTrackSmallSector_eta9","mm OnTrackResidualTrackSmallSector eta9 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta9 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta9","eta mm OnTrackResidualTrackSmallSector eta9 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta9 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta9","stereo mm OnTrackResidualTrackSmallSector eta9 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta10 = new TH1F("mmOnTrackResidualTrackSmallSector_eta10","mm OnTrackResidualTrackSmallSector eta10 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta10 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta10","eta mm OnTrackResidualTrackSmallSector eta10 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta10 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta10","stereo mm OnTrackResidualTrackSmallSector eta10 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta11 = new TH1F("mmOnTrackResidualTrackSmallSector_eta11","mm OnTrackResidualTrackSmallSector eta11 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta11 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta11","eta mm OnTrackResidualTrackSmallSector eta11 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta11 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta11","stereo mm OnTrackResidualTrackSmallSector eta11 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta12 = new TH1F("mmOnTrackResidualTrackSmallSector_eta12","mm OnTrackResidualTrackSmallSector eta12 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta12 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta12","eta mm OnTrackResidualTrackSmallSector eta12 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta12 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta12","stereo mm OnTrackResidualTrackSmallSector eta12 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta13 = new TH1F("mmOnTrackResidualTrackSmallSector_eta13","mm OnTrackResidualTrackSmallSector eta13 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta13 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta13","eta mm OnTrackResidualTrackSmallSector eta13 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta13 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta13","stereo mm OnTrackResidualTrackSmallSector eta13 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta14 = new TH1F("mmOnTrackResidualTrackSmallSector_eta14","mm OnTrackResidualTrackSmallSector eta14 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta14 = new TH1F("eta_mmOnTrackResidualTrackSmallSector_eta14","eta mm OnTrackResidualTrackSmallSector eta14 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta14 = new TH1F("stereo_mmOnTrackResidualTrackSmallSector_eta14","stereo mm OnTrackResidualTrackSmallSector eta14 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta1 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta1","mm OnTrackResidualTrackSmallSector MS eta1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta1 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta1","eta mm OnTrackResidualTrackSmallSector MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta1","stereo mm OnTrackResidualTrackSmallSector MS eta1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta2 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta2","mm OnTrackResidualTrackSmallSector MS eta2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta2 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta2","eta mm OnTrackResidualTrackSmallSector MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta2","stereo mm OnTrackResidualTrackSmallSector MS eta2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta3 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta3","mm OnTrackResidualTrackSmallSector MS eta3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta3 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta3","eta mm OnTrackResidualTrackSmallSector MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta3","stereo mm OnTrackResidualTrackSmallSector MS eta3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta4 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta4","mm OnTrackResidualTrackSmallSector MS eta4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta4 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta4","eta mm OnTrackResidualTrackSmallSector MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta4","stereo mm OnTrackResidualTrackSmallSector MS eta4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta5 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta5","mm OnTrackResidualTrackSmallSector MS eta5 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta5 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta5","eta mm OnTrackResidualTrackSmallSector MS eta5 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta5","stereo mm OnTrackResidualTrackSmallSector MS eta5 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta6 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta6","mm OnTrackResidualTrackSmallSector MS eta6 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta6 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta6","eta mm OnTrackResidualTrackSmallSector MS eta6 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta6","stereo mm OnTrackResidualTrackSmallSector MS eta6 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta7 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta7","mm OnTrackResidualTrackSmallSector MS eta7 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta7 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta7","eta mm OnTrackResidualTrackSmallSector MS eta7 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta7","stereo mm OnTrackResidualTrackSmallSector MS eta7 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta8 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta8","mm OnTrackResidualTrackSmallSector MS eta8 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta8 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta8","eta mm OnTrackResidualTrackSmallSector MS eta8 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta8","stereo mm OnTrackResidualTrackSmallSector MS eta8 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta9 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta9","mm OnTrackResidualTrackSmallSector MS eta9 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta9 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta9","eta mm OnTrackResidualTrackSmallSector MS eta9 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta9","stereo mm OnTrackResidualTrackSmallSector MS eta9 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta10 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta10","mm OnTrackResidualTrackSmallSector MS eta10 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta10 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta10","eta mm OnTrackResidualTrackSmallSector MS eta10 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta10","stereo mm OnTrackResidualTrackSmallSector MS eta10 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta11 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta11","mm OnTrackResidualTrackSmallSector MS eta11 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta11 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta11","eta mm OnTrackResidualTrackSmallSector MS eta11 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta11","stereo mm OnTrackResidualTrackSmallSector MS eta11 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta12 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta12","mm OnTrackResidualTrackSmallSector MS eta12 ", 800,-4,4);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta12 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta12","eta mm OnTrackResidualTrackSmallSector MS eta12 ", 800,-4,4);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta12","stereo mm OnTrackResidualTrackSmallSector MS eta12 ", 800,-4,4);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta13 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta13","mm OnTrackResidualTrackSmallSector MS eta13 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta13 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta13","eta mm OnTrackResidualTrackSmallSector MS eta13 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta13","stereo mm OnTrackResidualTrackSmallSector MS eta13 ", 400,-2,2);
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta14 = new TH1F("mmOnTrackResidualTrackMSSmallSector_eta14","mm OnTrackResidualTrackSmallSector MS eta14 ", 400,-2,2);
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta14 = new TH1F("eta_mmOnTrackResidualTrackMSSmallSector_eta14","eta mm OnTrackResidualTrackSmallSector MS eta14 ", 400,-2,2);
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14 = new TH1F("stereo_mmOnTrackResidualTrackMSSmallSector_eta14","stereo mm OnTrackResidualTrackSmallSector MS eta14 ", 400,-2,2);

//theta

   TH1F *h_mmOnTrackResidualTrack_PCB1_theta = new TH1F("mmOnTrackResidualTrack_PCB1_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB1_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB1_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB1_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB1_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB2_theta = new TH1F("mmOnTrackResidualTrack_PCB2_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB2_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB2_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB2_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB2_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB3_theta = new TH1F("mmOnTrackResidualTrack_PCB3_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB3_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB3_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB3_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB3_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB4_theta = new TH1F("mmOnTrackResidualTrack_PCB4_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB4_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB4_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB4_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB4_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB5_theta = new TH1F("mmOnTrackResidualTrack_PCB5_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB5_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB5_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB5_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB5_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB6_theta = new TH1F("mmOnTrackResidualTrack_PCB6_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB6_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB6_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB6_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB6_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB7_theta = new TH1F("mmOnTrackResidualTrack_PCB7_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB7_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB7_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB7_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB7_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_PCB8_theta = new TH1F("mmOnTrackResidualTrack_PCB8_theta","mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_PCB8_theta = new TH1F("eta_mmOnTrackResidualTrack_PCB8_theta","eta mm OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_PCB8_theta = new TH1F("stereo_mmOnTrackResidualTrack_PCB8_theta","stereo mm OnTrackResidualTrack theta ", 1200,-6,6);
   
   TH1F *h_mmOnTrackResidualTrackMS_PCB1_theta = new TH1F("mmOnTrackResidualTrackMS_PCB1_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB1_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB1_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB2_theta = new TH1F("mmOnTrackResidualTrackMS_PCB2_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB2_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB2_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB3_theta = new TH1F("mmOnTrackResidualTrackMS_PCB3_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB3_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB3_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB4_theta = new TH1F("mmOnTrackResidualTrackMS_PCB4_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB4_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB4_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB5_theta = new TH1F("mmOnTrackResidualTrackMS_PCB5_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB5_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB5_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB6_theta = new TH1F("mmOnTrackResidualTrackMS_PCB6_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB6_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB6_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB7_theta = new TH1F("mmOnTrackResidualTrackMS_PCB7_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB7_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB7_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_PCB8_theta = new TH1F("mmOnTrackResidualTrackMS_PCB8_theta","mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8_theta = new TH1F("eta_mmOnTrackResidualTrackMS_PCB8_theta","eta mm OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8_theta = new TH1F("stereo_mmOnTrackResidualTrackMS_PCB8_theta","stereo mm OnTrackResidualTrack MS theta ", 1200,-6,6);

//phi

   TH1F *h_mmOnTrackResidualTrack_phi1 = new TH1F("mmOnTrackResidualTrack_phi1","mm OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi1 = new TH1F("eta_mmOnTrackResidualTrack_phi1","eta mm OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi1 = new TH1F("stereo_mmOnTrackResidualTrack_phi1","stereo mm OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi2 = new TH1F("mmOnTrackResidualTrack_phi2","mm OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi2 = new TH1F("eta_mmOnTrackResidualTrack_phi2","eta mm OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi2 = new TH1F("stereo_mmOnTrackResidualTrack_phi2","stereo mm OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi3 = new TH1F("mmOnTrackResidualTrack_phi3","mm OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi3 = new TH1F("eta_mmOnTrackResidualTrack_phi3","eta mm OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi3 = new TH1F("stereo_mmOnTrackResidualTrack_phi3","stereo mm OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi4 = new TH1F("mmOnTrackResidualTrack_phi4","mm OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi4 = new TH1F("eta_mmOnTrackResidualTrack_phi4","eta mm OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi4 = new TH1F("stereo_mmOnTrackResidualTrack_phi4","stereo mm OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi5 = new TH1F("mmOnTrackResidualTrack_phi5","mm OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi5 = new TH1F("eta_mmOnTrackResidualTrack_phi5","eta mm OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi5 = new TH1F("stereo_mmOnTrackResidualTrack_phi5","stereo mm OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi6 = new TH1F("mmOnTrackResidualTrack_phi6","mm OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi6 = new TH1F("eta_mmOnTrackResidualTrack_phi6","eta mm OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi6 = new TH1F("stereo_mmOnTrackResidualTrack_phi6","stereo mm OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi7 = new TH1F("mmOnTrackResidualTrack_phi7","mm OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi7 = new TH1F("eta_mmOnTrackResidualTrack_phi7","eta mm OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi7 = new TH1F("stereo_mmOnTrackResidualTrack_phi7","stereo mm OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrack_phi8 = new TH1F("mmOnTrackResidualTrack_phi8","mm OnTrackResidualTrack phi8 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrack_phi8 = new TH1F("eta_mmOnTrackResidualTrack_phi8","eta mm OnTrackResidualTrack phi8 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrack_phi8 = new TH1F("stereo_mmOnTrackResidualTrack_phi8","stereo mm OnTrackResidualTrack phi8 ", 1200,-6,6);

   TH1F *h_mmOnTrackResidualTrackMS_phi1 = new TH1F("mmOnTrackResidualTrackMS_phi1","mm OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi1 = new TH1F("eta_mmOnTrackResidualTrackMS_phi1","eta mm OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi1 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi1","stereo mm OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi2 = new TH1F("mmOnTrackResidualTrackMS_phi2","mm OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi2 = new TH1F("eta_mmOnTrackResidualTrackMS_phi2","eta mm OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi2 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi2","stereo mm OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi3 = new TH1F("mmOnTrackResidualTrackMS_phi3","mm OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi3 = new TH1F("eta_mmOnTrackResidualTrackMS_phi3","eta mm OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi3 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi3","stereo mm OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi4 = new TH1F("mmOnTrackResidualTrackMS_phi4","mm OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi4 = new TH1F("eta_mmOnTrackResidualTrackMS_phi4","eta mm OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi4 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi4","stereo mm OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi5 = new TH1F("mmOnTrackResidualTrackMS_phi5","mm OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi5 = new TH1F("eta_mmOnTrackResidualTrackMS_phi5","eta mm OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi5 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi5","stereo mm OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi6 = new TH1F("mmOnTrackResidualTrackMS_phi6","mm OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi6 = new TH1F("eta_mmOnTrackResidualTrackMS_phi6","eta mm OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi6 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi6","stereo mm OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi7 = new TH1F("mmOnTrackResidualTrackMS_phi7","mm OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi7 = new TH1F("eta_mmOnTrackResidualTrackMS_phi7","eta mm OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi7 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi7","stereo mm OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_mmOnTrackResidualTrackMS_phi8 = new TH1F("mmOnTrackResidualTrackMS_phi8","mm OnTrackResidualTrack MS phi8 ", 1200,-6,6);
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi8 = new TH1F("eta_mmOnTrackResidualTrackMS_phi8","eta mm OnTrackResidualTrack MS phi8 ", 1200,-6,6);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi8 = new TH1F("stereo_mmOnTrackResidualTrackMS_phi8","stereo mm OnTrackResidualTrack MS phi8 ", 1200,-6,6);

//

   TH1F *h_mmOnTrackResidualTrack_x12_PCB1 = new TH1F("mmOnTrackResidualTrack_x12_PCB1","mm OnTrackResidualTrack x12 PCB1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB1 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB1","eta mm OnTrackResidualTrack x12 PCB1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB1 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB1","stereo mm OnTrackResidualTrack x12 PCB1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB2 = new TH1F("mmOnTrackResidualTrack_x12_PCB2","mm OnTrackResidualTrack x12 PCB2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB2 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB2","eta mm OnTrackResidualTrack x12 PCB2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB2 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB2","stereo mm OnTrackResidualTrack x12 PCB2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB3 = new TH1F("mmOnTrackResidualTrack_x12_PCB3","mm OnTrackResidualTrack x12 PCB3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB3 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB3","eta mm OnTrackResidualTrack x12 PCB3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB3 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB3","stereo mm OnTrackResidualTrack x12 PCB3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB4 = new TH1F("mmOnTrackResidualTrack_x12_PCB4","mm OnTrackResidualTrack x12 PCB4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB4 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB4","eta mm OnTrackResidualTrack x12 PCB4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB4 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB4","stereo mm OnTrackResidualTrack x12 PCB4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB5 = new TH1F("mmOnTrackResidualTrack_x12_PCB5","mm OnTrackResidualTrack x12 PCB5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB5 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB5","eta mm OnTrackResidualTrack x12 PCB5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB5 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB5","stereo mm OnTrackResidualTrack x12 PCB5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB6 = new TH1F("mmOnTrackResidualTrack_x12_PCB6","mm OnTrackResidualTrack x12 PCB6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB6 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB6","eta mm OnTrackResidualTrack x12 PCB6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB6 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB6","stereo mm OnTrackResidualTrack x12 PCB6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB7 = new TH1F("mmOnTrackResidualTrack_x12_PCB7","mm OnTrackResidualTrack x12 PCB7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB7 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB7","eta mm OnTrackResidualTrack x12 PCB7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB7 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB7","stereo mm OnTrackResidualTrack x12 PCB7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x12_PCB8 = new TH1F("mmOnTrackResidualTrack_x12_PCB8","mm OnTrackResidualTrack x12 PCB8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x12_PCB8 = new TH1F("eta_mmOnTrackResidualTrack_x12_PCB8","eta mm OnTrackResidualTrack x12 PCB8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x12_PCB8 = new TH1F("stereo_mmOnTrackResidualTrack_x12_PCB8","stereo mm OnTrackResidualTrack x12 PCB8 ", 2000,-10,10);

   TH1F *h_mmOnTrackResidualTrack_x34_PCB1 = new TH1F("mmOnTrackResidualTrack_x34_PCB1","mm OnTrackResidualTrack x34 PCB1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB1 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB1","eta mm OnTrackResidualTrack x34 PCB1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB1 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB1","stereo mm OnTrackResidualTrack x34 PCB1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB2 = new TH1F("mmOnTrackResidualTrack_x34_PCB2","mm OnTrackResidualTrack x34 PCB2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB2 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB2","eta mm OnTrackResidualTrack x34 PCB2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB2 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB2","stereo mm OnTrackResidualTrack x34 PCB2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB3 = new TH1F("mmOnTrackResidualTrack_x34_PCB3","mm OnTrackResidualTrack x34 PCB3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB3 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB3","eta mm OnTrackResidualTrack x34 PCB3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB3 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB3","stereo mm OnTrackResidualTrack x34 PCB3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB4 = new TH1F("mmOnTrackResidualTrack_x34_PCB4","mm OnTrackResidualTrack x34 PCB4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB4 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB4","eta mm OnTrackResidualTrack x34 PCB4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB4 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB4","stereo mm OnTrackResidualTrack x34 PCB4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB5 = new TH1F("mmOnTrackResidualTrack_x34_PCB5","mm OnTrackResidualTrack x34 PCB5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB5 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB5","eta mm OnTrackResidualTrack x34 PCB5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB5 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB5","stereo mm OnTrackResidualTrack x34 PCB5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB6 = new TH1F("mmOnTrackResidualTrack_x34_PCB6","mm OnTrackResidualTrack x34 PCB6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB6 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB6","eta mm OnTrackResidualTrack x34 PCB6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB6 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB6","stereo mm OnTrackResidualTrack x34 PCB6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB7 = new TH1F("mmOnTrackResidualTrack_x34_PCB7","mm OnTrackResidualTrack x34 PCB7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB7 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB7","eta mm OnTrackResidualTrack x34 PCB7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB7 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB7","stereo mm OnTrackResidualTrack x34 PCB7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrack_x34_PCB8 = new TH1F("mmOnTrackResidualTrack_x34_PCB8","mm OnTrackResidualTrack x34 PCB8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrack_x34_PCB8 = new TH1F("eta_mmOnTrackResidualTrack_x34_PCB8","eta mm OnTrackResidualTrack x34 PCB8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrack_x34_PCB8 = new TH1F("stereo_mmOnTrackResidualTrack_x34_PCB8","stereo mm OnTrackResidualTrack x34 PCB8 ", 2000,-10,10);

   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB1 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB1","mm OnTrackResidualTrackMS x12 PCB1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB1 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB1","eta mm OnTrackResidualTrackMS x12 PCB1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB1 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB1","stereo mm OnTrackResidualTrackMS x12 PCB1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB2 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB2","mm OnTrackResidualTrackMS x12 PCB2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB2 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB2","eta mm OnTrackResidualTrackMS x12 PCB2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB2 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB2","stereo mm OnTrackResidualTrackMS x12 PCB2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB3 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB3","mm OnTrackResidualTrackMS x12 PCB3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB3 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB3","eta mm OnTrackResidualTrackMS x12 PCB3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB3 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB3","stereo mm OnTrackResidualTrackMS x12 PCB3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB4 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB4","mm OnTrackResidualTrackMS x12 PCB4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB4 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB4","eta mm OnTrackResidualTrackMS x12 PCB4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB4 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB4","stereo mm OnTrackResidualTrackMS x12 PCB4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB5 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB5","mm OnTrackResidualTrackMS x12 PCB5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB5 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB5","eta mm OnTrackResidualTrackMS x12 PCB5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB5 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB5","stereo mm OnTrackResidualTrackMS x12 PCB5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB6 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB6","mm OnTrackResidualTrackMS x12 PCB6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB6 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB6","eta mm OnTrackResidualTrackMS x12 PCB6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB6 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB6","stereo mm OnTrackResidualTrackMS x12 PCB6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB7 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB7","mm OnTrackResidualTrackMS x12 PCB7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB7 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB7","eta mm OnTrackResidualTrackMS x12 PCB7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB7 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB7","stereo mm OnTrackResidualTrackMS x12 PCB7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x12_PCB8 = new TH1F("mmOnTrackResidualTrackMS_x12_PCB8","mm OnTrackResidualTrackMS x12 PCB8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x12_PCB8 = new TH1F("eta_mmOnTrackResidualTrackMS_x12_PCB8","eta mm OnTrackResidualTrackMS x12 PCB8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x12_PCB8 = new TH1F("stereo_mmOnTrackResidualTrackMS_x12_PCB8","stereo mm OnTrackResidualTrackMS x12 PCB8 ", 2000,-10,10);

   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB1 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB1","mm OnTrackResidualTrackMS x34 PCB1 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB1 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB1","eta mm OnTrackResidualTrackMS x34 PCB1 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB1 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB1","stereo mm OnTrackResidualTrackMS x34 PCB1 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB2 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB2","mm OnTrackResidualTrackMS x34 PCB2 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB2 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB2","eta mm OnTrackResidualTrackMS x34 PCB2 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB2 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB2","stereo mm OnTrackResidualTrackMS x34 PCB2 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB3 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB3","mm OnTrackResidualTrackMS x34 PCB3 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB3 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB3","eta mm OnTrackResidualTrackMS x34 PCB3 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB3 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB3","stereo mm OnTrackResidualTrackMS x34 PCB3 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB4 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB4","mm OnTrackResidualTrackMS x34 PCB4 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB4 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB4","eta mm OnTrackResidualTrackMS x34 PCB4 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB4 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB4","stereo mm OnTrackResidualTrackMS x34 PCB4 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB5 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB5","mm OnTrackResidualTrackMS x34 PCB5 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB5 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB5","eta mm OnTrackResidualTrackMS x34 PCB5 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB5 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB5","stereo mm OnTrackResidualTrackMS x34 PCB5 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB6 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB6","mm OnTrackResidualTrackMS x34 PCB6 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB6 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB6","eta mm OnTrackResidualTrackMS x34 PCB6 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB6 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB6","stereo mm OnTrackResidualTrackMS x34 PCB6 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB7 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB7","mm OnTrackResidualTrackMS x34 PCB7 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB7 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB7","eta mm OnTrackResidualTrackMS x34 PCB7 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB7 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB7","stereo mm OnTrackResidualTrackMS x34 PCB7 ", 2000,-10,10);
   TH1F *h_mmOnTrackResidualTrackMS_x34_PCB8 = new TH1F("mmOnTrackResidualTrackMS_x34_PCB8","mm OnTrackResidualTrackMS x34 PCB8 ", 2000,-10,10);
   TH1F *h_eta_mmOnTrackResidualTrackMS_x34_PCB8 = new TH1F("eta_mmOnTrackResidualTrackMS_x34_PCB8","eta mm OnTrackResidualTrackMS x34 PCB8 ", 2000,-10,10);
   TH1F *h_stereo_mmOnTrackResidualTrackMS_x34_PCB8 = new TH1F("stereo_mmOnTrackResidualTrackMS_x34_PCB8","stereo mm OnTrackResidualTrackMS x34 PCB8 ", 2000,-10,10);
////////////////////////////////small-strip Thin Gap Chambers
   TH1F *h_stgcOnTrackResidualTrack = new TH1F("stgcOnTrackResidualTrack","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrackMS = new TH1F("stgcOnTrackResidualTrackMS","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_pt20 = new TH1F("stgcOnTrackResidualTrack_pt20","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrackMS_pt20 = new TH1F("stgcOnTrackResidualTrackMS_pt20","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_ST1 = new TH1F("stgcOnTrackResidualTrack_ST1","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_ST2 = new TH1F("stgcOnTrackResidualTrack_ST2","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrackMS_ST1 = new TH1F("stgcOnTrackResidualTrackMS_ST1","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_ST2 = new TH1F("stgcOnTrackResidualTrackMS_ST2","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_ST1 = new TH1F("eta_stgcOnTrackResidualTrack_ST1","eta stgc OnTrackResidualTrack ST1 ", 8000,-20,20);
   TH1F *h_eta_stgcOnTrackResidualTrack_ST2 = new TH1F("eta_stgcOnTrackResidualTrack_ST2","eta stgc OnTrackResidualTrack ST2 ", 4000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_ST1 = new TH1F("eta_stgcOnTrackResidualTrackMS_ST1","eta stgc OnTrackResidualTrack MS ST1 ", 8000,-20,20);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_ST2 = new TH1F("eta_stgcOnTrackResidualTrackMS_ST2","eta stgc OnTrackResidualTrack MS ST2 ", 4000,-10,10);

   TH1F *h_stgcOnTrackResidualTrack_PhiST1 = new TH1F("stgcOnTrackResidualTrack_PhiST1","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST2 = new TH1F("stgcOnTrackResidualTrack_PhiST2","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST3 = new TH1F("stgcOnTrackResidualTrack_PhiST3","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST4 = new TH1F("stgcOnTrackResidualTrack_PhiST4","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST5 = new TH1F("stgcOnTrackResidualTrack_PhiST5","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST6 = new TH1F("stgcOnTrackResidualTrack_PhiST6","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST7 = new TH1F("stgcOnTrackResidualTrack_PhiST7","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrack_PhiST8 = new TH1F("stgcOnTrackResidualTrack_PhiST8","stgc OnTrackResidualTrack ", 8000,-20,20);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST1 = new TH1F("stgcOnTrackResidualTrackMS_PhiST1","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST2 = new TH1F("stgcOnTrackResidualTrackMS_PhiST2","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST3 = new TH1F("stgcOnTrackResidualTrackMS_PhiST3","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST4 = new TH1F("stgcOnTrackResidualTrackMS_PhiST4","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST5 = new TH1F("stgcOnTrackResidualTrackMS_PhiST5","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST6 = new TH1F("stgcOnTrackResidualTrackMS_PhiST6","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST7 = new TH1F("stgcOnTrackResidualTrackMS_PhiST7","stgc OnTrackResidualTrack MS ", 4000,-10,10);
   TH1F *h_stgcOnTrackResidualTrackMS_PhiST8 = new TH1F("stgcOnTrackResidualTrackMS_PhiST8","stgc OnTrackResidualTrack MS ", 4000,-10,10);

   TH1F *h_stgcOnTrackResidualTrack_PCB1 = new TH1F("stgcOnTrackResidualTrack_PCB1","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB1 = new TH1F("eta_stgcOnTrackResidualTrack_PCB1","eta stgc OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB1 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB1","stereo stgc OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB2 = new TH1F("stgcOnTrackResidualTrack_PCB2","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB2 = new TH1F("eta_stgcOnTrackResidualTrack_PCB2","eta stgc OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB2 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB2","stereo stgc OnTrackResidualTrack ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB3 = new TH1F("stgcOnTrackResidualTrack_PCB3","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB3 = new TH1F("eta_stgcOnTrackResidualTrack_PCB3","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB3 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB3","stereo stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stgcOnTrackResidualTrack_PCB4 = new TH1F("stgcOnTrackResidualTrack_PCB4","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB4 = new TH1F("eta_stgcOnTrackResidualTrack_PCB4","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB4 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB4","stereo stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stgcOnTrackResidualTrack_PCB5 = new TH1F("stgcOnTrackResidualTrack_PCB5","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB5 = new TH1F("eta_stgcOnTrackResidualTrack_PCB5","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB5 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB5","stereo stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stgcOnTrackResidualTrack_PCB6 = new TH1F("stgcOnTrackResidualTrack_PCB6","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB6 = new TH1F("eta_stgcOnTrackResidualTrack_PCB6","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB6 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB6","stereo stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stgcOnTrackResidualTrack_PCB7 = new TH1F("stgcOnTrackResidualTrack_PCB7","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB7 = new TH1F("eta_stgcOnTrackResidualTrack_PCB7","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB7 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB7","stereo stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stgcOnTrackResidualTrack_PCB8 = new TH1F("stgcOnTrackResidualTrack_PCB8","stgc OnTrackResidualTrack ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB8 = new TH1F("eta_stgcOnTrackResidualTrack_PCB8","eta stgc OnTrackResidualTrack ", 1000,-5,5);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB8 = new TH1F("stereo_stgcOnTrackResidualTrack_PCB8","stereo stgc OnTrackResidualTrack ", 1000,-5,5);

   TH1F *h_stgcOnTrackResidualTrackMS_PCB1 = new TH1F("stgcOnTrackResidualTrackMS_PCB1","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB1 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB1","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB1 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB1","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB2 = new TH1F("stgcOnTrackResidualTrackMS_PCB2","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB2 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB2","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB2 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB2","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB3 = new TH1F("stgcOnTrackResidualTrackMS_PCB3","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB3 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB3","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB3 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB3","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB4 = new TH1F("stgcOnTrackResidualTrackMS_PCB4","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB4 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB4","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB4 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB4","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB5 = new TH1F("stgcOnTrackResidualTrackMS_PCB5","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB5 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB5","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB5 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB5","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB6 = new TH1F("stgcOnTrackResidualTrackMS_PCB6","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB6 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB6","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB6 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB6","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB7 = new TH1F("stgcOnTrackResidualTrackMS_PCB7","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB7 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB7","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB7 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB7","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB8 = new TH1F("stgcOnTrackResidualTrackMS_PCB8","stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB8 = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB8","eta stgc OnTrackResidualTrack MS ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB8 = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB8","stereo stgc OnTrackResidualTrack MS ", 1200,-6,6);

   TH1F *h_stgcOnTrack_channel = new TH1F("stgcOnTrack_channel","stgc OnTrack channel ", 5100,0,5100);
   TH1F *h_stgcOnTrack_channel_pt20 =  new TH1F("stgcOnTrack_channel_pt20","stgc OnTrack channel ", 5100,0,5100);
   TH1F *h_stgcOnTrack_stationEta =  new TH1F("stgcOnTrack_stationEta","stgc OnTrack station Eta ", 8,-4,4);
   TH1F *h_stgcOnTrack_stationPhi =  new TH1F("stgcOnTrack_stationPhi","stgc OnTrack station Phi ", 9,0,9);

   TH1F *h_stgcOnTrack_gas_gap = new TH1F("stgcOnTrack_gas_gap","stgc OnTrack gas gap",6,0,6); 

   TH1F *h_stgchitmuons_theta = new TH1F("stgchitmuons_theta","stgc hit muons theta",50,0.1,0.6);
   TH1F *h_stgchitmuons_phi = new TH1F("stgchitmuons_phi","stgc hit muons phi",320,0,3.2);

//eta

   TH1F *h_stgcOnTrackResidualTrack_eta1 = new TH1F("stgcOnTrackResidualTrack_eta1","stgc OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta1 = new TH1F("eta_stgcOnTrackResidualTrack_eta1","eta stgc OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta1 = new TH1F("stereo_stgcOnTrackResidualTrack_eta1","stereo stgc OnTrackResidualTrack eta1 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta2 = new TH1F("stgcOnTrackResidualTrack_eta2","stgc OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta2 = new TH1F("eta_stgcOnTrackResidualTrack_eta2","eta stgc OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta2 = new TH1F("stereo_stgcOnTrackResidualTrack_eta2","stereo stgc OnTrackResidualTrack eta2 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta3 = new TH1F("stgcOnTrackResidualTrack_eta3","stgc OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta3 = new TH1F("eta_stgcOnTrackResidualTrack_eta3","eta stgc OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta3 = new TH1F("stereo_stgcOnTrackResidualTrack_eta3","stereo stgc OnTrackResidualTrack eta3 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta4 = new TH1F("stgcOnTrackResidualTrack_eta4","stgc OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta4 = new TH1F("eta_stgcOnTrackResidualTrack_eta4","eta stgc OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta4 = new TH1F("stereo_stgcOnTrackResidualTrack_eta4","stereo stgc OnTrackResidualTrack eta4 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta5 = new TH1F("stgcOnTrackResidualTrack_eta5","stgc OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta5 = new TH1F("eta_stgcOnTrackResidualTrack_eta5","eta stgc OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta5 = new TH1F("stereo_stgcOnTrackResidualTrack_eta5","stereo stgc OnTrackResidualTrack eta5 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta6 = new TH1F("stgcOnTrackResidualTrack_eta6","stgc OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta6 = new TH1F("eta_stgcOnTrackResidualTrack_eta6","eta stgc OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta6 = new TH1F("stereo_stgcOnTrackResidualTrack_eta6","stereo stgc OnTrackResidualTrack eta6 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta7 = new TH1F("stgcOnTrackResidualTrack_eta7","stgc OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta7 = new TH1F("eta_stgcOnTrackResidualTrack_eta7","eta stgc OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta7 = new TH1F("stereo_stgcOnTrackResidualTrack_eta7","stereo stgc OnTrackResidualTrack eta7 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta8 = new TH1F("stgcOnTrackResidualTrack_eta8","stgc OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta8 = new TH1F("eta_stgcOnTrackResidualTrack_eta8","eta stgc OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta8 = new TH1F("stereo_stgcOnTrackResidualTrack_eta8","stereo stgc OnTrackResidualTrack eta8 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta9 = new TH1F("stgcOnTrackResidualTrack_eta9","stgc OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta9 = new TH1F("eta_stgcOnTrackResidualTrack_eta9","eta stgc OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta9 = new TH1F("stereo_stgcOnTrackResidualTrack_eta9","stereo stgc OnTrackResidualTrack eta9 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta10 = new TH1F("stgcOnTrackResidualTrack_eta10","stgc OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta10 = new TH1F("eta_stgcOnTrackResidualTrack_eta10","eta stgc OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta10 = new TH1F("stereo_stgcOnTrackResidualTrack_eta10","stereo stgc OnTrackResidualTrack eta10 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta11 = new TH1F("stgcOnTrackResidualTrack_eta11","stgc OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta11 = new TH1F("eta_stgcOnTrackResidualTrack_eta11","eta stgc OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta11 = new TH1F("stereo_stgcOnTrackResidualTrack_eta11","stereo stgc OnTrackResidualTrack eta11 ", 2000,-10,10);
   TH1F *h_stgcOnTrackResidualTrack_eta12 = new TH1F("stgcOnTrackResidualTrack_eta12","stgc OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta12 = new TH1F("eta_stgcOnTrackResidualTrack_eta12","eta stgc OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta12 = new TH1F("stereo_stgcOnTrackResidualTrack_eta12","stereo stgc OnTrackResidualTrack eta12 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_eta13 = new TH1F("stgcOnTrackResidualTrack_eta13","stgc OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta13 = new TH1F("eta_stgcOnTrackResidualTrack_eta13","eta stgc OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta13 = new TH1F("stereo_stgcOnTrackResidualTrack_eta13","stereo stgc OnTrackResidualTrack eta13 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_eta14 = new TH1F("stgcOnTrackResidualTrack_eta14","stgc OnTrackResidualTrack eta14 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_eta14 = new TH1F("eta_stgcOnTrackResidualTrack_eta14","eta stgc OnTrackResidualTrack eta14 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_eta14 = new TH1F("stereo_stgcOnTrackResidualTrack_eta14","stereo stgc OnTrackResidualTrack eta14 ", 1200,-6,6);

   TH1F *h_stgcOnTrackResidualTrackMS_eta1 = new TH1F("stgcOnTrackResidualTrackMS_eta1","stgc OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta1 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta1","eta stgc OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta1 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta1","stereo stgc OnTrackResidualTrack MS eta1 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_eta2 = new TH1F("stgcOnTrackResidualTrackMS_eta2","stgc OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta2 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta2","eta stgc OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta2 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta2","stereo stgc OnTrackResidualTrack MS eta2 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_eta3 = new TH1F("stgcOnTrackResidualTrackMS_eta3","stgc OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta3 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta3","eta stgc OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta3 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta3","stereo stgc OnTrackResidualTrack MS eta3 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_eta4 = new TH1F("stgcOnTrackResidualTrackMS_eta4","stgc OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta4 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta4","eta stgc OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta4 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta4","stereo stgc OnTrackResidualTrack MS eta4 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_eta5 = new TH1F("stgcOnTrackResidualTrackMS_eta5","stgc OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta5 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta5","eta stgc OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta5 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta5","stereo stgc OnTrackResidualTrack MS eta5 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta6 = new TH1F("stgcOnTrackResidualTrackMS_eta6","stgc OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta6 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta6","eta stgc OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta6 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta6","stereo stgc OnTrackResidualTrack MS eta6 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta7 = new TH1F("stgcOnTrackResidualTrackMS_eta7","stgc OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta7 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta7","eta stgc OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta7 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta7","stereo stgc OnTrackResidualTrack MS eta7 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta8 = new TH1F("stgcOnTrackResidualTrackMS_eta8","stgc OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta8 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta8","eta stgc OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta8 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta8","stereo stgc OnTrackResidualTrack MS eta8 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta9 = new TH1F("stgcOnTrackResidualTrackMS_eta9","stgc OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta9 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta9","eta stgc OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta9 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta9","stereo stgc OnTrackResidualTrack MS eta9 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta10 = new TH1F("stgcOnTrackResidualTrackMS_eta10","stgc OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta10 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta10","eta stgc OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta10 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta10","stereo stgc OnTrackResidualTrack MS eta10 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta11 = new TH1F("stgcOnTrackResidualTrackMS_eta11","stgc OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta11 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta11","eta stgc OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta11 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta11","stereo stgc OnTrackResidualTrack MS eta11 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta12 = new TH1F("stgcOnTrackResidualTrackMS_eta12","stgc OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta12 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta12","eta stgc OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta12 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta12","stereo stgc OnTrackResidualTrack MS eta12 ", 800,-4,4);
   TH1F *h_stgcOnTrackResidualTrackMS_eta13 = new TH1F("stgcOnTrackResidualTrackMS_eta13","stgc OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta13 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta13","eta stgc OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta13 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta13","stereo stgc OnTrackResidualTrack MS eta13 ", 400,-2,2);
   TH1F *h_stgcOnTrackResidualTrackMS_eta14 = new TH1F("stgcOnTrackResidualTrackMS_eta14","stgc OnTrackResidualTrack MS eta14 ", 400,-2,2);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_eta14 = new TH1F("eta_stgcOnTrackResidualTrackMS_eta14","eta stgc OnTrackResidualTrack MS eta14 ", 400,-2,2);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_eta14 = new TH1F("stereo_stgcOnTrackResidualTrackMS_eta14","stereo stgc OnTrackResidualTrack MS eta14 ", 400,-2,2);

//theta

   TH1F *h_stgcOnTrackResidualTrack_PCB1_theta = new TH1F("stgcOnTrackResidualTrack_PCB1_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB1_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB1_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB1_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB1_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB2_theta = new TH1F("stgcOnTrackResidualTrack_PCB2_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB2_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB2_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB2_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB2_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB3_theta = new TH1F("stgcOnTrackResidualTrack_PCB3_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB3_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB3_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB3_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB3_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB4_theta = new TH1F("stgcOnTrackResidualTrack_PCB4_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB4_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB4_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB4_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB4_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB5_theta = new TH1F("stgcOnTrackResidualTrack_PCB5_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB5_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB5_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB5_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB5_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB6_theta = new TH1F("stgcOnTrackResidualTrack_PCB6_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB6_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB6_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB6_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB6_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB7_theta = new TH1F("stgcOnTrackResidualTrack_PCB7_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB7_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB7_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB7_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB7_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_PCB8_theta = new TH1F("stgcOnTrackResidualTrack_PCB8_theta","stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_PCB8_theta = new TH1F("eta_stgcOnTrackResidualTrack_PCB8_theta","eta stgc OnTrackResidualTrack theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_PCB8_theta = new TH1F("stereo_stgcOnTrackResidualTrack_PCB8_theta","stereo stgc OnTrackResidualTrack theta ", 1200,-6,6);
   
   TH1F *h_stgcOnTrackResidualTrackMS_PCB1_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB1_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB1_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB1_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB1_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB1_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB2_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB2_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB2_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB2_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB2_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB2_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB3_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB3_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB3_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB3_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB3_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB3_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB4_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB4_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB4_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB4_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB4_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB4_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB5_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB5_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB5_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB5_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB5_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB5_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB6_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB6_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB6_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB6_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB6_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB6_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB7_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB7_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB7_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB7_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB7_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB7_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_PCB8_theta = new TH1F("stgcOnTrackResidualTrackMS_PCB8_theta","stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_PCB8_theta = new TH1F("eta_stgcOnTrackResidualTrackMS_PCB8_theta","eta stgc OnTrackResidualTrack MS theta ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_PCB8_theta = new TH1F("stereo_stgcOnTrackResidualTrackMS_PCB8_theta","stereo stgc OnTrackResidualTrack MS theta ", 1200,-6,6);

//phi

   TH1F *h_stgcOnTrackResidualTrack_phi1 = new TH1F("stgcOnTrackResidualTrack_phi1","stgc OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi1 = new TH1F("eta_stgcOnTrackResidualTrack_phi1","eta stgc OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi1 = new TH1F("stereo_stgcOnTrackResidualTrack_phi1","stereo stgc OnTrackResidualTrack phi1 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi2 = new TH1F("stgcOnTrackResidualTrack_phi2","stgc OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi2 = new TH1F("eta_stgcOnTrackResidualTrack_phi2","eta stgc OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi2 = new TH1F("stereo_stgcOnTrackResidualTrack_phi2","stereo stgc OnTrackResidualTrack phi2 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi3 = new TH1F("stgcOnTrackResidualTrack_phi3","stgc OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi3 = new TH1F("eta_stgcOnTrackResidualTrack_phi3","eta stgc OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi3 = new TH1F("stereo_stgcOnTrackResidualTrack_phi3","stereo stgc OnTrackResidualTrack phi3 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi4 = new TH1F("stgcOnTrackResidualTrack_phi4","stgc OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi4 = new TH1F("eta_stgcOnTrackResidualTrack_phi4","eta stgc OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi4 = new TH1F("stereo_stgcOnTrackResidualTrack_phi4","stereo stgc OnTrackResidualTrack phi4 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi5 = new TH1F("stgcOnTrackResidualTrack_phi5","stgc OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi5 = new TH1F("eta_stgcOnTrackResidualTrack_phi5","eta stgc OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi5 = new TH1F("stereo_stgcOnTrackResidualTrack_phi5","stereo stgc OnTrackResidualTrack phi5 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi6 = new TH1F("stgcOnTrackResidualTrack_phi6","stgc OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi6 = new TH1F("eta_stgcOnTrackResidualTrack_phi6","eta stgc OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi6 = new TH1F("stereo_stgcOnTrackResidualTrack_phi6","stereo stgc OnTrackResidualTrack phi6 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi7 = new TH1F("stgcOnTrackResidualTrack_phi7","stgc OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi7 = new TH1F("eta_stgcOnTrackResidualTrack_phi7","eta stgc OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi7 = new TH1F("stereo_stgcOnTrackResidualTrack_phi7","stereo stgc OnTrackResidualTrack phi7 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrack_phi8 = new TH1F("stgcOnTrackResidualTrack_phi8","stgc OnTrackResidualTrack phi8 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrack_phi8 = new TH1F("eta_stgcOnTrackResidualTrack_phi8","eta stgc OnTrackResidualTrack phi8 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrack_phi8 = new TH1F("stereo_stgcOnTrackResidualTrack_phi8","stereo stgc OnTrackResidualTrack phi8 ", 1200,-6,6);

   TH1F *h_stgcOnTrackResidualTrackMS_phi1 = new TH1F("stgcOnTrackResidualTrackMS_phi1","stgc OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi1 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi1","eta stgc OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi1 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi1","stereo stgc OnTrackResidualTrack MS phi1 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi2 = new TH1F("stgcOnTrackResidualTrackMS_phi2","stgc OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi2 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi2","eta stgc OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi2 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi2","stereo stgc OnTrackResidualTrack MS phi2 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi3 = new TH1F("stgcOnTrackResidualTrackMS_phi3","stgc OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi3 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi3","eta stgc OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi3 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi3","stereo stgc OnTrackResidualTrack MS phi3 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi4 = new TH1F("stgcOnTrackResidualTrackMS_phi4","stgc OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi4 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi4","eta stgc OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi4 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi4","stereo stgc OnTrackResidualTrack MS phi4 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi5 = new TH1F("stgcOnTrackResidualTrackMS_phi5","stgc OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi5 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi5","eta stgc OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi5 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi5","stereo stgc OnTrackResidualTrack MS phi5 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi6 = new TH1F("stgcOnTrackResidualTrackMS_phi6","stgc OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi6 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi6","eta stgc OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi6 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi6","stereo stgc OnTrackResidualTrack MS phi6 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi7 = new TH1F("stgcOnTrackResidualTrackMS_phi7","stgc OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi7 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi7","eta stgc OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi7 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi7","stereo stgc OnTrackResidualTrack MS phi7 ", 1200,-6,6);
   TH1F *h_stgcOnTrackResidualTrackMS_phi8 = new TH1F("stgcOnTrackResidualTrackMS_phi8","stgc OnTrackResidualTrack MS phi8 ", 1200,-6,6);
   TH1F *h_eta_stgcOnTrackResidualTrackMS_phi8 = new TH1F("eta_stgcOnTrackResidualTrackMS_phi8","eta stgc OnTrackResidualTrack MS phi8 ", 1200,-6,6);
   TH1F *h_stereo_stgcOnTrackResidualTrackMS_phi8 = new TH1F("stereo_stgcOnTrackResidualTrackMS_phi8","stereo stgc OnTrackResidualTrack MS phi8 ", 1200,-6,6);
//Muons
   TH1F *h_muons_pt = new TH1F("muons_pt","muons pt ", 100,0.,100.);     
   TH1F *h_local_position = new TH1F("local_position", "local position", 1200,0,1200); 
   TH1F *h_global_position = new TH1F("global_position", "global position", 4000,6000,10000);
   TH1F *h_global_t_position = new TH1F("global_t_position", "global transverse position", 5000,0,5000); 
//   TH1F *h_IDTracks_pt = new TH1F("IDTracks_pt","IDTracks pt ", 100,0.,50.);
//   TH1F *h_METracks_pt = new TH1F("METracks_pt","METracks pt ", 100,0.,50.);
//   TH1F *h_MSOETracks_pt = new TH1F("MSOETracks_pt","MSOETracks pt ", 100,0.,50.);
//   TH1F *h_MSTracks_pt = new TH1F("MSTracks_pt","MSTracks pt ", 100,0.,50.);

   TH1F *h_muons_eta = new TH1F("muons_eta","muons eta ", 60,-3,3);
   TH1F *h_muons_eta_abs = new TH1F("muons_eta_abs","muons eta abs ", 60,0,3);
   TH1F *h_muons_theta = new TH1F("muons_theta","muons theta ", 60,0,4);
   TH1F *h_muons_eta_ST1 = new TH1F("muons_eta_ST1","muons eta ST1 ", 60,-3,3);
   TH1F *h_muons_eta_ST2 = new TH1F("muons_eta_ST2","muons eta ST2 ", 60,-3,3);
//   TH1F *h_IDTracks_eta = new TH1F("IDTracks_eta","IDTracks eta ", 60,-3,3);
//   TH1F *h_METracks_eta = new TH1F("METracks_eta","METracks eta ", 60,-3,3);
//   TH1F *h_MSOETracks_eta = new TH1F("MSOETracks_eta","MSOETracks eta ", 60,-3,3);
//   TH1F *h_MSTracks_eta = new TH1F("MSTracks_eta","MSTracks eta ", 60,-3,3);

   TH1F *h_x12 = new TH1F("x12", "posx12", 4000, -20,20);
   TH1F *h_x121 = new TH1F("x121", "posx121", 4000, -20,20);
   TH1F *h_x341 = new TH1F("x341", "posx341", 4000, -20,20);
   TH1F *h_x122 = new TH1F("x122", "posx122", 4000, -20,20);
   TH1F *h_x342 = new TH1F("x342", "posx342", 4000, -20,20);
   TH1F *h_x34 = new TH1F("x34", "posx34", 4000, -20,20);

  TH1F *h_x12_eta01 = new TH1F("x12_eta01", "posx12", 4000, -20,20);
  TH1F *h_x12_eta02 = new TH1F("x12_eta02", "posx12", 4000, -20,20);
  TH1F *h_x12_eta03 = new TH1F("x12_eta03", "posx12", 4000, -20,20);
  TH1F *h_x12_eta04 = new TH1F("x12_eta04", "posx12", 4000, -20,20);
  TH1F *h_x12_eta05 = new TH1F("x12_eta05", "posx12", 4000, -20,20);
  TH1F *h_x12_eta06 = new TH1F("x12_eta06", "posx12", 4000, -20,20);
  TH1F *h_x12_eta07 = new TH1F("x12_eta07", "posx12", 4000, -20,20);
  TH1F *h_x12_eta08 = new TH1F("x12_eta08", "posx12", 4000, -20,20);
  TH1F *h_x12_eta09 = new TH1F("x12_eta09", "posx12", 4000, -20,20);
  TH1F *h_x12_eta10 = new TH1F("x12_eta10", "posx12", 4000, -20,20);
  TH1F *h_x12_eta11 = new TH1F("x12_eta11", "posx12", 4000, -20,20);
  TH1F *h_x12_eta12 = new TH1F("x12_eta12", "posx12", 4000, -20,20);
  TH1F *h_x12_eta13 = new TH1F("x12_eta13", "posx12", 4000, -20,20);
  TH1F *h_x12_eta14 = new TH1F("x12_eta14", "posx12", 4000, -20,20);

  TH1F *h_x12_qpcb01 = new TH1F("x12_qpcb01", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb02 = new TH1F("x12_qpcb02", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb03 = new TH1F("x12_qpcb03", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb04 = new TH1F("x12_qpcb04", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb05 = new TH1F("x12_qpcb05", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb06 = new TH1F("x12_qpcb06", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb07 = new TH1F("x12_qpcb07", "posx12", 4000, -20,20);
  TH1F *h_x12_qpcb08 = new TH1F("x12_qpcb08", "posx12", 4000, -20,20);
 

   TH1F *h_x12G = new TH1F("x12G", "posx12", 4000, -20,20);
   TH1F *h_x121G = new TH1F("x121G", "posx121", 4000, -20,20);
   TH1F *h_x341G = new TH1F("x341G", "posx341", 4000, -20,20);
   TH1F *h_x122G = new TH1F("x122G", "posx122", 4000, -20,20);
   TH1F *h_x342G = new TH1F("x342G", "posx342", 4000, -20,20);
   TH1F *h_x34G = new TH1F("x34G", "posx34", 4000, -20,20);

   TH1F *h_x12R = new TH1F("x12R", "posx12", 4000, -20,20);
   TH1F *h_x121R = new TH1F("x121R", "posx121", 4000, -20,20);
   TH1F *h_x341R = new TH1F("x341R", "posx341", 4000, -20,20);
   TH1F *h_x122R = new TH1F("x122R", "posx122", 4000, -20,20);
   TH1F *h_x342R = new TH1F("x342R", "posx342", 4000, -20,20);
   TH1F *h_x34R = new TH1F("x34R", "posx34", 4000, -20,20);

   TH1F *h_x12MS = new TH1F("x12MS", "posx12 MS", 4000, -20,20);
   TH1F *h_x13MS = new TH1F("x13MS", "posx13 MS", 4000, -20,20);
   TH1F *h_x14MS = new TH1F("x14MS", "posx14 MS", 4000, -20,20);
   TH1F *h_x23MS = new TH1F("x23MS", "posx23 MS", 4000, -20,20);
   TH1F *h_x24MS = new TH1F("x24MS", "posx24 MS", 4000, -20,20);
   TH1F *h_x34MS = new TH1F("x34MS", "posx34 MS", 4000, -20,20);

   TH1F *h_x12R_MS = new TH1F("x12R_MS", "posx12R MS", 4000, -20,20);
   TH1F *h_x13R_MS = new TH1F("x13R_MS", "posx13R MS", 4000, -20,20);
   TH1F *h_x14R_MS = new TH1F("x14R_MS", "posx14R MS", 4000, -20,20);
   TH1F *h_x23R_MS = new TH1F("x23R_MS", "posx23R MS", 4000, -20,20);
   TH1F *h_x24R_MS = new TH1F("x24R_MS", "posx24R MS", 4000, -20,20);
   TH1F *h_x34R_MS = new TH1F("x34R_MS", "posx34R MS", 4000, -20,20);


   gStyle->SetOptFit(1);

   //

   if (fChain == 0) return;
   //residual
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) //analysis here
   {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

      //Analysis progress
      if(jentry%1000==0)std::cout << "Analysed a total of: " << jentry << " events" << std::endl;
	  //if(jentry>1000000)break;
      Float_t weight =1.; 

      //ANALYSIS AND HISTROGRAM FILLING
         for(int i = 0; i < muons_eta->size(); i++)
            {
               h_muons_pt->Fill(muons_pt->at(i));//if(muons_passMediumCuts == 1)
               h_muons_eta->Fill(muons_eta->at(i));
               h_muons_eta_abs->Fill(abs(muons_eta->at(i)));
               h_muons_theta->Fill(2*atan(exp(-muons_eta->at(i))));

               
               /* int station_eta=abs(mmOnTrack_stationEta->at(i));
               if(station_eta==1)h_muons_eta_ST1->Fill(mmOnTrackResidualTrack->at(i));
               if(station_eta==2)h_muons_eta_ST2->Fill(mmOnTrackResidualTrack->at(i)); */
            } 

         for(int i=0; i<mmOnTrack_gas_gap->size(); i++)
            {
               h_mmOnTrack_gas_gap->Fill(mmOnTrack_gas_gap->at(i));
            }


         for(int i = 0; i < mmOnTrackResidualTrack->size(); i++)
            {
               h_mmOnTrackResidualTrack->Fill(mmOnTrackResidualTrack->at(i));
               int NStrips = mmOnTrackNStrips->at(i);
               int index_mu=mmOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  if(pt_mu>=20.)h_mmOnTrackResidualTrack_pt20->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs(mmOnTrack_stationEta->at(i))==1)h_mmOnTrackResidualTrack_ST1->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs(mmOnTrack_stationEta->at(i))==2)h_mmOnTrackResidualTrack_ST2->Fill(mmOnTrackResidualTrack->at(i));

                  int gasgap = mmOnTrack_gas_gap->at(i);
                  if(gasgap == 2||gasgap == 3)
                  {
                     if(abs(mmOnTrack_stationEta->at(i))==1)h_eta_mmOnTrackResidualTrack_ST1->Fill(mmOnTrackResidualTrack->at(i));
                     if(abs(mmOnTrack_stationEta->at(i))==2)h_eta_mmOnTrackResidualTrack_ST2->Fill(mmOnTrackResidualTrack->at(i));
                  }

                  if(mmOnTrack_stationPhi->at(i)==1)h_mmOnTrackResidualTrack_PhiST1->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==2)h_mmOnTrackResidualTrack_PhiST2->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==3)h_mmOnTrackResidualTrack_PhiST3->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==4)h_mmOnTrackResidualTrack_PhiST4->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==5)h_mmOnTrackResidualTrack_PhiST5->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==6)h_mmOnTrackResidualTrack_PhiST6->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==7)h_mmOnTrackResidualTrack_PhiST7->Fill(mmOnTrackResidualTrack->at(i));
                  if(mmOnTrack_stationPhi->at(i)==8)h_mmOnTrackResidualTrack_PhiST8->Fill(mmOnTrackResidualTrack->at(i));
               }
            } 
         
         for(int i = 0; i < mmOnTrackResidualTrackMS->size(); i++) 
            {
               h_mmOnTrackResidualTrackMS->Fill(mmOnTrackResidualTrackMS->at(i));
               int NStrips = mmOnTrackNStrips->at(i);
               int index_mu=mmOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  if(pt_mu>=20.)h_mmOnTrackResidualTrackMS_pt20->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs(mmOnTrack_stationEta->at(i))==1)h_mmOnTrackResidualTrackMS_ST1->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs(mmOnTrack_stationEta->at(i))==2)h_mmOnTrackResidualTrackMS_ST2->Fill(mmOnTrackResidualTrackMS->at(i));

                  int gasgap = mmOnTrack_gas_gap->at(i);
                  if(gasgap == 2||gasgap == 3)
                  {
                     if(abs(mmOnTrack_stationEta->at(i))==1)h_eta_mmOnTrackResidualTrackMS_ST1->Fill(mmOnTrackResidualTrackMS->at(i));
                     if(abs(mmOnTrack_stationEta->at(i))==2)h_eta_mmOnTrackResidualTrackMS_ST2->Fill(mmOnTrackResidualTrackMS->at(i));
                  }

                  if(mmOnTrack_stationPhi->at(i)==1)h_mmOnTrackResidualTrackMS_PhiST1->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==2)h_mmOnTrackResidualTrackMS_PhiST2->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==3)h_mmOnTrackResidualTrackMS_PhiST3->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==4)h_mmOnTrackResidualTrackMS_PhiST4->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==5)h_mmOnTrackResidualTrackMS_PhiST5->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==6)h_mmOnTrackResidualTrackMS_PhiST6->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==7)h_mmOnTrackResidualTrackMS_PhiST7->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(mmOnTrack_stationPhi->at(i)==8)h_mmOnTrackResidualTrackMS_PhiST8->Fill(mmOnTrackResidualTrackMS->at(i));
               }
            }

         for(int i = 0; i < mmOnTrack_channel->size(); i++) 
            {
               h_mmOnTrack_channel->Fill(mmOnTrack_channel->at(i));
               int NStrips = mmOnTrackNStrips->at(i);
               int index_mu=mmOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  if(pt_mu>=20.)h_mmOnTrack_channel_pt20->Fill(mmOnTrack_channel->at(i));
                  h_mmOnTrack_stationEta->Fill(mmOnTrack_stationEta->at(i));
                  h_mmOnTrack_stationPhi->Fill(mmOnTrack_stationPhi->at(i));

//			Study wrt muon eta
                  double abs_eta_mu=abs(muons_eta->at(index_mu));
                  if(abs_eta_mu <1.4) h_mmOnTrackResidualTrack_eta1->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrack_eta2->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrack_eta3->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrack_eta4->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrack_eta5->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrack_eta6->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrack_eta7->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrack_eta8->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrack_eta9->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrack_eta10->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrack_eta11->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrack_eta12->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrack_eta13->Fill(mmOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrack_eta14->Fill(mmOnTrackResidualTrack->at(i));
                  
                  if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMS_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMS_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMS_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMS_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMS_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMS_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMS_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMS_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMS_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMS_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMS_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMS_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMS_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMS_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                  int gasgap = mmOnTrack_gas_gap->at(i);
                  int multiplet = mmOnTrack_multiplet->at(i);
                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrack_eta1->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrack_eta2->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrack_eta3->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrack_eta4->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrack_eta5->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrack_eta6->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrack_eta7->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrack_eta8->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrack_eta9->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrack_eta10->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrack_eta11->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrack_eta12->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrack_eta13->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrack_eta14->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMS_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMS_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMS_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMS_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMS_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMS_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMS_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMS_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMS_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMS_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMS_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMS_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMS_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMS_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrack_eta1->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrack_eta2->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrack_eta3->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrack_eta4->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrack_eta5->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrack_eta6->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrack_eta7->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrack_eta8->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrack_eta9->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrack_eta10->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrack_eta11->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrack_eta12->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrack_eta13->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrack_eta14->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMS_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMS_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMS_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMS_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMS_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMS_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMS_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMS_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMS_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMS_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMS_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMS_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMS_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMS_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrack_eta1->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrack_eta2->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrack_eta3->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrack_eta4->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrack_eta5->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrack_eta6->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrack_eta7->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrack_eta8->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrack_eta9->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrack_eta10->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrack_eta11->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrack_eta12->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrack_eta13->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrack_eta14->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMS_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMS_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMS_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMS_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMS_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMS_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMS_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMS_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMS_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMS_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMS_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMS_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMS_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMS_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrack_eta1->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrack_eta2->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrack_eta3->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrack_eta4->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrack_eta5->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrack_eta6->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrack_eta7->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrack_eta8->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrack_eta9->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrack_eta10->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrack_eta11->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrack_eta12->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrack_eta13->Fill(mmOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrack_eta14->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMS_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMS_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMS_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMS_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMS_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMS_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMS_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMS_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMS_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMS_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMS_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMS_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMS_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMS_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }

                     if (mmOnTrack_stationPhi->at(i)==1)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi01_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi01_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi01_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi01_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi01_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi01_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi01_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi01_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi01_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi01_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi01_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi01_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi01_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi01_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi01_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi01_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi01_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi01_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi01_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi01_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi01_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi01_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi01_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi01_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi01_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi01_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi01_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi01_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi01_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi01_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi01_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi01_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi01_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi01_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi01_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi01_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi01_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi01_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi01_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi01_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi01_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi01_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi01_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi01_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi01_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi01_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi01_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi01_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi01_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi01_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi01_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi01_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi01_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi01_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi01_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi01_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi01_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi01_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi01_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi01_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi01_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi01_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi01_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi01_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi01_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi01_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi01_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi01_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi01_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi01_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi01_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi01_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi01_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi01_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi01_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi01_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi01_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi01_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi01_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi01_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi01_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi01_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi01_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi01_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi01_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi01_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi01_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi01_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi01_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi01_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi01_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi01_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi01_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi01_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi01_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi01_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi01_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi01_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi01_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi01_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi01_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi01_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi01_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi01_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi01_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi01_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi01_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi01_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi01_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi01_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi01_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi01_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi01_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi01_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi01_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi01_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi01_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi01_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi01_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi01_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi01_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi01_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi01_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi01_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi01_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi01_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi01_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi01_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi01_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi01_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==2)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi02_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi02_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi02_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi02_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi02_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi02_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi02_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi02_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi02_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi02_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi02_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi02_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi02_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi02_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi02_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi02_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi02_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi02_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi02_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi02_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi02_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi02_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi02_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi02_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi02_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi02_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi02_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi02_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi02_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi02_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi02_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi02_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi02_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi02_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi02_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi02_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi02_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi02_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi02_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi02_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi02_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi02_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi02_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi02_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi02_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi02_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi02_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi02_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi02_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi02_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi02_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi02_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi02_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi02_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi02_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi02_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi02_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi02_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi02_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi02_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi02_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi02_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi02_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi02_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi02_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi02_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi02_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi02_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi02_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi02_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi02_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi02_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi02_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi02_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi02_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi02_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi02_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi02_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi02_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi02_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi02_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi02_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi02_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi02_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi02_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi02_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi02_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi02_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi02_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi02_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi02_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi02_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi02_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi02_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi02_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi02_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi02_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi02_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi02_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi02_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi02_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi02_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi02_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi02_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi02_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi02_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi02_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi02_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi02_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi02_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi02_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi02_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi02_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi02_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi02_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi02_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi02_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi02_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi02_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi02_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi02_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi02_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi02_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi02_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi02_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi02_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi02_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi02_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi02_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi02_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==3)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi03_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi03_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi03_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi03_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi03_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi03_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi03_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi03_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi03_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi03_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi03_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi03_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi03_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi03_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi03_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi03_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi03_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi03_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi03_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi03_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi03_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi03_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi03_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi03_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi03_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi03_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi03_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi03_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi03_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi03_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi03_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi03_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi03_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi03_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi03_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi03_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi03_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi03_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi03_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi03_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi03_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi03_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi03_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi03_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi03_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi03_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi03_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi03_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi03_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi03_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi03_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi03_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi03_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi03_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi03_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi03_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi03_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi03_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi03_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi03_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi03_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi03_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi03_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi03_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi03_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi03_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi03_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi03_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi03_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi03_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi03_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi03_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi03_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi03_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi03_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi03_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi03_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi03_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi03_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi03_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi03_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi03_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi03_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi03_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi03_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi03_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi03_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi03_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi03_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi03_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi03_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi03_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi03_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi03_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi03_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi03_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi03_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi03_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi03_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi03_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi03_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi03_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi03_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi03_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi03_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi03_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi03_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi03_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi03_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi03_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi03_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi03_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi03_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi03_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi03_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi03_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi03_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi03_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi03_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi03_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi03_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi03_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi03_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi03_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi03_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi03_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi03_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi03_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi03_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi03_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==4)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi04_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi04_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi04_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi04_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi04_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi04_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi04_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi04_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi04_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi04_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi04_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi04_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi04_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi04_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi04_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi04_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi04_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi04_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi04_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi04_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi04_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi04_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi04_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi04_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi04_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi04_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi04_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi04_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi04_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi04_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi04_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi04_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi04_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi04_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi04_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi04_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi04_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi04_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi04_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi04_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi04_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi04_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi04_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi04_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi04_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi04_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi04_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi04_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi04_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi04_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi04_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi04_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi04_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi04_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi04_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi04_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi04_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi04_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi04_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi04_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi04_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi04_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi04_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi04_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi04_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi04_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi04_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi04_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi04_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi04_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi04_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi04_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi04_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi04_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi04_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi04_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi04_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi04_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi04_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi04_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi04_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi04_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi04_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi04_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi04_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi04_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi04_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi04_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi04_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi04_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi04_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi04_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi04_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi04_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi04_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi04_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi04_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi04_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi04_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi04_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi04_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi04_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi04_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi04_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi04_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi04_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi04_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi04_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi04_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi04_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi04_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi04_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi04_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi04_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi04_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi04_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi04_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi04_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi04_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi04_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi04_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi04_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi04_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi04_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi04_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi04_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi04_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi04_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi04_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi04_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==5)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi05_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi05_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi05_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi05_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi05_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi05_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi05_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi05_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi05_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi05_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi05_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi05_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi05_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi05_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi05_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi05_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi05_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi05_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi05_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi05_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi05_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi05_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi05_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi05_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi05_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi05_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi05_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi05_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi05_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi05_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi05_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi05_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi05_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi05_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi05_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi05_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi05_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi05_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi05_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi05_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi05_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi05_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi05_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi05_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi05_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi05_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi05_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi05_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi05_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi05_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi05_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi05_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi05_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi05_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi05_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi05_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi05_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi05_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi05_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi05_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi05_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi05_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi05_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi05_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi05_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi05_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi05_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi05_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi05_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi05_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi05_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi05_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi05_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi05_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi05_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi05_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi05_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi05_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi05_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi05_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi05_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi05_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi05_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi05_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi05_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi05_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi05_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi05_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi05_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi05_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi05_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi05_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi05_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi05_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi05_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi05_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi05_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi05_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi05_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi05_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi05_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi05_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi05_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi05_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi05_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi05_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi05_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi05_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi05_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi05_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi05_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi05_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi05_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi05_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi05_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi05_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi05_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi05_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi05_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi05_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi05_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi05_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi05_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi05_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi05_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi05_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi05_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi05_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi05_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi05_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==6)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi06_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi06_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi06_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi06_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi06_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi06_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi06_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi06_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi06_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi06_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi06_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi06_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi06_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi06_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi06_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi06_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi06_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi06_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi06_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi06_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi06_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi06_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi06_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi06_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi06_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi06_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi06_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi06_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi06_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi06_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi06_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi06_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi06_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi06_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi06_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi06_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi06_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi06_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi06_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi06_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi06_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi06_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi06_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi06_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi06_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi06_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi06_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi06_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi06_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi06_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi06_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi06_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi06_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi06_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi06_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi06_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi06_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi06_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi06_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi06_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi06_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi06_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi06_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi06_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi06_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi06_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi06_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi06_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi06_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi06_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi06_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi06_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi06_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi06_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi06_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi06_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi06_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi06_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi06_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi06_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi06_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi06_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi06_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi06_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi06_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi06_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi06_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi06_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi06_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi06_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi06_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi06_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi06_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi06_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi06_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi06_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi06_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi06_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi06_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi06_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi06_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi06_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi06_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi06_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi06_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi06_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi06_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi06_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi06_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi06_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi06_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi06_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi06_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi06_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi06_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi06_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi06_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi06_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi06_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi06_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi06_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi06_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi06_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi06_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi06_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi06_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi06_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi06_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi06_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi06_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==7)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi07_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi07_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi07_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi07_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi07_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi07_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi07_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi07_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi07_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi07_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi07_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi07_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi07_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi07_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi07_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi07_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi07_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi07_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi07_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi07_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi07_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi07_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi07_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi07_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi07_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi07_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi07_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi07_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi07_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi07_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi07_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi07_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi07_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi07_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi07_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi07_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi07_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi07_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi07_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi07_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi07_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi07_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi07_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi07_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi07_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi07_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi07_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi07_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi07_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi07_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi07_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi07_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi07_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi07_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi07_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi07_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi07_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi07_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi07_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi07_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi07_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi07_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi07_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi07_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi07_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi07_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi07_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi07_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi07_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi07_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi07_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi07_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi07_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi07_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi07_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi07_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi07_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi07_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi07_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi07_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi07_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi07_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi07_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi07_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi07_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi07_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi07_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi07_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi07_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi07_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi07_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi07_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi07_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi07_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi07_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi07_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi07_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi07_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi07_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi07_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi07_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi07_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi07_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi07_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi07_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi07_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi07_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi07_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi07_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi07_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi07_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi07_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi07_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi07_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi07_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi07_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi07_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi07_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi07_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi07_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi07_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi07_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi07_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi07_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi07_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi07_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi07_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi07_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi07_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi07_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationPhi->at(i)==8)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackPhi08_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackPhi08_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackPhi08_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackPhi08_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackPhi08_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackPhi08_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackPhi08_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackPhi08_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackPhi08_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackPhi08_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackPhi08_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackPhi08_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackPhi08_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackPhi08_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSPhi08_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSPhi08_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSPhi08_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSPhi08_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSPhi08_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSPhi08_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSPhi08_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSPhi08_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSPhi08_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSPhi08_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSPhi08_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSPhi08_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSPhi08_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSPhi08_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi08_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi08_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi08_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi08_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi08_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi08_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi08_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi08_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi08_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi08_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi08_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi08_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi08_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi08_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi08_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi08_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi08_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi08_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi08_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi08_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi08_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi08_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi08_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi08_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi08_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi08_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi08_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi08_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi08_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi08_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi08_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi08_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi08_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi08_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi08_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi08_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi08_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi08_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi08_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi08_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi08_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi08_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi08_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi08_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi08_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi08_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi08_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi08_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi08_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi08_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackPhi08_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackPhi08_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackPhi08_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackPhi08_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackPhi08_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackPhi08_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackPhi08_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackPhi08_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackPhi08_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackPhi08_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackPhi08_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackPhi08_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackPhi08_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackPhi08_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSPhi08_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSPhi08_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSPhi08_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSPhi08_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSPhi08_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSPhi08_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSPhi08_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSPhi08_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSPhi08_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSPhi08_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSPhi08_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSPhi08_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackPhi08_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackPhi08_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackPhi08_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackPhi08_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackPhi08_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackPhi08_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackPhi08_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackPhi08_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackPhi08_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackPhi08_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackPhi08_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackPhi08_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackPhi08_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackPhi08_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSPhi08_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSPhi08_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSPhi08_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSPhi08_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSPhi08_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSPhi08_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSPhi08_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSPhi08_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSPhi08_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSPhi08_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSPhi08_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSPhi08_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationIndex->at(i)==56)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackLargeSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackLargeSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackLargeSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackLargeSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackLargeSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackLargeSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackLargeSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackLargeSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackLargeSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackLargeSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackLargeSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackLargeSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackLargeSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackLargeSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSLargeSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSLargeSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSLargeSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSLargeSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSLargeSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSLargeSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSLargeSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSLargeSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSLargeSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSLargeSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSLargeSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSLargeSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSLargeSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSLargeSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackLargeSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackLargeSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackLargeSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackLargeSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackLargeSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackLargeSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackLargeSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackLargeSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackLargeSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackLargeSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackLargeSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackLargeSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackLargeSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackLargeSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSLargeSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSLargeSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSLargeSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSLargeSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSLargeSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSLargeSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSLargeSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSLargeSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSLargeSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSLargeSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSLargeSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackLargeSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackLargeSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackLargeSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackLargeSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackLargeSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackLargeSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackLargeSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackLargeSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackLargeSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackLargeSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackLargeSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackLargeSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackLargeSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackLargeSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackLargeSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackLargeSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackLargeSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackLargeSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackLargeSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackLargeSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackLargeSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackLargeSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackLargeSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackLargeSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackLargeSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSLargeSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSLargeSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSLargeSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSLargeSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSLargeSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSLargeSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSLargeSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSLargeSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSLargeSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSLargeSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSLargeSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSLargeSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackLargeSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackLargeSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackLargeSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackLargeSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackLargeSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackLargeSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackLargeSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackLargeSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackLargeSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackLargeSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackLargeSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackLargeSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
                     if (mmOnTrack_stationIndex->at(i)==55)
                     {
                        double abs_eta_mu=abs(muons_eta->at(index_mu));
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackSmallSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackSmallSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackSmallSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackSmallSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackSmallSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackSmallSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackSmallSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackSmallSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackSmallSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackSmallSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackSmallSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackSmallSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackSmallSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackSmallSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                        
                        if(abs_eta_mu <1.4) h_mmOnTrackResidualTrackMSSmallSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_mmOnTrackResidualTrackMSSmallSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_mmOnTrackResidualTrackMSSmallSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_mmOnTrackResidualTrackMSSmallSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_mmOnTrackResidualTrackMSSmallSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_mmOnTrackResidualTrackMSSmallSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_mmOnTrackResidualTrackMSSmallSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_mmOnTrackResidualTrackMSSmallSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_mmOnTrackResidualTrackMSSmallSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_mmOnTrackResidualTrackMSSmallSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_mmOnTrackResidualTrackMSSmallSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_mmOnTrackResidualTrackMSSmallSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_mmOnTrackResidualTrackMSSmallSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(abs_eta_mu >=2.6) h_mmOnTrackResidualTrackMSSmallSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));

                        int gasgap = mmOnTrack_gas_gap->at(i);
                        int multiplet = mmOnTrack_multiplet->at(i);
                        if(multiplet == 1)
                           {
                           if(gasgap == 1||gasgap == 2)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackSmallSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackSmallSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackSmallSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackSmallSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackSmallSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackSmallSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackSmallSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackSmallSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackSmallSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackSmallSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackSmallSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackSmallSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackSmallSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackSmallSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSSmallSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSSmallSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSSmallSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSSmallSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSSmallSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSSmallSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSSmallSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSSmallSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSSmallSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSSmallSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSSmallSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           if(gasgap == 3||gasgap == 4)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackSmallSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackSmallSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackSmallSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackSmallSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackSmallSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackSmallSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackSmallSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackSmallSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackSmallSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackSmallSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackSmallSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i)); 
                              }
                           }
                        if(multiplet == 2)
                           {
                           if(gasgap == 3||gasgap == 4)// eta
                              {
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackSmallSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackSmallSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackSmallSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackSmallSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackSmallSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackSmallSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackSmallSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackSmallSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackSmallSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackSmallSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackSmallSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackSmallSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackSmallSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackSmallSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_eta_mmOnTrackResidualTrackMSSmallSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_mmOnTrackResidualTrackMSSmallSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_mmOnTrackResidualTrackMSSmallSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_mmOnTrackResidualTrackMSSmallSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_mmOnTrackResidualTrackMSSmallSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_mmOnTrackResidualTrackMSSmallSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_mmOnTrackResidualTrackMSSmallSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_mmOnTrackResidualTrackMSSmallSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_mmOnTrackResidualTrackMSSmallSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_mmOnTrackResidualTrackMSSmallSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_mmOnTrackResidualTrackMSSmallSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_eta_mmOnTrackResidualTrackMSSmallSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           if(gasgap == 1||gasgap == 2)// stereo
                              {
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackSmallSector_eta1->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackSmallSector_eta2->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta3->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackSmallSector_eta4->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackSmallSector_eta5->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackSmallSector_eta6->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackSmallSector_eta7->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackSmallSector_eta8->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackSmallSector_eta9->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackSmallSector_eta10->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackSmallSector_eta11->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackSmallSector_eta12->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta13->Fill(mmOnTrackResidualTrack->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackSmallSector_eta14->Fill(mmOnTrackResidualTrack->at(i));
                                 
                                 if(abs_eta_mu <1.4) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13->Fill(mmOnTrackResidualTrackMS->at(i));
                                 if(abs_eta_mu >=2.6) h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14->Fill(mmOnTrackResidualTrackMS->at(i));  
                              }
                           }
                     }
			   
			

//			Study wrt muon theta
                  double theta_mu = 2*atan(exp(-abs(muons_eta->at(index_mu))));
                  h_mmhitmuons_theta->Fill(theta_mu);

                  if(theta_mu <0.2) h_mmOnTrackResidualTrack_PCB1_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.2 && theta_mu <0.25) h_mmOnTrackResidualTrack_PCB2_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.25 && theta_mu <0.3) h_mmOnTrackResidualTrack_PCB3_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.3 && theta_mu <0.35) h_mmOnTrackResidualTrack_PCB4_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.35 && theta_mu <0.4) h_mmOnTrackResidualTrack_PCB5_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.4 && theta_mu <0.45) h_mmOnTrackResidualTrack_PCB6_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.45 && theta_mu <0.5) h_mmOnTrackResidualTrack_PCB7_theta->Fill(mmOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.5) h_mmOnTrackResidualTrack_PCB8_theta->Fill(mmOnTrackResidualTrack->at(i));
                  
                  if(theta_mu <0.2) h_mmOnTrackResidualTrackMS_PCB1_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.2 && theta_mu <0.25) h_mmOnTrackResidualTrackMS_PCB2_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.25 && theta_mu <0.3) h_mmOnTrackResidualTrackMS_PCB3_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.3 && theta_mu <0.35) h_mmOnTrackResidualTrackMS_PCB4_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.35 && theta_mu <0.4) h_mmOnTrackResidualTrackMS_PCB5_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.4 && theta_mu <0.45) h_mmOnTrackResidualTrackMS_PCB6_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.45 && theta_mu <0.5) h_mmOnTrackResidualTrackMS_PCB7_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.5) h_mmOnTrackResidualTrackMS_PCB8_theta->Fill(mmOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(theta_mu <0.2) h_eta_mmOnTrackResidualTrack_PCB1_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_mmOnTrackResidualTrack_PCB2_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_mmOnTrackResidualTrack_PCB3_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_mmOnTrackResidualTrack_PCB4_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_mmOnTrackResidualTrack_PCB5_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_mmOnTrackResidualTrack_PCB6_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_mmOnTrackResidualTrack_PCB7_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_eta_mmOnTrackResidualTrack_PCB8_theta->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_eta_mmOnTrackResidualTrackMS_PCB1_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_mmOnTrackResidualTrackMS_PCB2_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_mmOnTrackResidualTrackMS_PCB3_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_mmOnTrackResidualTrackMS_PCB4_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_mmOnTrackResidualTrackMS_PCB5_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_mmOnTrackResidualTrackMS_PCB6_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_mmOnTrackResidualTrackMS_PCB7_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_eta_mmOnTrackResidualTrackMS_PCB8_theta->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(theta_mu <0.2) h_stereo_mmOnTrackResidualTrack_PCB1_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_mmOnTrackResidualTrack_PCB2_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_mmOnTrackResidualTrack_PCB3_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_mmOnTrackResidualTrack_PCB4_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_mmOnTrackResidualTrack_PCB5_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_mmOnTrackResidualTrack_PCB6_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_mmOnTrackResidualTrack_PCB7_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_stereo_mmOnTrackResidualTrack_PCB8_theta->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_stereo_mmOnTrackResidualTrackMS_PCB1_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_mmOnTrackResidualTrackMS_PCB2_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_mmOnTrackResidualTrackMS_PCB3_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_mmOnTrackResidualTrackMS_PCB4_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_mmOnTrackResidualTrackMS_PCB5_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_mmOnTrackResidualTrackMS_PCB6_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_mmOnTrackResidualTrackMS_PCB7_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_stereo_mmOnTrackResidualTrackMS_PCB8_theta->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(theta_mu <0.2) h_eta_mmOnTrackResidualTrack_PCB1_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_mmOnTrackResidualTrack_PCB2_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_mmOnTrackResidualTrack_PCB3_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_mmOnTrackResidualTrack_PCB4_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_mmOnTrackResidualTrack_PCB5_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_mmOnTrackResidualTrack_PCB6_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_mmOnTrackResidualTrack_PCB7_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_eta_mmOnTrackResidualTrack_PCB8_theta->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_eta_mmOnTrackResidualTrackMS_PCB1_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_mmOnTrackResidualTrackMS_PCB2_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_mmOnTrackResidualTrackMS_PCB3_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_mmOnTrackResidualTrackMS_PCB4_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_mmOnTrackResidualTrackMS_PCB5_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_mmOnTrackResidualTrackMS_PCB6_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_mmOnTrackResidualTrackMS_PCB7_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_eta_mmOnTrackResidualTrackMS_PCB8_theta->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(theta_mu <0.2) h_stereo_mmOnTrackResidualTrack_PCB1_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_mmOnTrackResidualTrack_PCB2_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_mmOnTrackResidualTrack_PCB3_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_mmOnTrackResidualTrack_PCB4_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_mmOnTrackResidualTrack_PCB5_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_mmOnTrackResidualTrack_PCB6_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_mmOnTrackResidualTrack_PCB7_theta->Fill(mmOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_stereo_mmOnTrackResidualTrack_PCB8_theta->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_stereo_mmOnTrackResidualTrackMS_PCB1_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_mmOnTrackResidualTrackMS_PCB2_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_mmOnTrackResidualTrackMS_PCB3_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_mmOnTrackResidualTrackMS_PCB4_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_mmOnTrackResidualTrackMS_PCB5_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_mmOnTrackResidualTrackMS_PCB6_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_mmOnTrackResidualTrackMS_PCB7_theta->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_stereo_mmOnTrackResidualTrackMS_PCB8_theta->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }

//			Study wrt muon phi
                  double phi_mu = abs(muons_phi->at(index_mu));
                  h_mmhitmuons_phi->Fill(phi_mu);

                  if(phi_mu <0.4) h_mmOnTrackResidualTrack_phi1->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=0.4 && phi_mu <0.8) h_mmOnTrackResidualTrack_phi2->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=0.8 && phi_mu <1.2) h_mmOnTrackResidualTrack_phi3->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=1.2 && phi_mu <1.6) h_mmOnTrackResidualTrack_phi4->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=1.6 && phi_mu <2.) h_mmOnTrackResidualTrack_phi5->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=2. && phi_mu <2.4) h_mmOnTrackResidualTrack_phi6->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=2.4 && phi_mu <2.8) h_mmOnTrackResidualTrack_phi7->Fill(mmOnTrackResidualTrack->at(i));
                  if(phi_mu >=2.8) h_mmOnTrackResidualTrack_phi8->Fill(mmOnTrackResidualTrack->at(i));
                  
                  if(phi_mu <0.4) h_mmOnTrackResidualTrackMS_phi1->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=0.4 && phi_mu <0.8) h_mmOnTrackResidualTrackMS_phi2->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=0.8 && phi_mu <1.2) h_mmOnTrackResidualTrackMS_phi3->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=1.2 && phi_mu <1.6) h_mmOnTrackResidualTrackMS_phi4->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=1.6 && phi_mu <2.) h_mmOnTrackResidualTrackMS_phi5->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2. && phi_mu <2.4) h_mmOnTrackResidualTrackMS_phi6->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2.4 && phi_mu <2.8) h_mmOnTrackResidualTrackMS_phi7->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2.8) h_mmOnTrackResidualTrackMS_phi8->Fill(mmOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(phi_mu <0.4) h_eta_mmOnTrackResidualTrack_phi1->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_mmOnTrackResidualTrack_phi2->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_mmOnTrackResidualTrack_phi3->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_mmOnTrackResidualTrack_phi4->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_mmOnTrackResidualTrack_phi5->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_mmOnTrackResidualTrack_phi6->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_mmOnTrackResidualTrack_phi7->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_eta_mmOnTrackResidualTrack_phi8->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_eta_mmOnTrackResidualTrackMS_phi1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_mmOnTrackResidualTrackMS_phi2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_mmOnTrackResidualTrackMS_phi3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_mmOnTrackResidualTrackMS_phi4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_mmOnTrackResidualTrackMS_phi5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_mmOnTrackResidualTrackMS_phi6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_mmOnTrackResidualTrackMS_phi7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_eta_mmOnTrackResidualTrackMS_phi8->Fill(mmOnTrackResidualTrackMS->at(i));
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(phi_mu <0.4) h_stereo_mmOnTrackResidualTrack_phi1->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_mmOnTrackResidualTrack_phi2->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_mmOnTrackResidualTrack_phi3->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_mmOnTrackResidualTrack_phi4->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_mmOnTrackResidualTrack_phi5->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_mmOnTrackResidualTrack_phi6->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_mmOnTrackResidualTrack_phi7->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_stereo_mmOnTrackResidualTrack_phi8->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_stereo_mmOnTrackResidualTrackMS_phi1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_mmOnTrackResidualTrackMS_phi2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_mmOnTrackResidualTrackMS_phi3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_mmOnTrackResidualTrackMS_phi4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_mmOnTrackResidualTrackMS_phi5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_mmOnTrackResidualTrackMS_phi6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_mmOnTrackResidualTrackMS_phi7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_stereo_mmOnTrackResidualTrackMS_phi8->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(phi_mu <0.4) h_eta_mmOnTrackResidualTrack_phi1->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_mmOnTrackResidualTrack_phi2->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_mmOnTrackResidualTrack_phi3->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_mmOnTrackResidualTrack_phi4->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_mmOnTrackResidualTrack_phi5->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_mmOnTrackResidualTrack_phi6->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_mmOnTrackResidualTrack_phi7->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_eta_mmOnTrackResidualTrack_phi8->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_eta_mmOnTrackResidualTrackMS_phi1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_mmOnTrackResidualTrackMS_phi2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_mmOnTrackResidualTrackMS_phi3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_mmOnTrackResidualTrackMS_phi4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_mmOnTrackResidualTrackMS_phi5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_mmOnTrackResidualTrackMS_phi6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_mmOnTrackResidualTrackMS_phi7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_eta_mmOnTrackResidualTrackMS_phi8->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(phi_mu <0.4) h_stereo_mmOnTrackResidualTrack_phi1->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_mmOnTrackResidualTrack_phi2->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_mmOnTrackResidualTrack_phi3->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_mmOnTrackResidualTrack_phi4->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_mmOnTrackResidualTrack_phi5->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_mmOnTrackResidualTrack_phi6->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_mmOnTrackResidualTrack_phi7->Fill(mmOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_stereo_mmOnTrackResidualTrack_phi8->Fill(mmOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_stereo_mmOnTrackResidualTrackMS_phi1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_mmOnTrackResidualTrackMS_phi2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_mmOnTrackResidualTrackMS_phi3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_mmOnTrackResidualTrackMS_phi4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_mmOnTrackResidualTrackMS_phi5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_mmOnTrackResidualTrackMS_phi6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_mmOnTrackResidualTrackMS_phi7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_stereo_mmOnTrackResidualTrackMS_phi8->Fill(mmOnTrackResidualTrackMS->at(i)); 
                        }
                     }

//			Study wrt hit channel	
                  int channel=mmOnTrack_channel->at(i);
                  int station_eta=abs(mmOnTrack_stationEta->at(i));
                  if(station_eta==1 && 0<=channel && channel <1024) h_mmOnTrackResidualTrack_PCB1->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 1024<=channel && channel <2048) h_mmOnTrackResidualTrack_PCB2->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 2048<=channel && channel <3072) h_mmOnTrackResidualTrack_PCB3->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 3072<=channel && channel <4096) h_mmOnTrackResidualTrack_PCB4->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 4096<=channel && channel <5120) h_mmOnTrackResidualTrack_PCB5->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 0<=channel && channel <1024) h_mmOnTrackResidualTrack_PCB6->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 1024<=channel && channel <2048) h_mmOnTrackResidualTrack_PCB7->Fill(mmOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 2048<=channel && channel <3072) h_mmOnTrackResidualTrack_PCB8->Fill(mmOnTrackResidualTrack->at(i));
                  
                  if(station_eta==1 && 0<=channel && channel <1024) h_mmOnTrackResidualTrackMS_PCB1->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 1024<=channel && channel <2048) h_mmOnTrackResidualTrackMS_PCB2->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 2048<=channel && channel <3072) h_mmOnTrackResidualTrackMS_PCB3->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 3072<=channel && channel <4096) h_mmOnTrackResidualTrackMS_PCB4->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 4096<=channel && channel <5120) h_mmOnTrackResidualTrackMS_PCB5->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 0<=channel && channel <1024) h_mmOnTrackResidualTrackMS_PCB6->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 1024<=channel && channel <2048) h_mmOnTrackResidualTrackMS_PCB7->Fill(mmOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 2048<=channel && channel <3072) h_mmOnTrackResidualTrackMS_PCB8->Fill(mmOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrack_PCB1->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrack_PCB2->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrack_PCB3->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_mmOnTrackResidualTrack_PCB4->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_mmOnTrackResidualTrack_PCB5->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrack_PCB6->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrack_PCB7->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrack_PCB8->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrackMS_PCB1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrackMS_PCB2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrackMS_PCB3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_mmOnTrackResidualTrackMS_PCB4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_mmOnTrackResidualTrackMS_PCB5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrackMS_PCB6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrackMS_PCB7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrackMS_PCB8->Fill(mmOnTrackResidualTrackMS->at(i));  
                        }

                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrack_PCB1->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrack_PCB2->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrack_PCB3->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_mmOnTrackResidualTrack_PCB4->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_mmOnTrackResidualTrack_PCB5->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrack_PCB6->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrack_PCB7->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrack_PCB8->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrackMS_PCB1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrackMS_PCB2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrackMS_PCB3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_mmOnTrackResidualTrackMS_PCB4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_mmOnTrackResidualTrackMS_PCB5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrackMS_PCB6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrackMS_PCB7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrackMS_PCB8->Fill(mmOnTrackResidualTrackMS->at(i));  
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrack_PCB1->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrack_PCB2->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrack_PCB3->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_mmOnTrackResidualTrack_PCB4->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_mmOnTrackResidualTrack_PCB5->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrack_PCB6->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrack_PCB7->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrack_PCB8->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrackMS_PCB1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrackMS_PCB2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrackMS_PCB3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_mmOnTrackResidualTrackMS_PCB4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_mmOnTrackResidualTrackMS_PCB5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_mmOnTrackResidualTrackMS_PCB6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_mmOnTrackResidualTrackMS_PCB7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_mmOnTrackResidualTrackMS_PCB8->Fill(mmOnTrackResidualTrackMS->at(i));  
                        }

                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrack_PCB1->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrack_PCB2->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrack_PCB3->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_mmOnTrackResidualTrack_PCB4->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_mmOnTrackResidualTrack_PCB5->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrack_PCB6->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrack_PCB7->Fill(mmOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrack_PCB8->Fill(mmOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrackMS_PCB1->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrackMS_PCB2->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrackMS_PCB3->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_mmOnTrackResidualTrackMS_PCB4->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_mmOnTrackResidualTrackMS_PCB5->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_mmOnTrackResidualTrackMS_PCB6->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_mmOnTrackResidualTrackMS_PCB7->Fill(mmOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_mmOnTrackResidualTrackMS_PCB8->Fill(mmOnTrackResidualTrackMS->at(i));  
                        }
                     }
			   }
			}
//////////////////////////////sTGC
for(int i = 0; i < stgcOnTrackResidualTrack->size(); i++)
            {
               h_stgcOnTrackResidualTrack->Fill(stgcOnTrackResidualTrack->at(i));
               int NStrips = stgcOnTrackNStrips->at(i);
               int index_mu=stgcOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  if(stgcOnTrack_stationPhi->at(i)==1)h_stgcOnTrackResidualTrack_PhiST1->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==2)h_stgcOnTrackResidualTrack_PhiST2->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==3)h_stgcOnTrackResidualTrack_PhiST3->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==4)h_stgcOnTrackResidualTrack_PhiST4->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==5)h_stgcOnTrackResidualTrack_PhiST5->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==6)h_stgcOnTrackResidualTrack_PhiST6->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==7)h_stgcOnTrackResidualTrack_PhiST7->Fill(stgcOnTrackResidualTrack->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==8)h_stgcOnTrackResidualTrack_PhiST8->Fill(stgcOnTrackResidualTrack->at(i));
               }
            }
for(int i = 0; i < stgcOnTrackResidualTrackMS->size(); i++)
            {
               h_stgcOnTrackResidualTrackMS->Fill(stgcOnTrackResidualTrackMS->at(i));
               int NStrips = stgcOnTrackNStrips->at(i);
               int index_mu=stgcOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  if(stgcOnTrack_stationPhi->at(i)==1)h_stgcOnTrackResidualTrackMS_PhiST1->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==2)h_stgcOnTrackResidualTrackMS_PhiST2->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==3)h_stgcOnTrackResidualTrackMS_PhiST3->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==4)h_stgcOnTrackResidualTrackMS_PhiST4->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==5)h_stgcOnTrackResidualTrackMS_PhiST5->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==6)h_stgcOnTrackResidualTrackMS_PhiST6->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==7)h_stgcOnTrackResidualTrackMS_PhiST7->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(stgcOnTrack_stationPhi->at(i)==8)h_stgcOnTrackResidualTrackMS_PhiST8->Fill(stgcOnTrackResidualTrackMS->at(i));
               }
            } 
for(int i = 0; i < stgcOnTrack_channel->size(); i++) //stgcOnTrackResidualTrack
            {
               h_stgcOnTrack_channel->Fill(stgcOnTrack_channel->at(i));
               int NStrips = stgcOnTrackNStrips->at(i);
               int index_mu=stgcOnTrack_MuonLink->at(i);
               double eta_mu=muons_eta->at(index_mu);
               double pt_mu=muons_pt->at(index_mu);
               if(NStrips>=2 && NStrips<=10)
               {
                  //if(pt_mu>=20.)h_stgcOnTrack_channel_pt20->Fill(stgcOnTrack_channel->at(i));
                  h_stgcOnTrack_stationEta->Fill(stgcOnTrack_stationEta->at(i));
                  h_stgcOnTrack_stationPhi->Fill(stgcOnTrack_stationPhi->at(i));

//			Study wrt muon eta
                  double abs_eta_mu=abs(muons_eta->at(index_mu));
                  if(abs_eta_mu <1.4) h_stgcOnTrackResidualTrack_eta1->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stgcOnTrackResidualTrack_eta2->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stgcOnTrackResidualTrack_eta3->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stgcOnTrackResidualTrack_eta4->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stgcOnTrackResidualTrack_eta5->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stgcOnTrackResidualTrack_eta6->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stgcOnTrackResidualTrack_eta7->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stgcOnTrackResidualTrack_eta8->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stgcOnTrackResidualTrack_eta9->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stgcOnTrackResidualTrack_eta10->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stgcOnTrackResidualTrack_eta11->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stgcOnTrackResidualTrack_eta12->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stgcOnTrackResidualTrack_eta13->Fill(stgcOnTrackResidualTrack->at(i));
                  if(abs_eta_mu >=2.6) h_stgcOnTrackResidualTrack_eta14->Fill(stgcOnTrackResidualTrack->at(i));
                  
                  if(abs_eta_mu <1.4) h_stgcOnTrackResidualTrackMS_eta1->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stgcOnTrackResidualTrackMS_eta2->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stgcOnTrackResidualTrackMS_eta3->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stgcOnTrackResidualTrackMS_eta4->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stgcOnTrackResidualTrackMS_eta5->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stgcOnTrackResidualTrackMS_eta6->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stgcOnTrackResidualTrackMS_eta7->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stgcOnTrackResidualTrackMS_eta8->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stgcOnTrackResidualTrackMS_eta9->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stgcOnTrackResidualTrackMS_eta10->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stgcOnTrackResidualTrackMS_eta11->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stgcOnTrackResidualTrackMS_eta12->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stgcOnTrackResidualTrackMS_eta13->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(abs_eta_mu >=2.6) h_stgcOnTrackResidualTrackMS_eta14->Fill(stgcOnTrackResidualTrackMS->at(i));

                  int gasgap = stgcOnTrack_gas_gap->at(i);
                  int multiplet = stgcOnTrack_multiplet->at(i);
                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(abs_eta_mu <1.4) h_eta_stgcOnTrackResidualTrack_eta1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_stgcOnTrackResidualTrack_eta2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_stgcOnTrackResidualTrack_eta3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_stgcOnTrackResidualTrack_eta4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_stgcOnTrackResidualTrack_eta5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_stgcOnTrackResidualTrack_eta6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_stgcOnTrackResidualTrack_eta7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_stgcOnTrackResidualTrack_eta8->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_stgcOnTrackResidualTrack_eta9->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_stgcOnTrackResidualTrack_eta10->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_stgcOnTrackResidualTrack_eta11->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_stgcOnTrackResidualTrack_eta12->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_stgcOnTrackResidualTrack_eta13->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_eta_stgcOnTrackResidualTrack_eta14->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_eta_stgcOnTrackResidualTrackMS_eta1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_stgcOnTrackResidualTrackMS_eta2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_stgcOnTrackResidualTrackMS_eta3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_stgcOnTrackResidualTrackMS_eta4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_stgcOnTrackResidualTrackMS_eta5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_stgcOnTrackResidualTrackMS_eta6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_stgcOnTrackResidualTrackMS_eta7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_stgcOnTrackResidualTrackMS_eta8->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_stgcOnTrackResidualTrackMS_eta9->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_stgcOnTrackResidualTrackMS_eta10->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_stgcOnTrackResidualTrackMS_eta11->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_stgcOnTrackResidualTrackMS_eta12->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_stgcOnTrackResidualTrackMS_eta13->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_eta_stgcOnTrackResidualTrackMS_eta14->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(abs_eta_mu <1.4) h_stereo_stgcOnTrackResidualTrack_eta1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_stgcOnTrackResidualTrack_eta2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_stgcOnTrackResidualTrack_eta3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_stgcOnTrackResidualTrack_eta4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_stgcOnTrackResidualTrack_eta5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_stgcOnTrackResidualTrack_eta6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_stgcOnTrackResidualTrack_eta7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_stgcOnTrackResidualTrack_eta8->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_stgcOnTrackResidualTrack_eta9->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_stgcOnTrackResidualTrack_eta10->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_stgcOnTrackResidualTrack_eta11->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_stgcOnTrackResidualTrack_eta12->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_stgcOnTrackResidualTrack_eta13->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_stgcOnTrackResidualTrack_eta14->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_stereo_stgcOnTrackResidualTrackMS_eta1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_stgcOnTrackResidualTrackMS_eta2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_stgcOnTrackResidualTrackMS_eta3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_stgcOnTrackResidualTrackMS_eta4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_stgcOnTrackResidualTrackMS_eta5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_stgcOnTrackResidualTrackMS_eta6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_stgcOnTrackResidualTrackMS_eta7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_stgcOnTrackResidualTrackMS_eta8->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_stgcOnTrackResidualTrackMS_eta9->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_stgcOnTrackResidualTrackMS_eta10->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_stgcOnTrackResidualTrackMS_eta11->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_stgcOnTrackResidualTrackMS_eta12->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_stgcOnTrackResidualTrackMS_eta13->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_stgcOnTrackResidualTrackMS_eta14->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(abs_eta_mu <1.4) h_eta_stgcOnTrackResidualTrack_eta1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_stgcOnTrackResidualTrack_eta2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_stgcOnTrackResidualTrack_eta3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_stgcOnTrackResidualTrack_eta4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_stgcOnTrackResidualTrack_eta5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_stgcOnTrackResidualTrack_eta6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_stgcOnTrackResidualTrack_eta7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_stgcOnTrackResidualTrack_eta8->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_stgcOnTrackResidualTrack_eta9->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_stgcOnTrackResidualTrack_eta10->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_stgcOnTrackResidualTrack_eta11->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_stgcOnTrackResidualTrack_eta12->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_stgcOnTrackResidualTrack_eta13->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_eta_stgcOnTrackResidualTrack_eta14->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_eta_stgcOnTrackResidualTrackMS_eta1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_eta_stgcOnTrackResidualTrackMS_eta2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_eta_stgcOnTrackResidualTrackMS_eta3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_eta_stgcOnTrackResidualTrackMS_eta4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_eta_stgcOnTrackResidualTrackMS_eta5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_eta_stgcOnTrackResidualTrackMS_eta6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_eta_stgcOnTrackResidualTrackMS_eta7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_eta_stgcOnTrackResidualTrackMS_eta8->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_eta_stgcOnTrackResidualTrackMS_eta9->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_eta_stgcOnTrackResidualTrackMS_eta10->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_eta_stgcOnTrackResidualTrackMS_eta11->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_eta_stgcOnTrackResidualTrackMS_eta12->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_eta_stgcOnTrackResidualTrackMS_eta13->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_eta_stgcOnTrackResidualTrackMS_eta14->Fill(stgcOnTrackResidualTrackMS->at(i));  
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(abs_eta_mu <1.4) h_stereo_stgcOnTrackResidualTrack_eta1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_stgcOnTrackResidualTrack_eta2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_stgcOnTrackResidualTrack_eta3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_stgcOnTrackResidualTrack_eta4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_stgcOnTrackResidualTrack_eta5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_stgcOnTrackResidualTrack_eta6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_stgcOnTrackResidualTrack_eta7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_stgcOnTrackResidualTrack_eta8->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_stgcOnTrackResidualTrack_eta9->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_stgcOnTrackResidualTrack_eta10->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_stgcOnTrackResidualTrack_eta11->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_stgcOnTrackResidualTrack_eta12->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_stgcOnTrackResidualTrack_eta13->Fill(stgcOnTrackResidualTrack->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_stgcOnTrackResidualTrack_eta14->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(abs_eta_mu <1.4) h_stereo_stgcOnTrackResidualTrackMS_eta1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.4 && abs_eta_mu <1.5) h_stereo_stgcOnTrackResidualTrackMS_eta2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.5 && abs_eta_mu <1.6) h_stereo_stgcOnTrackResidualTrackMS_eta3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.6 && abs_eta_mu <1.7) h_stereo_stgcOnTrackResidualTrackMS_eta4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.7 && abs_eta_mu <1.8) h_stereo_stgcOnTrackResidualTrackMS_eta5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.8 && abs_eta_mu <1.9) h_stereo_stgcOnTrackResidualTrackMS_eta6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=1.9 && abs_eta_mu <2) h_stereo_stgcOnTrackResidualTrackMS_eta7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2 && abs_eta_mu <2.1) h_stereo_stgcOnTrackResidualTrackMS_eta8->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.1 && abs_eta_mu <2.2) h_stereo_stgcOnTrackResidualTrackMS_eta9->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.2 && abs_eta_mu <2.3) h_stereo_stgcOnTrackResidualTrackMS_eta10->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.3 && abs_eta_mu <2.4) h_stereo_stgcOnTrackResidualTrackMS_eta11->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.4 && abs_eta_mu <2.5) h_stereo_stgcOnTrackResidualTrackMS_eta12->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.5 && abs_eta_mu <2.6) h_stereo_stgcOnTrackResidualTrackMS_eta13->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(abs_eta_mu >=2.6) h_stereo_stgcOnTrackResidualTrackMS_eta14->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     }
			   
			

//			Study wrt muon theta
                  double theta_mu = 2*atan(exp(-abs(muons_eta->at(index_mu))));
                  h_stgchitmuons_theta->Fill(theta_mu);

                  if(theta_mu <0.2) h_stgcOnTrackResidualTrack_PCB1_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.2 && theta_mu <0.25) h_stgcOnTrackResidualTrack_PCB2_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.25 && theta_mu <0.3) h_stgcOnTrackResidualTrack_PCB3_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.3 && theta_mu <0.35) h_stgcOnTrackResidualTrack_PCB4_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.35 && theta_mu <0.4) h_stgcOnTrackResidualTrack_PCB5_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.4 && theta_mu <0.45) h_stgcOnTrackResidualTrack_PCB6_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.45 && theta_mu <0.5) h_stgcOnTrackResidualTrack_PCB7_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  if(theta_mu >=0.5) h_stgcOnTrackResidualTrack_PCB8_theta->Fill(stgcOnTrackResidualTrack->at(i));
                  
                  if(theta_mu <0.2) h_stgcOnTrackResidualTrackMS_PCB1_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.2 && theta_mu <0.25) h_stgcOnTrackResidualTrackMS_PCB2_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.25 && theta_mu <0.3) h_stgcOnTrackResidualTrackMS_PCB3_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.3 && theta_mu <0.35) h_stgcOnTrackResidualTrackMS_PCB4_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.35 && theta_mu <0.4) h_stgcOnTrackResidualTrackMS_PCB5_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.4 && theta_mu <0.45) h_stgcOnTrackResidualTrackMS_PCB6_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.45 && theta_mu <0.5) h_stgcOnTrackResidualTrackMS_PCB7_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(theta_mu >=0.5) h_stgcOnTrackResidualTrackMS_PCB8_theta->Fill(stgcOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(theta_mu <0.2) h_eta_stgcOnTrackResidualTrack_PCB1_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_stgcOnTrackResidualTrack_PCB2_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_stgcOnTrackResidualTrack_PCB3_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_stgcOnTrackResidualTrack_PCB4_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_stgcOnTrackResidualTrack_PCB5_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_stgcOnTrackResidualTrack_PCB6_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_stgcOnTrackResidualTrack_PCB7_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_eta_stgcOnTrackResidualTrack_PCB8_theta->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_eta_stgcOnTrackResidualTrackMS_PCB1_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_stgcOnTrackResidualTrackMS_PCB2_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_stgcOnTrackResidualTrackMS_PCB3_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_stgcOnTrackResidualTrackMS_PCB4_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_stgcOnTrackResidualTrackMS_PCB5_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_stgcOnTrackResidualTrackMS_PCB6_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_stgcOnTrackResidualTrackMS_PCB7_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_eta_stgcOnTrackResidualTrackMS_PCB8_theta->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(theta_mu <0.2) h_stereo_stgcOnTrackResidualTrack_PCB1_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_stgcOnTrackResidualTrack_PCB2_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_stgcOnTrackResidualTrack_PCB3_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_stgcOnTrackResidualTrack_PCB4_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_stgcOnTrackResidualTrack_PCB5_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_stgcOnTrackResidualTrack_PCB6_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_stgcOnTrackResidualTrack_PCB7_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_stereo_stgcOnTrackResidualTrack_PCB8_theta->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_stereo_stgcOnTrackResidualTrackMS_PCB1_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_stgcOnTrackResidualTrackMS_PCB2_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_stgcOnTrackResidualTrackMS_PCB3_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_stgcOnTrackResidualTrackMS_PCB4_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_stgcOnTrackResidualTrackMS_PCB5_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_stgcOnTrackResidualTrackMS_PCB6_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_stgcOnTrackResidualTrackMS_PCB7_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_stereo_stgcOnTrackResidualTrackMS_PCB8_theta->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(theta_mu <0.2) h_eta_stgcOnTrackResidualTrack_PCB1_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_stgcOnTrackResidualTrack_PCB2_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_stgcOnTrackResidualTrack_PCB3_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_stgcOnTrackResidualTrack_PCB4_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_stgcOnTrackResidualTrack_PCB5_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_stgcOnTrackResidualTrack_PCB6_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_stgcOnTrackResidualTrack_PCB7_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_eta_stgcOnTrackResidualTrack_PCB8_theta->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_eta_stgcOnTrackResidualTrackMS_PCB1_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_eta_stgcOnTrackResidualTrackMS_PCB2_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_eta_stgcOnTrackResidualTrackMS_PCB3_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_eta_stgcOnTrackResidualTrackMS_PCB4_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_eta_stgcOnTrackResidualTrackMS_PCB5_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_eta_stgcOnTrackResidualTrackMS_PCB6_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_eta_stgcOnTrackResidualTrackMS_PCB7_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_eta_stgcOnTrackResidualTrackMS_PCB8_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(theta_mu <0.2) h_stereo_stgcOnTrackResidualTrack_PCB1_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_stgcOnTrackResidualTrack_PCB2_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_stgcOnTrackResidualTrack_PCB3_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_stgcOnTrackResidualTrack_PCB4_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_stgcOnTrackResidualTrack_PCB5_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_stgcOnTrackResidualTrack_PCB6_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_stgcOnTrackResidualTrack_PCB7_theta->Fill(stgcOnTrackResidualTrack->at(i));
                           if(theta_mu >=0.5) h_stereo_stgcOnTrackResidualTrack_PCB8_theta->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(theta_mu <0.2) h_stereo_stgcOnTrackResidualTrackMS_PCB1_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.2 && theta_mu <0.25) h_stereo_stgcOnTrackResidualTrackMS_PCB2_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.25 && theta_mu <0.3) h_stereo_stgcOnTrackResidualTrackMS_PCB3_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.3 && theta_mu <0.35) h_stereo_stgcOnTrackResidualTrackMS_PCB4_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.35 && theta_mu <0.4) h_stereo_stgcOnTrackResidualTrackMS_PCB5_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.4 && theta_mu <0.45) h_stereo_stgcOnTrackResidualTrackMS_PCB6_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.45 && theta_mu <0.5) h_stereo_stgcOnTrackResidualTrackMS_PCB7_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(theta_mu >=0.5) h_stereo_stgcOnTrackResidualTrackMS_PCB8_theta->Fill(stgcOnTrackResidualTrackMS->at(i));
                        }
                     }

//			Study wrt muon phi
                  double phi_mu = abs(muons_phi->at(index_mu));
                  h_stgchitmuons_phi->Fill(phi_mu);

                  if(phi_mu <0.4) h_stgcOnTrackResidualTrack_phi1->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=0.4 && phi_mu <0.8) h_stgcOnTrackResidualTrack_phi2->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=0.8 && phi_mu <1.2) h_stgcOnTrackResidualTrack_phi3->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=1.2 && phi_mu <1.6) h_stgcOnTrackResidualTrack_phi4->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=1.6 && phi_mu <2.) h_stgcOnTrackResidualTrack_phi5->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=2. && phi_mu <2.4) h_stgcOnTrackResidualTrack_phi6->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=2.4 && phi_mu <2.8) h_stgcOnTrackResidualTrack_phi7->Fill(stgcOnTrackResidualTrack->at(i));
                  if(phi_mu >=2.8) h_stgcOnTrackResidualTrack_phi8->Fill(stgcOnTrackResidualTrack->at(i));
                  
                  if(phi_mu <0.4) h_stgcOnTrackResidualTrackMS_phi1->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=0.4 && phi_mu <0.8) h_stgcOnTrackResidualTrackMS_phi2->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=0.8 && phi_mu <1.2) h_stgcOnTrackResidualTrackMS_phi3->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=1.2 && phi_mu <1.6) h_stgcOnTrackResidualTrackMS_phi4->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=1.6 && phi_mu <2.) h_stgcOnTrackResidualTrackMS_phi5->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2. && phi_mu <2.4) h_stgcOnTrackResidualTrackMS_phi6->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2.4 && phi_mu <2.8) h_stgcOnTrackResidualTrackMS_phi7->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(phi_mu >=2.8) h_stgcOnTrackResidualTrackMS_phi8->Fill(stgcOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(phi_mu <0.4) h_eta_stgcOnTrackResidualTrack_phi1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_stgcOnTrackResidualTrack_phi2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_stgcOnTrackResidualTrack_phi3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_stgcOnTrackResidualTrack_phi4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_stgcOnTrackResidualTrack_phi5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_stgcOnTrackResidualTrack_phi6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_stgcOnTrackResidualTrack_phi7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_eta_stgcOnTrackResidualTrack_phi8->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_eta_stgcOnTrackResidualTrackMS_phi1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_stgcOnTrackResidualTrackMS_phi2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_stgcOnTrackResidualTrackMS_phi3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_stgcOnTrackResidualTrackMS_phi4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_stgcOnTrackResidualTrackMS_phi5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_stgcOnTrackResidualTrackMS_phi6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_stgcOnTrackResidualTrackMS_phi7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_eta_stgcOnTrackResidualTrackMS_phi8->Fill(stgcOnTrackResidualTrackMS->at(i));
                        }
                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(phi_mu <0.4) h_stereo_stgcOnTrackResidualTrack_phi1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_stgcOnTrackResidualTrack_phi2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_stgcOnTrackResidualTrack_phi3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_stgcOnTrackResidualTrack_phi4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_stgcOnTrackResidualTrack_phi5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_stgcOnTrackResidualTrack_phi6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_stgcOnTrackResidualTrack_phi7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_stereo_stgcOnTrackResidualTrack_phi8->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_stereo_stgcOnTrackResidualTrackMS_phi1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_stgcOnTrackResidualTrackMS_phi2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_stgcOnTrackResidualTrackMS_phi3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_stgcOnTrackResidualTrackMS_phi4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_stgcOnTrackResidualTrackMS_phi5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_stgcOnTrackResidualTrackMS_phi6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_stgcOnTrackResidualTrackMS_phi7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_stereo_stgcOnTrackResidualTrackMS_phi8->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(phi_mu <0.4) h_eta_stgcOnTrackResidualTrack_phi1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_stgcOnTrackResidualTrack_phi2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_stgcOnTrackResidualTrack_phi3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_stgcOnTrackResidualTrack_phi4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_stgcOnTrackResidualTrack_phi5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_stgcOnTrackResidualTrack_phi6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_stgcOnTrackResidualTrack_phi7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_eta_stgcOnTrackResidualTrack_phi8->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_eta_stgcOnTrackResidualTrackMS_phi1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_eta_stgcOnTrackResidualTrackMS_phi2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_eta_stgcOnTrackResidualTrackMS_phi3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_eta_stgcOnTrackResidualTrackMS_phi4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_eta_stgcOnTrackResidualTrackMS_phi5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_eta_stgcOnTrackResidualTrackMS_phi6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_eta_stgcOnTrackResidualTrackMS_phi7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_eta_stgcOnTrackResidualTrackMS_phi8->Fill(stgcOnTrackResidualTrackMS->at(i));
                        }
                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(phi_mu <0.4) h_stereo_stgcOnTrackResidualTrack_phi1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_stgcOnTrackResidualTrack_phi2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_stgcOnTrackResidualTrack_phi3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_stgcOnTrackResidualTrack_phi4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_stgcOnTrackResidualTrack_phi5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_stgcOnTrackResidualTrack_phi6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_stgcOnTrackResidualTrack_phi7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(phi_mu >=2.8) h_stereo_stgcOnTrackResidualTrack_phi8->Fill(stgcOnTrackResidualTrack->at(i));
                           
                           if(phi_mu <0.4) h_stereo_stgcOnTrackResidualTrackMS_phi1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.4 && phi_mu <0.8) h_stereo_stgcOnTrackResidualTrackMS_phi2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=0.8 && phi_mu <1.2) h_stereo_stgcOnTrackResidualTrackMS_phi3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.2 && phi_mu <1.6) h_stereo_stgcOnTrackResidualTrackMS_phi4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=1.6 && phi_mu <2.) h_stereo_stgcOnTrackResidualTrackMS_phi5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2. && phi_mu <2.4) h_stereo_stgcOnTrackResidualTrackMS_phi6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.4 && phi_mu <2.8) h_stereo_stgcOnTrackResidualTrackMS_phi7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(phi_mu >=2.8) h_stereo_stgcOnTrackResidualTrackMS_phi8->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }
                     }

//			Study wrt hit channel	
                  /* int channel=stgcOnTrack_channel->at(i);
                  int station_eta=abs(stgcOnTrack_stationEta->at(i));
                  if(station_eta==1 && 0<=channel && channel <1024) h_stgcOnTrackResidualTrack_PCB1->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 1024<=channel && channel <2048) h_stgcOnTrackResidualTrack_PCB2->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 2048<=channel && channel <3072) h_stgcOnTrackResidualTrack_PCB3->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 3072<=channel && channel <4096) h_stgcOnTrackResidualTrack_PCB4->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==1 && 4096<=channel && channel <5120) h_stgcOnTrackResidualTrack_PCB5->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 0<=channel && channel <1024) h_stgcOnTrackResidualTrack_PCB6->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 1024<=channel && channel <2048) h_stgcOnTrackResidualTrack_PCB7->Fill(stgcOnTrackResidualTrack->at(i));
                  if(station_eta==2 && 2048<=channel && channel <3072) h_stgcOnTrackResidualTrack_PCB8->Fill(stgcOnTrackResidualTrack->at(i));
                  
                  if(station_eta==1 && 0<=channel && channel <1024) h_stgcOnTrackResidualTrackMS_PCB1->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 1024<=channel && channel <2048) h_stgcOnTrackResidualTrackMS_PCB2->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 2048<=channel && channel <3072) h_stgcOnTrackResidualTrackMS_PCB3->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 3072<=channel && channel <4096) h_stgcOnTrackResidualTrackMS_PCB4->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==1 && 4096<=channel && channel <5120) h_stgcOnTrackResidualTrackMS_PCB5->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 0<=channel && channel <1024) h_stgcOnTrackResidualTrackMS_PCB6->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 1024<=channel && channel <2048) h_stgcOnTrackResidualTrackMS_PCB7->Fill(stgcOnTrackResidualTrackMS->at(i));
                  if(station_eta==2 && 2048<=channel && channel <3072) h_stgcOnTrackResidualTrackMS_PCB8->Fill(stgcOnTrackResidualTrackMS->at(i));

                  if(multiplet == 1)
                     {
                     if(gasgap == 1||gasgap == 2)// eta
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrack_PCB1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrack_PCB2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrack_PCB3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_stgcOnTrackResidualTrack_PCB4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_stgcOnTrackResidualTrack_PCB5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrack_PCB6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrack_PCB7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrack_PCB8->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrackMS_PCB1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrackMS_PCB2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrackMS_PCB3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_stgcOnTrackResidualTrackMS_PCB4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_stgcOnTrackResidualTrackMS_PCB5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrackMS_PCB6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrackMS_PCB7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrackMS_PCB8->Fill(stgcOnTrackResidualTrackMS->at(i));  
                        }

                     if(gasgap == 3||gasgap == 4)// stereo
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrack_PCB1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrack_PCB2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrack_PCB3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_stgcOnTrackResidualTrack_PCB4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_stgcOnTrackResidualTrack_PCB5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrack_PCB6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrack_PCB7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrack_PCB8->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrackMS_PCB1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrackMS_PCB2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrackMS_PCB3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_stgcOnTrackResidualTrackMS_PCB4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_stgcOnTrackResidualTrackMS_PCB5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrackMS_PCB6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrackMS_PCB7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrackMS_PCB8->Fill(stgcOnTrackResidualTrackMS->at(i));  
                        }
                     }
                  if(multiplet == 2)
                     {
                     if(gasgap == 3||gasgap == 4)// eta
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrack_PCB1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrack_PCB2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrack_PCB3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_stgcOnTrackResidualTrack_PCB4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_stgcOnTrackResidualTrack_PCB5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrack_PCB6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrack_PCB7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrack_PCB8->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrackMS_PCB1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrackMS_PCB2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrackMS_PCB3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_eta_stgcOnTrackResidualTrackMS_PCB4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_eta_stgcOnTrackResidualTrackMS_PCB5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_eta_stgcOnTrackResidualTrackMS_PCB6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_eta_stgcOnTrackResidualTrackMS_PCB7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_eta_stgcOnTrackResidualTrackMS_PCB8->Fill(stgcOnTrackResidualTrackMS->at(i)); 
                        }

                     if(gasgap == 1||gasgap == 2)// stereo
                        {
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrack_PCB1->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrack_PCB2->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrack_PCB3->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_stgcOnTrackResidualTrack_PCB4->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_stgcOnTrackResidualTrack_PCB5->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrack_PCB6->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrack_PCB7->Fill(stgcOnTrackResidualTrack->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrack_PCB8->Fill(stgcOnTrackResidualTrack->at(i));
                     
                           if(station_eta==1 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrackMS_PCB1->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrackMS_PCB2->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrackMS_PCB3->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 3072<=channel && channel <4096) h_stereo_stgcOnTrackResidualTrackMS_PCB4->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==1 && 4096<=channel && channel <5120) h_stereo_stgcOnTrackResidualTrackMS_PCB5->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 0<=channel && channel <1024) h_stereo_stgcOnTrackResidualTrackMS_PCB6->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 1024<=channel && channel <2048) h_stereo_stgcOnTrackResidualTrackMS_PCB7->Fill(stgcOnTrackResidualTrackMS->at(i));
                           if(station_eta==2 && 2048<=channel && channel <3072) h_stereo_stgcOnTrackResidualTrackMS_PCB8->Fill(stgcOnTrackResidualTrackMS->at(i));  
                        }
                     } */
			   }
			}
   
//			Study wrt hit position
// wrt muons
                  double posx[5][3][10];
                  double posxG[5][3][10];
                  int muon_index[10]; 
                  for(int i=0; i<5; i++)
                  {
                     for(int j=0; j<3; j++)
                     {
                        for (int k=0; k<10;k++)
                        {
                           posx[i][j][k]=-9999.;
                           posxG[i][j][k]=-9999.;
                           muon_index[k]=-1;
                        }
                     }
                  }
                  
                     for(int i = 0; i < mmOnTrackResidualTrack->size(); i++)
                     {
                        int index_mu  = mmOnTrack_MuonLink->at(i);
                        muon_index[index_mu]=1.;
                        int multiplet = mmOnTrack_multiplet->at(i);
                        int layer     = mmOnTrack_gas_gap->at(i);
						if(multiplet==1){						
                        if(layer==1 || layer==2)h_x12R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==3 || layer==4)h_x34R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==1 || layer==2)h_x121R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==3 || layer==4)h_x341R->Fill(mmOnTrackResidualTrackMS->at(i));
                        }
						if(multiplet==2){						
                        if(layer==1 || layer==2)h_x34R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==3 || layer==4)h_x12R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==1 || layer==2)h_x342R->Fill(mmOnTrackResidualTrackMS->at(i));
                        if(layer==3 || layer==4)h_x122R->Fill(mmOnTrackResidualTrackMS->at(i));
                        }

                        posx[layer][multiplet][index_mu]= mmOnTrackLocalPos_x->at(i);
                        posxG[layer][multiplet][index_mu]= mmOnTrackGlobalPos_x->at(i);

                     }  

                     for(int k = 0; k < 10; k++)
                     {
                        if(muon_index[k]>0 && muons_isBad->at(k)==0)
                        {
						   double eta_mu=fabs(muons_eta->at(k));
                           double theta_mu = 2*atan(exp(-abs(muons_eta->at(k)))); 
                           // gas gap positions 24.975, 8.175, -8.175, -24.975
                           double off12=16.80*tan(theta_mu);
                           double off13=33.15*tan(theta_mu);
                           double off14=49.95*tan(theta_mu);
                           double off23=16.35*tan(theta_mu);
                           double off24=33.15*tan(theta_mu);
                           double off34=16.80*tan(theta_mu);

                           double norm =1./sqrt(2.);
                           for(int j = 1; j <= 2; j++)
                           {
                               if(j==1){
								   if(posx[1][j][k] > -2000. && posx[2][j][k] > -2000.)
									{                                
									 h_x12->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(fabs(posxG[1][j][k])>100. && fabs(posxG[1][j][k])>100.) h_x12G->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 h_x121->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(fabs(posxG[1][j][k])>100. && fabs(posxG[1][j][k])>100.)h_x121G->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3 && eta_mu<1.4)h_x12_eta01->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.4 && eta_mu<1.5)h_x12_eta02->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));										
									 if(eta_mu>=1.5 && eta_mu<1.6)h_x12_eta03->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));								   
									 if(eta_mu>=1.6 && eta_mu<1.7)h_x12_eta04->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.7 && eta_mu<1.8)h_x12_eta05->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));										
									 if(eta_mu>=1.8 && eta_mu<1.9)h_x12_eta06->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));								   
									 if(eta_mu>=1.9 && eta_mu<2.0)h_x12_eta07->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=2.0 && eta_mu<2.1)h_x12_eta08->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));										
									 if(eta_mu>=2.1 && eta_mu<2.2)h_x12_eta09->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));								   
									 if(eta_mu>=2.2 && eta_mu<2.3)h_x12_eta10->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=2.3 && eta_mu<2.4)h_x12_eta11->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));									
									 if(eta_mu>=2.4 && eta_mu<2.5)h_x12_eta12->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));								   
									 if(eta_mu>=2.5 && eta_mu<2.6)h_x12_eta13->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=2.6 && eta_mu<2.7)h_x12_eta14->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 
									 if(eta_mu>=1.3+0*0.175 && eta_mu <1.3 + 1*0.175)h_x12_qpcb01->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+1*0.175 && eta_mu <1.3 + 2*0.175)h_x12_qpcb02->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+2*0.175 && eta_mu <1.3 + 3*0.175)h_x12_qpcb03->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+3*0.175 && eta_mu <1.3 + 4*0.175)h_x12_qpcb04->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+4*0.175 && eta_mu <1.3 + 5*0.175)h_x12_qpcb05->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+5*0.175 && eta_mu <1.3 + 6*0.175)h_x12_qpcb06->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+6*0.175 && eta_mu <1.3 + 7*0.175)h_x12_qpcb07->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(eta_mu>=1.3+7*0.175 && eta_mu <1.3 + 8*0.175)h_x12_qpcb08->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 
									}
									 if(posx[3][j][k] > -2000. && posx[4][j][k] > -2000.)
									{                                
									 h_x34->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 if(fabs(posxG[3][j][k])>100. && fabs(posxG[3][j][k])>100.)h_x34G->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 h_x341->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 if(fabs(posxG[3][j][k])>100. && fabs(posxG[3][j][k])>100.)h_x341G->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									}
							   }
                                if(j==2){
								   if(posx[1][j][k] > -2000. && posx[2][j][k] > -2000.)
									{                                
									 h_x34->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(fabs(posxG[3][j][k])>100. && fabs(posxG[3][j][k])>100.)h_x34G->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 h_x342->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									 if(fabs(posxG[3][j][k])>100. && fabs(posxG[3][j][k])>100.)h_x342G->Fill(norm*(posx[1][j][k]-posx[2][j][k]+off12));
									}	
								   if(posx[3][j][k] > -2000. && posx[4][j][k] > -2000.)
									{                                
									 h_x12->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 if(fabs(posxG[1][j][k])>100. && fabs(posxG[1][j][k])>100.)h_x12G->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 h_x122->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 if(fabs(posxG[1][j][k])>100. && fabs(posxG[1][j][k])>100.)h_x122G->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off34));
									 if(eta_mu>=1.3 && eta_mu<1.4)h_x12_eta01->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.4 && eta_mu<1.5)h_x12_eta02->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));										
									 if(eta_mu>=1.5 && eta_mu<1.6)h_x12_eta03->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));								   
									 if(eta_mu>=1.6 && eta_mu<1.7)h_x12_eta04->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.7 && eta_mu<1.8)h_x12_eta05->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));									
									 if(eta_mu>=1.8 && eta_mu<1.9)h_x12_eta06->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));								   
									 if(eta_mu>=1.9 && eta_mu<2.0)h_x12_eta07->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=2.0 && eta_mu<2.1)h_x12_eta08->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));									
									 if(eta_mu>=2.1 && eta_mu<2.2)h_x12_eta09->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));								   
									 if(eta_mu>=2.2 && eta_mu<2.3)h_x12_eta10->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=2.3 && eta_mu<2.4)h_x12_eta11->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));									
									 if(eta_mu>=2.4 && eta_mu<2.5)h_x12_eta12->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));								   
									 if(eta_mu>=2.5 && eta_mu<2.6)h_x12_eta13->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=2.6 && eta_mu<2.7)h_x12_eta14->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));									

									 if(eta_mu>=1.3+0*0.175 && eta_mu <1.3 + 1*0.175)h_x12_qpcb01->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+1*0.175 && eta_mu <1.3 + 2*0.175)h_x12_qpcb02->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+2*0.175 && eta_mu <1.3 + 3*0.175)h_x12_qpcb03->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+3*0.175 && eta_mu <1.3 + 4*0.175)h_x12_qpcb04->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+4*0.175 && eta_mu <1.3 + 5*0.175)h_x12_qpcb05->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+5*0.175 && eta_mu <1.3 + 6*0.175)h_x12_qpcb06->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+6*0.175 && eta_mu <1.3 + 7*0.175)h_x12_qpcb07->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));
									 if(eta_mu>=1.3+7*0.175 && eta_mu <1.3 + 8*0.175)h_x12_qpcb08->Fill(norm*(posx[3][j][k]-posx[4][j][k]+off12));

									}
								}
                                 
						   }
               

               for(int i = 0; i < mmOnTrackGlobalPos_x->size(); i++)
                  {
                     double lx = mmOnTrackLocalPos_x->at(i);
                     double ly = mmOnTrackLocalPos_y->at(i);

                     double x = mmOnTrackGlobalPos_x->at(i);
                     double y = mmOnTrackGlobalPos_y->at(i);
                     double z = mmOnTrackGlobalPos_z->at(i);
                     
                     h_local_position->Fill(sqrt(lx*lx + ly*ly));
                     h_global_t_position->Fill(sqrt(x*x + y*y));
                     h_global_position->Fill(sqrt(x*x + y*y+z*z));
                  }


               }
            }
   }



   // At this point we write our histograms to the file and we close the file to finish

   h_muons_pt->Write();
   h_muons_eta->Write();
   h_muons_eta_abs->Write();
   h_muons_theta->Write();

   //h_mmOnTrack_gas_gap->Write();
   h_mmhitmuons_theta->Write();
   h_stgchitmuons_theta->Write();
   h_mmhitmuons_phi->Write();
   h_stgchitmuons_phi->Write();
   h_mmOnTrack_stationEta->Write();
   h_stgcOnTrack_stationEta->Write();
   h_mmOnTrack_stationPhi->Write();
   h_stgcOnTrack_stationPhi->Write();

   h_mmOnTrackResidualTrack_PhiST1->Write();
   h_mmOnTrackResidualTrack_PhiST2->Write();
   h_mmOnTrackResidualTrack_PhiST3->Write();
   h_mmOnTrackResidualTrack_PhiST4->Write();
   h_mmOnTrackResidualTrack_PhiST5->Write();
   h_mmOnTrackResidualTrack_PhiST6->Write();
   h_mmOnTrackResidualTrack_PhiST7->Write();
   h_mmOnTrackResidualTrack_PhiST8->Write();
   h_mmOnTrackResidualTrackMS_PhiST1->Write();
   h_mmOnTrackResidualTrackMS_PhiST2->Write();
   h_mmOnTrackResidualTrackMS_PhiST3->Write();
   h_mmOnTrackResidualTrackMS_PhiST4->Write();
   h_mmOnTrackResidualTrackMS_PhiST5->Write();
   h_mmOnTrackResidualTrackMS_PhiST6->Write();
   h_mmOnTrackResidualTrackMS_PhiST7->Write();
   h_mmOnTrackResidualTrackMS_PhiST8->Write();
   h_stgcOnTrackResidualTrack_PhiST1->Write();
   h_stgcOnTrackResidualTrack_PhiST2->Write();
   h_stgcOnTrackResidualTrack_PhiST3->Write();
   h_stgcOnTrackResidualTrack_PhiST4->Write();
   h_stgcOnTrackResidualTrack_PhiST5->Write();
   h_stgcOnTrackResidualTrack_PhiST6->Write();
   h_stgcOnTrackResidualTrack_PhiST7->Write();
   h_stgcOnTrackResidualTrack_PhiST8->Write();
   h_stgcOnTrackResidualTrackMS_PhiST1->Write();
   h_stgcOnTrackResidualTrackMS_PhiST2->Write();
   h_stgcOnTrackResidualTrackMS_PhiST3->Write();
   h_stgcOnTrackResidualTrackMS_PhiST4->Write();
   h_stgcOnTrackResidualTrackMS_PhiST5->Write();
   h_stgcOnTrackResidualTrackMS_PhiST6->Write();
   h_stgcOnTrackResidualTrackMS_PhiST7->Write();
   h_stgcOnTrackResidualTrackMS_PhiST8->Write();

   h_local_position->Write();
   h_global_t_position->Write();
   h_global_position->Write();
   
   //h_muons_eta_ST1->Write();
   //h_muons_eta_ST2->Write();

   h_x12->Write();
   h_x34->Write();
   h_x121->Write();
   h_x341->Write();
   h_x122->Write();
   h_x342->Write();

   h_x12R->Write();
   h_x34R->Write();
   h_x121R->Write();
   h_x341R->Write();
   h_x122R->Write();
   h_x342R->Write();

   h_x12G->Write();
   h_x34G->Write();
   h_x121G->Write();
   h_x341G->Write();
   h_x122G->Write();
   h_x342G->Write();
   
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

   h_x12_qpcb01->Write();
   h_x12_qpcb02->Write();
   h_x12_qpcb03->Write();
   h_x12_qpcb04->Write();
   h_x12_qpcb05->Write();
   h_x12_qpcb06->Write();
   h_x12_qpcb07->Write();
   h_x12_qpcb08->Write();
 

   /* h_mmOnTrackResidualTrack_x12_PCB1->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB1->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB1->Write();
   h_mmOnTrackResidualTrack_x12_PCB2->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB2->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB2->Write();
   h_mmOnTrackResidualTrack_x12_PCB3->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB3->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB3->Write();
   h_mmOnTrackResidualTrack_x12_PCB4->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB4->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB4->Write();
   h_mmOnTrackResidualTrack_x12_PCB5->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB5->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB5->Write();
   h_mmOnTrackResidualTrack_x12_PCB6->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB6->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB6->Write();
   h_mmOnTrackResidualTrack_x12_PCB7->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB7->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB7->Write();
   h_mmOnTrackResidualTrack_x12_PCB8->Write();
   h_eta_mmOnTrackResidualTrack_x12_PCB8->Write();
   h_stereo_mmOnTrackResidualTrack_x12_PCB8->Write();

   h_mmOnTrackResidualTrackMS_x12_PCB1->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB1->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB1->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB2->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB2->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB2->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB3->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB3->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB3->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB4->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB4->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB4->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB5->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB5->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB5->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB6->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB6->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB6->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB7->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB7->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB7->Write();
   h_mmOnTrackResidualTrackMS_x12_PCB8->Write();
   h_eta_mmOnTrackResidualTrackMS_x12_PCB8->Write();
   h_stereo_mmOnTrackResidualTrackMS_x12_PCB8->Write();

   h_mmOnTrackResidualTrack_x34_PCB1->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB1->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB1->Write();
   h_mmOnTrackResidualTrack_x34_PCB2->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB2->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB2->Write();
   h_mmOnTrackResidualTrack_x34_PCB3->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB3->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB3->Write();
   h_mmOnTrackResidualTrack_x34_PCB4->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB4->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB4->Write();
   h_mmOnTrackResidualTrack_x34_PCB5->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB5->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB5->Write();
   h_mmOnTrackResidualTrack_x34_PCB6->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB6->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB6->Write();
   h_mmOnTrackResidualTrack_x34_PCB7->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB7->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB7->Write();
   h_mmOnTrackResidualTrack_x34_PCB8->Write();
   h_eta_mmOnTrackResidualTrack_x34_PCB8->Write();
   h_stereo_mmOnTrackResidualTrack_x34_PCB8->Write();

   h_mmOnTrackResidualTrackMS_x34_PCB1->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB1->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB1->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB2->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB2->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB2->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB3->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB3->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB3->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB4->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB4->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB4->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB5->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB5->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB5->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB6->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB6->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB6->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB7->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB7->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB7->Write();
   h_mmOnTrackResidualTrackMS_x34_PCB8->Write();
   h_eta_mmOnTrackResidualTrackMS_x34_PCB8->Write();
   h_stereo_mmOnTrackResidualTrackMS_x34_PCB8->Write(); */

   h_mmOnTrackResidualTrack->Write();
   h_mmOnTrackResidualTrackMS->Write();
   h_mmOnTrackResidualTrack_pt20->Write();
   h_mmOnTrackResidualTrackMS_pt20->Write();
   h_mmOnTrackResidualTrack_ST1->Write();
   h_mmOnTrackResidualTrackMS_ST1->Write();
   h_eta_mmOnTrackResidualTrack_ST1->Write();
   h_eta_mmOnTrackResidualTrackMS_ST1->Write();
   h_mmOnTrackResidualTrack_ST2->Write();
   h_mmOnTrackResidualTrackMS_ST2->Write();
   h_eta_mmOnTrackResidualTrack_ST2->Write();
   h_eta_mmOnTrackResidualTrackMS_ST2->Write();
//////////MM
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
//////////sTGC
//PCB
   /* h_stgcOnTrackResidualTrack_PCB1->Write();
   h_eta_stgcOnTrackResidualTrack_PCB1->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB1->Write();
	h_stgcOnTrackResidualTrack_PCB2->Write();
   h_eta_stgcOnTrackResidualTrack_PCB2->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB2->Write();
	h_stgcOnTrackResidualTrack_PCB3->Write();
   h_eta_stgcOnTrackResidualTrack_PCB3->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB3->Write();
	h_stgcOnTrackResidualTrack_PCB4->Write();
   h_eta_stgcOnTrackResidualTrack_PCB4->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB4->Write();
	h_stgcOnTrackResidualTrack_PCB5->Write();
   h_eta_stgcOnTrackResidualTrack_PCB5->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB5->Write();
	h_stgcOnTrackResidualTrack_PCB6->Write();
   h_eta_stgcOnTrackResidualTrack_PCB6->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB6->Write();
	h_stgcOnTrackResidualTrack_PCB7->Write();
   h_eta_stgcOnTrackResidualTrack_PCB7->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB7->Write();
	h_stgcOnTrackResidualTrack_PCB8->Write();
   h_eta_stgcOnTrackResidualTrack_PCB8->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB8->Write();

   h_stgcOnTrackResidualTrackMS_PCB1->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB1->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB1->Write();
	h_stgcOnTrackResidualTrackMS_PCB2->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB2->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB2->Write();
	h_stgcOnTrackResidualTrackMS_PCB3->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB3->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB3->Write();
	h_stgcOnTrackResidualTrackMS_PCB4->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB4->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB4->Write();
	h_stgcOnTrackResidualTrackMS_PCB5->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB5->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB5->Write();
	h_stgcOnTrackResidualTrackMS_PCB6->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB6->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB6->Write();
	h_stgcOnTrackResidualTrackMS_PCB7->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB7->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB7->Write();
	h_stgcOnTrackResidualTrackMS_PCB8->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB8->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB8->Write(); */
//eta
   h_stgcOnTrackResidualTrack_eta1->Write();
   h_eta_stgcOnTrackResidualTrack_eta1->Write();
   h_stereo_stgcOnTrackResidualTrack_eta1->Write();
	h_stgcOnTrackResidualTrack_eta2->Write();
   h_eta_stgcOnTrackResidualTrack_eta2->Write();
   h_stereo_stgcOnTrackResidualTrack_eta2->Write();
   h_stgcOnTrackResidualTrack_eta3->Write();
   h_eta_stgcOnTrackResidualTrack_eta3->Write();
   h_stereo_stgcOnTrackResidualTrack_eta3->Write();
   h_stgcOnTrackResidualTrack_eta4->Write();
   h_eta_stgcOnTrackResidualTrack_eta4->Write();
   h_stereo_stgcOnTrackResidualTrack_eta4->Write();
   h_stgcOnTrackResidualTrack_eta5->Write();
   h_eta_stgcOnTrackResidualTrack_eta5->Write();
   h_stereo_stgcOnTrackResidualTrack_eta5->Write();
   h_stgcOnTrackResidualTrack_eta6->Write();
   h_eta_stgcOnTrackResidualTrack_eta6->Write();
   h_stereo_stgcOnTrackResidualTrack_eta6->Write();
   h_stgcOnTrackResidualTrack_eta7->Write();
   h_eta_stgcOnTrackResidualTrack_eta7->Write();
   h_stereo_stgcOnTrackResidualTrack_eta7->Write();
   h_stgcOnTrackResidualTrack_eta8->Write();
   h_eta_stgcOnTrackResidualTrack_eta8->Write();
   h_stereo_stgcOnTrackResidualTrack_eta8->Write();
   h_stgcOnTrackResidualTrack_eta9->Write();
   h_eta_stgcOnTrackResidualTrack_eta9->Write();
   h_stereo_stgcOnTrackResidualTrack_eta9->Write();
   h_stgcOnTrackResidualTrack_eta10->Write();
   h_eta_stgcOnTrackResidualTrack_eta10->Write();
   h_stereo_stgcOnTrackResidualTrack_eta10->Write();
   h_stgcOnTrackResidualTrack_eta11->Write();
   h_eta_stgcOnTrackResidualTrack_eta11->Write();
   h_stereo_stgcOnTrackResidualTrack_eta11->Write();
   h_stgcOnTrackResidualTrack_eta12->Write();
   h_eta_stgcOnTrackResidualTrack_eta12->Write();
   h_stereo_stgcOnTrackResidualTrack_eta12->Write();
   h_stgcOnTrackResidualTrack_eta13->Write();
   h_eta_stgcOnTrackResidualTrack_eta13->Write();
   h_stereo_stgcOnTrackResidualTrack_eta13->Write();
   h_stgcOnTrackResidualTrack_eta14->Write();
   h_eta_stgcOnTrackResidualTrack_eta14->Write();
   h_stereo_stgcOnTrackResidualTrack_eta14->Write();
   
   h_stgcOnTrackResidualTrackMS_eta1->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta1->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta1->Write();
	h_stgcOnTrackResidualTrackMS_eta2->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta2->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta2->Write();
   h_stgcOnTrackResidualTrackMS_eta3->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta3->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta3->Write();
   h_stgcOnTrackResidualTrackMS_eta4->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta4->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta4->Write();
   h_stgcOnTrackResidualTrackMS_eta5->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta5->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta5->Write();
   h_stgcOnTrackResidualTrackMS_eta6->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta6->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta6->Write();
   h_stgcOnTrackResidualTrackMS_eta7->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta7->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta7->Write();
   h_stgcOnTrackResidualTrackMS_eta8->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta8->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta8->Write();
   h_stgcOnTrackResidualTrackMS_eta9->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta9->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta9->Write();
   h_stgcOnTrackResidualTrackMS_eta10->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta10->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta10->Write();
   h_stgcOnTrackResidualTrackMS_eta11->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta11->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta11->Write();
   h_stgcOnTrackResidualTrackMS_eta12->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta12->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta12->Write();
   h_stgcOnTrackResidualTrackMS_eta13->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta13->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta13->Write();
   h_stgcOnTrackResidualTrackMS_eta14->Write();
   h_eta_stgcOnTrackResidualTrackMS_eta14->Write();
   h_stereo_stgcOnTrackResidualTrackMS_eta14->Write();
//theta
   h_stgcOnTrackResidualTrack_PCB1_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB1_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB1_theta->Write();
	h_stgcOnTrackResidualTrack_PCB2_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB2_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB2_theta->Write();
	h_stgcOnTrackResidualTrack_PCB3_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB3_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB3_theta->Write();
	h_stgcOnTrackResidualTrack_PCB4_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB4_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB4_theta->Write();
	h_stgcOnTrackResidualTrack_PCB5_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB5_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB5_theta->Write();
	h_stgcOnTrackResidualTrack_PCB6_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB6_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB6_theta->Write();
	h_stgcOnTrackResidualTrack_PCB7_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB7_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB7_theta->Write();
	h_stgcOnTrackResidualTrack_PCB8_theta->Write();
   h_eta_stgcOnTrackResidualTrack_PCB8_theta->Write();
   h_stereo_stgcOnTrackResidualTrack_PCB8_theta->Write();
   
   h_stgcOnTrackResidualTrackMS_PCB1_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB1_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB1_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB2_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB2_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB2_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB3_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB3_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB3_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB4_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB4_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB4_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB5_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB5_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB5_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB6_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB6_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB6_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB7_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB7_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB7_theta->Write();
	h_stgcOnTrackResidualTrackMS_PCB8_theta->Write();
   h_eta_stgcOnTrackResidualTrackMS_PCB8_theta->Write();
   h_stereo_stgcOnTrackResidualTrackMS_PCB8_theta->Write();
//phi
   h_stgcOnTrackResidualTrack_phi1->Write();
   h_eta_stgcOnTrackResidualTrack_phi1->Write();
   h_stereo_stgcOnTrackResidualTrack_phi1->Write();
	h_stgcOnTrackResidualTrack_phi2->Write();
   h_eta_stgcOnTrackResidualTrack_phi2->Write();
   h_stereo_stgcOnTrackResidualTrack_phi2->Write();
	h_stgcOnTrackResidualTrack_phi3->Write();
   h_eta_stgcOnTrackResidualTrack_phi3->Write();
   h_stereo_stgcOnTrackResidualTrack_phi3->Write();
	h_stgcOnTrackResidualTrack_phi4->Write();
   h_eta_stgcOnTrackResidualTrack_phi4->Write();
   h_stereo_stgcOnTrackResidualTrack_phi4->Write();
	h_stgcOnTrackResidualTrack_phi5->Write();
   h_eta_stgcOnTrackResidualTrack_phi5->Write();
   h_stereo_stgcOnTrackResidualTrack_phi5->Write();
	h_stgcOnTrackResidualTrack_phi6->Write();
   h_eta_stgcOnTrackResidualTrack_phi6->Write();
   h_stereo_stgcOnTrackResidualTrack_phi6->Write();
	h_stgcOnTrackResidualTrack_phi7->Write();
   h_eta_stgcOnTrackResidualTrack_phi7->Write();
   h_stereo_stgcOnTrackResidualTrack_phi7->Write();
	h_stgcOnTrackResidualTrack_phi8->Write();
   h_eta_stgcOnTrackResidualTrack_phi8->Write();
   h_stereo_stgcOnTrackResidualTrack_phi8->Write();
   
   h_stgcOnTrackResidualTrackMS_phi1->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi1->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi1->Write();
	h_stgcOnTrackResidualTrackMS_phi2->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi2->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi2->Write();
	h_stgcOnTrackResidualTrackMS_phi3->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi3->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi3->Write();
	h_stgcOnTrackResidualTrackMS_phi4->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi4->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi4->Write();
	h_stgcOnTrackResidualTrackMS_phi5->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi5->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi5->Write();
	h_stgcOnTrackResidualTrackMS_phi6->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi6->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi6->Write();
	h_stgcOnTrackResidualTrackMS_phi7->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi7->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi7->Write();
	h_stgcOnTrackResidualTrackMS_phi8->Write();
   h_eta_stgcOnTrackResidualTrackMS_phi8->Write();
   h_stereo_stgcOnTrackResidualTrackMS_phi8->Write();
 
   rfile->Close();

}