#include <iostream>
using namespace std;
#include <set>

//��ӡ
void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//����͸�ֵ
void test64()
{
	set<int> s1;
	s1.insert(10);//set������������ʱ��insert
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);//����Ԫ�ض����ڲ���ʱ�Զ�����������
	s1.insert(20);//����������ظ����ݣ����������ǲ��ܲ���
	printSet(s1);
	//��������
	set<int>s2(s1);
	printSet(s2);
	//��ֵ
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//��С
void test65()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	if (s1.empty())
	{
		cout << "s1Ϊ��" << endl;
	}
	else
	{
		cout << "s1��Ϊ��" << endl;
		cout << "s1�Ĵ�СΪ�� " << s1.size() << endl;
	}
}
//����
void test66()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "����ǰ" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;
	cout << "������" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

//set�����ɾ��
void test67()
{
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	//ɾ��
	s1.erase(s1.begin());
	printSet(s1);//20 30 40 
	s1.erase(30);
	printSet(s1);//20 40
	//���
	s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

//���Һ�ͳ��
void test68()
{
	set<int> s1;
	//����
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//����
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "�ҵ���Ԫ�� �� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}
	//ͳ��
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

//set��multiset����
void test69()
{	//set
	set<int> s;
	pair<set<int>::iterator, bool>  ret = s.insert(10);//����set.insert�ķ���ֵ
	if (ret.second) {//ȡbool����
		cout << "��һ�β���ɹ�!" << endl;
	}
	else {
		cout << "��һ�β���ʧ��!" << endl;
	}
	ret = s.insert(10);//�����⣬����ֵΪbool����
	if (ret.second) {
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else {
		cout << "�ڶ��β���ʧ��!" << endl;
	}

	//multiset
	multiset<int> ms;//����ֵֻ�е�����һ��
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//���鴴��
void test70()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "������ " << p.first << " ���䣺 " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "������ " << p2.first << " ���䣺 " << p2.second << endl;
}

//set���������������
class MyCompare1
{
public:
	bool operator()(int v1, int v2) const{//����С����
		return v1 > v2;//����
	}
};
void test71()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	//Ĭ�ϴ�С��������
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//ָ��������� ��������ǰ��Ҫ����,ģ����Ĭ��ֵ
	set<int,MyCompare1> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);
	for (set<int, MyCompare1>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//set����Զ�����������
class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson
{
public:
	bool operator()(const Person3& p1, const Person3& p2)const
	{
		//����������н������� ���ֽ��н���
		if (p1.m_Age != p2.m_Age){
		return p1.m_Age > p2.m_Age;
		}
		else return p1.m_Name > p2.m_Name;
	}
};
void test72()
{
	set<Person3, comparePerson> s;//�Զ�����������ָ����������޷���������
	Person3 p1("����", 23);
	Person3 p2("����", 27);
	Person3 p3("�ŷ�", 25);
	Person3 p4("����", 21);
	Person3 p5("����", 25);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	for (set<Person3, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->m_Name << " ���䣺 " << it->m_Age << endl;
	}
}

int main23() {
	test64();
	test65();
	test66();
	test67();
	test68();
	test69();
	test70();
	test71();
	test72();
	system("pause");
	return 0;
}