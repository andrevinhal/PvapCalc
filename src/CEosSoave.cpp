#include "CEosSoave.h"

using namespace std;
//
///// Soave's parameter "aT" calculation.
//void CEosSoave::Const_aT (double w, double T, double Tc)
//{const_aT = pow((1.0+(0.480+1.57*w-0.176*w*w)*(1.0-sqrt(T/Tc))),2.0);}
//
///// Soave's parameter "a" calculation.
//void CEosSoave::Const_a (double aT, double Tc, double Pc, double  R)
//{const_a = ((0.4274*R*R*Tc*Tc/Pc)*aT);}
//
///// Soave's parameter "A" calculation.
//void CEosSoave::Const_A(double a, double T, double P, double R)
//{const_A = (a*P)/(R*R*T*T);}
