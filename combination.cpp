#include "combination.h"
//组合贷款
Combination::Combination()
{

}
Combination::Combination(double _cl,double _pl,double _mo,double _CI,double _PI)
{
    CLoans=_cl;
    PLoans=_pl;
    Month=_mo;
    CInterestRate=_CI;
    PInterestRate=_PI;
}
Combination Combination:: operator =(Combination)
{
    Combination n;
    n.CLoans=CLoans;
    n.PLoans=PLoans;
    n.Month=Month;
    n.CInterestRate=CInterestRate;
    n.PInterestRate=PInterestRate;
    return n;
}
