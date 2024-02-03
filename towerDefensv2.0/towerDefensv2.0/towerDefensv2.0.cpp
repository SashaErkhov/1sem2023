#include <iostream>

int main()
{
	using ull = unsigned long long int;
	ull smallroom=2;//наименьшая комната в квадрате
	ull smallfloor=1;//наименьшый этаж в квадрате
	ull bigfloor=1;//наибольшый этаж в квадрате
	ull room;//комната-ввод

	std::cin >> room;

	if (room == 1)
	{
		std::cout << "1 1";
		return 0;
	}
	for (ull i = 2; i != 0xffffffffffffffff; ++i)
	{
		smallfloor = bigfloor + 1;
		bigfloor += i;
		if (smallroom + i * i - 1 < smallroom)//При переполнении я вывожу этот квадрат
			//т.к. по условию задачи комната не может быть больше чем 2 в 64
		{
			ull floor = (room - smallroom) / i + smallfloor;
			std::cout << floor << ' ' << room - (smallroom + (floor - smallfloor) * i) + 1;
			return 0;
		}
		if (smallroom <= room and room <= (smallroom + i * i - 1))
		{
			ull floor = (room - smallroom) / i + smallfloor;
			std::cout << floor << ' ' << room - (smallroom + (floor-smallfloor) * i) + 1;
			return 0;
		}
		smallroom += i*i;//К следующему i
	}
	return 0;
}