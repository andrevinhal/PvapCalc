#ifndef CSolver_H
#define CSolver_H
#include <iostream>
#include <cmath>
#include <iomanip>

/**
 * This class finds the roots of the 3rd degree equation 
 * of state in terms of the compressibility factor
 */
 
class CSolver
{
private:
	double control; ///< iteration control variable
	double zv; ///< compressibility factor of the vapor phase
	double zl; ///< compressibility factor of the liquid phase
			
public:
	void Z_Calc(double &_x, double &_y, double &_z, double &_ig);
	
	double Get_zl();
	
	double Get_zv();
	
	/// Class constructor.
	CSolver(){};
	
	/// Class destructor.
	~CSolver(){};
	
};

#endif // CSOLVER_H

