#include<iostream>
using namespace std;

//void myPrint(int a, int b);
void myPrint(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}

template<typename T>
void myPrint(T a, T b)//��������
{
	cout << "���õĺ���ģ��" << endl;
}

template<typename T>//����ģ��Ҳ���Է�������
void myPrint(T a, T b, T c)
{
	cout << "�������صĺ���ģ��" << endl;
}

void test07()
{
	//1���������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
	// ע�� ������߱���������ͨ�������еģ���ֻ������û��ʵ�֣����߲��ڵ�ǰ�ļ���ʵ�֣��ͻᱨ���Ҳ���
	int a = 10;
	int b = 20;
	myPrint(a, b); //������ͨ����

	//2������ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
	myPrint<>(a, b); //���õ�ģ��

	//3������ģ��Ҳ���Է�������
	int c = 30;
	myPrint(a, b, c); //�������صĺ���ģ��

	//4���������ģ����Բ������õ�ƥ��,���ȵ��ú���ģ�� 
	//��ͨ�������ԣ���Ϊ���Է�����ʽ����ת�������Ǻ���ģ�����
	char c1 = 'a';
	char c2 = 'b';
	myPrint(c1, c2); //���ú���ģ��
}

int main4() {
	test07();
	system("pause");
	return 0;
}