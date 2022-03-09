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
			cout << "1 Ц ƒобавление элемента очереди\n"
				<< "2 Ц »звлечение элемента очереди\n"
				<< "3 Ц ¬ывод очереди на экран\n"
				<< "4 Ц  оличество элементов очереди больших "
				<< "среднего арифметического\n"
				<< "5 Ц —оздание копии очереди\n"
				<< "6 Ц —ли€ние двух очередей\n" 
				<< "7 Ц ¬ыход из программы\n";
			choice = input<int>();

			switch (choice)
			{
			case 1:
			{
				system("cls");
				cout << "¬ведите добавл€емый элемент\n";
				int var = input<int>();
				q1->add_item(var);
				system("cls");
				cout << "Ёлемент " << var << " успешно добавлен в очередь.\n\n";
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
				cout << "Ёлементы текущей очереди:" << endl;
				q1->display(); cout << endl;
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
				if (q1->return_size_of_queue())
				{
					queue_template* copy1 = new queue_template;
					copy1->copy(q1);
					cout << "ќчередь скопирована в другой объект этого класса." << endl
						<< "Ёлементы скопированной очереди:" << endl;
					copy1->display(); cout << endl;
					delete copy1;
				}
				else
				{
					throw(std::string("¬ используемой очереди нет элементов, дл€ копировани€ в другую очередь!\n"));
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
						cout << "¬ведите несколько элементов дл€ добавлени€ во 2 очередь, "
							<< "с которой будет произведено сли€ние\n";
						d = input<int>();
						temp->add_item(d);
						cout << "∆елаете продолжить?(дл€ выхода введите - н)\n"; 
						c = input<char>(); cout << endl;
					} while (c != 'н');

					system("cls");
					cout << "Ёто элементы 1 очереди: " << endl;
					q1->display(); cout << endl;
					cout << "Ёто элементы 2 очереди: " << endl;
					temp->display(); cout << endl;
					res->merge(q1, temp);
					cout << "Ёто элементы 3 очереди, после смешивани€ 1 и 2 очередей: " << endl;
					res->display(); cout << endl;
					delete res;
					delete temp;
				}
				else
				{
					throw(std::string("¬ используемой очереди нет элементов, дл€ сли€ни€ с другой очередью!\n"));
				}
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
		catch (std::string& ex)
		{
			cout << ex << std::endl;
			system("pause");
			system("cls");
		}
	}
}