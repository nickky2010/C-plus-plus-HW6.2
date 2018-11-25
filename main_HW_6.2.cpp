//                                   ����.�������� - ��������������� ���������������� �� C++.
//                                           ������ 6. ������������ ��������� ������.
//                                                   �������� ������� � 1.
// ����������� ����������, ����������� ������� ������ ��������. 
// ������ ���� �������, ���������� ������� �� �������, � ������� �� ������� ���� ���� ���������.
// ������ ����� ������ �������� � ������� � ����������� �� ������ ����������.
// ���������� ��������� ���������� ������(������������, �����) � ��������� �������. ������������� ����� ���������� �� �����.

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
			cout << "�������� ����������� �� ������\n";
			cout << "1 - ��������\n";
			cout << "2 - ���������\n";
			cout << "3 - ���������\n";
			cout << "4 - ���������\n";
			cout << "5 - �������\n";
			cout << "0 - ��� ������ ���������� �� �����\n";
			cout << "��� �����: ";
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
			cout << "\t\t������� ������:\n\n";
			P.Extract_Show();
		}
		if (vyb) {
			cout << P.Get_co_worker(vyb - 1) << " �������� �� ������ �������!\n\n";
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
		if (vyb < min) cout << "�������! �������� ������ ����������� �� ����� ���� ����� " << min << " !\n";
		else if (vyb > max) cout << "�������! �������� ������ ����������� �� ����� ���� ����� " << max << " !\n";
		cout << "��������� ����!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}