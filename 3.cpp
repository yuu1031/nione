<<<<<<< HEAD
#include<iostream>
#include<iomanip> 
using namespace std;
void swap1(float *a,float *b)
{
	float c;
	c=*a;
	*a=*b;
	*b=c;
}
void swap2(float &a,float &b)
{
float c=a;
	a=b;
	b=c;
}
void main()
{
	float m,n;
	cin>>m>>n;
	swap1(&m,&n);
	cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl;
	swap2(m,n);
    cout<<fixed<<setprecision(2)<<m<<"  "<<n<<endl; 
    cin>>m; 
} 
=======
#include  <iostream> 
#include  <iomanip> 
using  namespace  std; 
class Account
{	
	public:
	char *ID;
	char *name;
	char sex;
	int age;
	double sum;
	void init(char *a, char *b,char *c,int d,double e);
	void printmoney();
	void deposit(double money);
	void withdraw(double money);
	
};

void Account::init(char *a, char *b,char *c,int d,double e)
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
	cout<<"������Ľ��Ϸ�"<<endl;
	cout<<name<<"�Ĵ��Ϊ"<<fixed<<setprecision(2)<<sum<<endl;
};

void Account::deposit(double money)
{	
	double sum1,sum2;
	sum1=(int)(money*100);
	sum2=(int)(money*1000);
	if(sum1*10!=sum2)
		cout<<"������Ľ��Ϸ�"<<endl;
	else
		sum=sum+money;
};
void Account::withdraw(double money){
		
		double sum1,sum2;
		sum1=(int)(money*100);
		sum2=(int)(money*1000);
		if(sum1*10!=sum2)
			cout<<"������Ľ��Ϸ�"<<endl;
		else
			sum=sum-money;
		if(sum<0)
		{
			sum=sum+money;
		cout<<"���Ĵ����� "<<endl;
		}
};
Account tom,jerry;
int  main() 
{ 
        Account  tom; 
        tom.init("32020320011001876X",  "Tom  Black",  "��",  19,  2000.89); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(89.471);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
        tom.deposit(10000); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
        tom.withdraw(10001); 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        tom.withdraw(10000.9);//��������Ĵ����� 
        tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
        Account  jerry; 
        jerry.init("320203200910116569",  "Jerry  Black",  "Ů",  11,  100.956);//�����������Ľ��Ϸ� 
        jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
		return 0;
}
>>>>>>> 3
