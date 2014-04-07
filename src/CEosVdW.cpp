#include "CEosVdW.h"

using namespace std;

/// VdW's parameter "a" calculation.
void CEosVdW::Const_a (double Tc, double Pc, double const R)	
{const_a = (27.0*R*R*Tc*Tc)/(64.0*Pc);}	

/// VdW's parameter "b" calculation
void CEosVdW::Const_b (double Tc, double Pc, double const R)
{const_b = (R*Tc)/(8.0*Pc);}	

/// VdW's parameter "A" calculation.
void CEosVdW::Const_A(double a, double T, double P, double const R)
{const_A = (a*P)/(R*R*T*T);}	

/// VdW's parameter "B" calculation.
void CEosVdW::Const_B(double b, double T, double P, double const R)
{const_B = (b*P)/(R*T);}	

/// VdW's parameter "Alpha" calculation.
void CEosVdW::Alpha (double B)
{alpha=-1.0-B;}	

/// VdW's parameter "Beta" calculation.
void CEosVdW::Beta (double A)
{beta=A;}	

/// VdW's parameter "Gamma" calculation.
void CEosVdW::Gamma (double A, double B)
{gamma=-A*B;}
