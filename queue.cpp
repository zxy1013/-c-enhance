#include <iostream>
using namespace std;
#include <queue>
#include <string>

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}
	string m_Name;
	int m_Age;
};

void test55() {
	//创建队列
	queue<Person> q;
	//创建数据
	Person p1("唐僧", 30);
	Person p2("孙悟空", 1000);
	Person p3("猪八戒", 900);
	Person p4("沙僧", 800);
	//向队列中添加元素 入队操作
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	queue<Person> q1= q;//构造
	queue<Person> q2;//赋值
	q2 = q1;//重载等号操作符

	//队列不提供迭代器，更不支持随机访问	
	while (!q.empty()) {
		//输出队头元素
		cout << "队头元素-- 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;
		cout << "队尾元素-- 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;
		cout << endl;
		//删除队头元素
		q.pop();
	}
	cout << "队列q大小为：" << q.size() << endl;//0
	cout << "队列q1大小为：" << q1.size() << endl;//4
	cout << "队列q2大小为：" << q2.size() << endl;//4
}

int main20() {
	test55();
	system("pause");
	return 0;
}