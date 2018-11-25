#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include "Print_queue.h"
using namespace std;


Print_queue::Print_queue(int m)
{
	//получаем размер
	MaxQueueLength = m;
	//создаем очередь
	Wait = new int[MaxQueueLength];
	print_time = new char*[MaxQueueLength];
	for (int i = 0; i < MaxQueueLength; i++) {
		print_time[i] = new char[128];
	}
	//»значально очередь пуста
	QueueLength = 0;
}

Print_queue::~Print_queue()
{
	//удаление очереди
	delete[]Wait;
	for (int i = 0; i < MaxQueueLength; i++) {
		delete[]print_time[i];
	}
	delete[]print_time;
}

void Print_queue::Add(int c)
{
	// ≈сли в очереди есть свободное место,
	// то увеличиваем количество
	// значений и вставл€ем новый элемент
	if (!IsFull())
	{
		Wait[QueueLength] = c;
		lt = time(NULL);
		ptr = localtime(&lt);
		strcpy_s (print_time[QueueLength], strlen(asctime(ptr))+1, asctime(ptr));
		QueueLength++;
	}
}

void Print_queue::Extract_Show()
{
	//≈сли в очереди есть элементы, то возвращаем тот,
	//у которого наивысший приоритет и сдвигаем очередь
	int n = 1;// пор€дковый номер печати
	while (!IsEmpty())
	{
		//пусть приоритетный элемент - нулевой
		int max_pri = Wait[0];
		//а приоритетный индекс = 0
		int pos_max_pri = 0;
		//ищем приоритет
		for (int i = 1; i<QueueLength; i++)
			//если встречен более приоритетный элемент
			if (max_pri>Wait[i])
			{
				max_pri = Wait[i];
				pos_max_pri = i;
			}
		//печатаем приоритетный элемент
		cout << n++ << ". " << co_worker[Wait[pos_max_pri]] << " \t" << print_time[pos_max_pri];
		//сдвинуть все элементы
		for (int i = pos_max_pri; i<QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			strcpy_s(print_time[i], strlen(print_time[i+1])+1, print_time[i + 1]);
		}
		//уменьшаем количество
		QueueLength--;
	}
}

bool Print_queue::IsEmpty()
{
	//ѕуста€?
	return QueueLength == 0;
}

bool Print_queue::IsFull()
{
	//ѕолна€?
	return QueueLength == MaxQueueLength;
}

int Print_queue::GetCount()
{
	// оличество присутствующих в стеке элементов
	return QueueLength;
}

char *Print_queue::Get_co_worker(int n)
{
	return co_worker[n];
}
