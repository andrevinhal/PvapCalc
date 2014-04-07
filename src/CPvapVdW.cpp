#include "CPvapVdW.h"

using namespace std;

/// This method calculates the Vapor Pressure of a substance using vdW's EoS.
vector<double> CPvapVdW::Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T) {
	for (int i=0; i<=n; i++) {
	/// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter)) {
	/// VdW Parameters Calculation.	
			vdweos.Const_a(Tc, Pc, R);	///< vdw constant a
			vdweos.Const_b(Tc, Pc, R);	///< vdw constant b
			a = vdweos.Get_a();
			b = vdweos.Get_b();
		
			vdweos.Const_A(a, T, P, R);	///< vdw constant A
			vdweos.Const_B(b, T, P, R);	///< vdw constant B
			A = vdweos.Get_A();
			B = vdweos.Get_B();
		
			vdweos.Beta(A);		///< vdw constant Beta
			vdweos.Alpha(B);	///< vdw constant Alpha
			vdweos.Gamma(A,B);	///< vdw constant Gamma
			alpha = vdweos.Get_Alpha();
			beta = vdweos.Get_Beta();
			gamma = vdweos.Get_Gamma();
		
		/// VdW Fugacity Calculation.
			ig=(b*P)/(R*T);	///< initial guess
		
			solver.Z_Calc(alpha, beta, gamma, ig);	///< 3rd degree equation solver
		
			zl = solver.Get_zl();	///< smallest positive root - zl
			zv = solver.Get_zv();	///< biggest positive root - zv
		
			fugVdW.Fug_Calc(P, zl, zv, A, B);	///< van der Waals fugacity calculation
		
			fl = fugVdW.Get_fl();	///< VdWaals liquid fugacity
			fv = fugVdW.Get_fv();	///< VdWaals vapor fugacity
		
			control = abs(fl/fv-1);	///< iteration control
		
			P = P*fl/fv;			
		
			cont++;
		}
		Pvap = P;	///< Vapor pressure
		Pf.push_back(Pvap); ///< Vapor pressure vector
		T++; ///<increasing temperature
		cont=0;	maxiter=100; control=1; ///< reinitializing iteration variables
	}
	return Pf;
}

