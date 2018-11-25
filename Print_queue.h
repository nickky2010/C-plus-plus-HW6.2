#pragma once
class Print_queue 
{
private:
	struct tm *ptr;
	time_t lt;
	char* co_worker[5] = { (char*)"Директор", (char*)"Бухгалтер", (char*)"Секретарь", (char*)"Начальник", (char*)"Инженер" };
	//Очередь
	int * Wait;
	// Время
	char ** print_time;
	//Максимальный размер очереди
	int MaxQueueLength;
	//Текущий размер очереди
	int QueueLength;
public:
	//Конструктор
	Print_queue(int m);
	//Деструктор
	~Print_queue();
	//Добавление элемента
	void Add(int c);
	//Извлечение и печать элемента
	void Extract_Show();
	//Проверка существования элементов в очереди
	bool IsEmpty();
	//Проверка на переполнение очереди
	bool IsFull();
	//Количество элементов в очереди
	int GetCount();
	// кто послал на печать
	char *Get_co_worker(int n);
};
