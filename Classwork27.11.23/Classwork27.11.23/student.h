#ifndef _STUDENT_2023_
#define _STUDENT_2023_
#include <iostream>

const int marksCount = 5;

struct student
{
	int number;
	char surname[32];
	char name[16];
	unsigned char marks[marksCount];
};

std::ostream& operator<<(std::ostream& out, const student& st);
std::istream& operator>>(std::istream& in, const student& st);
bool compareByNomber(const student& left, const student& right);
bool compareBySurname(const student& left, const student& right);
bool compareByMarks(const student& left, const student& right);



#endif //_STUDENT_2023_