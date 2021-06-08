#include <iostream>
using namespace std;
#include <stack>

//栈容器常用接口
void test54()
{
	//创建栈容器 栈容器必须符合先进后出
	stack<int> s;
	//向栈中添加元素，叫做 压栈 入栈
	s.push(10);
	s.push(20);
	s.push(30);
	stack<int> s1 = s;//构造
	
	stack<int> s2;//赋值
	s2 = s1;//重载等号操作符

	while (!s.empty()) {
		//输出栈顶元素
		cout << "栈顶元素为： " << s.top() << endl;
		//删除栈顶元素 出栈
		s.pop();
	}
	cout << "栈s的大小为：" << s.size() << endl;//0
	cout << "栈s1的大小为：" << s1.size() << endl;//3
	cout << "栈s2的大小为：" << s2.size() << endl;//3
}

int main19() {
	test54();
	system("pause");
	return 0;
}