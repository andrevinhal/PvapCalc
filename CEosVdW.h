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
	double const_a;///< EOS parameter "a"
	double const_b;///< EOS parameter "b"
	double const_A;///< EOS parameter "A"
	double const_B;///< EOS parameter "a"
	double alpha;///< EOS parameter "alpha"
	double beta;///< EOS parameter "beta"
	double gamma;///< EOS parameter "gamma"

public:
	double Get_a() {return const_a;};///< return "a"
	double Get_b() {return const_b;};///< return "b"
	double Get_A() {return const_A;}; ///< return "A"
	double Get_B() {return const_B;};///< return "B"
	double Get_Alpha() {return alpha;};///< return "alpha"
	double Get_Beta() {return beta;};///< return "beta"
	double Get_Gamma(){return gamma;};///< return "gamma"
		
	void Const_a(double Tc, double Pc, double const R); ///< method for "a" estimation
	void Const_b(double Tc, double Pc, double const R); ///< method for "b" estimation
	void Const_A(double a, double T, double P, double const R); ///< method for "A" estimation
	void Const_B(double b, double T, double P, double const R); ///< method for "B" estimation
	void Alpha (double B); ///< method for "alpha" estimation
	void Beta (double A); ///< method for "beta" estimation
	void Gamma (double A, double B); ///< method for "gamma" estimation
	
/// Class Constructor.
	CEosVdW(){const_a=0;const_b=0;const_A=0;const_B=0;alpha=0;beta=0;gamma=0;};

/// Class Destructor.	
	~CEosVdW(){};
};
	
#endif //CEOSVDW_H

