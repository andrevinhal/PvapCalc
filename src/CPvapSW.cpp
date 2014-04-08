#include "CPvapSW.h" // class's header file

using namespace std;

CPvapSW::CPvapSW(double w) {
	sweos.Set_u_w_bc_zc(w);
}

/// This method calculates the Vapor Pressure of a substance using SW's EoS.
vector<double> CPvapSW::Pvap_Calc(int n, double Pc, double Tc, double w, double P, double T){
	
	double aT, a, b, A, B, alpha, beta, gamma;
	
	for (int i=0; i<=n; i++)
	{  
	// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
		/// PR Parameters Calculation.
		aT = sweos.Const_aT(w,T,Tc); ///< PR's constant aT
	
		a = sweos.Const_a(aT, Tc, Pc);	///< PR's parameter "a"
		b = sweos.Const_b(Tc, Pc);	///< PR's parameter "b"

		A = sweos.Const_A(a, T, P);	///< PR's parameter "A"
		B = sweos.Const_B(b, T, P);	///< PR's parameter "B"

		alpha = sweos.Alpha(const_u, B);	///< PR's parameter "alpha"
		beta = sweos.Beta(const_u, const_w, A, B);	///< PR's parameter "beta"
		gamma =sweos.Gamma(const_w, A, B);	///< PR's parameter "gamma"
		
/// PR Fugacity Calculation.
		ig=(b*P)/(R*T); ///< initial guess.
	
		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree equation solver

		zl = solver.Get_zl();	///< smallest positive root - zl
		zv = solver.Get_zv();	///< biggest positive root - zv
		
		fugSW.Fug_Calc(P, zl, zv, A, B, const_u, const_w); 	///< PR's fugacity calculation
	
		fl = fugSW.Get_fl();	///< PR's liquid fugacity
		fv = fugSW.Get_fv();	///< PR's vapor fugacity
	
		control = abs(fl/fv-1);	///< iteration control
		
		P = P*fl/fv;
		}	
	Pvap=P;	///< Vapor pressure
	Pf.push_back(Pvap);	///< Vapor pressure vector
	T++;  ///<increasing temperature
	cont=0;	maxiter=100; control=1; ///< reinitializing iteration variables
	}
return Pf;
}

