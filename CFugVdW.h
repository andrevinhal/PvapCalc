#ifndef CFugVdW_H
#define CFugVdW_H
#include <iostream>
#include <cmath>

/**
*	This class determines the fugacity of the
*	liquid and vapor phases of a van der Waals' fluid
*/

class CFugVdW
{
protected:
	double fcoeffv;	///< vapor phase fug. coeff.
	double fcoeffl; ///< liquid phase fug. coeff.
	double fv;	///< vapor phase fug. 
	double fl;	///< liquid phase fug.	
				
public:
	void Fug_Calc(double P, double zl, double zv, double A, double B);  ///< method for fug. calc.
	double Get_fl () {return fl;}; ///< return fug. liq.
	double Get_fv () {return fv;}; ///< return fug. vap.
	double Get_fcoeffl() {return fcoeffl;}; ///< return fug. coeff. liq.
	double Get_fcoeffv() {return fcoeffv;}; ///< return fug. coeff. vap.

/// Class Constructor.
	CFugVdW(){fcoeffv=0;fcoeffl=0;fv=0;fl=0;};

/// Class Destructor.	
	~CFugVdW(){};
};

#endif // CFugVdW_H
