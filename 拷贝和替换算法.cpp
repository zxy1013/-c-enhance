#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>

class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
//copy
void test104()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i + 1);
	}
	vector<int> v2;
	v2.resize(v1.size());//提前开辟空间
	copy(v1.begin(), v1.end(), v2.begin());
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

//replace
void test105()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中所有的20替换成 2000
	cout << "替换后：" << endl;
	replace(v.begin(), v.end(), 20, 2000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//replace_if
class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val >= 30;
	}
};
void test106()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);
	cout << "替换前：" << endl;
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
	//将容器中大于等于的30 替换成 3000
	cout << "替换后：" << endl;
	replace_if(v.begin(), v.end(), ReplaceGreater30(), 3000);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

//swap
void test107()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++) {
		v1.push_back(i);
		v2.push_back(i + 100);
	}
	cout << "交换前： " << endl;
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
	cout << "交换后： " << endl;
	swap(v1, v2);
	for_each(v1.begin(), v1.end(), myPrint());
	cout << endl;
	for_each(v2.begin(), v2.end(), myPrint());
	cout << endl;
}

int main30() {
	test104();
	test105();
	test106();
	test107();
	system("pause");
	return 0;
}