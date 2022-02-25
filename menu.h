#pragma once

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
		cout << "1 � ���������� �������� �������" << endl
			<< "2 � ���������� �������� �������" << endl
			<< "3 � ����� ������� �� �����" << endl
			<< "4 � ���������� ��������� ������� �������, "
			<< "�������� ���������������" << endl
			<< "5 � �������� ����� �������" << endl
			<< "6 � ������� ���� ��������" << endl
			<< "7 � ����� �� ���������" << endl;
		cout << "������� �����: "; cin >> choice;
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
		{
			system("cls");
			queue_template* copy1 = new queue_template;
			copy1->copy(q1);
			cout << "������� ����������� � ������ ������ ����� ������." << endl
				<< "�������� ������������� �������:" << endl;
			copy1->display();
			delete copy1;
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			system("cls");
			int d;
			char c;
			queue_template* temp = new queue_template;
			queue_template* res = new queue_template;
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
}