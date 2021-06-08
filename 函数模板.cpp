#include<iostream>
using namespace std;

//交换整型函数
void swapInt(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}
//交换浮点型函数
void swapDouble(double& a, double& b) {
	double temp = a;
	a = b;
	b = temp;
}
//由于数据类型太多了，还有自定义的数据类型，所以需要模板。

//利用模板提供通用的交换函数
template<typename T>//声明一个模板，告诉编译器后面代码的T不要报错，T为一个通用数据类型
void mySwap(T& a, T& b)//函数模板
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

	//利用模板实现交换
	//1、自动类型推导
	//mySwap(a, b);

	//2、或显示指定类型
	mySwap<double>(a, b);
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
}

// 1、自动类型推导，必须推导出一致的数据类型T,才可以使用
void test02()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	mySwap(a, b); // 正确，可以推导出一致的T
	//mySwap(a, c); // 错误，推导不出一致的T类型
}

// 2、模板必须要确定出T的数据类型，才可以使用
template<class T>
void func()//函数模板
{
	cout << "func 调用" << endl;
}
void test03()
{
	//func(); //错误，模板不能独立使用，必须确定出T的类型
	func<int>(); //利用显示指定类型的方式，给T一个类型，才可以使用该模板
}

int main1() {
	test01();
	test02();
	test03();
	system("pause");
	return 0;
}