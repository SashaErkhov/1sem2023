#include <iostream>
#include <ctime>
#include <cstring>
#include "foos.h"
#include "foos"//шаблоны
//#define DEBUG

#ifdef DEBUG

void tester()
{
	std::cout << tran10to2(0) << std::endl;
	std::cout << tran10to2(1) << std::endl;
	std::cout << tran10to2(2) << std::endl;
	std::cout << tran10to2(8) << std::endl;
	std::cout << tran10to2(0xffffffffffffffff) << std::endl;
	for (int i = 0; i != 10; ++i)
	{
		std::cout << 8 * i << ' ' << tran10to2(8 * i) << std::endl;
	}
}

#endif // DEBUG


int main()
{
#ifdef DEBUG

	tester();
	return 0;

#endif // DEBUG

	std::cout << "len = ";
	int len;
	std::cin >> len;
	std::cout << std::endl;
	unsigned long long int *N = new unsigned long long int [len];
	srand(time(0));
	std::system("cls");
	std::system("clear");
	for (size_t i = 0; i != len; ++i)
	{
		N[i] = rand()*8;//Массив целых чисел кратных восьми
		printer(N[i]);
		std::system("cls");
		std::system("clear");
	}
	delete[] N;
	return 0;
}