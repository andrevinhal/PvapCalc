#ifndef CPVAPRK_H
#define CPVAPRK_H
#include "CPvapVdW.h"
#include "CEosRK.h"
#include "CFugRK.h"

/**
*	This class calculates the vapor pressure of
* the liquid and vapor phases of a Redlich-Kwong's fluid
*/

class CPvapRK : public CPvapVdW
{
//protected:
//	CEosRK rkeos; 	///< Object for calculation of RK's EoS parameters 
//	CFugRK fugRK;	///< Object for calculation of the phase fugacity
//	CNewtonMet solver; ///< Object for solving 3rd degree equation 
//
//public:
//	std::vector<double> Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T); ///< method for pvap estimation
//	
///// Class constructor.
//	CPvapRK()
//	{cont=0;maxiter=100;control=1;a=0;b=0;A=0;B=0;alpha=0;beta=0;gamma=0;ig=0;zl=0;zv=0;fv=0;fl=0;Pvap=0;};		
//	
///// Class destructor.
//	~CPvapRK(){};
};

#endif // CPVAPRK_H
