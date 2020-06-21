#include "loan.h"
#include<QDebug>
//根据单价面积
Loan::Loan(QWidget *parent) : QWidget(parent)
{

}
//Loan::Loan(){}
Loan::Loan(Loan &p):QWidget()
{
    this->UnitPrice=p.UnitPrice ;//单价
 this->Area=p.Area ;//面积
 this->Rate=p.Rate ; //成数
 this->Month=p.Month; // 月份
 this->InterestRate=p.InterestRate;
}
Loan::Loan(double _ur,double _ar,double _ra, int _mo,double _ir)
{    UnitPrice=_ur;
        Area=_ar;
      Rate=_ra;
      Month=_mo;
      InterestRate=_ir;}
Loan Loan:: operator =(Loan)
{
    Loan n;
    n.UnitPrice=UnitPrice;
    return n;
}
