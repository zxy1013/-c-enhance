#include<iostream>
#include <string>
using namespace std;

//����ʵ�� - ��������ģ���������·���������ģ�嶨�壬������Ԫ�������Ⱥ���ģ�壬����Ԫ
template<class T1, class T2> 
class Person1;//��ǰ�ñ�����֪��person��Ĵ���

// 2��ȫ�ֺ���������ʵ��
template<class T1, class T2>
void printPerson2(Person1<T1, T2>& p)
{
	cout << "����ʵ�� ---- ������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
}

template<class T1, class T2>
class Person1
{
	//1��ȫ�ֺ��������Ԫ  ����ʵ��
	friend void printPerson(Person1<T1, T2>& p)
	{
		cout << "������ " << p.m_Name << " ���䣺" << p.m_Age << endl;
	}
	//ȫ�ֺ��������Ԫ  ����ʵ��
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

//1��ȫ�ֺ���������ʵ��
void test21()
{
	Person1 <string, int >p("Tom", 20);
	printPerson(p);
}

//2��ȫ�ֺ���������ʵ��
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