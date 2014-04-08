#ifndef CEOSPR_H
#define CEOSPR_H
#include "CEosSoave.h"

/**
*	This class calculates the parameters
*	of Peng-Robinson's equation of state
*/

class CEosPR : public CEosSoave
{
public:
	void Set_a_b(double Tc, double Pc); ///< method for calculating "a" and "b" PR's parameters
			
	double Const_aT(double w, double T, double Tc); ///< method for calculating "aT"
	
	double Alpha (double B); ///< Method for "alpha" estimation
	double Beta (double A, double B); ///< Method for "beta" estimation
	double Gamma (double A, double B); ///< Method for "gamma" estimation
		
/// Class Constructor.
	CEosPR();

/// Class Destructor.	
	~CEosPR(){};
};
#endif // CEOSPR_H
