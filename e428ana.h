//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri Dec 12 12:06:04 2014 by ROOT version 5.34/19
// from TTree test/EN raw data convert by T D Trong using ENConvert
// found on file: /Users/quser/Documents/Berylium/e428/e428_run0370.root
//////////////////////////////////////////////////////////

#ifndef e428ana_h
#define e428ana_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

// Fixed size dimensions of array or collections stored in the TTree if any.

class e428ana {
private:
    
public :
   TH1 *hdssd[5][129];  
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

   // Declaration of leaf types
   Int_t           evtNo;
   Int_t           rF1FilberLead[128];
   Int_t           rF1FilberTrail[128];
   Int_t           rF1FiberDYQ[2];
   Int_t           rF1PLT_F1;
   Int_t           rF1PLT_F3;
   Int_t           rF2PPAC[10];
   Int_t           rPlasticT[6];
   Int_t           rPlasticQ[6];
   Int_t           rRF;
   Int_t           rRefcommon;
   Int_t           rCsIor;
   Int_t           rSior;
   Int_t           rSWor[4];
   Int_t           rF1PLQ;
   Int_t           rCsIQ[16];
   Int_t           rCsIT[16];
   Int_t           rRF_V775;
   Int_t           rStackQ[8];
   Int_t           rStackT[8];
   Int_t           rLiqQ[8];
   Int_t           rLiqT[4];
   Int_t           rLupoCoin[16];
   Int_t           rMWDC1[64];
   Int_t           rMWDC2[64];
   Int_t           rMWDC3[64];
   Int_t           rMWDC4[64];
   Int_t           rDSSD1[128];
   Int_t           rDSSD2[128];
   Int_t           rDSSD3[128];
   Int_t           rDSSD4[128];

   // List of branches
   TBranch        *b_evtNo;   //!
   TBranch        *b_rF1FilberLead;   //!
   TBranch        *b_rF1FilberTrail;   //!
   TBranch        *b_rF1FiberDYQ;   //!
   TBranch        *b_rF1PLT_F1;   //!
   TBranch        *b_rF1PLT_F3;   //!
   TBranch        *b_rF2PPAC;   //!
   TBranch        *b_rPlasticT;   //!
   TBranch        *b_rPlasticQ;   //!
   TBranch        *b_rRF;   //!
   TBranch        *b_rRefcommon;   //!
   TBranch        *b_rCsIor;   //!
   TBranch        *b_rSior;   //!
   TBranch        *b_rSWor;   //!
   TBranch        *b_rF1PLQ;   //!
   TBranch        *b_rCsIQ;   //!
   TBranch        *b_rCsIT;   //!
   TBranch        *b_rRF_V775;   //!
   TBranch        *b_rStackQ;   //!
   TBranch        *b_rStackT;   //!
   TBranch        *b_rLiqQ;   //!
   TBranch        *b_rLiqT;   //!
   TBranch        *b_rLupoCoin;   //!
   TBranch        *b_rMWDC1;   //!
   TBranch        *b_rMWDC2;   //!
   TBranch        *b_rMWDC3;   //!
   TBranch        *b_rMWDC4;   //!
   TBranch        *b_rDSSD1;   //!
   TBranch        *b_rDSSD2;   //!
   TBranch        *b_rDSSD3;   //!
   TBranch        *b_rDSSD4;   //!

   e428ana(TTree *tree=0);
   virtual ~e428ana();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef e428ana_cxx
e428ana::e428ana(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("/Users/quser/Documents/Berylium/e428/e428_run0370.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("/Users/quser/Documents/Berylium/e428/e428_run0370.root");
      }
      f->GetObject("rawa",tree);

   }
   Init(tree);
}

e428ana::~e428ana()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t e428ana::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t e428ana::LoadTree(Long64_t entry)
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

void e428ana::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evtNo", &evtNo, &b_evtNo);
   fChain->SetBranchAddress("rF1FilberLead", rF1FilberLead, &b_rF1FilberLead);
   fChain->SetBranchAddress("rF1FilberTrail", rF1FilberTrail, &b_rF1FilberTrail);
   fChain->SetBranchAddress("rF1FiberDYQ", rF1FiberDYQ, &b_rF1FiberDYQ);
   fChain->SetBranchAddress("rF1PLT_F1", &rF1PLT_F1, &b_rF1PLT_F1);
   fChain->SetBranchAddress("rF1PLT_F3", &rF1PLT_F3, &b_rF1PLT_F3);
   fChain->SetBranchAddress("rF2PPAC", rF2PPAC, &b_rF2PPAC);
   fChain->SetBranchAddress("rPlasticT", rPlasticT, &b_rPlasticT);
   fChain->SetBranchAddress("rPlasticQ", rPlasticQ, &b_rPlasticQ);
   fChain->SetBranchAddress("rRF", &rRF, &b_rRF);
   fChain->SetBranchAddress("rRefcommon", &rRefcommon, &b_rRefcommon);
   fChain->SetBranchAddress("rCsIor", &rCsIor, &b_rCsIor);
   fChain->SetBranchAddress("rSior", &rSior, &b_rSior);
   fChain->SetBranchAddress("rSWor", rSWor, &b_rSWor);
   fChain->SetBranchAddress("rF1PLQ", &rF1PLQ, &b_rF1PLQ);
   fChain->SetBranchAddress("rCsIQ", rCsIQ, &b_rCsIQ);
   fChain->SetBranchAddress("rCsIT", rCsIT, &b_rCsIT);
   fChain->SetBranchAddress("rRF_V775", &rRF_V775, &b_rRF_V775);
   fChain->SetBranchAddress("rStackQ", rStackQ, &b_rStackQ);
   fChain->SetBranchAddress("rStackT", rStackT, &b_rStackT);
   fChain->SetBranchAddress("rLiqQ", rLiqQ, &b_rLiqQ);
   fChain->SetBranchAddress("rLiqT", rLiqT, &b_rLiqT);
   fChain->SetBranchAddress("rLupoCoin", rLupoCoin, &b_rLupoCoin);
   fChain->SetBranchAddress("rMWDC1", rMWDC1, &b_rMWDC1);
   fChain->SetBranchAddress("rMWDC2", rMWDC2, &b_rMWDC2);
   fChain->SetBranchAddress("rMWDC3", rMWDC3, &b_rMWDC3);
   fChain->SetBranchAddress("rMWDC4", rMWDC4, &b_rMWDC4);
   fChain->SetBranchAddress("rDSSD1", rDSSD1, &b_rDSSD1);
   fChain->SetBranchAddress("rDSSD2", rDSSD2, &b_rDSSD2);
   fChain->SetBranchAddress("rDSSD3", rDSSD3, &b_rDSSD3);
   fChain->SetBranchAddress("rDSSD4", rDSSD4, &b_rDSSD4);
   Notify();
}

Bool_t e428ana::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void e428ana::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t e428ana::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef e428ana_cxx
