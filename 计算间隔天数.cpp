 #include <iostream>
 #include <iostream>

using namespace std;

int run(int y)//年
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
//声明一个表示时间的类CTime，可以精确表示年、月、日、小时、分、秒，请计算两个日期对象之间相隔的天数。
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
        cout<<"析构函数被调用"<<endl;
    }
    int dayDiff(CTime t) ;//用于计算当前对象与形参t之间的相隔的天数，注意相隔天数为大于等于0的正整数。注意闰年的问题。
    void showTime();
    int isvalid();//显示日期，显示格式为：2020/3/12 11:50:20
};

CTime::CTime(int y,int mo,int d,int h,int m,int s)
//如果日期无效，则输出 “date error! ”  并将年、月、日、小时、分、秒置为0。
//如果时间无效，则输出 “time error! ”  并将年、月、日、小时、分、秒置为0。
//如果日期和时间都有效，则根据传递的参数初始化年、月、日、小时、分、秒
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
        a=1;//闰年
        if((mo==1||mo==3||mo==5||mo==7||mo==8||mo==10||month==12)&&day<=31)
        a=1;//大月
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
    cout<<"构造函数被调用"<<endl;
}
CTime::CTime(CTime &p)
//将参数的值全部传递给当前对象，同时输出“拷贝构造函数被调用”
{
     year=p.year;
     month=p.month;
     day=p.day;
     hour=p.hour;
     minute=p.minute;
     second=p.second;
    cout<<"拷贝构造函数被调用"<<endl;
}
int CTime::isvalid()
{
    if(year&&month&&day)
        torf=1;
    else torf=0;
    return torf;
}
void CTime::showTime()
//用于显示日期，显示格式为：2020/3/12 11:50:20
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
       yy=t.year-year-1;//年差，t.year大，year为小
		if(yy)
		{
			for(i=1;i<yy+1;i++)
           {ya=ya+run(year+i);}//年
        for(i=1;i<t.month;i++)//除t.month的月份的天数
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
                ya=ya+run(year+i);//年
            }
        
        for(i=1;i<=12-month;i++)//12-month=year剩的月份
        {
            ma=ma+yue(month+i,year);//除掉month的月份的在year的天数
        }
        for(i=1;i<t.month;i++)
        {ma=ma+yue(i,t.year);}//除掉t.month月份在t.year的天数

        d1=yue(month,year)-day;
        d2=t.day;
        da=d1+d2;
        }
        }
	 if(year>t.year)
        {
            yy=year-t.year-1;//年差，t.year大，year为小
		if(yy)
		{for(i=1;i<yy+1;i++)
        
            {
                ya=ya+run(t.year+i);//年
            }
			
        for(i=1;i<month;i++)//除month在year的天数
        {
            ma=ma+yue(i,year);
        }
        for(i=1;i<=12-t.month;i++)
        {ma=ma+yue(t.month+i,t.year);
		 }//除掉t.month月份在t.year的天数
        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
        if(!yy)
        {for(i=0;i<yy;i++)
        {
            {
                ya=ya+run(t.year+i);//年
            }
        }
        for(i=1;i<=12-t.month;i++)//12-month=year剩的月份
        {
            ma=ma+yue(t.month+i,t.year);//除掉month的月份的在year的天数
        }
        for(i=1;i<month;i++)
        {ma=ma+yue(i,year);}//除掉t.month月份在t.year的天数

        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
        }
	if(year==t.year)
	{	{
		if(t.month<month)
		for(i=t.month+1;i<month;i++)
        {ma=ma+yue(i,year);}//除掉month&t.month月份在year的天数

        d1=yue(t.month,t.year)-t.day;
        d2=day;
        da=d1+d2;
        }
	
		if(month<t.month)
		{
			for(i=month+1;i<t.month;i++)
			 {
				ma=ma+yue(i,year);
			}//除掉month&t.month月份在year的天数

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
    CTime t2(2000, 1, 1); //利用默认形参将时间初始化为00:00:00
    if (t1.isvalid())     //如果日期和时间合法，则计算天数
    {
        int days=0;
        days=t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days=t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
}

