#include<iostream>
#include <string>
using namespace std;

//类外实现 - 先做函数模板声明，下方再做函数模板定义，再做友元。或者先函数模板，再友元
template<class T1, class T2> 
class Person1;//提前让编译器知道person类的存在

// 2、全局函数在类外实现
template<class T1, class T2>
void printPerson2(Person1<T1, T2>& p)
{
	cout << "类外实现 ---- 姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
}

template<class T1, class T2>
class Person1
{
	//1、全局函数配合友元  类内实现
	friend void printPerson(Person1<T1, T2>& p)
	{
		cout << "姓名： " << p.m_Name << " 年龄：" << p.m_Age << endl;
	}
	//全局函数配合友元  类外实现
	friend void printPerson2<>(Person1<T1, T2>& p);
public:
	Person1(T1 name, T2 age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
private:
	T1 m_Name;
	T2 m_Age;
};

//1、全局函数在类内实现
void test21()
{
	Person1 <string, int >p("Tom", 20);
	printPerson(p);
}

//2、全局函数在类外实现
void test22()
{
	Person1 <string, int >p("Jerry", 30);
	printPerson2(p);
}

int main12() {
	test21();
	test22();
	system("pause");
	return 0;
}