#ifndef CEOSRK_H
#define CEOSRK_H
#include "CEosVdW.h"

/**
*	This class calculates the Redlich-Kwong's 
* 	equation of state parameters
*/

class CEosRK : public CEosVdW
{

public:
	void Const_a(double Tc, double Pc, double const R); ///<Method for "a" estimation
	void Const_b(double Tc, double Pc, double const R); ///<Method for "b" estimation
	void Const_A(double a, double T, double P, double const R); ///<Method for "A" estimation
	void Const_B(double b, double T, double P, double const R); ///<Method for "B" estimation
	void Alpha (); ///< Method for "alpha" estimation
	void Beta (double A, double B); ///< Method for "beta" estimation
	void Gamma (double A, double B); ///< Method for "gamma" estimation
};
#endif // CEOSRK_H
