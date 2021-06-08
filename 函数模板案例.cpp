#include<iostream>
using namespace std;

//�����ĺ���ģ��
template<typename T>
void mySwap1(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<class T>
//����ѡ�����򣬽��ж�����Ӵ�С������
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++)
	{
		int max = i; //��������±�
		for (int j = i + 1; j < len; j++)
		{
			if (arr[max] < arr[j])
			{
				max = j;
			}
		}
		if (max != i) //�����������±겻��i����������
		{
			mySwap1(arr[max], arr[i]);
		}
	}
}
//����ĺ���ģ��
template<typename T>
void printArray(T arr[], int len) {

	for (int i = 0; i < len; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void test04()
{
	//����char����
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	printArray(charArr, num);
}

void test05()
{
	//����int����
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	printArray(intArr, num);
}

int main2() {
	test04();
	test05();
	system("pause");
	return 0;
}