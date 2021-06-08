#include <iostream>
using namespace std;
#include <map>

//打印
void printMap(map<int, int>& m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << " value = " << it->second << endl;
	}
	cout << endl;
}
//构造和赋值
void test73()
{
	map<int, int>m; //默认构造
	m.insert(pair<int, int>(1, 10));//map中所有元素都是成对出现，插入数据时候要使用对组
	m.insert(pair<int, int>(4, 20));
	m.insert(pair<int, int>(3, 30));//由key升序排序
	printMap(m);
	map<int, int>m2(m); //拷贝构造
	printMap(m2);

	map<int, int>m3;
	m3 = m2; //赋值
	printMap(m3);
}

//大小
void test74()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	if (m.empty())
	{
		cout << "m为空" << endl;
	}
	else
	{
		cout << "m不为空" << endl;
		cout << "m的大小为： " << m.size() << endl;
	}
}
//交换
void test75()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));
	cout << "交换前" << endl;
	printMap(m);
	printMap(m2);
	cout << "交换后" << endl;
	m.swap(m2);
	printMap(m);
	printMap(m2);
}

//插入和删除
void test76()
{
	//插入
	map<int, int> m;
	//第一种插入方式
	m.insert(pair<int, int>(1, 10));
	//第二种插入方式
	m.insert(make_pair(2, 20));
	//第三种插入方式 麻烦 map下的值类型
	m.insert(map<int, int>::value_type(3, 30));
	//第四种插入方式
	m[4] = 40;
	cout << m[5] << endl;//如果没有m[5]，编译器会自动创建一个对组，值为(5,0)
	//所以不用其做插入，而是用键访问值
	printMap(m);

	//删除
	m.erase(m.begin());
	printMap(m);
	m.erase(3);
	printMap(m);
	//清空
	m.erase(m.begin(), m.end());
	m.clear();
	printMap(m);
}

//查找和统计
void test77()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));
	//查找
	map<int, int>::iterator pos = m.find(3);
	if (pos != m.end())
	{
		cout << "找到了元素 key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	//统计
	int num = m.count(3);
	cout << "num = " << num << endl;
}

//map容器排序
class MyCompare {
public:
	bool operator()(int v1, int v2) const{
		return v1 > v2;//key降序
	}
};
void test78()
{
	//默认从小到大排序
	//利用仿函数实现从大到小排序 同set，插入之前指定规则
	map<int, int, MyCompare> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	for (map<int, int, MyCompare>::iterator it = m.begin(); it != m.end(); it++) {
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

int main24() {
	test73();
	test74();
	test75();
	test76();
	test77();
	test78();
	system("pause");
	return 0;
}