#include "CPerr.h"

using namespace std;

/// Method for evaluating the differance between experimental and calculated pressures.
vector <double> CPerr::Perr_Calc(vector <double>  &_a, vector <double>  &_b, vector <double>  &_c, vector <double>  &_d)
{	int n_calc;
	n_calc = _a.size()-1; 
	
	int n_exp;
	n_exp = _b.size()-1;
		
	for (int ie=0; ie<=n_exp; ie++)
		{
			for (int ic = 0; ic <= n_calc; ic++)
			{
				if (_d[ie] == _c[ic])
					{
					/// Relative error calculation.
					re=abs((_a[ic] - _b[ie])/(_b[ie]))*100; 
					Err.push_back(re); 
					}  
			
			}
		}
	return Err;
}

/// Method for return the maximum relative error.
double CPerr::Maxerr()
{
	return *max_element(Err.begin(), Err.end());
}


