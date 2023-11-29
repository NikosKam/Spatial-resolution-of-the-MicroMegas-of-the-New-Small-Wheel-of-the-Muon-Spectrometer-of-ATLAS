//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Oct 31 15:24:03 2022 by ROOT version 6.24/06
// from TTree BasicTesterTree/MuonTesterTree
// found on file: C:/root_v6.24.06/macros/MuonTester/data22_13p6TeV.00436422.physics_Main.merge.NTUP_MUTEST.f1291_m2138_c1404_m2100._0001.root
//////////////////////////////////////////////////////////

#ifndef AnalizeMuonTester_h
#define AnalizeMuonTester_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "vector"

class AnalizeMuonTester {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   vector<float>   *IDTracks_pt; //Tracks reconstructed in Inner Detector
   vector<float>   *IDTracks_eta;
   vector<float>   *IDTracks_phi;
   vector<float>   *IDTracks_e;
   vector<int>     *IDTracks_q;
   vector<float>   *IDTracks_chi2;
   vector<float>   *IDTracks_cov_d0;
   vector<float>   *IDTracks_cov_phi;
   vector<float>   *IDTracks_cov_phi_d0;
   vector<float>   *IDTracks_cov_phi_z0;
   vector<float>   *IDTracks_cov_qOverP;
   vector<float>   *IDTracks_cov_qOverP_d0;
   vector<float>   *IDTracks_cov_qOverP_phi;
   vector<float>   *IDTracks_cov_qOverP_theta;
   vector<float>   *IDTracks_cov_qOverP_z0;
   vector<float>   *IDTracks_cov_theta;
   vector<float>   *IDTracks_cov_theta_d0;
   vector<float>   *IDTracks_cov_theta_phi;
   vector<float>   *IDTracks_cov_theta_z0;
   vector<float>   *IDTracks_cov_z0;
   vector<float>   *IDTracks_cov_z0_d0;
   vector<float>   *IDTracks_d0;
   vector<float>   *IDTracks_z0;
   vector<float>   *IDTracks_d0Sig;
   vector<float>   *IDTracks_eta_err;
   vector<float>   *IDTracks_pt_err;
   vector<unsigned int> *IDTracks_nDoF;
   vector<float>   *METracks_pt; //Tracks reconstructed in Muon Spectrometer and extrapolated at the interaction point
   vector<float>   *METracks_eta;
   vector<float>   *METracks_phi;
   vector<float>   *METracks_e;
   vector<int>     *METracks_q;
   vector<float>   *METracks_chi2;
   vector<float>   *METracks_cov_d0;
   vector<float>   *METracks_cov_phi;
   vector<float>   *METracks_cov_phi_d0;
   vector<float>   *METracks_cov_phi_z0;
   vector<float>   *METracks_cov_qOverP;
   vector<float>   *METracks_cov_qOverP_d0;
   vector<float>   *METracks_cov_qOverP_phi;
   vector<float>   *METracks_cov_qOverP_theta;
   vector<float>   *METracks_cov_qOverP_z0;
   vector<float>   *METracks_cov_theta;
   vector<float>   *METracks_cov_theta_d0;
   vector<float>   *METracks_cov_theta_phi;
   vector<float>   *METracks_cov_theta_z0;
   vector<float>   *METracks_cov_z0;
   vector<float>   *METracks_cov_z0_d0;
   vector<float>   *METracks_d0;
   vector<float>   *METracks_z0;
   vector<float>   *METracks_d0Sig;
   vector<float>   *METracks_eta_err;
   vector<float>   *METracks_pt_err;
   vector<unsigned int> *METracks_nDoF;
   vector<signed char> *MM_NumRioOnTrkCB; //Micro Megas
   vector<signed char> *MM_NumRioOnTrkME;
   vector<signed char> *MM_NumRioOnTrkMS;
   vector<signed char> *MM_NumRioOnTrkMSOE;
   vector<signed char> *MM_NumRioOnTrkPR;
   vector<int>     *MM_SimDataDeposit;
   vector<int>     *MM_SimDataGenParPdgId;
   vector<float>   *MM_SimDataGenParPt;
   vector<float>   *MM_SimDataGenParVertexPos_x;
   vector<float>   *MM_SimDataGenParVertexPos_y;
   vector<float>   *MM_SimDataGenParVertexPos_z;
   vector<float>   *MM_SimDataGloabalPos_x;
   vector<float>   *MM_SimDataGloabalPos_y;
   vector<float>   *MM_SimDataGloabalPos_z;
   vector<float>   *MM_SimDataLocalPos_x;
   vector<float>   *MM_SimDataLocalPos_y;
   vector<unsigned short> *MM_SimData_channel;
   vector<unsigned char> *MM_SimData_gas_gap;
   vector<unsigned char> *MM_SimData_multiplet;
   vector<signed char> *MM_SimData_stationEta;
   vector<unsigned char> *MM_SimData_stationIndex;
   vector<unsigned char> *MM_SimData_stationPhi;
   Int_t           MM_nDeltaElectrons;
   Int_t           MM_nMuonSimData;
   vector<float>   *MSOETracks_pt; 
   vector<float>   *MSOETracks_eta;
   vector<float>   *MSOETracks_phi;
   vector<float>   *MSOETracks_e;
   vector<int>     *MSOETracks_q;
   vector<float>   *MSOETracks_chi2;
   vector<float>   *MSOETracks_cov_d0;
   vector<float>   *MSOETracks_cov_phi;
   vector<float>   *MSOETracks_cov_phi_d0;
   vector<float>   *MSOETracks_cov_phi_z0;
   vector<float>   *MSOETracks_cov_qOverP;
   vector<float>   *MSOETracks_cov_qOverP_d0;
   vector<float>   *MSOETracks_cov_qOverP_phi;
   vector<float>   *MSOETracks_cov_qOverP_theta;
   vector<float>   *MSOETracks_cov_qOverP_z0;
   vector<float>   *MSOETracks_cov_theta;
   vector<float>   *MSOETracks_cov_theta_d0;
   vector<float>   *MSOETracks_cov_theta_phi;
   vector<float>   *MSOETracks_cov_theta_z0;
   vector<float>   *MSOETracks_cov_z0;
   vector<float>   *MSOETracks_cov_z0_d0;
   vector<float>   *MSOETracks_d0;
   vector<float>   *MSOETracks_z0;
   vector<float>   *MSOETracks_d0Sig;
   vector<float>   *MSOETracks_eta_err;
   vector<float>   *MSOETracks_pt_err;
   vector<unsigned int> *MSOETracks_nDoF;
   vector<float>   *MSTracks_pt; //Tracks reconstructed in Muon Spectrometer
   vector<float>   *MSTracks_eta;
   vector<float>   *MSTracks_phi;
   vector<float>   *MSTracks_e;
   vector<int>     *MSTracks_q;
   vector<float>   *MSTracks_chi2;
   vector<float>   *MSTracks_cov_d0;
   vector<float>   *MSTracks_cov_phi;
   vector<float>   *MSTracks_cov_phi_d0;
   vector<float>   *MSTracks_cov_phi_z0;
   vector<float>   *MSTracks_cov_qOverP;
   vector<float>   *MSTracks_cov_qOverP_d0;
   vector<float>   *MSTracks_cov_qOverP_phi;
   vector<float>   *MSTracks_cov_qOverP_theta;
   vector<float>   *MSTracks_cov_qOverP_z0;
   vector<float>   *MSTracks_cov_theta;
   vector<float>   *MSTracks_cov_theta_d0;
   vector<float>   *MSTracks_cov_theta_phi;
   vector<float>   *MSTracks_cov_theta_z0;
   vector<float>   *MSTracks_cov_z0;
   vector<float>   *MSTracks_cov_z0_d0;
   vector<float>   *MSTracks_d0;
   vector<float>   *MSTracks_z0;
   vector<float>   *MSTracks_d0Sig;
   vector<float>   *MSTracks_eta_err;
   vector<float>   *MSTracks_pt_err;
   vector<unsigned int> *MSTracks_nDoF;
   vector<unsigned char> *MdtChamHitId_multiLayer;
   vector<signed char> *MdtChamHitId_stationEta;
   vector<unsigned char> *MdtChamHitId_stationIndex;
   vector<unsigned char> *MdtChamHitId_stationPhi;
   vector<unsigned char> *MdtChamHitId_tube;
   vector<unsigned char> *MdtChamHitId_tubeLayer;
   vector<int>     *MdtChamHit_Adc;
   vector<unsigned short> *MdtChamHit_ChamberLink;
   vector<int>     *MdtChamHit_Tdc;
   vector<float>   *MdtChamHit_driftR;
   vector<float>   *MdtChamHit_driftUncert;
   vector<unsigned char> *MdtChamId_multiLayer;
   vector<signed char> *MdtChamId_stationEta;
   vector<unsigned char> *MdtChamId_stationIndex;
   vector<unsigned char> *MdtChamId_stationPhi;
   vector<unsigned char> *MdtChamId_tube;
   vector<unsigned char> *MdtChamId_tubeLayer;
   vector<int>     *MdtCham_NTubesPerML;
   vector<int>     *MdtCham_hitN;
   vector<bool>    *MdtCham_matchedCaloTag;
   vector<bool>    *MdtCham_matchedCaloTag_IPcut;
   vector<bool>    *MdtCham_matchedMuon;
   vector<bool>    *MdtCham_matchedMuon_IPcut;
   vector<signed char> *RPC_NumRioOnTrkCB;
   vector<signed char> *RPC_NumRioOnTrkME;
   vector<signed char> *RPC_NumRioOnTrkMS;
   vector<signed char> *RPC_NumRioOnTrkMSOE;
   vector<signed char> *RPC_NumRioOnTrkPR;
   Int_t           avgIntPerCrossing;
   UInt_t          cham_N;
   ULong64_t       evtNumber;
   vector<unsigned char> *extCaloToCham_Identifier_IPCut_multiLayer;
   vector<signed char> *extCaloToCham_Identifier_IPCut_stationEta;
   vector<unsigned char> *extCaloToCham_Identifier_IPCut_stationIndex;
   vector<unsigned char> *extCaloToCham_Identifier_IPCut_stationPhi;
   vector<unsigned char> *extCaloToCham_Identifier_IPCut_tube;
   vector<unsigned char> *extCaloToCham_Identifier_IPCut_tubeLayer;
   vector<unsigned char> *extCaloToCham_Identifier_multiLayer;
   vector<signed char> *extCaloToCham_Identifier_stationEta;
   vector<unsigned char> *extCaloToCham_Identifier_stationIndex;
   vector<unsigned char> *extCaloToCham_Identifier_stationPhi;
   vector<unsigned char> *extCaloToCham_Identifier_tube;
   vector<unsigned char> *extCaloToCham_Identifier_tubeLayer;
   UInt_t          extCaloToCham_N;
   UInt_t          extCaloToCham_N_IPCut;
   UInt_t          lbNumber;
   Float_t         lumi;
   vector<float>   *mmClusterOnTrackGlobalPos_x;
   vector<float>   *mmClusterOnTrackGlobalPos_y;
   vector<float>   *mmClusterOnTrackGlobalPos_z;
   vector<float>   *mmClusterOnTrackLocalPos_x;
   vector<float>   *mmClusterOnTrackLocalPos_y;
   vector<float>   *mmError;
   vector<vector<float> > *mmLocalStripPosX;
   vector<float>   *mmOnTrackError;
   vector<float>   *mmOnTrackGlobalPos_x;
   vector<float>   *mmOnTrackGlobalPos_y;
   vector<float>   *mmOnTrackGlobalPos_z;
   vector<float>   *mmOnTrackLocalPos_x;
   vector<float>   *mmOnTrackLocalPos_y;
   vector<int>     *mmOnTrackNStrips;
   vector<float>   *mmOnTrackPullTrack;
   vector<float>   *mmOnTrackPullTrackMS;
   vector<float>   *mmOnTrackResidualTrack;
   vector<float>   *mmOnTrackResidualTrackMS;
   vector<float>   *mmOnTrackResidualTruth;
   vector<vector<int> > *mmOnTrackStripCharges;
   vector<vector<short> > *mmOnTrackStripDriftTimes;
   vector<vector<unsigned short> > *mmOnTrackStripNumbers;
   vector<unsigned short> *mmOnTrack_MuonLink;
   vector<unsigned short> *mmOnTrack_channel;
   vector<unsigned char> *mmOnTrack_gas_gap;
   vector<unsigned char> *mmOnTrack_multiplet;
   vector<signed char> *mmOnTrack_stationEta;
   vector<unsigned char> *mmOnTrack_stationIndex;
   vector<unsigned char> *mmOnTrack_stationPhi;
   vector<float>   *mmOnTrackuTpcAngle;
   vector<float>   *mmOnTrackuTpcChisqProb;
   vector<float>   *mmPos_x;
   vector<float>   *mmPos_y;
   vector<float>   *mmPos_z;
   vector<float>   *mmResidualTruth;
   vector<vector<int> > *mmStripCharges;
   vector<vector<short> > *mmStripDriftTimes;
   vector<vector<unsigned short> > *mmStripNumbers;
   vector<float>   *mmTpcAngle;
   vector<float>   *mmTrackStateGlobalPos_x;  //Cluster position x in ATLAS framework
   vector<float>   *mmTrackStateGlobalPos_y;  //Cluster position y in ATLAS framework
   vector<float>   *mmTrackStateGlobalPos_z;  //Cluster position z in ATLAS framework
   vector<float>   *mmTrackStateLocalPos_x;  //Cluster position x in local mm framework
   vector<float>   *mmTrackStateLocalPos_y;  //Cluster position y in local mm framework
   vector<unsigned short> *mmTrackState_ClusterOnTrackLink;
   vector<unsigned short> *mmTrackState_MuonLink;
   vector<unsigned short> *mmTrackState_channel;
   vector<unsigned short> *mmTrackState_closestClusterLink;
   vector<float>   *mmTrackState_closestClusterResidual;
   vector<unsigned char> *mmTrackState_gas_gap;
   vector<unsigned char> *mmTrackState_multiplet;
   vector<signed char> *mmTrackState_stationEta;
   vector<unsigned char> *mmTrackState_stationIndex;
   vector<unsigned char> *mmTrackState_stationPhi;
   vector<unsigned short> *mm_channel;
   vector<unsigned char> *mm_gas_gap;
   vector<unsigned char> *mm_multiplet;
   vector<vector<float> > *mm_segment_cluster_gas_gap;
   vector<vector<float> > *mm_segment_cluster_globpos_x;
   vector<vector<float> > *mm_segment_cluster_globpos_y;
   vector<vector<float> > *mm_segment_cluster_globpos_z;
   vector<vector<float> > *mm_segment_cluster_multilayer;
   vector<float>   *mm_segment_clusterprd_residuals_x;
   vector<float>   *mm_segment_clusterprd_residuals_y;
   vector<vector<float> > *mm_segment_locx_err;
   vector<vector<float> > *mm_segment_truth_locx_residuals;
   vector<signed char> *mm_stationEta;
   vector<unsigned char> *mm_stationIndex;
   vector<unsigned char> *mm_stationPhi;
   vector<float>   *mmmuTpcChi2;
   vector<unsigned short> *muon_segmentLink; 
   vector<short>   *muon_segment_ChamberIdx;
   vector<short>   *muon_segment_ChamberTech;
   vector<short>   *muon_segment_EtaStation;
   vector<float>   *muon_segment_Mom_x;
   vector<float>   *muon_segment_Mom_y;
   vector<float>   *muon_segment_Mom_z;
   vector<float>   *muon_segment_Pos_x;
   vector<float>   *muon_segment_Pos_y;
   vector<float>   *muon_segment_Pos_z;
   vector<short>   *muon_segment_Sector;
   vector<float>   *muon_segment_chi2;
   vector<unsigned int> *muon_segment_nDoF;
   vector<unsigned char> *muon_segment_nMM_EtaHits;
   vector<unsigned char> *muon_segment_nMM_StereoHits;
   vector<unsigned int> *muon_segment_nPrecisionHits;
   vector<unsigned char> *muon_segment_nSTGC_EtaHits;
   vector<unsigned char> *muon_segment_nSTGC_PhiHits;
   vector<unsigned int> *muon_segment_nTrigEtaLayers;
   vector<unsigned int> *muon_segment_nTrigPhiLayers;
   vector<float>   *muons_pt;
   vector<float>   *muons_eta;
   vector<float>   *muons_phi;
   vector<float>   *muons_e;
   vector<int>     *muons_q;
   vector<float>   *muons_EnergyLoss;
   vector<float>   *muons_EnergyLossSigma;
   vector<float>   *muons_FSR_CandidateEnergy;
   vector<unsigned short> *muons_IDLink;
   vector<unsigned short> *muons_MELink;
   vector<unsigned short> *muons_MSLink;
   vector<unsigned short> *muons_MSOELink;
   vector<float>   *muons_MeasEnergyLoss;
   vector<float>   *muons_MeasEnergyLossSigma;
   vector<float>   *muons_ParamEnergyLoss;
   vector<float>   *muons_ParamEnergyLossSigmaMinus;
   vector<float>   *muons_ParamEnergyLossSigmaPlus;
   vector<float>   *muons_PtImbalSig;
   vector<float>   *muons_SCS;
   vector<float>   *muons_SNS;
   vector<unsigned short> *muons_allAuthors;
   vector<unsigned short> *muons_author;
   vector<float>   *muons_chi2;
   vector<unsigned char> *muons_combinedTrackOutBoundsPrecisionHits;
   vector<float>   *muons_cov_d0;
   vector<float>   *muons_cov_phi;
   vector<float>   *muons_cov_phi_d0;
   vector<float>   *muons_cov_phi_z0;
   vector<float>   *muons_cov_qOverP;
   vector<float>   *muons_cov_qOverP_d0;
   vector<float>   *muons_cov_qOverP_phi;
   vector<float>   *muons_cov_qOverP_theta;
   vector<float>   *muons_cov_qOverP_z0;
   vector<float>   *muons_cov_theta;
   vector<float>   *muons_cov_theta_d0;
   vector<float>   *muons_cov_theta_phi;
   vector<float>   *muons_cov_theta_z0;
   vector<float>   *muons_cov_z0;
   vector<float>   *muons_cov_z0_d0;
   vector<unsigned char> *muons_cscUnspoiledEtaHits;
   vector<float>   *muons_d0;
   vector<unsigned char> *muons_extendedClosePrecisionHits;
   vector<unsigned char> *muons_extendedLargeHits;
   vector<unsigned char> *muons_extendedLargeHoles;
   vector<unsigned char> *muons_extendedOutBoundsPrecisionHits;
   vector<unsigned char> *muons_extendedSmallHits;
   vector<unsigned char> *muons_extendedSmallHoles;
   vector<float>   *muons_innAngle;
   vector<unsigned char> *muons_innerClosePrecisionHits;
   vector<unsigned char> *muons_innerLargeHits;
   vector<unsigned char> *muons_innerLargeHoles;
   vector<unsigned char> *muons_innerOutBoundsPrecisionHits;
   vector<unsigned char> *muons_innerSmallHits;
   vector<unsigned char> *muons_innerSmallHoles;
   vector<bool>    *muons_isBad;
   vector<bool>    *muons_isCaloTag;
   vector<unsigned char> *muons_isEndcapGoodLayers;
   vector<unsigned char> *muons_isSmallGoodSectors;
   vector<float>   *muons_midAngle;
   vector<unsigned char> *muons_middleClosePrecisionHits;
   vector<unsigned char> *muons_middleLargeHits;
   vector<unsigned char> *muons_middleLargeHoles;
   vector<unsigned char> *muons_middleOutBoundsPrecisionHits;
   vector<unsigned char> *muons_middleSmallHits;
   vector<unsigned char> *muons_middleSmallHoles;
   vector<float>   *muons_msInnerMatchChi2;
   vector<int>     *muons_msInnerMatchDOF;
   vector<float>   *muons_msOuterMatchChi2;
   vector<int>     *muons_msOuterMatchDOF;
   vector<unsigned char> *muons_numberOfGoodPrecisionLayers;
   vector<unsigned char> *muons_numberOfOutliersOnTrack;
   vector<unsigned char> *muons_numberOfPhiHoleLayers;
   vector<unsigned char> *muons_numberOfPhiLayers;
   vector<unsigned char> *muons_numberOfPrecisionHoleLayers;
   vector<unsigned char> *muons_numberOfPrecisionLayers;
   vector<unsigned char> *muons_numberOfTriggerEtaHoleLayers;
   vector<unsigned char> *muons_numberOfTriggerEtaLayers;
   vector<unsigned char> *muons_outerClosePrecisionHits;
   vector<unsigned char> *muons_outerLargeHits;
   vector<unsigned char> *muons_outerLargeHoles;
   vector<unsigned char> *muons_outerOutBoundsPrecisionHits;
   vector<unsigned char> *muons_outerSmallHits;
   vector<unsigned char> *muons_outerSmallHoles;
   vector<bool>    *muons_passHighPtCuts;
   vector<bool>    *muons_passIDCuts;
   vector<bool>    *muons_passIPCuts;
   vector<bool>    *muons_passLooseCuts;
   vector<bool>    *muons_passLowPtCuts;
   vector<bool>    *muons_passMediumCuts;
   vector<unsigned char> *muons_primarySector;
   vector<unsigned char> *muons_quality;
   vector<unsigned char> *muons_secondarySector;
   vector<float>   *muons_segmentChi2OverDoF;
   vector<float>   *muons_segmentDeltaEta;
   vector<float>   *muons_segmentDeltaPhi;
   vector<unsigned short> *muons_type;
   vector<float>   *muons_z0;
   vector<float>   *muons_d0Sig;
   vector<float>   *muons_eta_err;
   vector<float>   *muons_pt_err;
   vector<vector<ULong64_t> > *muons_MdtExtChamFromCalo;
   vector<unsigned int> *muons_nDoF;
   Int_t           nMM;
   vector<int>     *nMMOnTrack;
   Int_t           nRPC;
   Int_t           nSTGC;
   vector<int>     *nSTGCOnTrack;
   vector<int>     *nSTGCOnTrackPad;
   vector<int>     *nSTGCOnTrackStrip;
   vector<int>     *nSTGCOnTrackWire;
   Int_t           nSTGCPad;
   Int_t           nSTGCStrip;
   Int_t           nSTGCWire;
   Int_t           n_Muon;
   Bool_t          passGRL;
   vector<unsigned short> *rpcAmbiFlag;
   vector<float>   *rpcError;
   vector<float>   *rpcPos_x;
   vector<float>   *rpcPos_y;
   vector<float>   *rpcPos_z;
   vector<float>   *rpcTime;
   vector<unsigned short> *rpcTrigInfo;
   vector<unsigned short> *rpc_MuonLink;
   vector<unsigned char> *rpc_doubletPhi;
   vector<unsigned char> *rpc_doubletR;
   vector<unsigned char> *rpc_doubletZ;
   vector<unsigned char> *rpc_gasGap;
   vector<bool>    *rpc_measuresPhi;
   vector<signed char> *rpc_stationEta;
   vector<unsigned char> *rpc_stationIndex;
   vector<unsigned char> *rpc_stationPhi;
   vector<unsigned char> *rpc_strip;
   UInt_t          runNumber;
   vector<int>     *sTGC_SimDataGenParPdgId;
   vector<float>   *sTGC_SimDataGenParPt;
   vector<float>   *sTGC_SimDataGenParVertexPos_x;
   vector<float>   *sTGC_SimDataGenParVertexPos_y;
   vector<float>   *sTGC_SimDataGenParVertexPos_z;
   vector<float>   *sTGC_SimDataGlobalPos_x;
   vector<float>   *sTGC_SimDataGlobalPos_y;
   vector<float>   *sTGC_SimDataGlobalPos_z;
   vector<float>   *sTGC_SimDataLocalPos_x;
   vector<float>   *sTGC_SimDataLocalPos_y;
   vector<unsigned short> *sTGC_SimData_channel;
   vector<unsigned char> *sTGC_SimData_channel_type;
   vector<unsigned char> *sTGC_SimData_gas_gap;
   vector<unsigned char> *sTGC_SimData_multiplet;
   vector<signed char> *sTGC_SimData_stationEta;
   vector<unsigned char> *sTGC_SimData_stationIndex;
   vector<unsigned char> *sTGC_SimData_stationPhi;
   vector<bool>    *segment_asoc;
   vector<unsigned short> *stgcBCID;
   vector<int>     *stgcCharge;
   vector<float>   *stgcError;
   vector<float>   *stgcGlobalPos_x;
   vector<float>   *stgcGlobalPos_y;
   vector<float>   *stgcGlobalPos_z;
   vector<float>   *stgcLocalPos_x;
   vector<float>   *stgcLocalPos_y;
   vector<int>     *stgcNStrips;
   vector<float>   *stgcOnTrackError;
   vector<float>   *stgcOnTrackGlobalPos_x;
   vector<float>   *stgcOnTrackGlobalPos_y;
   vector<float>   *stgcOnTrackGlobalPos_z;
   vector<float>   *stgcOnTrackLocalPos_x;
   vector<float>   *stgcOnTrackLocalPos_y;
   vector<int>     *stgcOnTrackNStrips;
   vector<float>   *stgcOnTrackPullTrack;
   vector<float>   *stgcOnTrackPullTrackMS;
   vector<float>   *stgcOnTrackPullTruth;
   vector<float>   *stgcOnTrackResidualTrack;
   vector<float>   *stgcOnTrackResidualTrackMS;
   vector<float>   *stgcOnTrackResidualTruth;
   vector<vector<int> > *stgcOnTrackStripCharges;
   vector<vector<short> > *stgcOnTrackStripDriftTimes;
   vector<vector<unsigned short> > *stgcOnTrackStripNumbers;
   vector<unsigned short> *stgcOnTrack_MuonLink;
   vector<unsigned short> *stgcOnTrack_channel;
   vector<unsigned char> *stgcOnTrack_channel_type;
   vector<unsigned char> *stgcOnTrack_gas_gap;
   vector<unsigned char> *stgcOnTrack_multiplet;
   vector<signed char> *stgcOnTrack_stationEta;
   vector<unsigned char> *stgcOnTrack_stationIndex;
   vector<unsigned char> *stgcOnTrack_stationPhi;
   vector<vector<float> > *stgcPadCorners_x;
   vector<vector<float> > *stgcPadCorners_y;
   vector<vector<unsigned short> > *stgcStripChannel;
   vector<vector<int> > *stgcStripCharge;
   vector<vector<short> > *stgcStripTime;
   vector<short>   *stgcTime;
   vector<float>   *stgcTrackStateGlobalPos_x;
   vector<float>   *stgcTrackStateGlobalPos_y;
   vector<float>   *stgcTrackStateGlobalPos_z;
   vector<float>   *stgcTrackStateLocalPos_x;
   vector<float>   *stgcTrackStateLocalPos_y;
   vector<unsigned short> *stgcTrackState_ClusterOnTrackLink;
   vector<unsigned short> *stgcTrackState_MuonLink;
   vector<unsigned short> *stgcTrackState_channel;
   vector<unsigned char> *stgcTrackState_channel_type;
   vector<unsigned short> *stgcTrackState_closestClusterLink;
   vector<float>   *stgcTrackState_closestClusterResidualX;
   vector<float>   *stgcTrackState_closestClusterResidualY;
   vector<unsigned char> *stgcTrackState_gas_gap;
   vector<unsigned char> *stgcTrackState_multiplet;
   vector<unsigned short> *stgcTrackState_padEta;
   vector<unsigned short> *stgcTrackState_padPhi;
   vector<signed char> *stgcTrackState_stationEta;
   vector<unsigned char> *stgcTrackState_stationIndex;
   vector<unsigned char> *stgcTrackState_stationPhi;
   vector<unsigned short> *stgc_channel;
   vector<unsigned char> *stgc_channel_type;
   vector<unsigned char> *stgc_gas_gap;
   vector<unsigned char> *stgc_multiplet;
   vector<vector<int> > *stgc_segment_cluster_channel_type;
   vector<vector<float> > *stgc_segment_cluster_gas_gap;
   vector<vector<float> > *stgc_segment_cluster_globpos_x;
   vector<vector<float> > *stgc_segment_cluster_globpos_y;
   vector<vector<float> > *stgc_segment_cluster_globpos_z;
   vector<vector<float> > *stgc_segment_cluster_multilayer;
   vector<float>   *stgc_segment_cluster_theta;
   vector<float>   *stgc_segment_clusterprd_residuals_x;
   vector<float>   *stgc_segment_clusterprd_residuals_y;
   vector<vector<float> > *stgc_segment_locx_err;
   vector<vector<float> > *stgc_segment_locy_err;
   vector<vector<float> > *stgc_segment_truth_locx_residuals;
   vector<vector<float> > *stgc_segment_truth_locy_residuals;
   vector<signed char> *stgc_stationEta;
   vector<unsigned char> *stgc_stationIndex;
   vector<unsigned char> *stgc_stationPhi;
   vector<short>   *unassoc_segment_ChamberIdx;
   vector<short>   *unassoc_segment_ChamberTech;
   vector<short>   *unassoc_segment_EtaStation;
   vector<float>   *unassoc_segment_Mom_x;
   vector<float>   *unassoc_segment_Mom_y;
   vector<float>   *unassoc_segment_Mom_z;
   vector<float>   *unassoc_segment_Pos_x;
   vector<float>   *unassoc_segment_Pos_y;
   vector<float>   *unassoc_segment_Pos_z;
   vector<short>   *unassoc_segment_Sector;
   vector<float>   *unassoc_segment_chi2;
   vector<unsigned int> *unassoc_segment_nDoF;
   vector<unsigned char> *unassoc_segment_nMM_EtaHits;
   vector<unsigned char> *unassoc_segment_nMM_StereoHits;
   vector<unsigned int> *unassoc_segment_nPrecisionHits;
   vector<unsigned char> *unassoc_segment_nSTGC_EtaHits;
   vector<unsigned char> *unassoc_segment_nSTGC_PhiHits;
   vector<unsigned int> *unassoc_segment_nTrigEtaLayers;
   vector<unsigned int> *unassoc_segment_nTrigPhiLayers;

   // List of branches
   TBranch        *b_IDTracks_pt;   //!
   TBranch        *b_IDTracks_eta;   //!
   TBranch        *b_IDTracks_phi;   //!
   TBranch        *b_IDTracks_e;   //!
   TBranch        *b_IDTracks_q;   //!
   TBranch        *b_IDTracks_chi2;   //!
   TBranch        *b_IDTracks_cov_d0;   //!
   TBranch        *b_IDTracks_cov_phi;   //!
   TBranch        *b_IDTracks_cov_phi_d0;   //!
   TBranch        *b_IDTracks_cov_phi_z0;   //!
   TBranch        *b_IDTracks_cov_qOverP;   //!
   TBranch        *b_IDTracks_cov_qOverP_d0;   //!
   TBranch        *b_IDTracks_cov_qOverP_phi;   //!
   TBranch        *b_IDTracks_cov_qOverP_theta;   //!
   TBranch        *b_IDTracks_cov_qOverP_z0;   //!
   TBranch        *b_IDTracks_cov_theta;   //!
   TBranch        *b_IDTracks_cov_theta_d0;   //!
   TBranch        *b_IDTracks_cov_theta_phi;   //!
   TBranch        *b_IDTracks_cov_theta_z0;   //!
   TBranch        *b_IDTracks_cov_z0;   //!
   TBranch        *b_IDTracks_cov_z0_d0;   //!
   TBranch        *b_IDTracks_d0;   //!
   TBranch        *b_IDTracks_z0;   //!
   TBranch        *b_IDTracks_d0Sig;   //!
   TBranch        *b_IDTracks_eta_err;   //!
   TBranch        *b_IDTracks_pt_err;   //!
   TBranch        *b_IDTracks_nDoF;   //!
   TBranch        *b_METracks_pt;   //!
   TBranch        *b_METracks_eta;   //!
   TBranch        *b_METracks_phi;   //!
   TBranch        *b_METracks_e;   //!
   TBranch        *b_METracks_q;   //!
   TBranch        *b_METracks_chi2;   //!
   TBranch        *b_METracks_cov_d0;   //!
   TBranch        *b_METracks_cov_phi;   //!
   TBranch        *b_METracks_cov_phi_d0;   //!
   TBranch        *b_METracks_cov_phi_z0;   //!
   TBranch        *b_METracks_cov_qOverP;   //!
   TBranch        *b_METracks_cov_qOverP_d0;   //!
   TBranch        *b_METracks_cov_qOverP_phi;   //!
   TBranch        *b_METracks_cov_qOverP_theta;   //!
   TBranch        *b_METracks_cov_qOverP_z0;   //!
   TBranch        *b_METracks_cov_theta;   //!
   TBranch        *b_METracks_cov_theta_d0;   //!
   TBranch        *b_METracks_cov_theta_phi;   //!
   TBranch        *b_METracks_cov_theta_z0;   //!
   TBranch        *b_METracks_cov_z0;   //!
   TBranch        *b_METracks_cov_z0_d0;   //!
   TBranch        *b_METracks_d0;   //!
   TBranch        *b_METracks_z0;   //!
   TBranch        *b_METracks_d0Sig;   //!
   TBranch        *b_METracks_eta_err;   //!
   TBranch        *b_METracks_pt_err;   //!
   TBranch        *b_METracks_nDoF;   //!
   TBranch        *b_MM_NumRioOnTrkCB;   //!
   TBranch        *b_MM_NumRioOnTrkME;   //!
   TBranch        *b_MM_NumRioOnTrkMS;   //!
   TBranch        *b_MM_NumRioOnTrkMSOE;   //!
   TBranch        *b_MM_NumRioOnTrkPR;   //!
   TBranch        *b_MM_SimDataDeposit;   //!
   TBranch        *b_MM_SimDataGenParPdgId;   //!
   TBranch        *b_MM_SimDataGenParPt;   //!
   TBranch        *b_MM_SimDataGenParVertexPos_x;   //!
   TBranch        *b_MM_SimDataGenParVertexPos_y;   //!
   TBranch        *b_MM_SimDataGenParVertexPos_z;   //!
   TBranch        *b_MM_SimDataGloabalPos_x;   //!
   TBranch        *b_MM_SimDataGloabalPos_y;   //!
   TBranch        *b_MM_SimDataGloabalPos_z;   //!
   TBranch        *b_MM_SimDataLocalPos_x;   //!
   TBranch        *b_MM_SimDataLocalPos_y;   //!
   TBranch        *b_MM_SimData_channel;   //!
   TBranch        *b_MM_SimData_gas_gap;   //!
   TBranch        *b_MM_SimData_multiplet;   //!
   TBranch        *b_MM_SimData_stationEta;   //!
   TBranch        *b_MM_SimData_stationIndex;   //!
   TBranch        *b_MM_SimData_stationPhi;   //!
   TBranch        *b_MM_nDeltaElectrons;   //!
   TBranch        *b_MM_nMuonSimData;   //!
   TBranch        *b_MSOETracks_pt;   //!
   TBranch        *b_MSOETracks_eta;   //!
   TBranch        *b_MSOETracks_phi;   //!
   TBranch        *b_MSOETracks_e;   //!
   TBranch        *b_MSOETracks_q;   //!
   TBranch        *b_MSOETracks_chi2;   //!
   TBranch        *b_MSOETracks_cov_d0;   //!
   TBranch        *b_MSOETracks_cov_phi;   //!
   TBranch        *b_MSOETracks_cov_phi_d0;   //!
   TBranch        *b_MSOETracks_cov_phi_z0;   //!
   TBranch        *b_MSOETracks_cov_qOverP;   //!
   TBranch        *b_MSOETracks_cov_qOverP_d0;   //!
   TBranch        *b_MSOETracks_cov_qOverP_phi;   //!
   TBranch        *b_MSOETracks_cov_qOverP_theta;   //!
   TBranch        *b_MSOETracks_cov_qOverP_z0;   //!
   TBranch        *b_MSOETracks_cov_theta;   //!
   TBranch        *b_MSOETracks_cov_theta_d0;   //!
   TBranch        *b_MSOETracks_cov_theta_phi;   //!
   TBranch        *b_MSOETracks_cov_theta_z0;   //!
   TBranch        *b_MSOETracks_cov_z0;   //!
   TBranch        *b_MSOETracks_cov_z0_d0;   //!
   TBranch        *b_MSOETracks_d0;   //!
   TBranch        *b_MSOETracks_z0;   //!
   TBranch        *b_MSOETracks_d0Sig;   //!
   TBranch        *b_MSOETracks_eta_err;   //!
   TBranch        *b_MSOETracks_pt_err;   //!
   TBranch        *b_MSOETracks_nDoF;   //!
   TBranch        *b_MSTracks_pt;   //!
   TBranch        *b_MSTracks_eta;   //!
   TBranch        *b_MSTracks_phi;   //!
   TBranch        *b_MSTracks_e;   //!
   TBranch        *b_MSTracks_q;   //!
   TBranch        *b_MSTracks_chi2;   //!
   TBranch        *b_MSTracks_cov_d0;   //!
   TBranch        *b_MSTracks_cov_phi;   //!
   TBranch        *b_MSTracks_cov_phi_d0;   //!
   TBranch        *b_MSTracks_cov_phi_z0;   //!
   TBranch        *b_MSTracks_cov_qOverP;   //!
   TBranch        *b_MSTracks_cov_qOverP_d0;   //!
   TBranch        *b_MSTracks_cov_qOverP_phi;   //!
   TBranch        *b_MSTracks_cov_qOverP_theta;   //!
   TBranch        *b_MSTracks_cov_qOverP_z0;   //!
   TBranch        *b_MSTracks_cov_theta;   //!
   TBranch        *b_MSTracks_cov_theta_d0;   //!
   TBranch        *b_MSTracks_cov_theta_phi;   //!
   TBranch        *b_MSTracks_cov_theta_z0;   //!
   TBranch        *b_MSTracks_cov_z0;   //!
   TBranch        *b_MSTracks_cov_z0_d0;   //!
   TBranch        *b_MSTracks_d0;   //!
   TBranch        *b_MSTracks_z0;   //!
   TBranch        *b_MSTracks_d0Sig;   //!
   TBranch        *b_MSTracks_eta_err;   //!
   TBranch        *b_MSTracks_pt_err;   //!
   TBranch        *b_MSTracks_nDoF;   //!
   TBranch        *b_MdtChamHitId_multiLayer;   //!
   TBranch        *b_MdtChamHitId_stationEta;   //!
   TBranch        *b_MdtChamHitId_stationIndex;   //!
   TBranch        *b_MdtChamHitId_stationPhi;   //!
   TBranch        *b_MdtChamHitId_tube;   //!
   TBranch        *b_MdtChamHitId_tubeLayer;   //!
   TBranch        *b_MdtChamHit_Adc;   //!
   TBranch        *b_MdtChamHit_ChamberLink;   //!
   TBranch        *b_MdtChamHit_Tdc;   //!
   TBranch        *b_MdtChamHit_driftR;   //!
   TBranch        *b_MdtChamHit_driftUncert;   //!
   TBranch        *b_MdtChamId_multiLayer;   //!
   TBranch        *b_MdtChamId_stationEta;   //!
   TBranch        *b_MdtChamId_stationIndex;   //!
   TBranch        *b_MdtChamId_stationPhi;   //!
   TBranch        *b_MdtChamId_tube;   //!
   TBranch        *b_MdtChamId_tubeLayer;   //!
   TBranch        *b_MdtCham_NTubesPerML;   //!
   TBranch        *b_MdtCham_hitN;   //!
   TBranch        *b_MdtCham_matchedCaloTag;   //!
   TBranch        *b_MdtCham_matchedCaloTag_IPcut;   //!
   TBranch        *b_MdtCham_matchedMuon;   //!
   TBranch        *b_MdtCham_matchedMuon_IPcut;   //!
   TBranch        *b_RPC_NumRioOnTrkCB;   //!
   TBranch        *b_RPC_NumRioOnTrkME;   //!
   TBranch        *b_RPC_NumRioOnTrkMS;   //!
   TBranch        *b_RPC_NumRioOnTrkMSOE;   //!
   TBranch        *b_RPC_NumRioOnTrkPR;   //!
   TBranch        *b_avgIntPerCrossing;   //!
   TBranch        *b_cham_N;   //!
   TBranch        *b_evtNumber;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_multiLayer;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_stationEta;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_stationIndex;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_stationPhi;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_tube;   //!
   TBranch        *b_extCaloToCham_Identifier_IPCut_tubeLayer;   //!
   TBranch        *b_extCaloToCham_Identifier_multiLayer;   //!
   TBranch        *b_extCaloToCham_Identifier_stationEta;   //!
   TBranch        *b_extCaloToCham_Identifier_stationIndex;   //!
   TBranch        *b_extCaloToCham_Identifier_stationPhi;   //!
   TBranch        *b_extCaloToCham_Identifier_tube;   //!
   TBranch        *b_extCaloToCham_Identifier_tubeLayer;   //!
   TBranch        *b_extCaloToCham_N;   //!
   TBranch        *b_extCaloToCham_N_IPCut;   //!
   TBranch        *b_lbNumber;   //!
   TBranch        *b_lumi;   //!
   TBranch        *b_mmClusterOnTrackGlobalPos_x;   //!
   TBranch        *b_mmClusterOnTrackGlobalPos_y;   //!
   TBranch        *b_mmClusterOnTrackGlobalPos_z;   //!
   TBranch        *b_mmClusterOnTrackLocalPos_x;   //!
   TBranch        *b_mmClusterOnTrackLocalPos_y;   //!
   TBranch        *b_mmError;   //!
   TBranch        *b_mmLocalStripPosX;   //!
   TBranch        *b_mmOnTrackError;   //!
   TBranch        *b_mmOnTrackGlobalPos_x;   //!
   TBranch        *b_mmOnTrackGlobalPos_y;   //!
   TBranch        *b_mmOnTrackGlobalPos_z;   //!
   TBranch        *b_mmOnTrackLocalPos_x;   //!
   TBranch        *b_mmOnTrackLocalPos_y;   //!
   TBranch        *b_mmOnTrackNStrips;   //!
   TBranch        *b_mmOnTrackPullTrack;   //!
   TBranch        *b_mmOnTrackPullTrackMS;   //!
   TBranch        *b_mmOnTrackResidualTrack;   //!
   TBranch        *b_mmOnTrackResidualTrackMS;   //!
   TBranch        *b_mmOnTrackResidualTruth;   //!
   TBranch        *b_mmOnTrackStripCharges;   //!
   TBranch        *b_mmOnTrackStripDriftTimes;   //!
   TBranch        *b_mmOnTrackStripNumbers;   //!
   TBranch        *b_mmOnTrack_MuonLink;   //!
   TBranch        *b_mmOnTrack_channel;   //!
   TBranch        *b_mmOnTrack_gas_gap;   //!
   TBranch        *b_mmOnTrack_multiplet;   //!
   TBranch        *b_mmOnTrack_stationEta;   //!
   TBranch        *b_mmOnTrack_stationIndex;   //!
   TBranch        *b_mmOnTrack_stationPhi;   //!
   TBranch        *b_mmOnTrackuTpcAngle;   //!
   TBranch        *b_mmOnTrackuTpcChisqProb;   //!
   TBranch        *b_mmPos_x;   //!
   TBranch        *b_mmPos_y;   //!
   TBranch        *b_mmPos_z;   //!
   TBranch        *b_mmResidualTruth;   //!
   TBranch        *b_mmStripCharges;   //!
   TBranch        *b_mmStripDriftTimes;   //!
   TBranch        *b_mmStripNumbers;   //!
   TBranch        *b_mmTpcAngle;   //!
   TBranch        *b_mmTrackStateGlobalPos_x;   //!
   TBranch        *b_mmTrackStateGlobalPos_y;   //!
   TBranch        *b_mmTrackStateGlobalPos_z;   //!
   TBranch        *b_mmTrackStateLocalPos_x;   //!
   TBranch        *b_mmTrackStateLocalPos_y;   //!
   TBranch        *b_mmTrackState_ClusterOnTrackLink;   //!
   TBranch        *b_mmTrackState_MuonLink;   //!
   TBranch        *b_mmTrackState_channel;   //!
   TBranch        *b_mmTrackState_closestClusterLink;   //!
   TBranch        *b_mmTrackState_closestClusterResidual;   //!
   TBranch        *b_mmTrackState_gas_gap;   //!
   TBranch        *b_mmTrackState_multiplet;   //!
   TBranch        *b_mmTrackState_stationEta;   //!
   TBranch        *b_mmTrackState_stationIndex;   //!
   TBranch        *b_mmTrackState_stationPhi;   //!
   TBranch        *b_mm_channel;   //!
   TBranch        *b_mm_gas_gap;   //!
   TBranch        *b_mm_multiplet;   //!
   TBranch        *b_mm_segment_cluster_gas_gap;   //!
   TBranch        *b_mm_segment_cluster_globpos_x;   //!
   TBranch        *b_mm_segment_cluster_globpos_y;   //!
   TBranch        *b_mm_segment_cluster_globpos_z;   //!
   TBranch        *b_mm_segment_cluster_multilayer;   //!
   TBranch        *b_mm_segment_clusterprd_residuals_x;   //!
   TBranch        *b_mm_segment_clusterprd_residuals_y;   //!
   TBranch        *b_mm_segment_locx_err;   //!
   TBranch        *b_mm_segment_truth_locx_residuals;   //!
   TBranch        *b_mm_stationEta;   //!
   TBranch        *b_mm_stationIndex;   //!
   TBranch        *b_mm_stationPhi;   //!
   TBranch        *b_mmmuTpcChi2;   //!
   TBranch        *b_muon_segmentLink;   //!
   TBranch        *b_muon_segment_ChamberIdx;   //!
   TBranch        *b_muon_segment_ChamberTech;   //!
   TBranch        *b_muon_segment_EtaStation;   //!
   TBranch        *b_muon_segment_Mom_x;   //!
   TBranch        *b_muon_segment_Mom_y;   //!
   TBranch        *b_muon_segment_Mom_z;   //!
   TBranch        *b_muon_segment_Pos_x;   //!
   TBranch        *b_muon_segment_Pos_y;   //!
   TBranch        *b_muon_segment_Pos_z;   //!
   TBranch        *b_muon_segment_Sector;   //!
   TBranch        *b_muon_segment_chi2;   //!
   TBranch        *b_muon_segment_nDoF;   //!
   TBranch        *b_muon_segment_nMM_EtaHits;   //!
   TBranch        *b_muon_segment_nMM_StereoHits;   //!
   TBranch        *b_muon_segment_nPrecisionHits;   //!
   TBranch        *b_muon_segment_nSTGC_EtaHits;   //!
   TBranch        *b_muon_segment_nSTGC_PhiHits;   //!
   TBranch        *b_muon_segment_nTrigEtaLayers;   //!
   TBranch        *b_muon_segment_nTrigPhiLayers;   //!
   TBranch        *b_muons_pt;   //!
   TBranch        *b_muons_eta;   //!
   TBranch        *b_muons_phi;   //!
   TBranch        *b_muons_e;   //!
   TBranch        *b_muons_q;   //!
   TBranch        *b_muons_EnergyLoss;   //!
   TBranch        *b_muons_EnergyLossSigma;   //!
   TBranch        *b_muons_FSR_CandidateEnergy;   //!
   TBranch        *b_muons_IDLink;   //!
   TBranch        *b_muons_MELink;   //!
   TBranch        *b_muons_MSLink;   //!
   TBranch        *b_muons_MSOELink;   //!
   TBranch        *b_muons_MeasEnergyLoss;   //!
   TBranch        *b_muons_MeasEnergyLossSigma;   //!
   TBranch        *b_muons_ParamEnergyLoss;   //!
   TBranch        *b_muons_ParamEnergyLossSigmaMinus;   //!
   TBranch        *b_muons_ParamEnergyLossSigmaPlus;   //!
   TBranch        *b_muons_PtImbalSig;   //!
   TBranch        *b_muons_SCS;   //!
   TBranch        *b_muons_SNS;   //!
   TBranch        *b_muons_allAuthors;   //!
   TBranch        *b_muons_author;   //!
   TBranch        *b_muons_chi2;   //!
   TBranch        *b_muons_combinedTrackOutBoundsPrecisionHits;   //!
   TBranch        *b_muons_cov_d0;   //!
   TBranch        *b_muons_cov_phi;   //!
   TBranch        *b_muons_cov_phi_d0;   //!
   TBranch        *b_muons_cov_phi_z0;   //!
   TBranch        *b_muons_cov_qOverP;   //!
   TBranch        *b_muons_cov_qOverP_d0;   //!
   TBranch        *b_muons_cov_qOverP_phi;   //!
   TBranch        *b_muons_cov_qOverP_theta;   //!
   TBranch        *b_muons_cov_qOverP_z0;   //!
   TBranch        *b_muons_cov_theta;   //!
   TBranch        *b_muons_cov_theta_d0;   //!
   TBranch        *b_muons_cov_theta_phi;   //!
   TBranch        *b_muons_cov_theta_z0;   //!
   TBranch        *b_muons_cov_z0;   //!
   TBranch        *b_muons_cov_z0_d0;   //!
   TBranch        *b_muons_cscUnspoiledEtaHits;   //!
   TBranch        *b_muons_d0;   //!
   TBranch        *b_muons_extendedClosePrecisionHits;   //!
   TBranch        *b_muons_extendedLargeHits;   //!
   TBranch        *b_muons_extendedLargeHoles;   //!
   TBranch        *b_muons_extendedOutBoundsPrecisionHits;   //!
   TBranch        *b_muons_extendedSmallHits;   //!
   TBranch        *b_muons_extendedSmallHoles;   //!
   TBranch        *b_muons_innAngle;   //!
   TBranch        *b_muons_innerClosePrecisionHits;   //!
   TBranch        *b_muons_innerLargeHits;   //!
   TBranch        *b_muons_innerLargeHoles;   //!
   TBranch        *b_muons_innerOutBoundsPrecisionHits;   //!
   TBranch        *b_muons_innerSmallHits;   //!
   TBranch        *b_muons_innerSmallHoles;   //!
   TBranch        *b_muons_isBad;   //!
   TBranch        *b_muons_isCaloTag;   //!
   TBranch        *b_muons_isEndcapGoodLayers;   //!
   TBranch        *b_muons_isSmallGoodSectors;   //!
   TBranch        *b_muons_midAngle;   //!
   TBranch        *b_muons_middleClosePrecisionHits;   //!
   TBranch        *b_muons_middleLargeHits;   //!
   TBranch        *b_muons_middleLargeHoles;   //!
   TBranch        *b_muons_middleOutBoundsPrecisionHits;   //!
   TBranch        *b_muons_middleSmallHits;   //!
   TBranch        *b_muons_middleSmallHoles;   //!
   TBranch        *b_muons_msInnerMatchChi2;   //!
   TBranch        *b_muons_msInnerMatchDOF;   //!
   TBranch        *b_muons_msOuterMatchChi2;   //!
   TBranch        *b_muons_msOuterMatchDOF;   //!
   TBranch        *b_muons_numberOfGoodPrecisionLayers;   //!
   TBranch        *b_muons_numberOfOutliersOnTrack;   //!
   TBranch        *b_muons_numberOfPhiHoleLayers;   //!
   TBranch        *b_muons_numberOfPhiLayers;   //!
   TBranch        *b_muons_numberOfPrecisionHoleLayers;   //!
   TBranch        *b_muons_numberOfPrecisionLayers;   //!
   TBranch        *b_muons_numberOfTriggerEtaHoleLayers;   //!
   TBranch        *b_muons_numberOfTriggerEtaLayers;   //!
   TBranch        *b_muons_outerClosePrecisionHits;   //!
   TBranch        *b_muons_outerLargeHits;   //!
   TBranch        *b_muons_outerLargeHoles;   //!
   TBranch        *b_muons_outerOutBoundsPrecisionHits;   //!
   TBranch        *b_muons_outerSmallHits;   //!
   TBranch        *b_muons_outerSmallHoles;   //!
   TBranch        *b_muons_passHighPtCuts;   //!
   TBranch        *b_muons_passIDCuts;   //!
   TBranch        *b_muons_passIPCuts;   //!
   TBranch        *b_muons_passLooseCuts;   //!
   TBranch        *b_muons_passLowPtCuts;   //!
   TBranch        *b_muons_passMediumCuts;   //!
   TBranch        *b_muons_primarySector;   //!
   TBranch        *b_muons_quality;   //!
   TBranch        *b_muons_secondarySector;   //!
   TBranch        *b_muons_segmentChi2OverDoF;   //!
   TBranch        *b_muons_segmentDeltaEta;   //!
   TBranch        *b_muons_segmentDeltaPhi;   //!
   TBranch        *b_muons_type;   //!
   TBranch        *b_muons_z0;   //!
   TBranch        *b_muons_d0Sig;   //!
   TBranch        *b_muons_eta_err;   //!
   TBranch        *b_muons_pt_err;   //!
   TBranch        *b_muons_MdtExtChamFromCalo;   //!
   TBranch        *b_muons_nDoF;   //!
   TBranch        *b_nMM;   //!
   TBranch        *b_nMMOnTrack;   //!
   TBranch        *b_nRPC;   //!
   TBranch        *b_nSTGC;   //!
   TBranch        *b_nSTGCOnTrack;   //!
   TBranch        *b_nSTGCOnTrackPad;   //!
   TBranch        *b_nSTGCOnTrackStrip;   //!
   TBranch        *b_nSTGCOnTrackWire;   //!
   TBranch        *b_nSTGCPad;   //!
   TBranch        *b_nSTGCStrip;   //!
   TBranch        *b_nSTGCWire;   //!
   TBranch        *b_n_Muon;   //!
   TBranch        *b_passGRL;   //!
   TBranch        *b_rpcAmbiFlag;   //!
   TBranch        *b_rpcError;   //!
   TBranch        *b_rpcPos_x;   //!
   TBranch        *b_rpcPos_y;   //!
   TBranch        *b_rpcPos_z;   //!
   TBranch        *b_rpcTime;   //!
   TBranch        *b_rpcTrigInfo;   //!
   TBranch        *b_rpc_MuonLink;   //!
   TBranch        *b_rpc_doubletPhi;   //!
   TBranch        *b_rpc_doubletR;   //!
   TBranch        *b_rpc_doubletZ;   //!
   TBranch        *b_rpc_gasGap;   //!
   TBranch        *b_rpc_measuresPhi;   //!
   TBranch        *b_rpc_stationEta;   //!
   TBranch        *b_rpc_stationIndex;   //!
   TBranch        *b_rpc_stationPhi;   //!
   TBranch        *b_rpc_strip;   //!
   TBranch        *b_runNumber;   //!
   TBranch        *b_sTGC_SimDataGenParPdgId;   //!
   TBranch        *b_sTGC_SimDataGenParPt;   //!
   TBranch        *b_sTGC_SimDataGenParVertexPos_x;   //!
   TBranch        *b_sTGC_SimDataGenParVertexPos_y;   //!
   TBranch        *b_sTGC_SimDataGenParVertexPos_z;   //!
   TBranch        *b_sTGC_SimDataGlobalPos_x;   //!
   TBranch        *b_sTGC_SimDataGlobalPos_y;   //!
   TBranch        *b_sTGC_SimDataGlobalPos_z;   //!
   TBranch        *b_sTGC_SimDataLocalPos_x;   //!
   TBranch        *b_sTGC_SimDataLocalPos_y;   //!
   TBranch        *b_sTGC_SimData_channel;   //!
   TBranch        *b_sTGC_SimData_channel_type;   //!
   TBranch        *b_sTGC_SimData_gas_gap;   //!
   TBranch        *b_sTGC_SimData_multiplet;   //!
   TBranch        *b_sTGC_SimData_stationEta;   //!
   TBranch        *b_sTGC_SimData_stationIndex;   //!
   TBranch        *b_sTGC_SimData_stationPhi;   //!
   TBranch        *b_segment_asoc;   //!
   TBranch        *b_stgcBCID;   //!
   TBranch        *b_stgcCharge;   //!
   TBranch        *b_stgcError;   //!
   TBranch        *b_stgcGlobalPos_x;   //!
   TBranch        *b_stgcGlobalPos_y;   //!
   TBranch        *b_stgcGlobalPos_z;   //!
   TBranch        *b_stgcLocalPos_x;   //!
   TBranch        *b_stgcLocalPos_y;   //!
   TBranch        *b_stgcNStrips;   //!
   TBranch        *b_stgcOnTrackError;   //!
   TBranch        *b_stgcOnTrackGlobalPos_x;   //!
   TBranch        *b_stgcOnTrackGlobalPos_y;   //!
   TBranch        *b_stgcOnTrackGlobalPos_z;   //!
   TBranch        *b_stgcOnTrackLocalPos_x;   //!
   TBranch        *b_stgcOnTrackLocalPos_y;   //!
   TBranch        *b_stgcOnTrackNStrips;   //!
   TBranch        *b_stgcOnTrackPullTrack;   //!
   TBranch        *b_stgcOnTrackPullTrackMS;   //!
   TBranch        *b_stgcOnTrackPullTruth;   //!
   TBranch        *b_stgcOnTrackResidualTrack;   //!
   TBranch        *b_stgcOnTrackResidualTrackMS;   //!
   TBranch        *b_stgcOnTrackResidualTruth;   //!
   TBranch        *b_stgcOnTrackStripCharges;   //!
   TBranch        *b_stgcOnTrackStripDriftTimes;   //!
   TBranch        *b_stgcOnTrackStripNumbers;   //!
   TBranch        *b_stgcOnTrack_MuonLink;   //!
   TBranch        *b_stgcOnTrack_channel;   //!
   TBranch        *b_stgcOnTrack_channel_type;   //!
   TBranch        *b_stgcOnTrack_gas_gap;   //!
   TBranch        *b_stgcOnTrack_multiplet;   //!
   TBranch        *b_stgcOnTrack_stationEta;   //!
   TBranch        *b_stgcOnTrack_stationIndex;   //!
   TBranch        *b_stgcOnTrack_stationPhi;   //!
   TBranch        *b_stgcPadCorners_x;   //!
   TBranch        *b_stgcPadCorners_y;   //!
   TBranch        *b_stgcStripChannel;   //!
   TBranch        *b_stgcStripCharge;   //!
   TBranch        *b_stgcStripTime;   //!
   TBranch        *b_stgcTime;   //!
   TBranch        *b_stgcTrackStateGlobalPos_x;   //!
   TBranch        *b_stgcTrackStateGlobalPos_y;   //!
   TBranch        *b_stgcTrackStateGlobalPos_z;   //!
   TBranch        *b_stgcTrackStateLocalPos_x;   //!
   TBranch        *b_stgcTrackStateLocalPos_y;   //!
   TBranch        *b_stgcTrackState_ClusterOnTrackLink;   //!
   TBranch        *b_stgcTrackState_MuonLink;   //!
   TBranch        *b_stgcTrackState_channel;   //!
   TBranch        *b_stgcTrackState_channel_type;   //!
   TBranch        *b_stgcTrackState_closestClusterLink;   //!
   TBranch        *b_stgcTrackState_closestClusterResidualX;   //!
   TBranch        *b_stgcTrackState_closestClusterResidualY;   //!
   TBranch        *b_stgcTrackState_gas_gap;   //!
   TBranch        *b_stgcTrackState_multiplet;   //!
   TBranch        *b_stgcTrackState_padEta;   //!
   TBranch        *b_stgcTrackState_padPhi;   //!
   TBranch        *b_stgcTrackState_stationEta;   //!
   TBranch        *b_stgcTrackState_stationIndex;   //!
   TBranch        *b_stgcTrackState_stationPhi;   //!
   TBranch        *b_stgc_channel;   //!
   TBranch        *b_stgc_channel_type;   //!
   TBranch        *b_stgc_gas_gap;   //!
   TBranch        *b_stgc_multiplet;   //!
   TBranch        *b_stgc_segment_cluster_channel_type;   //!
   TBranch        *b_stgc_segment_cluster_gas_gap;   //!
   TBranch        *b_stgc_segment_cluster_globpos_x;   //!
   TBranch        *b_stgc_segment_cluster_globpos_y;   //!
   TBranch        *b_stgc_segment_cluster_globpos_z;   //!
   TBranch        *b_stgc_segment_cluster_multilayer;   //!
   TBranch        *b_stgc_segment_cluster_theta;   //!
   TBranch        *b_stgc_segment_clusterprd_residuals_x;   //!
   TBranch        *b_stgc_segment_clusterprd_residuals_y;   //!
   TBranch        *b_stgc_segment_locx_err;   //!
   TBranch        *b_stgc_segment_locy_err;   //!
   TBranch        *b_stgc_segment_truth_locx_residuals;   //!
   TBranch        *b_stgc_segment_truth_locy_residuals;   //!
   TBranch        *b_stgc_stationEta;   //!
   TBranch        *b_stgc_stationIndex;   //!
   TBranch        *b_stgc_stationPhi;   //!
   TBranch        *b_unassoc_segment_ChamberIdx;   //!
   TBranch        *b_unassoc_segment_ChamberTech;   //!
   TBranch        *b_unassoc_segment_EtaStation;   //!
   TBranch        *b_unassoc_segment_Mom_x;   //!
   TBranch        *b_unassoc_segment_Mom_y;   //!
   TBranch        *b_unassoc_segment_Mom_z;   //!
   TBranch        *b_unassoc_segment_Pos_x;   //!
   TBranch        *b_unassoc_segment_Pos_y;   //!
   TBranch        *b_unassoc_segment_Pos_z;   //!
   TBranch        *b_unassoc_segment_Sector;   //!
   TBranch        *b_unassoc_segment_chi2;   //!
   TBranch        *b_unassoc_segment_nDoF;   //!
   TBranch        *b_unassoc_segment_nMM_EtaHits;   //!
   TBranch        *b_unassoc_segment_nMM_StereoHits;   //!
   TBranch        *b_unassoc_segment_nPrecisionHits;   //!
   TBranch        *b_unassoc_segment_nSTGC_EtaHits;   //!
   TBranch        *b_unassoc_segment_nSTGC_PhiHits;   //!
   TBranch        *b_unassoc_segment_nTrigEtaLayers;   //!
   TBranch        *b_unassoc_segment_nTrigPhiLayers;   //!

   AnalizeMuonTester(TTree *tree=0);
   virtual ~AnalizeMuonTester();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef AnalizeMuonTester_cxx
AnalizeMuonTester::AnalizeMuonTester(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("group.det-muon.31657347.EXT0._000001.GridFile.root"); // data22_13p6TeV.00436422.physics_Main.merge.NTUP_MUTEST.f1291_m2138_c1404_m2100._0001
      if (!f || !f->IsOpen()) {
         f = new TFile("group.det-muon.31657347.EXT0._000001.GridFile.root"); 
      }
      f->GetObject("BasicTesterTree",tree);

   }
   Init(tree);
}

AnalizeMuonTester::~AnalizeMuonTester()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t AnalizeMuonTester::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t AnalizeMuonTester::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void AnalizeMuonTester::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   IDTracks_pt = 0;
   IDTracks_eta = 0;
   IDTracks_phi = 0;
   IDTracks_e = 0;
   IDTracks_q = 0;
   IDTracks_chi2 = 0;
   IDTracks_cov_d0 = 0;
   IDTracks_cov_phi = 0;
   IDTracks_cov_phi_d0 = 0;
   IDTracks_cov_phi_z0 = 0;
   IDTracks_cov_qOverP = 0;
   IDTracks_cov_qOverP_d0 = 0;
   IDTracks_cov_qOverP_phi = 0;
   IDTracks_cov_qOverP_theta = 0;
   IDTracks_cov_qOverP_z0 = 0;
   IDTracks_cov_theta = 0;
   IDTracks_cov_theta_d0 = 0;
   IDTracks_cov_theta_phi = 0;
   IDTracks_cov_theta_z0 = 0;
   IDTracks_cov_z0 = 0;
   IDTracks_cov_z0_d0 = 0;
   IDTracks_d0 = 0;
   IDTracks_z0 = 0;
   IDTracks_d0Sig = 0;
   IDTracks_eta_err = 0;
   IDTracks_pt_err = 0;
   IDTracks_nDoF = 0;
   METracks_pt = 0;
   METracks_eta = 0;
   METracks_phi = 0;
   METracks_e = 0;
   METracks_q = 0;
   METracks_chi2 = 0;
   METracks_cov_d0 = 0;
   METracks_cov_phi = 0;
   METracks_cov_phi_d0 = 0;
   METracks_cov_phi_z0 = 0;
   METracks_cov_qOverP = 0;
   METracks_cov_qOverP_d0 = 0;
   METracks_cov_qOverP_phi = 0;
   METracks_cov_qOverP_theta = 0;
   METracks_cov_qOverP_z0 = 0;
   METracks_cov_theta = 0;
   METracks_cov_theta_d0 = 0;
   METracks_cov_theta_phi = 0;
   METracks_cov_theta_z0 = 0;
   METracks_cov_z0 = 0;
   METracks_cov_z0_d0 = 0;
   METracks_d0 = 0;
   METracks_z0 = 0;
   METracks_d0Sig = 0;
   METracks_eta_err = 0;
   METracks_pt_err = 0;
   METracks_nDoF = 0;
   MM_NumRioOnTrkCB = 0;
   MM_NumRioOnTrkME = 0;
   MM_NumRioOnTrkMS = 0;
   MM_NumRioOnTrkMSOE = 0;
   MM_NumRioOnTrkPR = 0;
   MM_SimDataDeposit = 0;
   MM_SimDataGenParPdgId = 0;
   MM_SimDataGenParPt = 0;
   MM_SimDataGenParVertexPos_x = 0;
   MM_SimDataGenParVertexPos_y = 0;
   MM_SimDataGenParVertexPos_z = 0;
   MM_SimDataGloabalPos_x = 0;
   MM_SimDataGloabalPos_y = 0;
   MM_SimDataGloabalPos_z = 0;
   MM_SimDataLocalPos_x = 0;
   MM_SimDataLocalPos_y = 0;
   MM_SimData_channel = 0;
   MM_SimData_gas_gap = 0;
   MM_SimData_multiplet = 0;
   MM_SimData_stationEta = 0;
   MM_SimData_stationIndex = 0;
   MM_SimData_stationPhi = 0;
   MSOETracks_pt = 0;
   MSOETracks_eta = 0;
   MSOETracks_phi = 0;
   MSOETracks_e = 0;
   MSOETracks_q = 0;
   MSOETracks_chi2 = 0;
   MSOETracks_cov_d0 = 0;
   MSOETracks_cov_phi = 0;
   MSOETracks_cov_phi_d0 = 0;
   MSOETracks_cov_phi_z0 = 0;
   MSOETracks_cov_qOverP = 0;
   MSOETracks_cov_qOverP_d0 = 0;
   MSOETracks_cov_qOverP_phi = 0;
   MSOETracks_cov_qOverP_theta = 0;
   MSOETracks_cov_qOverP_z0 = 0;
   MSOETracks_cov_theta = 0;
   MSOETracks_cov_theta_d0 = 0;
   MSOETracks_cov_theta_phi = 0;
   MSOETracks_cov_theta_z0 = 0;
   MSOETracks_cov_z0 = 0;
   MSOETracks_cov_z0_d0 = 0;
   MSOETracks_d0 = 0;
   MSOETracks_z0 = 0;
   MSOETracks_d0Sig = 0;
   MSOETracks_eta_err = 0;
   MSOETracks_pt_err = 0;
   MSOETracks_nDoF = 0;
   MSTracks_pt = 0;
   MSTracks_eta = 0;
   MSTracks_phi = 0;
   MSTracks_e = 0;
   MSTracks_q = 0;
   MSTracks_chi2 = 0;
   MSTracks_cov_d0 = 0;
   MSTracks_cov_phi = 0;
   MSTracks_cov_phi_d0 = 0;
   MSTracks_cov_phi_z0 = 0;
   MSTracks_cov_qOverP = 0;
   MSTracks_cov_qOverP_d0 = 0;
   MSTracks_cov_qOverP_phi = 0;
   MSTracks_cov_qOverP_theta = 0;
   MSTracks_cov_qOverP_z0 = 0;
   MSTracks_cov_theta = 0;
   MSTracks_cov_theta_d0 = 0;
   MSTracks_cov_theta_phi = 0;
   MSTracks_cov_theta_z0 = 0;
   MSTracks_cov_z0 = 0;
   MSTracks_cov_z0_d0 = 0;
   MSTracks_d0 = 0;
   MSTracks_z0 = 0;
   MSTracks_d0Sig = 0;
   MSTracks_eta_err = 0;
   MSTracks_pt_err = 0;
   MSTracks_nDoF = 0;
   MdtChamHitId_multiLayer = 0;
   MdtChamHitId_stationEta = 0;
   MdtChamHitId_stationIndex = 0;
   MdtChamHitId_stationPhi = 0;
   MdtChamHitId_tube = 0;
   MdtChamHitId_tubeLayer = 0;
   MdtChamHit_Adc = 0;
   MdtChamHit_ChamberLink = 0;
   MdtChamHit_Tdc = 0;
   MdtChamHit_driftR = 0;
   MdtChamHit_driftUncert = 0;
   MdtChamId_multiLayer = 0;
   MdtChamId_stationEta = 0;
   MdtChamId_stationIndex = 0;
   MdtChamId_stationPhi = 0;
   MdtChamId_tube = 0;
   MdtChamId_tubeLayer = 0;
   MdtCham_NTubesPerML = 0;
   MdtCham_hitN = 0;
   MdtCham_matchedCaloTag = 0;
   MdtCham_matchedCaloTag_IPcut = 0;
   MdtCham_matchedMuon = 0;
   MdtCham_matchedMuon_IPcut = 0;
   RPC_NumRioOnTrkCB = 0;
   RPC_NumRioOnTrkME = 0;
   RPC_NumRioOnTrkMS = 0;
   RPC_NumRioOnTrkMSOE = 0;
   RPC_NumRioOnTrkPR = 0;
   extCaloToCham_Identifier_IPCut_multiLayer = 0;
   extCaloToCham_Identifier_IPCut_stationEta = 0;
   extCaloToCham_Identifier_IPCut_stationIndex = 0;
   extCaloToCham_Identifier_IPCut_stationPhi = 0;
   extCaloToCham_Identifier_IPCut_tube = 0;
   extCaloToCham_Identifier_IPCut_tubeLayer = 0;
   extCaloToCham_Identifier_multiLayer = 0;
   extCaloToCham_Identifier_stationEta = 0;
   extCaloToCham_Identifier_stationIndex = 0;
   extCaloToCham_Identifier_stationPhi = 0;
   extCaloToCham_Identifier_tube = 0;
   extCaloToCham_Identifier_tubeLayer = 0;
   mmClusterOnTrackGlobalPos_x = 0;
   mmClusterOnTrackGlobalPos_y = 0;
   mmClusterOnTrackGlobalPos_z = 0;
   mmClusterOnTrackLocalPos_x = 0;
   mmClusterOnTrackLocalPos_y = 0;
   mmError = 0;
   mmLocalStripPosX = 0;
   mmOnTrackError = 0;
   mmOnTrackGlobalPos_x = 0;
   mmOnTrackGlobalPos_y = 0;
   mmOnTrackGlobalPos_z = 0;
   mmOnTrackLocalPos_x = 0;
   mmOnTrackLocalPos_y = 0;
   mmOnTrackNStrips = 0;
   mmOnTrackPullTrack = 0;
   mmOnTrackPullTrackMS = 0;
   mmOnTrackResidualTrack = 0;
   mmOnTrackResidualTrackMS = 0;
   mmOnTrackResidualTruth = 0;
   mmOnTrackStripCharges = 0;
   mmOnTrackStripDriftTimes = 0;
   mmOnTrackStripNumbers = 0;
   mmOnTrack_MuonLink = 0;
   mmOnTrack_channel = 0;
   mmOnTrack_gas_gap = 0;
   mmOnTrack_multiplet = 0;
   mmOnTrack_stationEta = 0;
   mmOnTrack_stationIndex = 0;
   mmOnTrack_stationPhi = 0;
   mmOnTrackuTpcAngle = 0;
   mmOnTrackuTpcChisqProb = 0;
   mmPos_x = 0;
   mmPos_y = 0;
   mmPos_z = 0;
   mmResidualTruth = 0;
   mmStripCharges = 0;
   mmStripDriftTimes = 0;
   mmStripNumbers = 0;
   mmTpcAngle = 0;
   mmTrackStateGlobalPos_x = 0;
   mmTrackStateGlobalPos_y = 0;
   mmTrackStateGlobalPos_z = 0;
   mmTrackStateLocalPos_x = 0;
   mmTrackStateLocalPos_y = 0;
   mmTrackState_ClusterOnTrackLink = 0;
   mmTrackState_MuonLink = 0;
   mmTrackState_channel = 0;
   mmTrackState_closestClusterLink = 0;
   mmTrackState_closestClusterResidual = 0;
   mmTrackState_gas_gap = 0;
   mmTrackState_multiplet = 0;
   mmTrackState_stationEta = 0;
   mmTrackState_stationIndex = 0;
   mmTrackState_stationPhi = 0;
   mm_channel = 0;
   mm_gas_gap = 0;
   mm_multiplet = 0;
   mm_segment_cluster_gas_gap = 0;
   mm_segment_cluster_globpos_x = 0;
   mm_segment_cluster_globpos_y = 0;
   mm_segment_cluster_globpos_z = 0;
   mm_segment_cluster_multilayer = 0;
   mm_segment_clusterprd_residuals_x = 0;
   mm_segment_clusterprd_residuals_y = 0;
   mm_segment_locx_err = 0;
   mm_segment_truth_locx_residuals = 0;
   mm_stationEta = 0;
   mm_stationIndex = 0;
   mm_stationPhi = 0;
   mmmuTpcChi2 = 0;
   muon_segmentLink = 0;
   muon_segment_ChamberIdx = 0;
   muon_segment_ChamberTech = 0;
   muon_segment_EtaStation = 0;
   muon_segment_Mom_x = 0;
   muon_segment_Mom_y = 0;
   muon_segment_Mom_z = 0;
   muon_segment_Pos_x = 0;
   muon_segment_Pos_y = 0;
   muon_segment_Pos_z = 0;
   muon_segment_Sector = 0;
   muon_segment_chi2 = 0;
   muon_segment_nDoF = 0;
   muon_segment_nMM_EtaHits = 0;
   muon_segment_nMM_StereoHits = 0;
   muon_segment_nPrecisionHits = 0;
   muon_segment_nSTGC_EtaHits = 0;
   muon_segment_nSTGC_PhiHits = 0;
   muon_segment_nTrigEtaLayers = 0;
   muon_segment_nTrigPhiLayers = 0;
   muons_pt = 0;
   muons_eta = 0;
   muons_phi = 0;
   muons_e = 0;
   muons_q = 0;
   muons_EnergyLoss = 0;
   muons_EnergyLossSigma = 0;
   muons_FSR_CandidateEnergy = 0;
   muons_IDLink = 0;
   muons_MELink = 0;
   muons_MSLink = 0;
   muons_MSOELink = 0;
   muons_MeasEnergyLoss = 0;
   muons_MeasEnergyLossSigma = 0;
   muons_ParamEnergyLoss = 0;
   muons_ParamEnergyLossSigmaMinus = 0;
   muons_ParamEnergyLossSigmaPlus = 0;
   muons_PtImbalSig = 0;
   muons_SCS = 0;
   muons_SNS = 0;
   muons_allAuthors = 0;
   muons_author = 0;
   muons_chi2 = 0;
   muons_combinedTrackOutBoundsPrecisionHits = 0;
   muons_cov_d0 = 0;
   muons_cov_phi = 0;
   muons_cov_phi_d0 = 0;
   muons_cov_phi_z0 = 0;
   muons_cov_qOverP = 0;
   muons_cov_qOverP_d0 = 0;
   muons_cov_qOverP_phi = 0;
   muons_cov_qOverP_theta = 0;
   muons_cov_qOverP_z0 = 0;
   muons_cov_theta = 0;
   muons_cov_theta_d0 = 0;
   muons_cov_theta_phi = 0;
   muons_cov_theta_z0 = 0;
   muons_cov_z0 = 0;
   muons_cov_z0_d0 = 0;
   muons_cscUnspoiledEtaHits = 0;
   muons_d0 = 0;
   muons_extendedClosePrecisionHits = 0;
   muons_extendedLargeHits = 0;
   muons_extendedLargeHoles = 0;
   muons_extendedOutBoundsPrecisionHits = 0;
   muons_extendedSmallHits = 0;
   muons_extendedSmallHoles = 0;
   muons_innAngle = 0;
   muons_innerClosePrecisionHits = 0;
   muons_innerLargeHits = 0;
   muons_innerLargeHoles = 0;
   muons_innerOutBoundsPrecisionHits = 0;
   muons_innerSmallHits = 0;
   muons_innerSmallHoles = 0;
   muons_isBad = 0;
   muons_isCaloTag = 0;
   muons_isEndcapGoodLayers = 0;
   muons_isSmallGoodSectors = 0;
   muons_midAngle = 0;
   muons_middleClosePrecisionHits = 0;
   muons_middleLargeHits = 0;
   muons_middleLargeHoles = 0;
   muons_middleOutBoundsPrecisionHits = 0;
   muons_middleSmallHits = 0;
   muons_middleSmallHoles = 0;
   muons_msInnerMatchChi2 = 0;
   muons_msInnerMatchDOF = 0;
   muons_msOuterMatchChi2 = 0;
   muons_msOuterMatchDOF = 0;
   muons_numberOfGoodPrecisionLayers = 0;
   muons_numberOfOutliersOnTrack = 0;
   muons_numberOfPhiHoleLayers = 0;
   muons_numberOfPhiLayers = 0;
   muons_numberOfPrecisionHoleLayers = 0;
   muons_numberOfPrecisionLayers = 0;
   muons_numberOfTriggerEtaHoleLayers = 0;
   muons_numberOfTriggerEtaLayers = 0;
   muons_outerClosePrecisionHits = 0;
   muons_outerLargeHits = 0;
   muons_outerLargeHoles = 0;
   muons_outerOutBoundsPrecisionHits = 0;
   muons_outerSmallHits = 0;
   muons_outerSmallHoles = 0;
   muons_passHighPtCuts = 0;
   muons_passIDCuts = 0;
   muons_passIPCuts = 0;
   muons_passLooseCuts = 0;
   muons_passLowPtCuts = 0;
   muons_passMediumCuts = 0;
   muons_primarySector = 0;
   muons_quality = 0;
   muons_secondarySector = 0;
   muons_segmentChi2OverDoF = 0;
   muons_segmentDeltaEta = 0;
   muons_segmentDeltaPhi = 0;
   muons_type = 0;
   muons_z0 = 0;
   muons_d0Sig = 0;
   muons_eta_err = 0;
   muons_pt_err = 0;
   muons_MdtExtChamFromCalo = 0;
   muons_nDoF = 0;
   nMMOnTrack = 0;
   nSTGCOnTrack = 0;
   nSTGCOnTrackPad = 0;
   nSTGCOnTrackStrip = 0;
   nSTGCOnTrackWire = 0;
   rpcAmbiFlag = 0;
   rpcError = 0;
   rpcPos_x = 0;
   rpcPos_y = 0;
   rpcPos_z = 0;
   rpcTime = 0;
   rpcTrigInfo = 0;
   rpc_MuonLink = 0;
   rpc_doubletPhi = 0;
   rpc_doubletR = 0;
   rpc_doubletZ = 0;
   rpc_gasGap = 0;
   rpc_measuresPhi = 0;
   rpc_stationEta = 0;
   rpc_stationIndex = 0;
   rpc_stationPhi = 0;
   rpc_strip = 0;
   sTGC_SimDataGenParPdgId = 0;
   sTGC_SimDataGenParPt = 0;
   sTGC_SimDataGenParVertexPos_x = 0;
   sTGC_SimDataGenParVertexPos_y = 0;
   sTGC_SimDataGenParVertexPos_z = 0;
   sTGC_SimDataGlobalPos_x = 0;
   sTGC_SimDataGlobalPos_y = 0;
   sTGC_SimDataGlobalPos_z = 0;
   sTGC_SimDataLocalPos_x = 0;
   sTGC_SimDataLocalPos_y = 0;
   sTGC_SimData_channel = 0;
   sTGC_SimData_channel_type = 0;
   sTGC_SimData_gas_gap = 0;
   sTGC_SimData_multiplet = 0;
   sTGC_SimData_stationEta = 0;
   sTGC_SimData_stationIndex = 0;
   sTGC_SimData_stationPhi = 0;
   segment_asoc = 0;
   stgcBCID = 0;
   stgcCharge = 0;
   stgcError = 0;
   stgcGlobalPos_x = 0;
   stgcGlobalPos_y = 0;
   stgcGlobalPos_z = 0;
   stgcLocalPos_x = 0;
   stgcLocalPos_y = 0;
   stgcNStrips = 0;
   stgcOnTrackError = 0;
   stgcOnTrackGlobalPos_x = 0;
   stgcOnTrackGlobalPos_y = 0;
   stgcOnTrackGlobalPos_z = 0;
   stgcOnTrackLocalPos_x = 0;
   stgcOnTrackLocalPos_y = 0;
   stgcOnTrackNStrips = 0;
   stgcOnTrackPullTrack = 0;
   stgcOnTrackPullTrackMS = 0;
   stgcOnTrackPullTruth = 0;
   stgcOnTrackResidualTrack = 0;
   stgcOnTrackResidualTrackMS = 0;
   stgcOnTrackResidualTruth = 0;
   stgcOnTrackStripCharges = 0;
   stgcOnTrackStripDriftTimes = 0;
   stgcOnTrackStripNumbers = 0;
   stgcOnTrack_MuonLink = 0;
   stgcOnTrack_channel = 0;
   stgcOnTrack_channel_type = 0;
   stgcOnTrack_gas_gap = 0;
   stgcOnTrack_multiplet = 0;
   stgcOnTrack_stationEta = 0;
   stgcOnTrack_stationIndex = 0;
   stgcOnTrack_stationPhi = 0;
   stgcPadCorners_x = 0;
   stgcPadCorners_y = 0;
   stgcStripChannel = 0;
   stgcStripCharge = 0;
   stgcStripTime = 0;
   stgcTime = 0;
   stgcTrackStateGlobalPos_x = 0;
   stgcTrackStateGlobalPos_y = 0;
   stgcTrackStateGlobalPos_z = 0;
   stgcTrackStateLocalPos_x = 0;
   stgcTrackStateLocalPos_y = 0;
   stgcTrackState_ClusterOnTrackLink = 0;
   stgcTrackState_MuonLink = 0;
   stgcTrackState_channel = 0;
   stgcTrackState_channel_type = 0;
   stgcTrackState_closestClusterLink = 0;
   stgcTrackState_closestClusterResidualX = 0;
   stgcTrackState_closestClusterResidualY = 0;
   stgcTrackState_gas_gap = 0;
   stgcTrackState_multiplet = 0;
   stgcTrackState_padEta = 0;
   stgcTrackState_padPhi = 0;
   stgcTrackState_stationEta = 0;
   stgcTrackState_stationIndex = 0;
   stgcTrackState_stationPhi = 0;
   stgc_channel = 0;
   stgc_channel_type = 0;
   stgc_gas_gap = 0;
   stgc_multiplet = 0;
   stgc_segment_cluster_channel_type = 0;
   stgc_segment_cluster_gas_gap = 0;
   stgc_segment_cluster_globpos_x = 0;
   stgc_segment_cluster_globpos_y = 0;
   stgc_segment_cluster_globpos_z = 0;
   stgc_segment_cluster_multilayer = 0;
   stgc_segment_cluster_theta = 0;
   stgc_segment_clusterprd_residuals_x = 0;
   stgc_segment_clusterprd_residuals_y = 0;
   stgc_segment_locx_err = 0;
   stgc_segment_locy_err = 0;
   stgc_segment_truth_locx_residuals = 0;
   stgc_segment_truth_locy_residuals = 0;
   stgc_stationEta = 0;
   stgc_stationIndex = 0;
   stgc_stationPhi = 0;
   unassoc_segment_ChamberIdx = 0;
   unassoc_segment_ChamberTech = 0;
   unassoc_segment_EtaStation = 0;
   unassoc_segment_Mom_x = 0;
   unassoc_segment_Mom_y = 0;
   unassoc_segment_Mom_z = 0;
   unassoc_segment_Pos_x = 0;
   unassoc_segment_Pos_y = 0;
   unassoc_segment_Pos_z = 0;
   unassoc_segment_Sector = 0;
   unassoc_segment_chi2 = 0;
   unassoc_segment_nDoF = 0;
   unassoc_segment_nMM_EtaHits = 0;
   unassoc_segment_nMM_StereoHits = 0;
   unassoc_segment_nPrecisionHits = 0;
   unassoc_segment_nSTGC_EtaHits = 0;
   unassoc_segment_nSTGC_PhiHits = 0;
   unassoc_segment_nTrigEtaLayers = 0;
   unassoc_segment_nTrigPhiLayers = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("IDTracks_pt", &IDTracks_pt, &b_IDTracks_pt);
   fChain->SetBranchAddress("IDTracks_eta", &IDTracks_eta, &b_IDTracks_eta);
   fChain->SetBranchAddress("IDTracks_phi", &IDTracks_phi, &b_IDTracks_phi);
   fChain->SetBranchAddress("IDTracks_e", &IDTracks_e, &b_IDTracks_e);
   fChain->SetBranchAddress("IDTracks_q", &IDTracks_q, &b_IDTracks_q);
   fChain->SetBranchAddress("IDTracks_chi2", &IDTracks_chi2, &b_IDTracks_chi2);
   fChain->SetBranchAddress("IDTracks_cov_d0", &IDTracks_cov_d0, &b_IDTracks_cov_d0);
   fChain->SetBranchAddress("IDTracks_cov_phi", &IDTracks_cov_phi, &b_IDTracks_cov_phi);
   fChain->SetBranchAddress("IDTracks_cov_phi_d0", &IDTracks_cov_phi_d0, &b_IDTracks_cov_phi_d0);
   fChain->SetBranchAddress("IDTracks_cov_phi_z0", &IDTracks_cov_phi_z0, &b_IDTracks_cov_phi_z0);
   fChain->SetBranchAddress("IDTracks_cov_qOverP", &IDTracks_cov_qOverP, &b_IDTracks_cov_qOverP);
   fChain->SetBranchAddress("IDTracks_cov_qOverP_d0", &IDTracks_cov_qOverP_d0, &b_IDTracks_cov_qOverP_d0);
   fChain->SetBranchAddress("IDTracks_cov_qOverP_phi", &IDTracks_cov_qOverP_phi, &b_IDTracks_cov_qOverP_phi);
   fChain->SetBranchAddress("IDTracks_cov_qOverP_theta", &IDTracks_cov_qOverP_theta, &b_IDTracks_cov_qOverP_theta);
   fChain->SetBranchAddress("IDTracks_cov_qOverP_z0", &IDTracks_cov_qOverP_z0, &b_IDTracks_cov_qOverP_z0);
   fChain->SetBranchAddress("IDTracks_cov_theta", &IDTracks_cov_theta, &b_IDTracks_cov_theta);
   fChain->SetBranchAddress("IDTracks_cov_theta_d0", &IDTracks_cov_theta_d0, &b_IDTracks_cov_theta_d0);
   fChain->SetBranchAddress("IDTracks_cov_theta_phi", &IDTracks_cov_theta_phi, &b_IDTracks_cov_theta_phi);
   fChain->SetBranchAddress("IDTracks_cov_theta_z0", &IDTracks_cov_theta_z0, &b_IDTracks_cov_theta_z0);
   fChain->SetBranchAddress("IDTracks_cov_z0", &IDTracks_cov_z0, &b_IDTracks_cov_z0);
   fChain->SetBranchAddress("IDTracks_cov_z0_d0", &IDTracks_cov_z0_d0, &b_IDTracks_cov_z0_d0);
   fChain->SetBranchAddress("IDTracks_d0", &IDTracks_d0, &b_IDTracks_d0);
   fChain->SetBranchAddress("IDTracks_z0", &IDTracks_z0, &b_IDTracks_z0);
   fChain->SetBranchAddress("IDTracks_d0Sig", &IDTracks_d0Sig, &b_IDTracks_d0Sig);
   fChain->SetBranchAddress("IDTracks_eta_err", &IDTracks_eta_err, &b_IDTracks_eta_err);
   fChain->SetBranchAddress("IDTracks_pt_err", &IDTracks_pt_err, &b_IDTracks_pt_err);
   fChain->SetBranchAddress("IDTracks_nDoF", &IDTracks_nDoF, &b_IDTracks_nDoF);
   fChain->SetBranchAddress("METracks_pt", &METracks_pt, &b_METracks_pt);
   fChain->SetBranchAddress("METracks_eta", &METracks_eta, &b_METracks_eta);
   fChain->SetBranchAddress("METracks_phi", &METracks_phi, &b_METracks_phi);
   fChain->SetBranchAddress("METracks_e", &METracks_e, &b_METracks_e);
   fChain->SetBranchAddress("METracks_q", &METracks_q, &b_METracks_q);
   fChain->SetBranchAddress("METracks_chi2", &METracks_chi2, &b_METracks_chi2);
   fChain->SetBranchAddress("METracks_cov_d0", &METracks_cov_d0, &b_METracks_cov_d0);
   fChain->SetBranchAddress("METracks_cov_phi", &METracks_cov_phi, &b_METracks_cov_phi);
   fChain->SetBranchAddress("METracks_cov_phi_d0", &METracks_cov_phi_d0, &b_METracks_cov_phi_d0);
   fChain->SetBranchAddress("METracks_cov_phi_z0", &METracks_cov_phi_z0, &b_METracks_cov_phi_z0);
   fChain->SetBranchAddress("METracks_cov_qOverP", &METracks_cov_qOverP, &b_METracks_cov_qOverP);
   fChain->SetBranchAddress("METracks_cov_qOverP_d0", &METracks_cov_qOverP_d0, &b_METracks_cov_qOverP_d0);
   fChain->SetBranchAddress("METracks_cov_qOverP_phi", &METracks_cov_qOverP_phi, &b_METracks_cov_qOverP_phi);
   fChain->SetBranchAddress("METracks_cov_qOverP_theta", &METracks_cov_qOverP_theta, &b_METracks_cov_qOverP_theta);
   fChain->SetBranchAddress("METracks_cov_qOverP_z0", &METracks_cov_qOverP_z0, &b_METracks_cov_qOverP_z0);
   fChain->SetBranchAddress("METracks_cov_theta", &METracks_cov_theta, &b_METracks_cov_theta);
   fChain->SetBranchAddress("METracks_cov_theta_d0", &METracks_cov_theta_d0, &b_METracks_cov_theta_d0);
   fChain->SetBranchAddress("METracks_cov_theta_phi", &METracks_cov_theta_phi, &b_METracks_cov_theta_phi);
   fChain->SetBranchAddress("METracks_cov_theta_z0", &METracks_cov_theta_z0, &b_METracks_cov_theta_z0);
   fChain->SetBranchAddress("METracks_cov_z0", &METracks_cov_z0, &b_METracks_cov_z0);
   fChain->SetBranchAddress("METracks_cov_z0_d0", &METracks_cov_z0_d0, &b_METracks_cov_z0_d0);
   fChain->SetBranchAddress("METracks_d0", &METracks_d0, &b_METracks_d0);
   fChain->SetBranchAddress("METracks_z0", &METracks_z0, &b_METracks_z0);
   fChain->SetBranchAddress("METracks_d0Sig", &METracks_d0Sig, &b_METracks_d0Sig);
   fChain->SetBranchAddress("METracks_eta_err", &METracks_eta_err, &b_METracks_eta_err);
   fChain->SetBranchAddress("METracks_pt_err", &METracks_pt_err, &b_METracks_pt_err);
   fChain->SetBranchAddress("METracks_nDoF", &METracks_nDoF, &b_METracks_nDoF);
   fChain->SetBranchAddress("MM_NumRioOnTrkCB", &MM_NumRioOnTrkCB, &b_MM_NumRioOnTrkCB);
   fChain->SetBranchAddress("MM_NumRioOnTrkME", &MM_NumRioOnTrkME, &b_MM_NumRioOnTrkME);
   fChain->SetBranchAddress("MM_NumRioOnTrkMS", &MM_NumRioOnTrkMS, &b_MM_NumRioOnTrkMS);
   fChain->SetBranchAddress("MM_NumRioOnTrkMSOE", &MM_NumRioOnTrkMSOE, &b_MM_NumRioOnTrkMSOE);
   fChain->SetBranchAddress("MM_NumRioOnTrkPR", &MM_NumRioOnTrkPR, &b_MM_NumRioOnTrkPR);
   fChain->SetBranchAddress("MM_SimDataDeposit", &MM_SimDataDeposit, &b_MM_SimDataDeposit);
   fChain->SetBranchAddress("MM_SimDataGenParPdgId", &MM_SimDataGenParPdgId, &b_MM_SimDataGenParPdgId);
   fChain->SetBranchAddress("MM_SimDataGenParPt", &MM_SimDataGenParPt, &b_MM_SimDataGenParPt);
   fChain->SetBranchAddress("MM_SimDataGenParVertexPos_x", &MM_SimDataGenParVertexPos_x, &b_MM_SimDataGenParVertexPos_x);
   fChain->SetBranchAddress("MM_SimDataGenParVertexPos_y", &MM_SimDataGenParVertexPos_y, &b_MM_SimDataGenParVertexPos_y);
   fChain->SetBranchAddress("MM_SimDataGenParVertexPos_z", &MM_SimDataGenParVertexPos_z, &b_MM_SimDataGenParVertexPos_z);
   fChain->SetBranchAddress("MM_SimDataGloabalPos_x", &MM_SimDataGloabalPos_x, &b_MM_SimDataGloabalPos_x);
   fChain->SetBranchAddress("MM_SimDataGloabalPos_y", &MM_SimDataGloabalPos_y, &b_MM_SimDataGloabalPos_y);
   fChain->SetBranchAddress("MM_SimDataGloabalPos_z", &MM_SimDataGloabalPos_z, &b_MM_SimDataGloabalPos_z);
   fChain->SetBranchAddress("MM_SimDataLocalPos_x", &MM_SimDataLocalPos_x, &b_MM_SimDataLocalPos_x);
   fChain->SetBranchAddress("MM_SimDataLocalPos_y", &MM_SimDataLocalPos_y, &b_MM_SimDataLocalPos_y);
   fChain->SetBranchAddress("MM_SimData_channel", &MM_SimData_channel, &b_MM_SimData_channel);
   fChain->SetBranchAddress("MM_SimData_gas_gap", &MM_SimData_gas_gap, &b_MM_SimData_gas_gap);
   fChain->SetBranchAddress("MM_SimData_multiplet", &MM_SimData_multiplet, &b_MM_SimData_multiplet);
   fChain->SetBranchAddress("MM_SimData_stationEta", &MM_SimData_stationEta, &b_MM_SimData_stationEta);
   fChain->SetBranchAddress("MM_SimData_stationIndex", &MM_SimData_stationIndex, &b_MM_SimData_stationIndex);
   fChain->SetBranchAddress("MM_SimData_stationPhi", &MM_SimData_stationPhi, &b_MM_SimData_stationPhi);
   fChain->SetBranchAddress("MM_nDeltaElectrons", &MM_nDeltaElectrons, &b_MM_nDeltaElectrons);
   fChain->SetBranchAddress("MM_nMuonSimData", &MM_nMuonSimData, &b_MM_nMuonSimData);
   fChain->SetBranchAddress("MSOETracks_pt", &MSOETracks_pt, &b_MSOETracks_pt);
   fChain->SetBranchAddress("MSOETracks_eta", &MSOETracks_eta, &b_MSOETracks_eta);
   fChain->SetBranchAddress("MSOETracks_phi", &MSOETracks_phi, &b_MSOETracks_phi);
   fChain->SetBranchAddress("MSOETracks_e", &MSOETracks_e, &b_MSOETracks_e);
   fChain->SetBranchAddress("MSOETracks_q", &MSOETracks_q, &b_MSOETracks_q);
   fChain->SetBranchAddress("MSOETracks_chi2", &MSOETracks_chi2, &b_MSOETracks_chi2);
   fChain->SetBranchAddress("MSOETracks_cov_d0", &MSOETracks_cov_d0, &b_MSOETracks_cov_d0);
   fChain->SetBranchAddress("MSOETracks_cov_phi", &MSOETracks_cov_phi, &b_MSOETracks_cov_phi);
   fChain->SetBranchAddress("MSOETracks_cov_phi_d0", &MSOETracks_cov_phi_d0, &b_MSOETracks_cov_phi_d0);
   fChain->SetBranchAddress("MSOETracks_cov_phi_z0", &MSOETracks_cov_phi_z0, &b_MSOETracks_cov_phi_z0);
   fChain->SetBranchAddress("MSOETracks_cov_qOverP", &MSOETracks_cov_qOverP, &b_MSOETracks_cov_qOverP);
   fChain->SetBranchAddress("MSOETracks_cov_qOverP_d0", &MSOETracks_cov_qOverP_d0, &b_MSOETracks_cov_qOverP_d0);
   fChain->SetBranchAddress("MSOETracks_cov_qOverP_phi", &MSOETracks_cov_qOverP_phi, &b_MSOETracks_cov_qOverP_phi);
   fChain->SetBranchAddress("MSOETracks_cov_qOverP_theta", &MSOETracks_cov_qOverP_theta, &b_MSOETracks_cov_qOverP_theta);
   fChain->SetBranchAddress("MSOETracks_cov_qOverP_z0", &MSOETracks_cov_qOverP_z0, &b_MSOETracks_cov_qOverP_z0);
   fChain->SetBranchAddress("MSOETracks_cov_theta", &MSOETracks_cov_theta, &b_MSOETracks_cov_theta);
   fChain->SetBranchAddress("MSOETracks_cov_theta_d0", &MSOETracks_cov_theta_d0, &b_MSOETracks_cov_theta_d0);
   fChain->SetBranchAddress("MSOETracks_cov_theta_phi", &MSOETracks_cov_theta_phi, &b_MSOETracks_cov_theta_phi);
   fChain->SetBranchAddress("MSOETracks_cov_theta_z0", &MSOETracks_cov_theta_z0, &b_MSOETracks_cov_theta_z0);
   fChain->SetBranchAddress("MSOETracks_cov_z0", &MSOETracks_cov_z0, &b_MSOETracks_cov_z0);
   fChain->SetBranchAddress("MSOETracks_cov_z0_d0", &MSOETracks_cov_z0_d0, &b_MSOETracks_cov_z0_d0);
   fChain->SetBranchAddress("MSOETracks_d0", &MSOETracks_d0, &b_MSOETracks_d0);
   fChain->SetBranchAddress("MSOETracks_z0", &MSOETracks_z0, &b_MSOETracks_z0);
   fChain->SetBranchAddress("MSOETracks_d0Sig", &MSOETracks_d0Sig, &b_MSOETracks_d0Sig);
   fChain->SetBranchAddress("MSOETracks_eta_err", &MSOETracks_eta_err, &b_MSOETracks_eta_err);
   fChain->SetBranchAddress("MSOETracks_pt_err", &MSOETracks_pt_err, &b_MSOETracks_pt_err);
   fChain->SetBranchAddress("MSOETracks_nDoF", &MSOETracks_nDoF, &b_MSOETracks_nDoF);
   fChain->SetBranchAddress("MSTracks_pt", &MSTracks_pt, &b_MSTracks_pt);
   fChain->SetBranchAddress("MSTracks_eta", &MSTracks_eta, &b_MSTracks_eta);
   fChain->SetBranchAddress("MSTracks_phi", &MSTracks_phi, &b_MSTracks_phi);
   fChain->SetBranchAddress("MSTracks_e", &MSTracks_e, &b_MSTracks_e);
   fChain->SetBranchAddress("MSTracks_q", &MSTracks_q, &b_MSTracks_q);
   fChain->SetBranchAddress("MSTracks_chi2", &MSTracks_chi2, &b_MSTracks_chi2);
   fChain->SetBranchAddress("MSTracks_cov_d0", &MSTracks_cov_d0, &b_MSTracks_cov_d0);
   fChain->SetBranchAddress("MSTracks_cov_phi", &MSTracks_cov_phi, &b_MSTracks_cov_phi);
   fChain->SetBranchAddress("MSTracks_cov_phi_d0", &MSTracks_cov_phi_d0, &b_MSTracks_cov_phi_d0);
   fChain->SetBranchAddress("MSTracks_cov_phi_z0", &MSTracks_cov_phi_z0, &b_MSTracks_cov_phi_z0);
   fChain->SetBranchAddress("MSTracks_cov_qOverP", &MSTracks_cov_qOverP, &b_MSTracks_cov_qOverP);
   fChain->SetBranchAddress("MSTracks_cov_qOverP_d0", &MSTracks_cov_qOverP_d0, &b_MSTracks_cov_qOverP_d0);
   fChain->SetBranchAddress("MSTracks_cov_qOverP_phi", &MSTracks_cov_qOverP_phi, &b_MSTracks_cov_qOverP_phi);
   fChain->SetBranchAddress("MSTracks_cov_qOverP_theta", &MSTracks_cov_qOverP_theta, &b_MSTracks_cov_qOverP_theta);
   fChain->SetBranchAddress("MSTracks_cov_qOverP_z0", &MSTracks_cov_qOverP_z0, &b_MSTracks_cov_qOverP_z0);
   fChain->SetBranchAddress("MSTracks_cov_theta", &MSTracks_cov_theta, &b_MSTracks_cov_theta);
   fChain->SetBranchAddress("MSTracks_cov_theta_d0", &MSTracks_cov_theta_d0, &b_MSTracks_cov_theta_d0);
   fChain->SetBranchAddress("MSTracks_cov_theta_phi", &MSTracks_cov_theta_phi, &b_MSTracks_cov_theta_phi);
   fChain->SetBranchAddress("MSTracks_cov_theta_z0", &MSTracks_cov_theta_z0, &b_MSTracks_cov_theta_z0);
   fChain->SetBranchAddress("MSTracks_cov_z0", &MSTracks_cov_z0, &b_MSTracks_cov_z0);
   fChain->SetBranchAddress("MSTracks_cov_z0_d0", &MSTracks_cov_z0_d0, &b_MSTracks_cov_z0_d0);
   fChain->SetBranchAddress("MSTracks_d0", &MSTracks_d0, &b_MSTracks_d0);
   fChain->SetBranchAddress("MSTracks_z0", &MSTracks_z0, &b_MSTracks_z0);
   fChain->SetBranchAddress("MSTracks_d0Sig", &MSTracks_d0Sig, &b_MSTracks_d0Sig);
   fChain->SetBranchAddress("MSTracks_eta_err", &MSTracks_eta_err, &b_MSTracks_eta_err);
   fChain->SetBranchAddress("MSTracks_pt_err", &MSTracks_pt_err, &b_MSTracks_pt_err);
   fChain->SetBranchAddress("MSTracks_nDoF", &MSTracks_nDoF, &b_MSTracks_nDoF);
   fChain->SetBranchAddress("MdtChamHitId_multiLayer", &MdtChamHitId_multiLayer, &b_MdtChamHitId_multiLayer);
   fChain->SetBranchAddress("MdtChamHitId_stationEta", &MdtChamHitId_stationEta, &b_MdtChamHitId_stationEta);
   fChain->SetBranchAddress("MdtChamHitId_stationIndex", &MdtChamHitId_stationIndex, &b_MdtChamHitId_stationIndex);
   fChain->SetBranchAddress("MdtChamHitId_stationPhi", &MdtChamHitId_stationPhi, &b_MdtChamHitId_stationPhi);
   fChain->SetBranchAddress("MdtChamHitId_tube", &MdtChamHitId_tube, &b_MdtChamHitId_tube);
   fChain->SetBranchAddress("MdtChamHitId_tubeLayer", &MdtChamHitId_tubeLayer, &b_MdtChamHitId_tubeLayer);
   fChain->SetBranchAddress("MdtChamHit_Adc", &MdtChamHit_Adc, &b_MdtChamHit_Adc);
   fChain->SetBranchAddress("MdtChamHit_ChamberLink", &MdtChamHit_ChamberLink, &b_MdtChamHit_ChamberLink);
   fChain->SetBranchAddress("MdtChamHit_Tdc", &MdtChamHit_Tdc, &b_MdtChamHit_Tdc);
   fChain->SetBranchAddress("MdtChamHit_driftR", &MdtChamHit_driftR, &b_MdtChamHit_driftR);
   fChain->SetBranchAddress("MdtChamHit_driftUncert", &MdtChamHit_driftUncert, &b_MdtChamHit_driftUncert);
   fChain->SetBranchAddress("MdtChamId_multiLayer", &MdtChamId_multiLayer, &b_MdtChamId_multiLayer);
   fChain->SetBranchAddress("MdtChamId_stationEta", &MdtChamId_stationEta, &b_MdtChamId_stationEta);
   fChain->SetBranchAddress("MdtChamId_stationIndex", &MdtChamId_stationIndex, &b_MdtChamId_stationIndex);
   fChain->SetBranchAddress("MdtChamId_stationPhi", &MdtChamId_stationPhi, &b_MdtChamId_stationPhi);
   fChain->SetBranchAddress("MdtChamId_tube", &MdtChamId_tube, &b_MdtChamId_tube);
   fChain->SetBranchAddress("MdtChamId_tubeLayer", &MdtChamId_tubeLayer, &b_MdtChamId_tubeLayer);
   fChain->SetBranchAddress("MdtCham_NTubesPerML", &MdtCham_NTubesPerML, &b_MdtCham_NTubesPerML);
   fChain->SetBranchAddress("MdtCham_hitN", &MdtCham_hitN, &b_MdtCham_hitN);
   fChain->SetBranchAddress("MdtCham_matchedCaloTag", &MdtCham_matchedCaloTag, &b_MdtCham_matchedCaloTag);
   fChain->SetBranchAddress("MdtCham_matchedCaloTag_IPcut", &MdtCham_matchedCaloTag_IPcut, &b_MdtCham_matchedCaloTag_IPcut);
   fChain->SetBranchAddress("MdtCham_matchedMuon", &MdtCham_matchedMuon, &b_MdtCham_matchedMuon);
   fChain->SetBranchAddress("MdtCham_matchedMuon_IPcut", &MdtCham_matchedMuon_IPcut, &b_MdtCham_matchedMuon_IPcut);
   fChain->SetBranchAddress("RPC_NumRioOnTrkCB", &RPC_NumRioOnTrkCB, &b_RPC_NumRioOnTrkCB);
   fChain->SetBranchAddress("RPC_NumRioOnTrkME", &RPC_NumRioOnTrkME, &b_RPC_NumRioOnTrkME);
   fChain->SetBranchAddress("RPC_NumRioOnTrkMS", &RPC_NumRioOnTrkMS, &b_RPC_NumRioOnTrkMS);
   fChain->SetBranchAddress("RPC_NumRioOnTrkMSOE", &RPC_NumRioOnTrkMSOE, &b_RPC_NumRioOnTrkMSOE);
   fChain->SetBranchAddress("RPC_NumRioOnTrkPR", &RPC_NumRioOnTrkPR, &b_RPC_NumRioOnTrkPR);
   fChain->SetBranchAddress("avgIntPerCrossing", &avgIntPerCrossing, &b_avgIntPerCrossing);
   fChain->SetBranchAddress("cham_N", &cham_N, &b_cham_N);
   fChain->SetBranchAddress("evtNumber", &evtNumber, &b_evtNumber);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_multiLayer", &extCaloToCham_Identifier_IPCut_multiLayer, &b_extCaloToCham_Identifier_IPCut_multiLayer);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_stationEta", &extCaloToCham_Identifier_IPCut_stationEta, &b_extCaloToCham_Identifier_IPCut_stationEta);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_stationIndex", &extCaloToCham_Identifier_IPCut_stationIndex, &b_extCaloToCham_Identifier_IPCut_stationIndex);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_stationPhi", &extCaloToCham_Identifier_IPCut_stationPhi, &b_extCaloToCham_Identifier_IPCut_stationPhi);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_tube", &extCaloToCham_Identifier_IPCut_tube, &b_extCaloToCham_Identifier_IPCut_tube);
   fChain->SetBranchAddress("extCaloToCham_Identifier_IPCut_tubeLayer", &extCaloToCham_Identifier_IPCut_tubeLayer, &b_extCaloToCham_Identifier_IPCut_tubeLayer);
   fChain->SetBranchAddress("extCaloToCham_Identifier_multiLayer", &extCaloToCham_Identifier_multiLayer, &b_extCaloToCham_Identifier_multiLayer);
   fChain->SetBranchAddress("extCaloToCham_Identifier_stationEta", &extCaloToCham_Identifier_stationEta, &b_extCaloToCham_Identifier_stationEta);
   fChain->SetBranchAddress("extCaloToCham_Identifier_stationIndex", &extCaloToCham_Identifier_stationIndex, &b_extCaloToCham_Identifier_stationIndex);
   fChain->SetBranchAddress("extCaloToCham_Identifier_stationPhi", &extCaloToCham_Identifier_stationPhi, &b_extCaloToCham_Identifier_stationPhi);
   fChain->SetBranchAddress("extCaloToCham_Identifier_tube", &extCaloToCham_Identifier_tube, &b_extCaloToCham_Identifier_tube);
   fChain->SetBranchAddress("extCaloToCham_Identifier_tubeLayer", &extCaloToCham_Identifier_tubeLayer, &b_extCaloToCham_Identifier_tubeLayer);
   fChain->SetBranchAddress("extCaloToCham_N", &extCaloToCham_N, &b_extCaloToCham_N);
   fChain->SetBranchAddress("extCaloToCham_N_IPCut", &extCaloToCham_N_IPCut, &b_extCaloToCham_N_IPCut);
   fChain->SetBranchAddress("lbNumber", &lbNumber, &b_lbNumber);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("mmClusterOnTrackGlobalPos_x", &mmClusterOnTrackGlobalPos_x, &b_mmClusterOnTrackGlobalPos_x);
   fChain->SetBranchAddress("mmClusterOnTrackGlobalPos_y", &mmClusterOnTrackGlobalPos_y, &b_mmClusterOnTrackGlobalPos_y);
   fChain->SetBranchAddress("mmClusterOnTrackGlobalPos_z", &mmClusterOnTrackGlobalPos_z, &b_mmClusterOnTrackGlobalPos_z);
   fChain->SetBranchAddress("mmClusterOnTrackLocalPos_x", &mmClusterOnTrackLocalPos_x, &b_mmClusterOnTrackLocalPos_x);
   fChain->SetBranchAddress("mmClusterOnTrackLocalPos_y", &mmClusterOnTrackLocalPos_y, &b_mmClusterOnTrackLocalPos_y);
   fChain->SetBranchAddress("mmError", &mmError, &b_mmError);
   fChain->SetBranchAddress("mmLocalStripPosX", &mmLocalStripPosX, &b_mmLocalStripPosX);
   fChain->SetBranchAddress("mmOnTrackError", &mmOnTrackError, &b_mmOnTrackError);
   fChain->SetBranchAddress("mmOnTrackGlobalPos_x", &mmOnTrackGlobalPos_x, &b_mmOnTrackGlobalPos_x);
   fChain->SetBranchAddress("mmOnTrackGlobalPos_y", &mmOnTrackGlobalPos_y, &b_mmOnTrackGlobalPos_y);
   fChain->SetBranchAddress("mmOnTrackGlobalPos_z", &mmOnTrackGlobalPos_z, &b_mmOnTrackGlobalPos_z);
   fChain->SetBranchAddress("mmOnTrackLocalPos_x", &mmOnTrackLocalPos_x, &b_mmOnTrackLocalPos_x);
   fChain->SetBranchAddress("mmOnTrackLocalPos_y", &mmOnTrackLocalPos_y, &b_mmOnTrackLocalPos_y);
   fChain->SetBranchAddress("mmOnTrackNStrips", &mmOnTrackNStrips, &b_mmOnTrackNStrips);
   fChain->SetBranchAddress("mmOnTrackPullTrack", &mmOnTrackPullTrack, &b_mmOnTrackPullTrack);
   fChain->SetBranchAddress("mmOnTrackPullTrackMS", &mmOnTrackPullTrackMS, &b_mmOnTrackPullTrackMS);
   fChain->SetBranchAddress("mmOnTrackResidualTrack", &mmOnTrackResidualTrack, &b_mmOnTrackResidualTrack);
   fChain->SetBranchAddress("mmOnTrackResidualTrackMS", &mmOnTrackResidualTrackMS, &b_mmOnTrackResidualTrackMS);
   fChain->SetBranchAddress("mmOnTrackResidualTruth", &mmOnTrackResidualTruth, &b_mmOnTrackResidualTruth);
   fChain->SetBranchAddress("mmOnTrackStripCharges", &mmOnTrackStripCharges, &b_mmOnTrackStripCharges);
   fChain->SetBranchAddress("mmOnTrackStripDriftTimes", &mmOnTrackStripDriftTimes, &b_mmOnTrackStripDriftTimes);
   fChain->SetBranchAddress("mmOnTrackStripNumbers", &mmOnTrackStripNumbers, &b_mmOnTrackStripNumbers);
   fChain->SetBranchAddress("mmOnTrack_MuonLink", &mmOnTrack_MuonLink, &b_mmOnTrack_MuonLink);
   fChain->SetBranchAddress("mmOnTrack_channel", &mmOnTrack_channel, &b_mmOnTrack_channel);
   fChain->SetBranchAddress("mmOnTrack_gas_gap", &mmOnTrack_gas_gap, &b_mmOnTrack_gas_gap);
   fChain->SetBranchAddress("mmOnTrack_multiplet", &mmOnTrack_multiplet, &b_mmOnTrack_multiplet);
   fChain->SetBranchAddress("mmOnTrack_stationEta", &mmOnTrack_stationEta, &b_mmOnTrack_stationEta);
   fChain->SetBranchAddress("mmOnTrack_stationIndex", &mmOnTrack_stationIndex, &b_mmOnTrack_stationIndex);
   fChain->SetBranchAddress("mmOnTrack_stationPhi", &mmOnTrack_stationPhi, &b_mmOnTrack_stationPhi);
   fChain->SetBranchAddress("mmOnTrackuTpcAngle", &mmOnTrackuTpcAngle, &b_mmOnTrackuTpcAngle);
   fChain->SetBranchAddress("mmOnTrackuTpcChisqProb", &mmOnTrackuTpcChisqProb, &b_mmOnTrackuTpcChisqProb);
   fChain->SetBranchAddress("mmPos_x", &mmPos_x, &b_mmPos_x);
   fChain->SetBranchAddress("mmPos_y", &mmPos_y, &b_mmPos_y);
   fChain->SetBranchAddress("mmPos_z", &mmPos_z, &b_mmPos_z);
   fChain->SetBranchAddress("mmResidualTruth", &mmResidualTruth, &b_mmResidualTruth);
   fChain->SetBranchAddress("mmStripCharges", &mmStripCharges, &b_mmStripCharges);
   fChain->SetBranchAddress("mmStripDriftTimes", &mmStripDriftTimes, &b_mmStripDriftTimes);
   fChain->SetBranchAddress("mmStripNumbers", &mmStripNumbers, &b_mmStripNumbers);
   fChain->SetBranchAddress("mmTpcAngle", &mmTpcAngle, &b_mmTpcAngle);
   fChain->SetBranchAddress("mmTrackStateGlobalPos_x", &mmTrackStateGlobalPos_x, &b_mmTrackStateGlobalPos_x);
   fChain->SetBranchAddress("mmTrackStateGlobalPos_y", &mmTrackStateGlobalPos_y, &b_mmTrackStateGlobalPos_y);
   fChain->SetBranchAddress("mmTrackStateGlobalPos_z", &mmTrackStateGlobalPos_z, &b_mmTrackStateGlobalPos_z);
   fChain->SetBranchAddress("mmTrackStateLocalPos_x", &mmTrackStateLocalPos_x, &b_mmTrackStateLocalPos_x);
   fChain->SetBranchAddress("mmTrackStateLocalPos_y", &mmTrackStateLocalPos_y, &b_mmTrackStateLocalPos_y);
   fChain->SetBranchAddress("mmTrackState_ClusterOnTrackLink", &mmTrackState_ClusterOnTrackLink, &b_mmTrackState_ClusterOnTrackLink);
   fChain->SetBranchAddress("mmTrackState_MuonLink", &mmTrackState_MuonLink, &b_mmTrackState_MuonLink);
   fChain->SetBranchAddress("mmTrackState_channel", &mmTrackState_channel, &b_mmTrackState_channel);
   fChain->SetBranchAddress("mmTrackState_closestClusterLink", &mmTrackState_closestClusterLink, &b_mmTrackState_closestClusterLink);
   fChain->SetBranchAddress("mmTrackState_closestClusterResidual", &mmTrackState_closestClusterResidual, &b_mmTrackState_closestClusterResidual);
   fChain->SetBranchAddress("mmTrackState_gas_gap", &mmTrackState_gas_gap, &b_mmTrackState_gas_gap);
   fChain->SetBranchAddress("mmTrackState_multiplet", &mmTrackState_multiplet, &b_mmTrackState_multiplet);
   fChain->SetBranchAddress("mmTrackState_stationEta", &mmTrackState_stationEta, &b_mmTrackState_stationEta);
   fChain->SetBranchAddress("mmTrackState_stationIndex", &mmTrackState_stationIndex, &b_mmTrackState_stationIndex);
   fChain->SetBranchAddress("mmTrackState_stationPhi", &mmTrackState_stationPhi, &b_mmTrackState_stationPhi);
   fChain->SetBranchAddress("mm_channel", &mm_channel, &b_mm_channel);
   fChain->SetBranchAddress("mm_gas_gap", &mm_gas_gap, &b_mm_gas_gap);
   fChain->SetBranchAddress("mm_multiplet", &mm_multiplet, &b_mm_multiplet);
   fChain->SetBranchAddress("mm_segment_cluster_gas_gap", &mm_segment_cluster_gas_gap, &b_mm_segment_cluster_gas_gap);
   fChain->SetBranchAddress("mm_segment_cluster_globpos_x", &mm_segment_cluster_globpos_x, &b_mm_segment_cluster_globpos_x);
   fChain->SetBranchAddress("mm_segment_cluster_globpos_y", &mm_segment_cluster_globpos_y, &b_mm_segment_cluster_globpos_y);
   fChain->SetBranchAddress("mm_segment_cluster_globpos_z", &mm_segment_cluster_globpos_z, &b_mm_segment_cluster_globpos_z);
   fChain->SetBranchAddress("mm_segment_cluster_multilayer", &mm_segment_cluster_multilayer, &b_mm_segment_cluster_multilayer);
   fChain->SetBranchAddress("mm_segment_clusterprd_residuals_x", &mm_segment_clusterprd_residuals_x, &b_mm_segment_clusterprd_residuals_x);
   fChain->SetBranchAddress("mm_segment_clusterprd_residuals_y", &mm_segment_clusterprd_residuals_y, &b_mm_segment_clusterprd_residuals_y);
   fChain->SetBranchAddress("mm_segment_locx_err", &mm_segment_locx_err, &b_mm_segment_locx_err);
   fChain->SetBranchAddress("mm_segment_truth_locx_residuals", &mm_segment_truth_locx_residuals, &b_mm_segment_truth_locx_residuals);
   fChain->SetBranchAddress("mm_stationEta", &mm_stationEta, &b_mm_stationEta);
   fChain->SetBranchAddress("mm_stationIndex", &mm_stationIndex, &b_mm_stationIndex);
   fChain->SetBranchAddress("mm_stationPhi", &mm_stationPhi, &b_mm_stationPhi);
   fChain->SetBranchAddress("mmmuTpcChi2", &mmmuTpcChi2, &b_mmmuTpcChi2);
   fChain->SetBranchAddress("muon_segmentLink", &muon_segmentLink, &b_muon_segmentLink);
   fChain->SetBranchAddress("muon_segment_ChamberIdx", &muon_segment_ChamberIdx, &b_muon_segment_ChamberIdx);
   fChain->SetBranchAddress("muon_segment_ChamberTech", &muon_segment_ChamberTech, &b_muon_segment_ChamberTech);
   fChain->SetBranchAddress("muon_segment_EtaStation", &muon_segment_EtaStation, &b_muon_segment_EtaStation);
   fChain->SetBranchAddress("muon_segment_Mom_x", &muon_segment_Mom_x, &b_muon_segment_Mom_x);
   fChain->SetBranchAddress("muon_segment_Mom_y", &muon_segment_Mom_y, &b_muon_segment_Mom_y);
   fChain->SetBranchAddress("muon_segment_Mom_z", &muon_segment_Mom_z, &b_muon_segment_Mom_z);
   fChain->SetBranchAddress("muon_segment_Pos_x", &muon_segment_Pos_x, &b_muon_segment_Pos_x);
   fChain->SetBranchAddress("muon_segment_Pos_y", &muon_segment_Pos_y, &b_muon_segment_Pos_y);
   fChain->SetBranchAddress("muon_segment_Pos_z", &muon_segment_Pos_z, &b_muon_segment_Pos_z);
   fChain->SetBranchAddress("muon_segment_Sector", &muon_segment_Sector, &b_muon_segment_Sector);
   fChain->SetBranchAddress("muon_segment_chi2", &muon_segment_chi2, &b_muon_segment_chi2);
   fChain->SetBranchAddress("muon_segment_nDoF", &muon_segment_nDoF, &b_muon_segment_nDoF);
   fChain->SetBranchAddress("muon_segment_nMM_EtaHits", &muon_segment_nMM_EtaHits, &b_muon_segment_nMM_EtaHits);
   fChain->SetBranchAddress("muon_segment_nMM_StereoHits", &muon_segment_nMM_StereoHits, &b_muon_segment_nMM_StereoHits);
   fChain->SetBranchAddress("muon_segment_nPrecisionHits", &muon_segment_nPrecisionHits, &b_muon_segment_nPrecisionHits);
   fChain->SetBranchAddress("muon_segment_nSTGC_EtaHits", &muon_segment_nSTGC_EtaHits, &b_muon_segment_nSTGC_EtaHits);
   fChain->SetBranchAddress("muon_segment_nSTGC_PhiHits", &muon_segment_nSTGC_PhiHits, &b_muon_segment_nSTGC_PhiHits);
   fChain->SetBranchAddress("muon_segment_nTrigEtaLayers", &muon_segment_nTrigEtaLayers, &b_muon_segment_nTrigEtaLayers);
   fChain->SetBranchAddress("muon_segment_nTrigPhiLayers", &muon_segment_nTrigPhiLayers, &b_muon_segment_nTrigPhiLayers);
   fChain->SetBranchAddress("muons_pt", &muons_pt, &b_muons_pt);
   fChain->SetBranchAddress("muons_eta", &muons_eta, &b_muons_eta);
   fChain->SetBranchAddress("muons_phi", &muons_phi, &b_muons_phi);
   fChain->SetBranchAddress("muons_e", &muons_e, &b_muons_e);
   fChain->SetBranchAddress("muons_q", &muons_q, &b_muons_q);
   fChain->SetBranchAddress("muons_EnergyLoss", &muons_EnergyLoss, &b_muons_EnergyLoss);
   fChain->SetBranchAddress("muons_EnergyLossSigma", &muons_EnergyLossSigma, &b_muons_EnergyLossSigma);
   fChain->SetBranchAddress("muons_FSR_CandidateEnergy", &muons_FSR_CandidateEnergy, &b_muons_FSR_CandidateEnergy);
   fChain->SetBranchAddress("muons_IDLink", &muons_IDLink, &b_muons_IDLink);
   fChain->SetBranchAddress("muons_MELink", &muons_MELink, &b_muons_MELink);
   fChain->SetBranchAddress("muons_MSLink", &muons_MSLink, &b_muons_MSLink);
   fChain->SetBranchAddress("muons_MSOELink", &muons_MSOELink, &b_muons_MSOELink);
   fChain->SetBranchAddress("muons_MeasEnergyLoss", &muons_MeasEnergyLoss, &b_muons_MeasEnergyLoss);
   fChain->SetBranchAddress("muons_MeasEnergyLossSigma", &muons_MeasEnergyLossSigma, &b_muons_MeasEnergyLossSigma);
   fChain->SetBranchAddress("muons_ParamEnergyLoss", &muons_ParamEnergyLoss, &b_muons_ParamEnergyLoss);
   fChain->SetBranchAddress("muons_ParamEnergyLossSigmaMinus", &muons_ParamEnergyLossSigmaMinus, &b_muons_ParamEnergyLossSigmaMinus);
   fChain->SetBranchAddress("muons_ParamEnergyLossSigmaPlus", &muons_ParamEnergyLossSigmaPlus, &b_muons_ParamEnergyLossSigmaPlus);
   fChain->SetBranchAddress("muons_PtImbalSig", &muons_PtImbalSig, &b_muons_PtImbalSig);
   fChain->SetBranchAddress("muons_SCS", &muons_SCS, &b_muons_SCS);
   fChain->SetBranchAddress("muons_SNS", &muons_SNS, &b_muons_SNS);
   fChain->SetBranchAddress("muons_allAuthors", &muons_allAuthors, &b_muons_allAuthors);
   fChain->SetBranchAddress("muons_author", &muons_author, &b_muons_author);
   fChain->SetBranchAddress("muons_chi2", &muons_chi2, &b_muons_chi2);
   fChain->SetBranchAddress("muons_combinedTrackOutBoundsPrecisionHits", &muons_combinedTrackOutBoundsPrecisionHits, &b_muons_combinedTrackOutBoundsPrecisionHits);
   fChain->SetBranchAddress("muons_cov_d0", &muons_cov_d0, &b_muons_cov_d0);
   fChain->SetBranchAddress("muons_cov_phi", &muons_cov_phi, &b_muons_cov_phi);
   fChain->SetBranchAddress("muons_cov_phi_d0", &muons_cov_phi_d0, &b_muons_cov_phi_d0);
   fChain->SetBranchAddress("muons_cov_phi_z0", &muons_cov_phi_z0, &b_muons_cov_phi_z0);
   fChain->SetBranchAddress("muons_cov_qOverP", &muons_cov_qOverP, &b_muons_cov_qOverP);
   fChain->SetBranchAddress("muons_cov_qOverP_d0", &muons_cov_qOverP_d0, &b_muons_cov_qOverP_d0);
   fChain->SetBranchAddress("muons_cov_qOverP_phi", &muons_cov_qOverP_phi, &b_muons_cov_qOverP_phi);
   fChain->SetBranchAddress("muons_cov_qOverP_theta", &muons_cov_qOverP_theta, &b_muons_cov_qOverP_theta);
   fChain->SetBranchAddress("muons_cov_qOverP_z0", &muons_cov_qOverP_z0, &b_muons_cov_qOverP_z0);
   fChain->SetBranchAddress("muons_cov_theta", &muons_cov_theta, &b_muons_cov_theta);
   fChain->SetBranchAddress("muons_cov_theta_d0", &muons_cov_theta_d0, &b_muons_cov_theta_d0);
   fChain->SetBranchAddress("muons_cov_theta_phi", &muons_cov_theta_phi, &b_muons_cov_theta_phi);
   fChain->SetBranchAddress("muons_cov_theta_z0", &muons_cov_theta_z0, &b_muons_cov_theta_z0);
   fChain->SetBranchAddress("muons_cov_z0", &muons_cov_z0, &b_muons_cov_z0);
   fChain->SetBranchAddress("muons_cov_z0_d0", &muons_cov_z0_d0, &b_muons_cov_z0_d0);
   fChain->SetBranchAddress("muons_cscUnspoiledEtaHits", &muons_cscUnspoiledEtaHits, &b_muons_cscUnspoiledEtaHits);
   fChain->SetBranchAddress("muons_d0", &muons_d0, &b_muons_d0);
   fChain->SetBranchAddress("muons_extendedClosePrecisionHits", &muons_extendedClosePrecisionHits, &b_muons_extendedClosePrecisionHits);
   fChain->SetBranchAddress("muons_extendedLargeHits", &muons_extendedLargeHits, &b_muons_extendedLargeHits);
   fChain->SetBranchAddress("muons_extendedLargeHoles", &muons_extendedLargeHoles, &b_muons_extendedLargeHoles);
   fChain->SetBranchAddress("muons_extendedOutBoundsPrecisionHits", &muons_extendedOutBoundsPrecisionHits, &b_muons_extendedOutBoundsPrecisionHits);
   fChain->SetBranchAddress("muons_extendedSmallHits", &muons_extendedSmallHits, &b_muons_extendedSmallHits);
   fChain->SetBranchAddress("muons_extendedSmallHoles", &muons_extendedSmallHoles, &b_muons_extendedSmallHoles);
   fChain->SetBranchAddress("muons_innAngle", &muons_innAngle, &b_muons_innAngle);
   fChain->SetBranchAddress("muons_innerClosePrecisionHits", &muons_innerClosePrecisionHits, &b_muons_innerClosePrecisionHits);
   fChain->SetBranchAddress("muons_innerLargeHits", &muons_innerLargeHits, &b_muons_innerLargeHits);
   fChain->SetBranchAddress("muons_innerLargeHoles", &muons_innerLargeHoles, &b_muons_innerLargeHoles);
   fChain->SetBranchAddress("muons_innerOutBoundsPrecisionHits", &muons_innerOutBoundsPrecisionHits, &b_muons_innerOutBoundsPrecisionHits);
   fChain->SetBranchAddress("muons_innerSmallHits", &muons_innerSmallHits, &b_muons_innerSmallHits);
   fChain->SetBranchAddress("muons_innerSmallHoles", &muons_innerSmallHoles, &b_muons_innerSmallHoles);
   fChain->SetBranchAddress("muons_isBad", &muons_isBad, &b_muons_isBad);
   fChain->SetBranchAddress("muons_isCaloTag", &muons_isCaloTag, &b_muons_isCaloTag);
   fChain->SetBranchAddress("muons_isEndcapGoodLayers", &muons_isEndcapGoodLayers, &b_muons_isEndcapGoodLayers);
   fChain->SetBranchAddress("muons_isSmallGoodSectors", &muons_isSmallGoodSectors, &b_muons_isSmallGoodSectors);
   fChain->SetBranchAddress("muons_midAngle", &muons_midAngle, &b_muons_midAngle);
   fChain->SetBranchAddress("muons_middleClosePrecisionHits", &muons_middleClosePrecisionHits, &b_muons_middleClosePrecisionHits);
   fChain->SetBranchAddress("muons_middleLargeHits", &muons_middleLargeHits, &b_muons_middleLargeHits);
   fChain->SetBranchAddress("muons_middleLargeHoles", &muons_middleLargeHoles, &b_muons_middleLargeHoles);
   fChain->SetBranchAddress("muons_middleOutBoundsPrecisionHits", &muons_middleOutBoundsPrecisionHits, &b_muons_middleOutBoundsPrecisionHits);
   fChain->SetBranchAddress("muons_middleSmallHits", &muons_middleSmallHits, &b_muons_middleSmallHits);
   fChain->SetBranchAddress("muons_middleSmallHoles", &muons_middleSmallHoles, &b_muons_middleSmallHoles);
   fChain->SetBranchAddress("muons_msInnerMatchChi2", &muons_msInnerMatchChi2, &b_muons_msInnerMatchChi2);
   fChain->SetBranchAddress("muons_msInnerMatchDOF", &muons_msInnerMatchDOF, &b_muons_msInnerMatchDOF);
   fChain->SetBranchAddress("muons_msOuterMatchChi2", &muons_msOuterMatchChi2, &b_muons_msOuterMatchChi2);
   fChain->SetBranchAddress("muons_msOuterMatchDOF", &muons_msOuterMatchDOF, &b_muons_msOuterMatchDOF);
   fChain->SetBranchAddress("muons_numberOfGoodPrecisionLayers", &muons_numberOfGoodPrecisionLayers, &b_muons_numberOfGoodPrecisionLayers);
   fChain->SetBranchAddress("muons_numberOfOutliersOnTrack", &muons_numberOfOutliersOnTrack, &b_muons_numberOfOutliersOnTrack);
   fChain->SetBranchAddress("muons_numberOfPhiHoleLayers", &muons_numberOfPhiHoleLayers, &b_muons_numberOfPhiHoleLayers);
   fChain->SetBranchAddress("muons_numberOfPhiLayers", &muons_numberOfPhiLayers, &b_muons_numberOfPhiLayers);
   fChain->SetBranchAddress("muons_numberOfPrecisionHoleLayers", &muons_numberOfPrecisionHoleLayers, &b_muons_numberOfPrecisionHoleLayers);
   fChain->SetBranchAddress("muons_numberOfPrecisionLayers", &muons_numberOfPrecisionLayers, &b_muons_numberOfPrecisionLayers);
   fChain->SetBranchAddress("muons_numberOfTriggerEtaHoleLayers", &muons_numberOfTriggerEtaHoleLayers, &b_muons_numberOfTriggerEtaHoleLayers);
   fChain->SetBranchAddress("muons_numberOfTriggerEtaLayers", &muons_numberOfTriggerEtaLayers, &b_muons_numberOfTriggerEtaLayers);
   fChain->SetBranchAddress("muons_outerClosePrecisionHits", &muons_outerClosePrecisionHits, &b_muons_outerClosePrecisionHits);
   fChain->SetBranchAddress("muons_outerLargeHits", &muons_outerLargeHits, &b_muons_outerLargeHits);
   fChain->SetBranchAddress("muons_outerLargeHoles", &muons_outerLargeHoles, &b_muons_outerLargeHoles);
   fChain->SetBranchAddress("muons_outerOutBoundsPrecisionHits", &muons_outerOutBoundsPrecisionHits, &b_muons_outerOutBoundsPrecisionHits);
   fChain->SetBranchAddress("muons_outerSmallHits", &muons_outerSmallHits, &b_muons_outerSmallHits);
   fChain->SetBranchAddress("muons_outerSmallHoles", &muons_outerSmallHoles, &b_muons_outerSmallHoles);
   fChain->SetBranchAddress("muons_passHighPtCuts", &muons_passHighPtCuts, &b_muons_passHighPtCuts);
   fChain->SetBranchAddress("muons_passIDCuts", &muons_passIDCuts, &b_muons_passIDCuts);
   fChain->SetBranchAddress("muons_passIPCuts", &muons_passIPCuts, &b_muons_passIPCuts);
   fChain->SetBranchAddress("muons_passLooseCuts", &muons_passLooseCuts, &b_muons_passLooseCuts);
   fChain->SetBranchAddress("muons_passLowPtCuts", &muons_passLowPtCuts, &b_muons_passLowPtCuts);
   fChain->SetBranchAddress("muons_passMediumCuts", &muons_passMediumCuts, &b_muons_passMediumCuts);
   fChain->SetBranchAddress("muons_primarySector", &muons_primarySector, &b_muons_primarySector);
   fChain->SetBranchAddress("muons_quality", &muons_quality, &b_muons_quality);
   fChain->SetBranchAddress("muons_secondarySector", &muons_secondarySector, &b_muons_secondarySector);
   fChain->SetBranchAddress("muons_segmentChi2OverDoF", &muons_segmentChi2OverDoF, &b_muons_segmentChi2OverDoF);
   fChain->SetBranchAddress("muons_segmentDeltaEta", &muons_segmentDeltaEta, &b_muons_segmentDeltaEta);
   fChain->SetBranchAddress("muons_segmentDeltaPhi", &muons_segmentDeltaPhi, &b_muons_segmentDeltaPhi);
   fChain->SetBranchAddress("muons_type", &muons_type, &b_muons_type);
   fChain->SetBranchAddress("muons_z0", &muons_z0, &b_muons_z0);
   fChain->SetBranchAddress("muons_d0Sig", &muons_d0Sig, &b_muons_d0Sig);
   fChain->SetBranchAddress("muons_eta_err", &muons_eta_err, &b_muons_eta_err);
   fChain->SetBranchAddress("muons_pt_err", &muons_pt_err, &b_muons_pt_err);
   fChain->SetBranchAddress("muons_MdtExtChamFromCalo", &muons_MdtExtChamFromCalo, &b_muons_MdtExtChamFromCalo);
   fChain->SetBranchAddress("muons_nDoF", &muons_nDoF, &b_muons_nDoF);
   fChain->SetBranchAddress("nMM", &nMM, &b_nMM);
   fChain->SetBranchAddress("nMMOnTrack", &nMMOnTrack, &b_nMMOnTrack);
   fChain->SetBranchAddress("nRPC", &nRPC, &b_nRPC);
   fChain->SetBranchAddress("nSTGC", &nSTGC, &b_nSTGC);
   fChain->SetBranchAddress("nSTGCOnTrack", &nSTGCOnTrack, &b_nSTGCOnTrack);
   fChain->SetBranchAddress("nSTGCOnTrackPad", &nSTGCOnTrackPad, &b_nSTGCOnTrackPad);
   fChain->SetBranchAddress("nSTGCOnTrackStrip", &nSTGCOnTrackStrip, &b_nSTGCOnTrackStrip);
   fChain->SetBranchAddress("nSTGCOnTrackWire", &nSTGCOnTrackWire, &b_nSTGCOnTrackWire);
   fChain->SetBranchAddress("nSTGCPad", &nSTGCPad, &b_nSTGCPad);
   fChain->SetBranchAddress("nSTGCStrip", &nSTGCStrip, &b_nSTGCStrip);
   fChain->SetBranchAddress("nSTGCWire", &nSTGCWire, &b_nSTGCWire);
   fChain->SetBranchAddress("n_Muon", &n_Muon, &b_n_Muon);
   fChain->SetBranchAddress("passGRL", &passGRL, &b_passGRL);
   fChain->SetBranchAddress("rpcAmbiFlag", &rpcAmbiFlag, &b_rpcAmbiFlag);
   fChain->SetBranchAddress("rpcError", &rpcError, &b_rpcError);
   fChain->SetBranchAddress("rpcPos_x", &rpcPos_x, &b_rpcPos_x);
   fChain->SetBranchAddress("rpcPos_y", &rpcPos_y, &b_rpcPos_y);
   fChain->SetBranchAddress("rpcPos_z", &rpcPos_z, &b_rpcPos_z);
   fChain->SetBranchAddress("rpcTime", &rpcTime, &b_rpcTime);
   fChain->SetBranchAddress("rpcTrigInfo", &rpcTrigInfo, &b_rpcTrigInfo);
   fChain->SetBranchAddress("rpc_MuonLink", &rpc_MuonLink, &b_rpc_MuonLink);
   fChain->SetBranchAddress("rpc_doubletPhi", &rpc_doubletPhi, &b_rpc_doubletPhi);
   fChain->SetBranchAddress("rpc_doubletR", &rpc_doubletR, &b_rpc_doubletR);
   fChain->SetBranchAddress("rpc_doubletZ", &rpc_doubletZ, &b_rpc_doubletZ);
   fChain->SetBranchAddress("rpc_gasGap", &rpc_gasGap, &b_rpc_gasGap);
   fChain->SetBranchAddress("rpc_measuresPhi", &rpc_measuresPhi, &b_rpc_measuresPhi);
   fChain->SetBranchAddress("rpc_stationEta", &rpc_stationEta, &b_rpc_stationEta);
   fChain->SetBranchAddress("rpc_stationIndex", &rpc_stationIndex, &b_rpc_stationIndex);
   fChain->SetBranchAddress("rpc_stationPhi", &rpc_stationPhi, &b_rpc_stationPhi);
   fChain->SetBranchAddress("rpc_strip", &rpc_strip, &b_rpc_strip);
   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("sTGC_SimDataGenParPdgId", &sTGC_SimDataGenParPdgId, &b_sTGC_SimDataGenParPdgId);
   fChain->SetBranchAddress("sTGC_SimDataGenParPt", &sTGC_SimDataGenParPt, &b_sTGC_SimDataGenParPt);
   fChain->SetBranchAddress("sTGC_SimDataGenParVertexPos_x", &sTGC_SimDataGenParVertexPos_x, &b_sTGC_SimDataGenParVertexPos_x);
   fChain->SetBranchAddress("sTGC_SimDataGenParVertexPos_y", &sTGC_SimDataGenParVertexPos_y, &b_sTGC_SimDataGenParVertexPos_y);
   fChain->SetBranchAddress("sTGC_SimDataGenParVertexPos_z", &sTGC_SimDataGenParVertexPos_z, &b_sTGC_SimDataGenParVertexPos_z);
   fChain->SetBranchAddress("sTGC_SimDataGlobalPos_x", &sTGC_SimDataGlobalPos_x, &b_sTGC_SimDataGlobalPos_x);
   fChain->SetBranchAddress("sTGC_SimDataGlobalPos_y", &sTGC_SimDataGlobalPos_y, &b_sTGC_SimDataGlobalPos_y);
   fChain->SetBranchAddress("sTGC_SimDataGlobalPos_z", &sTGC_SimDataGlobalPos_z, &b_sTGC_SimDataGlobalPos_z);
   fChain->SetBranchAddress("sTGC_SimDataLocalPos_x", &sTGC_SimDataLocalPos_x, &b_sTGC_SimDataLocalPos_x);
   fChain->SetBranchAddress("sTGC_SimDataLocalPos_y", &sTGC_SimDataLocalPos_y, &b_sTGC_SimDataLocalPos_y);
   fChain->SetBranchAddress("sTGC_SimData_channel", &sTGC_SimData_channel, &b_sTGC_SimData_channel);
   fChain->SetBranchAddress("sTGC_SimData_channel_type", &sTGC_SimData_channel_type, &b_sTGC_SimData_channel_type);
   fChain->SetBranchAddress("sTGC_SimData_gas_gap", &sTGC_SimData_gas_gap, &b_sTGC_SimData_gas_gap);
   fChain->SetBranchAddress("sTGC_SimData_multiplet", &sTGC_SimData_multiplet, &b_sTGC_SimData_multiplet);
   fChain->SetBranchAddress("sTGC_SimData_stationEta", &sTGC_SimData_stationEta, &b_sTGC_SimData_stationEta);
   fChain->SetBranchAddress("sTGC_SimData_stationIndex", &sTGC_SimData_stationIndex, &b_sTGC_SimData_stationIndex);
   fChain->SetBranchAddress("sTGC_SimData_stationPhi", &sTGC_SimData_stationPhi, &b_sTGC_SimData_stationPhi);
   fChain->SetBranchAddress("segment_asoc", &segment_asoc, &b_segment_asoc);
   fChain->SetBranchAddress("stgcBCID", &stgcBCID, &b_stgcBCID);
   fChain->SetBranchAddress("stgcCharge", &stgcCharge, &b_stgcCharge);
   fChain->SetBranchAddress("stgcError", &stgcError, &b_stgcError);
   fChain->SetBranchAddress("stgcGlobalPos_x", &stgcGlobalPos_x, &b_stgcGlobalPos_x);
   fChain->SetBranchAddress("stgcGlobalPos_y", &stgcGlobalPos_y, &b_stgcGlobalPos_y);
   fChain->SetBranchAddress("stgcGlobalPos_z", &stgcGlobalPos_z, &b_stgcGlobalPos_z);
   fChain->SetBranchAddress("stgcLocalPos_x", &stgcLocalPos_x, &b_stgcLocalPos_x);
   fChain->SetBranchAddress("stgcLocalPos_y", &stgcLocalPos_y, &b_stgcLocalPos_y);
   fChain->SetBranchAddress("stgcNStrips", &stgcNStrips, &b_stgcNStrips);
   fChain->SetBranchAddress("stgcOnTrackError", &stgcOnTrackError, &b_stgcOnTrackError);
   fChain->SetBranchAddress("stgcOnTrackGlobalPos_x", &stgcOnTrackGlobalPos_x, &b_stgcOnTrackGlobalPos_x);
   fChain->SetBranchAddress("stgcOnTrackGlobalPos_y", &stgcOnTrackGlobalPos_y, &b_stgcOnTrackGlobalPos_y);
   fChain->SetBranchAddress("stgcOnTrackGlobalPos_z", &stgcOnTrackGlobalPos_z, &b_stgcOnTrackGlobalPos_z);
   fChain->SetBranchAddress("stgcOnTrackLocalPos_x", &stgcOnTrackLocalPos_x, &b_stgcOnTrackLocalPos_x);
   fChain->SetBranchAddress("stgcOnTrackLocalPos_y", &stgcOnTrackLocalPos_y, &b_stgcOnTrackLocalPos_y);
   fChain->SetBranchAddress("stgcOnTrackNStrips", &stgcOnTrackNStrips, &b_stgcOnTrackNStrips);
   fChain->SetBranchAddress("stgcOnTrackPullTrack", &stgcOnTrackPullTrack, &b_stgcOnTrackPullTrack);
   fChain->SetBranchAddress("stgcOnTrackPullTrackMS", &stgcOnTrackPullTrackMS, &b_stgcOnTrackPullTrackMS);
   fChain->SetBranchAddress("stgcOnTrackPullTruth", &stgcOnTrackPullTruth, &b_stgcOnTrackPullTruth);
   fChain->SetBranchAddress("stgcOnTrackResidualTrack", &stgcOnTrackResidualTrack, &b_stgcOnTrackResidualTrack);
   fChain->SetBranchAddress("stgcOnTrackResidualTrackMS", &stgcOnTrackResidualTrackMS, &b_stgcOnTrackResidualTrackMS);
   fChain->SetBranchAddress("stgcOnTrackResidualTruth", &stgcOnTrackResidualTruth, &b_stgcOnTrackResidualTruth);
   fChain->SetBranchAddress("stgcOnTrackStripCharges", &stgcOnTrackStripCharges, &b_stgcOnTrackStripCharges);
   fChain->SetBranchAddress("stgcOnTrackStripDriftTimes", &stgcOnTrackStripDriftTimes, &b_stgcOnTrackStripDriftTimes);
   fChain->SetBranchAddress("stgcOnTrackStripNumbers", &stgcOnTrackStripNumbers, &b_stgcOnTrackStripNumbers);
   fChain->SetBranchAddress("stgcOnTrack_MuonLink", &stgcOnTrack_MuonLink, &b_stgcOnTrack_MuonLink);
   fChain->SetBranchAddress("stgcOnTrack_channel", &stgcOnTrack_channel, &b_stgcOnTrack_channel);
   fChain->SetBranchAddress("stgcOnTrack_channel_type", &stgcOnTrack_channel_type, &b_stgcOnTrack_channel_type);
   fChain->SetBranchAddress("stgcOnTrack_gas_gap", &stgcOnTrack_gas_gap, &b_stgcOnTrack_gas_gap);
   fChain->SetBranchAddress("stgcOnTrack_multiplet", &stgcOnTrack_multiplet, &b_stgcOnTrack_multiplet);
   fChain->SetBranchAddress("stgcOnTrack_stationEta", &stgcOnTrack_stationEta, &b_stgcOnTrack_stationEta);
   fChain->SetBranchAddress("stgcOnTrack_stationIndex", &stgcOnTrack_stationIndex, &b_stgcOnTrack_stationIndex);
   fChain->SetBranchAddress("stgcOnTrack_stationPhi", &stgcOnTrack_stationPhi, &b_stgcOnTrack_stationPhi);
   fChain->SetBranchAddress("stgcPadCorners_x", &stgcPadCorners_x, &b_stgcPadCorners_x);
   fChain->SetBranchAddress("stgcPadCorners_y", &stgcPadCorners_y, &b_stgcPadCorners_y);
   fChain->SetBranchAddress("stgcStripChannel", &stgcStripChannel, &b_stgcStripChannel);
   fChain->SetBranchAddress("stgcStripCharge", &stgcStripCharge, &b_stgcStripCharge);
   fChain->SetBranchAddress("stgcStripTime", &stgcStripTime, &b_stgcStripTime);
   fChain->SetBranchAddress("stgcTime", &stgcTime, &b_stgcTime);
   fChain->SetBranchAddress("stgcTrackStateGlobalPos_x", &stgcTrackStateGlobalPos_x, &b_stgcTrackStateGlobalPos_x);
   fChain->SetBranchAddress("stgcTrackStateGlobalPos_y", &stgcTrackStateGlobalPos_y, &b_stgcTrackStateGlobalPos_y);
   fChain->SetBranchAddress("stgcTrackStateGlobalPos_z", &stgcTrackStateGlobalPos_z, &b_stgcTrackStateGlobalPos_z);
   fChain->SetBranchAddress("stgcTrackStateLocalPos_x", &stgcTrackStateLocalPos_x, &b_stgcTrackStateLocalPos_x);
   fChain->SetBranchAddress("stgcTrackStateLocalPos_y", &stgcTrackStateLocalPos_y, &b_stgcTrackStateLocalPos_y);
   fChain->SetBranchAddress("stgcTrackState_ClusterOnTrackLink", &stgcTrackState_ClusterOnTrackLink, &b_stgcTrackState_ClusterOnTrackLink);
   fChain->SetBranchAddress("stgcTrackState_MuonLink", &stgcTrackState_MuonLink, &b_stgcTrackState_MuonLink);
   fChain->SetBranchAddress("stgcTrackState_channel", &stgcTrackState_channel, &b_stgcTrackState_channel);
   fChain->SetBranchAddress("stgcTrackState_channel_type", &stgcTrackState_channel_type, &b_stgcTrackState_channel_type);
   fChain->SetBranchAddress("stgcTrackState_closestClusterLink", &stgcTrackState_closestClusterLink, &b_stgcTrackState_closestClusterLink);
   fChain->SetBranchAddress("stgcTrackState_closestClusterResidualX", &stgcTrackState_closestClusterResidualX, &b_stgcTrackState_closestClusterResidualX);
   fChain->SetBranchAddress("stgcTrackState_closestClusterResidualY", &stgcTrackState_closestClusterResidualY, &b_stgcTrackState_closestClusterResidualY);
   fChain->SetBranchAddress("stgcTrackState_gas_gap", &stgcTrackState_gas_gap, &b_stgcTrackState_gas_gap);
   fChain->SetBranchAddress("stgcTrackState_multiplet", &stgcTrackState_multiplet, &b_stgcTrackState_multiplet);
   fChain->SetBranchAddress("stgcTrackState_padEta", &stgcTrackState_padEta, &b_stgcTrackState_padEta);
   fChain->SetBranchAddress("stgcTrackState_padPhi", &stgcTrackState_padPhi, &b_stgcTrackState_padPhi);
   fChain->SetBranchAddress("stgcTrackState_stationEta", &stgcTrackState_stationEta, &b_stgcTrackState_stationEta);
   fChain->SetBranchAddress("stgcTrackState_stationIndex", &stgcTrackState_stationIndex, &b_stgcTrackState_stationIndex);
   fChain->SetBranchAddress("stgcTrackState_stationPhi", &stgcTrackState_stationPhi, &b_stgcTrackState_stationPhi);
   fChain->SetBranchAddress("stgc_channel", &stgc_channel, &b_stgc_channel);
   fChain->SetBranchAddress("stgc_channel_type", &stgc_channel_type, &b_stgc_channel_type);
   fChain->SetBranchAddress("stgc_gas_gap", &stgc_gas_gap, &b_stgc_gas_gap);
   fChain->SetBranchAddress("stgc_multiplet", &stgc_multiplet, &b_stgc_multiplet);
   fChain->SetBranchAddress("stgc_segment_cluster_channel_type", &stgc_segment_cluster_channel_type, &b_stgc_segment_cluster_channel_type);
   fChain->SetBranchAddress("stgc_segment_cluster_gas_gap", &stgc_segment_cluster_gas_gap, &b_stgc_segment_cluster_gas_gap);
   fChain->SetBranchAddress("stgc_segment_cluster_globpos_x", &stgc_segment_cluster_globpos_x, &b_stgc_segment_cluster_globpos_x);
   fChain->SetBranchAddress("stgc_segment_cluster_globpos_y", &stgc_segment_cluster_globpos_y, &b_stgc_segment_cluster_globpos_y);
   fChain->SetBranchAddress("stgc_segment_cluster_globpos_z", &stgc_segment_cluster_globpos_z, &b_stgc_segment_cluster_globpos_z);
   fChain->SetBranchAddress("stgc_segment_cluster_multilayer", &stgc_segment_cluster_multilayer, &b_stgc_segment_cluster_multilayer);
   fChain->SetBranchAddress("stgc_segment_cluster_theta", &stgc_segment_cluster_theta, &b_stgc_segment_cluster_theta);
   fChain->SetBranchAddress("stgc_segment_clusterprd_residuals_x", &stgc_segment_clusterprd_residuals_x, &b_stgc_segment_clusterprd_residuals_x);
   fChain->SetBranchAddress("stgc_segment_clusterprd_residuals_y", &stgc_segment_clusterprd_residuals_y, &b_stgc_segment_clusterprd_residuals_y);
   fChain->SetBranchAddress("stgc_segment_locx_err", &stgc_segment_locx_err, &b_stgc_segment_locx_err);
   fChain->SetBranchAddress("stgc_segment_locy_err", &stgc_segment_locy_err, &b_stgc_segment_locy_err);
   fChain->SetBranchAddress("stgc_segment_truth_locx_residuals", &stgc_segment_truth_locx_residuals, &b_stgc_segment_truth_locx_residuals);
   fChain->SetBranchAddress("stgc_segment_truth_locy_residuals", &stgc_segment_truth_locy_residuals, &b_stgc_segment_truth_locy_residuals);
   fChain->SetBranchAddress("stgc_stationEta", &stgc_stationEta, &b_stgc_stationEta);
   fChain->SetBranchAddress("stgc_stationIndex", &stgc_stationIndex, &b_stgc_stationIndex);
   fChain->SetBranchAddress("stgc_stationPhi", &stgc_stationPhi, &b_stgc_stationPhi);
   fChain->SetBranchAddress("unassoc_segment_ChamberIdx", &unassoc_segment_ChamberIdx, &b_unassoc_segment_ChamberIdx);
   fChain->SetBranchAddress("unassoc_segment_ChamberTech", &unassoc_segment_ChamberTech, &b_unassoc_segment_ChamberTech);
   fChain->SetBranchAddress("unassoc_segment_EtaStation", &unassoc_segment_EtaStation, &b_unassoc_segment_EtaStation);
   fChain->SetBranchAddress("unassoc_segment_Mom_x", &unassoc_segment_Mom_x, &b_unassoc_segment_Mom_x);
   fChain->SetBranchAddress("unassoc_segment_Mom_y", &unassoc_segment_Mom_y, &b_unassoc_segment_Mom_y);
   fChain->SetBranchAddress("unassoc_segment_Mom_z", &unassoc_segment_Mom_z, &b_unassoc_segment_Mom_z);
   fChain->SetBranchAddress("unassoc_segment_Pos_x", &unassoc_segment_Pos_x, &b_unassoc_segment_Pos_x);
   fChain->SetBranchAddress("unassoc_segment_Pos_y", &unassoc_segment_Pos_y, &b_unassoc_segment_Pos_y);
   fChain->SetBranchAddress("unassoc_segment_Pos_z", &unassoc_segment_Pos_z, &b_unassoc_segment_Pos_z);
   fChain->SetBranchAddress("unassoc_segment_Sector", &unassoc_segment_Sector, &b_unassoc_segment_Sector);
   fChain->SetBranchAddress("unassoc_segment_chi2", &unassoc_segment_chi2, &b_unassoc_segment_chi2);
   fChain->SetBranchAddress("unassoc_segment_nDoF", &unassoc_segment_nDoF, &b_unassoc_segment_nDoF);
   fChain->SetBranchAddress("unassoc_segment_nMM_EtaHits", &unassoc_segment_nMM_EtaHits, &b_unassoc_segment_nMM_EtaHits);
   fChain->SetBranchAddress("unassoc_segment_nMM_StereoHits", &unassoc_segment_nMM_StereoHits, &b_unassoc_segment_nMM_StereoHits);
   fChain->SetBranchAddress("unassoc_segment_nPrecisionHits", &unassoc_segment_nPrecisionHits, &b_unassoc_segment_nPrecisionHits);
   fChain->SetBranchAddress("unassoc_segment_nSTGC_EtaHits", &unassoc_segment_nSTGC_EtaHits, &b_unassoc_segment_nSTGC_EtaHits);
   fChain->SetBranchAddress("unassoc_segment_nSTGC_PhiHits", &unassoc_segment_nSTGC_PhiHits, &b_unassoc_segment_nSTGC_PhiHits);
   fChain->SetBranchAddress("unassoc_segment_nTrigEtaLayers", &unassoc_segment_nTrigEtaLayers, &b_unassoc_segment_nTrigEtaLayers);
   fChain->SetBranchAddress("unassoc_segment_nTrigPhiLayers", &unassoc_segment_nTrigPhiLayers, &b_unassoc_segment_nTrigPhiLayers);
   Notify();
}

Bool_t AnalizeMuonTester::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void AnalizeMuonTester::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t AnalizeMuonTester::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef AnalizeMuonTester_cxx
