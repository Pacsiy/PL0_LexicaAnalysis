//
// Created by AlvinZH on 2017/11/21.
// Copyright (c) AlvinZH. All rights reserved.
//

#include "stdafx.h"
#include "Judge.h"

Judge::Judge() {}

bool Judge::isSpace() {
	if (ch == ' ') return true;
	else return false;
}

bool Judge::isNewline() {
	if (ch == '\n') return true;
	else return false;
}

bool Judge::isTab() {
	if (ch == '\t') return true;
	else return false;
}

bool Judge::isDigit() {
	if (ch >= '0' && ch <= '9')
		return true;
	else return false;
}

bool Judge::isLetter() {
	if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
		return true;
	else return false;
}

bool Judge::isKeyword() {
	for (int i = 0; i < KeyWordsNum; i++)
		if (token == KeyWords[i])
			return true;
	return false;
}

bool Judge::isBountary() {
	for (int i = 0; i < BoundaryNum; i++)
		if (ch == Boundarys[i])
			return true;
	return false;
}

bool Judge::isDoubleOperator()
{
	for (int i = 0; i < doubleOperatorNum; i++)
		if (token == doubleOperator[i])
			return true;
	return false;
}

bool Judge::isSingleOperator()
{
	for (int i = 0; i < singleOperatorNum; i++)
		if (token == singleOperator[i])
			return true;
	return false;
}

bool Judge::isOperatorFirst()
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '=' || ch == '<' || ch == '>' || ch == ':')
		return true;
	return false;
}

Judge& Judge::clearToken() {
	token = "";
	return *this;
}

Judge& Judge::catToken() {
	token += ch;
	return *this;
}

Judge& Judge::retract() {
	fseek(fp, -1, 1);
	return *this;
}