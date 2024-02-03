//about base64
//В случае необходимости чекать LMS

#include <iostream>
#include <fstream>

 unsigned char base64Code(char ch)
{
	 if (ch >= 'A' && ch <= 'Z')
	 {
		 return ch - 'A';
	 }
	 if (ch >= 'a' && ch <= 'z')
	 {
		 return ch - 'a' + 26;
	 }
	 if (ch >= '0' && ch <= '9')
	 {
		 return ch - '0' + 52;
	 }
	 if (ch == '+')
	 {
		 return 62;
	 }
	 if (ch == '/')
	 {
		 return 63;
	 }
	 return 64;
}
 bool isbase64(char ch)
 {
	 if (ch >= 'A' && ch <= 'Z')
	 {
		 return true;
	 }
	 if (ch >= 'a' && ch <= 'z')
	 {
		 return true;
	 }
	 if (ch >= '0' && ch <= '9')
	 {
		 return true;
	 }
	 if (ch == '+')
	 {
		 return true;
	 }
	 if (ch == '/')
	 {
		 return true;
	 }
	 if (ch == '=')
	 {
		 return true;
	 }
	 return false;
 }
 int base64Decode(char inStr[], int len, char outStr[])
 {
	 //Функция вернет кол-во символов Base64 в outStr
	 int outIndex = 0;
	 unsigned char b1, b2, b3, b4;
	 int skip = 0;
	 if (len % 4 != 0)
	 {
		 throw "Wrang data for decoding";
	 }
	 for (int inIndex = 0; (inIndex < len)&&(skip==0);inIndex += 4)
	 {
		 b1 = base64Code(inStr[inIndex]);
		 b2 = base64Code(inStr[inIndex+1]);
		 b3 = base64Code(inStr[inIndex + 2]);
		 b4 = base64Code(inStr[inIndex + 3]);
		 if (b4 == 64)
		 {
			 b4 = 0;
			 skip = 1;
		 }
		 if (b3 == 64)
		 {
			 b3 = 0;
			 skip = 2;
		 }
		 outStr[outIndex++] = (b1 << 2) | (b2 >> 4);
		 outStr[outIndex++] = (b2 << 4) | (b3 >> 2);
		 outStr[outIndex++] = (b3 << 6) | b4;
	 }
	 return outIndex - skip;
 }
 void help(const char* cmdname)
 {
	 std::cout << "Use for decoding:\n";
	 std::cout << " " << cmdname << " file_source file desyination" << std::endl;
 }

int main(int argc, char* argv[])
{
	if (argc < 3)
	{
		help(argv[0]);
		return 1;
	}
	std::ifstream inFile(argv[1]);
	if (!inFile)
	{
		std::cout << "Xui";
		return 1;
	}
	std::ofstream outFile(argv[2], std::ios_base::binary);
	if (!outFile)
	{
		std::cout << "Xui";
		inFile.close();
		return 2;
	}

	char inStr[4];
	char outStr[3];
	int ch;
	int cnt = 0;
	while ((ch = inFile.get()) != EOF)
	{
		if (isbase64(ch))
		{
			inStr[cnt++] = ch;
			if (cnt == 4)
			{
				try 
				{
					cnt = base64Decode(inStr, 4, outStr);
					outFile.write(outStr, cnt);
				}
				catch (const char* error)
				{
					std::cerr << "Error: " << error << std::endl;
					outFile.close();
					inFile.close();
					return 111;
				}
				catch (...) 
				{
					std::cerr << "Unlnown error!" << std::endl;
					outFile.close();
					inFile.close();
					return 111;
				}
				cnt = 0;
			}
		}
	}
	inFile.close();
	outFile.close();
	//В случае необходимости чекать LMS
	return 0;
}