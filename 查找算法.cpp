#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <string>

//find ������������
void test90() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	//�����������Ƿ��� 5 ���Ԫ��
	vector<int>::iterator it = find(v.begin(), v.end(), 5);
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�:" << *it << endl;
	}
}
//�Զ�����������
class Person {
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	//���� ==
	bool operator==(const Person& p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}

public:
	string m_Name;
	int m_Age;
};
void test91() {
	vector<Person> v;
	//��������
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person>::iterator it = find(v.begin(), v.end(), p2);//��Ҫ����== �ñ�����֪����ζԱ�person����
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->m_Name << " ����: " << it->m_Age << endl;
	}
}

//find_if
//������������
class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};
void test92() {
	vector<int> v;
	for (int i = 0; i < 10; i++) {
		v.push_back(i + 1);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());
	if (it == v.end()) {
		cout << "û���ҵ�!" << endl;
	}
	else {
		cout << "�ҵ�����5������:" << *it << endl;
	}
}
//�Զ�����������
class Person1 {
public:
	Person1(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};
class Greater20
{
public:
	bool operator()(Person1& p)
	{
		return p.m_Age > 20;
	}
};
void test93() {
	vector<Person1> v;
	//��������
	Person1 p1("aaa", 10);
	Person1 p2("bbb", 20);
	Person1 p3("ccc", 30);
	Person1 p4("ddd", 40);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	vector<Person1>::iterator it = find_if(v.begin(), v.end(), Greater20());
	if (it == v.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << it->m_Name << " ����: " << it->m_Age << endl;//"ccc", 30
	}
}

//adjacent_find
void test94()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);
	//���������ظ�Ԫ��
	vector<int>::iterator it = adjacent_find(v.begin(), v.end());
	if (it == v.end()) {
		cout << "�Ҳ���!" << endl;
	}
	else {
		cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;//4
	}
}

//binary_search
void test95()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//���ֲ���
	bool ret = binary_search(v.begin(), v.end(), 2);
	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

//count
//������������
void test96()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count(v.begin(), v.end(), 4);
	cout << "4�ĸ���Ϊ�� " << num << endl;
}
//�Զ�����������
void test97()
{
	vector<Person> v;
	Person p1("����", 35);
	Person p2("����", 35);
	Person p3("�ŷ�", 35);
	Person p4("����", 30);
	Person p5("�ܲ�", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	Person p("�����", 35);
	int num = count(v.begin(), v.end(), p);//����==
	cout << "num = " << num << endl;
}

//count_if
class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};
//������������
void test98()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(4);
	v.push_back(5);
	v.push_back(3);
	v.push_back(4);
	v.push_back(4);
	int num = count_if(v.begin(), v.end(), Greater4());
	cout << "����4�ĸ���Ϊ�� " << num << endl;//4
}
//�Զ�����������
class AgeLess35
{
public:
	bool operator()(const Person1& p)
	{
		return p.m_Age < 35;
	}
};
void test99()
{
	vector<Person1> v;
	Person1 p1("����", 35);
	Person1 p2("����", 35);
	Person1 p3("�ŷ�", 35);
	Person1 p4("����", 30);
	Person1 p5("�ܲ�", 25);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	int num = count_if(v.begin(), v.end(), AgeLess35());
	cout << "С��35��ĸ�����" << num << endl;//2
}

int main28() {
	test90();
	test91();
	test92();
	test93();
	test94();
	test95();
	test96();
	test97();
	test98();
	test99();
	system("pause");
	return 0;
}