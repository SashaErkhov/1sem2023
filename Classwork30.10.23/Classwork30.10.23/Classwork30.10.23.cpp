//Сортировка решений

#include <iostream>
#define DEBUG
#include "sorters.h"
#include "arrayutils.h"

//Возмножно у меня все сломается, но пример будет в лмс( наверное)

void sortArray(void(*sorter)(int[],int), int A[], int size, const char* arrayname)
{
	std::cout << "--Array: " << arrayname << std::endl;
	if (size < 25)
	{
		prinArray(A, size, "Before ");
	}
	sorter(A, size);
	if (size < 25) prinArray(A, size, "After ");
	if (!isSorted(A,size))
	{
		std::cout << "Error: not sorted" << std::endl;
	}
}

int main()
{
	const int N = 10;
	int M[N];
	randomArray(M, N);
	sortArray(Bubblesort, M, N, "Random");
	sortArray(ChooseSort, M, N, "pass");//в тот раз не успел
	return 0;
}