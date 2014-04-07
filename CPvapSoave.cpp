#include "CPvapSoave.h"

using namespace std;

/// This method calculates the Vapor Pressure of a substance using Soave's EoS.
vector<double> CPvapSoave::Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T)
{
	for (int i=0; i<=n; i++)
	{
/// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
/// 	Soave-Redlich-Kwong Parameters Calculation.
		srkeos.Const_aT(w,T,Tc); ///< Soave parameter "aT"
		aT=srkeos.Get_aT();

		srkeos.Const_a(aT, Tc, Pc, R); ///< Soave parameter "a"
		srkeos.Const_b(Tc, Pc, R); ///< Soave parameter "b"
		a = srkeos.Get_a();	
		b = srkeos.Get_b();

		srkeos.Const_A(a, T, P, R); ///< Soave parameter "A"
		srkeos.Const_B(b, T, P, R); ///< Soave parameter "B"
		A = srkeos.Get_A();
		B = srkeos.Get_B();

		srkeos.Alpha();	///< Soave parameter "Alpha"
		srkeos.Beta(A,B); ///< Soave parameter "Beta"
		srkeos.Gamma(A,B); ///< Soave parameter "Gamma"
		alpha = srkeos.Get_Alpha();
		beta = srkeos.Get_Beta();
		gamma = srkeos.Get_Gamma();
	 
/// RK Fugacity Calculation.
		ig=(b*P)/(R*T); ///< initial guess

		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree eqauation solver

		zl = solver.Get_zl(); ///< smallest positive root - zl
		zv = solver.Get_zv(); ///< biggest positive root - zv

		fugSoave.Fug_Calc(P, zl, zv, A, B); ///< Soave-Redlich-Kwong fugacity calculation
	
		fl = fugSoave.Get_fl(); ///< Redlich-Kwong liquid fugacity
		fv = fugSoave.Get_fv(); ///< Redlich-Kwong vapor fugacity

		control = abs(fl/fv-1); ///< iteration control

		P = P*fl/fv;

		cont++;
		}	
		
	Pvap=P;	///< Vapor pressure
	Pf.push_back(Pvap); ///< Vapor pressure vector
	T++;  ///<increasing temperature
	cont=0;	maxiter=100; control=1; ///< reinitializing iteration variables
	}
return Pf;
}
