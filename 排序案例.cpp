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
	string m_Name;  //����
	int m_Age;      //����
	int m_Height;   //���
};

//�������
bool ComparePerson(Person2& p1, Person2& p2) {
	if (p1.m_Age == p2.m_Age) {
		return p1.m_Height > p2.m_Height;//������ͬ����߽���
	}
	else
	{
		return  p1.m_Age < p2.m_Age;//��������
	}
}

void test63() {
	list<Person2> L;
	Person2 p1("����", 35, 175);
	Person2 p2("�ܲ�", 45, 180);
	Person2 p3("��Ȩ", 40, 170);
	Person2 p4("����", 25, 190);
	Person2 p5("�ŷ�", 35, 160);
	Person2 p6("����", 35, 200);
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<Person2>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}//��ӡ

	cout << "---------------------------------" << endl;
	L.sort(ComparePerson); //���򣬶����Զ����������ͣ�����Ҫָ���������
	for (list<Person2>::iterator it = L.begin(); it != L.end(); it++) {
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age
			<< " ��ߣ� " << it->m_Height << endl;
	}
}

int main22() {
	test63();
	system("pause");
	return 0;
}