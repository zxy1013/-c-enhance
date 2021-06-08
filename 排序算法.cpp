#include<iostream>
using namespace std;
#include <algorithm>
#include <vector>
#include <ctime>

void myPrint(int val)
{
	cout << val << " ";
}
//sort
void test100() {
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	//sortĬ�ϴ�С��������
	sort(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint);//��ӡ���
	cout << endl;
	//�Ӵ�С����
	sort(v.begin(), v.end(), greater<int>());//���ú�������
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

//random_shuffle
class myPrint1
{
public:
	void operator()(int val)
	{
		cout << val << " ";
	}
};
void test101()
{
	srand((unsigned int)time(NULL));//�������
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(), v.end(), myPrint1());
	cout << endl;
	//����˳��
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint1());
	cout << endl;
}

//merge
void test102()
{
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 1);
	}
	vector<int> vtarget;
	vtarget.resize(v1.size() + v2.size());//Ŀ��������Ҫ��ǰ���ٿռ�
	//�ϲ� ��Ҫ������������
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vtarget.begin());
	for_each(vtarget.begin(), vtarget.end(), myPrint1());//0 1 1 2 2 3 3 4 4 5 5 6 6 7 7 8 8 9 9 10
	cout << endl;
}

//reverse
void test103()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);
	cout << "��תǰ�� " << endl;
	for_each(v.begin(), v.end(), myPrint1());
	cout << endl;
	cout << "��ת�� " << endl;
	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), myPrint1());
	cout << endl;
}

int main29() {
	test100();
	test101();
	test102();
	test103();
	system("pause");
	return 0;
}