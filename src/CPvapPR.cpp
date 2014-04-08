#include "CPvapPR.h"

using namespace std;

CPvapPR::CPvapPR(double Tc, double Pc) {
	srkeos.Set_a_b(Tc, Pc);
}

/// This method calculates the Vapor Pressure of a substance using PR's EoS.
vector<double> CPvapPR::Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T){
	
	double aT, A, B, alpha, beta, gamma;
	
	for (int i=0; i<=n; i++)
	{  
	///Pressure iteration.
		while ((control>0.0001) && (cont < maxiter))
		{
		///PR Parameters Calculation.
		aT =preos.Const_aT(w,T,Tc); ///< Soave parameter "aT"
		
		A = preos.Const_A(aT, T, P); ///< Soave parameter "A"
		B = preos.Const_B(T, P); ///< Soave parameter "B"

		alpha = preos.Alpha(B);	///< SRK parameter Alpha
		beta = preos.Beta(A,B);	///< SRK parameter Beta
		gamma = preos.Gamma(A,B);	///< SRK parameter Gamma
		
		///PR Fugacity Calculation.
		ig=(preos.Get_b()*P*P)/(R*T); ///< initial guess.
	
		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree equation solver

		zl = solver.Get_zl();	///< smallest positive root - zl
		zv = solver.Get_zv();	///< biggest positive root - zv
	
		fugPR.Fug_Calc(P, zl, zv, A, B); 	///< PR's fugacity calculation
	
		fl = fugPR.Get_fl();	///< PR's liquid fugacity
		fv = fugPR.Get_fv();	///< PR's vapor fugacity
	
		control = abs(fl/fv-1);	///< iteration control

		P = P*fl/fv;
		cont++;
		}	
	Pvap=P;	///< Vapor pressure
	Pf.push_back(Pvap);	///< Vapor pressure vector
	T++;  ///<increasing temperature
	cont=0;	maxiter=100; control=1; ///< reinitializing iteration variables
	}
return Pf;
}
