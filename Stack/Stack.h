#pragma once

//============================================================================
// Name        : Stack.h
// Author      : Cristian Sanchez
// Version     : 1.0
// Copyright   : Cristian Sanchez copyright 2018
//============================================================================
#include<iostream>
#include<cstdlib>

typedef int object; 
class stack
{
private:
	object *o;	
	int size;	
	int tp;		
public:
	stack() = default;
	stack(int n);		// creates a empty stack (max: n objects)
	~stack();			// free the stack memory
	void push(object o);// load an value object on the stack
	object pop();		// hold and delete the last element on the stack
	object top();		// return the last element on the stack
	bool isEmpty();		// return true if stack empty
	bool isFull();		// return true if stack full
	void print();		// prints all elements on stack
};

stack::stack(int n) {
	size = n;
	tp = -1;
	o = new object[size];
} 

void stack::push(object o) {
	if (!isFull()) {
		tp++;
		this->o[tp] = o;
	}
		
}

object stack::top() {
	if (!isEmpty())
		return(o[tp]);
	else
		return -1;
}

bool stack::isEmpty() {
	return(tp> -1 ? false : true);
}

object stack::pop() {
	if (!isEmpty()) {
		o[tp] = -1;
		tp--;
		return(o[tp]);
	}
	else
		return -1;
}

bool stack::isFull() {
	return (tp< size - 1 ? false : true);
}

void stack::print()
{
	if (top() == -1)
		std::cout << "Stack is empty" << std::endl;
	else
	{
		int counter = 0;
		std::cout << "Stack elements :" << std::endl;
		while (size > counter)
		{
			std::cout << o[counter] << "	";
			counter++;
		}
		std::cout<< std::endl;
	}
}

stack::~stack() {
	delete[] o;
}