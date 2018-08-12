//============================================================================
// Name        : AED_SourceCodes.cpp
// Author      : Cristian Sanchez
// Version     : 1.0
// Copyright   : Cristian Sanchez copyright 2018
//============================================================================

#include "stdafx.h"
#include "Stack.h"

void TestStack() {
	int choice, item;
	stack s1(5);

	s1.push(10);
	s1.push(2);
	s1.push(30);
	s1.push(5);
	s1.push(8);
	s1.print();

	s1.pop();
	s1.pop();
	s1.print();
	
}


int main()
{
	TestStack();
    return 0;
}

