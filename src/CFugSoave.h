#ifndef CFUGSOAVE_H
#define CFUGSOAVE_H
#include "CFugRK.h"

/**
*	This class calculates the fugacity of 
* 	the liquid and vapor phases of a Soave's fluid
*/

class CFugSoave : public CFugRK
{
public:
	void Fug_Calc (double P, double zl, double zv, double A, double B); ///< method for fug. calc.
};

#endif // CFUGSOAVE_H

