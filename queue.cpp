#include <iostream>
using namespace std;
#include <queue>
#include <string>

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

void test55() {
	//��������
	queue<Person> q;
	//��������
	Person p1("��ɮ", 30);
	Person p2("�����", 1000);
	Person p3("��˽�", 900);
	Person p4("ɳɮ", 800);
	//����������Ԫ�� ��Ӳ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	queue<Person> q1= q;//����
	queue<Person> q2;//��ֵ
	q2 = q1;//���صȺŲ�����

	//���в��ṩ������������֧���������	
	while (!q.empty()) {
		//�����ͷԪ��
		cout << "��ͷԪ��-- ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;
		cout << "��βԪ��-- ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;
		cout << endl;
		//ɾ����ͷԪ��
		q.pop();
	}
	cout << "����q��СΪ��" << q.size() << endl;//0
	cout << "����q1��СΪ��" << q1.size() << endl;//4
	cout << "����q2��СΪ��" << q2.size() << endl;//4
}

int main20() {
	test55();
	system("pause");
	return 0;
}