#include "CPvapPR.h"


using namespace std;
//
///// This method calculates the Vapor Pressure of a substance using PR's EoS.
//vector<double> CPvapPR::Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T)
//{
//	for (int i=0; i<=n; i++)
//	{  
//// Pressure iteration.
//		while ((control>0.0001) && (cont < maxiter))
//		{
///// PR Parameters Calculation.
//		preos.Const_aT(w,T,Tc); ///< PR's constant aT
//		aT=preos.Get_aT();
//
//		preos.Const_a(aT, Tc, Pc, R);	///< PR's parameter "a"
//		preos.Const_b(Tc, Pc, R);	///< PR's parameter "b"
//
//		a = preos.Get_a();	
//		b = preos.Get_b();
//		
//		preos.Const_A(a, T, P, R);	///< PR's parameter "A"
//		preos.Const_B(b, T, P, R);	///< PR's parameter "B"
//
//		A = preos.Get_A();
//		B = preos.Get_B();
//		
//		preos.Alpha(B);		///< PR's parameter "alpha"
//		preos.Beta(A,B);	///< PR's parameter "beta"
//		preos.Gamma(A,B);	///< PR's parameter "gamma"
//
//		alpha = preos.Get_Alpha();
//		beta = preos.Get_Beta();
//		gamma = preos.Get_Gamma(); 
//
///// PR Fugacity Calculation.
//		ig=(b*P)/(R*T); ///< initial guess.
//	
//		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree equation solver
//
//		zl = solver.Get_zl();	///< smallest positive root - zl
//		zv = solver.Get_zv();	///< biggest positive root - zv
//	
//		fugPR.Fug_Calc(P, zl, zv, A, B); 	///< PR's fugacity calculation
//	
//		fl = fugPR.Get_fl();	///< PR's liquid fugacity
//		fv = fugPR.Get_fv();	///< PR's vapor fugacity
//	
//		control = abs(fl/fv-1);	///< iteration control
//
//		P = P*fl/fv;
//		}	
//	Pvap=P;	///< Vapor pressure
//	Pf.push_back(Pvap);	///< Vapor pressure vector
//	T++;  ///<increasing temperature
//	cont=0;	maxiter=100; control=1; ///< reinitializing iteration variables
//	}
//return Pf;
//}

