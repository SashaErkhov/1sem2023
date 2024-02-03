#include <iostream>
#include <cmath>

int main()
{
	unsigned long long int r;//Radius
	std::cin >> r;
	unsigned long long int powr2 = r * r;
	unsigned long long int count = 0;
	for (long long int i = 0; i != r;++i)//брутфорс прямых || Ох
	{
		count += unsigned long long int(sqrtl(powr2 - i * i));
	}
	count = 4 * count + 1;
	std::cout << count;
	return 0;
}