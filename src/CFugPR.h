#ifndef CFUGPR_H
#define CFUGPR_H
#include "CFugSoave.h"

/**
*	This class determines the fugacity of the
*	liquid and vapor phases of a Peng-Robinson's fluid
*/

class CFugPR : public CFugSoave
{
public:
	void Fug_Calc(double P, double zl, double zv, double A, double B); ///< method for fug. calc.
};

#endif // CFUGPR_H
