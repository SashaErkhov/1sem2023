#include <iostream>

union bytecod
{
	unsigned char x;
	struct
	{
		unsigned char a0 : 1;
		unsigned char a1 : 1;
		unsigned char a2 : 1;
		unsigned char a3 : 1;
		unsigned char a4 : 1;
		unsigned char a5 : 1;
		unsigned char a6 : 1;
		unsigned char a7 : 1;
	}byte;
};

std::ostream& operator<<(std::ostream& out, const bytecod& B)
{
	out << (int)B.byte.a7;
	out << (int)B.byte.a7;
	out << (int)B.byte.a6;
	out << (int)B.byte.a5;
	out << (int)B.byte.a4;
	out << (int)B.byte.a3;
	out << (int)B.byte.a2;
	out << (int)B.byte.a1;
	out << (int)B.byte.a0;
	return out;
}

union code32
{
	int x;
	bytecod b[4];
};

union codDouble
{
	double d;
	code32 x[2];
};

std::ostream& operator<<(std::ostream& out, const code32& C)
{
	out << C.x << ": ";
	for (int i = 3; i >=0; --i)
	{
		out << (int)C.b[i].x << ".";
	}
	out << ": ";
	for (int i = 3; i >= 0; --i)
	{
		out << C.b[i] << ".";
	}
	return out;
}

int main()
{
	bytecod S;
	for (S.x = 0; S.x < 32; ++S.x)
	{
		std::cout <<(int)S.x<< S.x<<": "<< S << std::endl;
	}
	code32 C;
	for (C.x = 0; C.x < 3200; C.x += 100)
	{
		std::cout << C << std::endl;
	}
	return 0;
}