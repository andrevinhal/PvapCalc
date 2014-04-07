#ifndef CNEWTONMET_H
#define CNEWTONMET_H
#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * This class finds the roots of the 3rd degree equation 
 * of state in terms of the compressibility factor
 */
 
class CNewtonMet
{
private:
	double zv; ///< compressibility factor of the vapor phase
	double zl; ///< compressibility factor of the liquid phase
	double control;	int maxiter, cont; ///< iteration variables			

public:
	void Z_Calc(double alpha, double beta, double gamma, double ig); ///<
	double Get_zl() {return zl;};
	double Get_zv() {return zv;};
	
/// Class constructor.
	CNewtonMet(){control=1.0;maxiter=100;cont=0;};
	
/// Class destructor.
	~CNewtonMet(){};
};

#endif // CNEWTONMET_H

