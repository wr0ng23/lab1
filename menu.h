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
		try
		{
			cout << "1 – Добавление элемента очереди" << endl
				<< "2 – Извлечение элемента очереди" << endl
				<< "3 – Вывод очереди на экран" << endl
				<< "4 – Количество элементов очереди больших, "
				<< "среднего арифметического" << endl
				<< "5 – Создание копии очереди" << endl
				<< "6 – Слияние двух очередей" << endl
				<< "7 – Выход из программы" << endl;
			cout << "Введите цифру: "; cin >> choice;
			switch (choice)
			{
			case 1:
				system("cls");
				int var;
				cout << "Введите добавляемый элемент: "; cin >> var;
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
				cout << "Элементы текущей очереди:" << endl;
				q1->display();
				system("pause");
				system("cls");
				break;
			case 4:
				system("cls");
				cout << "Количество элементов больших среднего арифметического: "
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
					cout << "Очередь скопирована в другой объект этого класса." << endl
						<< "Элементы скопированной очереди:" << endl;
					copy1->display();
					delete copy1;
				}
				else 
					throw(std::string("В используемой очереди нет элементов, для копирования в другую очередь!"));
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
						cout << "Введите несколько элементов для добавления во 2 очередь,\n"
							<< "с которой будет произведено слияние: ";
						cin >> d;
						temp->add_item(d);
						cout << "Желаете продолжить?(для выхода введите - н): "; cin >> c;
						cout << endl;
					} while (c != 'н');

					system("cls");
					cout << "Это элементы 1 очереди: " << endl;
					q1->display(); cout << endl;
					cout << "Это элементы 2 очереди: " << endl;
					temp->display(); cout << endl;
					res->merge(q1, temp);
					cout << "Это элементы 3 очереди, после смешивания 1 и 2 очередей: " << endl;
					res->display();
					delete res;
					delete temp;
				}
				else
					throw(std::string("В используемой очереди нет элементов, для слияния с другой очередью!"));
				system("pause");
				system("cls");
				break;
			}
			case 7:
				system("cls");
				cout << "Завершение работы.." << endl;
				delete q1;
				cout << endl;
				exit(1);
			default:
				system("cls");
				cout << "Введена неверная команда!" << endl;
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