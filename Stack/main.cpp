// eBook_AED_SourceCodes.cpp : Defines the entry point for the console application.
//

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

