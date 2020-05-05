#include <iostream>
using namespace std;

class Complex
{
private:
    double real;
    double imag;
public:
    Complex(double r=0.0,double i=0.0)
    {
        real=r;
        imag=i;
    }
    Complex operator +(Complex c1)
    {
        Complex c;
        c.real=c1.real+real;
        c.imag=c1.imag+imag;
        return Complex(c.real,c.imag);
    }
    Complex operator -(Complex c1)
    {
        Complex c;

        c.real=real-c1.real;
        c.imag=c1.imag-imag;
        if(c.real<0)
            c.real=0-c.real;
        if(c.imag<0)
            c.imag=0-c.imag;
        return Complex(c.real,c.imag);
    }
    void print()//4+3i
    {
        cout<<real<<"+"<<imag<<"i";
    }
};



int main()
{
    Complex a(3,4),b(1,-1),c;
    c=a+b;
    cout<<"a+b=";
    c.print();
    cout<<endl;
    c=a-b;
    cout<<"a-b=";
    c.print();
    cout<<endl;
    c=a+100;
    cout<<"a+100=";
    c.print();
    cout<<endl;
    c=a-2.5;
    cout<<"a-2.5=";
    c.print();
    cout<<endl;

    return 0;
}


