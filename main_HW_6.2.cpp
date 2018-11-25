//                                   Курс.Объектно - ориентированное программирование на C++.
//                                           Модуль 6. Динамические структуры данных.
//                                                   Домашнее задание № 1.
// Разработать приложение, имитирующее очередь печати принтера. 
// Должны быть клиенты, посылающие запросы на принтер, у каждого из которых есть свой приоритет.
// Каждый новый клиент попадает в очередь в зависимости от своего приоритета.
// Необходимо сохранять статистику печати(пользователь, время) в отдельной очереди. Предусмотреть вывод статистики на экран.

#include <iostream>
#include <Windows.h>
#include <time.h>
#include "Print_queue.h"
using namespace std;
void check_inter(int vyb, int min, int max);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	Print_queue P(20);
	int vyb = 0;
	do {
		do {
			system("cls");
			cout << "Выберите отправителя на печать\n";
			cout << "1 - директор\n";
			cout << "2 - бухгалтер\n";
			cout << "3 - секретарь\n";
			cout << "4 - начальник\n";
			cout << "5 - инженер\n";
			cout << "0 - для вывода статистики на экран\n";
			cout << "Ваш выбор: ";
			cin >> vyb;
			check_inter(vyb, 0, 5);
		} while (vyb < 0 || vyb>5);
		if (vyb == 1) P.Add(0);
		else if (vyb == 2) P.Add(1);
		else if (vyb == 3) P.Add(2);
		else if (vyb == 4) P.Add(3);
		else if (vyb == 5) P.Add(4);
		else if (vyb == 0) {
			system("cls");
			cout << "\t\tОчередь печати:\n\n";
			P.Extract_Show();
		}
		if (vyb) {
			cout << P.Get_co_worker(vyb - 1) << " отправил на печать успешно!\n\n";
			system("pause");
		}
	} while (vyb!=0 && !P.IsFull());
	cout << "\n";
	system("pause");
	return 0;
}

void check_inter(int vyb, int min, int max)
{
	if (vyb < min || vyb>max) {
		if (vyb < min) cout << "Неверно! Согласно списка отправитель не может быть менее " << min << " !\n";
		else if (vyb > max) cout << "Неверно! Согласно списка отправитель не может быть более " << max << " !\n";
		cout << "Повторите ввод!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}