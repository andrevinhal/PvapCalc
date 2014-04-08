#ifndef CEOSSW_H
#define CEOSSW_H
#include "CEosPR.h"

/*
 * No description
 */
class CEosSW : public CEosPR
{
	protected:
		double const_u;
		double const_w;
		double bc;
		double zc;

				
	public:
		void Set_u_w_bc_zc(double w);
		
		double Const_a(double aT, double Tc, double Pc); ///< Method for "a" estimation
		double Const_b(double Tc, double Pc); ///< Method for "b" estimation
		double Const_aT(double w, double T, double Tc); ///< Method for "aT" estimation
		double Const_A(double a, double T, double P);
		double Const_B(double b, double T, double P);
		double Alpha (double const_u, double B); ///< method for "alpha" estimation
		double Beta (double const_u, double const_w, double A, double B); ///< method for "beta" estimation
		double Gamma (double const_w, double A, double B); ///< method for "gamma" estimation
		
/// Class Constructor.
	CEosSW();

/// Class Destructor.	
	~CEosSW(){};
};

#endif // CEOSSW_H

