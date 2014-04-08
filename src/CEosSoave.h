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
	//double const_aT; ///< EOS parameter "aT"
	double w; ///< acentric factor
	
public:
	void Set_a_b(double Tc, double Pc); ///< method for calculating "a" and "b" Soave's parameters
			
	double Const_aT(double w, double T, double Tc); ///< method for calculating "aT"
	double Const_A(double aT, double T, double P); ///< method for calculating "A"
		
/// Class Constructor.
	CEosSoave();

/// Class Destructor.	
	~CEosSoave(){};

};
#endif // CEOSSOAVE_H


