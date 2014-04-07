#include "CEosRK.h"

using namespace std;

/// RK parameter a estimation.
void CEosRK::Const_a (double Tc, double Pc, double const R)
{const_a = (0.4278*R*R*pow(Tc,2.5))/Pc;}

/// RK parameter b estimation.
void CEosRK::Const_b (double Tc, double Pc, double const  R)
{const_b = (0.0867*R*Tc)/Pc;}

/// RK parameter A estimation.
void CEosRK::Const_A(double a, double T, double P, double const R)
{const_A = (a*P)/(R*R*pow(T,2.5));}

/// RK parameter B estimation.
void CEosRK::Const_B(double b, double T, double P, double const R)
{const_B = (b*P)/(R*T);}

/// RK parameter Alpha estimation.
void CEosRK::Alpha ()
{alpha=-1.0;}

/// RK parameter Beta estimation.
void CEosRK::Beta (double A, double B)
{beta=A-B-B*B;}

/// RK parameter Gamma estimation.
void CEosRK::Gamma (double A, double B)
{gamma=-A*B;}


