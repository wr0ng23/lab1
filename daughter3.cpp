#include "daughter3.h"

int queue3::count_bigger_avereage() const
{
	Element* temp = this->first;
	if (temp == nullptr)
	{
		throw std::string("Нет элементов в очереди!\n");
	}

	int count = 0;
	while (temp)
	{
		count += temp->data;
		temp = temp->next;
	}
	int average = count / size;
	int number_bigger_average = 0;
	temp = this->first;
	while (temp)
	{
		if (temp->data > average)
			number_bigger_average++;
		temp = temp->next;
	}
	return number_bigger_average;
}