#include <iostream>
#include "parent.h"

queue::~queue()
{
	Element* temp = nullptr;
	while (first)
	{
		temp = first->next;
		delete first;
		first = temp;
	}
}

int queue::return_size_of_queue() const
{
	return size;
}

bool queue::isEmpty()
{
	return (first == nullptr) ? true : false;
}

void queue::add_item(int d)
{
	Element* newElement = new Element;
	newElement->data = d;
	newElement->next = nullptr;
	if (isEmpty())
		first = newElement;
	else
		last->next = newElement;
	last = newElement;
	size++;
}

void queue::pop_item()
{
	if (first == nullptr)
		throw std::string("Попытка извлечения из пустой очереди!");
	int temp = first->data;
	Element* temp_element = first->next;
	if (first->next == nullptr)
		last = nullptr;
	delete first;
	first = temp_element;
	std::cout << "Извлечен элемент : " << temp << std::endl;
	size--;
}

void queue::copy(queue* q2)
{
	Element* temp = q2->first;
	int* arr = new int[q2->size] {};
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

void queue::display() const
{
	if (size == 0)
		throw(std::string("В очереди нет элементов!"));
	Element* current = first;
	while (current)
	{
		std::cout << current->data << std::endl;
		current = current->next;
	}
}

void queue::merge(queue* q1, queue* q2)
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