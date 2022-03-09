#pragma once
#include "safe_input.h"
#include "daughter1.h"
#include "daughter2.h"
#include "daughter3.h"

template <typename queue_template>
void menu(queue_template* q1)
{
	using std::cout;
	using std::endl;
	using std::cin;
	system("cls");
	int choice;
	while (1)
	{
		try
		{
			cout << "1 � ���������� �������� �������\n"
				<< "2 � ���������� �������� �������\n"
				<< "3 � ����� ������� �� �����\n"
				<< "4 � ���������� ��������� ������� ������� "
				<< "�������� ���������������\n"
				<< "5 � �������� ����� �������\n"
				<< "6 � ������� ���� ��������\n" 
				<< "7 � ����� �� ���������\n";
			choice = input<int>();

			switch (choice)
			{
			case 1:
			{
				system("cls");
				cout << "������� ����������� �������\n";
				int var = input<int>();
				q1->add_item(var);
				system("cls");
				cout << "������� " << var << " ������� �������� � �������.\n\n";
				system("pause");
				system("cls");
				break;
			}
			case 2:
				system("cls");
				q1->pop_item(); cout << endl;
				system("pause");
				system("cls");
				break;
			case 3:
				system("cls");
				cout << "�������� ������� �������:" << endl;
				q1->display(); cout << endl;
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				cout << "���������� ��������� ������� �������� ���������������: "
					<< q1->count_bigger_avereage() << endl;
				system("pause");
				system("cls");
				break;
			case 5:
			{
				system("cls");
				if (q1->return_size_of_queue())
				{
					queue_template* copy1 = new queue_template;
					copy1->copy(q1);
					cout << "������� ����������� � ������ ������ ����� ������." << endl
						<< "�������� ������������� �������:" << endl;
					copy1->display(); cout << endl;
					delete copy1;
				}
				else
				{
					throw(std::string("� ������������ ������� ��� ���������, ��� ����������� � ������ �������!\n"));
				}
				system("pause");
				system("cls");
				break;
			}
			case 6:
			{
				system("cls");
				int d;
				char c;
				if(q1->return_size_of_queue())
				{
					queue_template* temp = new queue_template;
					queue_template* res = new queue_template;
					do
					{
						cout << "������� ��������� ��������� ��� ���������� �� 2 �������, "
							<< "� ������� ����� ����������� �������\n";
						d = input<int>();
						temp->add_item(d);
						cout << "������� ����������?(��� ������ ������� - �)\n"; 
						c = input<char>(); cout << endl;
					} while (c != '�');

					system("cls");
					cout << "��� �������� 1 �������: " << endl;
					q1->display(); cout << endl;
					cout << "��� �������� 2 �������: " << endl;
					temp->display(); cout << endl;
					res->merge(q1, temp);
					cout << "��� �������� 3 �������, ����� ���������� 1 � 2 ��������: " << endl;
					res->display(); cout << endl;
					delete res;
					delete temp;
				}
				else
				{
					throw(std::string("� ������������ ������� ��� ���������, ��� ������� � ������ ��������!\n"));
				}
				system("pause");
				system("cls");
				break;
			}
			case 7:
				system("cls");
				cout << "���������� ������.." << endl;
				delete q1;
				cout << endl;
				exit(1);
			default:
				system("cls");
				cout << "������� �������� �������!" << endl;
				system("pause");
				system("cls");
				break;
			}
		}
		catch (std::string& ex)
		{
			cout << ex << std::endl;
			system("pause");
			system("cls");
		}
	}
}