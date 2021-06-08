#include<iostream>
#include <string>
using namespace std;

//类模板 多个模板
template<class NameType, class AgeType = int>
//template<class NameType, class AgeType>
class Person
{
public:
	Person(NameType name, AgeType age)
	{
		this->mName = name;
		this->mAge = age;
	}
	void showPerson()
	{
		cout << "name: " << this->mName << " age: " << this->mAge << endl;
	}
public:
	NameType mName;
	AgeType mAge;
};

void test10()
{
	// 指定NameType为string类型，AgeType为int类型
	Person<string, int>P1("孙悟空", 999);
	P1.showPerson();
}

//1、类模板没有自动类型推导的使用方式
void test11()
{
	//Person p("孙悟空", 1000); // 错误，类模板使用时候，不可以用自动类型推导
	Person <string, int>p("孙悟空", 1000); //必须通过显示指定类型的方式使用类模板
	p.showPerson();
}
//2、类模板在模板参数列表中可以有默认参数
void test12()
{
	Person <string> p("猪八戒", 999); //类模板中的模板参数列表 可以指定默认参数class AgeType = int
	p.showPerson();
}

int main6() {
	test10();
	test11();
	test12();
	system("pause");
	return 0;
}