#include <iostream>
using namespace std;
#include <vector>

//输出数据
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//vector构造函数
void test38()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end()-1);//将v1[begin(), end())区间中的元素拷贝给v2。
	printVector(v2);

	vector<int> v3(10, 100); //构造函数将10个100拷贝给v3。
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

//赋值操作
void test39()
{
	vector<int> v1; //无参构造
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;//重载等号操作符
	v2 = v1;
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end()-5); //将[beg, end)区间中的数据拷贝赋值给本身。
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100);//将n个elem拷贝赋值给本身。
	printVector(v4);
}

//vector容量和大小
void test40()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1为空" << endl;
	}
	else
	{
		cout << "v1不为空" << endl;
		cout << "v1的容量 = " << v1.capacity() << endl;
		cout << "v1的大小 = " << v1.size() << endl;
	}

	//resize重新指定大小 ，若指定的更大，用10填充新位置
	v1.resize(15, 10);
	printVector(v1);

	//resize重新指定大小 ，若指定的更小，超出部分元素被删除
	v1.resize(5);
	printVector(v1);
}

//插入和删除
void test41()
{
	vector<int> v1;
	//尾插
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//尾删
	v1.pop_back();
	printVector(v1);
	//插入
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//删除
	v1.erase(v1.begin());
	printVector(v1);
	//清空
	v1.erase(v1.begin(), v1.end());
	v1.clear();//类似
	printVector(v1);
}

//vector数据存取
void test42()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)//输出[]访问
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)//输出at访问
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	cout << "v1的第一个元素为： " << v1.front() << endl;
	cout << "v1的最后一个元素为： " << v1.back() << endl;
}

//vector互换容器
void test43()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	//互换容器
	cout << "互换后" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//达到实用的收缩内存效果
void test44()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v的容量为：" << v.capacity() << endl;//138255
	cout << "v的大小为：" << v.size() << endl;//100000
	v.resize(3);
	cout << "v的容量为：" << v.capacity() << endl;//138255
	cout << "v的大小为：" << v.size() << endl;//3

	//swap收缩内存
	vector<int>(v).swap(v); //匿名对象 拷贝构造vector<int>(v) 匿名对象系统自动回收空间
	cout << "v的容量为：" << v.capacity() << endl;//3
	cout << "v的大小为：" << v.size() << endl;//3
}

//预留空间
void test45()
{
	vector<int> v;
	//预留空间100000
	//v.reserve(100000);
	int num = 0;//如果不预留空间，开辟地址次数
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {//p指向首地址
			p = &v[0];
			num++;
		}
	}
	cout << "num:" << num << endl;//预留空间开辟地址次数为1，不预留开辟地址次数为30
}

int main16() {
	test38();
	test39();
	test40();
	test41();
	test42();
	test43();
	test44();
	test45();
	system("pause");
	return 0;
}