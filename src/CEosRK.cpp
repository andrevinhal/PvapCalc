#include "CEosRK.h"

using namespace std;

CEosRK::CEosRK() : CEosVdW() {};

/// RK parameter a and b estimation.
void CEosRK::Set_a_b(double Tc, double Pc) {
	const_a = (0.4278*R*R*pow(Tc,2.5))/Pc;
	const_b = (0.0867*R*Tc)/Pc;
}

/// RK parameter A estimation.
double CEosRK::Const_A(double T, double P) {
	return (const_a*P)/(R*R*pow(T,2.5));
}

/// RK parameter B estimation.
double CEosRK::Const_B(double T, double P) {
	return (const_b*P)/(R*T);
}

/// RK parameter Alpha estimation.
double CEosRK::Alpha() {
	return -1.0;
}

/// RK parameter Beta estimation.
double CEosRK::Beta(double A, double B) {
	return A-B-B*B;
}

