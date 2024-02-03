#include <iostream>

struct A
{
	unsigned char x: 3;
	unsigned char : 1;
	unsigned char y: 4;
};

void print(const A& a)
{
	std::cout << (int)a.x << ", " << (int)a.y << std::endl;
}

struct Byte
{
	unsigned char a0 : 1;
	unsigned char a1 : 1;
	unsigned char a2 : 1;
	unsigned char a3 : 1;
	unsigned char a4 : 1;
	unsigned char a5 : 1;
	unsigned char a6 : 1;
	unsigned char a7 : 1;
};

union number1
{
	unsigned char x;
	Byte y;
};

void print(const number1& a)
{
	std::cout << int(a.x) << ": ";
	std::cout << (int)a.y.a0;
	std::cout << (int)a.y.a1;
	std::cout << (int)a.y.a2;
	std::cout << (int)a.y.a3;
	std::cout << (int)a.y.a4;
	std::cout << (int)a.y.a5;
	std::cout << (int)a.y.a6;
	std::cout << (int)a.y.a7<<std::endl;
}

int main()
{
	number1 w;
	w.x = 75;
	print(w);
	w.y.a7 = 1;
	print(w);
	/*A a;
	std::cout << sizeof(a)<<std::endl;
	a.x = 12;
	a.y = 25;
	print(a);*/
	return 0;
}