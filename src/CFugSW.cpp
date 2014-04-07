#include "CFugSW.h" // class's header file

using namespace std;

/// This method calculates the fugacity of the phases using PR's EoS.
void CFugSW::Fug_Calc (double P, double zl, double zv, double A, double B, double u, double w)
{
/// PR's liquid phase fugacity coefficient estimation.
double delta = u*u-4.0*w;
double laml1 = 2*zl+B*(u-sqrt(delta));
double laml2 = 2*zl+B*(u+sqrt(delta));
fcoeffl=(zl-1.0)-log(zl-B)+(A/(B*sqrt(delta)))*log(laml1/laml2);

/// PR's liquid phase fugacity estimation.
fl=P*exp(fcoeffl);

/// PR's liquid phase fugacity coefficient estimation.
double lamv1 = 2*zv+B*(u-sqrt(delta));
double lamv2 = 2*zv+B*(u+sqrt(delta));
fcoeffv=(zv-1.0)-log(zv-B)+(A/(B*sqrt(delta)))*log(lamv1/lamv2);

/// PR's liquid phase fugacity estimation.
fv=P*exp(fcoeffv);
}

