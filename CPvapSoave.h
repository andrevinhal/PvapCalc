#ifndef CPVAPSOAVE_H
#define CPVAPSOAVE_H
#include "CPvapRK.h"
#include "CEosSoave.h"
#include "CFugSoave.h"

/**
*	This class calculates the vapor pressure of
* the liquid and vapor phases of a Soave's fluid
*/

class CPvapSoave : public CPvapRK
{
protected:
	CEosSoave srkeos; ///< Object for calculation of Soave's EoS parameters 
	CFugSoave fugSoave; ///< Object for calculation of the phase fugacity
	CNewtonMet solver; ///< Object for solving 3rd degree equation 
	
	double aT; ///< parameter "aT"
			
public:
	std::vector<double> Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T); ///< method for pvap estimation
	
/// Class constructor.
	CPvapSoave()
	{cont=0;maxiter=100;control=1;aT=0;a=0;b=0;A=0;B=0;alpha=0;beta=0;gamma=0;ig=0;zl=0;zv=0;fv=0;fl=0;Pvap=0;};
	
/// Class destructor.
	~CPvapSoave(){};
};

#endif // CPVAPSOAVE_H
