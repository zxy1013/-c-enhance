#include<iostream>
#include <string>
using namespace std;

//��ģ���г�Ա��������ʵ��
template<class T1, class T2>
class Person {
public:
	//��ģ���г�Ա������������
	Person(T1 name, T2 age);
	void showPerson();
public:
	T1 m_Name;
	T2 m_Age;
};

//���캯�� ����ʵ�� ����Ҫ�к���ģ�� �����б�
template<class T1, class T2>
Person<T1, T2>::Person(T1 name, T2 age) {
	this->m_Name = name;
	this->m_Age = age;
}

//��Ա���� ����ʵ�� ����Ҫ�к���ģ�� �����б�
template<class T1, class T2>
void Person<T1, T2>::showPerson() {
	cout << "����: " << this->m_Name << " ����:" << this->m_Age << endl;
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