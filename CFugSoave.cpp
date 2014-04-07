#include "CFugSoave.h"

using namespace std;

/// This method calculates the fugacity of the phases using Soave's EoS.
void CFugSoave::Fug_Calc (double P, double zl, double zv, double A, double B)
{
/// Soave's liquid phase fugacity coefficient estimation.
fcoeffl=(zl-1.0)-log(zl-B)-(A/B)*log(1.0+B/zl);

/// Soave's liquid phase fugacity estimation.
fl=P*exp(fcoeffl);

/// Soave's liquid phase fugacity coefficient estimation.
fcoeffv=(zv-1.0)-log(zv-B)-(A/B)*log(1.0+B/zv);

/// Soave's liquid vapor fugacity estimation.
fv=P*exp(fcoeffv);
}

