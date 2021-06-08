#include<iostream>
#include <string>
using namespace std;
//解决方式2，将声明和实现写到一起，文件后缀名改为.hpp
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