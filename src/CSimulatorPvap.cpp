#include "CSimulatorPvap.h" 

using namespace std;

void CSimulatorPvap::Run()
{
cout << "Pvap Calc Simulator"<<endl;
cout << "A program to calculate the vapor pressure of a substance" << endl;

string line = "\n-------------------------------------------\n"; 

double const R = 83.14; ///< universal gas constant definition

/// Fluid and System properties definition.
	cout << line<< "Enter with the Fluid Properties? (Yes=1, No=0): ";
	int enter; cin>>enter; cin.get(); 
	cout<<line;

			if (enter==1)
			{cout<<"Critical Tempeature and Pressure, Acentric Factor, Min and Max Temperature: "<<endl;
			cin>>data; 
			cin.get(); 
			cout<<line;
			cout<<data;}
			
			if (enter==0)
			{cout<<"Enter with file's name: ";
			string fp;
			getline(cin, fp);
			string path;
			path = "..\\compostos\\" + fp;
			ifstream fin (path.c_str ());
			fin>>data;
			cout<<line;
			cout<<data;}
	
	Tc=data.Get_DataTc();
	Pc=data.Get_DataPc(); 
	w=data.Get_Dataw();
	Tmin=data.Get_DataTmin(); 
	Tmax=data.Get_DataTmax();
	
/// Temperature Range.
	T=Tmin;	
	while (T <= Tmax) {
		Tvap.push_back(T);
		T++;
	}
	int n=Tvap.size()-1;
		
/// Van der Waals Vapor Pressure Calculation.
	pvapvdw = new CPvapVdW(Tc, Pc);
	PvapVdW=pvapvdw->Pvap_Calc(n, Pc, Tc, R, P, Tmin);

///// Redlich-Kwong Vapor Pressure Calculation.
//	pvaprk = new CPvapRK(Tc, Pc);
//	PvapRK=pvaprk->Pvap_Calc(n, Pc, Tc, R, P, Tmin);
//	//PvapRK=pvaprk.Pvap_Calc(n, Pc, Tc, R, P, Tmin);
//	
///// Soave-Redlich-Kwong Vapor Pressure Calculation.
//	pvapsoave = new CPvapSoave(Tc, Pc);
//	PvapSoave = pvapsoave->Pvap_Calc(n, Pc, Tc, R, P, Tmin);
//	//PvapSoave=pvapsoave.Pvap_Calc(n, Pc, Tc, w, R, P, Tmin);
//
///// Peng-Robinson Vapor Pressure Calculation.
//	pvappr = new CPvapPR(Tc, Pc);
//	PvapPR = pvappr->Pvap_Calc(n, Pc, Tc, R, P, Tmin);
////	PvapPR = pvappr.Pvap_Calc(n, Pc, Tc, w, R, P, Tmin);
//
///// Schmidt-Wenzel Vapor Pressure Calculation.
//	pvapsw = new CPvapSW(Tc, Pc);
//	PvapSW = pvapsw->Pvap_Calc(n, Pc, Tc, R, P, Tmin);
////	PvapSW = pvapsw.Pvap_Calc(n, Pc, Tc, w, R, P, Tmin);

if (enter==1)
{
/// Pvap Experimental values defintion.
	for (int i=0; i<=n; i++)
	Pvapexp.push_back(0);
	
///Plot Results
	cout<<line;
	//data.Plot(Tvap,PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW,Pvapexp);

/// Vapor Pressure Output.
	cout<<line;
	cout<<"\nWhere do you want to print the results? (File=1, Screen=0): ";
	cin>>print; cin.get();
	if (print==0)
	data.Pscreen(n,Tvap, Tvapexp,PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW,Pvapexp);
	if (print==1)
	data.Pfile(n,Tvap, Tvapexp, PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW,Pvapexp);
}

if (enter==0)
{
/// Pvap Experimental values defintion.
//	cout<<"\n"<<line<<"Enter with exp. Temperature file's name: ";
//	string Texp;
//	getline(cin, Texp);
//	string path;
//	path = "..\\compostos\\" + Texp;
//	ifstream Tin (path.c_str ());
//	Tin>>Tvapexp;
	
//	cout<<"\n"<<line<<"Enter with exp. Pressure file's name: ";
//	string Pexp;
//	getline(cin, Pexp);
//	path = "..\\compostos\\" + Pexp;
//	ifstream Pin (path.c_str ());
//	Pin>>Pvapexp;
	
	int n_exp = Tvapexp.size()-1;
/// Plot Results.
	cout<<line;
	data.Plotcalc(n, Tvap, PvapVdW, "Van der Waals Pvap");
	//data.Plotcalc(n, Tvap,PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW);
	//data.Plotexp(n_exp, Tvapexp, Pvapexp);
	
/// Vapor Pressure Output.
	cout<<line;
	cout<<"\nWhere do you want to print the results? (File=1, Screen=0): ";
	int print; cin>>print; cin.get();
	if (print==0)
	data.Pscreen(n,Tvap, Tvapexp, PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW,Pvapexp);
	if (print==1)
	data.Pfile(n,Tvap, Tvapexp, PvapVdW,PvapRK,PvapSoave,PvapPR,PvapSW,Pvapexp);
	
//Pressure Relative Errors.
	ErrVdW=errvdw.Perr_Calc(PvapVdW,Pvapexp,Tvap,Tvapexp);
	maxerrvdw=errvdw.Maxerr();
	ErrRK=errrk.Perr_Calc(PvapRK,Pvapexp,Tvap,Tvapexp);
	maxerrrk=errrk.Maxerr();
	ErrSoave=errsoave.Perr_Calc(PvapSoave,Pvapexp,Tvap,Tvapexp);
	maxerrsoave=errsoave.Maxerr();
	ErrPR=errpr.Perr_Calc(PvapPR,Pvapexp,Tvap,Tvapexp);	
	maxerrpr=errpr.Maxerr();	
	ErrSW=errsw.Perr_Calc(PvapSW,Pvapexp,Tvap,Tvapexp);	
	maxerrsw=errsw.Maxerr();
	
/// Relative Errors Output.
	cout<<line;
	if (print==0)
	data.Errscreen(n_exp,Tvapexp,ErrVdW,maxerrvdw,ErrRK,maxerrrk,ErrSoave,maxerrsoave,ErrPR,maxerrpr,ErrSW,maxerrsw);
	if (print==1)
	data.Errfile(n_exp,Tvapexp,ErrVdW,maxerrvdw,ErrRK,maxerrrk,ErrSoave,maxerrsoave,ErrPR,maxerrpr,ErrSW,maxerrsw);
}
	cout<<line;
	cout<<"End of program"<<endl;
	cin.ignore();
}

