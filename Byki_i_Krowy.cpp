#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <time.h>
using namespace std;

int main()
{
	srand(time(NULL));
	int const iCount = 5; // ���������� ���������
	int x;
	cout << "\n\n\t\tEnter end of range:\n";
	cin >> x;

	int r;
	// ������� �
	cout << "\t\tIN\n\n";
	for (int i = 0; i < iCount; i++){
		r = rand() % (x + 1); // ���������
		cout << "RAND - " << r << "\n\n";
	}
	// �������� �
	cout << "\t\tOUT\n\n";
	for (int i = 0; i < iCount; i++){
		r = rand() % x; // ���������
		cout << "RAND - " << r << "\n\n";
	}
//	srand(time(NULL));
//
//	int ar[4];
//	for (int i = 0; i < 5; i++)
//	{
//		ar[i] = 5+i;
//		//while (ar [i-1] == ar[i] || ar[0] == 0)
//		//	ar[i] = rand() % 1;
//		cout << ar[i];
//	}
//	//for (int j = 0; j < 5; j++)
//	//{
//	//	cout << ar[j];
//	//}
	return 0;
}