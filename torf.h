#ifndef TORF_H
#define TORF_H
#include<loan.h>
#include <QWidget>
#include<loans.h>
#include<combination.h>
class TOrF : public QWidget
{
    Q_OBJECT
public:
    explicit TOrF(QWidget *parent = nullptr);
    bool Valid(Loan a);
    bool Valid(Loans a);
    bool Valid(Combination a);
signals:

public slots:
};

#endif // TORF_H
