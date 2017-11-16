// draw.C


void draw(TString file = "datfiles/run001.dat",Double_t SG_MHz = 4170){

	auto C = new TCanvas();
	C->Divide(1,2);
	//f1:freq. (fpga).
	//f2:I
	//f3:Q
	//f4:Mag.
	//f5:phase
	// freq - Mag
	// freq - phase

	Double_t f1, f2, f3, f4, f5;
	vector<Double_t> d1, d2, d3, d4, d5;

	ifstream ifs(file);
	while(ifs >> f1 >> f2 >> f3 >> f4 >> f5){
		d1.push_back(f1*1.0e-6+SG_MHz);
		d2.push_back(f2);
		d3.push_back(f3);
		d4.push_back(20.0*log10(f4));
		d5.push_back(f5);
	}
	C->cd(1);
	auto tg4 = new TGraph(d1.size(),d1.data(),d4.data());
	tg4->SetTitle(";freq.[MHz];Amplitude");
	tg4->Draw();

	C->cd(2);
	auto tg5 = new TGraph(d1.size(),d1.data(),d5.data());
	tg5->SetTitle(";freq.[MHz];phase[rad.]");
	tg5->Draw();

	auto C2 = new TCanvas();
	auto IQ = new TGraph(d2.size(),d2.data(),d3.data());
	IQ->SetTitle(";I;Q");
	IQ->Draw();
	
}
