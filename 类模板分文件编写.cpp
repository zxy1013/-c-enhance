#include<iostream>
#include <string>
using namespace std;
//�����ʽ2����������ʵ��д��һ���ļ���׺����Ϊ.hpp
#include "person.hpp"

void test20()
{
	Person<string, int> p("Tom", 10);
	p.showPerson();
}

int main11() {
	test20();
	system("pause");
	return 0;
}