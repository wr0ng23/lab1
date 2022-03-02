#include "parent.h"

class queue1 : private queue
{
public:
	int count_bigger_avereage() const;
	int return_size_of_queue() const;
	void display() const;
	void add_item(int);
	void pop_item();
	void copy(queue1*);
	void merge(queue1*, queue1*);
};