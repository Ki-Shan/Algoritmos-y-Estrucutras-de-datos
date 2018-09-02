#pragma once

#include <iostream>

typedef int object;
class element{
public:
	object val;
	element* next;
};

class list{
private:
	element* head; //Pointer to the start
	element* tail; //Pointer to the end
	void deleteList(element* first);
public:
	list(); //constructor, creates a list
	~list();
	void append(object o); //
	void deleteList(); //delete the list
	void deleteValue(object o); //delete single value
	void print(); //print the list
	element* searchValue(object o);
	element* searchValue(element* tmp, object o);
};

list::list() {
	head = nullptr;
	tail = nullptr;
}

list::~list() {
	deleteList(head->next);
	head = nullptr; tail = nullptr;
}

void list::deleteList() {
	deleteList(head->next);
}

void list::deleteList(element* first) {
	//go to the end of the list and delete backwards
	if (first != nullptr) {
		if (first->next != nullptr)
			deleteList(first->next);
		delete first;
	}
}

void list::print() {
	element* curr = head->next;
	while (curr != tail) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

void list::append(object o) {
	element* elem = new element;
	elem->val = o;
	elem->next = nullptr;
	if (head->next == nullptr) {	//empty list
		head->next = elem; elem->next = tail;
	}
	else { tail->next = elem; tail = elem; }
}

element* list::searchValue(element* tmp, object o) {
	//tmp is a running variable over the elements
	//if tmp == nullptr, then the elements were already checked,
	//and the element was not found
	if (tmp->next != nullptr) {	//list not empty
		//check the next element
		if (tmp->next->val == o)
			//return a copy pointing to the same variable
			//return the element before the target
			return tmp;
		else
			//call the function again wit the next element
			return searchValue(tmp->next, o);
	}
	//element not found
	else {
		if (tmp != nullptr) {
			if (tmp->val == o)
				return tmp;
		}
		std::cout << "Element not found" << std::endl;
		return nullptr;
	}
}

element* list::searchValue(object o) {
	//check the list is not empty
	if (head != nullptr && tail != nullptr) {
		//calling by value
		//give the function a copy of the head pointer 
		return searchValue(head, o);
	}	
}

void list::deleteValue(object o) {
	//search the value:
	element* target = searchValue(o);
	if (target != nullptr)
	{
		target->next = 
		delete target;	//delete where the target points to
	}
}