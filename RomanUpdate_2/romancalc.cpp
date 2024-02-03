#include <iostream>
#include <fstream>

template <typename T>
T* adder(const T* Input, int* len, T New)
{
	T* tmp = new T[(*len) + 1];
	for (int i = 0; i < (*len); ++i)
	{
		tmp[i] = Input[i];
	}
	tmp[(*len)] = New;
	++(*len);
	delete[]Input;
	return tmp;
}

char* inRuman(const char* Input, int* len)
{
	int count = (*len);
	int midle;
	int lenTmp = 0;
	char* tmp = new char[lenTmp];
	int size = (*len);
	for (int i = 0; i != size; ++i)
	{
		midle = Input[i] - '0';
		if (count == 4)
		{
			for (int i = 0; i != midle; ++i)
			{
				tmp = adder(tmp, &lenTmp, 'M');
			}
		}
		else if (count == 3)
		{
			if (midle == 9)
			{
				tmp = adder(tmp, &lenTmp, 'C');
				tmp = adder(tmp, &lenTmp, 'M');
			}
			else if (midle > 4)
			{
				tmp = adder(tmp, &lenTmp, 'D');
				int size = midle - 5;
				for (int i = 0; i != size; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'C');
				}
			}
			else if (midle == 4)
			{
				tmp = adder(tmp, &lenTmp, 'C');
				tmp = adder(tmp, &lenTmp, 'D');
			}
			else
			{
				for (int i = 0; i != midle; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'C');
				}
			}
		}
		else if (count == 2)
		{
			if (midle == 9)
			{
				tmp = adder(tmp, &lenTmp, 'X');
				tmp = adder(tmp, &lenTmp, 'C');
			}
			else if (midle > 4)
			{
				tmp = adder(tmp, &lenTmp, 'L');
				int size = midle - 5;
				for (int i = 0; i != size; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'X');
				}
			}
			else if (midle == 4)
			{
				tmp = adder(tmp, &lenTmp, 'X');
				tmp = adder(tmp, &lenTmp, 'L');
			}
			else
			{
				for (int i = 0; i != midle; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'X');
				}
			}
		}
		else if (count == 1)
		{
			if (midle == 9)
			{
				tmp = adder(tmp, &lenTmp, 'I');
				tmp = adder(tmp, &lenTmp, 'X');
			}
			else if (midle > 4)
			{
				tmp = adder(tmp, &lenTmp, 'V');
				int size = midle - 5;
				for (int i = 0; i != size; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'I');
				}
			}
			else if (midle == 4)
			{
				tmp = adder(tmp, &lenTmp, 'I');
				tmp = adder(tmp, &lenTmp, 'V');
			}
			else
			{
				for (int i = 0; i != midle; ++i)
				{
					tmp = adder(tmp, &lenTmp, 'I');
				}
			}
		}
		--count;
	}
	delete[]Input;
	(*len) = lenTmp;
	return tmp;
}

template <typename T>
T* adderStart(const T* Input, int* len, T New)
{
	T* tmp = new T[(*len) + 1];
	tmp[0] = New;
	for (int i = 1; i < (*len) + 1; ++i)
	{
		tmp[i] = Input[i - 1];
	}
	++(*len);
	delete[]Input;
	return tmp;
}

int main(int argc, char* argv[])
{
	std::fstream InFile;
	InFile.open(argv[1], std::ios_base::in | std::ios_base::binary);
	std::fstream OutFile;
	OutFile.open(argv[2], std::ios_base::out | std::ios_base::binary);
	char* tmp;
	int lenTmp;
	int lenStr;
	char* Str;
	char sym;
	int lenStack;
	int stack[100];
	do
	{
		lenStr = 0;//Обнуление Строчки
		Str = nullptr;
		lenStack = 0;//Обнуления Стека
		stack[0] = -1;
		bool ok = true;
		do
		{
			InFile.get(sym);
			if (sym == '\n' or InFile.eof() or sym == '\r')
			{
				ok = false;
			}
			if (ok)
			{
				Str = adder(Str, &lenStr, sym);
			}
		} while (ok);
		OutFile.write(Str, lenStr);
		if (lenStr != 0)
		{
			lenTmp = 0;
			tmp = nullptr;
			for (int i = 0; i < lenStr; ++i)
			{
				if (stack[0] != -1 and (Str[i] == '+' or Str[i] == '-' or Str[i] == '*' or Str[i] == '/'))
				{
					if (Str[i] == '+')
					{
						stack[lenStack - 2] += stack[lenStack - 1];
						--lenStack;
					}
					else if (Str[i] == '-')
					{
						stack[lenStack - 2] -= stack[lenStack - 1];
						--lenStack;
					}
					else if (Str[i] == '*')
					{
						stack[lenStack - 2] *= stack[lenStack - 1];
						--lenStack;
					}
					else if (Str[i] == '/')
					{
						stack[lenStack - 2] /= stack[lenStack - 1];
						--lenStack;
					}
				}
				else
				{
					if (Str[i] != ' ')
					{
						tmp = adder(tmp, &lenTmp, Str[i]);
					}
					else
					{
						if (lenTmp == 0)
						{
							continue;
						}
						int* arriveRuman = new int[lenTmp];
						for (size_t i = 0; i != lenTmp; ++i)
						{
							if (tmp[i] == 'I')
							{
								arriveRuman[i] = 1;
							}
							else if (tmp[i] == 'X')
							{
								arriveRuman[i] = 10;
							}
							else if (tmp[i] == 'C')
							{
								arriveRuman[i] = 100;
							}
							else if (tmp[i] == 'M')
							{
								arriveRuman[i] = 1000;
							}
							else if (tmp[i] == 'V')
							{
								arriveRuman[i] = 5;
							}
							else if (tmp[i] == 'L')
							{
								arriveRuman[i] = 50;
							}
							else if (tmp[i] == 'D')
							{
								arriveRuman[i] = 500;
							}
						}
						int output = arriveRuman[lenTmp - 1];
						for (size_t i = 0; i != lenTmp - 1; ++i)
						{
							output += (arriveRuman[i] >= arriveRuman[i + 1]) ? arriveRuman[i] : (-arriveRuman[i]);
						}
						stack[lenStack] = output;
						++lenStack;
						delete[] arriveRuman;
						delete[] tmp;
						lenTmp = 0;
						tmp = new char[lenTmp];
					}
				}
			}
			delete[]tmp;
			OutFile.write(" = ", 3);
			if (stack[0] <= 0 or stack[0] >= 4000)
			{
				OutFile.write("ERR", 3);
			}
			else
			{
				int lenNomber = 0;
				char* Nomber=nullptr;
				while (stack[0] != 0)
				{
					Nomber = adderStart(Nomber, &lenNomber, char((stack[0] % 10) + 48));
					stack[0] /= 10;
				}
				Nomber = inRuman(Nomber, &lenNomber);
				OutFile.write(Nomber, lenNomber);
				delete[]Nomber;
			}
		}
		delete[]Str;
		if (InFile.eof())
		{
			break;
		}
		OutFile.put(sym);
	} while (true);
	InFile.close();
	OutFile.close();
	return 0;
}
