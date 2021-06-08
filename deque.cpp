#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

//输出
void printDeque(const deque<int>& d)//只读 const_iterator
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque构造
void test46() {
	deque<int> d1; //无参构造函数
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end()-3); //构造函数将[beg, end)区间中的元素拷贝给本身。
	printDeque(d2);

	deque<int>d3(10, 100);//构造函数将n个elem拷贝给本身。
	printDeque(d3);

	deque<int>d4 = d3;//拷贝构造函数
	printDeque(d4);
}

//赋值操作
void test47()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2;
	d2 = d1;//重载等号操作符
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());//将[beg, end)区间中的数据拷贝赋值给本身。
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//大小操作
void test48()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//判断容器是否为空
	if (d1.empty()) {
		cout << "d1为空!" << endl;
	}
	else {
		cout << "d1不为空!" << endl;
		//统计大小
		cout << "d1的大小为：" << d1.size() << endl;
	}

	//重新指定大小，以1填充
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

//两端操作
void test49()
{
	deque<int> d;
	//尾插
	d.push_back(10);
	d.push_back(20);
	//头插
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20
	//尾删
	d.pop_back();
	//头删
	d.pop_front();
	printDeque(d);//100 10
}
//插入
void test50()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20

	d.insert(d.begin(), 1000);
	printDeque(d);//1000 200 100 10 20

	d.insert(d.begin(), 2, 10000);//10000 10000 1000 200 100 10 20
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);//1 2 3 10000 10000 1000 200 100 10 20
}
//删除
void test51()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20

	deque<int>::iterator it = d.begin();
	d.erase(++it);
	printDeque(d);//200 10 20

	d.erase(d.begin(), d.end());
	d.clear();//效果同上
	printDeque(d);
}

//数据存取
void test52()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	for (int i = 0; i < d.size(); i++) {//[]访问
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++) {//at访问
		cout << d.at(i) << " ";
	}
	cout << endl;
	cout << "front:" << d.front() << endl;//第一个元素200
	cout << "back:" << d.back() << endl;//最后一个元素20
}

//排序
void test53()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20
	sort(d.begin(), d.end());
	printDeque(d);//10 20 100 200
}

int main17() {
	test46();
	test47();
	test48();
	test49();
	test50();
	test51();
	test52();
	test53();
	system("pause");
	return 0;
}