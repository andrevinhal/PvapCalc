#ifndef CFUGRK_H
#define CFUGRK_H
#include "CFugVdW.h"

/**
*	This class calculates the fugacity of 
* the liquid and vapor phases of a RK's fluid
*/

class CFugRK : public CFugVdW
{
public:
	void Fug_Calc(double P, double zl, double zv, double A, double B); ///< method for fug. calc.
};

#endif // CFUGRK_H
