#include<iostream>
#include<cmath>

using namespace std;
const double pi=3.1415926;
int main()
{
    double d[6];
    double da0=0.0,da,dhe=0;
    double  ubD,uaD,uD,ED;
    int i,n;
    cout<<"cin>>n: "<<endl;
    cin>>n;

    cout<<" cin>>ubD: "<<endl;
    cin>>ubD;//da average

    for(i=0; i<n; i++)
    {
        cout<<"d: "<<endl;
        cin>>d[i];
        da0+=d[i];
    }
    da0=da0/6.0;
    cout<<"da0: "<<da0<<endl;
    da=da0-0.008;
    cout<<"da: "<<da<<endl;
    for(i=0; i<n; i++)
    {
        dhe+=pow(d[i]-da,2);
    }
    uaD=sqrt(dhe/(n*1.0*(n-1)));
    uD=sqrt(pow(uaD,2)+pow(ubD,2));
    ED=uD/da;
    cout<<"uaD: "<<uaD<<endl;
    cout<<"uD: "<<uD<<endl;
    cout<<"ED: "<<ED*100<<"%"<<endl;

}
