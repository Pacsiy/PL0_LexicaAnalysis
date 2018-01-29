#pragma once

//
// Created by AlvinZH on 2017/11/21.
// Copyright (c) AlvinZH. All rights reserved.
//

#ifndef LEXICA_ANALYSIS_COMPILER_H
#define LEXICA_ANALYSIS_COMPILER_H

#include "Judge.h"
using namespace std;

class Compiler : public Judge {
public:
	Compiler();
	Compiler(const char* input, const char* output);
	bool nextToken();
	string toBinary();

	void printCate();

	void setTxtOutput();
	string* getTxtOutput();
private:
	string txtOutput[3];
};

#endif //LEXICA_ANALYSIS_COMPILER_H