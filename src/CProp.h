#ifndef CPROP_H
#define CPROP_H
# include <string>
# include <fstream>
# include <vector>
# include <algorithm>
# include <iostream>
# include <iomanip>
# include <cmath>
# include "CGnuplot.h"

/**
 * This class reads and writes the data used in the software
 */

class CProp
{
	private :
	double Tc; ///< Critical temperature
	double Pc; ///< Critical pressure
	double w; ///< acentric factor
	double Tmin; ///< Min temperature
	double Tmax; ///< Max temperature
	std::vector<double> Tplot; ///< plot T calc
	std::vector<double> Tplotexp; ///< plot T exp
	Gnuplot plot;
	
	public:
	int n_exp;
	friend std::istream & operator >> (std::istream & in, CProp &);	///< Reads data from console 
	friend std::ifstream & operator >> (std::ifstream & fin, CProp &);	///< Shows data at screen
	friend std::ostream & operator << (std::ostream & out, CProp &);	///< Reads data from extern file
	friend std::ostream & operator << (std::ostream & out, std::vector<double> &);	///< Reads exp pressure from external file
	
	/// Method to get exp presure.
	std::vector <double> ExpPvap(int &_n, std::string &_file); 
	
	///Method to plot calculates vapor pressure.
	void Plotcalc(int &_n, std::vector <double> &_Tvap, std::vector <double> &_PvapVdW, std::vector <double> &_PvapRK, std::vector <double> &_PvapSoave, std::vector <double> &_PvapPR, std::vector <double> &_PvapSW);
	void Plotcalc(int &_n, std::vector <double> &_Tvap, std::vector <double> &pressure_data, std::string tag);
	
	///Method to plot experimental vapor pressure.
	void Plotexp(int &_n, std::vector <double> &_Tvapexp, std::vector <double> &_Pvapexp);
		
	/// Function to print the Vapor Pressure in screen
	void Pscreen(int &_n, std::vector <double> &_Tvap, std::vector <double> &_Tvapexp, std::vector <double> &_PvapVdW, std::vector <double> &_PvapRK, std::vector <double> &_PvapSoave, std::vector <double> &_PvapPR, std::vector <double> &_PvapSW, std::vector <double> &_Pvapexp);

	/// Function to print the Vapor Pressure in file
	void Pfile(int &_n, std::vector <double> &_Tvap, std::vector <double> &_Tvapexp, std::vector <double> &_PvapVdW, std::vector <double> &_PvapRK, std::vector <double> &_PvapSoave, std::vector <double> &_PvapPR, std::vector <double> &_PvapSW, std::vector <double> &_Pvapexp);
	
	/// Function to print the errors in screen.
	void Errscreen(int &_n, std::vector <double> &_Tvap, std::vector <double> &_ErrVdW, double maxerrvdw, std::vector <double> &_ErrRK, double maxerrrk, std::vector <double> &_ErrSoave, double maxerrsoave, std::vector <double> &_ErrPR, double maxerrpr, std::vector <double> &_ErrSW, double maxerrsw);

	/// Function to print the errors in file.
	void Errfile(int &_n, std::vector <double> &_Tvap, std::vector <double> &_ErrVdW, double maxerrvdw, std::vector <double> &_ErrRK, double maxerrrk, std::vector <double> &_ErrSoave, double maxerrsoave, std::vector <double> &_ErrPR, double maxerrpr, std::vector <double> &_ErrSW, double maxerrsw);

	double Get_DataTc(){return this->Tc;};	///< Get critical temperature from external file
	double Get_DataPc(){return this->Pc;};	///< Get critical pressure from external file
	double Get_Dataw(){return this->w;};		///< Get acentric factor external file
	double Get_DataTmin(){return this->Tmin;};	///< Get systems min temperature
	double Get_DataTmax(){return this->Tmax;};	///< Get systems max temperature
	
/// Class constructor.
	CProp(){
	Tc=0;Pc=100;w=0;Tmin=0;Tmax=0;
	plot.set_style("linespoints");
    plot.set_xlabel("Temperature (K)");
    plot.set_ylabel("Pressure (bar)");
    plot.set_pointsize(1.2);
    plot.set_title("Vapor Pressure vs. Temperature");
	};
	
/// Class destructor.
	~CProp(){};
};

// Reads exp pressure from an external file
template <typename T> 
std::ifstream & operator >> (std::ifstream & fin , std::vector<T> & exp) 
	{
	int n_exp; fin>>n_exp; ///<number of experimental points
	fin.ignore(255, '\n');
	double exp_value;
	for (int i = 0; i<=n_exp; i++)
	 {
	 fin>>exp_value; ///< exp. value
	 exp.push_back(exp_value); ///<exp. vector
	 fin.ignore(255, '\n');
	 }
	fin.close ();}



#endif //CPROP_H
