#include <iostream>
#include <Windows.h>
#include "daughter1.h"
#include "daughter2.h"
#include "daughter3.h"
#include "menu.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice1;

	std::cout << "� ����� �������� ������� �� ������� ��������? " << std::endl
		<< "1 - �������� ����� � ������������� private" << std::endl
		<< "2 - �������� ����� � ������������� protected" << std::endl
		<< "3 - �������� ����� � ������������� public" << std::endl; 
	std::cout << "������� �����: "; std::cin >> choice1;

	if (choice1 == 1)
	{
		queue1* q1 = new queue1;
		menu(q1);
	}
	else if (choice1 == 2)
	{
		queue2* q2 = new queue2;
		menu(q2);
	}
	else if (choice1 == 3)
	{
		queue3* q3 = new queue3;
		menu(q3);
	}
	else
		std::cout << "������� ������������ �����!\n";

	return 0;
}