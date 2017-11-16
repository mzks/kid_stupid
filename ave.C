// draw.C


TGraph* draw(TString file = "datfiles/run001.dat",Double_t SG_MHz = 4200){

	//auto C = new TCanvas();
	//C->Divide(1,2);

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
	//C->cd(1);

	auto tg4 = new TGraph(d1.size(),d1.data(),d4.data());
	tg4->SetTitle(";freq.[MHz];magnitude[dB]");
	//tg4->Draw();

	//C->cd(2);
	auto tg5 = new TGraph(d1.size(),d1.data(),d5.data());
	tg5->SetTitle(";freq.[MHz];phase[rad.]");
	//tg5->Draw();
	
	return tg5;
	
}

void ave(){
	auto run001 = draw("datfiles/run001.dat",4200);
	auto run002 = draw("datfiles/run002.dat",4200);
	auto run003 = draw("datfiles/run003.dat",4200);
	auto run004 = draw("datfiles/run004.dat",4200);
	auto run005 = draw("datfiles/run005.dat",4200);
	auto run006 = draw("datfiles/run006.dat",4200);
	auto run007 = draw("datfiles/run007.dat",4200);
	auto run008 = draw("datfiles/run008.dat",4200);
	auto run009 = draw("datfiles/run009.dat",4200);
	auto run010 = draw("datfiles/run010.dat",4200);

	run001->Draw("AP");
	run002->Draw("P");
	run003->Draw("P");
	run004->Draw("P");
	run005->Draw("P");
	run006->Draw("P");
	run007->Draw("P");
	run008->Draw("P");
	run009->Draw("P");
	run010->Draw("P");
}
