#define e428ana1_cxx
#include "e428ana1.h"
#include <TH2.h>
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TSpectrum.h>
void e428ana1::Loop()
{
//   In a ROOT session, you can do:
//      Root > .L e428ana1.C
//      Root > e428ana1 t
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
           hdssd[0][i]->Fill(rDSSD1[0][i]);
           hdssd[1][i]->Fill(rDSSD2[0][i]);
           hdssd[2][i]->Fill(rDSSD3[0][i]);
           hdssd[3][i]->Fill(rDSSD4[0][i]);
     //      printf("values:  %d   %d   %d   %d   %d\n",i,rDSSD1[i],rDSSD2[i],rDSSD3[i],rDSSD4[i]);
           
       }

   }
}

int e428ana1::MakePara(Double_t thr){
    int npeak,nlap;
    double threshol,thrmin,thrmax;
    TSpectrum *spec;
    for (int i=0; i<4; i++) {
        for (int j=0; j<127; j++) {
            npeak=0;nlap=0;
            threshol=thr;
            thrmax=1;thrmin=0;
            while (npeak!=4 && nlap<100){
                spec = new TSpectrum(10);
                npeak = spec->Search(hdssd[i][j],2,"",threshol);
                if (npeak >3) {
                    thrmin=threshol;
                }else thrmax=threshol;
                threshol=(thrmax-thrmin)/2;
                nlap++;
        //        printf("Npeak   %d   %d    %d    %f\n",i,j,npeak,threshol);
            }
            float *xpeak=spec->GetPositionX();
            float *ypeak=spec->GetPositionY();
            printf("Npeak   %d   %d    %d",i,j,npeak);
            for (int i1=0; i1<npeak; i1++) {
                printf("    %f   %f",xpeak[i1],ypeak[i1]);
            }
            printf("\n");
        }
    }    
    return 0;
}