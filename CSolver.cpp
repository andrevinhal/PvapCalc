#include "CSolver.h" // class's header file

using namespace std;

/// This method finds the roots of a 3rd degree eqaution through Newton's method.
void CSolver::Z_Calc(double &_x, double &_y, double &_z, double &_ig)
{

	double *z;
	z = new double [3];
	z[0]=0; z[1]=0;	z[2]=0; ///< roots of the equation initial values

	double *zi;
	zi = new double [3];
	zi[0]=_ig; ///< initial guess for compressibility factor
	zi[1]=2/3;	zi[2]=1;			

/// Newton's method.
	for (int i=0; i<3; i++)
	{
	control=1;
 	int cont=0, maxiter = 100;
  	
	while ((control>0.0001) && (cont < maxiter))
    {
	double z1, z2;
	z1=(pow(zi[i],3) + pow(zi[i],2)*_x + zi[i]*_y + _z);///< Equation of state	
	z2=3*(pow(zi[i],2)) + 2*zi[i]*_x + _y; ///< Equation of state derivative              	
	z[i]=zi[i]-z1/z2;	///< New value for the root    
	control=abs(z[i]-zi[i]);	///< Iteration control 
	zi[i]=z[i];		///< New value for the initial guess
	cont++;
	}
	}
	

zl=z[0];
zv=z[2];

delete [] zi;
delete [] z;
}

double CSolver::Get_zl() {return zl;}

double CSolver::Get_zv() {return zv;}
