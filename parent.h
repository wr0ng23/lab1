#pragma once
#include <iostream>

struct Element
{
	int data;
	Element* next;
};

class queue
{
private:
	Element* first;
	Element* last;
protected:
	int size;
public:
	queue()
	{
		first = nullptr;
		last = nullptr;
		size = 0;
	}
	~queue();
	bool isEmpty();
	int return_size_of_queue() const;
	void display() const;
	void add_item(int);
	void pop_item();
	void copy(queue*);
	void merge(queue*, queue*);
	friend class queue1;
	friend class queue2;
	friend class queue3;
};