#include <iostream>
using namespace std;
#include <stack>

//ջ�������ýӿ�
void test54()
{
	//����ջ���� ջ������������Ƚ����
	stack<int> s;
	//��ջ�����Ԫ�أ����� ѹջ ��ջ
	s.push(10);
	s.push(20);
	s.push(30);
	stack<int> s1 = s;//����
	
	stack<int> s2;//��ֵ
	s2 = s1;//���صȺŲ�����

	while (!s.empty()) {
		//���ջ��Ԫ��
		cout << "ջ��Ԫ��Ϊ�� " << s.top() << endl;
		//ɾ��ջ��Ԫ�� ��ջ
		s.pop();
	}
	cout << "ջs�Ĵ�СΪ��" << s.size() << endl;//0
	cout << "ջs1�Ĵ�СΪ��" << s1.size() << endl;//3
	cout << "ջs2�Ĵ�СΪ��" << s2.size() << endl;//3
}

int main19() {
	test54();
	system("pause");
	return 0;
}