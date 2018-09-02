#pragma once
#include <iostream>


typedef int object;		// rename the ints to objects
class queue{
private:
	object*o;
	int size, first, last;
	bool empty, full;
	void _print();
public:
	queue(int n);		// empty Queue, n objects
	~queue();			// free the queue
	void enqueue(object o);// insert a new element
	object dequeue();	// get and remove the oldest element.
	object getFirst();	// get the oldest element without removing it.
	bool isEmpty();		
	bool isFull();	
	void print() { _print(); };
};

void queue::_print() {
	for (int i = 0; i < size; i++)
		std::cout << o[i] << ", ";
}

queue::queue(int n) {
	size = n; first = last = 0;
	empty = true;
	full = false;
	o = new object[size];
}

queue::~queue() {
	delete[] o;
}

bool queue::isEmpty() {
	return empty;
}

bool queue::isFull() {
	return full;
}

object queue::getFirst() {
	if (!isEmpty()) return o[first];
	else {}// Fehlerbehandlung...
}


object queue::dequeue() {
	if (!isEmpty()) {
		full = false;
		object ret = o[first];
		//remove element setting it to -1
		o[first] = -1;
		first = (first + 1) % size;
		if (first == last)
			empty = true;
		return ret;
	}
	else {}// Fehlerbehandlung...
}

void queue::enqueue(object o) {
	if (!isFull()) {
		empty = false;
		this->o[last] = o;
		last = (last + 1) % size;
		if (first == last)
			full = true;
	}
	else {}// Fehlerbehandlung...
}