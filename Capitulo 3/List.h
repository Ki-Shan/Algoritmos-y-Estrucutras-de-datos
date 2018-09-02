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
	list();
	~list();
	void append(object o);//Insert new value
	void deleteList();//Delete the list
	void deleteValue(object o);//Delete value
	void print();//print the list
};

list::list() {
	head = nullptr;
	tail = nullptr;
}

list::~list() {
	deleteList(head);
	head = nullptr; tail = nullptr;
}

void list::deleteList() {
	deleteList(head);
}

void list::deleteList(element* first) {
	if (first != nullptr) {
		if (first->next != nullptr)
			deleteList(first->next);
		delete first;
	}
}

void list::print() {
	element* curr = head;
	while (curr != nullptr) {
		std::cout << curr->val << " ";
		curr = curr->next;
	}
	std::cout << std::endl;
}

void list::append(object o) {
	element*elem = new element;
	elem->val = o;
	elem->next = nullptr;
	if (tail == nullptr) {
		head = elem; tail = elem;
	}
	else { tail->next = elem; tail = elem; }
}

void list::deleteValue(object o) {
	element *curr = head, *prev = nullptr;
	while (curr != nullptr) {
		if (curr->val == o) {
			if (prev == nullptr)
				head = curr->next;
			else
				prev->next = curr->next;
			if (curr == tail)
				tail = prev;
			element *h = curr;
			curr = curr->next;
			delete h;
		}
		else {
			prev = curr;
			curr = curr->next;
		}
	}
}