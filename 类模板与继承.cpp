#include<iostream>
#include <string>
using namespace std;

template<class T>
class Base
{
	T m;
};

//class Son:public Base  //����c++������Ҫ����������ڴ棬����֪��������T�����Ͳſ������¼̳�
class Son :public Base<int> //����ָ��һ�����ͣ���Ϊ���಻��ģ��
{
};
void test17()
{
	Son c;
}
//����������ƶ������T���ͣ�����Ҳ���Ա�Ϊ��ģ��
//��ģ��̳���ģ�� ,������T2ָ�������е�T����
template<class T1, class T2>
class Son2 :public Base<T2>//T2����
{
public:
	Son2()//���캯��
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

void test18()
{
	Son2<int, char> child1;
}


int main9() {
	test17();
	test18();
	system("pause");
	return 0;
}