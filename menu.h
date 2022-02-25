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
		cout << "1 Ц ƒобавление элемента очереди" << endl
			<< "2 Ц »звлечение элемента очереди" << endl
			<< "3 Ц ¬ывод очереди на экран" << endl
			<< "4 Ц  оличество элементов очереди больших, "
			<< "среднего арифметического" << endl
			<< "5 Ц —оздание копии очереди" << endl
			<< "6 Ц —ли€ние двух очередей" << endl
			<< "7 Ц ¬ыход из программы" << endl;
		cout << "¬ведите цифру: "; cin >> choice;
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
		{
			system("cls");
			queue_template* copy1 = new queue_template;
			copy1->copy(q1);
			cout << "ќчередь скопирована в другой объект этого класса." << endl
				<< "Ёлементы скопированной очереди:" << endl;
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
		}
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