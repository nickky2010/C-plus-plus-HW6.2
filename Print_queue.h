#pragma once
class Print_queue 
{
private:
	struct tm *ptr;
	time_t lt;
	char* co_worker[5] = { (char*)"��������", (char*)"���������", (char*)"���������", (char*)"���������", (char*)"�������" };
	//�������
	int * Wait;
	// �����
	char ** print_time;
	//������������ ������ �������
	int MaxQueueLength;
	//������� ������ �������
	int QueueLength;
public:
	//�����������
	Print_queue(int m);
	//����������
	~Print_queue();
	//���������� ��������
	void Add(int c);
	//���������� � ������ ��������
	void Extract_Show();
	//�������� ������������� ��������� � �������
	bool IsEmpty();
	//�������� �� ������������ �������
	bool IsFull();
	//���������� ��������� � �������
	int GetCount();
	// ��� ������ �� ������
	char *Get_co_worker(int n);
};
