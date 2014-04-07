#include "CProp.h"

using namespace std;

/// Read fluid and system data from user.
istream & operator >> (istream & in , CProp & data)
	{in >> data.Tc;
	 in >> data.Pc;
	 in >> data.w;
	 in >> data.Tmin;
	 in >> data.Tmax;
	 return in;}

/// Write fluid and system data to screen.
ostream & operator << (ostream & out , CProp & data)
	{out << "\nFluid Properties";
	 out << "\nCritical Temperature: " << data.Tc ;
	 out << "\nCritical Pressure: " << data.Pc;
	 out << "\nAcentric Factor: "<< data.w<<endl;
	 out << "\nSystem Properties";
	 out << "\nMin. Temperature: "<< data.Tmin;
	 out << "\nMax. Temperature: "<< data.Tmax;
	return out;}

/// Read fluid and system data from external file.
ifstream & operator >> (ifstream & fin , CProp & data)
	{fin.ignore (255, '\n'); fin >> data.Tc;		
	 fin.ignore (255, '\n'); fin >> data.Pc;		
	 fin.ignore (255, '\n'); fin >> data.w;		
	 fin.ignore (255, '\n'); 				
	 fin.ignore (255, '\n'); fin >> data.Tmin;	
	 fin.ignore (255, '\n'); fin >> data.Tmax; 	
	 fin.close ();}

// Write Vapor Pressure results on screen.
void CProp::Pscreen(int &_n, vector <double> &_Tvap, 
					vector <double> &_Tvapexp,
					vector <double> &_PvapVdW, 
					vector <double> &_PvapRK, 
					vector <double> &_PvapSoave, 
					vector <double> &_PvapPR, 
					vector <double> &_PvapSW, 
					vector <double> &_Pvapexp)
					
{	cout<<"\nTemperature vs. Vapor Pressure for each EOS: "<< endl;
	cout<<setw(5)<<"Tvap: "<<setw(10)<<"VdW Pvap: "<<setw(10)<<" RK Pvap: "<<
	setw(10)<<"SRK Pvap: "<< setw(10)<<" PR Pvap: "<<setw(10)<<" SW Pvap: "<<
	setw(10)<<"Pexp: "<<endl;
	
	int exp_count = 0;
	
			for (int i=0;i<=_n;i++)
			{
				if (_Tvap[i] == _Tvapexp[exp_count]) {
					
					cout<<_Tvap[i]<<setw(10)<<setprecision(3)<<_PvapVdW[i]
					<<setw(10)<<setprecision(3)<<_PvapRK[i]<<
					setw(10)<<setprecision(3)<<_PvapSoave[i]<<
					setw(10)<<setprecision(3)<<_PvapPR[i]<<
					setw(10)<<setprecision(3)<<_PvapSW[i]<<
					setw(10)<<setprecision(3)<<_Pvapexp[exp_count]<<endl;
					
					exp_count++;
					
				}
				else {
					cout<<_Tvap[i]<<setw(10)<<setprecision(3)<<_PvapVdW[i]
					<<setw(10)<<setprecision(3)<<_PvapRK[i]<<
					setw(10)<<setprecision(3)<<_PvapSoave[i]<<
					setw(10)<<setprecision(3)<<_PvapPR[i]<<
					setw(10)<<setprecision(3)<<_PvapSW[i]<<
					setw(10)<<setprecision(3)<<"-"<<endl;
				}
			
			}
				
}

/// Write Vapor Pressure results on file.
void CProp::Pfile(int &_n, vector <double> &_Tvap,
					vector <double> &_Tvapexp, 
					vector <double> &_PvapVdW, 
					vector <double> &_PvapRK, 
					vector <double> &_PvapSoave, 
					vector <double> &_PvapPR, 
					vector <double> &_PvapSW,
					vector <double> &_Pvapexp)
					
{	string foexp;
	cout <<"\nEnter with vapor pressure output file's name: ";
	getline(cin,foexp);
	string path;
	path = "..\\resultados\\" + foexp;
	ofstream fout(path.c_str ());
	
	fout<<"\nTemperature vs. Vapor Pressure for each EOS: "<< endl;
	fout<<setw(5)<<"Tvap: "<<setw(10)<<"VdW Pvap: "<<setw(10)<<" RK Pvap: "<<
	setw(10)<<"SRK Pvap: "<< setw(10)<<" PR Pvap: "<<setw(10)<<" SW Pvap: "<<
	setw(10)<<"Pexp: "<<endl;
	
		int exp_count = 0;
	
			for (int i=0;i<=_n;i++)
			{
				if (_Tvap[i] == _Tvapexp[exp_count]) {
					
					fout<<_Tvap[i]<<setw(10)<<setprecision(3)<<_PvapVdW[i]
					<<setw(10)<<setprecision(3)<<_PvapRK[i]<<
					setw(10)<<setprecision(3)<<_PvapSoave[i]<<
					setw(10)<<setprecision(3)<<_PvapPR[i]<<
					setw(10)<<setprecision(3)<<_PvapSW[i]<<
					setw(10)<<setprecision(3)<<_Pvapexp[exp_count]<<endl;
					
					exp_count++;
					
				}
				else {
					fout<<_Tvap[i]<<setw(10)<<setprecision(3)<<_PvapVdW[i]
					<<setw(10)<<setprecision(3)<<_PvapRK[i]<<
					setw(10)<<setprecision(3)<<_PvapSoave[i]<<
					setw(10)<<setprecision(3)<<_PvapPR[i]<<
					setw(10)<<setprecision(3)<<_PvapSW[i]<<
					setw(10)<<setprecision(3)<<"-"<<endl;
				}
			
			}
			
		fout << flush;
		fout.close();	
		cout<<"\nData in file: "<<foexp<<endl;}

/// Write Relative errors on screen.
void CProp::Errscreen(int &_n, std::vector <double> &_Tvap, 
						std::vector <double> &_ErrVdW, double maxerrvdw, 
						std::vector <double> &_ErrRK, double maxerrrk, 
						std::vector <double> &_ErrSoave, double maxerrsoave, 
						std::vector <double> &_ErrPR, double maxerrpr,
						std::vector <double> &_ErrSW, double maxerrsw)
						
{	cout<<"\nMax Relative Error (%) - Vapor Pressure: "<< endl;
	cout<<setw(10)<<"VdW: "<<maxerrvdw<<setw(10)<<"RK : "<<maxerrrk<<
	setw(10)<<"SRK: "<<maxerrsoave<<setw(10)<<"PR: "<<maxerrpr<<setw(10)<<"SW: "<<maxerrsw<<endl;
	
	cout<<"\nRelative Error (%) - Vapor Pressure: "<< endl;
	cout<<setw(10)<<"Tvap: "<<setw(10)<<"VdW: "<<setw(10)<<
	"RK : "<<setw(10)<<"SRK: "<< setw(10)<<"PR: "<< setw(10)<<"SW: "<<endl;
	
		for (int i=0;i<=_n;i++)
		{cout<<setw(10)<<setprecision(3)<<_Tvap[i]<<
		 setw(10)<<setprecision(5)<<_ErrVdW[i]<<
		 setw(10)<<setprecision(5)<<_ErrRK[i]<<
		 setw(10)<<setprecision(5)<<_ErrSoave[i]<<
		 setw(10)<<setprecision(5)<<_ErrPR[i]<<
		 setw(10)<<setprecision(5)<<_ErrSW[i]<<endl;
		}
}

/// Write Relative errors on file.
void CProp::Errfile(int &_n, std::vector <double> &_Tvap, 
						std::vector <double> &_ErrVdW, double maxerrvdw, 
						std::vector <double> &_ErrRK, double maxerrrk, 
						std::vector <double> &_ErrSoave, double maxerrsoave, 
						std::vector <double> &_ErrPR, double maxerrpr,
						std::vector <double> &_ErrSW, double maxerrsw)
						
{	string foerr;
	cout <<"\nEnter with relative error output file's name: ";
	getline(cin,foerr);
	string path;
	path = "..\\resultados\\" + foerr;
	ofstream fouterr(path.c_str ());
		
	fouterr<<"\nMax Relative Error (%) - Vapor Pressure: "<< endl;
	fouterr<<setw(10)<<"VdW: "<<maxerrvdw<<setw(10)<<"RK : "<<maxerrrk<<setw(10)
	<<"SRK: "<<maxerrsoave<<setw(10)<<"PR: "<<maxerrpr<<setw(10)<<"SW: "<<maxerrsw<<endl;
	 
	fouterr<<"\nRelative Error (%) - Vapor Pressure: "<< endl;
	fouterr<<setw(10)<<"Tvap: "<<setw(10)<<"VdW: "<<setw(10)<<
	"RK : "<<setw(10)<<"SRK: "<< setw(10)<<"PR: "<< setw(10)<<"SW: "<<endl;	
	
		for (int i=0;i<=_n;i++)
		{
		fouterr<<setw(10)<<setprecision(3)<<_Tvap[i]<<
		setw(10)<<setprecision(5)<<_ErrVdW[i]<<
		setw(10)<<setprecision(5)<<_ErrRK[i]<<
		setw(10)<<setprecision(5)<<_ErrSoave[i]<<
		setw(10)<<setprecision(5)<<_ErrPR[i]<<
		setw(10)<<setprecision(5)<<_ErrSW[i]<<endl;}
		
	fouterr<<flush;
	fouterr.close();
	cout<<"\nData in file: "<<foerr<<endl;
}


///Plot Calculated Vapor Pressure
void CProp::Plotcalc(int &_n,
				vector <double> &_Tvap, 
				vector <double> &_PvapVdW, 
				vector <double> &_PvapRK, 
				vector <double> &_PvapSoave, 
				vector <double> &_PvapPR,
			    vector <double> &_PvapSW)
				
{
		for (int i=0; i<=_n; i++)
		{ double T = log(1/_Tvap[i]);
		Tplot.push_back(T);
    	}
	
	plot.set_style("linespoints");
    plot.set_xlabel("Temperature (K)");
    plot.set_ylabel("Pressure (bar)");
    plot.set_pointsize(1.2);
    plot.set_title("Vapor Pressure vs. Temperature");
   
    plot.plot_xy(Tplot, _PvapVdW , "Van der Waals Pvap");
    plot.plot_xy(Tplot, _PvapRK,  "Redlich-Kwong Pvap");
    plot.plot_xy(Tplot, _PvapSoave, "Soave Pvap");
    plot.plot_xy(Tplot, _PvapPR, "Peng-Robinson Pvap");
	plot.plot_xy(Tplot, _PvapSW, "Schimidt-Wenzel Pvap");

}

///Plot Experimental Vapor Pressure

void CProp::Plotexp(int &_n, 
					vector <double> &_Tvapexp, 
					vector <double> &_Pvapexp)
{
		for (int i=0; i<=_n; i++)
		{ double T = log(1/_Tvapexp[i]);
		Tplotexp.push_back(T);
    	}
     	cin.ignore();
    	plot.plot_xy(Tplotexp, _Pvapexp, "Exp Pvap"); 
    	
}
