#ifndef CPVAPVDW_H
#define CPVAPVDW_H
#include <vector>
#include "CEosVdW.h"
#include "CFugVdW.h"
#include "CNewtonMet.h"

/**
*	This class calculates the vapor pressure of
* the liquid and vapor phases of a VdW's fluid
*/

class CPvapVdW
{
protected:
	CEosVdW vdweos;	///< Object for calculation of vdW's EoS parameters 
	CFugVdW fugVdW; ///< Object for calculation of the phase fugacity
	CNewtonMet solver; ///< Object for solving 3rd degree equation 
	
	double R;
	double ig; ///< initial guess 
	double zl; ///< liq. comp. factor 
	double zv; ///< vap. comp. factor
	double fv; ///< vapor fugacity
	double fl; ///< liquid fugacity
	double Pvap; ///< Vapor pressure
	double control;	///< iteration control
	int maxiter; ///< max iteration 
	int cont; ///< iteration counter
	
	std::vector<double> Pf; ///< vapor pressure vector
	
public:
	std::vector<double> Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T); ///< method for pvap estimation
	std::vector<double> Pvap_Calc(int n, double Pc, double Tc, double P, double T); ///< method for pvap estimation
	double Get_Pvap() {return Pvap;}; ///< return pvap

/// Class Constructor.
	CPvapVdW()
	{cont=0;maxiter=100;control=1.0;ig=0;zl=0;zv=0;fv=0;fl=0;Pvap=0; R=83.14;};
	
	CPvapVdW(double Tc, double Pc);

/// Class Destructor.	
	~CPvapVdW(){};
};

#endif // CPVAPVDW_H
