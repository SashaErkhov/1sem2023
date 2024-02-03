#include "arrayutils.h"


void randomArray(int M[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		M[i] = rand() % 9000 + 1000;
	}
}