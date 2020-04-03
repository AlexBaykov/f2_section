#include "section.h"
#include "getCorrections.h"
#include "getExperimental.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_deriv.h>
#include "TROOT.h"
#include "TCanvas.h"
#include "TGraph.h"
#include "TFile.h"


int main(){
	double E[401];
	double visibleCS[401];
	double bornCS[401];
//	double vacpol = 1.0112824;
	double pars[4] = {1275.1, 185.1, 1.6e-10, 0.28267};

	for(int i = 0; i < 401; i++){
		E[i] = 1100 + i; 
		visibleCS[i] = getCorrections(E[i], pars)*0.3894e12; 
		bornCS[i] = born(E[i]*E[i], pars)*0.3894e12; 
		std::cout << "   " << i + 1 << "    " << E[i] << "     " << bornCS[i] << std::endl;
	}

	TFile *f = new TFile("sections.root", "recreate");
	TGraph *gr = new TGraph(401, E, visibleCS);
	TGraph *gr1 = new TGraph(401, E, bornCS);

	gr->SetLineColor(2);
	gr->SetLineWidth(3);
	gr1->SetLineWidth(3);
	gr1->SetLineColor(4);
	gr->Write();
	gr1->Write();
	f->Close();
	return 0;
}

