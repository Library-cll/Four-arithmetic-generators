// math_dll.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <string>

using namespace std;

/*
�������һ�����Ϲ�������֣�ת��Ϊstring���ͷ��ء�
*/
string GetRandomNumber(int isDecimal, int Maxnum)
{
	// ȡ��[a, b)�����������ʹ��(rand() % (b - a)) + a �����ֵ��a����b��
	int randomnum = (rand() % (Maxnum - 0)) + 0;
	if (isDecimal) {
		// ����С��������ĩβ���С�����С��
		return to_string(randomnum) + "." + to_string(((rand() % (100 - 0 + 1)) + 0));
	}
	return to_string(randomnum);
}

string GetRandomSymbol(int Operator)
{
	string symbol = "";  // ���ѡ������������
	string temp = to_string(Operator);
	int len = temp.size();
	for (int i = 0; i < 4 - len; i++)
	{
		// ��Operator����4λ
		temp = "0" + temp;
	}

	if (temp[0] == '1') { symbol.push_back('+'); }
	if (temp[1] == '1') { symbol.push_back('-'); }
	if (temp[2] == '1') { symbol.push_back('*'); }
	if (temp[3] == '1') { symbol.push_back('/'); }
	// ȡ��[0, 3]��������������ѡ�������
	string index = "";
	index.push_back(symbol[(rand() % (symbol.size()))]);
	return index;
}

string AddBrackets()
{
	return 0;
}

/*
��ȡһ����ʽ������ֵΪ�ַ���
Operator ��ʾ�ĸ��������㣬��λ���ֱַ��ʾ�ĸ������������Ϊ+ - * /��OperatorΪ1��ʾֻѡ���ˡ�/��������㣬
ֵΪ3��ʾѡ���ˡ�*������/���������㣬
isDecimal ��ʾ�Ƿ���С��
isBrackets ��ʾ�Ƿ�������
Maxnum ��ʾ��ʽ�����ֵ����ֵ
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
	// ���ڱ�������ת�������Ĵ˲���
	// https://blog.csdn.net/hebbely/article/details/79577880
	char* ch = new char[cur.size() + 1];
	strcpy_s(ch, cur.size() + 1, cur.c_str());
	return ch;
}

