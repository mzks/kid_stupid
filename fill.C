// ------------------------------- //
// fill.C -- root macro
// Author :Mizukoshi Keita
// 2017 Nov. 16
// ------------------------------- //

void fill(TString dir = "multiTod1", int num = 10){
	auto tree = new TTree("tree","AmstelTree");

	Double_t f1, f2, f3;
	vector<Double_t> I, Q, T, radius;

	tree->Branch("I",&I);
	tree->Branch("Q",&Q);
	tree->Branch("T",&T);
	tree->Branch("radius",&radius);


	for(int runnum = 0;runnum<num;runnum++){
		stringstream ss;
		ss << dir << "/trg" << runnum << ".dat"; //fix for your filename
		TString file = ss.str();
		ifstream ifs(file);
		
		I.clear();
		Q.clear();
		T.clear();
		radius.clear();

		while(ifs >> f1 >> f2 >> f3){
			T.push_back(f1);
			I.push_back(f2);
			Q.push_back(f3);
			radius.push_back(sqrt(f2*f2+f3*f3));
		}
		tree->Fill();
	}

	stringstream ssout;
	ssout << dir << "/data.root";
	TString outfile = ssout.str();
	

	auto fout = new TFile(outfile,"recreate");
	tree->Write();
	fout->Close();

}
