#include "CEosPR.h"

using namespace std;

CEosPR::CEosPR() : CEosSoave() {};

/// PR parameter a and b estimation.
void CEosPR::Set_a_b(double Tc, double Pc) {
	const_a = (0.45724*R*R*Tc*Tc)/Pc;
	const_b = (0.07780*R*Tc)/Pc;
}

/// PR parameter "aT" calculation.
double CEosPR::Const_aT (double w, double T, double Tc)
{return pow(1.0+(0.37464+1.5422*w-0.26922*w*w)*(1.0-sqrt(T/Tc)),2.0);}

/// PR parameter "alpha" estimation.
double CEosPR::Alpha (double B)
{return -1.0+B;}

/// PR parameter "beta" estimation.
double CEosPR::Beta (double A, double B)
{return A-3.0*B*B-2.0*B;}

/// PR parameter "gamma" estimation.
double CEosPR::Gamma (double A, double B)
{return -A*B+B*B+B*B*B;}
