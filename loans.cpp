#include "loans.h"

Loans::Loans()
{

}
Loans::Loans(double _a,double _mo,double _ir)
{
  this->LoanAll=_a;
    this->Month=_mo;
    this->InterestRate=_ir;
}
Loans Loans:: operator =(Loans)
{
    Loans n;
    n.LoanAll=LoanAll;
    n.Month=Month;
    n.InterestRate=InterestRate;
    return n;
}
//Loans::Loans(Loans &p):QWidget()
//{
//    this->LoanAll=p.LoanAll;
//    this->Month=p.Month;
//    this->InterestRate=p.InterestRate;
//}
