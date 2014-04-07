#ifndef CEOSVDW_H
#define CEOSVDW_H
#include <iostream>
#include <cmath>

/**
 * This class calculates van der Waals equation
 * of state parameters
 */
 
class CEosVdW
{
protected:
	double R;
	double const_a;///< EOS parameter "a"
	double const_b;///< EOS parameter "b"
	
public:
	double Get_a() {return const_a;};///< return "a"
	double Get_b() {return const_b;};///< return "b"
	
	void Set_a_b(double Tc, double Pc);
			
	double Const_A(double T, double P);
	double Const_B(double T, double P);
	
	double Alpha (double B); ///< method for "alpha" estimation
	double Beta (double A); ///< method for "beta" estimation
	double Gamma (double A, double B); ///< method for "gamma" estimation
	
/// Class Constructor.
	CEosVdW(){ R=83.14; const_a=0; const_b=0; };
	CEosVdW(double Tc, double Pc);

/// Class Destructor.	
	~CEosVdW(){};
};
	
#endif //CEOSVDW_H

