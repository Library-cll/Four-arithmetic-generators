// math_dll.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/*
随机生成一个符合规则的数字，转换为string类型返回。
*/
string GetRandomNumber(int isDecimal, int Maxnum)
{
	// 取得[a, b)的随机整数，使用(rand() % (b - a)) + a （结果值含a不含b）
	int randomnum = (rand() % (Maxnum - 0)) + 0;
	if (isDecimal) {
		// 若有小数，则在末尾添加小数点和小数
		return to_string(randomnum) + "." + to_string(((rand() % (100 - 0 + 1)) + 0));
	}
	return to_string(randomnum);
}

string GetRandomSymbol(int Operator)
{
	string symbol = "";  // 存放选择的运算操作符
	string temp = to_string(Operator);
	int len = temp.size();
	for (int i = 0; i < 4 - len; i++)
	{
		// 将Operator补到4位
		temp = "0" + temp;
	}

	if (temp[0] == '1') { symbol.push_back('+'); }
	if (temp[1] == '1') { symbol.push_back('-'); }
	if (temp[2] == '1') { symbol.push_back('*'); }
	if (temp[3] == '1') { symbol.push_back('/'); }
	// 取得[0, 3]的随机整数，随机选择操作符
	string index = "";
	index.push_back(symbol[(rand() % (symbol.size()))]);
	return index;
}

string AddBrackets()
{
	return 0;
}

/*
获取一个算式。返回值为字符串
Operator 表示四个基本运算，四位数字分别表示四个运算符，依次为+ - * /，Operator为1表示只选择了“/”这个运算，
值为3表示选择了“*”、“/”两种运算，
isDecimal 表示是否有小数
isBrackets 表示是否有括号
Maxnum 表示算式中数字的最大值
*/
char* GetExercises(int Operator, int isDecimal, int isBrackets, int Maxnum)
{
	string cur = "";
	if (isBrackets == 1)
	{
		int len = (rand() % (4 - 1) + 1);
		if (len == 1)
		{
			cur = GetRandomNumber(isDecimal, Maxnum) + " " + GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
		}
		if (len == 2)
		{
			int r = rand() % 2;
			if (r == 1) {
				cur = "(" + GetRandomNumber(isDecimal, Maxnum) + " " + GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")" +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
			}
			else
			{
				cur = GetRandomNumber(isDecimal, Maxnum) + " " + GetRandomSymbol(Operator) + " " + "(" + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")";
			}
		}
		if (len == 3)
		{
			int r = rand() % 6;
			if (r == 0)
			{
				cur = "(" + GetRandomNumber(isDecimal, Maxnum) + " " + GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")" +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum)
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
			}
			if (r == 1)
			{
				cur = GetRandomNumber(isDecimal, Maxnum) + " "
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + "(" + GetRandomNumber(isDecimal, Maxnum)
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")";
			}
			if (r == 2)
			{
				cur = GetRandomNumber(isDecimal, Maxnum) + " "
					+ GetRandomSymbol(Operator) + " " + "(" + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")"
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
			}
			if (r == 3)
			{
				cur = GetRandomNumber(isDecimal, Maxnum) + " "
					+ GetRandomSymbol(Operator) + " " + "(" + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum)
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")";
			}
			if (r == 4)
			{
				cur = GetRandomNumber(isDecimal, Maxnum) + " "
					+ GetRandomSymbol(Operator) + " " + "("+"(" + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")"
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")";
			}
			if (r == 5)
			{
				cur = "(" + GetRandomNumber(isDecimal, Maxnum) + " "
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) +
					GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum) + ")"
					+ GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
			}
		}
	}
	else
	{
		cur = GetRandomNumber(isDecimal, Maxnum);
		int len = (rand() % (4 - 1) + 1);
		for (int i = 0; i < len + 1; i++) {
			//cout << len + 1 << endl;
			cur = cur + " " + GetRandomSymbol(Operator) + " " + GetRandomNumber(isDecimal, Maxnum);
		}
	}
	// 关于变量类型转化，查阅此博文
	// https://blog.csdn.net/hebbely/article/details/79577880
	char* ch = new char[cur.size() + 1];
	strcpy_s(ch, cur.size() + 1, cur.c_str());
	return ch;
}

