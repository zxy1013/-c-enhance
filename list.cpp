#include <iostream>
using namespace std;
#include <list>

//打印数据
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//list构造函数
void test56()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);//10 20 30 40

	list<int>L2(L1.begin(), L1.end());//区间方式构造
	printList(L2);//10 20 30 40

	list<int>L3(L2);//拷贝构造
	printList(L3);//10 20 30 40

	list<int>L4(10, 1000);
	printList(L4);//1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
}

// list赋值和交换
//赋值
void test57()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	//赋值
	list<int>L2;
	L2 = L1;//重载等号操作符
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);
}
//交换
void test58()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);
	cout << "交换前： " << endl;
	printList(L1);
	printList(L2);
	cout << endl;

	L1.swap(L2);
	cout << "交换后： " << endl;
	printList(L1);
	printList(L2);
}

//大小操作
void test59()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if (L1.empty())
	{
		cout << "L1为空" << endl;
	}
	else
	{
		cout << "L1不为空" << endl;
		cout << "L1的大小为： " << L1.size() << endl;
	}
	//重新指定大小
	L1.resize(10);//10 20 30 40 0 0 0 0 0 0
	printList(L1);
	L1.resize(2);
	printList(L1);
}

//插入和删除
void test60()
{
	list<int> L;
	//尾插
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//头插
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);//300 200 100 10 20 30 
	//尾删
	L.pop_back();
	printList(L);//300 200 100 10 20
	//头删
	L.pop_front();
	printList(L);
	//插入
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);//200 1000 100 10 20
	//删除
	it = L.begin();
	L.erase(++it);
	printList(L);
	//移除
	L.push_back(10000);//尾插
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);//删除容器中所有与10000匹配的元素。
	printList(L);
	//清空
	L.clear();
	printList(L);
}

//list数据存取
void test61()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//cout << L1.at(0) << endl;//错误 不支持at访问数据
	//cout << L1[0] << endl; //错误 不支持[]方式访问数据
	cout << "第一个元素为： " << L1.front() << endl;//10
	cout << "最后一个元素为： " << L1.back() << endl;//40
	//由于list本质为链表，不是连续的线性空间存储数据
	//list容器的迭代器是双向迭代器，不支持随机访问。
	list<int>::iterator it = L1.begin();
	it ++; //支持双向it --;
	//it = it + 1;//错误，不可以跳跃访问，即使是+1
}

//排序规则
bool myCompare(int val1 , int val2)
{	//降序 让第一个数大于第二个数
	return val1 > val2;
}

//反转和排序
void test62()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);
	//反转容器的元素
	L.reverse();
	printList(L);
	//排序 所有不支持随机访问迭代器的容器，不可以用标准算法 sort(d.begin(), d.end());
	L.sort(); //默认的排序规则 从小到大
	printList(L);
	L.sort(myCompare); //指定规则，从大到小
	printList(L);
}

int main21() {
	test56();
	test57();
	test58();
	test59();
	test60();
	test61();
	test62();
	system("pause");
	return 0;
}