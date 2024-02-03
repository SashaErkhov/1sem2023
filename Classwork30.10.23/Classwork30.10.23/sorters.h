#ifndef SORTERS
#define SORTERS

template <typename T>
void Bubblesort(T M[], int size)//—ортировка пузырьком
{
#ifdef DEBUG//“акое же можно на ChooseSort
	clock_t ticktok = clock();
	unsigned long long countLess = 0;
	unsigned long long countEq = 0;
#endif // DEBUG



	for (int step = 1; step < size; ++step)
	{
		bool isSorted = true;
		for (int i = size - 1; i >= step; --i)
		{
#ifdef DEBUG
			++countLess;
#endif // DEBUG

			if (M[i] < M[i - 1])
			{
#ifdef DEBUG
				countEq += 3;
#endif // DEBUG

				std::swap(M[i], M[i - 1]);
				isSorted = false;
			}
		}
		if (isSorted)
		{
			break;
		}
	}
#ifdef DEBUG
	ticktok = clock() - ticktok;
	std::cout << "<" << countLess;
	std::cout << "=" << countEq;
	std::cout << ">" << ticktok << std::endl;
#endif // DEBUG

}
template <typename T>
void ChooseSort(T M[], int size)
{
	//сюда можно добавить тестер, как и в BubbleSort
	for (int step = 0; step < size; ++step)
	{
		int minIndex = step;
		for (int i = minIndex + 1; i < size; ++i)
		{
			if (M[i] < M[minIndex])
			{
				minIndex = i;
			}
		}
		if (step < minIndex)
		{
			std::swap(M[step], M[minIndex]);
		}
	}
}



#endif // !SORTERS