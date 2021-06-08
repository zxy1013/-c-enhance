#include<iostream>
#include <string>
using namespace std;

//��ģ�� ���ģ��
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
	// ָ��NameTypeΪstring���ͣ�AgeTypeΪint����
	Person<string, int>P1("�����", 999);
	P1.showPerson();
}

//1����ģ��û���Զ������Ƶ���ʹ�÷�ʽ
void test11()
{
	//Person p("�����", 1000); // ������ģ��ʹ��ʱ�򣬲��������Զ������Ƶ�
	Person <string, int>p("�����", 1000); //����ͨ����ʾָ�����͵ķ�ʽʹ����ģ��
	p.showPerson();
}
//2����ģ����ģ������б��п�����Ĭ�ϲ���
void test12()
{
	Person <string> p("��˽�", 999); //��ģ���е�ģ������б� ����ָ��Ĭ�ϲ���class AgeType = int
	p.showPerson();
}

int main6() {
	test10();
	test11();
	test12();
	system("pause");
	return 0;
}