#include <iostream>
#include <vector>
using namespace std;
class Book
{
//请在此处补充Book类的定义

private:
    unsigned int m_ID;//编号

    string m_Name;//书名

    string m_Introduction;//简介

    string m_Author;//作者

    string m_Date;//日期

    unsigned int m_Page;//页数
public:
    /* b1.SetID(1);
        b1.SetName("C++  语言程序设计(第4版)");
        b1.SetAuthor("郑莉");
        b1.SetIntroduction("介绍C++及面向对象的知识");
        b1.SetDate("201007");
        b1.SetPage(529);*/
    void SetID(int x);//ok
    int GetID();//ok
    void SetName(string name);//ok

    string GetName();//ok
    void SetIntroduction(string Introduction);//ok
    string GetIntroduction();//ok
    void SetAuthor(string author);//ok
    string GetAuthor();//ok
    void SetDate(string date);//ok
    string GetDate();//ok
    void SetPage(int page);//ok
    int GetPage();//ok

    Book();//ok

    virtual ~Book() {} //ok

    Book(const Book& other);//ok

};
//请在此处补充Book类的成员函数实现
void Book::SetID(int x)
{
    m_ID=x;
}//ok
int Book::GetID()
{
    return m_ID;   //ok
}
void Book::SetName(string name)
{
    m_Name=name;
}//ok
string Book::GetName()
{
    return m_Name;
}
void Book::SetIntroduction(string Introduction)
{
    m_Introduction=Introduction;
}
string Book::GetIntroduction()
{
    return m_Introduction;   //ok
}
void Book::SetAuthor(string author)
{
    m_Author=author;
}//ok
string Book::GetAuthor()
{
    return m_Author;   //ok
}
void Book::SetDate(string date)
{
    m_Date=date;
}//ok
string Book::GetDate()
{
    return m_Date;   //ok
}
void Book::SetPage(int page)
{
    m_Page=page;
}//ok
int Book::GetPage()
{
    return m_Page;   //ok
}

Book::Book()//ok
{
    m_ID=0;
}//将m_ID初始化为0，表示这个一个未赋值对象

Book::Book(const Book& other)
{
    m_ID=other.m_ID;
    m_Name=other.m_Name;//书名

    m_Introduction=other.m_Introduction;//简介

    m_Author=other.m_Author;//作者

    m_Date=other.m_Date;//日期

    m_Page=other.m_Page;
};//实现所有成员变量的拷贝

class Store
{
//请在此处补充Store类的定义

private:
    vector<Book>m_Books;//利用vector动态创建的Book数组
public:
    Store();
    Store(int n);
    void in(Book &b);
    void out(string name);
    int GetCount()
    {
        return m_Books.size();
    }
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
    virtual ~Store()
    {
        cout<<"Store destructor called!"<<endl;
    }//将m_Count置为0;判断如果m_pBook不为空指针，释放m_pBook指向空间;并输出"Store destructor called!";
    Store(const Store& other);

};
//请在此处补充Store类的成员函数实现
 Store::Store()
//将m_Books的大小置为n;并输出"Store constructor with (int n) called!";
{

    cout<<"Store default constructor called!"<<endl;
};
Store::Store(int n)
//将m_Books的大小置为n;并输出"Store constructor with (int n) called!";
{
    m_Books.resize(n);
    cout<<"Store constructor with (int n) called!"<<endl;
}
Store::Store(const Store& other)
/* 实现对象数组的拷贝，并输出"Store copy constructor called!";
vector已经解决了深拷贝的问题，这里无需做深拷贝设计*/
{
    m_Books.assign(other.m_Books.begin(),other.m_Books.end());
    cout<<"Store copy constructor called!"<<endl;
}//实现对象数组的深拷贝，并输出"Store copy constructor called!";
void Store::in(Book &b)
/*入库操作的主要功能是在数组中添加一本新书。
   提示：利用vector的成员函数可以直接实现添加元素功能*/
{
    m_Books.resize(m_Books.size()+1,b);
}
void Store::out(string name)
/*  出库操作的主要功能是根据指定的书名，在数组中删除这本书。
  提示：利用vector的成员函数可以直接实现删除元素功能*/
{
    vector<Book>::iterator it=m_Books.begin();
    while(it!=m_Books.end())
    {
        if(it->GetName()==name)
            m_Books.erase(it);
        it++;
    }
}
Book Store::findbyID(int ID)
/*要求根据给定的ID查找图书，
如果找到，则返回一个Book对象，
Book对象中存储了对应书本的信息；
如果找不到，则返回一个Book对象，
Book对象的m_ID为0，表示未被初始化。
vector中的元素遍历可以使用迭代器*/
{
    int i;
    int k=0;
    for(i=0; i<m_Books.size(); i++)
    {
        if(m_Books[i].GetID()==ID)
        {
            k=1;
            return m_Books[i];
            break;
        }
    }
    if(k==0)
        return Book();
}
Book Store::findbyName(string name)
/*要求根据给定的书名查找图书，
如果找到，则返回一个Book对象，
Book对象中存储了对应书本的信息；
如果找不到，则返回一个Book对象
，Book对象的m_ID为0，表示未被初始化。
vector中的元素遍历可以使用迭代器*/
{
    int i;
    int k=0;
    for(i=0; i<m_Books.size(); i++)
    {
        if(m_Books[i].GetName()==name)
        {
            k=1;
            return m_Books[i];
            break;
        }
    }
    if(k==0)
    {
        return Book();
    }
}

void Store::printList()
//设计一个函数打印所有的图书的信息
/*There are totally 2 Books:

ID=1;  Name:C++ 语言程序设计(第4版);  Author:郑莉;  Date:201007;

ID=3;  Name:c程序设计;  Author:谭浩强;  Date:201006;*/
{
    int i;
    cout<<"There are totally "<<m_Books.size()<<" Books:"<<endl;
    for(i=0; i<m_Books.size(); i++)
        cout<<"ID="<<m_Books[i].GetID()<<";"<<"  Name:"<<m_Books[i].GetName()<<";"<<"  Author:"<<m_Books[i].GetAuthor()<<";"<<"  Date:"<<m_Books[i].GetDate()<<";"<<endl;
}

int main()
{
    Store s;
    Book b1,b2,b3;
    b1.SetID(1);
    b1.SetName("C++ 语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout<<"第一本书入库"<<endl;
    s.in(b1);
    cout<<"第二本书入库"<<endl;
    s.in(b2);
    cout<<"第三本书入库"<<endl;
    s.in(b3);
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;
    cout <<"查找并出库图书：离散数学" << endl;
    Book tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
    {
        s.out("离散数学");
        cout <<"离散数学 已成功出库" << endl;
    }
    else
        cout<<"没有找到name为离散数学的书"<<endl;
    cout <<"现有库存书籍数量："<<s.GetCount() << endl;

    cout <<"查找图书 ID：3" << endl;
    tmpbook=s.findbyID(3);
    if(tmpbook.GetID()!=0)
        cout<<"找到ID为"<<3<<"的书，书名："<<tmpbook.GetName()<<endl;
    else
        cout<<"没有找到ID为"<<3<<"的书"<<endl;

    cout <<"查找图书 name：离散数学" << endl;
    tmpbook=s.findbyName("离散数学");
    if(tmpbook.GetID()!=0)
        cout<<"找到name为离散数学的书，ID："<<tmpbook.GetID()<<endl;
    else
        cout<<"没有找到name为离散数学的书"<<endl;

    cout<<"输出所有库存图书的信息"<<endl;
    s.printList();
    cout<<"程序运行结束"<<endl;
    return 0;
}


