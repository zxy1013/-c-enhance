#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//1������������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
class MyAdd
{
public:
	int operator()(int v1, int v2)//���غ������ò���������
	{
		return v1 + v2;
	}
};
void test79()
{
	MyAdd myAdd;//��������
	cout << myAdd(10, 10) << endl;//ʹ�����ص�()ʱ��Ҳ�зº���
}

//2����������������Լ���״̬
class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		count++; //ͳ��ʹ�ô���
	}
	int count; //�ڲ��Լ���״̬
};
void test80()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint���ô���Ϊ�� " << myPrint.count << endl;
}

//3���������������Ϊ��������
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
void test81()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

//1.һԪν��
class GreaterFive {
public:
	bool operator()(int val) const {//����bool���͵ķº�����Ϊν��
		return val > 5;
	}
};
void test82() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//��v.begin()��v.end()֮�� ���ҵ�һ������5�����ݡ�GreaterFive()������������
	if (it == v.end()) {
		cout << "û�ҵ�!" << endl;
	}
	else {
		cout << "�ҵ�:" << *it << endl;//6
	}
}

//2.��Ԫν��
class MyCompare
{
public:
	bool operator()(int num1, int num2) const
	{
		return num1 > num2;
	}
};
void test83()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(40);
	v.push_back(20);
	v.push_back(30);
	v.push_back(50);
	//Ĭ�ϴ�С����
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//ʹ�ú�������ı��㷨���ԣ�����Ӵ�С
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//�����º���
//negate
void test84()
{
	negate<int> n;
	cout << n(50) << endl;//-50
}
//plus
void test85()
{
	plus<int> p;//Ĭ��ͬ���ͣ�����дһ�����ͼ���
	cout << p(10, 20) << endl;
}

//��ϵ�º���
void test86()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(40);
	v.push_back(20);
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//�Լ�ʵ�ַº���
	//sort(v.begin(), v.end(), MyCompare());
	//STL�ڽ��º��� ���ڷº���
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//�߼��º���
void test87()
{
	vector<bool> v;
	v.push_back(true);
	v.push_back(false);
	v.push_back(true);
	v.push_back(false);
	for (vector<bool>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//�߼��� ��v�������˵�v2�У���ִ���߼�������
	vector<bool> v2;
	v2.resize(v.size());//4
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//ԭ��������ʼ��ֹλ�ã�Ŀ����������ʼλ�ã��߼��º���
	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main26() {
	test79();
	test80();
	test81();
	test82();
	test83();
	test84();
	test85();
	test86();
	test87();
	system("pause");
	return 0;
}