#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void MyPrint(int val)
{
	cout << val << endl;
}
//vector存放内置数据类型
void test25() {
	//创建vector容器对象，并且通过模板参数指定容器中存放的数据的类型 #include <vector>
	vector<int> v;
	//向容器中放数据 尾插push_back
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);

	/*//每一个容器都有自己的迭代器，迭代器是用来遍历容器中的元素
	//v.begin()返回起始迭代器，这个迭代器指向容器中第一个数据
	//v.end()返回结束迭代器，这个迭代器指向容器元素的最后一个元素的下一个位置
	//vector<int>::iterator 拿到vector<int>这种容器的迭代器类型
	vector<int>::iterator pBegin = v.begin();//起始迭代器
	vector<int>::iterator pEnd = v.end();//结束迭代器

	//第一种遍历方式：
	while (pBegin != pEnd) {
		cout << *pBegin << endl;//解引用
		pBegin++;
	}*/

	//第二种遍历方式：
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << endl;
	}

	//第三种遍历方式：
	//使用STL提供标准遍历算法for_each，#include <algorithm>
	for_each(v.begin(), v.end(), MyPrint);//回调，底层使用MyPrint作为Func，v.begin()作为*_UFirst，调用Func(*_UFirst);
}

//自定义数据类型
class Person4 {
public:
	Person4(string name, int age) {
		mName = name;
		mAge = age;
	}
public:
	string mName;
	int mAge;
};
//存放自定义类型对象
void test26() {
	vector<Person4> v;
	//创建数据
	Person4 p1("aaa", 10);
	Person4 p2("bbb", 20);
	Person4 p3("ccc", 30);
	Person4 p4("ddd", 40);
	Person4 p5("eee", 50);
	//添加
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);
	v.push_back(p5);
	//遍历
	for (vector<Person4>::iterator it = v.begin(); it != v.end(); it++) {
		cout << "Name:" << (*it).mName << " Age:" << (*it).mAge << endl;
	}
}

//放对象指针
void test27() {
	vector<Person4*> v;
	//创建数据
	Person4 p1("aaa", 10);
	Person4 p2("bbb", 20);
	Person4 p3("ccc", 30);
	Person4 p4("ddd", 40);
	Person4 p5("eee", 50);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);
	v.push_back(&p5);
	for (vector<Person4*>::iterator it = v.begin(); it != v.end(); it++) {
		Person4* p = (*it);
		cout << "Name:" << p->mName << " Age:" << (*it)->mAge << endl;
	}
}

//容器嵌套容器
void test28() {
	vector<vector<int>>  v;
	//创建小容器
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	vector<int> v4;
	//向小容器中添加数据
	for (int i = 0; i < 4; i++) {
		v1.push_back(i + 1);
		v2.push_back(i + 2);
		v3.push_back(i + 3);
		v4.push_back(i + 4);
	}
	//将小容器元素插入到大容器vector v中
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//通过大容器遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++) {
		for (vector<int>::iterator vit = (*it).begin(); vit != (*it).end(); vit++) {
			cout << *vit << " ";//输出每个小容器的每个数据
		}
		cout << endl;
	}
}

int main14() {
	test25();
	test26();
	test27();
	test28();
	system("pause");
	return 0;
}