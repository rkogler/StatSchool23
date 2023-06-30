#include <cmath>
#include <iostream>
#include <fstream>

void plot_cov()
{
	using namespace std;
	gROOT->SetStyle("Plain");
	gStyle->SetOptStat(0);

	int nmax = 1000;
	TGraph* g = new TGraph(nmax);

	// open file
	string line;
  	ifstream infile ("cmu.txt");
  	if (infile.is_open()){
  		int i=0;
  		while (!infile.eof()){
  			double mu, coverage;
  			infile >> mu;
  			infile >> coverage; 
  			g->SetPoint(i, mu, coverage);
  			++i;
  			//cout << "mu = " << mu << " cmu = " << cmu << endl;
  		}
        infile.close();
    }	

	TH1* h = g->GetHistogram();
	h->SetTitle("");
	h->GetXaxis()->SetTitle("#mu");
	h->GetXaxis()->SetTitleSize(0.055);
	h->GetXaxis()->SetTitleOffset(0.8);
	h->GetYaxis()->SetTitle("C(#mu)");
	h->GetYaxis()->SetTitleSize(0.055);
	h->GetYaxis()->SetTitleOffset(0.8);
	h->GetYaxis()->SetRangeUser(0,1);
	h->GetXaxis()->SetRangeUser(0,20);
	h->Draw();

	// draw line for 68% Coverage
	double lim = 0.68;
	TLine* l = new TLine(0, lim, 20, lim);
	l->SetLineColor(kRed+1);
	l->SetLineWidth(1);
	l->SetLineStyle(kDotted);
	l->Draw();
	g->SetMarkerSize(0.4);
	g->SetMarkerStyle(20);
	g->Draw("P same");
}
