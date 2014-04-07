#include "CEosVdW.h"

using namespace std;

/// Overloaded Constructor
CEosVdW::CEosVdW(double Tc, double Pc){
	R = 83.14;
	const_a = (27.0*R*R*Tc*Tc)/(64.0*Pc);
	const_b = (R*Tc)/(8.0*Pc);
}
/// VdW's parameter "a" calculation.
//void CEosVdW::Const_a (double Tc, double Pc, double const R)	
//{const_a = (27.0*R*R*Tc*Tc)/(64.0*Pc);}	

/// VdW's parameter "b" calculation
//void CEosVdW::Const_b (double Tc, double Pc, double const R)
//{const_b = (R*Tc)/(8.0*Pc);}	

/// VdW's parameter "A" calculation.
double CEosVdW::Const_A(double T, double P)
{
	return ((const_a*P)/(R*R*T*T));
}	

/// VdW's parameter "B" calculation.
double CEosVdW::Const_B(double T, double P)
{
	return ( (const_b*P)/(R*T) );
}	

/// VdW's parameter "Alpha" calculation.
double CEosVdW::Alpha (double B)
{
	return (-1.0 - B);
}	

/// VdW's parameter "Beta" calculation.
double CEosVdW::Beta (double A)
{
	return A;
}	

/// VdW's parameter "Gamma" calculation.
double CEosVdW::Gamma (double A, double B)
{
	return -A*B;
}

void CEosVdW::Set_a_b(double Tc, double Pc) {
	const_a = (27.0*R*R*Tc*Tc)/(64.0*Pc);
	const_b = (R*Tc)/(8.0*Pc);
}
