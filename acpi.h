#ifndef ACPI_H
#define ACPI_H

#include <QWidget>
#include<loan.h>
#include<loans.h>
#include<combination.h>
//等额本息还款
class ACPI : public QWidget
{
    Q_OBJECT
public:
    explicit ACPI(QWidget *parent = nullptr);
     Loan data;
     Loans _Adata;
     Combination _Cdata;
    ////////根据单价面积////////
     ACPI(Loan a);
     double MyHome(Loan a);
     double DownPayment(Loan a);//首付
     double MyLoan(Loan a);//贷款总额=房款总额-首付
     double AverageMonRepayment(Loan a);
     double  MyInterest(Loan a);
     double Repayment(Loan a);
    ///////根据贷款总额///////
     ACPI(Loans a);
     double Repayment(Loans a);
     double MyInterest(Loans a);
     double AverageMonRepayment(Loans a);
    ////////组合贷款///////
     ACPI(Combination a);
     double LoansALL(Combination a);//贷款总额
     double Repayment(Combination a);//还款总额
     double MyInterest(Combination a);//总利息
     double CAverageMonRepayment(Combination a);//商业还款月利息
     double PAverageMonRepayment(Combination a);//公积金还款月利息
     double AverageMonRepayment(Combination a);//月均还款

signals:

public slots:
};

#endif // ACPI_H
