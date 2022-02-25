#include <iostream>
#include <Windows.h>
#include "daughter1.h"
#include "daughter2.h"
#include "daughter3.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice1;
	queue1* q1 = new queue1;
	queue2* q2 = new queue2;
	queue3* q3 = new queue3;

	std::cout << "С каким дочерним классом вы желаете работать? " << std::endl
		<< "1 - Дочерний класс с наследованием private" << std::endl
		<< "2 - Дочерний класс с наследованием protected" << std::endl
		<< "3 - Дочерний класс с наследнованием public" << std::endl; 
	std::cout << "Введите цифру: "; std::cin >> choice1;
	if (choice1 == 1)
	{
		delete q3;
		delete q2;
		variety(q1);
	}
	else if (choice1 == 2)
	{
		delete q1; 
		delete q3;
		variety(q2);
	}
	else if (choice1 == 3)
	{
		delete q1;
		delete q2;
		variety(q3);
	}
	else
		std::cout << "Введена некорректная цифра!\n";

	return 0;
}