#ifndef LOANS_H
#define LOANS_H

#include <QWidget>
//根据贷款总额计算
class Loans
{
public:
    Loans();
    Loans(double _a,double _mo,double _ir);
    double LoanAll;
    double  Month;//月数
    double InterestRate;
     Loans operator =(Loans);
     //Loans(Loans &p);
};

#endif // LOANS_H
