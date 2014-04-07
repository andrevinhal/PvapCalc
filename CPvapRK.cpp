#include "CPvapRK.h"

using namespace std;

/// This method calculates the Vapor Pressure of a substance using RK's EoS.
vector<double> CPvapRK::Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T)
{
	for (int i=0; i<=n; i++)
	{
/// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
/// RK Parameters Calculation.
		rkeos.Const_a(Tc, Pc, R);	///< RK parameter a
		rkeos.Const_b(Tc, Pc, R);	///< RK parameter b
		a = rkeos.Get_a();		
		b = rkeos.Get_b();

		rkeos.Const_A(a, T, P, R);	///< RK parameter A
		rkeos.Const_B(b, T, P, R);	///< RK parameter B
		A = rkeos.Get_A();
		B = rkeos.Get_B();

		rkeos.Beta(A,B);	///< RK parameter Beta
		rkeos.Alpha();		///< RK parameter Alpha
		rkeos.Gamma(A,B);	///< RK parameter Gamma
		alpha = rkeos.Get_Alpha();
		beta = rkeos.Get_Beta();
		gamma = rkeos.Get_Gamma(); 

/// RK Fugacity Calculation.

		ig=(b*P)/(R*T); ///< initial guess
	
		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree equation solver
	
		zl = solver.Get_zl();	///< smallest positive root - zl
		zv = solver.Get_zv();	///< biggest positive root - zv
	
		fugRK.Fug_Calc(P, zl, zv, A, B);	///< Redlich-Kwong fugacity calculation
		
		fl = fugRK.Get_fl();	///< Redlich-Kwong liquid fugacity
		fv = fugRK.Get_fv();	///< Redlich-Kwong vapor fugacity
	
		control = abs(fl/fv-1);	///< iteration control

		P = P*fl/fv;					
		cont++;
		}
	Pvap=P;	///< Vapor pressure
	Pf.push_back(Pvap);  ///< Vapor pressure vector
	T++;  ///<increasing temperature
	cont=0; maxiter=100; control=1;  ///< reinitializing iteration variables
	}
return Pf;
}

