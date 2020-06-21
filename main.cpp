<<<<<<< HEAD
#include <iostream>

using namespace std;

int main()
{
   int a[2][3];
   int b[3][2];
   int c[2][2];
   int i,j,k;
    for(i=0;i<2;i++)
   {
       for(j=0;j<3;j++)
        cin>>a[i][j];
   }
     for(i=0;i<3;i++)
   {
       for(j=0;j<2;j++)
        cin>>b[i][j];
   }
   for(i=0;i<2;i++)
   {for(j=0;j<2;j++)
    c[i][j]=0;
   }
   for(i=0;i<2;i++)
   {
       for(j=0;j<2;j++)
       {for(k=0;k<3;k++)
        c[i][j]+=a[i][k]*b[k][j];
       }
   }
   for(i=0;i<2;i++)
   {
       for(j=0;j<2;j++)
    {
        cout<<c[i][j]<<" ";
        if(j==1)
            cout<<endl;
    }

   }
=======
#include "widget.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();

    return a.exec();
>>>>>>> WowW
}
