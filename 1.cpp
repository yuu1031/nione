<<<<<<< HEAD
<<<<<<< HEAD
#include<iostream> 
using namespace std;
void queen(char a[])
{	
	int i,j,c,m=0,n=0;
	int b[8]={0};
	for(i=0;i<8;i++)
		a[i]=a[i]-'0';
	for(i=0;i<8;i++) 
	{
		if(a[i]>0&&a[i]<9)
			b[i]=a[i];
		else 
			m=i;
	}
	for(i=1;i<=8;i++)
	{	
		c=0;
		for(j=0;j<8;j++)
		{
			if(i==b[j])
				continue;
			else 
				c++;
		}
		if(c==8) 
			n=i;
	}  
	c=1;
    b[m]=n;
		
    for(i=0;i<7;i++)
    {
		for(j=i+1;j<8;j++)
		{
			if(b[i]-b[j]==j-i||b[j]-b[i]==j-i)/*斜线*/
			c=0;
		}
	}
    if(c)
		cout<<n<<endl;
    else 
		cout<<"No Answer"<<endl;
}
int main()
{  
	char a[8];
	int i;
    for(i=0;i<8;i++)
	{
		cin>>a[i];
	}
	 queen(a);
	 return 0;
=======
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
		double a,b;
		void init(double h, double d)
		{
			a=PI*d*d*h;
			b=PI*2*d*h+2*PI*r*r;
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
int  main() 
{ 
        double  d,h; 
        cin>>d>>h; 
        can.init(h,d/2); 
		can.getvolumn();
		can.getarea();
        cout<<fixed<<setprecision(6); 
        cout<<"油桶的容积是"<<can.getvolumn()<<"  "<<endl; 
        cout<<"铁皮的面积是"<<can.getarea()<<endl; 
		return 0;
>>>>>>> 3
=======
 #include<iostream>
using namespace std;
int main()
{
    double n1;
	int a[4];
	int i,n;
    cin>>n1;
	n=n1*10;
	for(i=0;i<4;i++)
	{	
		
		a[i]=n%10;
		n=n/10;
	}
	for(i=0;i<4;i++)
	{
		{
			if(i==1)
			cout<<".";
		}
	cout<<a[i];
	}

    return 0;
>>>>>>> luo P5705
}
