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

//����������������
void test23()
{
	MyArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.Push_back(i);
	}
	cout << "array1��ӡ�����" << endl;
	printIntArray(array1);
	cout << "array1�Ĵ�С��" << array1.getSize() << endl;
	cout << "array1��������" << array1.getCapacity() << endl;
	cout << "--------------------------" << endl;

	MyArray<int> array2(array1);
	array2.Pop_back();
	array2.Push_back(3);
	cout << "array2βɾ���ӡ�����" << endl;
	printIntArray(array2);
}

//�����Զ�����������
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
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}
}

void test24()
{
	//��������
	MyArray<Person3> pArray(10);
	Person3 p1("�����", 30);
	Person3 p2("����", 20);
	Person3 p3("槼�", 18);
	Person3 p4("���Ѿ�", 15);
	Person3 p5("����", 24);
	//��������
	pArray.Push_back(p1);
	pArray.Push_back(p2);
	pArray.Push_back(p3);
	pArray.Push_back(p4);
	pArray.Push_back(p5);
	//��ӡ
	cout << "--------------------------" << endl;
	printPersonArray(pArray);
	cout << "pArray�Ĵ�С��" << pArray.getSize() << endl;
	cout << "pArray��������" << pArray.getCapacity() << endl;
}
int main13() {
	test23();
	test24();
	system("pause");
	return 0;
}