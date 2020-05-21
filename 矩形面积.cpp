#include <iostream>
using namespace std;
//请在这里补充CPoint，CRectangle类的定义
#include<iostream>
using namespace std;
class CPoint
{

public:
    int x,y;//x,y坐标
    CPoint(int a=0,int b=0);
    CPoint (CPoint &p);
};
class CRectangle
{
public:
    CPoint p1;
    CPoint p2;
    int le,ri;//le:左边，ri；右边
    int left();
    int right();
    CRectangle();
    CRectangle(CPoint a,CPoint b);
    CRectangle(int a,int b,int c,int d);
    CRectangle(CRectangle& p);
    int GetArea();
};
CPoint::CPoint(int a,int b)
{
    x=a;
    y=b;
    cout<<"CPoint contstructor with default value(0,0) is called."<<endl;
}
CPoint::CPoint(CPoint &p)
{
    x=p.x;
    y=p.y;
    cout<<"CPoint copy contstructor is called."<<endl;
}
CRectangle::CRectangle(CPoint a,CPoint b):p1(a),p2(b)
{
    cout<<"CRectangle contstructor with (CPoint,CPoint) is called."<<endl;
}
CRectangle::CRectangle()
{
    cout<<"CRectangle default contstructor is called."<<endl;
}
CRectangle::CRectangle(int a,int b,int c,int d):p1(a,b),p2(c,d)
{
    cout<<"CRectangle contstructor with (int,int,int,int) is called."<<endl;
}
CRectangle::CRectangle(CRectangle& p):p1(p.p1),p2(p.p2)
{
    cout<<"CRectangle copy contstructor is called."<<endl;
}
int CRectangle::left()
{
    if(p1.x>p2.x)
        le=p1.x-p2.x;
    else
        le=p2.x-p1.x;
    return le;
}
int CRectangle::right()
{
    if(p1.y>p2.y)
        ri=p1.y-p2.y;
    else
        ri=p2.y-p1.y;
    return ri;
}
int CRectangle::GetArea()
{
    return left()*right();
}


int main()
{
    int a=1, b=1, c=6, d=11;
    cout<<"# Define p1 ######"<<endl;
    CPoint p1;
    cout<<"# Define p2 ######"<<endl;
    CPoint p2(10,20);
    cout<<"# Define rect1 ######"<<endl;
    CRectangle rect1;
    cout<<"# Define rect2 ######"<<endl;
    CRectangle rect2(p1, p2);
    cout<<"# Define rect3 ######"<<endl;
    CRectangle rect3(a, b, c, d);
    cout<<"# Define rect4 ######"<<endl;
    CRectangle rect4(rect2);
    cout<<"# Calculate area ######"<<endl;
    cout << "rect1面积为" << rect1.GetArea() << endl;
    cout << "rect2面积为" << rect2.GetArea() << endl;
    cout << "rect3面积为" << rect3.GetArea() << endl;
    cout << "rect4面积为" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}



