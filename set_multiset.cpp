#include <iostream>
using namespace std;
#include <set>

//打印
void printSet(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

//构造和赋值
void test64()
{
	set<int> s1;
	s1.insert(10);//set容器插入数据时用insert
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);//所有元素都会在插入时自动被排序。升序
	s1.insert(20);//不允许插入重复数据，不报错，但是不能插入
	printSet(s1);
	//拷贝构造
	set<int>s2(s1);
	printSet(s2);
	//赋值
	set<int>s3;
	s3 = s2;
	printSet(s3);
}

//大小
void test65()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	if (s1.empty())
	{
		cout << "s1为空" << endl;
	}
	else
	{
		cout << "s1不为空" << endl;
		cout << "s1的大小为： " << s1.size() << endl;
	}
}
//交换
void test66()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	set<int> s2;
	s2.insert(100);
	s2.insert(300);
	s2.insert(200);
	s2.insert(400);
	cout << "交换前" << endl;
	printSet(s1);
	printSet(s2);
	cout << endl;
	cout << "交换后" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
}

//set插入和删除
void test67()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet(s1);
	//删除
	s1.erase(s1.begin());
	printSet(s1);//20 30 40 
	s1.erase(30);
	printSet(s1);//20 40
	//清空
	s1.erase(s1.begin(), s1.end());
	s1.clear();
	printSet(s1);
}

//查找和统计
void test68()
{
	set<int> s1;
	//插入
	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	//查找
	set<int>::iterator pos = s1.find(30);
	if (pos != s1.end())
	{
		cout << "找到了元素 ： " << *pos << endl;
	}
	else
	{
		cout << "未找到元素" << endl;
	}
	//统计
	int num = s1.count(30);
	cout << "num = " << num << endl;
}

//set和multiset区别
void test69()
{	//set
	set<int> s;
	pair<set<int>::iterator, bool>  ret = s.insert(10);//接收set.insert的返回值
	if (ret.second) {//取bool数据
		cout << "第一次插入成功!" << endl;
	}
	else {
		cout << "第一次插入失败!" << endl;
	}
	ret = s.insert(10);//插入检测，返回值为bool类型
	if (ret.second) {
		cout << "第二次插入成功!" << endl;
	}
	else {
		cout << "第二次插入失败!" << endl;
	}

	//multiset
	multiset<int> ms;//返回值只有迭代器一项
	ms.insert(10);
	ms.insert(10);
	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//对组创建
void test70()
{
	pair<string, int> p(string("Tom"), 20);
	cout << "姓名： " << p.first << " 年龄： " << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry", 10);
	cout << "姓名： " << p2.first << " 年龄： " << p2.second << endl;
}

//set存放内置数据类型
class MyCompare1
{
public:
	bool operator()(int v1, int v2) const{//重载小括号
		return v1 > v2;//降序
	}
};
void test71()
{
	set<int> s1;
	s1.insert(10);
	s1.insert(40);
	s1.insert(20);
	s1.insert(30);
	s1.insert(50);
	//默认从小到大排序
	for (set<int>::iterator it = s1.begin(); it != s1.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	//指定排序规则 插入数据前就要声明,模板有默认值
	set<int,MyCompare1> s2;
	s2.insert(10);
	s2.insert(40);
	s2.insert(20);
	s2.insert(30);
	s2.insert(50);
	for (set<int, MyCompare1>::iterator it = s2.begin(); it != s2.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//set存放自定义数据类型
class Person3
{
public:
	Person3(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};
class comparePerson
{
public:
	bool operator()(const Person3& p1, const Person3& p2)const
	{
		//按照年龄进行降序排序 名字进行降序
		if (p1.m_Age != p2.m_Age){
		return p1.m_Age > p2.m_Age;
		}
		else return p1.m_Name > p2.m_Name;
	}
};
void test72()
{
	set<Person3, comparePerson> s;//自定义类型若不指定排序规则，无法插入数据
	Person3 p1("刘备", 23);
	Person3 p2("关羽", 27);
	Person3 p3("张飞", 25);
	Person3 p4("赵云", 21);
	Person3 p5("张三", 25);
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	s.insert(p5);
	for (set<Person3, comparePerson>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "姓名： " << it->m_Name << " 年龄： " << it->m_Age << endl;
	}
}

int main23() {
	test64();
	test65();
	test66();
	test67();
	test68();
	test69();
	test70();
	test71();
	test72();
	system("pause");
	return 0;
}