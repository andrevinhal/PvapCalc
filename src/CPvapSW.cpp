#include "CPvapSW.h" // class's header file

using namespace std;
//
//vector<double> CPvapSW::Pvap_Calc(int n, double Pc, double Tc, double w, double const R, double P, double T)
//{
//
//	sweos.Const_w(w);	
//	const_w = sweos.Get_w();
//	sweos.Const_u();
//	const_u = sweos.Get_u();
//	sweos.Bc(w);
//	bc = sweos.Get_Bc();
//	sweos.Zc(bc,w);
//	zc = sweos.Get_Zc();
//	
//	for (int i=0; i<=n; i++)
//	{  
//
//// Pressure iteration.
//		while ((control>0.0001) && (cont < maxiter))
//		{
///// PR Parameters Calculation.
//		sweos.Const_aT(w,T,Tc); ///< PR's constant aT
//		aT=sweos.Get_aT();
//	
//		sweos.Const_a(bc, zc, aT, Tc, Pc, R);	///< PR's parameter "a"
//		sweos.Const_b(bc, zc, Tc, Pc, R);	///< PR's parameter "b"
//
//		a = sweos.Get_a();	
//		b = sweos.Get_b();
//		
//		sweos.Const_A(a, T, P, R);	///< PR's parameter "A"
//		sweos.Const_B(b, T, P, R);	///< PR's parameter "B"
//
//		A = sweos.Get_A();
//		B = sweos.Get_B();
//		
//		sweos.Alpha(const_u, B);		///< PR's parameter "alpha"
//		sweos.Beta(const_u, const_w, A, B);	///< PR's parameter "beta"
//		sweos.Gamma(const_w, A, B);	///< PR's parameter "gamma"
//
//		alpha = sweos.Get_Alpha();
//		beta = sweos.Get_Beta();
//		gamma = sweos.Get_Gamma(); 
//		
///// PR Fugacity Calculation.
//		ig=(b*P)/(R*T); ///< initial guess.
//	
//		solver.Z_Calc(alpha, beta, gamma, ig); ///< 3rd degree equation solver
//
//		zl = solver.Get_zl();	///< smallest positive root - zl
//		zv = solver.Get_zv();	///< biggest positive root - zv
//		
//		fugSW.Fug_Calc(P, zl, zv, A, B, const_u, const_w); 	///< PR's fugacity calculation
//	
//		fl = fugSW.Get_fl();	///< PR's liquid fugacity
//		fv = fugSW.Get_fv();	///< PR's vapor fugacity
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

