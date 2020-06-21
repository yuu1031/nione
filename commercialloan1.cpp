#include "commercialloan1.h"
#include "ui_commercialloan1.h"

CommercialLoan1::CommercialLoan1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CommercialLoan1)
{
    ui->setupUi(this);

}

CommercialLoan1::~CommercialLoan1()
{
    delete ui;
}
