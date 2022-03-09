#include <Windows.h>
#include "menu.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int choice1;

	while (1)
	{
		system("cls");
		std::cout << "� ����� �������� ������� �� ������� ��������?\n"
			<< "1 - �������� ����� � ������������� private\n" 
			<< "2 - �������� ����� � ������������� protected\n"
			<< "3 - �������� ����� � ������������� public\n";
		choice1 = input<int>();

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
		{
			system("cls");
			std::cout << "������� ������������ �����!\n";
			system("pause");
		}
	}
	return 0;
}