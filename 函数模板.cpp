#include<iostream>
using namespace std;

//�������ͺ���
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//���������ͺ���
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}
//������������̫���ˣ������Զ�����������ͣ�������Ҫģ�塣

//����ģ���ṩͨ�õĽ�������
template<typename T>//����һ��ģ�壬���߱�������������T��Ҫ����TΪһ��ͨ����������
void mySwap(T& a, T& b)//����ģ��
{
	T temp = a;
	a = b;
	b = temp;
}

void test01()
{
	double a = 10.3;
	double b = 20.2;
	//swapInt(a, b);

	//����ģ��ʵ�ֽ���
	//1���Զ������Ƶ�
	//mySwap(a, b);

	//2������ʾָ������
	mySwap<double>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

// 1���Զ������Ƶ��������Ƶ���һ�µ���������T,�ſ���ʹ��
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b); // ��ȷ�������Ƶ���һ�µ�T
	//mySwap(a, c); // �����Ƶ�����һ�µ�T����
}

// 2��ģ�����Ҫȷ����T���������ͣ��ſ���ʹ��
template<class T>
void func()//����ģ��
{
	cout << "func ����" << endl;
}
void test03()
{
	//func(); //����ģ�岻�ܶ���ʹ�ã�����ȷ����T������
	func<int>(); //������ʾָ�����͵ķ�ʽ����Tһ�����ͣ��ſ���ʹ�ø�ģ��
}

int main1() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}