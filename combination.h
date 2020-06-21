#ifndef COMBINATION_H
#define COMBINATION_H

#include <QWidget>
//组合贷款
class Combination
{
public:
    Combination();
    Combination(double _cl,double _pl,double _mo,double _CI,double _PI);
    Combination operator =(Combination);
    double CLoans;//商业贷款总额
    double PLoans;//公积金贷款总额
    double  Month;//月数
    double CInterestRate;//商业月利率
    double PInterestRate;//公积金月利率

};

#endif // COMBINATION_H
