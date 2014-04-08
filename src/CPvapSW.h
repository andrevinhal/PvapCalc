#ifndef CPVAPSW_H
#define CPVAPSW_H
#include "CPvapPR.h"
#include "CEosSW.h"
#include "CFugSW.h"

class CPvapSW : public CPvapPR
{
protected:
	double const_w;
	double const_u;
	double bc;
	double zc;
	CEosSW sweos;	///< Object for calculation of PR's EoS parameters 
	CFugSW fugSW;	///< Object for calculation of the phase fugacity
	CNewtonMet solver;	///< Object for solving 3rd degree equation
			
public:
	std::vector<double> Pvap_Calc(int n, double Pc, double Tc, double w, double P, double T); ///< method for pvap estimation

/// Class constructor.
	CPvapSW()
	{cont=0;maxiter=100;control=1;const_u=0;const_w=0;bc=0;zc=0;ig=0;zl=0;zv=0;fv=0;fl=0;Pvap=0;};
	CPvapSW(double w);
/// Class destructor.
	~CPvapSW(){};
};

#endif // CPVAPSW_H

