#include <iostream>
#include <cstring>
#include "foos"//функции - шаблоны

void printer(unsigned long long int s)//Вывод кадра
{
	std::string kadr=tran10to2(s);
	for (size_t i = 0; i != 64; i+=8)
	{
		std::cout << kadr[i] << ' ';
		std::cout << kadr[i+1] << ' ';
		std::cout << kadr[i+2] << ' ';
		std::cout << kadr[i+3] << ' ';
		std::cout << kadr[i+4] << ' ';
		std::cout << kadr[i+5] << ' ';
		std::cout << kadr[i+6] << ' ';
		std::cout << kadr[i+7] << ' '<<std::endl;
	}
}