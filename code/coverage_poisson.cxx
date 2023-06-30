#include <cmath>
#include <iostream>
#include <fstream>

double prob(double n, double mu)
{
	// Implement the Poisson pdf here
	double value = 0;

	return value;
}

double Cmu(double mu)
{
	// sum over all probabilities inside the
	// coverage interval, then return the value of the coverage for the provided value of mu

	// let the sum run up to a very high value
	int nmax = 1000;
	double sum = 0.;
	for (int n=0; n<nmax; ++n){


	}
	return sum;
}

int main()
{
	using namespace std;

	double mu;
	mu = 0;
	cout << "mu = " << mu << "  Coverage = " << Cmu(mu) << endl;
	mu = 1; 
	cout << "mu = " << mu << "  Coverage = " << Cmu(mu) << endl;
	mu = 3; 
	cout << "mu = " << mu << "  Coverage = " << Cmu(mu) << endl;
	mu = 10; 
	cout << "mu = " << mu << "  Coverage = " << Cmu(mu) << endl;


	// write out the values obtained as a function of mu
	std::ofstream fout("cmu.txt"); 
	int nmax = 1000;
	for (int n=0; n<nmax; ++n){
		double step = 20./nmax;
		double mu = n*step; 
		double coverage = Cmu(mu);	
		//cout << "C(" << mu << ") = " << coverage << endl;
	    fout << mu << " ";
	    fout << coverage << " " << std::endl;
    }
  fout.close();

}
