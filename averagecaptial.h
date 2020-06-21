#ifndef AVERAGECAPTIAL_H
#define AVERAGECAPTIAL_H
#include <QWidget>
#include<loan.h>
#include<loans.h>
#include<combination.h>
//等额本金还款
class AverageCaptial : public QWidget
{
    Q_OBJECT
public:
    explicit AverageCaptial(QWidget *parent = nullptr);


    ///////根据单价面积模式下等额本金还款/////////
   Loan data;
   double MyHome(Loan a);//房款总额
   double MyLoan(Loan a);//贷款总额
   double Repayment(Loan a);//还款总额
    double DownPayment(Loan a);//首付
    double MyInterest(Loan a);//利息
    double ShouldPay(Loan a);//每月应还本金
   double FirstPay(Loan a);//首月月供
   double Decreasing(Loan a);//月供递减
   ////////根据贷款总额模式下等额本金还款//////////
     Loans _data;
   double Repayment(Loans a);//贷款总额 还款总额
    double MyInterest(Loans a);//贷款总额 利息
    double ShouldPay(Loans a);//贷款总额 每月应还本金
   double FirstPay(Loans a);//贷款总额 首月月供
   double Decreasing(Loans a);//贷款总额 月供递减
    AverageCaptial(Loan a);
    AverageCaptial(Loans a);
    ///////组合贷款模式下等额本金还款/////////
    Combination _Cdata;
    AverageCaptial(Combination a);
    double LoansALL(Combination a);//贷款总额
    double Repayment(Combination a);//还款总额
    double MyInterest(Combination a);
    double FirstPay(Combination a);
    double Decreasing(Combination a);
    //公积金
    //double PRepayment;//还款总额
     double PMyInterest(Combination a);//利息
     double PShouldPay(Combination a);//每月应还本金
    double PFirstPay(Combination a);//首月月供
    double PDecreasing(Combination a);//月供递减
    //商贷
    //double CRepayment;//还款总额
     double CMyInterest(Combination a);//利息
     double CShouldPay(Combination a);//每月应还本金
    double CFirstPay(Combination a);//首月月供
    double CDecreasing(Combination a);//月供递减
signals:

public slots:
};

#endif // AVERAGECAPTIAL_H
