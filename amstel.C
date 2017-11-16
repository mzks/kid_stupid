#define amstel_cxx
#include "amstel.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void amstel::Loop()
{
//   In a ROOT session, you can do:
//      root> .L amstel.C
//      root> amstel t
//      root> t.GetEntry(12); // Fill t data members with entry number 12
//      root> t.Show();       // Show values of entry 12
//      root> t.Show(16);     // Read and show values of entry 16
//      root> t.Loop();       // Loop on all entries
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

	const Double_t MIN =100;
	const Double_t MAX =900;

	ofstream ofs("fit.txt");

   if (fChain == 0) return;

   Long64_t nentries = fChain->GetEntriesFast();

   Long64_t nbytes = 0, nb = 0;


   for (Long64_t jentry=0; jentry<nentries;jentry++) {
   //for (Long64_t jentry=0; jentry<1;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      // if (Cut(ientry) < 0) continue;

	  //calc baseline using first 90 data;
	  const Int_t firstBin = 90;
	  Double_t baseline = 0;
	  for(int i=0;i<firstBin;i++){
		  baseline += Q->at(i);
	  }
	  baseline = baseline / firstBin;

	  //calc area and pulse height
	  Double_t pulseHeight = 0;
	  Double_t area = 0;
	  for(int i=firstBin;i<1000;i++){
		  if(Q->at(i) < pulseHeight) pulseHeight = Q->at(i);
		  area += baseline - Q->at(i);
	  }
	  pulseHeight = baseline - pulseHeight;


	  //auto C = new TCanvas();
	  auto tg = new TGraph(T->size(),T->data(),Q->data());
	  tg->Draw();
	  
	  auto decayfunc = new TF1("decayfunc","-1*[0]-[1]*exp(-1*x/[2])",MIN,MAX);

	  double Ninit = 80e6;
	  double Cinit = 1.0e9;
	  double tauinit = 30;

	  decayfunc->SetParName(0,"N");
	  decayfunc->SetParameter(0,Ninit);
	  decayfunc->SetParLimits(0,Ninit*0.8,Ninit*1.2);
	  decayfunc->SetParName(1,"C");
	  decayfunc->SetParameter(1,Cinit);
	  decayfunc->SetParLimits(1,Cinit*0.1,Cinit*10.2);
	  decayfunc->SetParName(2,"tau");
	  decayfunc->SetParameter(2,tauinit);
	  decayfunc->SetParLimits(2,tauinit*0.6,tauinit*1.8);

	 tg->Fit("decayfunc","","",MIN,MAX);

	 //stringstream ss;
	 //ss << "fig/fig" << jentry << ".pdf";
	 //TString file = ss.str();
	 //C->SaveAs(file);

	 ofs << jentry << " "
		 << decayfunc->GetParameter(0) << " " 
	     << decayfunc->GetParameter(1) << " " 
	     << decayfunc->GetParameter(2) << " "
		 << decayfunc->GetParError(0) << " " 
	     << decayfunc->GetParError(1) << " " 
	     << decayfunc->GetParError(2) << " "
	     << decayfunc->GetChisquare() << " "
	     << decayfunc->GetNDF() << " "
		 << baseline << " "
		 << area << " "
		 << pulseHeight << endl;

	delete tg;


   }
}
