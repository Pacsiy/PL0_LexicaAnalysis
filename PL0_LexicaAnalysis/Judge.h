#pragma once

//
// Created by AlvinZH on 2017/11/21.
// Copyright (c) AlvinZH. All rights reserved.
//

#ifndef LEXICA_ANALYSIS_JUDGE_H
#define LEXICA_ANALYSIS_JUDGE_H

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class Judge {
public:
	Judge();
	bool isSpace();//判断空格
	bool isNewline();//判断换行符
	bool isTab();//判断缩进
	bool isLetter();//判断字母
	bool isDigit();//判断数字

	bool isKeyword();//判断关键字
	bool isBountary();//判断界符
	bool isDoubleOperator();//判断双字符运算符
	bool isSingleOperator();//判断单字符运算符
	bool isOperatorFirst();//判断运算符首字符

	Judge& clearToken();//清除token
	Judge& catToken();//连接token
	Judge& retract();//文件指针前移

	static const int KeyWordsNum = 16;
	string KeyWords[KeyWordsNum] = {
		"const", "var", "procedure", "odd", "if", 
		"else" , "then", "while", "do", "call", "begin",
		"end", "repeat", "until", "read", "write"
	};
	static const int BoundaryNum = 5;
	char Boundarys[BoundaryNum] = {
		',', '(', ')', ';', '.'
	};
	static const int doubleOperatorNum = 4;
	string doubleOperator[doubleOperatorNum] = {
		"<>", "<=",  ">=", ":="
	};
	static const int singleOperatorNum = 7;
	string singleOperator[singleOperatorNum] = {
		"+", "-", "*", "/", "=", "<", ">"
	};

	enum Category {
		KeyWord,//关键字
		Identifier,//标识符
		Boundary,//分界符
		Constant,//常数
		DoubleOperator,//双目运算符
		SingleOperator,//单目运算符
		Error//错误
	};

	string token;
	Category tokenCate;
	char ch;
	FILE *fp;
};

#endif //LEXICA_ANALYSIS_JUDGE_H