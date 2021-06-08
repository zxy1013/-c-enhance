#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void MyPrint(int val)
{
	cout << val << endl;
}
//vector���������������
void test25() {
	//����vector�������󣬲���ͨ��ģ�����ָ�������д�ŵ����ݵ����� #include <vector>
	vector<int> v;
	//�������з����� β��push_back
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	/*//ÿһ�����������Լ��ĵ����������������������������е�Ԫ��
	//v.begin()������ʼ�����������������ָ�������е�һ������
	//v.end()���ؽ��������������������ָ������Ԫ�ص����һ��Ԫ�ص���һ��λ��
	//vector<int>::iterator �õ�vector<int>���������ĵ���������
	vector<int>::iterator pBegin = v.begin();//��ʼ������
	vector<int>::iterator pEnd = v.end();//����������

	//��һ�ֱ�����ʽ��
	while (pBegin != pEnd) {
		cout << *pBegin << endl;//������
		pBegin++;
	}*/

	//�ڶ��ֱ�����ʽ��
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//�����ֱ�����ʽ��
	//ʹ��STL�ṩ��׼�����㷨for_each��#include <algorithm>
	for_each(v.begin(), v.end(), MyPrint);//�ص����ײ�ʹ��MyPrint��ΪFunc��v.begin()��Ϊ*_UFirst������Func(*_UFirst);
}

//�Զ�����������
class Person4 {
public:
	Person4(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//����Զ������Ͷ���
void test26() {
	vector<Person4> v;
	//��������
	Person4 p1("aaa", 10);
	Person4 p2("bbb", 20);
	Person4 p3("ccc", 30);
	Person4 p4("ddd", 40);
	Person4 p5("eee", 50);
	//���
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//����
	for (vector<Person4>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;
	}
}

//�Ŷ���ָ��
void test27() {
	vector<Person4*> v;
	//��������
	Person4 p1("aaa", 10);
	Person4 p2("bbb", 20);
	Person4 p3("ccc", 30);
	Person4 p4("ddd", 40);
	Person4 p5("eee", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person4*>::iterator it = v.begin(); it != v.end(); it++) {
		Person4* p = (*it);
		cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
	}
}

//����Ƕ������
void test28() {
	vector<vector<int>>  v;
	//����С����
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	//��С�������������
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//��С����Ԫ�ز��뵽������vector v��
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//ͨ��������������������
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";//���ÿ��С������ÿ������
		}
		cout << endl;
	}
}

int main14() {
	test25();
	test26();
	test27();
	test28();
	system("pause");
	return 0;
}