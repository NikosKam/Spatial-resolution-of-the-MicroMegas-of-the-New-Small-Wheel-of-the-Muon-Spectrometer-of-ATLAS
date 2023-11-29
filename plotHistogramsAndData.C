#include <TFile.h>
#include <TTree.h>
#include <TH1F.h>
#include <TCanvas.h>
#include <TLegend.h>

//function
Double_t FitFunction(Double_t* x, Double_t* par);
void FitPol1_Gauss(TGraphErrors* graph1);
void FitPol1(TGraph* graph1,TGraph* graph2);
void plot_single(TH1F *mc_hist);
void plot(TH1F *mc_hist, TH1F *real_hist);
void plot4(TGraphErrors *mc_graph_eta, TGraphErrors *mc_graph_stereo, TGraphErrors *real_graph_eta, TGraphErrors *real_graph_stereo);
void plot2_CB(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype);
void plot2(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype);
void plot2_Gauss(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype);
void plot3_Gauss(TGraphErrors *mc_graph, TGraphErrors *graph,TGraphErrors *real_graph , TString striptype);

void plotHistogramsAndData() {
    
    // Simulated MC data
    //TFile *mc_file = new TFile("MuonTester_Res_MC_ParticleGun.root");  // MC simulated data ROOT file
    // Gauss
    TFile *mc_file = new TFile("MC/Gauss/MC_FinaleHistograms.root");  // MC simulated data ROOT file
    ////Unscaled
    //TFile *mc_file = new TFile("MC/no rebin/MC_FinaleHistograms.root");  // MC simulated data ROOT file RESULTS
    //TFile *mc_file = new TFile("MC/rebin(2)/MC_FinaleHistograms.root");  // MC simulated data ROOT file RESULTS
    //TFile *mc_file = new TFile("MC/rebin(4)/MC_FinaleHistograms.root");  // MC simulated data ROOT file RESULTS
    //Scaled
    //TFile *mc_file = new TFile("MC_Scaled/no rebin/MC_FinaleHistograms_Scaled.root");  // MC simulated data ROOT file RESULTS
    //TFile *mc_file = new TFile("MC_Scaled/rebin(2)/MC_FinaleHistograms_Scaled.root");  // MC simulated data ROOT file RESULTS
    //TFile *mc_file = new TFile("MC_Scaled/rebin(4)/MC_FinaleHistograms_Scaled.root");  // MC simulated data ROOT file RESULTS

    //TTree* mc_tree = (TTree*)mc_file->Get("tree_name");  // Replace "tree_name" with your TTree name

    //sigma graphs

    //Gauss only

    //c1
    TGraphErrors *Sigma1_MS_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;1");
    TGraphErrors *Sigma1_MS_stereo_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;2");
    //c101
    TGraphErrors *Sigma1_MS_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;3");
    //c2
    TGraphErrors *Sigma1_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;4");
    TGraphErrors *Sigma1_stereo_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;5");
    //c201
    TGraphErrors *Sigma1_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;6");
    //c3
    TGraphErrors *Sigma1_MS_eta_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;7");
    TGraphErrors *Sigma1_MS_stereo_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;8");
    //c301
    TGraphErrors *Sigma1_MS_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;9");
    //c4
    TGraphErrors *Sigma1_eta_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;10");
    TGraphErrors *Sigma1_stereo_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;11");
    //c401
    TGraphErrors *Sigma1_theta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;12");
    //c5
    TGraphErrors *Sigma1_MS_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;13");
    TGraphErrors *Sigma1_MS_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;14");
    //c501
    TGraphErrors *Sigma1_MS__eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;15");
    //c6
    TGraphErrors *Sigma1_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;16");
    TGraphErrors *Sigma1_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;17");
    //c601
    TGraphErrors *Sigma1__eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;18");
    //c71
    TGraphErrors *Sigma1_MS_Phi01_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;19");
    TGraphErrors *Sigma1_MS_Phi01_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;20");
    //c72
    TGraphErrors *Sigma1_MS_Phi02_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;21");
    TGraphErrors *Sigma1_MS_Phi02_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;22");
    //c73
    TGraphErrors *Sigma1_MS_Phi03_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;23");
    TGraphErrors *Sigma1_MS_Phi03_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;24");
    //c74
    TGraphErrors *Sigma1_MS_Phi04_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;25");
    TGraphErrors *Sigma1_MS_Phi04_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;26");
    //c75
    TGraphErrors *Sigma1_MS_Phi05_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;27");
    TGraphErrors *Sigma1_MS_Phi05_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;28");
    //c76
    TGraphErrors *Sigma1_MS_Phi06_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;29");
    TGraphErrors *Sigma1_MS_Phi06_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;30");
    //c77
    TGraphErrors *Sigma1_MS_Phi07_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;31");
    TGraphErrors *Sigma1_MS_Phi07_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;32");
    //c78
    TGraphErrors *Sigma1_MS_Phi08_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;33");
    TGraphErrors *Sigma1_MS_Phi08_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;34");
    //c79
    TGraphErrors *Sigma1_MS_SmallSector_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;35");
    TGraphErrors *Sigma1_MS_SmallSector_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;36");
    //c710
    TGraphErrors *Sigma1_MS_LargeSector_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;37");
    TGraphErrors *Sigma1_MS_LargeSector_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;38");
    //c701
    TGraphErrors *Sigma1_MS_Phi01_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;39");
    //c702
    TGraphErrors *Sigma1_MS_Phi02_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;40");
    //c703
    TGraphErrors *Sigma1_MS_Phi03_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;41");
    //c704
    TGraphErrors *Sigma1_MS_Phi04_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;42");
    //c705
    TGraphErrors *Sigma1_MS_Phi05_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;43");
    //c706
    TGraphErrors *Sigma1_MS_Phi06_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;44");
    //c707
    TGraphErrors *Sigma1_MS_Phi07_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;45");
    //c708
    TGraphErrors *Sigma1_MS_Phi08_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;46");
    //c717
    TGraphErrors *Sigma1_Phi01_eta_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;47");
    TGraphErrors *Sigma1_Phi01_stereo_eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;48");
    //c7071
    TGraphErrors *Sigma1_Phi01_Eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;49");
    //c82
    TGraphErrors *Sigma1_posx12pcb_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;50");
    //c802
    TGraphErrors *Sigma1_posx12eta_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;51");
    //c803
    TGraphErrors *Sigma1_posx12eta_short_Gauss_MC = (TGraphErrors *)mc_file->Get("Graph;52");

    /* //c1
    TGraphErrors *Sigma1_MS_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;1");//Get("Sigma1_MS_eta_CB");
    TGraphErrors *Sigma1_MS_stereo_CB_MC = (TGraphErrors *)mc_file->Get("Graph;2");//Get("Sigma1_MS_stereo_CB");
    TGraphErrors *Sigma1_MS_eta_MC = (TGraphErrors *)mc_file->Get("Graph;3");//Get("Sigma1_MS_eta");
    TGraphErrors *Sigma1_MS_stereo_MC = (TGraphErrors *)mc_file->Get("Graph;4");//Get("Sigma1_MS_stereo");
    //c101
    TGraphErrors *Sigma1_MS_CB_MC = (TGraphErrors *)mc_file->Get("Graph;5");
    TGraphErrors *Sigma1_MS_MC = (TGraphErrors *)mc_file->Get("Graph;6");
    //c2
    TGraphErrors *Sigma1_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;7");
    TGraphErrors *Sigma1_stereo_CB_MC = (TGraphErrors *)mc_file->Get("Graph;8");
    TGraphErrors *Sigma1_eta_MC = (TGraphErrors *)mc_file->Get("Graph;9");
    TGraphErrors *Sigma1_stereo_MC = (TGraphErrors *)mc_file->Get("Graph;10");
    //c201
    TGraphErrors *Sigma1_CB_MC = (TGraphErrors *)mc_file->Get("Graph;11");
    TGraphErrors *Sigma1_MC = (TGraphErrors *)mc_file->Get("Graph;12");
    //c3
    TGraphErrors *Sigma1_MS_eta_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;13");
    TGraphErrors *Sigma1_MS_stereo_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;14");
    TGraphErrors *Sigma1_MS_eta_theta_MC = (TGraphErrors *)mc_file->Get("Graph;15");
    TGraphErrors *Sigma1_MS_stereo_theta_MC = (TGraphErrors *)mc_file->Get("Graph;16");
    //c301
    TGraphErrors *Sigma1_MS_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;17");
    TGraphErrors *Sigma1_MS_theta_MC = (TGraphErrors *)mc_file->Get("Graph;18");
    //c4
    TGraphErrors *Sigma1_eta_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;19");
    TGraphErrors *Sigma1_stereo_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;20");
    TGraphErrors *Sigma1_eta_theta_MC = (TGraphErrors *)mc_file->Get("Graph;21");
    TGraphErrors *Sigma1_stereo_theta_MC = (TGraphErrors *)mc_file->Get("Graph;22");
    //c401
    TGraphErrors *Sigma1_theta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;23");
    TGraphErrors *Sigma1_theta_MC = (TGraphErrors *)mc_file->Get("Graph;24");
    //c5
    TGraphErrors *Sigma1_MS_eta_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;25");
    TGraphErrors *Sigma1_MS_stereo_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;26");
    TGraphErrors *Sigma1_MS_eta_eta_MC = (TGraphErrors *)mc_file->Get("Graph;27");
    TGraphErrors *Sigma1_MS_stereo_eta_MC = (TGraphErrors *)mc_file->Get("Graph;28");
    //c501
    TGraphErrors *Sigma1_MS__eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;29");
    TGraphErrors *Sigma1_MS__eta_MC = (TGraphErrors *)mc_file->Get("Graph;30");
    //c6
    TGraphErrors *Sigma1_eta_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;31");
    TGraphErrors *Sigma1_stereo_eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;32");
    TGraphErrors *Sigma1_eta_eta_MC = (TGraphErrors *)mc_file->Get("Graph;33");
    TGraphErrors *Sigma1_stereo_eta_MC = (TGraphErrors *)mc_file->Get("Graph;34");
    //c601
    TGraphErrors *Sigma1__eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;35");
    TGraphErrors *Sigma1__eta_MC = (TGraphErrors *)mc_file->Get("Graph;36");
    //c82
    TGraphErrors *Sigma1_posx12pcb_CB_MC = (TGraphErrors *)mc_file->Get("Graph;37");
    TGraphErrors *Sigma1_posx12pcb_MC = (TGraphErrors *)mc_file->Get("Graph;38");
    //c802
    TGraphErrors *Sigma1_posx12eta_CB_MC = (TGraphErrors *)mc_file->Get("Graph;39");
    TGraphErrors *Sigma1_posx12eta_MC = (TGraphErrors *)mc_file->Get("Graph;40");
    //c9
    TGraphErrors *Sigma1_pos_CB_MC = (TGraphErrors *)mc_file->Get("Graph;41");
    TGraphErrors *Sigma1_pos_MC = (TGraphErrors *)mc_file->Get("Graph;42"); */

    //kinematic and reconstructed ver

    /* TH1F *h_mmOnTrackResidualTrack_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack");
    TH1F *h_mmOnTrackResidualTrackMS_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS");
    TH1F *h_mmOnTrackResidualTrack_pt20_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_pt20");
    TH1F *h_mmOnTrackResidualTrackMS_pt20_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_pt20");
    TH1F *h_mmOnTrackResidualTrack_ST1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_ST1");
    TH1F *h_mmOnTrackResidualTrack_ST2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_ST2");
    TH1F *h_mmOnTrackResidualTrackMS_ST1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_ST1");
    TH1F *h_mmOnTrackResidualTrackMS_ST2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_ST2");
    TH1F *h_eta_mmOnTrackResidualTrack_ST1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_ST1");
    TH1F *h_eta_mmOnTrackResidualTrack_ST2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_ST2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_ST1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_ST1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_ST2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_ST2");

    TH1F *h_mmOnTrack_gas_gap_MC = (TH1F *)mc_file->Get("mmOnTrack_gas_gap"); 

    TH1F *h_muons_pt_MC = (TH1F *)mc_file->Get("muons_pt");     
    TH1F *h_local_position_MC = (TH1F *)mc_file->Get("local_position"); 
    TH1F *h_global_position_MC = (TH1F *)mc_file->Get("global_position");
    TH1F *h_global_t_position_MC = (TH1F *)mc_file->Get("global_t_position"); 
    TH1F *h_muons_eta_MC = (TH1F *)mc_file->Get("muons_eta");
    TH1F *h_muons_eta_abs_MC = (TH1F *)mc_file->Get("muons_eta_abs");
    TH1F *h_muons_theta_MC = (TH1F *)mc_file->Get("muons_theta");
    TH1F *h_muons_eta_ST1_MC = (TH1F *)mc_file->Get("muons_eta_ST1");
    TH1F *h_muons_eta_ST2_MC = (TH1F *)mc_file->Get("muons_eta_ST2"); */

    TH1F *h_x12_MC = (TH1F *)mc_file->Get("x12");
    TH1F *h_x121_MC = (TH1F *)mc_file->Get("x121");
    TH1F *h_x341_MC = (TH1F *)mc_file->Get("x341");
    TH1F *h_x122_MC = (TH1F *)mc_file->Get("x122");
    TH1F *h_x342_MC = (TH1F *)mc_file->Get("x342");
    TH1F *h_x34_MC = (TH1F *)mc_file->Get("x34");
    
    //pcb

    TH1F *h_mmOnTrackResidualTrack_PCB1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB1");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB1");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB1");
    TH1F *h_mmOnTrackResidualTrack_PCB2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB2");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB2");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB2");
    TH1F *h_mmOnTrackResidualTrack_PCB3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB3");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB3");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB3");
    TH1F *h_mmOnTrackResidualTrack_PCB4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB4");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB4");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB4");
    TH1F *h_mmOnTrackResidualTrack_PCB5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB5");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB5");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB5");
    TH1F *h_mmOnTrackResidualTrack_PCB6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB6");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB6");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB6");
    TH1F *h_mmOnTrackResidualTrack_PCB7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB7");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB7");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB7");
    TH1F *h_mmOnTrackResidualTrack_PCB8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB8");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB8");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB8");

    TH1F *h_mmOnTrackResidualTrackMS_PCB1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_mmOnTrackResidualTrackMS_PCB2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_mmOnTrackResidualTrackMS_PCB3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_mmOnTrackResidualTrackMS_PCB4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_mmOnTrackResidualTrackMS_PCB5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_mmOnTrackResidualTrackMS_PCB6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_mmOnTrackResidualTrackMS_PCB7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_mmOnTrackResidualTrackMS_PCB8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB8");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB8");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB8");

    //eta

    TH1F *h_mmOnTrackResidualTrack_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta1");
    TH1F *h_eta_mmOnTrackResidualTrack_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta1");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta1");
    TH1F *h_mmOnTrackResidualTrack_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta2");
    TH1F *h_eta_mmOnTrackResidualTrack_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta2");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta2");
    TH1F *h_mmOnTrackResidualTrack_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta3");
    TH1F *h_eta_mmOnTrackResidualTrack_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta3");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta3");
    TH1F *h_mmOnTrackResidualTrack_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta4");
    TH1F *h_eta_mmOnTrackResidualTrack_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta4");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta4");
    TH1F *h_mmOnTrackResidualTrack_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta5");
    TH1F *h_eta_mmOnTrackResidualTrack_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta5");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta5");
    TH1F *h_mmOnTrackResidualTrack_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta6");
    TH1F *h_eta_mmOnTrackResidualTrack_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta6");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta6");
    TH1F *h_mmOnTrackResidualTrack_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta7");
    TH1F *h_eta_mmOnTrackResidualTrack_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta7");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta7");
    TH1F *h_mmOnTrackResidualTrack_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta8");
    TH1F *h_eta_mmOnTrackResidualTrack_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta8");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta8");
    TH1F *h_mmOnTrackResidualTrack_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta9");
    TH1F *h_eta_mmOnTrackResidualTrack_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta9");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta9");
    TH1F *h_mmOnTrackResidualTrack_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta10");
    TH1F *h_eta_mmOnTrackResidualTrack_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta10");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta10");
    TH1F *h_mmOnTrackResidualTrack_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta11");
    TH1F *h_eta_mmOnTrackResidualTrack_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta11");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta11");
    TH1F *h_mmOnTrackResidualTrack_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta12");
    TH1F *h_eta_mmOnTrackResidualTrack_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta12");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta12");
    TH1F *h_mmOnTrackResidualTrack_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta13");
    TH1F *h_eta_mmOnTrackResidualTrack_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta13");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta13");
    TH1F *h_mmOnTrackResidualTrack_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_eta14");
    TH1F *h_eta_mmOnTrackResidualTrack_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_eta14");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_eta14");

    TH1F *h_mmOnTrackResidualTrackMS_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta1");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta1");
    TH1F *h_mmOnTrackResidualTrackMS_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta2");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta2");
    TH1F *h_mmOnTrackResidualTrackMS_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta3");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta3");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta3");
    TH1F *h_mmOnTrackResidualTrackMS_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta4");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta4");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta4");
    TH1F *h_mmOnTrackResidualTrackMS_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta5");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta5");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta5");
    TH1F *h_mmOnTrackResidualTrackMS_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta6");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta6");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta6");
    TH1F *h_mmOnTrackResidualTrackMS_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta7");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta7");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta7");
    TH1F *h_mmOnTrackResidualTrackMS_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta8");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta8");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta8");
    TH1F *h_mmOnTrackResidualTrackMS_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta9");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta9");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta9");
    TH1F *h_mmOnTrackResidualTrackMS_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta10");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta10");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta10");
    TH1F *h_mmOnTrackResidualTrackMS_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta11");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta11");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta11");
    TH1F *h_mmOnTrackResidualTrackMS_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta12");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta12");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta12");
    TH1F *h_mmOnTrackResidualTrackMS_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta13");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta13");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta13");
    TH1F *h_mmOnTrackResidualTrackMS_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_eta14");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_eta14");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_eta14");

///Phi01

   TH1F *h_mmOnTrackResidualTrackPhi01_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi01_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi01_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi01_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi01_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi01_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi01_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi01_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi01_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi01_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi01_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi01_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi01_eta14");

///Phi02

   TH1F *h_mmOnTrackResidualTrackPhi02_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi02_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi02_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi02_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi02_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi02_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi02_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi02_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi02_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi02_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi02_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi02_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi02_eta14");

///Phi03

   TH1F *h_mmOnTrackResidualTrackPhi03_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi03_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi03_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi03_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi03_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi03_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi03_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi03_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi03_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi03_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi03_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi03_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi03_eta14");
///Phi04

   TH1F *h_mmOnTrackResidualTrackPhi04_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi04_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi04_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi04_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi04_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi04_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi04_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi04_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi04_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi04_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi04_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi04_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi04_eta14");

///Phi05

   TH1F *h_mmOnTrackResidualTrackPhi05_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi05_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi05_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi05_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi05_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi05_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi05_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi05_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi05_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi05_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi05_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi05_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi05_eta14");

///Phi06

   TH1F *h_mmOnTrackResidualTrackPhi06_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi06_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi06_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi06_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi06_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi06_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi06_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi06_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi06_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi06_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi06_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi06_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi06_eta14");

///Phi07

   TH1F *h_mmOnTrackResidualTrackPhi07_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi07_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi07_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi07_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi07_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi07_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi07_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi07_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi07_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi07_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi07_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi07_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi07_eta14");

///Phi08

   TH1F *h_mmOnTrackResidualTrackPhi08_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta1");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta2");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta3");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta4");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta5");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta6");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta7");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta8");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta9");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta10");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta11");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta12");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta13");
   TH1F *h_mmOnTrackResidualTrackPhi08_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackPhi08_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackPhi08_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackPhi08_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackPhi08_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackPhi08_eta14");

   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta1");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta2");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta3");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta4");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta5");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta6");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta7");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta8");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta9");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta10");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta11");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta12");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta13");
   TH1F *h_mmOnTrackResidualTrackMSPhi08_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSPhi08_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSPhi08_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSPhi08_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSPhi08_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSPhi08_eta14");

///LargeSector

   TH1F *h_mmOnTrackResidualTrackLargeSector_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta1");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta2");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta3");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta4");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta5");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta6");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta7");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta8");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta9");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta10");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta11");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta12");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta13");
   TH1F *h_mmOnTrackResidualTrackLargeSector_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackLargeSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackLargeSector_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackLargeSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackLargeSector_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackLargeSector_eta14");

   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta1");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta2");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta3");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta4");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta5");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta6");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta7");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta8");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta9");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta10");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta11");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta12");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta13");
   TH1F *h_mmOnTrackResidualTrackMSLargeSector_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSLargeSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSLargeSector_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSLargeSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSLargeSector_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSLargeSector_eta14");

///SmallSector

   TH1F *h_mmOnTrackResidualTrackSmallSector_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta1");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta2");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta3");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta4");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta5");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta6");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta7");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta8");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta9");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta10");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta11");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta12");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta13");
   TH1F *h_mmOnTrackResidualTrackSmallSector_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackSmallSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackSmallSector_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackSmallSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackSmallSector_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackSmallSector_eta14");

   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta1");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta2");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta3");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta4");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta5");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta6");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta7");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta8");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta9_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta9_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta9_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta9");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta10_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta10_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta10_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta10");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta11_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta11_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta11_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta11");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta12_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta12_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta12_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta12");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta13_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta13_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta13_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta13");
   TH1F *h_mmOnTrackResidualTrackMSSmallSector_eta14_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMSSmallSector_eta14");
   TH1F *h_eta_mmOnTrackResidualTrackMSSmallSector_eta14_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMSSmallSector_eta14");
   TH1F *h_stereo_mmOnTrackResidualTrackMSSmallSector_eta14_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMSSmallSector_eta14");

    //theta

    TH1F *h_mmOnTrackResidualTrack_PCB1_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB1_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB1_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB2_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB2_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB2_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB3_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB3_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB3_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB4_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB4_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB4_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB5_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB5_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB5_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB6_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB6_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB6_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB7_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB7_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB7_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB8_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_PCB8_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB8_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_PCB8_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB8_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_PCB8_theta");

    TH1F *h_mmOnTrackResidualTrackMS_PCB1_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB2_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB3_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB4_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB5_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB6_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB7_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB8_theta_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_PCB8_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8_theta_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_PCB8_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8_theta_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_PCB8_theta");

//phi

   TH1F *h_mmOnTrackResidualTrack_phi1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi1");
   TH1F *h_eta_mmOnTrackResidualTrack_phi1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi1");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi1");
   TH1F *h_mmOnTrackResidualTrack_phi2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi2");
   TH1F *h_eta_mmOnTrackResidualTrack_phi2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi2");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi2");
   TH1F *h_mmOnTrackResidualTrack_phi3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi3");
   TH1F *h_eta_mmOnTrackResidualTrack_phi3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi3");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi3");
   TH1F *h_mmOnTrackResidualTrack_phi4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi4");
   TH1F *h_eta_mmOnTrackResidualTrack_phi4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi4");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi4");
   TH1F *h_mmOnTrackResidualTrack_phi5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi5");
   TH1F *h_eta_mmOnTrackResidualTrack_phi5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi5");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi5");
   TH1F *h_mmOnTrackResidualTrack_phi6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi6");
   TH1F *h_eta_mmOnTrackResidualTrack_phi6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi6");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi6");
   TH1F *h_mmOnTrackResidualTrack_phi7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi7");
   TH1F *h_eta_mmOnTrackResidualTrack_phi7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi7");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi7");
   TH1F *h_mmOnTrackResidualTrack_phi8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrack_phi8");
   TH1F *h_eta_mmOnTrackResidualTrack_phi8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrack_phi8");
   TH1F *h_stereo_mmOnTrackResidualTrack_phi8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrack_phi8");

   TH1F *h_mmOnTrackResidualTrackMS_phi1_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi1");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi1_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi1");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi1_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi1");
   TH1F *h_mmOnTrackResidualTrackMS_phi2_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi2");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi2_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi2");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi2_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi2");
   TH1F *h_mmOnTrackResidualTrackMS_phi3_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi3");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi3_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi3");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi3_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi3");
   TH1F *h_mmOnTrackResidualTrackMS_phi4_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi4");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi4_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi4");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi4_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi4");
   TH1F *h_mmOnTrackResidualTrackMS_phi5_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi5");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi5_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi5");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi5_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi5");
   TH1F *h_mmOnTrackResidualTrackMS_phi6_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi6");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi6_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi6");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi6_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi6");
   TH1F *h_mmOnTrackResidualTrackMS_phi7_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi7");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi7_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi7");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi7_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi7");
   TH1F *h_mmOnTrackResidualTrackMS_phi8_MC = (TH1F *)mc_file->Get("mmOnTrackResidualTrackMS_phi8");
   TH1F *h_eta_mmOnTrackResidualTrackMS_phi8_MC = (TH1F *)mc_file->Get("eta_mmOnTrackResidualTrackMS_phi8");
   TH1F *h_stereo_mmOnTrackResidualTrackMS_phi8_MC = (TH1F *)mc_file->Get("stereo_mmOnTrackResidualTrackMS_phi8");

    //position

    TH1F *h_x12_eta01_MC = (TH1F *)mc_file->Get("x12_eta01");
    TH1F *h_x12_eta02_MC = (TH1F *)mc_file->Get("x12_eta02");
    TH1F *h_x12_eta03_MC = (TH1F *)mc_file->Get("x12_eta03");
    TH1F *h_x12_eta04_MC = (TH1F *)mc_file->Get("x12_eta04");
    TH1F *h_x12_eta05_MC = (TH1F *)mc_file->Get("x12_eta05");
    TH1F *h_x12_eta06_MC = (TH1F *)mc_file->Get("x12_eta06");
    TH1F *h_x12_eta07_MC = (TH1F *)mc_file->Get("x12_eta07");
    TH1F *h_x12_eta08_MC = (TH1F *)mc_file->Get("x12_eta08");
    TH1F *h_x12_eta09_MC = (TH1F *)mc_file->Get("x12_eta09");
    TH1F *h_x12_eta10_MC = (TH1F *)mc_file->Get("x12_eta10");
    TH1F *h_x12_eta11_MC = (TH1F *)mc_file->Get("x12_eta11");
    TH1F *h_x12_eta12_MC = (TH1F *)mc_file->Get("x12_eta12");
    TH1F *h_x12_eta13_MC = (TH1F *)mc_file->Get("x12_eta13");
    TH1F *h_x12_eta14_MC = (TH1F *)mc_file->Get("x12_eta14");

    TH1F *h_x12_eta1_MC = (TH1F *)mc_file->Get("mergedHistogram;1");
    TH1F *h_x12_eta2_MC = (TH1F *)mc_file->Get("mergedHistogram;2");
    TH1F *h_x12_eta3_MC = (TH1F *)mc_file->Get("mergedHistogram;3");
    TH1F *h_x12_eta4_MC = (TH1F *)mc_file->Get("mergedHistogram;4");
    TH1F *h_x12_eta5_MC = (TH1F *)mc_file->Get("mergedHistogram;5");
    TH1F *h_x12_eta6_MC = (TH1F *)mc_file->Get("mergedHistogram;6");
    TH1F *h_x12_eta7_MC = (TH1F *)mc_file->Get("mergedHistogram;7");

    TH1F *h_x12_qpcb01_MC = (TH1F *)mc_file->Get("x12_qpcb01");
    TH1F *h_x12_qpcb02_MC = (TH1F *)mc_file->Get("x12_qpcb02");
    TH1F *h_x12_qpcb03_MC = (TH1F *)mc_file->Get("x12_qpcb03");
    TH1F *h_x12_qpcb04_MC = (TH1F *)mc_file->Get("x12_qpcb04");
    TH1F *h_x12_qpcb05_MC = (TH1F *)mc_file->Get("x12_qpcb05");
    TH1F *h_x12_qpcb06_MC = (TH1F *)mc_file->Get("x12_qpcb06");
    TH1F *h_x12_qpcb07_MC = (TH1F *)mc_file->Get("x12_qpcb07");
    TH1F *h_x12_qpcb08_MC = (TH1F *)mc_file->Get("x12_qpcb08");

    /* TH1F *h_x12R_MC = (TH1F *)mc_file->Get("x12R");
    TH1F *h_x121R_MC = (TH1F *)mc_file->Get("x121R");
    TH1F *h_x341R_MC = (TH1F *)mc_file->Get("x341R");
    TH1F *h_x122R_MC = (TH1F *)mc_file->Get("x122R");
    TH1F *h_x342R_MC = (TH1F *)mc_file->Get("x342R");
    TH1F *h_x34R_MC = (TH1F *)mc_file->Get("x34R"); */

    /* TH1F *h_x12R_MS_MC = (TH1F *)mc_file->Get("x12R_MS");
    TH1F *h_x13R_MS_MC = (TH1F *)mc_file->Get("x13R_MS");
    TH1F *h_x14R_MS_MC = (TH1F *)mc_file->Get("x14R_MS");
    TH1F *h_x23R_MS_MC = (TH1F *)mc_file->Get("x23R_MS");
    TH1F *h_x24R_MS_MC = (TH1F *)mc_file->Get("x24R_MS");
    TH1F *h_x34R_MS_MC = (TH1F *)mc_file->Get("x34R_MS"); */

    ///////////////////////////////////////////////////////////// At this point we scale the histograms //////////////////////////////////////////////////////////////////////////////////

    /* h_mmOnTrackResidualTrack_MC->Scale(1./h_mmOnTrackResidualTrack_MC->Integral());
    h_mmOnTrackResidualTrackMS_MC->Scale(1./h_mmOnTrackResidualTrackMS_MC->Integral());
    h_mmOnTrackResidualTrack_pt20_MC->Scale(1./h_mmOnTrackResidualTrack_pt20_MC->Integral());
    h_mmOnTrackResidualTrackMS_pt20_MC->Scale(1./h_mmOnTrackResidualTrackMS_pt20_MC->Integral());
    h_mmOnTrackResidualTrack_ST1_MC->Scale(1./h_mmOnTrackResidualTrack_ST1_MC->Integral());
    h_mmOnTrackResidualTrack_ST2_MC->Scale(1./h_mmOnTrackResidualTrack_ST2_MC->Integral());
    h_mmOnTrackResidualTrackMS_ST1_MC->Scale(1./h_mmOnTrackResidualTrackMS_ST1_MC->Integral());
    h_mmOnTrackResidualTrackMS_ST2_MC->Scale(1./h_mmOnTrackResidualTrackMS_ST2_MC->Integral());
    h_eta_mmOnTrackResidualTrack_ST1_MC->Scale(1./h_eta_mmOnTrackResidualTrack_ST1_MC->Integral());
    h_eta_mmOnTrackResidualTrack_ST2_MC->Scale(1./h_eta_mmOnTrackResidualTrack_ST2_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_ST1_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_ST1_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_ST2_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_ST2_MC->Integral());

    h_mmOnTrack_gas_gap_MC->Scale(1./h_mmOnTrack_gas_gap_MC->Integral());

    //h_muons_pt_MC->Scale(1./h_muons_pt_MC->Integral());      
    h_local_position_MC->Scale(1./h_local_position_MC->Integral());
    h_global_position_MC->Scale(1./h_global_position_MC->Integral());
    h_global_t_position_MC->Scale(1./h_global_t_position_MC->Integral());
    //h_muons_eta_MC->Scale(1./h_muons_eta_MC->Integral());
    h_muons_eta_abs_MC->Scale(1./h_muons_eta_abs_MC->Integral());
    h_muons_theta_MC->Scale(1./h_muons_theta_MC->Integral());
    //h_muons_eta_ST1_MC->Scale(1./h_muons_eta_ST1_MC->Integral());
    //h_muons_eta_ST2_MC->Scale(1./h_muons_eta_ST2_MC->Integral());

    h_x12_MC->Scale(1./h_x12_MC->Integral());
    h_x121_MC->Scale(1./h_x121_MC->Integral());
    h_x341_MC->Scale(1./h_x341_MC->Integral());
    h_x122_MC->Scale(1./h_x122_MC->Integral());
    h_x342_MC->Scale(1./h_x342_MC->Integral());
    h_x34_MC->Scale(1./h_x34_MC->Integral()); */
    
    /* //c1
    Sigma1_MS_eta_CB_MC->Scale(1./Sigma1_MS_eta_CB_MC->Integral());
    Sigma1_MS_stereo_CB_MC->Scale(1./Sigma1_MS_stereo_CB_MC->Integral());
    Sigma1_MS_eta_MC->Scale(1./Sigma1_MS_eta_MC->Integral());
    Sigma1_MS_stereo_MC->Scale(1./Sigma1_MS_stereo_MC->Integral());
    //c101
    Sigma1_MS_CB_MC->Scale(1./Sigma1_MS_CB_MC->Integral());
    Sigma1_MS_MC->Scale(1./Sigma1_MS_MC->Integral());
    //c2
    Sigma1_eta_CB_MC->Scale(1./Sigma1_eta_CB_MC->Integral());
    Sigma1_stereo_CB_MC->Scale(1./Sigma1_stereo_CB_MC->Integral());
    Sigma1_eta_MC->Scale(1./Sigma1_eta_MC->Integral());
    Sigma1_stereo_MC->Scale(1./Sigma1_stereo_MC->Integral());
    //c201
    Sigma1_CB_MC->Scale(1./Sigma1_CB_MC->Integral());
    Sigma1_MC->Scale(1./Sigma1_MC->Integral());
    //c3
    Sigma1_MS_eta_theta_CB_MC->Scale(1./Sigma1_MS_eta_theta_CB_MC->Integral());
    Sigma1_MS_stereo_theta_CB_MC->Scale(1./Sigma1_MS_stereo_theta_CB_MC->Integral());
    Sigma1_MS_eta_theta_MC->Scale(1./Sigma1_MS_eta_theta_MC->Integral());
    Sigma1_MS_stereo_theta_MC->Scale(1./Sigma1_MS_stereo_theta_MC->Integral());
    //c301
    Sigma1_MS_theta_CB_MC->Scale(1./Sigma1_MS_theta_CB_MC->Integral());
    Sigma1_MS_theta_MC->Scale(1./Sigma1_MS_theta_MC->Integral());
    //c4
    Sigma1_eta_theta_CB_MC->Scale(1./Sigma1_eta_theta_CB_MC->Integral());
    Sigma1_stereo_theta_CB_MC->Scale(1./Sigma1_stereo_theta_CB_MC->Integral());
    Sigma1_eta_theta_MC->Scale(1./Sigma1_eta_theta_MC->Integral());
    Sigma1_stereo_theta_MC->Scale(1./Sigma1_stereo_theta_MC->Integral());
    //c401
    Sigma1_theta_CB_MC->Scale(1./Sigma1_theta_CB_MC->Integral());
    Sigma1_theta_MC->Scale(1./Sigma1_theta_MC->Integral());
    //c5
    Sigma1_MS_eta_eta_CB_MC->Scale(1./Sigma1_MS_eta_eta_CB_MC->Integral());
    Sigma1_MS_stereo_eta_CB_MC->Scale(1./Sigma1_MS_stereo_eta_CB_MC->Integral());
    Sigma1_MS_eta_eta_MC->Scale(1./Sigma1_MS_eta_eta_MC->Integral());
    Sigma1_MS_stereo_eta_MC->Scale(1./Sigma1_MS_stereo_eta_MC->Integral());
    //c501
    Sigma1_MS__eta_CB_MC->Scale(1./Sigma1_MS__eta_CB_MC->Integral());
    Sigma1_MS__eta_MC->Scale(1./Sigma1_MS__eta_MC->Integral());
    //c6
    Sigma1_eta_eta_CB_MC->Scale(1./Sigma1_eta_eta_CB_MC->Integral());
    Sigma1_stereo_eta_CB_MC->Scale(1./Sigma1_stereo_eta_CB_MC->Integral());
    Sigma1_eta_eta_MC->Scale(1./Sigma1_eta_eta_MC->Integral());
    Sigma1_stereo_eta_MC->Scale(1./Sigma1_stereo_eta_MC->Integral());
    //c601
    Sigma1__eta_CB_MC->Scale(1./Sigma1__eta_CB_MC->Integral());
    Sigma1__eta_MC->Scale(1./Sigma1__eta_MC->Integral());
    //c82
    Sigma1_posx12pcb_CB_MC->Scale(1./Sigma1_posx12pcb_CB_MC->Integral());
    Sigma1_posx12pcb_MC->Scale(1./Sigma1_posx12pcb_MC->Integral());
    //c802
    Sigma1_posx12eta_CB_MC->Scale(1./Sigma1_posx12eta_CB_MC->Integral());
    Sigma1_posx12eta_MC->Scale(1./Sigma1_posx12eta_MC->Integral());
    //c9
    Sigma1_pos_CB_MC->Scale(1./Sigma1_pos_CB_MC->Integral());
    Sigma1_pos_MC->Scale(1./Sigma1_pos_MC->Integral()); */



    /* h_mmOnTrackResidualTrack_PCB1_MC->Scale(1./h_mmOnTrackResidualTrack_PCB1_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB1_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB1_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB1_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB1_MC->Integral());
    h_mmOnTrackResidualTrack_PCB2_MC->Scale(1./h_mmOnTrackResidualTrack_PCB2_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB2_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB2_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB2_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB2_MC->Integral());
    h_mmOnTrackResidualTrack_PCB3_MC->Scale(1./h_mmOnTrackResidualTrack_PCB3_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB3_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB3_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB3_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB3_MC->Integral());
    h_mmOnTrackResidualTrack_PCB4_MC->Scale(1./h_mmOnTrackResidualTrack_PCB4_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB4_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB4_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB4_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB4_MC->Integral());
    h_mmOnTrackResidualTrack_PCB5_MC->Scale(1./h_mmOnTrackResidualTrack_PCB5_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB5_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB5_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB5_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB5_MC->Integral());
    h_mmOnTrackResidualTrack_PCB6_MC->Scale(1./h_mmOnTrackResidualTrack_PCB6_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB6_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB6_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB6_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB6_MC->Integral());
    h_mmOnTrackResidualTrack_PCB7_MC->Scale(1./h_mmOnTrackResidualTrack_PCB7_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB7_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB7_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB7_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB7_MC->Integral());
    h_mmOnTrackResidualTrack_PCB8_MC->Scale(1./h_mmOnTrackResidualTrack_PCB8_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB8_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB8_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB8_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB8_MC->Integral());

    h_mmOnTrackResidualTrackMS_PCB1_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB1_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB1_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB1_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB1_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB1_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB2_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB2_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB2_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB2_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB2_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB2_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB3_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB3_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB3_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB3_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB3_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB3_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB4_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB4_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB4_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB4_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB4_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB4_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB5_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB5_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB5_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB5_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB5_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB5_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB6_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB6_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB6_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB6_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB6_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB6_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB7_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB7_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB7_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB7_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB7_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB7_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB8_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB8_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB8_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB8_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB8_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB8_MC->Integral());

    h_mmOnTrackResidualTrack_eta1_MC->Scale(1./h_mmOnTrackResidualTrack_eta1_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta1_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta1_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta1_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta1_MC->Integral());
    h_mmOnTrackResidualTrack_eta2_MC->Scale(1./h_mmOnTrackResidualTrack_eta2_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta2_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta2_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta2_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta2_MC->Integral());
    h_mmOnTrackResidualTrack_eta3_MC->Scale(1./h_mmOnTrackResidualTrack_eta3_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta3_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta3_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta3_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta3_MC->Integral());
    h_mmOnTrackResidualTrack_eta4_MC->Scale(1./h_mmOnTrackResidualTrack_eta4_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta4_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta4_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta4_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta4_MC->Integral());
    h_mmOnTrackResidualTrack_eta5_MC->Scale(1./h_mmOnTrackResidualTrack_eta5_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta5_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta5_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta5_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta5_MC->Integral());
    h_mmOnTrackResidualTrack_eta6_MC->Scale(1./h_mmOnTrackResidualTrack_eta6_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta6_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta6_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta6_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta6_MC->Integral());
    h_mmOnTrackResidualTrack_eta7_MC->Scale(1./h_mmOnTrackResidualTrack_eta7_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta7_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta7_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta7_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta7_MC->Integral());
    h_mmOnTrackResidualTrack_eta8_MC->Scale(1./h_mmOnTrackResidualTrack_eta8_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta8_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta8_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta8_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta8_MC->Integral());
    h_mmOnTrackResidualTrack_eta9_MC->Scale(1./h_mmOnTrackResidualTrack_eta9_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta9_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta9_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta9_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta9_MC->Integral());
    h_mmOnTrackResidualTrack_eta10_MC->Scale(1./h_mmOnTrackResidualTrack_eta10_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta10_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta10_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta10_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta10_MC->Integral());
    h_mmOnTrackResidualTrack_eta11_MC->Scale(1./h_mmOnTrackResidualTrack_eta11_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta11_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta11_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta11_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta11_MC->Integral());
    h_mmOnTrackResidualTrack_eta12_MC->Scale(1./h_mmOnTrackResidualTrack_eta12_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta12_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta12_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta12_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta12_MC->Integral());
    h_mmOnTrackResidualTrack_eta13_MC->Scale(1./h_mmOnTrackResidualTrack_eta13_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta13_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta13_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta13_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta13_MC->Integral());
    h_mmOnTrackResidualTrack_eta14_MC->Scale(1./h_mmOnTrackResidualTrack_eta14_MC->Integral());
    h_eta_mmOnTrackResidualTrack_eta14_MC->Scale(1./h_eta_mmOnTrackResidualTrack_eta14_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_eta14_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_eta14_MC->Integral());

    h_mmOnTrackResidualTrackMS_eta1_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta1_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta1_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta1_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta1_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta1_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta2_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta2_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta2_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta2_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta2_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta2_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta3_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta3_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta3_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta3_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta3_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta3_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta4_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta4_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta4_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta4_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta4_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta4_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta5_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta5_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta5_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta5_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta5_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta5_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta6_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta6_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta6_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta6_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta6_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta6_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta7_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta7_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta7_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta7_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta7_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta7_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta8_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta8_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta8_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta8_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta8_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta8_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta9_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta9_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta9_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta9_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta9_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta9_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta10_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta10_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta10_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta10_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta10_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta10_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta11_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta11_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta11_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta11_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta11_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta11_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta12_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta12_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta12_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta12_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta12_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta12_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta13_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta13_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta13_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta13_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta13_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta13_MC->Integral());
    h_mmOnTrackResidualTrackMS_eta14_MC->Scale(1./h_mmOnTrackResidualTrackMS_eta14_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_eta14_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_eta14_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_eta14_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_eta14_MC->Integral());

    h_mmOnTrackResidualTrack_PCB1_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB1_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB1_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB1_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB1_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB1_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB2_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB2_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB2_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB2_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB2_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB2_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB3_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB3_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB3_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB3_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB3_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB3_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB4_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB4_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB4_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB4_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB4_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB4_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB5_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB5_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB5_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB5_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB5_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB5_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB6_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB6_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB6_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB6_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB6_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB6_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB7_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB7_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB7_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB7_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB7_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB7_theta_MC->Integral());
    h_mmOnTrackResidualTrack_PCB8_theta_MC->Scale(1./h_mmOnTrackResidualTrack_PCB8_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrack_PCB8_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrack_PCB8_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrack_PCB8_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrack_PCB8_theta_MC->Integral());

    h_mmOnTrackResidualTrackMS_PCB1_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB1_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB1_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB1_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB1_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB1_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB2_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB2_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB2_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB2_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB2_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB2_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB3_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB3_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB3_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB3_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB3_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB3_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB4_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB4_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB4_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB4_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB4_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB4_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB5_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB5_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB5_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB5_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB5_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB5_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB6_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB6_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB6_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB6_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB6_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB6_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB7_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB7_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB7_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB7_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB7_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB7_theta_MC->Integral());
    h_mmOnTrackResidualTrackMS_PCB8_theta_MC->Scale(1./h_mmOnTrackResidualTrackMS_PCB8_theta_MC->Integral());
    h_eta_mmOnTrackResidualTrackMS_PCB8_theta_MC->Scale(1./h_eta_mmOnTrackResidualTrackMS_PCB8_theta_MC->Integral());
    h_stereo_mmOnTrackResidualTrackMS_PCB8_theta_MC->Scale(1./h_stereo_mmOnTrackResidualTrackMS_PCB8_theta_MC->Integral());

    h_x12_eta01_MC->Scale(1./h_x12_eta01_MC->Integral());
    h_x12_eta02_MC->Scale(1./h_x12_eta02_MC->Integral());
    h_x12_eta03_MC->Scale(1./h_x12_eta03_MC->Integral());
    h_x12_eta04_MC->Scale(1./h_x12_eta04_MC->Integral());
    h_x12_eta05_MC->Scale(1./h_x12_eta05_MC->Integral());
    h_x12_eta06_MC->Scale(1./h_x12_eta06_MC->Integral());
    h_x12_eta07_MC->Scale(1./h_x12_eta07_MC->Integral());
    h_x12_eta08_MC->Scale(1./h_x12_eta08_MC->Integral());
    h_x12_eta09_MC->Scale(1./h_x12_eta09_MC->Integral());
    h_x12_eta10_MC->Scale(1./h_x12_eta10_MC->Integral());
    h_x12_eta11_MC->Scale(1./h_x12_eta11_MC->Integral());
    h_x12_eta12_MC->Scale(1./h_x12_eta12_MC->Integral());
    h_x12_eta13_MC->Scale(1./h_x12_eta13_MC->Integral());
    h_x12_eta14_MC->Scale(1./h_x12_eta14_MC->Integral());

    h_x12_qpcb01_MC->Scale(1./h_x12_qpcb01_MC->Integral());
    h_x12_qpcb02_MC->Scale(1./h_x12_qpcb02_MC->Integral());
    h_x12_qpcb03_MC->Scale(1./h_x12_qpcb03_MC->Integral());
    h_x12_qpcb04_MC->Scale(1./h_x12_qpcb04_MC->Integral());
    h_x12_qpcb05_MC->Scale(1./h_x12_qpcb05_MC->Integral());
    h_x12_qpcb06_MC->Scale(1./h_x12_qpcb06_MC->Integral());
    h_x12_qpcb07_MC->Scale(1./h_x12_qpcb07_MC->Integral());
    h_x12_qpcb08_MC->Scale(1./h_x12_qpcb08_MC->Integral());

    h_x12R_MC->Scale(1./h_x12R_MC->Integral());
    h_x121R_MC->Scale(1./h_x121R_MC->Integral());
    h_x341R_MC->Scale(1./h_x341R_MC->Integral());
    h_x122R_MC->Scale(1./h_x122R_MC->Integral());
    h_x342R_MC->Scale(1./h_x342R_MC->Integral());
    h_x34R_MC->Scale(1./h_x34R_MC->Integral());

 */
    // Real data (plot as data points)
    TFile* real_file = new TFile("MuonTester_Res_452573.root");  // Real data ROOT file
    //Unscaled
    //TFile *real_file = new TFile("Data/no rebin/FinaleHistograms.root");  // Real data ROOT file RESULTS
    //TFile *real_file = new TFile("Data/rebin(2)/FinaleHistograms.root");  // Real data ROOT file RESULTS
    //TFile *real_file = new TFile("Data/rebin(4)/FinaleHistograms.root");  // Real data ROOT file RESULTS
    //Scaled
    //TFile *real_file = new TFile("Data_Scaled/no rebin/FinaleHistograms_Scaled.root");  // Real data ROOT file RESULTS
    //TFile *real_file = new TFile("Data_Scaled/rebin(2)/FinaleHistograms_Scaled.root");  // Real data ROOT file RESULTS
    //TFile *real_file = new TFile("Data_Scaled/rebin(4)/FinaleHistograms_Scaled.root");  // Real data ROOT file RESULTS

    //TTree* real_tree = (TTree*)real_file->Get("tree_name");  // Replace "tree_name" with your TTree name

    //sigma graphs

    /* //c1
    TGraphErrors *Sigma1_MS_eta_CB = (TGraphErrors *)real_file->Get("Graph;1");//Get("Sigma1_MS_eta_CB");
    TGraphErrors *Sigma1_MS_stereo_CB = (TGraphErrors *)real_file->Get("Graph;2");//Get("Sigma1_MS_stereo_CB");
    TGraphErrors *Sigma1_MS_eta = (TGraphErrors *)real_file->Get("Graph;3");//Get("Sigma1_MS_eta");
    TGraphErrors *Sigma1_MS_stereo = (TGraphErrors *)real_file->Get("Graph;4");//Get("Sigma1_MS_stereo");
    //c101
    TGraphErrors *Sigma1_MS_CB = (TGraphErrors *)real_file->Get("Graph;5");
    TGraphErrors *Sigma1_MS = (TGraphErrors *)real_file->Get("Graph;6");
    //c2
    TGraphErrors *Sigma1_eta_CB = (TGraphErrors *)real_file->Get("Graph;7");
    TGraphErrors *Sigma1_stereo_CB = (TGraphErrors *)real_file->Get("Graph;8");
    TGraphErrors *Sigma1_eta = (TGraphErrors *)real_file->Get("Graph;9");
    TGraphErrors *Sigma1_stereo = (TGraphErrors *)real_file->Get("Graph;10");
    //c201
    TGraphErrors *Sigma1_CB = (TGraphErrors *)real_file->Get("Graph;11");
    TGraphErrors *Sigma1 = (TGraphErrors *)real_file->Get("Graph;12");
    //c3
    TGraphErrors *Sigma1_MS_eta_theta_CB = (TGraphErrors *)real_file->Get("Graph;13");
    TGraphErrors *Sigma1_MS_stereo_theta_CB = (TGraphErrors *)real_file->Get("Graph;14");
    TGraphErrors *Sigma1_MS_eta_theta = (TGraphErrors *)real_file->Get("Graph;15");
    TGraphErrors *Sigma1_MS_stereo_theta = (TGraphErrors *)real_file->Get("Graph;16");
    //c301
    TGraphErrors *Sigma1_MS_theta_CB = (TGraphErrors *)real_file->Get("Graph;17");
    TGraphErrors *Sigma1_MS_theta = (TGraphErrors *)real_file->Get("Graph;18");
    //c4
    TGraphErrors *Sigma1_eta_theta_CB = (TGraphErrors *)real_file->Get("Graph;19");
    TGraphErrors *Sigma1_stereo_theta_CB = (TGraphErrors *)real_file->Get("Graph;20");
    TGraphErrors *Sigma1_eta_theta = (TGraphErrors *)real_file->Get("Graph;21");
    TGraphErrors *Sigma1_stereo_theta = (TGraphErrors *)real_file->Get("Graph;22");
    //c401
    TGraphErrors *Sigma1_theta_CB = (TGraphErrors *)real_file->Get("Graph;23");
    TGraphErrors *Sigma1_theta = (TGraphErrors *)real_file->Get("Graph;24");
    //c5
    TGraphErrors *Sigma1_MS_eta_eta_CB = (TGraphErrors *)real_file->Get("Graph;25");
    TGraphErrors *Sigma1_MS_stereo_eta_CB = (TGraphErrors *)real_file->Get("Graph;26");
    TGraphErrors *Sigma1_MS_eta_eta = (TGraphErrors *)real_file->Get("Graph;27");
    TGraphErrors *Sigma1_MS_stereo_eta = (TGraphErrors *)real_file->Get("Graph;28");
    //c501
    TGraphErrors *Sigma1_MS__eta_CB = (TGraphErrors *)real_file->Get("Graph;29");
    TGraphErrors *Sigma1_MS__eta = (TGraphErrors *)real_file->Get("Graph;30");
    //c6
    TGraphErrors *Sigma1_eta_eta_CB = (TGraphErrors *)real_file->Get("Graph;31");
    TGraphErrors *Sigma1_stereo_eta_CB = (TGraphErrors *)real_file->Get("Graph;32");
    TGraphErrors *Sigma1_eta_eta = (TGraphErrors *)real_file->Get("Graph;33");
    TGraphErrors *Sigma1_stereo_eta = (TGraphErrors *)real_file->Get("Graph;34");
    //c601
    TGraphErrors *Sigma1__eta_CB = (TGraphErrors *)real_file->Get("Graph;35");
    TGraphErrors *Sigma1__eta = (TGraphErrors *)real_file->Get("Graph;36");
    //c82
    TGraphErrors *Sigma1_posx12pcb_CB = (TGraphErrors *)real_file->Get("Graph;37");
    TGraphErrors *Sigma1_posx12pcb = (TGraphErrors *)real_file->Get("Graph;38");
    //c802
    TGraphErrors *Sigma1_posx12eta_CB = (TGraphErrors *)real_file->Get("Graph;39");
    TGraphErrors *Sigma1_posx12eta = (TGraphErrors *)real_file->Get("Graph;40");
    //c9
    TGraphErrors *Sigma1_pos_CB = (TGraphErrors *)real_file->Get("Graph;41");
    TGraphErrors *Sigma1_pos = (TGraphErrors *)real_file->Get("Graph;42"); */
    
    //kinematic and reconstructed ver

    TH1F *h_mmOnTrackResidualTrack = (TH1F *)real_file->Get("mmOnTrackResidualTrack");
    TH1F *h_mmOnTrackResidualTrackMS = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS");
    TH1F *h_mmOnTrackResidualTrack_pt20 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_pt20");
    TH1F *h_mmOnTrackResidualTrackMS_pt20 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_pt20");
    TH1F *h_mmOnTrackResidualTrack_ST1 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_ST1");
    TH1F *h_mmOnTrackResidualTrack_ST2 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_ST2");
    TH1F *h_mmOnTrackResidualTrackMS_ST1 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_ST1");
    TH1F *h_mmOnTrackResidualTrackMS_ST2 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_ST2");
    TH1F *h_eta_mmOnTrackResidualTrack_ST1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_ST1");
    TH1F *h_eta_mmOnTrackResidualTrack_ST2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_ST2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_ST1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_ST1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_ST2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_ST2");

    TH1F *h_mmOnTrack_gas_gap = (TH1F *)real_file->Get("mmOnTrack_gas_gap"); 

    TH1F *h_muons_pt = (TH1F *)real_file->Get("muons_pt");     
    TH1F *h_local_position = (TH1F *)real_file->Get("local_position"); 
    TH1F *h_global_position = (TH1F *)real_file->Get("global_position");
    TH1F *h_global_t_position = (TH1F *)real_file->Get("global_t_position"); 
    TH1F *h_muons_eta = (TH1F *)real_file->Get("muons_eta");
    TH1F *h_muons_eta_abs = (TH1F *)real_file->Get("muons_eta_abs");
    TH1F *h_muons_theta = (TH1F *)real_file->Get("muons_theta");
    TH1F *h_muons_eta_ST1 = (TH1F *)real_file->Get("muons_eta_ST1");
    TH1F *h_muons_eta_ST2 = (TH1F *)real_file->Get("muons_eta_ST2");

    TH1F *h_x12 = (TH1F *)real_file->Get("x12");
    TH1F *h_x121 = (TH1F *)real_file->Get("x121");
    TH1F *h_x341 = (TH1F *)real_file->Get("x341");
    TH1F *h_x122 = (TH1F *)real_file->Get("x122");
    TH1F *h_x342 = (TH1F *)real_file->Get("x342");
    TH1F *h_x34 = (TH1F *)real_file->Get("x34");
    
    //pcb

    TH1F *h_mmOnTrackResidualTrack_PCB1 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB1");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB1");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB1 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB1");
    TH1F *h_mmOnTrackResidualTrack_PCB2 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB2");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB2");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB2 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB2");
    TH1F *h_mmOnTrackResidualTrack_PCB3 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB3");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB3 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB3");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB3 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB3");
    TH1F *h_mmOnTrackResidualTrack_PCB4 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB4");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB4 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB4");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB4 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB4");
    TH1F *h_mmOnTrackResidualTrack_PCB5 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB5");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB5 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB5");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB5 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB5");
    TH1F *h_mmOnTrackResidualTrack_PCB6 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB6");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB6 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB6");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB6 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB6");
    TH1F *h_mmOnTrackResidualTrack_PCB7 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB7");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB7 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB7");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB7 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB7");
    TH1F *h_mmOnTrackResidualTrack_PCB8 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB8");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB8 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB8");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB8 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB8");

    TH1F *h_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB1");
    TH1F *h_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB2");
    TH1F *h_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB3");
    TH1F *h_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB4");
    TH1F *h_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB5");
    TH1F *h_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB6");
    TH1F *h_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB7");
    TH1F *h_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB8");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB8");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB8");

    //eta

    TH1F *h_mmOnTrackResidualTrack_eta1 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta1");
    TH1F *h_eta_mmOnTrackResidualTrack_eta1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta1");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta1 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta1");
    TH1F *h_mmOnTrackResidualTrack_eta2 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta2");
    TH1F *h_eta_mmOnTrackResidualTrack_eta2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta2");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta2 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta2");
    TH1F *h_mmOnTrackResidualTrack_eta3 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta3");
    TH1F *h_eta_mmOnTrackResidualTrack_eta3 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta3");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta3 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta3");
    TH1F *h_mmOnTrackResidualTrack_eta4 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta4");
    TH1F *h_eta_mmOnTrackResidualTrack_eta4 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta4");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta4 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta4");
    TH1F *h_mmOnTrackResidualTrack_eta5 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta5");
    TH1F *h_eta_mmOnTrackResidualTrack_eta5 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta5");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta5 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta5");
    TH1F *h_mmOnTrackResidualTrack_eta6 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta6");
    TH1F *h_eta_mmOnTrackResidualTrack_eta6 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta6");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta6 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta6");
    TH1F *h_mmOnTrackResidualTrack_eta7 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta7");
    TH1F *h_eta_mmOnTrackResidualTrack_eta7 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta7");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta7 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta7");
    TH1F *h_mmOnTrackResidualTrack_eta8 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta8");
    TH1F *h_eta_mmOnTrackResidualTrack_eta8 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta8");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta8 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta8");
    TH1F *h_mmOnTrackResidualTrack_eta9 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta9");
    TH1F *h_eta_mmOnTrackResidualTrack_eta9 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta9");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta9 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta9");
    TH1F *h_mmOnTrackResidualTrack_eta10 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta10");
    TH1F *h_eta_mmOnTrackResidualTrack_eta10 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta10");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta10 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta10");
    TH1F *h_mmOnTrackResidualTrack_eta11 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta11");
    TH1F *h_eta_mmOnTrackResidualTrack_eta11 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta11");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta11 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta11");
    TH1F *h_mmOnTrackResidualTrack_eta12 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta12");
    TH1F *h_eta_mmOnTrackResidualTrack_eta12 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta12");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta12 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta12");
    TH1F *h_mmOnTrackResidualTrack_eta13 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta13");
    TH1F *h_eta_mmOnTrackResidualTrack_eta13 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta13");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta13 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta13");
    TH1F *h_mmOnTrackResidualTrack_eta14 = (TH1F *)real_file->Get("mmOnTrackResidualTrack_eta14");
    TH1F *h_eta_mmOnTrackResidualTrack_eta14 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_eta14");
    TH1F *h_stereo_mmOnTrackResidualTrack_eta14 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_eta14");

    TH1F *h_mmOnTrackResidualTrackMS_eta1 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta1");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta1 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta1");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta1 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta1");
    TH1F *h_mmOnTrackResidualTrackMS_eta2 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta2");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta2 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta2");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta2 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta2");
    TH1F *h_mmOnTrackResidualTrackMS_eta3 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta3");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta3 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta3");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta3 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta3");
    TH1F *h_mmOnTrackResidualTrackMS_eta4 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta4");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta4 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta4");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta4 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta4");
    TH1F *h_mmOnTrackResidualTrackMS_eta5 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta5");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta5 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta5");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta5 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta5");
    TH1F *h_mmOnTrackResidualTrackMS_eta6 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta6");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta6 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta6");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta6 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta6");
    TH1F *h_mmOnTrackResidualTrackMS_eta7 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta7");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta7 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta7");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta7 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta7");
    TH1F *h_mmOnTrackResidualTrackMS_eta8 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta8");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta8 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta8");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta8 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta8");
    TH1F *h_mmOnTrackResidualTrackMS_eta9 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta9");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta9 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta9");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta9 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta9");
    TH1F *h_mmOnTrackResidualTrackMS_eta10 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta10");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta10 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta10");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta10 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta10");
    TH1F *h_mmOnTrackResidualTrackMS_eta11 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta11");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta11 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta11");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta11 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta11");
    TH1F *h_mmOnTrackResidualTrackMS_eta12 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta12");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta12 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta12");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta12 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta12");
    TH1F *h_mmOnTrackResidualTrackMS_eta13 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta13");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta13 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta13");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta13 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta13");
    TH1F *h_mmOnTrackResidualTrackMS_eta14 = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_eta14");
    TH1F *h_eta_mmOnTrackResidualTrackMS_eta14 = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_eta14");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_eta14 = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_eta14");

    ///theta

    TH1F *h_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB1_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB1_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB2_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB2_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB3_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB3_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB4_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB4_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB5_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB5_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB6_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB6_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB7_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB7_theta");
    TH1F *h_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrack_PCB8_theta");
    TH1F *h_eta_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrack_PCB8_theta");
    TH1F *h_stereo_mmOnTrackResidualTrack_PCB8_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrack_PCB8_theta");

    TH1F *h_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB1_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB1_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB2_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB2_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB3_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB3_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB4_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB4_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB5_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB5_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB6_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB6_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB7_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB7_theta");
    TH1F *h_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)real_file->Get("mmOnTrackResidualTrackMS_PCB8_theta");
    TH1F *h_eta_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)real_file->Get("eta_mmOnTrackResidualTrackMS_PCB8_theta");
    TH1F *h_stereo_mmOnTrackResidualTrackMS_PCB8_theta = (TH1F *)real_file->Get("stereo_mmOnTrackResidualTrackMS_PCB8_theta");

    //position

    TH1F *h_x12_eta01 = (TH1F *)real_file->Get("x12_eta01");
    TH1F *h_x12_eta02 = (TH1F *)real_file->Get("x12_eta02");
    TH1F *h_x12_eta03 = (TH1F *)real_file->Get("x12_eta03");
    TH1F *h_x12_eta04 = (TH1F *)real_file->Get("x12_eta04");
    TH1F *h_x12_eta05 = (TH1F *)real_file->Get("x12_eta05");
    TH1F *h_x12_eta06 = (TH1F *)real_file->Get("x12_eta06");
    TH1F *h_x12_eta07 = (TH1F *)real_file->Get("x12_eta07");
    TH1F *h_x12_eta08 = (TH1F *)real_file->Get("x12_eta08");
    TH1F *h_x12_eta09 = (TH1F *)real_file->Get("x12_eta09");
    TH1F *h_x12_eta10 = (TH1F *)real_file->Get("x12_eta10");
    TH1F *h_x12_eta11 = (TH1F *)real_file->Get("x12_eta11");
    TH1F *h_x12_eta12 = (TH1F *)real_file->Get("x12_eta12");
    TH1F *h_x12_eta13 = (TH1F *)real_file->Get("x12_eta13");
    TH1F *h_x12_eta14 = (TH1F *)real_file->Get("x12_eta14");

    TH1F *h_x12_qpcb01 = (TH1F *)real_file->Get("x12_qpcb01");
    TH1F *h_x12_qpcb02 = (TH1F *)real_file->Get("x12_qpcb02");
    TH1F *h_x12_qpcb03 = (TH1F *)real_file->Get("x12_qpcb03");
    TH1F *h_x12_qpcb04 = (TH1F *)real_file->Get("x12_qpcb04");
    TH1F *h_x12_qpcb05 = (TH1F *)real_file->Get("x12_qpcb05");
    TH1F *h_x12_qpcb06 = (TH1F *)real_file->Get("x12_qpcb06");
    TH1F *h_x12_qpcb07 = (TH1F *)real_file->Get("x12_qpcb07");
    TH1F *h_x12_qpcb08 = (TH1F *)real_file->Get("x12_qpcb08");

    TH1F *h_x12R = (TH1F *)real_file->Get("x12R");
    TH1F *h_x121R = (TH1F *)real_file->Get("x121R");
    TH1F *h_x341R = (TH1F *)real_file->Get("x341R");
    TH1F *h_x122R = (TH1F *)real_file->Get("x122R");
    TH1F *h_x342R = (TH1F *)real_file->Get("x342R");
    TH1F *h_x34R = (TH1F *)real_file->Get("x34R");

    /* TH1F *h_x12R_MS = (TH1F *)real_file->Get("x12R_MS");
    TH1F *h_x13R_MS = (TH1F *)real_file->Get("x13R_MS");
    TH1F *h_x14R_MS = (TH1F *)real_file->Get("x14R_MS");
    TH1F *h_x23R_MS = (TH1F *)real_file->Get("x23R_MS");
    TH1F *h_x24R_MS = (TH1F *)real_file->Get("x24R_MS");
    TH1F *h_x34R_MS = (TH1F *)real_file->Get("x34R_MS"); */

    ///////////////////////////////////////////////////////////// At this point we scale the histograms //////////////////////////////////////////////////////////////////////////////////

    
    h_mmOnTrackResidualTrack->Scale(1./h_mmOnTrackResidualTrack->Integral());
    h_mmOnTrackResidualTrackMS->Scale(1./h_mmOnTrackResidualTrackMS->Integral());
    h_mmOnTrackResidualTrack_pt20->Scale(1./h_mmOnTrackResidualTrack_pt20->Integral());
    h_mmOnTrackResidualTrackMS_pt20->Scale(1./h_mmOnTrackResidualTrackMS_pt20->Integral());
    h_mmOnTrackResidualTrack_ST1->Scale(1./h_mmOnTrackResidualTrack_ST1->Integral());
    h_mmOnTrackResidualTrack_ST2->Scale(1./h_mmOnTrackResidualTrack_ST2->Integral());
    h_mmOnTrackResidualTrackMS_ST1->Scale(1./h_mmOnTrackResidualTrackMS_ST1->Integral());
    h_mmOnTrackResidualTrackMS_ST2->Scale(1./h_mmOnTrackResidualTrackMS_ST2->Integral());
    h_eta_mmOnTrackResidualTrack_ST1->Scale(1./h_eta_mmOnTrackResidualTrack_ST1->Integral());
    h_eta_mmOnTrackResidualTrack_ST2->Scale(1./h_eta_mmOnTrackResidualTrack_ST2->Integral());
    h_eta_mmOnTrackResidualTrackMS_ST1->Scale(1./h_eta_mmOnTrackResidualTrackMS_ST1->Integral());
    h_eta_mmOnTrackResidualTrackMS_ST2->Scale(1./h_eta_mmOnTrackResidualTrackMS_ST2->Integral());

    h_mmOnTrack_gas_gap->Scale(1./h_mmOnTrack_gas_gap->Integral());

    //h_muons_pt->Scale(1./h_muons_pt->Integral());      
    h_local_position->Scale(1./h_local_position->Integral());
    h_global_position->Scale(1./h_global_position->Integral());
    h_global_t_position->Scale(1./h_global_t_position->Integral());
    //h_muons_eta->Scale(1./h_muons_eta->Integral());
    h_muons_eta_abs->Scale(1./h_muons_eta_abs->Integral());
    h_muons_theta->Scale(1./h_muons_theta->Integral());
    //h_muons_eta_ST1->Scale(1./h_muons_eta_ST1->Integral());
    //h_muons_eta_ST2 ->Scale(1./h_muons_eta_ST2->Integral());

    h_x12->Scale(1./h_x12->Integral());
    h_x121->Scale(1./h_x121->Integral());
    h_x341->Scale(1./h_x341->Integral());
    h_x122->Scale(1./h_x122->Integral());
    h_x342->Scale(1./h_x342->Integral());
    h_x34->Scale(1./h_x34->Integral());

    /* //c1
    Sigma1_MS_eta_CB->Scale(1./Sigma1_MS_eta_CB->Integral());
    Sigma1_MS_stereo_CB->Scale(1./Sigma1_MS_stereo_CB->Integral());
    Sigma1_MS_eta->Scale(1./Sigma1_MS_eta->Integral());
    Sigma1_MS_stereo->Scale(1./Sigma1_MS_stereo->Integral());
    //c101
    Sigma1_MS_CB->Scale(1./Sigma1_MS_CB->Integral());
    Sigma1_MS->Scale(1./Sigma1_MS->Integral());
    //c2
    Sigma1_eta_CB->Scale(1./Sigma1_eta_CB->Integral());
    Sigma1_stereo_CB->Scale(1./Sigma1_stereo_CB->Integral());
    Sigma1_eta->Scale(1./Sigma1_eta->Integral());
    Sigma1_stereo->Scale(1./Sigma1_stereo->Integral());
    //c201
    Sigma1_CB->Scale(1./Sigma1_CB->Integral());
    Sigma1->Scale(1./Sigma1->Integral());
    //c3
    Sigma1_MS_eta_theta_CB->Scale(1./Sigma1_MS_eta_theta_CB->Integral());
    Sigma1_MS_stereo_theta_CB->Scale(1./Sigma1_MS_stereo_theta_CB->Integral());
    Sigma1_MS_eta_theta->Scale(1./Sigma1_MS_eta_theta->Integral());
    Sigma1_MS_stereo_theta->Scale(1./Sigma1_MS_stereo_theta->Integral());
    //c301
    Sigma1_MS_theta_CB->Scale(1./Sigma1_MS_theta_CB->Integral());
    Sigma1_MS_theta->Scale(1./Sigma1_MS_theta->Integral());
    //c4
    Sigma1_eta_theta_CB->Scale(1./Sigma1_eta_theta_CB->Integral());
    Sigma1_stereo_theta_CB->Scale(1./Sigma1_stereo_theta_CB->Integral());
    Sigma1_eta_theta->Scale(1./Sigma1_eta_theta->Integral());
    Sigma1_stereo_theta->Scale(1./Sigma1_stereo_theta->Integral());
    //c401
    Sigma1_theta_CB->Scale(1./Sigma1_theta_CB->Integral());
    Sigma1_theta->Scale(1./Sigma1_theta->Integral());
    //c5
    Sigma1_MS_eta_eta_CB->Scale(1./Sigma1_MS_eta_eta_CB->Integral());
    Sigma1_MS_stereo_eta_CB->Scale(1./Sigma1_MS_stereo_eta_CB->Integral());
    Sigma1_MS_eta_eta->Scale(1./Sigma1_MS_eta_eta->Integral());
    Sigma1_MS_stereo_eta->Scale(1./Sigma1_MS_stereo_eta->Integral());
    //c501
    Sigma1_MS__eta_CB->Scale(1./Sigma1_MS__eta_CB->Integral());
    Sigma1_MS__eta->Scale(1./Sigma1_MS__eta->Integral());
    //c6
    Sigma1_eta_eta_CB->Scale(1./Sigma1_eta_eta_CB->Integral());
    Sigma1_stereo_eta_CB->Scale(1./Sigma1_stereo_eta_CB->Integral());
    Sigma1_eta_eta->Scale(1./Sigma1_eta_eta->Integral());
    Sigma1_stereo_eta->Scale(1./Sigma1_stereo_eta->Integral());
    //c601
    Sigma1__eta_CB->Scale(1./Sigma1__eta_CB->Integral());
    Sigma1__eta->Scale(1./Sigma1__eta->Integral());
    //c82
    Sigma1_posx12pcb_CB->Scale(1./Sigma1_posx12pcb_CB->Integral());
    Sigma1_posx12pcb->Scale(1./Sigma1_posx12pcb->Integral());
    //c802
    Sigma1_posx12eta_CB->Scale(1./Sigma1_posx12eta_CB->Integral());
    Sigma1_posx12eta->Scale(1./Sigma1_posx12eta->Integral());
    //c9
    Sigma1_pos_CB->Scale(1./Sigma1_pos_CB->Integral());
    Sigma1_pos->Scale(1./Sigma1_pos->Integral()); */
    
    
    h_mmOnTrackResidualTrack_PCB1->Scale(1./h_mmOnTrackResidualTrack_PCB1->Integral());
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
    h_x34R->Scale(1./h_x34R->Integral());

    // Create a ROOT file to store the histograms and plots
    TFile *output_file = new TFile("everything.root", "RECREATE");


    //Ploting and filling the output_file
    gStyle->SetOptStat(0);
    gStyle->SetOptFit(11);

    //kinematic and reconstructed ver


    /* plot_single(h_mmOnTrack_gas_gap_MC);
    plot_single(h_muons_eta_abs_MC);
    plot_single(h_muons_theta_MC); */
    /* plot_single(h_x12_MC);
    plot_single(h_x121_MC);
    plot_single(h_x341_MC);
    plot_single(h_x122_MC);
    plot_single(h_x342_MC);
    plot_single(h_x34_MC); */

    /* plot(h_mmOnTrackResidualTrack_MC,h_mmOnTrackResidualTrack);
    plot(h_mmOnTrackResidualTrackMS_MC,h_mmOnTrackResidualTrackMS);
    plot(h_mmOnTrackResidualTrack_pt20_MC,h_mmOnTrackResidualTrack_pt20);
    plot(h_mmOnTrackResidualTrackMS_pt20_MC,h_mmOnTrackResidualTrackMS_pt20);
    plot(h_mmOnTrackResidualTrack_ST1_MC,h_mmOnTrackResidualTrack_ST1);
    plot(h_mmOnTrackResidualTrack_ST2_MC,h_mmOnTrackResidualTrack_ST2);
    plot(h_mmOnTrackResidualTrackMS_ST1_MC,h_mmOnTrackResidualTrackMS_ST1);
    plot(h_mmOnTrackResidualTrackMS_ST2_MC,h_mmOnTrackResidualTrackMS_ST2);
    plot(h_eta_mmOnTrackResidualTrack_ST1_MC,h_eta_mmOnTrackResidualTrack_ST1);
    plot(h_eta_mmOnTrackResidualTrack_ST2_MC,h_eta_mmOnTrackResidualTrack_ST2);
    plot(h_eta_mmOnTrackResidualTrackMS_ST1_MC,h_eta_mmOnTrackResidualTrackMS_ST1);
    plot(h_eta_mmOnTrackResidualTrackMS_ST2_MC,h_eta_mmOnTrackResidualTrackMS_ST2);

    plot(h_mmOnTrack_gas_gap_MC,h_mmOnTrack_gas_gap);

    plot(h_muons_pt_MC,h_muons_pt);
    plot(h_local_position_MC,h_local_position);
    plot(h_global_position_MC,h_global_position);
    plot(h_global_t_position_MC,h_global_t_position);
    //plot(h_muons_eta_MC,h_muons_eta);
    plot(h_muons_eta_abs_MC,h_muons_eta_abs);
    plot(h_muons_theta_MC,h_muons_theta);
    //plot(h_muons_eta_ST1_MC,h_muons_eta_ST1);
    //plot(h_muons_eta_ST2_MC,h_muons_eta_ST2);

    plot(h_x12_MC,h_x12);
    plot(h_x121_MC,h_x121);
    plot(h_x341_MC,h_x341);
    plot(h_x122_MC,h_x122);
    plot(h_x342_MC,h_x342);
    plot(h_x34_MC,h_x34); */

    //sigma graphs
    TString eta = "eta";
    TString stereo = "stereo";
    TString all = "all";

    /* plot2_Gauss(Sigma1_MS_eta_eta_Gauss_MC,Sigma1_posx12eta_Gauss_MC,eta);
    plot2_Gauss(Sigma1_MS_eta_Gauss_MC,Sigma1_posx12pcb_Gauss_MC,eta);
    plot2_Gauss(Sigma1_MS_eta_eta_Gauss_MC,Sigma1_posx12eta_short_Gauss_MC,eta);
    plot2_Gauss(Sigma1_posx12eta_short_Gauss_MC,Sigma1_posx12eta_Gauss_MC,eta); */
    plot3_Gauss(Sigma1_MS_eta_eta_Gauss_MC,Sigma1_eta_eta_Gauss_MC,Sigma1_posx12eta_Gauss_MC,eta);
    plot3_Gauss(Sigma1_MS_eta_Gauss_MC,Sigma1_eta_Gauss_MC,Sigma1_posx12pcb_Gauss_MC,eta);
    plot3_Gauss(Sigma1_MS_eta_eta_Gauss_MC,Sigma1_eta_eta_Gauss_MC,Sigma1_posx12eta_short_Gauss_MC,eta);

    //Gauss only
    /* //c1
    plot2_CB(Sigma1_MS_eta_CB_MC,Sigma1_MS_eta_CB, eta);
    plot2_CB(Sigma1_MS_stereo_CB_MC,Sigma1_MS_stereo_CB, stereo);
    //c101
    plot2_CB(Sigma1_MS_CB_MC,Sigma1_MS_CB, all);
    //c2
    plot2_CB(Sigma1_eta_CB_MC,Sigma1_eta_CB, eta);
    plot2_CB(Sigma1_stereo_CB_MC,Sigma1_stereo_CB, stereo);
    //c201
    plot2_CB(Sigma1_CB_MC,Sigma1_CB, all); */
    //c3
    FitPol1_Gauss(Sigma1_MS_eta_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_MS_eta_theta_Gauss_MC,Sigma1_MS_eta_theta_Gauss_MC, eta);
    FitPol1_Gauss(Sigma1_MS_stereo_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_MS_stereo_theta_Gauss_MC,Sigma1_MS_stereo_theta_Gauss_MC, stereo);
    //c301
    FitPol1_Gauss(Sigma1_MS_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_MS_theta_Gauss_MC,Sigma1_MS_theta_Gauss_MC, all);
    //c4
    FitPol1_Gauss(Sigma1_eta_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_eta_theta_Gauss_MC,Sigma1_eta_theta_Gauss_MC, eta);
    FitPol1_Gauss(Sigma1_stereo_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_stereo_theta_Gauss_MC,Sigma1_stereo_theta_Gauss_MC, stereo);
    //c401
    FitPol1_Gauss(Sigma1_theta_Gauss_MC);// Line
    plot2_Gauss(Sigma1_theta_Gauss_MC,Sigma1_theta_Gauss_MC, all);
    //c5
    /* plot2_CB(Sigma1_MS_eta_eta_CB_MC,Sigma1_MS_eta_eta_CB, eta);
    plot2_CB(Sigma1_MS_stereo_eta_CB_MC,Sigma1_MS_stereo_eta_CB, stereo);
    //c501
    plot2_CB(Sigma1_MS__eta_CB_MC,Sigma1_MS__eta_CB, all);
    //c6
    plot2_CB(Sigma1_eta_eta_CB_MC,Sigma1_eta_eta_CB, eta);
    plot2_CB(Sigma1_stereo_eta_CB_MC,Sigma1_stereo_eta_CB, stereo);
    //c601
    plot2_CB(Sigma1__eta_CB_MC,Sigma1__eta_CB, all);
    //c71
    plot2_CB(Sigma1_eta_eta_CB_MC,Sigma1_eta_eta_CB, eta);
    plot2_CB(Sigma1_stereo_eta_CB_MC,Sigma1_stereo_eta_CB, stereo);
    //c701
    plot2_CB(Sigma1__eta_CB_MC,Sigma1__eta_CB, all);
    //c82
    plot2_CB(Sigma1_posx12pcb_CB_MC,Sigma1_posx12pcb_CB, all);
    //c802
    plot2_CB(Sigma1_posx12eta_CB_MC,Sigma1_posx12eta_CB, all);
    //c9
    plot2_CB(Sigma1_pos_CB_MC,Sigma1_pos_CB, all);
 */
    /* //c1
    //plot4(Sigma1_MS_eta_CB_MC,Sigma1_MS_stereo_CB_MC,Sigma1_MS_eta_CB,Sigma1_MS_stereo_CB);
    plot2_CB(Sigma1_MS_eta_CB_MC,Sigma1_MS_eta_CB, eta);
    plot2_CB(Sigma1_MS_stereo_CB_MC,Sigma1_MS_stereo_CB, stereo);
    //plot4(Sigma1_MS_eta_MC,Sigma1_MS_stereo_MC,Sigma1_MS_eta,Sigma1_MS_stereo);
    plot2(Sigma1_MS_eta_MC,Sigma1_MS_eta, eta);
    plot2(Sigma1_MS_stereo_MC,Sigma1_MS_stereo, stereo);
    //c101
    plot2_CB(Sigma1_MS_CB_MC,Sigma1_MS_CB, all);
    plot2(Sigma1_MS_MC,Sigma1_MS, all);
    //c2
    plot2_CB(Sigma1_eta_CB_MC,Sigma1_eta_CB, eta);
    plot2_CB(Sigma1_stereo_CB_MC,Sigma1_stereo_CB, stereo);
    plot2(Sigma1_eta_MC,Sigma1_eta, eta);
    plot2(Sigma1_stereo_MC,Sigma1_stereo, stereo);
    //c201
    plot2_CB(Sigma1_CB_MC,Sigma1_CB, all);
    plot2(Sigma1_MC,Sigma1, all);
    //c3
    FitPol1(Sigma1_MS_eta_theta_CB_MC,Sigma1_MS_eta_theta_CB);// Line
    plot2_CB(Sigma1_MS_eta_theta_CB_MC,Sigma1_MS_eta_theta_CB, eta);
    FitPol1(Sigma1_MS_stereo_theta_CB_MC,Sigma1_MS_stereo_theta_CB);// Line
    plot2_CB(Sigma1_MS_stereo_theta_CB_MC,Sigma1_MS_stereo_theta_CB, stereo);
    FitPol1(Sigma1_MS_eta_theta_MC,Sigma1_MS_eta_theta);// Line
    plot2(Sigma1_MS_eta_theta_MC,Sigma1_MS_eta_theta, eta);
    FitPol1(Sigma1_MS_stereo_theta_MC,Sigma1_MS_stereo_theta);// Line
    plot2(Sigma1_MS_stereo_theta_MC,Sigma1_MS_stereo_theta, stereo);
    //c301
    FitPol1(Sigma1_MS_theta_CB_MC,Sigma1_MS_theta_CB);// Line
    plot2_CB(Sigma1_MS_theta_CB_MC,Sigma1_MS_theta_CB, all);
    FitPol1(Sigma1_MS_theta_MC,Sigma1_MS_theta);// Line
    plot2(Sigma1_MS_theta_MC,Sigma1_MS_theta, all);
    //c4
    FitPol1(Sigma1_eta_theta_CB_MC,Sigma1_eta_theta_CB);// Line
    plot2_CB(Sigma1_eta_theta_CB_MC,Sigma1_eta_theta_CB, eta);
    FitPol1(Sigma1_stereo_theta_CB_MC,Sigma1_stereo_theta_CB);// Line
    plot2_CB(Sigma1_stereo_theta_CB_MC,Sigma1_stereo_theta_CB, stereo);
    FitPol1(Sigma1_eta_theta_MC,Sigma1_eta_theta);// Line
    plot2(Sigma1_eta_theta_MC,Sigma1_eta_theta, eta);
    FitPol1(Sigma1_stereo_theta_MC,Sigma1_stereo_theta);// Line
    plot2(Sigma1_stereo_theta_MC,Sigma1_stereo_theta, stereo);
    //c401
    FitPol1(Sigma1_theta_CB_MC,Sigma1_theta_CB);// Line
    plot2_CB(Sigma1_theta_CB_MC,Sigma1_theta_CB, all);
    FitPol1(Sigma1_theta_MC,Sigma1_theta);// Line
    plot2(Sigma1_theta_MC,Sigma1_theta, all);
    //c5
    plot2_CB(Sigma1_MS_eta_eta_CB_MC,Sigma1_MS_eta_eta_CB, eta);
    plot2_CB(Sigma1_MS_stereo_eta_CB_MC,Sigma1_MS_stereo_eta_CB, stereo);
    plot2(Sigma1_MS_eta_eta_MC,Sigma1_MS_eta_eta, eta);
    plot2(Sigma1_MS_stereo_eta_MC,Sigma1_MS_stereo_eta, stereo);
    //c501
    plot2_CB(Sigma1_MS__eta_CB_MC,Sigma1_MS__eta_CB, all);
    plot2(Sigma1_MS__eta_MC,Sigma1_MS__eta, all);
    //c6
    plot2_CB(Sigma1_eta_eta_CB_MC,Sigma1_eta_eta_CB, eta);
    plot2_CB(Sigma1_stereo_eta_CB_MC,Sigma1_stereo_eta_CB, stereo);
    plot2(Sigma1_eta_eta_MC,Sigma1_eta_eta, eta);
    plot2(Sigma1_stereo_eta_MC,Sigma1_stereo_eta, stereo);
    //c601
    plot2_CB(Sigma1__eta_CB_MC,Sigma1__eta_CB, all);
    plot2(Sigma1__eta_MC,Sigma1__eta, all);
    //c82
    plot2_CB(Sigma1_posx12pcb_CB_MC,Sigma1_posx12pcb_CB, all);
    plot2(Sigma1_posx12pcb_MC,Sigma1_posx12pcb, all);
    //c802
    plot2_CB(Sigma1_posx12eta_CB_MC,Sigma1_posx12eta_CB, all);
    plot2(Sigma1_posx12eta_CB_MC,Sigma1_posx12eta, all);
    //c9
    plot2_CB(Sigma1_pos_CB_MC,Sigma1_pos_CB, all);
    plot2(Sigma1_pos_MC,Sigma1_pos, all); */

    

    //pcb

    /* plot(h_mmOnTrackResidualTrack_PCB1_MC,h_mmOnTrackResidualTrack_PCB1);
    plot(h_eta_mmOnTrackResidualTrack_PCB1_MC,h_eta_mmOnTrackResidualTrack_PCB1);
    plot(h_stereo_mmOnTrackResidualTrack_PCB1_MC,h_stereo_mmOnTrackResidualTrack_PCB1);
    plot(h_mmOnTrackResidualTrack_PCB2_MC,h_mmOnTrackResidualTrack_PCB2);
    plot(h_eta_mmOnTrackResidualTrack_PCB2_MC,h_eta_mmOnTrackResidualTrack_PCB2);
    plot(h_stereo_mmOnTrackResidualTrack_PCB2_MC,h_stereo_mmOnTrackResidualTrack_PCB2);
    plot(h_mmOnTrackResidualTrack_PCB3_MC,h_mmOnTrackResidualTrack_PCB3);
    plot(h_eta_mmOnTrackResidualTrack_PCB3_MC,h_eta_mmOnTrackResidualTrack_PCB3);
    plot(h_stereo_mmOnTrackResidualTrack_PCB3_MC,h_stereo_mmOnTrackResidualTrack_PCB3);
    plot(h_mmOnTrackResidualTrack_PCB4_MC,h_mmOnTrackResidualTrack_PCB4);
    plot(h_eta_mmOnTrackResidualTrack_PCB4_MC,h_eta_mmOnTrackResidualTrack_PCB4);
    plot(h_stereo_mmOnTrackResidualTrack_PCB4_MC,h_stereo_mmOnTrackResidualTrack_PCB4);
    plot(h_mmOnTrackResidualTrack_PCB5_MC,h_mmOnTrackResidualTrack_PCB5);
    plot(h_eta_mmOnTrackResidualTrack_PCB5_MC,h_eta_mmOnTrackResidualTrack_PCB5);
    plot(h_stereo_mmOnTrackResidualTrack_PCB5_MC,h_stereo_mmOnTrackResidualTrack_PCB5);
    plot(h_mmOnTrackResidualTrack_PCB6_MC,h_mmOnTrackResidualTrack_PCB6);
    plot(h_eta_mmOnTrackResidualTrack_PCB6_MC,h_eta_mmOnTrackResidualTrack_PCB6);
    plot(h_stereo_mmOnTrackResidualTrack_PCB6_MC,h_stereo_mmOnTrackResidualTrack_PCB6);
    plot(h_mmOnTrackResidualTrack_PCB7_MC,h_mmOnTrackResidualTrack_PCB7);
    plot(h_eta_mmOnTrackResidualTrack_PCB7_MC,h_eta_mmOnTrackResidualTrack_PCB7);
    plot(h_stereo_mmOnTrackResidualTrack_PCB7_MC,h_stereo_mmOnTrackResidualTrack_PCB7);
    plot(h_mmOnTrackResidualTrack_PCB8_MC,h_mmOnTrackResidualTrack_PCB8);
    plot(h_eta_mmOnTrackResidualTrack_PCB8_MC,h_eta_mmOnTrackResidualTrack_PCB8);
    plot(h_stereo_mmOnTrackResidualTrack_PCB8_MC,h_stereo_mmOnTrackResidualTrack_PCB8);

    plot(h_mmOnTrackResidualTrackMS_PCB1_MC,h_mmOnTrackResidualTrackMS_PCB1);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB1_MC,h_eta_mmOnTrackResidualTrackMS_PCB1);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB1_MC,h_stereo_mmOnTrackResidualTrackMS_PCB1);
    plot(h_mmOnTrackResidualTrackMS_PCB2_MC,h_mmOnTrackResidualTrackMS_PCB2);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB2_MC,h_eta_mmOnTrackResidualTrackMS_PCB2);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB2_MC,h_stereo_mmOnTrackResidualTrackMS_PCB2);
    plot(h_mmOnTrackResidualTrackMS_PCB3_MC,h_mmOnTrackResidualTrackMS_PCB3);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB3_MC,h_eta_mmOnTrackResidualTrackMS_PCB3);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB3_MC,h_stereo_mmOnTrackResidualTrackMS_PCB3);
    plot(h_mmOnTrackResidualTrackMS_PCB4_MC,h_mmOnTrackResidualTrackMS_PCB4);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB4_MC,h_eta_mmOnTrackResidualTrackMS_PCB4);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB4_MC,h_stereo_mmOnTrackResidualTrackMS_PCB4);
    plot(h_mmOnTrackResidualTrackMS_PCB5_MC,h_mmOnTrackResidualTrackMS_PCB5);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB5_MC,h_eta_mmOnTrackResidualTrackMS_PCB5);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB5_MC,h_stereo_mmOnTrackResidualTrackMS_PCB5);
    plot(h_mmOnTrackResidualTrackMS_PCB6_MC,h_mmOnTrackResidualTrackMS_PCB6);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB6_MC,h_eta_mmOnTrackResidualTrackMS_PCB6);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB6_MC,h_stereo_mmOnTrackResidualTrackMS_PCB6);
    plot(h_mmOnTrackResidualTrackMS_PCB7_MC,h_mmOnTrackResidualTrackMS_PCB7);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB7_MC,h_eta_mmOnTrackResidualTrackMS_PCB7);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB7_MC,h_stereo_mmOnTrackResidualTrackMS_PCB7);
    plot(h_mmOnTrackResidualTrackMS_PCB8_MC,h_mmOnTrackResidualTrackMS_PCB8);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB8_MC,h_eta_mmOnTrackResidualTrackMS_PCB8);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB8_MC,h_stereo_mmOnTrackResidualTrackMS_PCB8);

    //eta

    plot(h_mmOnTrackResidualTrack_eta1_MC,h_mmOnTrackResidualTrack_eta1);
    plot(h_eta_mmOnTrackResidualTrack_eta1_MC,h_eta_mmOnTrackResidualTrack_eta1);
    plot(h_stereo_mmOnTrackResidualTrack_eta1_MC,h_stereo_mmOnTrackResidualTrack_eta1);
    plot(h_mmOnTrackResidualTrack_eta2_MC,h_mmOnTrackResidualTrack_eta2);
    plot(h_eta_mmOnTrackResidualTrack_eta2_MC,h_eta_mmOnTrackResidualTrack_eta2);
    plot(h_stereo_mmOnTrackResidualTrack_eta2_MC,h_stereo_mmOnTrackResidualTrack_eta2);
    plot(h_mmOnTrackResidualTrack_eta3_MC,h_mmOnTrackResidualTrack_eta3);
    plot(h_eta_mmOnTrackResidualTrack_eta3_MC,h_eta_mmOnTrackResidualTrack_eta3);
    plot(h_stereo_mmOnTrackResidualTrack_eta3_MC,h_stereo_mmOnTrackResidualTrack_eta3);
    plot(h_mmOnTrackResidualTrack_eta4_MC,h_mmOnTrackResidualTrack_eta4);
    plot(h_eta_mmOnTrackResidualTrack_eta4_MC,h_eta_mmOnTrackResidualTrack_eta4);
    plot(h_stereo_mmOnTrackResidualTrack_eta4_MC,h_stereo_mmOnTrackResidualTrack_eta4);
    plot(h_mmOnTrackResidualTrack_eta5_MC,h_mmOnTrackResidualTrack_eta5);
    plot(h_eta_mmOnTrackResidualTrack_eta5_MC,h_eta_mmOnTrackResidualTrack_eta5);
    plot(h_stereo_mmOnTrackResidualTrack_eta5_MC,h_stereo_mmOnTrackResidualTrack_eta5);
    plot(h_mmOnTrackResidualTrack_eta6_MC,h_mmOnTrackResidualTrack_eta6);
    plot(h_eta_mmOnTrackResidualTrack_eta6_MC,h_eta_mmOnTrackResidualTrack_eta6);
    plot(h_stereo_mmOnTrackResidualTrack_eta6_MC,h_stereo_mmOnTrackResidualTrack_eta6);
    plot(h_mmOnTrackResidualTrack_eta7_MC,h_mmOnTrackResidualTrack_eta7);
    plot(h_eta_mmOnTrackResidualTrack_eta7_MC,h_eta_mmOnTrackResidualTrack_eta7);
    plot(h_stereo_mmOnTrackResidualTrack_eta7_MC,h_stereo_mmOnTrackResidualTrack_eta7);
    plot(h_mmOnTrackResidualTrack_eta8_MC,h_mmOnTrackResidualTrack_eta8);
    plot(h_eta_mmOnTrackResidualTrack_eta8_MC,h_eta_mmOnTrackResidualTrack_eta8);
    plot(h_stereo_mmOnTrackResidualTrack_eta8_MC,h_stereo_mmOnTrackResidualTrack_eta8);
    plot(h_mmOnTrackResidualTrack_eta9_MC,h_mmOnTrackResidualTrack_eta9);
    plot(h_eta_mmOnTrackResidualTrack_eta9_MC,h_eta_mmOnTrackResidualTrack_eta9);
    plot(h_stereo_mmOnTrackResidualTrack_eta9_MC,h_stereo_mmOnTrackResidualTrack_eta9);
    plot(h_mmOnTrackResidualTrack_eta10_MC,h_mmOnTrackResidualTrack_eta10);
    plot(h_eta_mmOnTrackResidualTrack_eta10_MC,h_eta_mmOnTrackResidualTrack_eta10);
    plot(h_stereo_mmOnTrackResidualTrack_eta10_MC,h_stereo_mmOnTrackResidualTrack_eta10);
    plot(h_mmOnTrackResidualTrack_eta11_MC,h_mmOnTrackResidualTrack_eta11);
    plot(h_eta_mmOnTrackResidualTrack_eta11_MC,h_eta_mmOnTrackResidualTrack_eta11);
    plot(h_stereo_mmOnTrackResidualTrack_eta11_MC,h_stereo_mmOnTrackResidualTrack_eta11);
    plot(h_mmOnTrackResidualTrack_eta12_MC,h_mmOnTrackResidualTrack_eta12);
    plot(h_eta_mmOnTrackResidualTrack_eta12_MC,h_eta_mmOnTrackResidualTrack_eta12);
    plot(h_stereo_mmOnTrackResidualTrack_eta12_MC,h_stereo_mmOnTrackResidualTrack_eta12);
    plot(h_mmOnTrackResidualTrack_eta13_MC,h_mmOnTrackResidualTrack_eta13);
    plot(h_eta_mmOnTrackResidualTrack_eta13_MC,h_eta_mmOnTrackResidualTrack_eta13);
    plot(h_stereo_mmOnTrackResidualTrack_eta13_MC,h_stereo_mmOnTrackResidualTrack_eta13);
    plot(h_mmOnTrackResidualTrack_eta14_MC,h_mmOnTrackResidualTrack_eta14);
    plot(h_eta_mmOnTrackResidualTrack_eta14_MC,h_eta_mmOnTrackResidualTrack_eta14);
    plot(h_stereo_mmOnTrackResidualTrack_eta14_MC,h_stereo_mmOnTrackResidualTrack_eta14);

    plot(h_mmOnTrackResidualTrackMS_eta1_MC,h_mmOnTrackResidualTrackMS_eta1);
    plot(h_eta_mmOnTrackResidualTrackMS_eta1_MC,h_eta_mmOnTrackResidualTrackMS_eta1);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta1_MC,h_stereo_mmOnTrackResidualTrackMS_eta1);
    plot(h_mmOnTrackResidualTrackMS_eta2_MC,h_mmOnTrackResidualTrackMS_eta2);
    plot(h_eta_mmOnTrackResidualTrackMS_eta2_MC,h_eta_mmOnTrackResidualTrackMS_eta2);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta2_MC,h_stereo_mmOnTrackResidualTrackMS_eta2);
    plot(h_mmOnTrackResidualTrackMS_eta3_MC,h_mmOnTrackResidualTrackMS_eta3);
    plot(h_eta_mmOnTrackResidualTrackMS_eta3_MC,h_eta_mmOnTrackResidualTrackMS_eta3);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta3_MC,h_stereo_mmOnTrackResidualTrackMS_eta3);
    plot(h_mmOnTrackResidualTrackMS_eta4_MC,h_mmOnTrackResidualTrackMS_eta4);
    plot(h_eta_mmOnTrackResidualTrackMS_eta4_MC,h_eta_mmOnTrackResidualTrackMS_eta4);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta4_MC,h_stereo_mmOnTrackResidualTrackMS_eta4);
    plot(h_mmOnTrackResidualTrackMS_eta5_MC,h_mmOnTrackResidualTrackMS_eta5);
    plot(h_eta_mmOnTrackResidualTrackMS_eta5_MC,h_eta_mmOnTrackResidualTrackMS_eta5);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta5_MC,h_stereo_mmOnTrackResidualTrackMS_eta5);
    plot(h_mmOnTrackResidualTrackMS_eta6_MC,h_mmOnTrackResidualTrackMS_eta6);
    plot(h_eta_mmOnTrackResidualTrackMS_eta6_MC,h_eta_mmOnTrackResidualTrackMS_eta6);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta6_MC,h_stereo_mmOnTrackResidualTrackMS_eta6);
    plot(h_mmOnTrackResidualTrackMS_eta7_MC,h_mmOnTrackResidualTrackMS_eta7);
    plot(h_eta_mmOnTrackResidualTrackMS_eta7_MC,h_eta_mmOnTrackResidualTrackMS_eta7);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta7_MC,h_stereo_mmOnTrackResidualTrackMS_eta7);
    plot(h_mmOnTrackResidualTrackMS_eta8_MC,h_mmOnTrackResidualTrackMS_eta8);
    plot(h_eta_mmOnTrackResidualTrackMS_eta8_MC,h_eta_mmOnTrackResidualTrackMS_eta8);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta8_MC,h_stereo_mmOnTrackResidualTrackMS_eta8);
    plot(h_mmOnTrackResidualTrackMS_eta9_MC,h_mmOnTrackResidualTrackMS_eta9);
    plot(h_eta_mmOnTrackResidualTrackMS_eta9_MC,h_eta_mmOnTrackResidualTrackMS_eta9);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta9_MC,h_stereo_mmOnTrackResidualTrackMS_eta9);
    plot(h_mmOnTrackResidualTrackMS_eta10_MC,h_mmOnTrackResidualTrackMS_eta10);
    plot(h_eta_mmOnTrackResidualTrackMS_eta10_MC,h_eta_mmOnTrackResidualTrackMS_eta10);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta10_MC,h_stereo_mmOnTrackResidualTrackMS_eta10);
    plot(h_mmOnTrackResidualTrackMS_eta11_MC,h_mmOnTrackResidualTrackMS_eta11);
    plot(h_eta_mmOnTrackResidualTrackMS_eta11_MC,h_eta_mmOnTrackResidualTrackMS_eta11);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta11_MC,h_stereo_mmOnTrackResidualTrackMS_eta11);
    plot(h_mmOnTrackResidualTrackMS_eta12_MC,h_mmOnTrackResidualTrackMS_eta12);
    plot(h_eta_mmOnTrackResidualTrackMS_eta12_MC,h_eta_mmOnTrackResidualTrackMS_eta12);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta12_MC,h_stereo_mmOnTrackResidualTrackMS_eta12);
    plot(h_mmOnTrackResidualTrackMS_eta13_MC,h_mmOnTrackResidualTrackMS_eta13);
    plot(h_eta_mmOnTrackResidualTrackMS_eta13_MC,h_eta_mmOnTrackResidualTrackMS_eta13);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta13_MC,h_stereo_mmOnTrackResidualTrackMS_eta13);
    plot(h_mmOnTrackResidualTrackMS_eta14_MC,h_mmOnTrackResidualTrackMS_eta14);
    plot(h_eta_mmOnTrackResidualTrackMS_eta14_MC,h_eta_mmOnTrackResidualTrackMS_eta14);
    plot(h_stereo_mmOnTrackResidualTrackMS_eta14_MC,h_stereo_mmOnTrackResidualTrackMS_eta14);

    //theta

    plot(h_mmOnTrackResidualTrack_PCB1_theta_MC,h_mmOnTrackResidualTrack_PCB1_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB1_theta_MC,h_eta_mmOnTrackResidualTrack_PCB1_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB1_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB1_theta);
    plot(h_mmOnTrackResidualTrack_PCB2_theta_MC,h_mmOnTrackResidualTrack_PCB2_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB2_theta_MC,h_eta_mmOnTrackResidualTrack_PCB2_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB2_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB2_theta);
    plot(h_mmOnTrackResidualTrack_PCB3_theta_MC,h_mmOnTrackResidualTrack_PCB3_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB3_theta_MC,h_eta_mmOnTrackResidualTrack_PCB3_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB3_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB3_theta);
    plot(h_mmOnTrackResidualTrack_PCB4_theta_MC,h_mmOnTrackResidualTrack_PCB4_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB4_theta_MC,h_eta_mmOnTrackResidualTrack_PCB4_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB4_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB4_theta);
    plot(h_mmOnTrackResidualTrack_PCB5_theta_MC,h_mmOnTrackResidualTrack_PCB5_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB5_theta_MC,h_eta_mmOnTrackResidualTrack_PCB5_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB5_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB5_theta);
    plot(h_mmOnTrackResidualTrack_PCB6_theta_MC,h_mmOnTrackResidualTrack_PCB6_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB6_theta_MC,h_eta_mmOnTrackResidualTrack_PCB6_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB6_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB6_theta);
    plot(h_mmOnTrackResidualTrack_PCB7_theta_MC,h_mmOnTrackResidualTrack_PCB7_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB7_theta_MC,h_eta_mmOnTrackResidualTrack_PCB7_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB7_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB7_theta);
    plot(h_mmOnTrackResidualTrack_PCB8_theta_MC,h_mmOnTrackResidualTrack_PCB8_theta);
    plot(h_eta_mmOnTrackResidualTrack_PCB8_theta_MC,h_eta_mmOnTrackResidualTrack_PCB8_theta);
    plot(h_stereo_mmOnTrackResidualTrack_PCB8_theta_MC,h_stereo_mmOnTrackResidualTrack_PCB8_theta);

    plot(h_mmOnTrackResidualTrackMS_PCB1_theta_MC,h_mmOnTrackResidualTrackMS_PCB1_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB1_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB1_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB1_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB1_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB2_theta_MC,h_mmOnTrackResidualTrackMS_PCB2_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB2_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB2_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB2_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB2_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB3_theta_MC,h_mmOnTrackResidualTrackMS_PCB3_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB3_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB3_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB3_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB3_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB4_theta_MC,h_mmOnTrackResidualTrackMS_PCB4_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB4_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB4_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB4_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB4_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB5_theta_MC,h_mmOnTrackResidualTrackMS_PCB5_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB5_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB5_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB5_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB5_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB6_theta_MC,h_mmOnTrackResidualTrackMS_PCB6_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB6_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB6_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB6_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB6_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB7_theta_MC,h_mmOnTrackResidualTrackMS_PCB7_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB7_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB7_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB7_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB7_theta);
    plot(h_mmOnTrackResidualTrackMS_PCB8_theta_MC,h_mmOnTrackResidualTrackMS_PCB8_theta);
    plot(h_eta_mmOnTrackResidualTrackMS_PCB8_theta_MC,h_eta_mmOnTrackResidualTrackMS_PCB8_theta);
    plot(h_stereo_mmOnTrackResidualTrackMS_PCB8_theta_MC,h_stereo_mmOnTrackResidualTrackMS_PCB8_theta);

    //position

    plot(h_x12_eta01_MC,h_x12_eta01);
    plot(h_x12_eta02_MC,h_x12_eta02);
    plot(h_x12_eta03_MC,h_x12_eta03);
    plot(h_x12_eta04_MC,h_x12_eta04);
    plot(h_x12_eta05_MC,h_x12_eta05);
    plot(h_x12_eta06_MC,h_x12_eta06);
    plot(h_x12_eta07_MC,h_x12_eta07);
    plot(h_x12_eta08_MC,h_x12_eta08);
    plot(h_x12_eta09_MC,h_x12_eta09);
    plot(h_x12_eta10_MC,h_x12_eta10);
    plot(h_x12_eta11_MC,h_x12_eta11);
    plot(h_x12_eta12_MC,h_x12_eta12);
    plot(h_x12_eta13_MC,h_x12_eta13);
    plot(h_x12_eta14_MC,h_x12_eta14);

    plot(h_x12_qpcb01_MC,h_x12_qpcb01);
    plot(h_x12_qpcb02_MC,h_x12_qpcb02);
    plot(h_x12_qpcb03_MC,h_x12_qpcb03);
    plot(h_x12_qpcb04_MC,h_x12_qpcb04);
    plot(h_x12_qpcb05_MC,h_x12_qpcb05);
    plot(h_x12_qpcb06_MC,h_x12_qpcb06);
    plot(h_x12_qpcb07_MC,h_x12_qpcb07);
    plot(h_x12_qpcb08_MC,h_x12_qpcb08);

    plot(h_x12R_MC,h_x12R);
    plot(h_x121R_MC,h_x121R);
    plot(h_x341R_MC,h_x341R);
    plot(h_x122R_MC,h_x122R);
    plot(h_x342R_MC,h_x342R);
    plot(h_x34R_MC,h_x34R); */





    // Close the output ROOT file
    output_file->Close();
}

int main() {
    plotHistogramsAndData();
    return 0;
}

Double_t FitFunction(Double_t* x, Double_t* par){
   double_t rad = 57.2957795;
   return par[1] + par[0] * TMath::Power(TMath::Tan(x[0]/rad), 2);//TMath::Tan(x[0]) * TMath::Tan(x[0])
}

void plot_single(TH1F *mc_hist)
{
    // Create a canvas to plot the histograms and data points
    TCanvas* canvas = new TCanvas("canvas", "Histograms and Data Points", 800, 600);

    mc_hist->SetLineColor(kBlue);
    mc_hist->SetLineWidth(2);
        

    // Draw the histograms and data points on the same canvas
    canvas->cd();
    mc_hist->Draw();

    // Add a legend
    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(mc_hist, "MC Simulated Data", "l");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Write();
}

void plot(TH1F *mc_hist, TH1F *real_hist)
{
    // Create a canvas to plot the histograms and data points
    TCanvas* canvas = new TCanvas("canvas", "Histograms and Data Points", 800, 600);

    mc_hist->SetLineColor(kBlue);
    mc_hist->SetLineWidth(2);
        
    real_hist->SetMarkerStyle(kFullCircle);
    real_hist->SetMarkerColor(kRed);

    // Draw the histograms and data points on the same canvas
    canvas->cd();
    mc_hist->Draw();
    real_hist->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points

    // Add a legend
    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(mc_hist, "MC Simulated Data", "l");
    legend->AddEntry(real_hist, "Real Data", "lp");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Write();
}

// Definition of functions
void FitPol1_Gauss(TGraphErrors* graph1)
{
   TF1* pol1F = new TF1("pol1F", "[0]*x +[1]");
   TF1* pol2F = new TF1("pol2F", "[0]*x*x +[1]*x +[2]");
   TF1* res = new TF1("res", FitFunction ,0,30,2);

   pol1F->SetParameters(1.,.05);
   res->SetParameters(1.5,.09);

   double_t rad = 57.2957795;

   graph1->SetPointError(0,0.005*rad,0.05*(graph1->GetPointY(0)));
   graph1->SetPointError(1,0.005*rad,0.05*(graph1->GetPointY(1)));
   graph1->SetPointError(2,0.005*rad,0.05*(graph1->GetPointY(2)));
   graph1->SetPointError(3,0.005*rad,0.05*(graph1->GetPointY(3)));
   graph1->SetPointError(4,0.005*rad,0.05*(graph1->GetPointY(4)));
   graph1->SetPointError(5,0.005*rad,0.05*(graph1->GetPointY(5)));
   graph1->SetPointError(6,0.005*rad,0.05*(graph1->GetPointY(6)));
   graph1->SetPointError(7,0.005*rad,0.05*(graph1->GetPointY(7)));

   /* graph1->SetPointError(0,0.005*rad,0.01);
   graph1->SetPointError(1,0.005*rad,0.01);
   graph1->SetPointError(2,0.005*rad,0.01);
   graph1->SetPointError(3,0.005*rad,0.01);
   graph1->SetPointError(4,0.005*rad,0.01);
   graph1->SetPointError(5,0.005*rad,0.01);
   graph1->SetPointError(6,0.005*rad,0.01);
   graph1->SetPointError(7,0.005*rad,0.01); */

   //graph1->Fit(pol1F, "EM");
   //graph1->Fit(pol2F, "EM");
   graph1->Fit(res, "EM");

}
void FitPol1(TGraph* graph1,TGraph* graph2)
{
   TF1* pol1F = new TF1("pol1F", "[0]*x +[1]");

   pol1F->SetParameters(1.0,.3);

   graph1->Fit(pol1F, "EM");
   graph2->Fit(pol1F, "+EM");
}
void plot4(TGraphErrors *mc_graph_eta, TGraphErrors *mc_graph_stereo, TGraphErrors *real_graph_eta, TGraphErrors *real_graph_stereo)
{
    // Create a canvas to plot the mc and data points
    TCanvas* canvas = new TCanvas("canvas", "Sigma Eta and Stereo Strips", 800, 600);

    /* mc_graph_eta->SetMarkerStyle(20);
    mc_graph_eta->SetMarkerColor(kRed);
    mc_graph_eta->SetMarkerSize(1.5);

    mc_graph_stereo->SetMarkerStyle(20);
    mc_graph_stereo->SetMarkerColor(kBlue);
    mc_graph_stereo->SetMarkerSize(1.5);

    real_graph_eta->SetMarkerStyle(21);
    real_graph_eta->SetMarkerColor(kViolet);
    real_graph_eta->SetMarkerSize(1.5);

    real_graph_stereo->SetMarkerStyle(21);
    real_graph_stereo->SetMarkerColor(kGreen);
    real_graph_stereo->SetMarkerSize(1.5); */

    // Draw the graphs on the same canvas
    canvas->cd();
    mc_graph_eta->Draw("AP");
    mc_graph_stereo->Draw("SAME P");
    real_graph_eta->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points
    real_graph_stereo->Draw("SAME P");

    // Add a legend
    TLegend* legend = new TLegend(0.6, 0.7, 0.9, 0.9);
    legend->AddEntry(mc_graph_eta, "MC Simulated Data Eta Strip", "p");
    legend->AddEntry(mc_graph_stereo, "MC Simulated Data Stereo Strip", "p");
    legend->AddEntry(real_graph_eta, "Real Data Eta Strip", "p");
    legend->AddEntry(real_graph_stereo, "Real Data Stereo Strip", "p");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Write();
}
void plot2_CB(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype)
{
    // Create a canvas to plot the mc and data points
    TCanvas* canvas = new TCanvas("canvas", "Sigma from Crystal Ball", 800, 600);

    mc_graph->SetMarkerStyle(kFullCircle);
    mc_graph->SetMarkerColor(kBlue);
    mc_graph->GetYaxis()->SetRangeUser(-2,2);
    TString name = mc_graph->GetTitle();
    mc_graph->SetTitle(name+"_"+striptype+"_strip");
    TString title = mc_graph->GetTitle();
        
    real_graph->SetMarkerStyle(kFullSquare);
    real_graph->SetMarkerColor(kRed);

    // Draw the graphs on the same canvas
    canvas->cd();
    mc_graph->Draw("AP");
    real_graph->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points

    // Add a legend
    TLegend* legend = new TLegend(0.1,0.1,0.3,0.3);
    legend->AddEntry(mc_graph, "MC Simulated Data", "p");
    legend->AddEntry(real_graph, "Real Data", "p");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Print("Combined/"+title+"_CB.pdf");
    canvas->Write();
}
void plot2(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype)
{
    // Create a canvas to plot the mc and data points
    TCanvas* canvas = new TCanvas("canvas", "Sigma from Double Gauss", 800, 600);

    mc_graph->SetMarkerStyle(kFullCircle);
    mc_graph->SetMarkerColor(kBlue);
    mc_graph->GetYaxis()->SetRangeUser(-2,2);
    TString name = mc_graph->GetTitle();
    mc_graph->SetTitle(name+"_"+striptype+"_strip");
    TString title = mc_graph->GetTitle();
        
    real_graph->SetMarkerStyle(kFullSquare);
    real_graph->SetMarkerColor(kRed);

    // Draw the graphs on the same canvas
    canvas->cd();
    mc_graph->Draw("AP");
    real_graph->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points

    // Add a legend
    TLegend* legend = new TLegend(0.1,0.1,0.3,0.3);
    legend->AddEntry(mc_graph, "MC Simulated Data", "p");
    legend->AddEntry(real_graph, "Real Data", "p");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Print("Combined/"+title+".pdf");
    canvas->Write();
}
void plot2_Gauss(TGraphErrors *mc_graph, TGraphErrors *real_graph, TString striptype)
{
    // Create a canvas to plot the mc and data points
    TCanvas* canvas = new TCanvas("canvas", "Resolution", 800, 600);

    mc_graph->SetMarkerStyle(kFullCircle);
    mc_graph->SetMarkerColor(kBlue);
    mc_graph->GetYaxis()->SetRangeUser(0,.6);
    TString name = mc_graph->GetTitle();
    mc_graph->SetTitle(name+"_"+striptype+"_strip");
    TString title = mc_graph->GetTitle();
        
    /* real_graph->SetMarkerStyle(kFullSquare);
    real_graph->SetMarkerColor(kRed); */

    // Draw the graphs on the same canvas
    canvas->cd();
    mc_graph->Draw("AP");
    real_graph->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points

    // Add a legend
    TLegend* legend = new TLegend(0.7,0.1,0.9,0.3);//TLegend(0.1,0.1,0.3,0.3)(0.7,0.1,0.9,0.3);
    legend->AddEntry(mc_graph, "Residual", "p");
    //legend->AddEntry(real_graph, "Layer vs Layer", "p");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Print("Combined/"+title+".pdf");
    canvas->Write();
}
void plot3_Gauss(TGraphErrors *mc_graph, TGraphErrors *graph , TGraphErrors *real_graph, TString striptype)
{
    // Create a canvas to plot the mc and data points
    TCanvas* canvas = new TCanvas("canvas", "Resolution", 800, 600);

    mc_graph->SetMarkerStyle(kFullCircle);
    mc_graph->SetMarkerColor(kBlue);
    mc_graph->GetYaxis()->SetRangeUser(0,.6);
    TString name1 = mc_graph->GetTitle();
    TString name2 = graph->GetTitle();
    TString name3 = real_graph->GetTitle();
    mc_graph->SetTitle(name1+'+'+name2+'+'+name3+"_"+striptype+"_strip");
    TString title = mc_graph->GetTitle();

    graph->SetMarkerStyle(kFullCircle);
    graph->SetMarkerColor(kYellow);

    real_graph->SetMarkerStyle(kFullSquare);
    real_graph->SetMarkerColor(kRed);

    // Draw the graphs on the same canvas
    canvas->cd();
    mc_graph->Draw("AP");
    graph->Draw("SAME P");
    real_graph->Draw("SAME P");  // "SAME" to overlay, "P" to draw as data points

    // Add a legend
    TLegend* legend = new TLegend(0.1,0.1,0.3,0.3);//TLegend(0.1,0.1,0.3,0.3)(0.7,0.1,0.9,0.3);
    legend->AddEntry(mc_graph, "Residual MS", "p");
    legend->AddEntry(graph, "Residual", "p");
    legend->AddEntry(real_graph, "Layer vs Layer", "p");
    legend->Draw();

    // Save the canvas to the output ROOT file
    canvas->Print("Combined/"+title+".pdf");
    canvas->Write();
}