#include "parent.h"

class queue1 : private queue
{
public:
	int count_bigger_avereage() const;
	void display() const;
	void add_item(int);
	void pop_item();
	void copy(queue1*);
	void merge(queue1*, queue1*);
};

void variety(queue1*);