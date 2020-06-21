#ifndef COMMERCIALLOAN1_H
#define COMMERCIALLOAN1_H

#include <QWidget>

namespace Ui {
class CommercialLoan1;
}

class CommercialLoan1 : public QWidget
{
    Q_OBJECT

public:
    explicit CommercialLoan1(QWidget *parent = 0);
    ~CommercialLoan1();

   signals:


private:
    Ui::CommercialLoan1 *ui;
};

#endif // COMMERCIALLOAN1_H
