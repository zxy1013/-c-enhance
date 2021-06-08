#include <iostream>
using namespace std;
#include <vector>

//�������
void printVector(vector<int>& v) {
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}
//vector���캯��
void test38()
{
	vector<int> v1; //�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int> v2(v1.begin(), v1.end()-1);//��v1[begin(), end())�����е�Ԫ�ؿ�����v2��
	printVector(v2);

	vector<int> v3(10, 100); //���캯����10��100������v3��
	printVector(v3);

	vector<int> v4(v3);
	printVector(v4);
}

//��ֵ����
void test39()
{
	vector<int> v1; //�޲ι���
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;//���صȺŲ�����
	v2 = v1;
	printVector(v2);

	vector<int>v3;
	v3.assign(v1.begin(), v1.end()-5); //��[beg, end)�����е����ݿ�����ֵ������
	printVector(v3);

	vector<int>v4;
	v4.assign(10, 100);//��n��elem������ֵ������
	printVector(v4);
}

//vector�����ʹ�С
void test40()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	if (v1.empty())
	{
		cout << "v1Ϊ��" << endl;
	}
	else
	{
		cout << "v1��Ϊ��" << endl;
		cout << "v1������ = " << v1.capacity() << endl;
		cout << "v1�Ĵ�С = " << v1.size() << endl;
	}

	//resize����ָ����С ����ָ���ĸ�����10�����λ��
	v1.resize(15, 10);
	printVector(v1);

	//resize����ָ����С ����ָ���ĸ�С����������Ԫ�ر�ɾ��
	v1.resize(5);
	printVector(v1);
}

//�����ɾ��
void test41()
{
	vector<int> v1;
	//β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector(v1);
	//βɾ
	v1.pop_back();
	printVector(v1);
	//����
	v1.insert(v1.begin(), 100);
	printVector(v1);
	v1.insert(v1.begin(), 2, 1000);
	printVector(v1);
	//ɾ��
	v1.erase(v1.begin());
	printVector(v1);
	//���
	v1.erase(v1.begin(), v1.end());
	v1.clear();//����
	printVector(v1);
}

//vector���ݴ�ȡ
void test42()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	for (int i = 0; i < v1.size(); i++)//���[]����
	{
		cout << v1[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < v1.size(); i++)//���at����
	{
		cout << v1.at(i) << " ";
	}
	cout << endl;
	cout << "v1�ĵ�һ��Ԫ��Ϊ�� " << v1.front() << endl;
	cout << "v1�����һ��Ԫ��Ϊ�� " << v1.back() << endl;
}

//vector��������
void test43()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector(v2);

	//��������
	cout << "������" << endl;
	v1.swap(v2);
	printVector(v1);
	printVector(v2);
}
//�ﵽʵ�õ������ڴ�Ч��
void test44()
{
	vector<int> v;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
	}
	cout << "v������Ϊ��" << v.capacity() << endl;//138255
	cout << "v�Ĵ�СΪ��" << v.size() << endl;//100000
	v.resize(3);
	cout << "v������Ϊ��" << v.capacity() << endl;//138255
	cout << "v�Ĵ�СΪ��" << v.size() << endl;//3

	//swap�����ڴ�
	vector<int>(v).swap(v); //�������� ��������vector<int>(v) ��������ϵͳ�Զ����տռ�
	cout << "v������Ϊ��" << v.capacity() << endl;//3
	cout << "v�Ĵ�СΪ��" << v.size() << endl;//3
}

//Ԥ���ռ�
void test45()
{
	vector<int> v;
	//Ԥ���ռ�100000
	//v.reserve(100000);
	int num = 0;//�����Ԥ���ռ䣬���ٵ�ַ����
	int* p = NULL;
	for (int i = 0; i < 100000; i++) {
		v.push_back(i);
		if (p != &v[0]) {//pָ���׵�ַ
			p = &v[0];
			num++;
		}
	}
	cout << "num:" << num << endl;//Ԥ���ռ俪�ٵ�ַ����Ϊ1����Ԥ�����ٵ�ַ����Ϊ30
}

int main16() {
	test38();
	test39();
	test40();
	test41();
	test42();
	test43();
	test44();
	test45();
	system("pause");
	return 0;
}