#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<acpi.h>
#include<loan.h>
#include<averagecaptial.h>
#include<loans.h>
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    ACPI *target;
    AverageCaptial *ac_pointer;
    void paintEvent(QPaintEvent *);
private:
    Ui::Widget *ui;
};

#endif // WIDGET_H
