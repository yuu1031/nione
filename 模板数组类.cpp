#include <iostream>
#include <vector>
using namespace std;

template <typename T>
/*封装一个模板数组类Array，支持以下操作：

1. 构造函数Array(int n)，将数组初始化为n个存储空间，建议使用vector；

2. 函数input(int n)，使用插入运算符<<读取数据，最多读取n个元素，但不能超过数组存储空间的上限；

3. 重载下标运算符，返回数组的元素。*/
class Array
{
//请完成类的设计

public:
    vector<T> arr;
    Array(int n)
    {
    }
    void input(int n)
    // 使用插入运算符<<读取数据，最多读取n个元素，但不能超过数组存储空间的上限；
    {
        for(int i=0; i<n; i++)
        {
            T a;
            cin>>a;
            arr.push_back(a);
        }
    }
    T& operator [](int n)
    {
        return arr[n];
    }

};



class Fract
/*封装一个分数类Fract，用来处理分数功能和运算，能支持你的Array类使用。

1. 构造：传入两个参数n和m，表示n/m；分数在构造时立即转化成最简分数。

提示：分数化简有专门的算法，可自行调研

2. show()函数：分数输出为“a/b”或“-a/b”的形式，a、b都是无符号整数。若a为0或b为1，只输出符号和分子，不输出“/”和分母。

3. 在分数类上重载+=运算符，进行分数的加法运算。*/
{
//请完成类的设计
public:

    Fract(){}
    int n,m;
    int gys(int n,int m)//最大公约数
    {
        while (m != 0)
            {
			int t = n% m;
			n = m;
            m = t;
		}
        int gyueshu = n;
		return gyueshu;
    }
    Fract(int a,int b)
    {
        n=a/gys(a,b);
        m=b/gys(a,b);
    }
    void show();
    Fract operator +=(const Fract &a)//1/4+2/3=1*3+2*4/4*3
    {
        Fract b(a.n*m+a.m*n,a.m*m);
        return *this=b;
    }
    friend istream &operator>>(istream &it,Fract &a)
    {
        it>>a.n>>a.m;
        return it;
    }
	friend ostream &operator<<(ostream &it,Fract &a);
	int fabs(int a)
	{
		if(a>0)
			return a;
		else return 0-a;
	}

};

 void Fract::show()
    {
        if(n==0||m==1)
        {
            cout<<n<<endl;
        }
        else
		{
			if(n*m<0)
            cout<<"-"<<fabs(n)<<"/"<<fabs(m)<<endl;
			else
				cout<<n<<"/"<<m<<endl;
		}
 }

int main()
{
    unsigned int n;
    cin >> n;
    Array<double> db(n);
    db.input(n);
    double dbsum(0.0);
    for (unsigned int i = 0; i < n; i++)
        dbsum += db[i];
    cout << dbsum << endl;

    cin >> n;
    Array<Fract> fr(n);
    fr.input(n);
    Fract frsum(0, 1);
    for ( unsigned int i = 0; i < n; i++)
        frsum += fr[i];
    frsum.show();
}


