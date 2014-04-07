#ifndef CPERR_H
#define CPERR_H
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

/**
 * This class estimates the relative error between
 * experimental pressure and the calculated pressure
 */

class CPerr
{
private:
	double re; ///< Relative error
	double maxerr; ///< Max Relative error
	std::vector <double> Err; ///< Relative error vector
 		
public:
	std::vector <double> Perr_Calc(std::vector <double> &_a, std::vector <double> &_b, std::vector <double> &_c, std::vector <double> &_d);	///< method for rel. err. calc.
	double Maxerr(); ///< return max relative error
};

#endif // CPERR_H

