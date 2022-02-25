#include <iostream>
#include "parent.h"

queue::~queue()
{
	Element* temp = nullptr;
	while (last)
	{
		temp = last->prev;
		delete last;
		last = temp;
	}
}

Element* queue::return_last() const
{
	return last;
}

void queue::add_item(int d)
{
	Element* newElement = new Element;
	newElement->data = d;
	newElement->prev = last;
	last = newElement;
	size++;
}

void queue::pop_item()
{
	Element* current = last;
	while (current)
	{
		if (current->prev == nullptr)
		{
			std::cout << "Извлечен элемент: " << current->data << std::endl;
			delete current;
			last = nullptr;
			size--;
			return;
		}
		if (current->prev->prev == nullptr)
		{
			std::cout << "Извлечен элемент: " << current->prev->data << std::endl;
			delete current->prev;
			current->prev = nullptr;
			size--;
			return;
		}
		current = current->prev;
	}
	std::cout << "Нет элементов!" << std::endl;
}

void queue::copy(queue* q2)
{
	Element* temp = q2->last;
	int* arr = new int[q2->size] {};
	int n = 0;
	while (temp)
	{
		arr[n] = temp->data;
		n++;
		temp = temp->prev;
	}
	for (n--; n >= 0; n--)
	{
		add_item(arr[n]);
	}
	delete[] arr;
}

void queue::display() const
{
	if (size == 0)
	{
		std::cout << "Нет элементов!" << std::endl;
		return;
	}
	Element* current = last;
	int* arr = new int[size];
	int n = 0;
	while (current)
	{
		arr[n] = current->data;
		n++;
		current = current->prev;
	}
	for (n--; n >= 0; n--)
	{
		std::cout << arr[n] << std::endl;
	}
	delete[] arr;
}

void queue::merge(queue* q1, queue* q2)
{
	Element* temp = q1->return_last();
	Element* temp1 = q2->return_last();
	int* arr = new int[q1->size];
	int* arr1 = new int[q2->size];
	int n = 0;
	while (temp)
	{
		arr[n] = temp->data;
		n++;
		temp = temp->prev;
	}
	for (n--; n >= 0; n--)
		this->add_item(arr[n]);

	n = 0;
	while (temp1)
	{
		arr1[n] = temp1->data;
		n++;
		temp1 = temp1->prev;
	}
	for (n--; n >= 0; n--)
		this->add_item(arr1[n]);

	delete[] arr;
	delete[] arr1;
}