#include <iostream>
#include "daughter2.h"

int queue2::count_bigger_avereage() const
{
	Element* temp = queue::return_last();
	if (temp == nullptr)
	{
		std::cout << "��� ���������!";
		return 0;
	}
	int count = 0;
	while (temp)
	{
		count += temp->data;
		temp = temp->prev;
	}
	int average = count / size;
	int number_bigger_average = 0;
	temp = queue::return_last();
	while (temp)
	{
		if (temp->data > average)
			number_bigger_average++;
		temp = temp->prev;
	}
	return number_bigger_average;
}

void queue2::display() const
{
	queue::display();
}

void queue2::add_item(int d)
{
	queue::add_item(d);
}

void queue2::pop_item()
{
	queue::pop_item();
}

void queue2::copy(queue2* q2)
{
	Element* temp = q2->return_last();
	int* arr = new int[q2->size]{};
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

void queue2::merge(queue2* q1, queue2* q2)
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

void variety(queue2* q1)
{
	using std::cout;
	using std::endl;
	using std::cin;
	system("cls");
	int choice;
	while (1)
	{
		cout << "1 � ���������� �������� �������" << endl
			<< "2 � ���������� �������� �������" << endl
			<< "3 � ����� ������� �� �����" << endl
			<< "4 � ���������� ��������� ������� �������, "
			<< "�������� ���������������" << endl
			<< "5 � �������� ����� �������" << endl
			<< "6 � ������� ���� ��������" << endl
			<< "7 � ����� �� ���������" << endl;
		cout << "������� �����: "; cin >> choice;
		queue2* temp = new queue2;
		queue2* res = new queue2;
		queue2* copy1 = new queue2;
		switch (choice)
		{
		case 1:
			system("cls");
			int var;
			cout << "������� ����������� �������: "; cin >> var;
			q1->add_item(var);
			system("pause");
			system("cls");
			break;
		case 2:
			system("cls");
			q1->pop_item();
			system("pause");
			system("cls");
			break;
		case 3:
			system("cls");
			cout << "�������� ������� �������:" << endl;
			q1->display();
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
			system("cls");
			copy1->copy(q1);
			cout << "������� ����������� � ������ ������ ����� ������." << endl
				<< "�������� ������������� �������:" << endl;
			copy1->display();
			delete copy1;
			system("pause");
			system("cls");
			break;
		case 6:
			system("cls");
			int d;
			char c;

			do
			{
				cout << "������� ��������� ��������� ��� ���������� �� 2 �������,\n"
					<< "� ������� ����� ����������� ������� ������� ������� � 3 �������: ";
				cin >> d;
				temp->add_item(d);
				cout << "������� ����������?(��� ������ ������� - �): "; cin >> c;
				cout << endl;
			} while (c != '�');
			system("cls");
			cout << "��� �������� 1 �������: " << endl;
			q1->display(); cout << endl;
			cout << "��� �������� 2 �������: " << endl;
			temp->display(); cout << endl;
			res->merge(q1, temp);
			cout << "��� �������� 3 �������, ����� ���������� 1 � 2 ��������: " << endl;
			res->display();
			delete res;
			delete temp;
			system("pause");
			system("cls");
			break;
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
}