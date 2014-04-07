#include "CFugRK.h"

using namespace std;

/// This method calculates the fugacity of the phases using RK's EoS.
void CFugRK::Fug_Calc (double P, double zl, double zv, double A, double B)
{
/// RK's liquid phase fugacity coefficient estimation.
fcoeffl=(zl-1.0)-log(zl-B)-(A/B)*log(1.0+B/zl);

/// RK's liquid phase fugacity estimation.
fl=P*exp(fcoeffl);

/// RK's vapor phase fugacity coefficient estimation.
fcoeffv=(zv-1.0)-log(zv-B)-(A/B)*log(1.0+B/zv);

/// RK's vapor phase fugacity estimation.
fv=P*exp(fcoeffv);
}
