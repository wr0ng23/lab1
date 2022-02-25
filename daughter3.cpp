#include "daughter3.h"

int queue3::count_bigger_avereage() const
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

void variety(queue3* q1)
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
		queue3* temp = new queue3;
		queue3* res = new queue3;
		queue3* copy1 = new queue3;
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