#include <iostream>
#include <conio.h>
#include "HashTable.h"

using namespace std;

int main() 
{
	setlocale(LC_ALL, "Russian");
	THashTable table1;

	table1.AddRecord(2, 20);
	table1.AddRecord(2, 212);
	table1.AddRecord(1, 22);
	table1.AddRecord(2, 0);
	table1.AddRecord(3, 89);
	table1.Search(1); 
	cout << endl;
	table1.DelRecord(1);
	cout << endl;
	table1.Search(2);
	cout << endl;
	table1.Search(7);
	table1.Search(3);
	table1.DelRecord(7);
	

	_getch();
	return 0;
}