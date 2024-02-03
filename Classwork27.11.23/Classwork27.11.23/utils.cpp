#include "utils.h"

int getInt(std::istream& in)
{
	int tmp = 0;
	in >> tmp;
	if (!std::cin.good())
	{
		in.clear();
		tmp = 0;
	}
	in.ignore();
	return tmp;
}