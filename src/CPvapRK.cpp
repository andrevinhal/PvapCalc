#include "CPvapRK.h"

using namespace std;

CPvapRK::CPvapRK(double Tc, double Pc) {
	vdweos.Set_a_b(Tc, Pc);
}

/// This method calculates the Vapor Pressure of a substance using RK's EoS.
vector<double> CPvapRK::Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T){
	
	double aT, A, B, alpha, beta, gamma;
	
	for (int i=0; i<=n; i++)
	{
	/// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
		/// RK Parameters Calculation.
		A = rkeos.Const_A(T, P);	///< vdw constant A
		B = rkeos.Const_B(T, P);	///< vdw constant B

		alpha = rkeos.Alpha();	///< RK parameter Alpha
		beta = rkeos.Beta(A,B);		///< RK parameter Beta
		gamma = rkeos.Gamma(A,B);	///< RK parameter Gamma
		
		/// RK Fugacity Calculation.
		ig=(rkeos.Get_b()*P)/(R*T); ///< initial guess
	
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
