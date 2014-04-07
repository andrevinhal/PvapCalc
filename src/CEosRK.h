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
	CEosRK();
	
	void Set_a_b(double Tc, double Pc);
	
	double Const_A(double T, double P);
	double Const_B(double T, double P);
	
	double Alpha (); ///< method for "alpha" estimation
	double Beta (double A, double B); ///< method for "beta" estimation
				
	
};
#endif // CEOSRK_H
