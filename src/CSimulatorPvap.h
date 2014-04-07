#ifndef CSIMULATORPVAP_H
#define CSIMULATORPVAP_H
#include <iostream>
#include <vector>
#include "CProp.h"
#include "CPerr.h"
#include "CPvapVdW.h"
#include "CPvapRK.h"
#include "CPvapSoave.h"
#include "CPvapPR.h"
#include "CPvapSW.h"

/**
 * This class manages the calculation
 * of the vapor pressure
 */

class CSimulatorPvap
{
private:	
	double Tc; ///< critical temperature
	double Pc; ///< critical pressure
	double w; ///< acentric factor
	double T; ///< system temperature
	double P; ///< system pressure
	double Tmin; ///< min. temperature
	double Tmax; ///< max. temperature
	double maxerrvdw; ///< Max. VdW relative error
	double maxerrrk; ///< Max. RK relative error
	double maxerrsoave;///< Max. Soave relative error
	double maxerrpr; ///< Max. PR relative error
	double maxerrsw; ///< Max. SW relative error
	int print; ///< Print data
	
	CPvapVdW *pvapvdw; ///< van der Waals Pvap object
	CPvapRK	pvaprk; ///< Redlich-Kwong Pvap object
	CPvapSoave pvapsoave; ///< Soave Pvap object
	CPvapPR pvappr; ///< Peng-Robinson Pvap object
	CPvapSW pvapsw; ///< Schmidt-Wenzel Pvap object
	CPerr errvdw, errrk, errsoave, errpr, errsw; ///< EOS' relative error
	CProp data; ///< Data manipulation object
	
	std::vector <double> Pvapexp; ///< vector containing exp Pvap
	std::vector <double> PvapVdW; ///< vector containing VdW Pvap
	std::vector <double> PvapRK; ///< vector containing RK Pvap
	std::vector <double> PvapSoave; ///< vector containing Soave Pvap
	std::vector <double> PvapPR; ///< vector containing PR Pvap
	std::vector <double> PvapSW; ///< vector containing SW Pvap
	
	std::vector <double> Tvap; ///< vector containing Temperature
	std::vector <double> Tvapexp;  ///< vector containing experimental Temperature values 
	
	std::vector <double> ErrVdW; ///< vector containing vdW Relative Errors
	std::vector <double> ErrRK; ///< vector containing RK Relative Errors
	std::vector <double> ErrSoave; ///< vector containing Soave Relative Errors
	std::vector <double> ErrPR; ///< vector containing PR Relative Errors
	std::vector <double> ErrSW; ///< vector containing SW Relative Errors
				
public: 
	static double const R; ///< Universal gas constant
	
/// Run method.	
	void Run();
	
/// Class constructor.
	CSimulatorPvap(){
		Tc=647.3;
		Pc=221.2;
		w=0.344;
		T=0;
		P=1;
		Tmin=273;
		Tmax=373;
		maxerrvdw=0;
		maxerrrk=0;
		maxerrsoave=0;
		maxerrpr=0;
		maxerrsw=0;
		print=0;
	};

/// Class destructor.
	~CSimulatorPvap(){};
};

#endif // CSIMULATORPVAP_H

