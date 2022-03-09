#include "daughter1.h"

int queue1::count_bigger_avereage() const
{
	Element* temp = this->first;
	if (temp == nullptr)
	{
		throw std::string("Нет элементов в очереди!\n");
	}

	int count = 0;
	while(temp)
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

int queue1::return_size_of_queue() const
{
	return size;
}

void queue1::display() const
{
	queue::display();
}

void queue1::add_item(int d)
{
	queue::add_item(d);
}

void queue1::pop_item()
{
	queue::pop_item();
}

void queue1::copy(queue1* q2)
{
	Element* temp = q2->first;
	int* arr = new int[q2->size]{};
	size_t n = 0;
	while (temp)
	{
		arr[n] = temp->data;
		n++;
		temp = temp->next;
	}
	for (size_t i = 0; i < n; i++)
	{
		add_item(arr[i]);
	}
	delete[] arr;
}

void queue1::merge(queue1* q1, queue1* q2)
{
	Element* temp = q1->first;
	Element* temp1 = q2->first;
	int* arr1 = new int[q1->size];
	int* arr2 = new int[q2->size];
	size_t n = 0;
	while (temp)
	{
		arr1[n] = temp->data;
		n++;
		temp = temp->next;
	}
	for (size_t i = 0; i < n; i++)
		this->add_item(arr1[i]);

	n = 0;
	while (temp1)
	{
		arr2[n] = temp1->data;
		n++;
		temp1 = temp1->next;
	}
	for (size_t i = 0; i < n; i++)
		this->add_item(arr2[i]);

	delete[] arr1;
	delete[] arr2;
}