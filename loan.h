#ifndef LOAN_H
#define LOAN_H

#include <QWidget>
//根据单价面积计算
class Loan : public QWidget
{
    Q_OBJECT
public:
    explicit Loan(QWidget *parent = nullptr);
    double UnitPrice;//单价
    double Area;//面积
   double Rate; //成数
     int Month; // 月份
     double InterestRate; // 月利率
     Loan operator =(Loan);
    //Loan();
    Loan(double _ur,double _ar,double _ra, int _mo,double _ir);
    Loan(Loan &p);
    //接收 单价，面积，成数，月数，利率
signals:

public slots:
};

#endif // LOAN_H
