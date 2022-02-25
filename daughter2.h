#include "parent.h"

class queue2 : protected queue
{
public:
	int count_bigger_avereage() const;
	void display() const;
	void add_item(int);
	void pop_item();
	void copy(queue2*);
	void merge(queue2*, queue2*);
};