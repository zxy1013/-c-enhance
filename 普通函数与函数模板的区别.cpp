#include<iostream>
using namespace std;

//��ͨ����
int myAdd01(int a, int b)
{
	return a + b;
}

//����ģ��
template<class T>
T myAdd02(T a, T b)
{
	return a + b;
}

//ʹ�ú���ģ��ʱ��������Զ������Ƶ������ᷢ���Զ�����ת��,����ʽ����ת��
void test06()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	cout << myAdd01(a, c) << endl; //��ȷ����char���͵�'c'��ʽת��Ϊint����  'c' ��Ӧ ASCII�� 99

	//myAdd02(a, c); // ����ʹ���Զ������Ƶ�ʱ�����ᷢ����ʽ����ת��
	cout << myAdd02<int>(a, c) << endl; //��ȷ���������ʾָ�����ͣ����Է�����ʽ����ת��
}
int main3() {
	test06();
	system("pause");
	return 0;
}