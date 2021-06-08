#include<iostream>
#include <string>
using namespace std;

//类模板中成员函数类外实现
template<class T1, class T2>
class Person {
public:
	//类模板中成员函数类内声明
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};

//构造函数 类外实现 必须要有函数模板 参数列表
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//成员函数 类外实现 必须要有函数模板 参数列表
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "姓名: " << this->m_Name << " 年龄:" << this->m_Age << endl;
}

void test19()
{
	Person<string, int> p("Tom", 20);
	p.showPerson();
}

int main10() {
	test19();
	system("pause");
	return 0;
}