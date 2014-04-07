#include "CFugVdW.h"

using namespace std;

/// This method calculates the fugacity of the phases using PR's EoS.
void CFugVdW::Fug_Calc (double P, double zl, double zv, double A, double B)
{
/// VdW's liquid phase fugacity coefficient estimation.
fcoeffl=(zl-1.0)-log(zl-B)-(A/zl);

/// VdW's liquid phase fugacity estimation.
fl=P*exp(fcoeffl);

/// VdW's liquid phase fugacity coefficient estimation.
fcoeffv=(zv-1.0)-log(zv-B)-(A/zv);

///	VdW's vapor phase fugacity estimation.
fv=P*exp(fcoeffv);	
}
