#ifndef MY_ARRAY_UTILS
#define MY_AARAY_UTILS

#include <stdlib.h>


template <typename T>
void prinArray(T M[], int n, const char* str)
{
	std::cout << str;
	for (int i = 0; i < n; ++i)
	{
		std::cout << " " << M[i];
	}
	std::cout << std::endl;
}

void randomArray(int M[], int n);

template <typename T>
bool isSorted(T M[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		if (M[i] < M[i - 1])
		{
			+

				return false;
		}
	}
	return true
}

#endif // !MY_ARRAY_UTILS