#include "syndicatedloan.h"
#include "ui_syndicatedloan.h"

SyndicatedLoan::SyndicatedLoan(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SyndicatedLoan)
{
    ui->setupUi(this);
}

SyndicatedLoan::~SyndicatedLoan()
{
    delete ui;
}
