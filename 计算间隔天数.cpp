 #include <iostream>
 #include <iostream>

using namespace std;

int run(int y)//��
{
    if ((y%100!=0&&y%4==0)||y%400==0)
        y=366;
    else
		y=365;
    return y;
}
int yue(int m,int y)
{
    int day=0;
    switch(m)
    {
    case 4: case 6: case 9: case 11:
        day=30;
        break;
    case 2:
        if(run(y)==366)

                day=29;
            else
                day=28;

        break;
    default:
        day=31;
    }

        return day;
}
//����һ����ʾʱ�����CTime�����Ծ�ȷ��ʾ�ꡢ�¡��ա�Сʱ���֡��룬������������ڶ���֮�������������
class CTime
{
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
public:
    int torf;
    CTime(int y=0,int mo=0,int d=0,int h=0,int m=0,int s=0);
    CTime(CTime& p);
    ~CTime ()
    {
        cout<<"��������������"<<endl;
    }
    int dayDiff(CTime t) ;//���ڼ��㵱ǰ�������β�t֮��������������ע���������Ϊ���ڵ���0����������ע����������⡣
    void showTime();
    int isvalid();//��ʾ���ڣ���ʾ��ʽΪ��2020/3/12 11:50:20
};

CTime::CTime(int y,int mo,int d,int h,int m,int s)
//���������Ч������� ��date error! ��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��
//���ʱ����Ч������� ��time error! ��  �����ꡢ�¡��ա�Сʱ���֡�����Ϊ0��
//������ں�ʱ�䶼��Ч������ݴ��ݵĲ�����ʼ���ꡢ�¡��ա�Сʱ���֡���
{
    year=y;
    month=mo;
    day=d;
    hour=h;
    minute=m;
    second=s;

    int a=0,b=0;
    {
        if(month==2&&day<=28)
        a=1;
        if (year%1000==0&&year%400==0&&month==2&&day==29)
        a=1;//����
        if((mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||month==12)&&day<=31)
        a=1;//����
        if((mo==4||mo==6||mo==9||mo==11)&&day<=30)
        a=1;
    }

    if(hour<24&&minute<60&&second<60)
        b=1;
    if(a==0)
        cout<<"date error!" <<endl;
    if(b==0)
        cout<<"time error!"<<endl;
    if(a==0&&b==0)
        cout<<"date and time error!"<<endl;

    if(a==0||b==0)
    {
        year=0;
        month=0;
        day=0;
        hour=0;
        minute=0;
        second=0;
    }
    cout<<"���캯��������"<<endl;
}
CTime::CTime(CTime &p)
//��������ֵȫ�����ݸ���ǰ����ͬʱ������������캯�������á�
{
     year=p.year;
     month=p.month;
     day=p.day;
     hour=p.hour;
     minute=p.minute;
     second=p.second;
    cout<<"�������캯��������"<<endl;
}
int CTime::isvalid()
{
    if(year&&month&&day)
        torf=1;
    else torf=0;
    return torf;
}
void CTime::showTime()
//������ʾ���ڣ���ʾ��ʽΪ��2020/3/12 11:50:20
{
    cout<<year<<"/"<<month<<"/"<<day<<" "<<hour<<":"<<minute<<":"<<second<<endl;
}
int CTime::dayDiff(CTime t)
{
    int ya=0,ma=0,da=0;
    int d1,d2;
    int yy,dd;
    int i;
    if(year<t.year)
    {
       yy=t.year-year-1;//��t.year��yearΪС
		if(yy)
		{
			for(i=1;i<yy+1;i++)
           {ya=ya+run(year+i);}//��
        for(i=1;i<t.month;i++)//��t.month���·ݵ�����
        {
            ma=ma+yue(i,t.year);
        }
		
        for(i=1;i<=12-month;i++)
        {
			ma=ma+yue(month+i,year);
		 }
	
        d1=yue(month,year)-day;
		
        d2=t.day;
	
        da=d1+d2;
	
        }

        if(!yy)//1999&2000
        {for(i=0;i<yy;i++)
        
            {
                ya=ya+run(year+i);//��
            }
        
        for(i=1;i<=12-month;i++)//12-month=yearʣ���·�
        {
            ma=ma+yue(month+i,year);//����month���·ݵ���year������
        }
        for(i=1;i<t.month;i++)
        {ma=ma+yue(i,t.year);}//����t.month�·���t.year������

        d1=yue(month,year)-day;
        d2=t.day;
        da=d1+d2;
        }
        }
	 if(year>t.year)
        {
            yy=year-t.year-1;//��t.year��yearΪС
		if(yy)
		{for(i=1;i<yy+1;i++)
        
            {
                ya=ya+run(t.year+i);//��
            }
			
        for(i=1;i<month;i++)//��month��year������
        {
            ma=ma+yue(i,year);
        }
        for(i=1;i<=12-t.month;i++)
        {ma=ma+yue(t.month+i,t.year);
		 }//����t.month�·���t.year������
        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
        if(!yy)
        {for(i=0;i<yy;i++)
        {
            {
                ya=ya+run(t.year+i);//��
            }
        }
        for(i=1;i<=12-t.month;i++)//12-month=yearʣ���·�
        {
            ma=ma+yue(t.month+i,t.year);//����month���·ݵ���year������
        }
        for(i=1;i<month;i++)
        {ma=ma+yue(i,year);}//����t.month�·���t.year������

        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
        }
	if(year==t.year)
	{	{
		if(t.month<month)
		for(i=t.month+1;i<month;i++)
        {ma=ma+yue(i,year);}//����month&t.month�·���year������

        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
	
		if(month<t.month)
		{
			for(i=month+1;i<t.month;i++)
			 {
				ma=ma+yue(i,year);
			}//����month&t.month�·���year������

        d1=yue(month,year)-day;
        d2=t.day;
        da=d1+d2;
        }
				
	}
        dd=ya+ma+da;
	
        return dd;
}


int main()
{
    int year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime t2(2000, 1, 1); //����Ĭ���βν�ʱ���ʼ��Ϊ00:00:00
    if (t1.isvalid())     //������ں�ʱ��Ϸ������������
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "������֮�������" << days << "��" << endl;
        days=t2.dayDiff(t1);
        cout << "������֮�������" << days << "��" << endl;
    }
}

