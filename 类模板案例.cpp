#pragma once
#include <iostream>
#include "myArray.hpp"
#include <string>
using namespace std;

void printIntArray(MyArray<int>& arr) {
	for (int i = 0; i < arr.getSize(); i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

//测试内置数据类型
void test23()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;
	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_back();
	array2.Push_back(3);
	cout << "array2尾删后打印输出：" << endl;
	printIntArray(array2);
}

//测试自定义数据类型
class Person3 {
public:
	Person3() {}
	Person3(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};
void printPersonArray(MyArray<Person3>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) {
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}
}

void test24()
{
	//创建数组
	MyArray<Person3> pArray(10);
	Person3 p1("孙悟空", 30);
	Person3 p2("韩信", 20);
	Person3 p3("妲己", 18);
	Person3 p4("王昭君", 15);
	Person3 p5("赵云", 24);
	//插入数据
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);
	//打印
	cout << "--------------------------" << endl;
	printPersonArray(pArray);
	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;
}
int main13() {
	test23();
	test24();
	system("pause");
	return 0;
}