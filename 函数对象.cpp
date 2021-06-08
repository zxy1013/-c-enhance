#include<iostream>
using namespace std;
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

//1、函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
class MyAdd
{
public:
	int operator()(int v1, int v2)//重载函数调用操作符的类
	{
		return v1 + v2;
	}
};
void test79()
{
	MyAdd myAdd;//函数对象
	cout << myAdd(10, 10) << endl;//使用重载的()时，也叫仿函数
}

//2、函数对象可以有自己的状态
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
		count++; //统计使用次数
	}
	int count; //内部自己的状态
};
void test80()
{
	MyPrint myPrint;
	myPrint("hello world");
	myPrint("hello world");
	myPrint("hello world");
	cout << "myPrint调用次数为： " << myPrint.count << endl;
}

//3、函数对象可以作为参数传递
void doPrint(MyPrint& mp, string test)
{
	mp(test);
}
void test81()
{
	MyPrint myPrint;
	doPrint(myPrint, "Hello C++");
}

//1.一元谓词
class GreaterFive {
public:
	bool operator()(int val) const {//返回bool类型的仿函数称为谓词
		return val > 5;
	}
};
void test82() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator it = find_if(v.begin(), v.end(), GreaterFive());//在v.begin()和v.end()之间 查找第一个大于5的数据。GreaterFive()匿名函数对象
	if (it == v.end()) {
		cout << "没找到!" << endl;
	}
	else {
		cout << "找到:" << *it << endl;//6
	}
}

//2.二元谓词
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
	//默认从小到大
	sort(v.begin(), v.end());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	//使用函数对象改变算法策略，排序从大到小
	sort(v.begin(), v.end(), MyCompare());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//算术仿函数
//negate
void test84()
{
	negate<int> n;
	cout << n(50) << endl;//-50
}
//plus
void test85()
{
	plus<int> p;//默认同类型，所以写一个类型即可
	cout << p(10, 20) << endl;
}

//关系仿函数
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

	//自己实现仿函数
	//sort(v.begin(), v.end(), MyCompare());
	//STL内建仿函数 大于仿函数
	sort(v.begin(), v.end(), greater<int>());
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//逻辑仿函数
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

	//逻辑非 将v容器搬运到v2中，并执行逻辑非运算
	vector<bool> v2;
	v2.resize(v.size());//4
	transform(v.begin(), v.end(), v2.begin(), logical_not<bool>());//原容器的起始终止位置，目标容器的起始位置，逻辑仿函数
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