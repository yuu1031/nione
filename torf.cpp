#include "torf.h"

TOrF::TOrF(QWidget *parent) : QWidget(parent)
{

}
bool TOrF::Valid(Loan a)
{
    if(a.Area>0&&a.UnitPrice>0&&a.InterestRate>0)
        return true;
    else
        return false;
}
bool TOrF::Valid(Loans a)
{
    if(a.LoanAll>0&&a.InterestRate>0)
        return true;
    else
        return false;
}
bool TOrF::Valid(Combination a)
{
    if(a.CLoans>0&&a.PLoans>0&&a.CInterestRate>0&&a.PInterestRate>0)
        return true;
    else
        return false;
}
