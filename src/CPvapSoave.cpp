#include "CPvapSoave.h"

using namespace std;

CPvapSoave::CPvapSoave(double Tc, double Pc) {
	srkeos.Set_a_b(Tc, Pc);
}

/// This method calculates the Vapor Pressure of a substance using Soave's EoS.
vector<double> CPvapSoave::Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T){
	
	double aT, A, B, alpha, beta, gamma;
	
	for (int i=0; i<=n; i++)
	{
	///Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
		///Soave-Redlich-Kwong Parameters Calculation.
		aT =srkeos.Const_aT(w,T,Tc); ///< Soave parameter "aT"
		
		A = srkeos.Const_A(aT, T, P); ///< Soave parameter "A"
		B = srkeos.Const_B(T, P); ///< Soave parameter "B"

		alpha = srkeos.Alpha();	///< SRK parameter Alpha
		beta = srkeos.Beta(A,B);	///< SRK parameter Beta
		gamma = srkeos.Gamma(A,B);	///< SRK parameter Gamma
	 
		/// RK Fugacity Calculation.
		ig=(srkeos.Get_b()*P)/(R*T); ///< initial guess

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
