#pragma once
#include <iostream>

using namespace std;

const int SIZE = 128;

class THashRecord
{
public:
	int key; // ключ
	int Data; //данные
	THashRecord* next; // указатель на слеудующую запись
	THashRecord (int key, int Data)
	{
		this->key = key;
		this->Data = Data;
		this->next = NULL;
	}
};

class THashTable
{
private:
	THashRecord ** htable;
public:
	THashTable()
	{
		htable = new THashRecord*[SIZE];
		for (int i = 0; i < SIZE; i++)
			htable[i] = NULL;
	}
	~THashTable()
	{
		for (int i = 0; i < SIZE; ++i)
		{
			THashRecord* entry = htable[i];
			while (entry != NULL)
			{
				THashRecord* prev = entry;
				entry = entry->next;
				delete prev;
			}
		}
		delete[] htable;
	}
	
	int HashFunc(int key) 
	{
		return key % SIZE;
	}

	
	void AddRecord(int key, int Data)
	{
		int hash_val = HashFunc(key);
		THashRecord* prev = NULL;
		THashRecord* entry = htable[hash_val];
		while (entry != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (entry == NULL)
		{
			entry = new THashRecord(key, Data);
			if (prev == NULL)
			{
				htable[hash_val] = entry;
			}
			else
			{
				prev->next = entry;
			}
		}
		else
		{
			entry->Data = Data;
		}
	}

	void DelRecord(int key)
	{
		int hash_val = HashFunc(key);
		THashRecord* entry = htable[hash_val];
		THashRecord* prev = NULL;
		cout << endl<<"key=";
		if (entry == NULL)
		
		{
			cout  << key << " не найден" << endl;
			return;
		}
		else
		{
			if (entry->key != key)
			{
				cout << key << " не найден" << endl;
				return;
			}
		}
		while (entry->next != NULL)
		{
			prev = entry;
			entry = entry->next;
		}
		if (prev != NULL)
		{
			prev->next = entry->next;
		}
		delete entry;
		cout <<key<< " удален" << endl;
		htable[hash_val] = NULL;
	}
	
	int Search(int key)

	{
		bool flag = false;
		int hash_val = HashFunc(key);
		THashRecord* entry = htable[hash_val];
		cout << "key="<<key<<": ";
		while (entry != NULL)
		{
			
			if (entry->key == key)
			{
				cout <<entry->Data << " ";
				flag = true;
			}
			entry = entry->next;
		}

		if (!flag)
		{
			cout << "не найден" << endl;
			return -1;

		}
	}
};
