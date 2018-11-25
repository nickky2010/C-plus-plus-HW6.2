#define _CRT_SECURE_NO_WARNINGS
#include <windows.h>
#include <iostream>
#include <string.h>
#include <time.h>
#include "Print_queue.h"
using namespace std;


Print_queue::Print_queue(int m)
{
	//�������� ������
	MaxQueueLength = m;
	//������� �������
	Wait = new int[MaxQueueLength];
	print_time = new char*[MaxQueueLength];
	for (int i = 0; i < MaxQueueLength; i++) {
		print_time[i] = new char[128];
	}
	//���������� ������� �����
	QueueLength = 0;
}

Print_queue::~Print_queue()
{
	//�������� �������
	delete[]Wait;
	for (int i = 0; i < MaxQueueLength; i++) {
		delete[]print_time[i];
	}
	delete[]print_time;
}

void Print_queue::Add(int c)
{
	// ���� � ������� ���� ��������� �����,
	// �� ����������� ����������
	// �������� � ��������� ����� �������
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
	//���� � ������� ���� ��������, �� ���������� ���,
	//� �������� ��������� ��������� � �������� �������
	int n = 1;// ���������� ����� ������
	while (!IsEmpty())
	{
		//����� ������������ ������� - �������
		int max_pri = Wait[0];
		//� ������������ ������ = 0
		int pos_max_pri = 0;
		//���� ���������
		for (int i = 1; i<QueueLength; i++)
			//���� �������� ����� ������������ �������
			if (max_pri>Wait[i])
			{
				max_pri = Wait[i];
				pos_max_pri = i;
			}
		//�������� ������������ �������
		cout << n++ << ". " << co_worker[Wait[pos_max_pri]] << " \t" << print_time[pos_max_pri];
		//�������� ��� ��������
		for (int i = pos_max_pri; i<QueueLength - 1; i++)
		{
			Wait[i] = Wait[i + 1];
			strcpy_s(print_time[i], strlen(print_time[i+1])+1, print_time[i + 1]);
		}
		//��������� ����������
		QueueLength--;
	}
}

bool Print_queue::IsEmpty()
{
	//������?
	return QueueLength == 0;
}

bool Print_queue::IsFull()
{
	//������?
	return QueueLength == MaxQueueLength;
}

int Print_queue::GetCount()
{
	//���������� �������������� � ����� ���������
	return QueueLength;
}

char *Print_queue::Get_co_worker(int n)
{
	return co_worker[n];
}
