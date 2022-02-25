#include "daughter1.h"
#include <iostream>

int queue1::count_bigger_avereage() const
{
	Element* temp = queue::return_last();
	if (temp == nullptr)
	{
		std::cout << "Ќет элементов!";
		return 0;
	}
	int count = 0;
	while(temp)
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
	Element* temp = q2->return_last();
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

void queue1::merge(queue1* q1, queue1* q2)
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

void variety(queue1* q1)
{
	using std::cout;
	using std::endl;
	using std::cin;
	system("cls");
	int choice;
	while (1)
	{
		cout << "1 Ц ƒобавление элемента очереди" << endl
			<< "2 Ц »звлечение элемента очереди" << endl
			<< "3 Ц ¬ывод очереди на экран" << endl
			<< "4 Ц  оличество элементов очереди больших, "
			<< "среднего арифметического" << endl
			<< "5 Ц —оздание копии очереди" << endl
			<< "6 Ц —ли€ние двух очередей" << endl
			<< "7 Ц ¬ыход из программы" << endl;
		cout << "¬ведите цифру: "; cin >> choice;
		queue1* temp = new queue1;
		queue1* res = new queue1;
		queue1* copy1 = new queue1;
		switch (choice)
		{
		case 1:
			system("cls");
			int var;
			cout << "¬ведите добавл€емый элемент: "; cin >> var;
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
			cout << "Ёлементы текущей очереди:" << endl;
			q1->display();
			system("pause");
			system("cls");
			break;
		case 4:
			system("cls");
			cout << " оличество элементов больших среднего арифметического: "
				<< q1->count_bigger_avereage() << endl;
			system("pause");
			system("cls");
			break;
		case 5:
			system("cls");
			copy1->copy(q1);
			cout << "ќчередь скопирована в другой объект этого класса." << endl
				<< "Ёлементы скопированной очереди:" << endl;
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
				cout << "¬ведите несколько элементов дл€ добавлени€ во 2 очередь,\n"
					<< "с которой будет произведено сли€ние текущей очереди в 3 очередь: ";
				cin >> d;
				temp->add_item(d);
				cout << "∆елаете продолжить?(дл€ выхода введите - н): "; cin >> c;
				cout << endl;
			} while (c != 'н');
			system("cls");
			cout << "Ёто элементы 1 очереди: " << endl;
			q1->display(); cout << endl;
			cout << "Ёто элементы 2 очереди: " << endl;
			temp->display(); cout << endl;
			res->merge(q1, temp);
			cout << "Ёто элементы 3 очереди, после смешивани€ 1 и 2 очередей: " << endl;
			res->display();
			delete res;
			delete temp;
			system("pause");
			system("cls");
			break;
		case 7:
			system("cls");
			cout << "«авершение работы.." << endl;
			delete q1;
			cout << endl;
			exit(1);
		default:
			system("cls");
			cout << "¬ведена неверна€ команда!" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
}