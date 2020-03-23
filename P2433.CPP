#include<iostream>
#include<cmath>
#include<iomanip>
#define PI 3.141593
using namespace std;
int nineth(void)
{
	int i=1,n=1;
	do{
		n=(n+1)*2;
		i++;
	}while(i!=4);
		return n;
}


int main() 
{
    int T;
    cin >> T;
    if (T == 1) 
	{
        cout << "I love Luogu!";
    } else if (T == 2) 
	{
        cout << 2 + 4 << " " << 10 - 2 - 4;
    } else if (T == 3) {
       cout<<14/4<<endl<<14/4*4<<endl<<14%4<<endl;
    } else if (T == 4) {
        cout<<fixed<<setprecision(3 )<<double(500.0/3)<<endl;
    } else if (T == 5) {
        cout<<(260+220)/(12+20)<<endl;
    } else if (T == 6) {
        cout<<sqrt((6*6)+(9*9))<<endl;
    } else if (T == 7) {
        cout<<100+10<<endl<<100+10-20<<endl<<0;
    } else if (T == 8) {
        cout<<2*PI*5<<endl<<PI*5*5<<endl<<4.0/3*PI*5*5*5;
    } else if (T == 9) {
		cout<<nineth()<<endl;
    } else if (T == 10) {
        cout<<"9"<<endl;
    } else if (T == 11) {
        cout<<double(100.0/3)<<endl;
    } else if (T == 12) {
        cout<<int('M'-'A')+1<<endl<<char('A'+17)<<endl;
    } else if (T == 13) {
        cout<<(int)pow(4.0/3*PI*4*4*4+4.0/3*PI*10*10*10,1.0/3);
    } else if (T == 14) {
        cout<<"50";
    }
    return 0;
}