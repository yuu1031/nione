#include "widget.h"
#include "ui_widget.h"
#include<QListWidgetItem>
#include<QString>
#include<math.h>
#include<acpi.h>
#include<loan.h>
#include<averagecaptial.h>
#include<QDebug>
#include<loans.h>
#include<combination.h>
#include<QMessageBox>
#include<QRegExp>
#include<QRegExpValidator>
#include<torf.h>
#include<QLineEdit>
#include<QPainter>
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

    setFixedSize(630,720);
    setWindowIcon(QIcon(":/图片/图片/1592717304603.png"));
    //栈控件的使用
    //设置默认定位 Calculator
     ui->stackedWidget->setCurrentIndex(0);
     ui->stackedWidget_2->setCurrentIndex(0);
     ui->stackedWidget_4->setCurrentIndex(0);
     //设置提示信息
     ui->lineEdit->setPlaceholderText("请输入单价");
     ui->lineEdit_2->setPlaceholderText("请输入面积");
     ui->lineEdit_3->setPlaceholderText("请输入贷款利率");
     ui->lineEdit_4->setPlaceholderText("请输入贷款总额");
     ui->lineEdit_5->setPlaceholderText("请输入商业利率");
     ui->lineEdit_6->setPlaceholderText("请输入公积金总额");
     ui->lineEdit_7->setPlaceholderText("请输入公积金总利率");
     ui->lineEdit_8->setPlaceholderText("请输入商业总额");

    //Calculator按钮
    connect(ui->btn_Calaulator,&QPushButton::clicked,[=](){

        ui->stackedWidget->setCurrentIndex(0);
    });
    connect(ui->btn_Close,&QPushButton::clicked,[=](){
        close();//关闭页面
    });

    //Result按钮
    connect(ui->btn_Result,&QPushButton::clicked,[=](){
            ui->stackedWidget->setCurrentIndex(1);
    });
    //CleanAgain按钮
    connect(ui->btn_CleanAgain,&QPushButton::clicked,[=](){
        ui->stackedWidget->setCurrentIndex(0);

        QMessageBox::StandardButton rb = QMessageBox::question(NULL, "(⊙﹏⊙)", "确定要清空数据吗？", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        if(rb == QMessageBox::Yes)
        {
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->lineEdit_5->clear();
            ui->lineEdit_6->clear();
            ui->lineEdit_7->clear();
            ui->lineEdit_8->clear();
        }
    });

    //radioButton_3商业型贷款
    connect(ui->radioButton_3,&QPushButton::clicked,[=](){
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_4->setCurrentIndex(0);
        ui->widget_9->show();
    });

    //radioButton_4公积金型贷款
    connect(ui->radioButton_4,&QPushButton::clicked,[=](){
        ui->stackedWidget_2->setCurrentIndex(0);
        ui->stackedWidget_4->setCurrentIndex(0);
        ui->widget_9->show();
    });

    //radioButton_5组合型贷款
    connect(ui->radioButton_5,&QPushButton::clicked,[=](){
        ui->stackedWidget_2->setCurrentIndex(1);
        ui->stackedWidget_4->setCurrentIndex(1);
         ui->widget_9->hide();
         ui->listWidget->clear();
    });
    //radioButton_6根据面积、单价计算按钮
    connect(ui->radioButton_6,&QPushButton::clicked,[=](){
        ui->stackedWidget_2->setCurrentIndex(0);
    });
    //radioButton_7根据贷款总额计算按钮
    connect(ui->radioButton_7,&QPushButton::clicked,[=](){
        ui->stackedWidget_2->setCurrentIndex(2);
    });
    //按揭成数RestrictedMortgages
    for(int i=0;i<14;i++)
    {
        ui->RestrictedMortgages->addItem(QString::number(8-i*0.5));
    }
    //按揭年数MortgageYears
    for(int i=25;i>0;i--)
    {
        ui->MortgageYears->addItem(QString::number(i));
    }

    QListWidgetItem *item=new QListWidgetItem("计算结果");
    ui->listWidget->addItem(item);
          connect(ui->radioButton,&QRadioButton::clicked,[=](){//等额本息
             connect(ui->btn_Result,&QPushButton::clicked,[=](){//计算结果

                 if(ui->radioButton_6->isChecked())//根据单价面积计算
             {


                 if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()) //判断lineedit输入内容是否为空
                      {
                          QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                          return;
                      }
                 QString a0=ui->lineEdit->text();
                 double a=a0.toDouble();//获取单价的数据
                 QString b0=ui->lineEdit_2->text();
                 double b=b0.toDouble();//获取面积的数据
                 double  c=ui->RestrictedMortgages->currentText().toDouble();//获取成数的数据

                 int d=ui->MortgageYears->currentText().toDouble()*12;//获取月份的数据
                 QString e0=ui->lineEdit_3->text();
                 double e=e0.toDouble()/(12*100.0);//获取年利率->月利率
                 QRegExp rx;
                 rx.setPatternSyntax(QRegExp::RegExp);
                 rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                 if(!rx.exactMatch(a0)||!rx.exactMatch(b0)||!rx.exactMatch(e0))
                 {
                     QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                     return;
                 } //返回的值为false

                 Loan data(a,b,c,d,e);
               TOrF guide;
               if(!guide.Valid(data))
               {
                   QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                   return;
               }
               ACPI target(data);
             ui->listWidget->clear();
             QListWidgetItem *item=new QListWidgetItem("查看结果");
             ui->listWidget->addItem(item);
             item->setTextAlignment(Qt::AlignHCenter);
             item->setForeground(QBrush(QColor(255,0,0)));
             QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
             item1->setTextAlignment(Qt::AlignRight);
             item1->setForeground(QBrush(QColor(160,152,133)));
             if(ui->radioButton_3->isChecked())
             {
                 QListWidgetItem *type=new QListWidgetItem("贷款类型：商业贷款");
                 ui->listWidget->addItem(type);
             }
             if(ui->radioButton_4->isChecked())
             {
                 QListWidgetItem *type=new QListWidgetItem("贷款类型：公积金贷款");
                 ui->listWidget->addItem(type);
             }
             QListWidgetItem *item3=new QListWidgetItem("还款类型：等额本息");
             ui->listWidget->addItem(item3);
//                QString::sprintf() 字符串连接函数
//                备注：QString::sprintf()函数支持与C/C++库中的sprintf 函数相同的格式说明符。
             QString str,str1,str2,str3,str4,str5,str6,str7;
             str.sprintf("%s%.2lf %s","房款总额: ",target.MyHome(data),"元");
             str1.sprintf("%s%.2lf %s","贷款总额: ",target.MyLoan(data),"元");
            str2.sprintf("%s%.2lf %s","还款总额: ",target.Repayment(data),"元");
             str3.sprintf("%s%.2lf %s","支付利息: ",target.MyInterest(data),"元");
            str4.sprintf("%s%.2lf %s","首付: ",target.DownPayment(data),"元");
             str5.sprintf("%s%d %s","还款月数: ",data.Month,"（月）");
             str6.sprintf("%s%.2lf %s","月均还款: ",target.AverageMonRepayment(data),"元");
             ui->listWidget->addItem(str);
            ui->listWidget->addItem(str1);
             ui->listWidget->addItem(str2);
             ui->listWidget->addItem(str3);
             ui->listWidget->addItem(str4);
             ui->listWidget->addItem(str5);
             ui->listWidget->addItem(str6);
             ui->listWidget->addItem(item1);
                 }
             if(ui->radioButton_7->isChecked())//根据贷款总额计算
             {
                 if(ui->lineEdit_4->text().isEmpty()||ui->lineEdit_3->text().isEmpty()) //判断lineedit输入内容是否为空
                      {
                          QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                          return;
                      }
                 QString a0=ui->lineEdit_4->text();
                 double a=a0.toDouble()*10000.0;//获取贷款总额
                 double e=ui->MortgageYears->currentText().toDouble()*12.0;//获取年份的数据        
                 QString c0=ui->lineEdit_3->text();
                 double f=c0.toDouble()/(12*100.0);//获取年利率的数据
                 QRegExp rx;
                 rx.setPatternSyntax(QRegExp::RegExp);
                 rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                 if(!rx.exactMatch(a0)||!rx.exactMatch(c0))
                 {
                     QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                     return;
                 } //返回的值为false

                 Loans data(a,e,f);
                 TOrF guide;
                 if(!guide.Valid(data))
                 {
                     QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                     return;
                 }
                 ACPI target(data);
                 ui->listWidget->clear();
                 QListWidgetItem *item=new QListWidgetItem("查看结果");
                 ui->listWidget->addItem(item);
                 item->setTextAlignment(Qt::AlignHCenter);
                 item->setForeground(QBrush(QColor(255,0,0)));
                 QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
                 item1->setTextAlignment(Qt::AlignRight);
                 item1->setForeground(QBrush(QColor(160,152,133)));
                 QListWidgetItem *item3=new QListWidgetItem("还款类型:等额本息");
                 ui->listWidget->addItem(item3);
 //                QString::sprintf() 字符串连接函数
 //                备注：QString::sprintf()函数支持与C/C++库中的sprintf 函数相同的格式说明符。
                 QString str1,str2,str3,str4,str5;

                 str1.sprintf("%s%.2lf %s","贷款总额: ",data.LoanAll,"元");
                 str2.sprintf("%s%.2lf %s","还款总额: ", target.Repayment(data),"元");
                 str3.sprintf("%s%.2lf %s","支付利息: ",target.MyInterest(data),"元");
                 str4.sprintf("%s%.0lf %s","还款月数: ",data.Month,"（月）");
                 str5.sprintf("%s%.2lf %s","月均还款: ",target.AverageMonRepayment(data),"元");

                 ui->listWidget->addItem(str1);
                 ui->listWidget->addItem(str2);
                 ui->listWidget->addItem(str3);
                 ui->listWidget->addItem(str4);
                 ui->listWidget->addItem(str5);
                 ui->listWidget->addItem(item1);
             }
             if(ui->radioButton_5->isChecked())//组合贷款
             {
                 if(ui->lineEdit_5->text().isEmpty()||ui->lineEdit_6->text().isEmpty()||ui->lineEdit_7->text().isEmpty()||ui->lineEdit_8->text().isEmpty()) //判断lineedit输入内容是否为空
                      {
                          QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                          return;
                      }
                 QString a0=ui->lineEdit_8->text();
                 double a=a0.toDouble();//获取商业贷款总额
                 QString b0=ui->lineEdit_6->text();
                 double b=b0.toDouble();
                 double c=ui->MortgageYears->currentText().toDouble()*12;//获取年份的数据
                 QString d0=ui->lineEdit_5->text();
                 double d=d0.toDouble()/(12*100.0);//获取商业年利率的数据
                 QString e0=ui->lineEdit_7->text();
                 double e=e0.toDouble()/(12*100.0);//获取公积金年利率的数据
                 QRegExp rx;
                 rx.setPatternSyntax(QRegExp::RegExp);
                 rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                 if(!rx.exactMatch(a0)||!rx.exactMatch(b0)||!rx.exactMatch(e0)||!rx.exactMatch(d0))
                 {
                     QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                     return;
                 } //返回的值为false

                 Combination data(a,b,c,d,e);
                 ACPI target(data);
                 TOrF guide;
                 if(!guide.Valid(data))
                 {
                     QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                     return;
                 }

                 ui->listWidget->clear();

                 QListWidgetItem *item=new QListWidgetItem("查看结果");
                 ui->listWidget->addItem(item);
                 item->setTextAlignment(Qt::AlignHCenter);
                 item->setForeground(QBrush(QColor(255,0,0)));
                 QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
                 item1->setTextAlignment(Qt::AlignRight);
                 item1->setForeground(QBrush(QColor(160,152,133)));
                 QListWidgetItem *item3=new QListWidgetItem("贷款类型：组合贷款");
                 ui->listWidget->addItem(item3);
                 //QString::sprintf() 字符串连接函数
                 //备注：QString::sprintf()函数支持与C/C++库中的sprintf 函数相同的格式说明符。
                 QString str1,str2,str3,str4,str5,str6,str7;
                 str6.sprintf("%s%.2lf %s","商业贷款总额: ",data.CLoans,"元");
                 str7.sprintf("%s%.2lf %s","公积金贷款总额: ",data.PLoans,"元");
                 str1.sprintf("%s%.2lf %s","贷款总额: ",target.LoansALL(data),"元");
                 str2.sprintf("%s%.2lf %s","还款总额: ", target.Repayment(data),"元");
                 str3.sprintf("%s%.2lf %s","支付利息: ",target.MyInterest(data),"元");
                 str4.sprintf("%s%.0lf %s","还款月数: ",data.Month,"（月）");
                 str5.sprintf("%s%.2lf %s","月均还款: ",target.AverageMonRepayment(data),"元");

                 ui->listWidget->addItem(str6);
                 ui->listWidget->addItem(str7);
                 ui->listWidget->addItem(str1);
                 ui->listWidget->addItem(str2);
                 ui->listWidget->addItem(str3);
                 ui->listWidget->addItem(str4);
                 ui->listWidget->addItem(str5);

                 ui->listWidget->addItem(item1);
             }
             });
         });

        connect(ui->radioButton_2,&QRadioButton::clicked,[=](){//等额本金
            connect(ui->btn_Result,&QPushButton::clicked,[=](){//计算结果
                 if(ui->radioButton_6->isChecked())//根据单价面积计算
                 {
                     if(ui->lineEdit->text().isEmpty()||ui->lineEdit_2->text().isEmpty()||ui->lineEdit_3->text().isEmpty()) //判断lineedit输入内容是否为空
                          {
                              QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                              return;
                          }
                     QString a0=ui->lineEdit->text();
                     double a=a0.toDouble();//获取单价的数据
                     QString b0=ui->lineEdit_2->text();
                     double b=b0.toDouble();//获取面积的数据
                     double c=ui->RestrictedMortgages->currentText().toDouble();//获取成数的数据
                     int d=ui->MortgageYears->currentText().toDouble()*12;//获取月份的数据
                     QString c0=ui->lineEdit_3->text();
                     double e=c0.toDouble()/(12*100.0);//获取年利率->月利率
                     QRegExp rx;
                     rx.setPatternSyntax(QRegExp::RegExp);
                     rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                     if(!rx.exactMatch(a0)||!rx.exactMatch(b0)||!rx.exactMatch(c0))
                     {
                         QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                         return;
                     } //返回的值为false

                     Loan data(a,b,c,d,e);
                     TOrF guide;
                     if(!guide.Valid(data))
                     {
                         QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                         return;
                     }
                     AverageCaptial ac_pointer(data);


                 ui->listWidget->clear();

                QListWidgetItem *item=new QListWidgetItem("查看结果");
                ui->listWidget->addItem(item);
                item->setTextAlignment(Qt::AlignHCenter);
                item->setForeground(QBrush(QColor(255,0,0)));
                QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
                item1->setTextAlignment(Qt::AlignRight);
                item1->setForeground(QBrush(QColor(160,152,133)));
                QListWidgetItem *item3=new QListWidgetItem("还款类型：等额本金");
                ui->listWidget->addItem(item3);
//                QString::sprintf() 字符串连接函数
//                备注：QString::sprintf()函数支持与C/C++库中的sprintf 函数相同的格式说明符。
                QString str,str1,str2,str3,str4,str5,str6,str7;
                str.sprintf("%s%.2lf %s","房款总额: ",ac_pointer.MyHome(data),"元");
                str1.sprintf("%s%.2lf %s","贷款总额: ",ac_pointer.MyLoan(data),"元");
                str2.sprintf("%s%.2lf %s","还款总额: ", ac_pointer.Repayment(data),"元");
                str3.sprintf("%s%.2lf %s","支付利息: ",ac_pointer.MyInterest(data),"元");
                str4.sprintf("%s%.2lf %s","首付: ",ac_pointer.DownPayment(data),"元");
                str5.sprintf("%s%d %s","还款月数: ",data.Month,"（月）");
                str6.sprintf("%s%.2lf %s","首月月供: ",ac_pointer.FirstPay(data),"元");
                 str7.sprintf("%s%.2lf %s","月供递减: ",ac_pointer.Decreasing(data),"元");

                ui->listWidget->addItem(str);
                ui->listWidget->addItem(str1);
                ui->listWidget->addItem(str2);
                ui->listWidget->addItem(str3);
                ui->listWidget->addItem(str4);
                ui->listWidget->addItem(str5);
                ui->listWidget->addItem(str6);
                 ui->listWidget->addItem(str7);
                ui->listWidget->addItem(item1);
                 }
                 if(ui->radioButton_7->isChecked())//根据贷款总额计算
                 {
                     if(ui->lineEdit_4->text().isEmpty()||ui->lineEdit_3->text().isEmpty()) //判断lineedit输入内容是否为空
                          {
                              QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                              return;
                          }
                     QString a0=ui->lineEdit_4->text();
                     double a=a0.toDouble()*10000.0;//获取贷款总额
                     double e=ui->MortgageYears->currentText().toDouble()*12.0;//获取年份的数据
                     QString c0=ui->lineEdit_3->text();
                     double f=c0.toDouble()/(12*100.0);//获取年利率的数据
                    QRegExp rx;
                    rx.setPatternSyntax(QRegExp::RegExp);
                    rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                    if(!rx.exactMatch(a0)||!rx.exactMatch(c0))
                    {
                        QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                        return;
                    } //返回的值为false
                    Loans data(a,e,f);
                    TOrF guide;
                    if(!guide.Valid(data))
                    {
                        QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                        return;
                    }
                    AverageCaptial ac_pointer(data);

                    ui->listWidget->clear();

                    QListWidgetItem *item=new QListWidgetItem("查看结果");
                    ui->listWidget->addItem(item);
                    item->setTextAlignment(Qt::AlignHCenter);
                    item->setForeground(QBrush(QColor(255,0,0)));
                    QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
                    item1->setTextAlignment(Qt::AlignRight);
                    item1->setForeground(QBrush(QColor(160,152,133)));
                    QListWidgetItem *item3=new QListWidgetItem("还款类型：等额本金");
                    ui->listWidget->addItem(item3);

                    QString str,str1,str2,str3,str4,str5;
                    str.sprintf("%s%.2lf %s","首月月供: ",ac_pointer.FirstPay(data),"元");
                    str1.sprintf("%s%.2lf %s","月供递减: ",ac_pointer.Decreasing(data),"元");
                    str2.sprintf("%s%.2lf %s","贷款总额: ",data.LoanAll,"元");
                    str4.sprintf("%s%.2lf %s","还款总额: ", ac_pointer.Repayment(data),"元");
                    str3.sprintf("%s%.2lf %s","支付利息: ",ac_pointer.MyInterest(data),"元");
                    str5.sprintf("%s%.0lf %s","还款月数: ",data.Month,"（月）");
                    ui->listWidget->addItem(str);
                    ui->listWidget->addItem(str1);
                    ui->listWidget->addItem(str2);
                    ui->listWidget->addItem(str3);
                    ui->listWidget->addItem(str4);
                    ui->listWidget->addItem(str5);
                    ui->listWidget->addItem(item1);
                 }
                 if(ui->radioButton_5->isChecked())//组合贷款
                 {
                     if(ui->lineEdit_5->text().isEmpty()||ui->lineEdit_6->text().isEmpty()||ui->lineEdit_7->text().isEmpty()||ui->lineEdit_8->text().isEmpty()) //判断lineedit输入内容是否为空
                          {
                              QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入数据"),QMessageBox::Ok);
                              return;
                          }
                     QString a0=ui->lineEdit_8->text();
                     double a=a0.toDouble();//获取商业贷款总额
                     QString b0=ui->lineEdit_6->text();
                     double b=b0.toDouble();
                     double c=ui->MortgageYears->currentText().toDouble()*12;//获取年份的数据
                     QString d0=ui->lineEdit_5->text();
                     double d=d0.toDouble()/(12*100.0);//获取商业年利率的数据
                     QString e0=ui->lineEdit_7->text();
                     double e=e0.toDouble()/(12*100.0);//获取公积金年利率的数据
                     QRegExp rx;
                     rx.setPatternSyntax(QRegExp::RegExp);
                    rx.setPattern(QString("^[0-9]+(\.?[0-9]+)?$"));//检查输入是否是数字组成的字符串
                     if(!rx.exactMatch(a0)||!rx.exactMatch(b0)||!rx.exactMatch(e0)||!rx.exactMatch(d0))
                     {
                         QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("您输入的数据格式不规范，请输入正确格式的数据"),QMessageBox::Ok);
                         return;
                     } //返回的值为false
                     Combination data(a,b,c,d,e);
                     TOrF guide;
                     if(!guide.Valid(data))
                     {
                         QMessageBox::information(this,tr("(⊙﹏⊙)"),QStringLiteral("请输入有效范围内的数据"),QMessageBox::Ok);
                         return;
                     }
                     AverageCaptial ac_pointer(data);
                     ui->listWidget->clear();
                     QListWidgetItem *item=new QListWidgetItem("查看结果");
                     ui->listWidget->addItem(item);
                     item->setTextAlignment(Qt::AlignHCenter);
                     item->setForeground(QBrush(QColor(255,0,0)));
                     QListWidgetItem *item1=new QListWidgetItem("*以上结果仅供参考");
                     item1->setTextAlignment(Qt::AlignRight);
                     item1->setForeground(QBrush(QColor(160,152,133)));
                     QListWidgetItem *item3=new QListWidgetItem("贷款类型：组合贷款-等额本金");
                     ui->listWidget->addItem(item3);

                     QString str6,str7,str1,str2,str3,str4,str5;
                      str6.sprintf("%s%.2lf %s","首月月供: ",ac_pointer.FirstPay(data),"元");
                     str7.sprintf("%s%.2lf %s","每月递减: ",ac_pointer.Decreasing(data),"元");
                     str3.sprintf("%s%.2lf %s","贷款总额: ",ac_pointer.LoansALL(data),"元");
                     str4.sprintf("%s%.2lf %s","还款总额: ", ac_pointer.Repayment(data),"元");
                     str5.sprintf("%s%.2lf %s","支付利息: ",ac_pointer.MyInterest(data),"元");
                     str5.sprintf("%s%.0lf %s","还款月数: ",data.Month,"（月）");
                     str1.sprintf("%s%.2lf %s","商业贷款总额: ",data.CLoans,"元");
                     str2.sprintf("%s%.2lf %s","公积金贷款总额: ",data.PLoans,"元");

                     ui->listWidget->addItem(str1);
                     ui->listWidget->addItem(str2);
                     ui->listWidget->addItem(str3);
                     ui->listWidget->addItem(str4);
                     ui->listWidget->addItem(str5);
                     ui->listWidget->addItem(str6);
                     ui->listWidget->addItem(str7);
                     ui->listWidget->addItem(item1);
                 }
            });
        });
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/图片/ding.png");
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
}

Widget::~Widget()
{
    delete ui;
}
