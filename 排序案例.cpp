#include <iostream>
using namespace std;
#include <list>
#include <string>

class Person2 {
public:
	Person2(string name, int age, int height) {
		m_Name = name;
		m_Age = age;
		m_Height = height;
	}
public:
	string m_Name;  //姓名
	int m_Age;      //年龄
	int m_Height;   //身高
};

//排序规则
bool ComparePerson(Person2& p1, Person2& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;//年龄相同，身高降序
	}
	else
	{
		return  p1.m_Age < p2.m_Age;//年龄升序
	}
}

void test63() {
	list<Person2> L;
	Person2 p1("刘备", 35, 175);
	Person2 p2("曹操", 45, 180);
	Person2 p3("孙权", 40, 170);
	Person2 p4("赵云", 25, 190);
	Person2 p5("张飞", 35, 160);
	Person2 p6("关羽", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person2>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}//打印

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //排序，对于自定义数据类型，必须要指定排序规则
	for (list<Person2>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age
			<< " 身高： " << it->m_Height << endl;
	}
}

int main22() {
	test63();
	system("pause");
	return 0;
}