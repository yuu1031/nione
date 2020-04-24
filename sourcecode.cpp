<<<<<<< HEAD
<<<<<<< HEAD
//实现功能：既能排序整型数，也可以排序字符串

#include <iostream>
#include <cstring>
using namespace std;

int cmpGT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回1，等于则返回0，小于则返回-1
  int n;
    if(*p1>*p2)
        n=1;
    if(*p1<*p2)
        n=-1;
    if(*p1==*p2)
        n=0;
    return n;

}
int cmpLT(const int *p1, const int *p2)
{
//实现两数比较，如果大于，则返回-1，等于则返回0，小于则返回1
  int n;
    if(*p1>*p2)
        n=-1;
    if(*p1<*p2)
        n=1;
    if(*p1==*p2)
        n=0;
    return n;


}

void swap(int *p1, int *p2)
{
//实现两个整形变量的值交换
    int *t;
    t=p1;
    p1=p2;
    p2=t;

}

void bubble(int *base,  int(*cmp)(const int *, const int *))
{
//请在这里补充冒泡排序，请根据main函数中对bubble函数的调用，分析形参的作用

    int i,j,k;
    for(i=0;i<10;i++)
        {for(j=i+1;j<10;j++)

        {
            k=(cmp)(&base[i],&base[j]);
            if(k==1)
            swap(base[i],base[j]);
        }
        }


}

int main()
{
	int arr[] = { 1, 3, 5, 7, 9, 2, 4, 6, 8, 0 };
	int i = 0;
	bubble(arr,  cmpGT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout<<endl;

	bubble(arr,  cmpLT);
	for (i = 0; i < 10; i++)
	{
		cout<<arr[i]<<" ";
	}	
	cout<<endl;
=======
#include <iostream>
#include <string>
using namespace std;

class CStudent
{

private:
   const char *name="noname";

    int age;
public:
    static int count;
    static int getcount()
    {
        return count;
    }
    CStudent(const char a[],int age)
    {
        name=a;
        this->age=age;
        count++;
        cout<<name<<" is contructing"<<endl;
    }
     CStudent()
    {
        count++;
        cout<<" noname is contructing"<<endl;
    }
    ~CStudent( )
    {
        count--;
        cout<<name<<" is destructing"<<endl;
    }

    void printname()
    {
        cout<<"name:"<<name<<endl;
    }

};
//请在这里初始静态成员变量
int CStudent::count=0;


int main()
{
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuB[5];
		stuB[4].printname();
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;
	{
		CStudent stuA[2] = {CStudent("Tom", 3), CStudent("Jerry", 2)};
		for (int i = 0; i < 2; i++)
		{
			stuA[i].printname();
		}
		cout << "现在有学生" << CStudent::getcount() << endl;
	}
	cout << "现在有学生" << CStudent::getcount() << endl;

>>>>>>> 6(2)
	return 0;
=======
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
>>>>>>> 7
}

