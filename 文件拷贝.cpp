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
		a.push_back(temp);//push_back :��vector a�в�������temp
	}

	in.close() ;
	Order(a) ;
	ofstream out ("b.txt") ;

	for (unsigned int i = 0 ;  i  < a.size() ; i++)
        /*��дunsigned�����о��档warning��comparison between signed and unsigned integer expressions [-Wsign-compare]
        �������˼��һ���޷������������з���������ò�Ҫ�Ƚϡ�
        i���з������ͣ�a.size()���޷�������*/

    {
		out << a[i] << " " ;}
	out.close() ;

	return 0 ;
}

