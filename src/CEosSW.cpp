#include "CEosSW.h" // class's header file

using namespace std;

CEosSW::CEosSW() : CEosPR() {};

/// SW parameters u, w, bc and zc estimation.
void CEosSW::Set_u_w_bc_zc(double w) {
	const_w = -3.0*w;
	const_u = 1.0-const_w;
	
double bci = 0.25989 - 0.0217*w + 0.00375*w*w;
double control = 1.0, f1 = 0, f2 = 0; int maxiter = 100, cont = 0;
	
	while ((control>0.0001) && (cont < maxiter)){
		f1=(6.0*w+1.0)*pow(bci,3.0) + 3.0*pow(bci,2.0) + 3.0*bci - 1.0; 
		f2=3*(6.0*w+1.0)*(pow(bci,2.0)) + 6.0*bci + 3.0;             	
		bc=bci-f1/f2; ///< New value for the root    
		control=abs(bc-bci); ///< Iteration control 
		bci=bc; ///< New value for the initial guess
		cont++;
	}
zc = 1/(3.0*(1.0+bc*w));
}

/// SW parameter "aT" calculation.
double CEosSW::Const_aT (double w, double T, double Tc){ 

	double kappa_o;
		if (w<=0.3671)
	 		{kappa_o = 0.465 + 1.347*w -0.528*w*w;}
		if (w>0.3671)
	 		{kappa_o = 0.5361*w +0.9593*w*w;}

	double kappa_1 = pow((5.0*(T/Tc)-3.0*kappa_o-1.0),2.0)/70.0;
	double kappa_2 = 0.71*pow((T/Tc)-0.779,2.0);
	
	double kappa;
		if (w<=0.4)
			{kappa = kappa_o + kappa_1;}
		if (w>=0.55)
			{kappa = kappa_o + kappa_2;}	
		if(w>0.4 and w<0.55)
			{kappa = ((0.55-w)*6.66666667)*kappa_1 + ((w-0.4)*2)*kappa_2;}

return pow(1.0+kappa*(1.0-sqrt(T/Tc)),2.0);
}

/// SW "a" estimation
 double CEosSW::Const_a (double aT, double Tc, double Pc){
 	double omega_a = pow(1-zc*(1-bc),3.0);
 return aT*(omega_a*R*R*Tc*Tc)/Pc;
 }

/// SW "b" estimation
 double CEosSW::Const_b (double Tc, double Pc){
 	double omega_b = bc*zc;
 return (omega_b*R*Tc)/Pc;
 }

/// SW "A" estimaiton
double CEosSW::Const_A (double a, double T, double P){
return ((a*P)/(R*R*T*T));
}

/// SW parameter "B" estimaiton
double CEosSW::Const_B(double b, double T, double P)
{
	return ((b*P)/(R*T));
}

/// SW parameter "alpha" estimation.
double CEosSW::Alpha (double const_u, double B)
{return const_u*B-B-1.0;}

/// SW parameter "beta" estimation.
double CEosSW::Beta (double const_u, double const_w, double A, double B)
{return const_w*B*B-const_u*B*B-const_u*B + A;}

/// SW parameter "gamma" estimation.
double CEosSW::Gamma (double const_w, double A, double B)
{return -const_w*B*B*B-const_w*B*B-A*B;}
