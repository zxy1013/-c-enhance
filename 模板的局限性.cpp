#include<iostream>
#include <string>
using namespace std;

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
//��ͨ����ģ��
template<class T>
bool myCompare(T& a, T& b)
{
	if (a == b)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//��ʾ���廯��ԭ�� ��template<>��ͷ����ͨ��������ָ������
//���廯�����ڳ���ģ��
template<> bool myCompare(Person& p1, Person& p2)
{
	if (p1.m_Name == p2.m_Name && p1.m_Age == p2.m_Age)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void test08()
{
	int a = 10;
	int b = 20;
	//�����������Ϳ���ֱ��ʹ��ͨ�õĺ���ģ��
	bool ret = myCompare(a, b);
	if (ret)
	{
		cout << "a == b " << endl;
	}
	else
	{
		cout << "a != b " << endl;
	}
}
void test09()
{
	Person p1("Tom", 10);
	Person p2("Tom", 10);
	//�Զ����������ͣ����������ͨ�ĺ���ģ��
	//���Դ������廯��Person�������͵�ģ�壬�������⴦���������
	bool ret = myCompare(p1, p2);
	if (ret)
	{
		cout << "p1 == p2 " << endl;
	}
	else
	{
		cout << "p1 != p2 " << endl;
	}
}
int main5() {
	test08();
	test09();
	system("pause");
	return 0;
}