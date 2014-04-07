#include "CPvapVdW.h"

using namespace std;

CPvapVdW::CPvapVdW(double Tc, double Pc) {
	vdweos.Set_a_b(Tc, Pc);
}

/// This method calculates the Vapor Pressure of a substance using vdW's EoS.
vector<double> CPvapVdW::Pvap_Calc(int n, double Pc, double Tc, double const R, double P, double T) {
	for (int i=0; i<=n; i++) {
	/// Pressure iteration.
		while ((control>0.0001) && (cont < maxiter)) {
	/// VdW Parameters Calculation.	
			//vdweos.Const_a(Tc, Pc, R);	///< vdw constant a
			//vdweos.Const_b(Tc, Pc, R);	///< vdw constant b
			//a = vdweos.Get_a();
			//b = vdweos.Get_b();
		
			A = vdweos.Const_A(T, P);	///< vdw constant A
			B = vdweos.Const_B(T, P);	///< vdw constant B
		
			alpha = vdweos.Alpha(B); ///< vdw constant Alpha
			beta = vdweos.Beta(A);		///< vdw constant Beta
			gamma = vdweos.Gamma(A,B);	///< vdw constant Gamma
		
		/// VdW Fugacity Calculation.
			ig=(vdweos.Get_b()*P)/(R*T);	///< initial guess
		
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

