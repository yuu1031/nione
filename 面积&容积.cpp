#include  <iostream>
#include<iomanip>
#include  <cmath>
using  namespace  std;

const  double  PI=3.1415926;
class cylinder
{
	private :
		double h,r;

	public :
	    cylinder(double a,double b);
	    ~cylinder()
	    {cout<<"��������������"<<endl;}

		double getvolumn()
		{
			return PI*r*r*h;
		}
		double getarea()
		{
			return PI*2*r*h+2*PI*r*r;
		}
};
cylinder::cylinder(double a,double b)
{
    h=a;
    r=b;
    cout<<"���캯��������"<<endl;
}


int main()

{

    double d,h;

    cin>>d>>h;

    cylinder can(h,d/2);

    cout<<fixed<<setprecision(6);

    cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<" "<<endl;

    cout<<"��Ƥ�������"<<can.getarea()<<endl;

}

