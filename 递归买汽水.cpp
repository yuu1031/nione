#include<iostream>
using namespace std;
 
int Number(int cap,int empty,int bottle)	//capƿ�ǣ�empty��ƿ��bottleơ��ƿ
{
	int a,b,c,d;
	if(empty<2&&cap<3)
	{
	return bottle;
	}
	a=empty/2;		//��ƿ�ɻ���ơ����
	b=empty%2;		//��ƿ����ʣ�µĿ�ƿ��
	c=cap/3;		//ƿ�ǿɻ���ơ����
	d=cap%3;		//ƿ�ǻ���ʣ�µ�ƿ����
	return Number(a+c+d,a+c+b,a+c+bottle);
}
 
int main()
{
	int num,n;
	cin>>num;
	n=num+Number(num,num,0);
	cout<<n<<endl;
	return 0;
}
