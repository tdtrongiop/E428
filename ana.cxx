{
//    if (!t) delete t;
//    if (!e) delete e;
//    if (! e372analys) delete e372analys;
    Double_t gama;
    Double_t Ninc;
    Int_t il;
    gROOT->Reset();
    gROOT->ProcessLine(".L Chain.C");
    TChain *t = new TChain();
    
    il = 0;
    
    if (il !=1){t = chain(311,311);il=0;
        printf("Running for Target IN\n");
    }
    else {t = chain(114,114);il=1;
        printf("Running for Target OUT\n");
    }
    gROOT->ProcessLine(".L e428ana1.C+");
    e428ana1 e(t);
    e.Loop();
}
