#include <iostream>
using namespace std;
#include <list>

//��ӡ����
void printList(const list<int>& L) {
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

//list���캯��
void test56()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);//10 20 30 40

	list<int>L2(L1.begin(), L1.end());//���䷽ʽ����
	printList(L2);//10 20 30 40

	list<int>L3(L2);//��������
	printList(L3);//10 20 30 40

	list<int>L4(10, 1000);
	printList(L4);//1000 1000 1000 1000 1000 1000 1000 1000 1000 1000
}

// list��ֵ�ͽ���
//��ֵ
void test57()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList(L1);
	//��ֵ
	list<int>L2;
	L2 = L1;//���صȺŲ�����
	printList(L2);

	list<int>L3;
	L3.assign(L2.begin(), L2.end());
	printList(L3);

	list<int>L4;
	L4.assign(10, 100);
	printList(L4);
}
//����
void test58()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	list<int>L2;
	L2.assign(10, 100);
	cout << "����ǰ�� " << endl;
	printList(L1);
	printList(L2);
	cout << endl;

	L1.swap(L2);
	cout << "������ " << endl;
	printList(L1);
	printList(L2);
}

//��С����
void test59()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	if (L1.empty())
	{
		cout << "L1Ϊ��" << endl;
	}
	else
	{
		cout << "L1��Ϊ��" << endl;
		cout << "L1�Ĵ�СΪ�� " << L1.size() << endl;
	}
	//����ָ����С
	L1.resize(10);//10 20 30 40 0 0 0 0 0 0
	printList(L1);
	L1.resize(2);
	printList(L1);
}

//�����ɾ��
void test60()
{
	list<int> L;
	//β��
	L.push_back(10);
	L.push_back(20);
	L.push_back(30);
	//ͷ��
	L.push_front(100);
	L.push_front(200);
	L.push_front(300);
	printList(L);//300 200 100 10 20 30 
	//βɾ
	L.pop_back();
	printList(L);//300 200 100 10 20
	//ͷɾ
	L.pop_front();
	printList(L);
	//����
	list<int>::iterator it = L.begin();
	L.insert(++it, 1000);
	printList(L);//200 1000 100 10 20
	//ɾ��
	it = L.begin();
	L.erase(++it);
	printList(L);
	//�Ƴ�
	L.push_back(10000);//β��
	L.push_back(10000);
	L.push_back(10000);
	printList(L);
	L.remove(10000);//ɾ��������������10000ƥ���Ԫ�ء�
	printList(L);
	//���
	L.clear();
	printList(L);
}

//list���ݴ�ȡ
void test61()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	//cout << L1.at(0) << endl;//���� ��֧��at��������
	//cout << L1[0] << endl; //���� ��֧��[]��ʽ��������
	cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;//10
	cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;//40
	//����list����Ϊ�����������������Կռ�洢����
	//list�����ĵ�������˫�����������֧��������ʡ�
	list<int>::iterator it = L1.begin();
	it ++; //֧��˫��it --;
	//it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1
}

//�������
bool myCompare(int val1 , int val2)
{	//���� �õ�һ�������ڵڶ�����
	return val1 > val2;
}

//��ת������
void test62()
{
	list<int> L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList(L);
	//��ת������Ԫ��
	L.reverse();
	printList(L);
	//���� ���в�֧��������ʵ��������������������ñ�׼�㷨 sort(d.begin(), d.end());
	L.sort(); //Ĭ�ϵ�������� ��С����
	printList(L);
	L.sort(myCompare); //ָ�����򣬴Ӵ�С
	printList(L);
}

int main21() {
	test56();
	test57();
	test58();
	test59();
	test60();
	test61();
	test62();
	system("pause");
	return 0;
}