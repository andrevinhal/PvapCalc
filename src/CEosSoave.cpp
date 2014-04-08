#include "CEosSoave.h"

using namespace std;

CEosSoave::CEosSoave() : CEosRK() {};

/// SRK parameter a and b estimation.
void CEosSoave::Set_a_b(double Tc, double Pc) {
	const_a = (0.4274*R*R*Tc*Tc)/Pc;
	const_b = (0.08664*R*Tc)/Pc;
}

/// Soave's parameter "aT" calculation.
double CEosSoave::Const_aT (double w, double T, double Tc)
{return pow((1.0+(0.480+1.57*w-0.176*w*w)*(1.0-sqrt(T/Tc))),2.0);}

/// Soave's parameter "A" calculation.
double CEosSoave::Const_A(double aT, double T, double P)
{return (const_a*aT*P)/(R*R*T*T);}
