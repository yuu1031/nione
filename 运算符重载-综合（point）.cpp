#include <iostream>
using namespace std;
 class Point
 {
 private :
    int m_x,m_y;
 public:
    Point(int a,int b)
    {
        m_x=a;
        m_y=b;
    }
    Point& operator ++();
    Point operator ++(int);
    friend ostream& operator << (ostream&,Point );  //运算符“<<”重载为友元函数
 };
 Point&Point:: operator++()
 {
     m_x++;
     m_y++;
     return *this;
 }
 Point Point::operator++(int)
 {
      Point old=*this;
      ++(*this);
      return old;
 }
 ostream& operator << (ostream& output,Point c)//定义运算符“<<”重载函数
{
   output<<"("<<c.m_x<<","<<c.m_y<<")"<<endl;
   return output;
}

int main()
{
    Point a(1,3);
    cout<<a;
    cout<<a++;
    cout<<++a;
    return 0;
}

