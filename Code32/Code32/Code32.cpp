#include <iostream>
#include <fstream>

void inbase32(const unsigned char buffer[], unsigned char a[])
{
	a[0] = buffer[0] >> 3;
	a[1] = ((buffer[0] & 0x7) << 2) | (buffer[1] >> 6);
	a[2] = (buffer[1] >> 1) & 31;
	a[3] = ((buffer[1] & 0x1) << 4) | (buffer[2] >> 4);
	a[4] = ((buffer[2] & 15) << 1) | (buffer[3] >> 7);
	a[5] = (buffer[3] >> 2) & 31;
	a[6] = ((buffer[3] & 0x3) << 3) | (buffer[4] >> 5);
	a[7] = buffer[4] & 31;
}

void readerBase32(unsigned char a[], int& lenA, unsigned char sym)
{
	if (sym >= '0' and sym <= '9')
	{
		a[lenA] = sym - '0';
	}
	else if ((sym >= 'A' and sym <= 'Z') or (sym >= 'a' and sym <= 'z'))
	{
		if (sym == 'A' or sym == 'a')
		{
			a[lenA] = 10;
		}
		else if (sym == 'B' or sym == 'b')
		{
			a[lenA] = 11;
		}
		else if (sym == 'C' or sym == 'c')
		{
			a[lenA] = 12;
		}
		else if (sym == 'D' or sym == 'd')
		{
			a[lenA] = 13;
		}
		else if (sym == 'E' or sym == 'e')
		{
			a[lenA] = 14;
		}
		else if (sym == 'F' or sym == 'f')
		{
			a[lenA] = 15;
		}
		else if (sym == 'G' or sym == 'g')
		{
			a[lenA] = 16;
		}
		else if (sym == 'H' or sym == 'h')
		{
			a[lenA] = 17;
		}
		else if (sym == 'I' or sym == 'i' or sym == 'L' or sym == 'l')
		{
			a[lenA] = 1;
		}
		else if (sym == 'J' or sym == 'j')
		{
			a[lenA] = 18;
		}
		else if (sym == 'K' or sym == 'k')
		{
			a[lenA] = 19;
		}
		else if (sym == 'M' or sym == 'm')
		{
			a[lenA] = 20;
		}
		else if (sym == 'N' or sym == 'n')
		{
			a[lenA] = 21;
		}
		else if (sym == 'O' or sym == 'o')
		{
			a[lenA] = 0;
		}
		else if (sym == 'P' or sym == 'p')
		{
			a[lenA] = 22;
		}
		else if (sym == 'Q' or sym == 'q')
		{
			a[lenA] = 23;
		}
		else if (sym == 'R' or sym == 'r')
		{
			a[lenA] = 24;
		}
		else if (sym == 'S' or sym == 's')
		{
			a[lenA] = 25;
		}
		else if (sym == 'T' or sym == 't')
		{
			a[lenA] = 26;
		}
		else if (sym == 'V' or sym == 'v')
		{
			a[lenA] = 27;
		}
		else if (sym == 'W' or sym == 'w')
		{
			a[lenA] = 28;
		}
		else if (sym == 'X' or sym == 'x')
		{
			a[lenA] = 29;
		}
		else if (sym == 'Y' or sym == 'y')
		{
			a[lenA] = 30;
		}
		else if (sym == 'Z' or sym == 'z')
		{
			a[lenA] = 31;
		}
	}
	else if (sym == '=')
	{
		a[lenA] = '=';
	}
	else
	{
		--lenA;
	}
	++lenA;
}

void writerBase32(std::fstream& out, unsigned char a[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		if (a[i] >= 0 and a[i]<=9)
		{
			out << char('0'+a[i]);
			continue;
		}
		switch (a[i])
		{
		case 10:
			out << 'A';
			break;
		case 11:
			out << 'B';
			break;
		case 12:
			out << 'C';
			break;
		case 13:
			out << 'D';
			break;
		case 14:
			out << 'E';
			break;
		case 15:
			out << 'F';
			break;
		case 16:
			out << 'G';
			break;
		case 17:
			out << 'H';
			break;
		case 18:
			out << 'J';
			break;
		case 19:
			out << 'K';
			break;
		case 20:
			out << 'M';
			break;
		case 21:
			out << 'N';
			break;
		case 22:
			out << 'P';
			break;
		case 23:
			out << 'Q';
			break;
		case 24:
			out << 'R';
			break;
		case 25:
			out << 'S';
			break;
		case 26:
			out << 'T';
			break;
		case 27:
			out << 'V';
			break;
		case 28:
			out << 'W';
			break;
		case 29:
			out << 'X';
			break;
		case 30:
			out << 'Y';
			break;
		case 31:
			out << 'Z';
			break;
		default:
			break;
		}
	}
}

int main(int argc, char* argv[])
{
	if (argc != 4)
	{
		std::cout << "error1" << std::endl;
		return 0;
	}
	bool menu;//true==encode false==decode
	if (argv[1][1] == 'e' and argv[1][0] == '-')
	{
		menu = true;
	}
	else if (argv[1][1] == 'd' and argv[1][0] == '-')
	{
		menu = false;
	}
	else
	{
		std::cout << "error2" << std::endl;
		return 0;
	}
	std::fstream InFile;
	InFile.open(argv[2], std::ios_base::in | std::ios_base::binary);
	if (!InFile.is_open())
	{
		std::cout << "Can't open infile error3" << std::endl;
		return 0;
	}
	std::fstream OutFile;
	OutFile.open(argv[3], std::ios_base::out | std::ios_base::binary);
	if (!OutFile.is_open())
	{
		std::cout << "Can't open outfile error4" << std::endl;
		return 0;
	}
	if (menu)
	{
		InFile.seekg(0, std::ios_base::end);
		long all = InFile.tellg();
		InFile.seekg(0, std::ios_base::beg);
		unsigned char buffer[5];//5 байт из файла
		unsigned char a[8];//разбиение 40 бит(5 байт, buffer) на 8 букв(цифр) по 5 бит
		while ((all - InFile.tellg()) >= 5)
		{
			InFile.read((char*)buffer, 5);
			inbase32(buffer, a);
			writerBase32(OutFile, a, 8);
		}
		if ((all - InFile.tellg()) != 0)
		{
			if ((all - InFile.tellg()) == 1)
			{
				InFile.read((char*)(buffer), 1);
				buffer[1] = buffer[2] = buffer[3] = buffer[4] = 0;
				inbase32(buffer, a);
				writerBase32(OutFile, a, 2);
				OutFile << "======";
			}
			else if ((all - InFile.tellg()) == 2)
			{
				InFile.read((char*)(buffer), 2);
				buffer[2] = buffer[3] = buffer[4] = 0;
				inbase32(buffer, a);
				writerBase32(OutFile, a, 4);
				OutFile << "====";
			}
			else if ((all - InFile.tellg()) == 3)
			{
				InFile.read((char*)(buffer), 3);
				buffer[3] = buffer[4] = 0;
				inbase32(buffer, a);
				writerBase32(OutFile, a, 5);
				OutFile << "===";
			}
			else if ((all - InFile.tellg()) == 4)
			{
				InFile.read(reinterpret_cast<char*>(buffer), 4);
				buffer[4] = 0;
				inbase32(buffer, a);
				writerBase32(OutFile, a, 7);
				OutFile << "=";
			}
		}
	}
	else
	{
		unsigned char buffer[5];// 5 байт в выходной файл
		unsigned char a[8];// 8 букв из файла
		int lenA = 0;
		unsigned char sym;
		while (!InFile.eof())
		{
			InFile >> sym;
			readerBase32(a, lenA, sym);
			if (lenA == 8)
			{
				if (a[7] != '=')
				{
					buffer[0] = (a[0] << 3) + ((a[1] & 28) >> 2);
					buffer[1] = ((a[1] & 3) << 6) + (a[2] << 1) + ((a[3] & 16) >> 4);
					buffer[2] = ((a[3] & 15) << 4) + ((a[4]) >> 1);
					buffer[3] = ((a[4] & 1) << 7) + (a[5] << 2) + ((a[6] & 24) >> 3);
					buffer[4] = ((a[6] & 7) << 5) + a[7];
					OutFile.write((char*)buffer, 5);
				}
				else
				{
					if (a[2] == '=')
					{
						buffer[0] = (a[0] << 3) + ((a[1] & 28) >> 2);
						OutFile.write((char*)buffer, 1);
					}
					else if (a[4] == '=')
					{
						buffer[0] = (a[0] << 3) + ((a[1] & 28) >> 2);
						buffer[1] = ((a[1] & 3) << 6) + (a[2] << 1) + ((a[3] & 16) >> 4);
						OutFile.write((char*)buffer, 2);
					}
					else if (a[5] == '=')
					{
						buffer[0] = (a[0] << 3) + ((a[1] & 28) >> 2);
						buffer[1] = ((a[1] & 3) << 6) + (a[2] << 1) + ((a[3] & 16) >> 4);
						buffer[2] = ((a[3] & 15) << 4) + ((a[4]) >> 1);
						OutFile.write((char*)buffer, 3);
					}
					else if (a[7] == '=')
					{
						buffer[0] = (a[0] << 3) + ((a[1] & 28) >> 2);
						buffer[1] = ((a[1] & 3) << 6) + (a[2] << 1) + ((a[3] & 16) >> 4);
						buffer[2] = ((a[3] & 15) << 4) + ((a[4]) >> 1);
						buffer[3] = ((a[4] & 1) << 7) + (a[5] << 2) + ((a[6] & 24) >> 3);
						OutFile.write((char*)buffer, 4);
					}
				}
				lenA = 0;
			}
		}
	}
	InFile.close();
	OutFile.close();
	return 0;
}