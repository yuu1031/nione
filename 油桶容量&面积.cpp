#include <iostream>
#include<iomanip>
#include <cmath>
using namespace std;

const double PI=3.1415926;
//请在此处完善类的设计
class cylinder
{
	private :
		double h,r;
		
	public :
		double a,b;
		void init(double h, double d)
		{
			a=PI*d*d*h;
			b=PI*2*d*h+2*PI*d*d;
		}

		double getvolumn()
		{
			return a;
		}
		double getarea()
		{
			return b;
		}
};
cylinder can;


int main()
{
    double d,h;
    cin>>d>>h;
    
    can.init(h,d/2);
    cout<<fixed<<setprecision(6);
    cout<<"油桶的容积是"<<can.getvolumn()<<" "<<endl;
    cout<<"铁皮的面积是"<<can.getarea()<<endl;
}



