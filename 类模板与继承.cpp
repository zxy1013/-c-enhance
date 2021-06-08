#include<iostream>
#include <string>
using namespace std;

template<class T>
class Base
{
	T m;
};

//class Son:public Base  //错误，c++编译需要给子类分配内存，必须知道父类中T的类型才可以向下继承
class Son :public Base<int> //必须指定一个类型，因为子类不是模板
{
};
void test17()
{
	Son c;
}
//如果想灵活的制定父类的T类型，子类也可以变为父模板
//类模板继承类模板 ,可以用T2指定父类中的T类型
template<class T1, class T2>
class Son2 :public Base<T2>//T2父类
{
public:
	Son2()//构造函数
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

void test18()
{
	Son2<int, char> child1;
}


int main9() {
	test17();
	test18();
	system("pause");
	return 0;
}