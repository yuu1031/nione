#ifndef SYNDICATEDLOAN_H
#define SYNDICATEDLOAN_H

#include <QWidget>

namespace Ui {
class SyndicatedLoan;
}

class SyndicatedLoan : public QWidget
{
    Q_OBJECT

public:
    explicit SyndicatedLoan(QWidget *parent = 0);
    ~SyndicatedLoan();

private:
    Ui::SyndicatedLoan *ui;
};

#endif // SYNDICATEDLOAN_H
