#include <iostream>




int main()
{

	using ForGitHub = unsigned long long int;
	ForGitHub room;//Номер комнаты
	ForGitHub smallFloor = 1;
	ForGitHub bigFloor = 1;
	ForGitHub small=1;
	ForGitHub big=1;
	ForGitHub i;
	ForGitHub j;
	
	std::cin >> room;


	if (room == 1)
	{
		std::cout << "1 1";
		return 0;
	}
	bool ok = true;
	for ( i = 2; i != 0xffffffffffffffff; ++i)
	{
		smallFloor += i - 1;
		bigFloor = smallFloor + i - 1;
		small = (i*(i-1)*(2*i-1))/6+1;//big + 1;
		//big = small+i-1;
		for (j = (smallFloor); j != (bigFloor + 1); ++j)
		{
			if (small <= room and room <= (small+i-1))
			{
				std::cout << j << " " << room - small + 1;
				ok = false;
				break;
			}
			if (j != bigFloor)
			{
				small += i;
				//big += mmmmi;
			}
		}
		if (!ok)
		{
			break;
		}
	}
	return 0;
}