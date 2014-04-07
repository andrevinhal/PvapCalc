#ifndef CEOSSOAVE_H
#define CEOSSOAVE_H
#include "CEosRK.h"

/**
*	This class calculates the parameters of 
* 	Soave's equation of state
*/

class CEosSoave : public CEosRK
{
protected:
	double const_aT; ///< EOS parameter "aT"
	
public:
	void Const_a(double aT, double Tc, double Pc, double const R); ///< method for calculating "a"
	void Const_A(double a, double T, double P, double R);///< method for calculating "A"
	void Const_aT(double w, double T, double Tc); ///< method for calculating "alpha"
	double Get_aT(){ return const_aT;}; ///< return "aT" 
};
#endif // CEOSSOAVE_H


