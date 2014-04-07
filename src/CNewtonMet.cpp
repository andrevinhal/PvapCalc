#include "CNewtonMet.h" // class's header file

using namespace std;

/// This method finds the roots of a 3rd degree equation through Newton's method.
void CNewtonMet::Z_Calc(double alpha, double beta, double gamma, double ig)
{
	double z[3];
	z[0]=0; z[1]=0; z[2]=0; ///< roots of the equation initial values

	double zi[3];
	zi[0]=ig; zi[1]=0.666; zi[2]=1; ///< initial guess for compressibility factor

/// Newton's method.
	for (int i=0; i<3; i++)
	{
	while ((control>0.0001) && (cont < maxiter))
    {
	double z1, z2;
	z1=(pow(zi[i],3) + pow(zi[i],2)*alpha + zi[i]*beta + gamma); ///< Equation of state	
	z2=3*(pow(zi[i],2)) + 2*zi[i]*alpha + beta; ///< Equation of state derivative              	
	z[i]=zi[i]-z1/z2; ///< New value for the root    
	control=abs(z[i]-zi[i]); ///< Iteration control 
	zi[i]=z[i]; ///< New value for the initial guess
	cont++;
	}
	control=1.0;cont=0;maxiter=100; ///<reinitializing iteration varibles
	}
	
zl=z[0]; ///< liq. phase comp. factor
zv=z[2]; ///< vap. phase comp. factor
}
