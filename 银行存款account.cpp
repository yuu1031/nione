#include <iostream>
#include <iomanip>
using namespace std;
//请在此处补充Account类的定义
class Account
{	
	public:
	char *ID;
	 char *name;
	char sex;
	int age;
	double sum;
	void init(char a[], char b[],char c[],int d,double e);
	void printmoney();
	void deposit(double money);
	void withdraw(double money);
	
};

void Account::init(char a[], char b[],char c[],int d,double e)
{
		ID=a;
		name=b;
		sex=*c;
		age=d;
		sum=e;
		double sum1,sum2;
		sum1=(int)(sum*100);
		sum2=(int)(sum*1000);
		if(sum1*10!=sum2)
			sum=0;
	};
void Account::printmoney()
{	
	if(sum==0)
	cout<<"您输入的金额不合法"<<endl;
	cout<<name<<"的存款为"<<fixed<<setprecision(2)<<sum<<endl;
};

void Account::deposit(double money)
{	
	double sum1,sum2;
	sum1=(int)(money*100);
	sum2=(int)(money*1000);
	if(sum1*10!=sum2)
		cout<<"您输入的金额不合法"<<endl;
	else
		sum=sum+money;
};
void Account::withdraw(double money){
		
		double sum1,sum2;
		sum1=(int)(money*100);
		sum2=(int)(money*1000);
		if(sum1*10!=sum2)
			cout<<"您输入的金额不合法"<<endl;
		else
			sum=sum-money;
		if(sum<0)
		{
			sum=sum+money;
		cout<<"您的存款金额不足 "<<endl;
		}
};
Account tom,jerry;


int main()
{
    Account tom;
    tom.init("32020320011001876X", "Tom Black", "男", 19, 2000.89);
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(89.471);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为2000.89
    tom.deposit(10000);
    tom.printmoney();//输出：Tom Black的存款为12000.89
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.123);//输出：您输入的金额不合法
    tom.printmoney();//输出：Tom Black的存款为1999.89
    tom.withdraw(10000.9);//输出：您的存款金额不足
    tom.printmoney();//输出：Tom Black的存款为1999.89
    Account jerry;
    jerry.init("320203200910116569", "Jerry Black", "女", 11, 100.956);//输出：您输入的金额不合法
    jerry.printmoney();//输出：Jerry Black的存款为0.00
}

