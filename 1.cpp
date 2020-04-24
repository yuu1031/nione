<<<<<<< HEAD
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
			if(b[i]-b[j]==j-i||b[j]-b[i]==j-i)/*б��*/
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
        cout<<"��Ͱ���ݻ���"<<can.getvolumn()<<"  "<<endl; 
        cout<<"��Ƥ�������"<<can.getarea()<<endl; 
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
=======
#include <iostream>
using namespace std;
const float pi=3.14159;
class Shape
/*1）私有成员m_ID

2）公有getter和setter

3）计算面积函数getArea()，返回0;

4）构造与析构函数*/
{
public:
    void setID(int x);
    int  getID();
    int getArea()//计算面积函数getArea()，返回0;
    {
        return 0;
    }
    Shape(int x);
    ~Shape()
    {
        cout<<"Shape destructor called:"<<m_ID<<endl;
    }
private:
    int m_ID;
};
class Circle:public Shape
//Circle类从shape类继承，并派生以下成员
/*1）私有成员r

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数*/
{
public:
    void setR(int x,int ID)
    {
        setID(ID);
        getID();
        r=x;
    }
    double getR()
    {
        return r;
    }
    double getArea()
    {
        double s;
        s=pi*getR()*getR();
        return s;
    }
    Circle(int x,int y):Shape(y)
    {
        r=x;
        cout<<"Circle constructor called:"<<getID()<<endl;
    }
    ~Circle()
    {
        cout<<"Circle destructor called:"<<getID()<<endl;
    }
private:
    int r;

};
class Rectangle:public Shape
//Rectangle类从shape类继承，并派生以下成员
/*1）私有成员h,w

2）公有getter和setter

3）计算面积函数getArea()，返回计算面积;

4）构造与析构函数*/
{
public:
    void setHW(int x,int y,int id)
    {
        setID(x);
        getID();
        h=x;
        w=y;
    }
    int getH()
    {
        return h;
    }
    int getw()
    {
        return w;
    }
    int getArea()
    {
        return w*h;
    }
    Rectangle(int x,int y,int id):Shape(id)
    {
        h=x;
        w=y;
        cout<<"Rectangle constructor called:"<<getID()<<endl;
    };
    ~Rectangle()
    {
        cout<<"Rectangle destructor called:"<<getID()<<endl;
    }
private:
    int h,w;
};
void Shape::setID(int x)
{
    m_ID=x;
}
int  Shape::getID()
{
    return m_ID;
}
Shape::Shape(int x)
{
    m_ID=x;
    cout<<"Shape constructor called:"<<m_ID<<endl;
}

int main()
{
    Shape s(1);//1表示ID
    Circle c(4,2);//4表示半径，2表示ID
    Rectangle r(4, 5,3);//4和5表示长和宽，3表示ID
    cout<<"Shape的面积"<<s.getArea()<<endl;
    cout<<"Circle的面积"<<c.getArea()<<endl;
    cout<<"Rectangle的面积"<<r.getArea()<<endl;
}

>>>>>>> 7
