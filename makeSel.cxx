void makeSel(std::string inputName="/Users/quser/Documents/Berylium/e428/e428_run0311.root",
             std::string outputName="e428ana1"){
  TFile* _fi = TFile::Open(inputName.c_str());
  TTree *_ti = (TTree *) _fi->Get("rawa");
  //_ti->MakeSelector(outputName.c_str());
    _ti->MakeClass(outputName.c_str());
  }
