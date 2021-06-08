#include <iostream>
using namespace std;
#include <string>

//string����
void test29()
{
	string s1; //�������ַ����������޲ι��캯��
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";//ʹ���ַ���hello world��ʼ��
	string s2(str); //��c_stringת������string
	cout << "str2 = " << s2 << endl;

	string s3(s2); //���ÿ������캯��
	cout << "str3 = " << s3 << endl;//ʹ��һ��string�����ʼ����һ��string����

	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;//ʹ��10���ַ�a��ʼ��
}

//��ֵ
void test30()
{
	string str1;
	str1 = "hello world";
	cout << "str1 = " << str1 << endl;

	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;

	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;

	string str4;
	str4.assign("hello c++");
	cout << "str4 = " << str4 << endl;

	string str5;
	str5.assign("hello c++", 5);//���ַ���s��ǰ5���ַ�������ǰ���ַ���
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');//��n���ַ�c������ǰ�ַ���
	cout << "str7 = " << str7 << endl;
}

//�ַ���ƴ��
void test31()
{
	string str1 = "��";
	str1 += "������Ϸ";
	cout << "str1 = " << str1 << endl;

	str1 += ':';
	cout << "str1 = " << str1 << endl;

	string str2 = "LOL DNF ";
	str1 += str2;
	cout << "str1 = " << str1 << endl;

	string str3 = "I";
	str3.append(" love ");
	str3.append("game abcde", 5);
	str3.append(str2);
	str3.append(str2, 4, 3); // ���±�4λ�ÿ�ʼ ����ȡ3���ַ���ƴ�ӵ��ַ���ĩβ
	cout << "str3 = " << str3 << endl;//str3 = I love game LOL DNF DNF
}

//���Һ��滻
void test32(){
	//����
	string str1 = "abcdefgde";
	int pos = str1.find("de");//����s��һ�γ���λ�� 3
	if (pos == -1)
	{
		cout << "δ�ҵ�" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	pos = str1.rfind("de");//����s���һ�γ���λ�ã���������� 7
	cout << "pos = " << pos << endl;
}

void test33()
{
	//�滻
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");//�滻��1��ʼ3���ַ�Ϊ�ַ���1111
	cout << "str1 = " << str1 << endl;// a1111efgde
}

//�ַ����Ƚ�
void test34()
{
	string s1 = "hello";
	string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 ���� s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else
	{
		cout << "s1 С�� s2" << endl;
	}
}

//string�ַ���ȡ
void test35()
{
	string str = "hello world";
	for (int i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//�ַ��޸�
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

//�ַ��������ɾ��
void test36()
{
	string str = "hello";
	str.insert(1, "111");//�����ַ��� h111ello
	cout << str << endl;

	str.erase(1, 3);  //��1��λ�ÿ�ʼ3���ַ� hello
	cout << str << endl;
}

//�Ӵ�
void test37()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);//bcd
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";//ʹ��
	int pos = email.find("@");
	string username = email.substr(0, pos);//���ʼ��л�ȡ�û�����Ϣ
	cout << "username: " << username << endl;//hello
}

int main15() {
	test29();
	test30();
	test31();
	test32();
	test33();
	test34();
	test35();
	test36();
	test37();
	system("pause");
	return 0;
}