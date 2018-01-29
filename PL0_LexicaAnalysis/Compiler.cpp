//
// Created by AlvinZH on 2017/11/21.
// Copyright (c) AlvinZH. All rights reserved.
//

#include "stdafx.h"
#include "Compiler.h"

Compiler::Compiler() :Judge() {}

Compiler::Compiler(const char* input,const char* output) {
	fp = freopen(input, "r", stdin);
	freopen(output, "w", stdout);
	cout << "Word" << "\t\t    Category" << "\t\tValue\n";
}

bool Compiler::nextToken() {
	if ((ch = getchar()) != EOF)
	{
		clearToken();
		while (isSpace() || isNewline() || isTab())
			ch = getchar();
		if (ch == EOF) return false;
		if (isLetter())
		{
			while (isLetter() || isDigit())
			{
				catToken();
				ch = getchar();
			}
			if (ch != EOF)
				retract();
			if (isKeyword()) {
				tokenCate = KeyWord;
				printCate();
			}
			else {
				tokenCate = Identifier;
				printCate();
			}
		}
		else if (isDigit())
		{
			while (isDigit()){
				catToken();
				ch = getchar();
			}
			if (ch == '.'){
				catToken();
				ch = getchar();
				if(isDigit())
					while (isDigit()){
						catToken();
						ch = getchar();
					}
				else{
					retract();
					token.erase(token.end()-1);
				}
			}
			if(ch != EOF)
				retract();
			tokenCate = Constant;
			printCate();
		}
		else if (isBountary())
		{
			catToken();
			tokenCate = Boundary;
			printCate();
		}
		else if (isOperatorFirst())
		{
			catToken();
			ch = getchar();
			if (token == "<" && (ch == '>' || ch == '='))
			{
				catToken();
				tokenCate = DoubleOperator;
				printCate();
			}
			else if (token == ">" && ch == '=')
			{
				catToken();
				tokenCate = DoubleOperator;
				printCate();
			}
			else if (token == ":")
			{
				if (ch == '=')
				{
					catToken();
					tokenCate = DoubleOperator;
					printCate();
				}
				else
				{
					if (ch != EOF)
						retract();
					tokenCate = Error;
					printCate();
				}
			}
			else
			{
				if (ch != EOF)
					retract();
				tokenCate = SingleOperator;
				printCate();
			}
		}
		else
		{
			catToken();
			tokenCate = Error;
			printCate();
		}
		return true;
	}
	else return false;
}

string Compiler::toBinary()
{
	int len = token.length();
	string str = "";
	int x = 0;
	int i = 0;
	for (; i < len && token[i] != '.'; i++)
		x = x * 10 + token[i] - '0';
	while (x > 0)
	{
		str += x % 2 + '0';
		x /= 2;
	}
	reverse(str.begin(), str.end());
	if (token[i] == '.')
	{
		str += '.';
		i ++;
		x = 0;
		int cnt = 0;
		for (; i < len; i++)
		{
			x = x * 10 + token[i] - '0';
			cnt ++;
			if (cnt == 8) break;
		}
		double y = (double)x / (pow(10, cnt));
		cnt = 0;
		while (y > 0)
		{
			str += y * 2 + '0';
			y *= 2;
			if (y >= 1)
				y -= 1;
			cnt ++;
			if (cnt == 6) break;
		}
	}
	if (str == "") str = "0";
	return str;
}

void Compiler::printCate()
{
	setTxtOutput();
	cout.setf(ios::left);
	cout.width(20);
	cout << txtOutput[0];
	cout.width(20);
	cout << txtOutput[1];
	cout.width(20);
	cout << txtOutput[2] << "\n";
}

void Compiler::setTxtOutput()
{
	string cate;
	switch (tokenCate)
	{
	case 0:cate = "KeyWord"; break;
	case 1:cate = "Identifier"; break;
	case 2:cate = "Boundary"; break;
	case 3:cate = "Constant"; break;
	case 4:cate = "DoubleOperator"; break;
	case 5:cate = "SingleOperator"; break;
	case 6:cate = "ERROR"; break;
	}

	txtOutput[0] = token;
	txtOutput[1] = cate;

	if (tokenCate == Constant)
		txtOutput[2] = toBinary();
	else
		txtOutput[2] = token;
}

string * Compiler::getTxtOutput()
{
	return txtOutput;
}
