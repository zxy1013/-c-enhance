#include <iostream>
using namespace std;
#include <deque>
#include <algorithm>

//���
void printDeque(const deque<int>& d)//ֻ�� const_iterator
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//deque����
void test46() {
	deque<int> d1; //�޲ι��캯��
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int> d2(d1.begin(), d1.end()-3); //���캯����[beg, end)�����е�Ԫ�ؿ���������
	printDeque(d2);

	deque<int>d3(10, 100);//���캯����n��elem����������
	printDeque(d3);

	deque<int>d4 = d3;//�������캯��
	printDeque(d4);
}

//��ֵ����
void test47()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	deque<int>d2;
	d2 = d1;//���صȺŲ�����
	printDeque(d2);

	deque<int>d3;
	d3.assign(d1.begin(), d1.end());//��[beg, end)�����е����ݿ�����ֵ������
	printDeque(d3);

	deque<int>d4;
	d4.assign(10, 100);
	printDeque(d4);
}

//��С����
void test48()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
	{
		d1.push_back(i);
	}
	printDeque(d1);

	//�ж������Ƿ�Ϊ��
	if (d1.empty()) {
		cout << "d1Ϊ��!" << endl;
	}
	else {
		cout << "d1��Ϊ��!" << endl;
		//ͳ�ƴ�С
		cout << "d1�Ĵ�СΪ��" << d1.size() << endl;
	}

	//����ָ����С����1���
	d1.resize(15, 1);
	printDeque(d1);

	d1.resize(5);
	printDeque(d1);
}

//���˲���
void test49()
{
	deque<int> d;
	//β��
	d.push_back(10);
	d.push_back(20);
	//ͷ��
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20
	//βɾ
	d.pop_back();
	//ͷɾ
	d.pop_front();
	printDeque(d);//100 10
}
//����
void test50()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20

	d.insert(d.begin(), 1000);
	printDeque(d);//1000 200 100 10 20

	d.insert(d.begin(), 2, 10000);//10000 10000 1000 200 100 10 20
	printDeque(d);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d.insert(d.begin(), d2.begin(), d2.end());
	printDeque(d);//1 2 3 10000 10000 1000 200 100 10 20
}
//ɾ��
void test51()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20

	deque<int>::iterator it = d.begin();
	d.erase(++it);
	printDeque(d);//200 10 20

	d.erase(d.begin(), d.end());
	d.clear();//Ч��ͬ��
	printDeque(d);
}

//���ݴ�ȡ
void test52()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	for (int i = 0; i < d.size(); i++) {//[]����
		cout << d[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < d.size(); i++) {//at����
		cout << d.at(i) << " ";
	}
	cout << endl;
	cout << "front:" << d.front() << endl;//��һ��Ԫ��200
	cout << "back:" << d.back() << endl;//���һ��Ԫ��20
}

//����
void test53()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque(d);//200 100 10 20
	sort(d.begin(), d.end());
	printDeque(d);//10 20 100 200
}

int main17() {
	test46();
	test47();
	test48();
	test49();
	test50();
	test51();
	test52();
	test53();
	system("pause");
	return 0;
}