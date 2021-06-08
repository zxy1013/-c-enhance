#include<iostream>
using namespace std;
#include <numeric>
#include <vector>
#include <algorithm>

//accumulate
void test108()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++) {
		v.push_back(i);
	}
	int total = accumulate(v.begin(), v.end(), 0);//0 ÆðÊ¼Öµ
	cout << "total = " << total << endl;
}

//fill
class myPrint
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test109()
{
	vector<int> v;
	v.resize(10);
	//Ìî³ä
	fill(v.begin(), v.end(), 100);
	for_each(v.begin(), v.end(), myPrint());
	cout << endl;
}

int main31() {
	test108();
	test109();
	system("pause");
	return 0;
}