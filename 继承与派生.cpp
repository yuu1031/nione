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

