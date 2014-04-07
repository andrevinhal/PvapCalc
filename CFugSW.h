#ifndef CFUGSW_H
#define CFUGSW_H

#include "CFugPR.h" // inheriting class's header file

/*
 * No description
 */
class CFugSW : public CFugPR
{
public:
	void Fug_Calc(double P, double zl, double zv, double A, double B, double u, double w); ///< method for fug. calc.
};

#endif // CFUGSW_H

