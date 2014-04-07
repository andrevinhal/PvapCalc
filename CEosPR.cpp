#include "CEosPR.h"

using namespace std;

/// Peng-Robinson's parameter "aT" estimation.
void CEosPR::Const_aT (double w, double T, double Tc)
{const_aT = pow(1.0+(0.37464+1.5422*w-0.26922*w*w)*(1.0-sqrt(T/Tc)),2.0);}

/// Peng-Robinson's parameter "a" estimation.
void CEosPR::Const_a (double aT, double Tc, double Pc, double  R)
{const_a = ((0.45724*R*R*Tc*Tc/Pc)*aT);}

/// Peng-Robinson's parameter "b" estimation.
void CEosPR::Const_b (double Tc, double Pc, double  R)
{const_b = (0.07780*R*Tc)/Pc;}

/// Peng-Robinson's parameter "alpha" estimation.
void CEosPR::Alpha (double B)
{alpha=-1.0+B;}

/// Peng-Robinson's parameter "beta" estimation.
void CEosPR::Beta (double A, double B)
{beta=A-3.0*B*B-2.0*B;}

/// Peng-Robinson's parameter "gamma" estimation.
void CEosPR::Gamma (double A, double B)
{gamma=-A*B+B*B+B*B*B;}
