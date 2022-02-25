#pragma once
struct Element
{
	int data;
	Element* prev;
};

class queue
{
private:
	Element* last;
protected:
	int size;
public:
	queue()
	{
		last = nullptr;
		size = 0;
	}
	~queue();
	void display() const;
	void add_item(int);
	void pop_item();
	void copy(queue*);
	void merge(queue*, queue*);
	Element* return_last() const;
};