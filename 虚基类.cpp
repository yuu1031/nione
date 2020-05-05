#include "iostream"
using namespace std;

class vehicle
{
public:

    void run()
    {
        cout<<"vehicle run"<<endl;
    }
    void stop()
    {
        cout<<"vehicle stop"<<endl;
    }
    vehicle(int x,int y)
    {
        maxspeed=x;
        weight=y;
        cout<<"vehicle constructor called.";
        cout<<" maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
    }
    ~vehicle()
    {
        cout<<"vehicle destructor called.";
        cout<<" maxspeed:"<<maxspeed<<"; weight"<<weight<<endl;
    }
private:
    int maxspeed,weight;
};
class bicycle: virtual public vehicle
//从vehicle派生bicycle和motorcar, bicycle有私有成员height， motorcar有私有成员seatnum,以及各自的构造函数和析构函数。
{
public:

    bicycle(int x,int y,int m):vehicle(y,m)
    {
        height=x;
        cout<<"bicycle constructor called. height:"<<height<<endl;
    }
    ~bicycle()
    {
        cout<<"bicycle destructor called. height:"<<height<<endl;
    }
private :
    int height;
};
class motorcar: virtual public vehicle
{
public:
    motorcar(int x,int y,int m):vehicle(y,m)
    {
        seatnum=x;
        cout<<"motorcar constructor called. seatnum:"<<seatnum<<endl;
    }
    ~motorcar()
    {
        cout<<"motorcar destructor called. seatnum:"<<seatnum<<endl;
    }
private :
    int seatnum;
};
class motorcycle: public bicycle,public motorcar
//从bicycle和motorcar派生出motorcycle，观察虚基类对继承的影响。
{
public:
    motorcycle(int x, int y, int m, int n):bicycle(x,m,n),motorcar(y,m,n),vehicle(m,n)
    {
        cout<<"motorcycle constructor called"<<endl;
    }
    ~motorcycle()
    {
        cout<<"motorcycle destructor called"<<endl;
    }
};


int main(int argc, char *argv[])
{
    motorcycle m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight
    m.run();
    m.stop();
    return 0;
}

