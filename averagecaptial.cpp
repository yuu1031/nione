#include "averagecaptial.h"
#include<loan.h>
#include<loans.h>
#include<combination.h>
/*等额本金还款计算公式:
1.每月月供额=(贷款本金÷还款月数)+(贷款本金-已归还本金累计百额)×月利率
2.每月应还本金=贷款本金÷还款月度数
3.每月应还利息内=剩余本金×月利率=(贷款本金-已归还本金累计额)×月利率容
4.每月月供递减额=每月应还本金×月利率=贷款本金÷还款月数×月利率
5.总利息=〔(总贷款额÷还款月数+总贷款额×月利率)+总贷款额÷还款月数×(1+月利率)〕÷2×还款月数-总贷款额*/
AverageCaptial::AverageCaptial(QWidget *parent) : QWidget(parent)
{

}
double AverageCaptial::MyHome(Loan a)
{
    return a.UnitPrice*a.Area;
}
AverageCaptial::AverageCaptial(Loan a)
{
    data=a;
}
AverageCaptial::AverageCaptial(Loans a)
{
    _data=a;
}
AverageCaptial::AverageCaptial(Combination a)
{
    _Cdata=a;
}
double AverageCaptial::MyLoan(Loan a)
{
    return MyHome(a)-DownPayment(a);//贷款总额=房款总额-首付
}//贷款总额
double AverageCaptial::Repayment(Loan a)
{
    return MyLoan(a)+MyInterest(a);//还款总额=贷款总额+利息；
}//还款总额
 double AverageCaptial::DownPayment(Loan a)
 {
     return 0.1*(10-a.Rate)*MyHome(a);//首付=（1-按揭成数）*房款总额
 }//首付
 double AverageCaptial::MyInterest(Loan a)
 {
     return (a.Month+1)*MyLoan(a)*a.InterestRate/2.0;//利息总额=(还款月数+1)×贷款总额×月利率÷2
 }//利息
 double AverageCaptial::ShouldPay(Loan a)
 {
     return MyLoan(a)/a.Month;
 }//每月应还本金
double AverageCaptial::FirstPay(Loan a)
{
    return 1.0*MyLoan(a)/a.Month+MyLoan(a)*a.InterestRate;
    //首月月供额=总贷款额/贷款月数+总贷款额*月利率值；每月月供额=(贷款本金÷还款月数)+(贷款本金-已归还本金累计额)×月利率
}//首月月供
double AverageCaptial::Decreasing(Loan a)
{
    return ShouldPay(a)*a.InterestRate;//月供递减

}//月供递减
/////////贷款总额/////////
double AverageCaptial:: Repayment(Loans a)
{
    return a.LoanAll+MyInterest(a);//还款总额=贷款总额+利息；
}//贷款总额 还款总额
 double AverageCaptial::MyInterest(Loans a)
 {
     return (a.Month+1)*a.LoanAll*a.InterestRate/2.0;//利息总额=(还款月数+1)×贷款总额×月利率÷2
 }//贷款总额 利息
 double AverageCaptial::ShouldPay(Loans a)
 {
     return a.LoanAll/a.Month;//应还本金
 }//贷款总额 每月应还本金
double AverageCaptial::FirstPay(Loans a)
{
    return 1.0*a.LoanAll/a.Month+a.LoanAll*a.InterestRate;//首月月供额=总贷款额/贷款月数+总贷款额*月利率值；
}//贷款总额 首月月供
double AverageCaptial::Decreasing(Loans a)
{
    return ShouldPay(a)*a.InterestRate;//月供递减
}//贷款总额 月供递减
///////组合贷款////////
double AverageCaptial::LoansALL(Combination a)
{
    return a.CLoans+a.PLoans;
}//贷款总额
double AverageCaptial::Repayment(Combination a)
{
    return LoansALL(a)+MyInterest(a);
}//还款总额
double AverageCaptial::MyInterest(Combination a)
{
    return CMyInterest(a)+PMyInterest(a);
}
double AverageCaptial::FirstPay(Combination a)
{
    return CFirstPay(a)+PFirstPay(a);
}
double AverageCaptial::Decreasing(Combination a)
{
    return CDecreasing(a)+PDecreasing(a);
}
//公积金
//double PRepayment;//还款总额
//PMyInterest=(Month+1)*PLoans*PInterestRate/2.0;//利息总额=(还款月数+1)×贷款总额×月利率÷2
//PShouldPay=PLoans/Month;//应还本金
//PFirstPay=1.0*PLoans/Month+PLoans*PInterestRate;//首月月供额=总贷款额/贷款月数+总贷款额*月利率值；
//PDecreasing=PShouldPay*PInterestRate;//月供递减
 double AverageCaptial::PMyInterest(Combination a)
 {
     return (a.Month+1)*a.PLoans*a.PInterestRate/2.0;
     //利息总额=(还款月数+1)×贷款总额×月利率÷2
 }//利息
 double AverageCaptial::PShouldPay(Combination a)
 {
     return a.PLoans/a.Month;
 }//每月应还本金
double AverageCaptial::PFirstPay(Combination a)
{
    return 1.0*a.PLoans/a.Month+a.PLoans*a.PInterestRate;//首月月供额=总贷款额/贷款月数+总贷款额*月利率值
}//首月月供
double AverageCaptial::PDecreasing(Combination a)
{
    return PShouldPay(a)*a.PInterestRate;//月供递减
}//月供递减
//商贷
////double CRepayment;//还款总额
//CMyInterest=(Month+1)*CLoans*CInterestRate/2.0;//利息总额=(还款月数+1)×贷款总额×月利率÷2
//CShouldPay=CLoans/Month;//应还本金
//CFirstPay=1.0*CLoans/Month+CLoans*CInterestRate;//首月月供额=总贷款额/贷款月数+总贷款额*月利率值；
//CDecreasing=CShouldPay*CInterestRate;//月供递减
//// CRepayment=CLoans+CMyInterest;//还款总额=贷款总额+利息
double AverageCaptial::CMyInterest(Combination a)
{
    //利息
    return (a.Month+1)*a.CLoans*a.CInterestRate/2.0;//利息总额=(还款月数+1)×贷款总额×月利率÷2
}
double AverageCaptial::CShouldPay(Combination a)
{
    //每月应还本金
    return a.CLoans/a.Month;
}
double AverageCaptial::CFirstPay(Combination a)
{
    //首月月供
    return 1.0*a.CLoans/a.Month+a.CLoans*a.CInterestRate;
    //首月月供额=总贷款额/贷款月数+总贷款额*月利率值；
}
double AverageCaptial::CDecreasing(Combination a)
{
    //月供递减
    return CShouldPay(a)*a.CInterestRate;
}
