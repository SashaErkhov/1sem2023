#ifndef _ST_DATABASE_2023_
#define _ST_DATABASE_2023_
#include "student.h"

struct Node
{
	student data;
	Node* next;
};

struct DataBase
{
	int count;
	Node* begin;
	Node* end; //не обязательно для списка
	//Сделали, чтобы иметь возможность быстрого добавления в конец списка
};

void deleteDB(DataBase& DB);
void printDB(const DataBase&);
int addRecord(DataBase&);
void saveDB(const DataBase& DB, const char filename[]);
int openDB(DataBase& DB, const char filename[]);
void exportDB(const DataBase& DB, const char filename[]);
Node* findRecord(const DataBase& DB);
void setMarks(const DataBase& DB);
void deleteRecord(DataBase& DB);
void sort(DataBase& DB);

#endif //_ST_DATABASE_2023_