

void fitshow(TString file = "summary.txt"){

	auto C = new TCanvas();
	C->Divide(2,4);

	Double_t f1,f2,f3,f4,f5,f6,f7,f8,f9,f10,f11,f12;

	auto tau = new TH1D("tau","tau",100,20,40);
	auto height = new TH1D("height","height",100,0,300e6);
	auto chi2 = new TH1D("chi2","chi2",100,0,1e17);
	auto area = new TH1D("area","area",100,0,1e10);
	auto heightExp = new TH1D("heightExp","heightExp",100,0,300e6);
	auto areaExp = new TH1D("areaExp","areaExp",100,0,1e10);
	auto baseline = new TH1D("baseline","baseline",100,-6e7,-8e7);
	

	ifstream ifs(file);
	while(ifs >>f1>>f2>>f3>>f4>>f5>>f6>>f7>>f8>>f9>>f10>>f11>>f12){
		tau->Fill(f4);
		height->Fill(f3*exp(-100/f4));
		chi2->Fill(f8);
		area->Fill( ( (-1*f4*exp(-900/f4)) -(-1*f4*exp(-100/f4)) )*f3);
		areaExp->Fill(f11);
		heightExp->Fill(f12);
		baseline->Fill(f10);


	}
	C->cd(1);
	tau->Draw();
	C->cd(2);
	chi2->Draw();
	C->cd(3);
	height->Draw();
	C->cd(4);
	area->Draw();
	C->cd(5);
	heightExp->Draw();
	C->cd(6);
	areaExp->Draw();
	C->cd(7);
	baseline->Draw();
	C->cd(8);

	
}
