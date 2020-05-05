#include <iostream>
#include <fstream>
#include <vector>
using namespace std ;

void Order(vector<double>& a)
{
	int n = a.size() ;
	double temp ;
	for (int i = 0 ;  i < n; ++i)
	{
		for (int j = 0 ; j < n - i - 1; ++j)
		{
			if (a[j] >a[j + 1])
			{
				temp = a[j] ;
				a[j] = a[j + 1] ;
				a[j + 1] = temp ;
			}
		}
	}
}

int main()
{
	vector<double> a ;
	ifstream in("a.txt") ;
	double temp ;
	while(!in.eof())
	{

		in>>temp ;
		cout<<"t: "<<temp<<endl;
		a.push_back(temp);//push_back :在vector a中插入数据temp
	}

	in.close() ;
	Order(a) ;
	ofstream out ("b.txt") ;

	for (unsigned int i = 0 ;  i  < a.size() ; i++)
        /*不写unsigned会有有警告。warning：comparison between signed and unsigned integer expressions [-Wsign-compare]
        警告的意思是一个无符号数整型与有符号整型最好不要比较。
        i是有符号整型，a.size()是无符号整型*/

    {
		out << a[i] << " " ;}
	out.close() ;

	return 0 ;
}

