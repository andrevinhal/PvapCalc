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
		double omega_a, omega_b;
		double kappa, kappa_o;
				
	public:
		void Const_w(double w);
		void Const_u();
		void Bc(double w);
		void Zc(double w, double bc);
		
		void Const_a(double bc, double zc, double aT, double Tc, double Pc, double  R); ///< Method for "a" estimation
		void Const_b(double bc, double zc, double Tc, double Pc, double  R); ///< Method for "b" estimation
		void Const_aT(double w, double T, double Tc); ///< Method for "aT" estimation
		void Alpha (double const_u, double B); ///< method for "alpha" estimation
		void Beta (double const_u, double const_w, double A, double B); ///< method for "beta" estimation
		void Gamma (double const_w, double A, double B); ///< method for "gamma" estimation
		
		double Get_u(){return const_u;};
		double Get_w(){return const_w;};
		double Get_Bc(){return bc;};
		double Get_Zc(){return zc;};
};

#endif // CEOSSW_H

