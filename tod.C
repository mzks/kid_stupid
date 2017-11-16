
void tod(TString file = "trg2.dat"){

	Double_t ev;
	Double_t f1, f2;

	vector<Double_t> d1, d2;
	vector<Double_t> dEv,r;

	ifstream ifs(file);
	while(ifs >> ev >> f1 >> f2){
		d1.push_back(f1);
		d2.push_back(f2);
		dEv.push_back(ev);
		r.push_back(sqrt(f1*f1+f2*f2));
	}
	
	auto C = new TCanvas();
	C->Divide(1,3);
	C->cd(1);
	auto tg1 = new TGraph(dEv.size(),dEv.data(),d1.data());
	tg1->SetTitle(";time;I");
	tg1->Draw();
	C->cd(2);
	auto tg2 = new TGraph(dEv.size(),dEv.data(),d2.data());
	tg2->SetTitle(";time;Q");
	tg2->Draw();

	C->cd(3);
	auto tg3 = new TGraph(dEv.size(),dEv.data(),r.data());
	tg3->Draw();
	
	
}
