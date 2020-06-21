#include "acpi.h"
#include"loan.h"
#include<QDebug>
#include<QtMath>
#include"loans.h"
#include"combination.h"
/*1.等额本息还款法:每月月供额=〔贷款本金*月利率*(1+月利率)^还款月数〕÷〔(1+月利率)^还款月数-1〕

2.每月应还利息=贷款本金*月利率*〔(1+月利率)^还款月数-(1+月利率)^(还款月序号-1)〕÷〔(1+月利率)^还款月数-1〕

3.每月应还本金=贷款本金*月利率*(1+月利率)^(还款月序号-1)÷〔(1+月利率)^还款月数-1〕

4.*/

ACPI::ACPI(QWidget *parent) : QWidget(parent)
{
}
ACPI::ACPI(Loan a)
{
    data=a;
}
ACPI::ACPI(Loans a)
{
    _Adata=a;
}
ACPI::ACPI(Combination a)
{
    _Cdata=a;
}

double ACPI::MyHome(Loan a)
{
    return 1.0*a.UnitPrice*a.Area;
            //房款总额
}
double ACPI::DownPayment(Loan a)
{
    return 0.1*(10-a.Rate)*MyHome(a);//首付=（1-按揭成数）*房款总额
}//首付
double ACPI::MyLoan(Loan a)
{
    return MyHome(a)-DownPayment(a);//贷款总额=房款总额-首付
}
double ACPI::AverageMonRepayment(Loan a)
{
     return 1.0*MyLoan(a)*a.InterestRate*pow((1.0+a.InterestRate),a.Month)/((pow((1.0+a.InterestRate),a.Month)-1.0)*1.0);
            //〔贷款本金×月利率×（1＋月利率）＾还款月数〕÷〔（1＋月利率）＾还款月数－1〕
}
double ACPI::MyInterest(Loan a)
{
    return AverageMonRepayment(a)*a.Month-MyLoan(a);
        //利息=Month*AverageMonRepayment-MyLoan;总利息=还款月数*每月月供额-贷款本金
}
double ACPI::Repayment(Loan a)
{
    return MyLoan(a)+MyInterest(a);
            //还款总额=贷款总额+利息；
}
double ACPI::Repayment(Loans a)
{
    return a.LoanAll+MyInterest(a);//还款总额=贷款总额+利息；
}
double ACPI::MyInterest(Loans a)
{
    return AverageMonRepayment(a)*a.Month-a.LoanAll;//利息=Month*AverageMonRepayment-MyLoan;总利息=还款月数*每月月供额-贷款本金
}
double ACPI::AverageMonRepayment(Loans a)
{
    return 1.0*a.LoanAll*a.InterestRate*pow((1.0+a.InterestRate),a.Month)/((pow((1.0+a.InterestRate),a.Month)-1.0)*1.0);
//〔贷款本金×月利率×（1＋月利率）＾还款月数〕÷〔（1＋月利率）＾还款月数－1〕
}

double ACPI::LoansALL(Combination a)
{
    //贷款总额
    return a.CLoans+a.PLoans;
}
double ACPI::Repayment(Combination a)
{
    return LoansALL(a)+MyInterest(a);
    //还款总额=贷款总额+利息；
}
double ACPI::MyInterest(Combination a)
{
    //总利息
    return AverageMonRepayment(a)*a.Month-LoansALL(a);
    //利息=Month*AverageMonRepayment-MyLoan;总利息=还款月数*每月月供额-贷款本金
}
double ACPI::CAverageMonRepayment(Combination a)
{
    //商业还款月利息
    return 1.0*a.CLoans*a.CInterestRate*pow((1.0+a.CInterestRate),a.Month)/((pow((1.0+a.CInterestRate),a.Month)-1.0)*1.0);
    //〔贷款本金×月利率×（1＋月利率）＾还款月数〕÷〔（1＋月利率）＾还款月数－1〕
}

double ACPI::PAverageMonRepayment(Combination a)
{
    //公积金还款月利息
    return 1.0*a.PLoans*a.PInterestRate*pow((1.0+a.PInterestRate),a.Month)/((pow((1.0+a.PInterestRate),a.Month)-1.0)*1.0);
    //〔贷款本金×月利率×（1＋月利率）＾还款月数〕÷〔（1＋月利率）＾还款月数－1〕
}
double ACPI::AverageMonRepayment(Combination a)
{
    return CAverageMonRepayment(a)+PAverageMonRepayment(a);
    //月均还款=商业还款月利息+公积金还款月利息
}
