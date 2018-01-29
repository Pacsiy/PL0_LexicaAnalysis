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
	bool isSpace();//�жϿո�
	bool isNewline();//�жϻ��з�
	bool isTab();//�ж�����
	bool isLetter();//�ж���ĸ
	bool isDigit();//�ж�����

	bool isKeyword();//�жϹؼ���
	bool isBountary();//�жϽ��
	bool isDoubleOperator();//�ж�˫�ַ������
	bool isSingleOperator();//�жϵ��ַ������
	bool isOperatorFirst();//�ж���������ַ�

	Judge& clearToken();//���token
	Judge& catToken();//����token
	Judge& retract();//�ļ�ָ��ǰ��

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
		KeyWord,//�ؼ���
		Identifier,//��ʶ��
		Boundary,//�ֽ��
		Constant,//����
		DoubleOperator,//˫Ŀ�����
		SingleOperator,//��Ŀ�����
		Error//����
	};

	string token;
	Category tokenCate;
	char ch;
	FILE *fp;
};

#endif //LEXICA_ANALYSIS_JUDGE_H