#include "student.h"
#include "utils.h"

std::ostream& operator<<(std::ostream& out, const student& st)
{
	out << "st" << st.number << ". "
		<< st.surname << " " << st.name << ": ";
	const char marks[] = "-FEDCBA";
	for (int i = 0; i < marksCount; ++i)
	{
		out << ' ' << marks[st.marks[i] % 7];
	}
	return out;
}

std::istream& operator>>(std::istream& in, student& st)
{
	std::cout << "Student number: ";
	st.number = getInt(in);
	std::cout << "Surname: ";
	in.getline(st.surname, 32);
	std::cout << "Name: ";
	in.getline(st.name, 16);
	for (int i = 0; i < marksCount; ++i)
	{
		st.marks[i] = 0;
	}
}

bool compareByNomber(const student& left, const student& right)
{
	return left.number < left.number;
}

bool compareBySurname(const student& left, const student& right)
{
	int result = strcmp(left.surname, right.surname);
	if (result < 0)
	{
		return true;
	}
	if (result == 0)
	{
		return strcmp(left.name, right.name)<0;
	}
	return false;
}

double averageMarks(const unsigned char* marks, int size)
{
	int cnt = 0;
	double res = 0;
	for (int i = 0; i < size; ++i)
	{
		if (marks[i] > 0)
		{
			res += marks[i];
			++cnt;
		}
	}
	return (cnt > 0)? res / double(cnt) : 0.0;
}

bool compareByMarks(const student& left, const student& right)
{
	return averageMarks(left.marks, marksCount) >
		averageMarks(right.marks, marksCount);
}