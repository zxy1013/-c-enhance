#include <iostream>
using namespace std;
#include <string>

//string构造
void test29()
{
	string s1; //创建空字符串，调用无参构造函数
	cout << "str1 = " << s1 << endl;

	const char* str = "hello world";//使用字符串hello world初始化
	string s2(str); //把c_string转换成了string
	cout << "str2 = " << s2 << endl;

	string s3(s2); //调用拷贝构造函数
	cout << "str3 = " << s3 << endl;//使用一个string对象初始化另一个string对象

	string s4(10, 'a');
	cout << "str4 = " << s4 << endl;//使用10个字符a初始化
}

//赋值
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
	str5.assign("hello c++", 5);//把字符串s的前5个字符赋给当前的字符串
	cout << "str5 = " << str5 << endl;

	string str6;
	str6.assign(str5);
	cout << "str6 = " << str6 << endl;

	string str7;
	str7.assign(5, 'x');//用n个字符c赋给当前字符串
	cout << "str7 = " << str7 << endl;
}

//字符串拼接
void test31()
{
	string str1 = "我";
	str1 += "爱玩游戏";
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
	str3.append(str2, 4, 3); // 从下标4位置开始 ，截取3个字符，拼接到字符串末尾
	cout << "str3 = " << str3 << endl;//str3 = I love game LOL DNF DNF
}

//查找和替换
void test32(){
	//查找
	string str1 = "abcdefgde";
	int pos = str1.find("de");//查找s第一次出现位置 3
	if (pos == -1)
	{
		cout << "未找到" << endl;
	}
	else
	{
		cout << "pos = " << pos << endl;
	}

	pos = str1.rfind("de");//查找s最后一次出现位置，从右往左查 7
	cout << "pos = " << pos << endl;
}

void test33()
{
	//替换
	string str1 = "abcdefgde";
	str1.replace(1, 3, "1111");//替换从1开始3个字符为字符串1111
	cout << "str1 = " << str1 << endl;// a1111efgde
}

//字符串比较
void test34()
{
	string s1 = "hello";
	string s2 = "aello";
	int ret = s1.compare(s2);
	if (ret == 0) {
		cout << "s1 等于 s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 大于 s2" << endl;
	}
	else
	{
		cout << "s1 小于 s2" << endl;
	}
}

//string字符存取
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

	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;
}

//字符串插入和删除
void test36()
{
	string str = "hello";
	str.insert(1, "111");//插入字符串 h111ello
	cout << str << endl;

	str.erase(1, 3);  //从1号位置开始3个字符 hello
	cout << str << endl;
}

//子串
void test37()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);//bcd
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";//使用
	int pos = email.find("@");
	string username = email.substr(0, pos);//从邮件中获取用户名信息
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