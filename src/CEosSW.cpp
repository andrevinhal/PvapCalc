#include "CEosSW.h" // class's header file

using namespace std;
//
/////Schmidt-Wenzel "w" estimation
// void CEosSW::Const_w (double w){
// const_w = -3.0*w;
// }
//
/////Schmidt-Wenzel "u" estimation
// void CEosSW::Const_u (){
// const_u = 1.0-const_w;
// }
//
/////Schmidt-Wenzel "aT" estimation
//
//void CEosSW::Const_aT (double w, double T, double Tc){
// if (w<=0.3671)
// 	{kappa_o = 0.465 + 1.347*w -0.528*w*w;
// 	}
//if (w>0.3671)
// 	{kappa_o = 0.5361*w +0.9593*w*w;
// 	}
//
//double kappa_1 = pow((5.0*(T/Tc)-3.0*kappa_o-1.0),2.0)/70.0;
//double kappa_2 = 0.71*pow((T/Tc)-0.779,2.0);
//
//if (w<=0.4)
//	{
//	kappa = kappa_o + kappa_1;
//	}
//if (w>=0.55)
//	{kappa = kappa_o + kappa_2;
//	}	
//if (w>0.4 and w<0.55)
//	{kappa = ((0.55-w)*6.66666667)*kappa_1 + ((w-0.4)*2)*kappa_2;
//	}
//
// const_aT = pow(1.0+kappa*(1.0-sqrt(T/Tc)),2.0);}
//
//
// 										   
/////Schmidt-Wenzel "a" estimation
// void CEosSW::Const_a (double bc, double zc, double aT, double Tc, double Pc, double  R){
// omega_a = pow(1-zc*(1-bc),3.0);
// const_a = (aT*omega_a*R*R*Tc*Tc)/Pc;
// }
//
/////Schmidt-Wenzel "b" estimation
// void CEosSW::Const_b (double bc, double zc, double Tc, double Pc, double  R){
// omega_b = bc*zc;
// const_b = (omega_b*R*Tc)/Pc;
// }
//
/////Schimidt-Wenzel "bc" estimation
// void CEosSW::Bc(double w){
// double bci = 0.25989 - 0.0217*w + 0.00375*w*w;
// double control = 1.0, f1 = 0, f2 = 0; int maxiter = 100, cont = 0;
//	
//	while ((control>0.0001) && (cont < maxiter)){
//		f1=(6.0*w+1.0)*pow(bci,3.0) + 3.0*pow(bci,2.0) + 3.0*bci - 1.0; 
//		f2=3*(6.0*w+1.0)*(pow(bci,2.0)) + 6.0*bci + 3.0;             	
//		bc=bci-f1/f2; ///< New value for the root    
//		control=abs(bc-bci); ///< Iteration control 
//		bci=bc; ///< New value for the initial guess
//		cont++;
//	}
// }
//
/////Schimidt-Wenzel "zc" estimation
// void CEosSW::Zc (double bc, double w){
// zc = 1/(3.0*(1.0+bc*w));
// }
// 
///// Schimidt-Wenzel "alpha" estimation.
//void CEosSW::Alpha (double const_u, double B)
//{alpha=const_u*B-B-1.0;}
//
///// Schimidt-Wenzel "beta" estimation.
//void CEosSW::Beta (double const_u, double const_w, double A, double B)
//{beta=const_w*B*B-const_u*B*B-const_u*B + A;}
//
///// Schimidt-Wenzel parameter "gamma" estimation.
//void CEosSW::Gamma (double const_w, double A, double B)
//{gamma=-const_w*B*B*B-const_w*B*B-A*B;}
