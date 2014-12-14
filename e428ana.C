#define e428ana_cxx
#include "e428ana.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>

void e428ana::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L e428ana.C
//      Root > e428ana t
//      Root > t.GetEntry(12); // Fill t data members with entry number 12
//      Root > t.Show();       // Show values of entry 12
//      Root > t.Show(16);     // Read and show values of entry 16
//      Root > t.Loop();       // Loop on all entries
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
//    fChain->SetBranchStatus("*",0);  // disable all branches
//    fChain->SetBranchStatus("branchname",1);  // activate branchname
// METHOD2: replace line
//    fChain->GetEntry(jentry);       //read all branches
//by  b_branchname->GetEntry(ientry); //read only this branch
   if (fChain == 0) return;

    char histname[50];
    
    for (int i=0; i<4; i++) {
        for (int j=0; j<128; j++) {
            sprintf(histname,"DSSD%d_%d",i,j);
            hdssd[i][j] = new TH1F(histname,"DSSD",2000,-0.5,1999.5);
        }
    }
    
    
   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
    //  nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;
       b_rDSSD1->GetEntry(ientry);
       b_rDSSD2->GetEntry(ientry);
       b_rDSSD3->GetEntry(ientry);
       b_rDSSD4->GetEntry(ientry);
       for (int i=0; i<128; i++) {
           hdssd[0][i]->Fill(rDSSD1[i]);
           hdssd[1][i]->Fill(rDSSD2[i]);
           hdssd[2][i]->Fill(rDSSD3[i]);
           hdssd[3][i]->Fill(rDSSD4[i]);
          printf("values:  %d   %d   %d   %d   %d\n",i,rDSSD1[i],rDSSD2[i],rDSSD3[i],rDSSD4[i]);
           
       }
//       printf("values:  %d   %d\n",jentry,rRF);
   }
}
