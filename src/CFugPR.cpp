#include "CFugPR.h"

using namespace std;

/// This method calculates the fugacity of the phases using PR's EoS.
void CFugPR::Fug_Calc (double P, double zl, double zv, double A, double B)
{
/// PR's liquid phase fugacity coefficient estimation.
fcoeffl=(zl-1.0)-log(zl-B)-(A/(2*sqrt(2.0)*B))*log((zl+(1.0+sqrt(2.0))*B)/(zl+(1.0-sqrt(2.0))*B));

/// PR's liquid phase fugacity estimation.
fl=P*exp(fcoeffl);

/// PR's liquid phase fugacity coefficient estimation.
fcoeffv=(zv-1.0)-log(zv-B)-(A/(2*sqrt(2.0)*B))*log((zv+(1.0+sqrt(2.0))*B)/(zv+(1.0-sqrt(2.0))*B));

/// PR's liquid phase fugacity estimation.
fv=P*exp(fcoeffv);
}
