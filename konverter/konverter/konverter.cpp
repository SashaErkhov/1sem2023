#include <iostream>
#include <string>

using ULL = unsigned long long int;

ULL pow(ULL input, ULL len)
{
    ULL output = 1;
    for (ULL i = 0; i != len;++i)
    {
        output *= input;
    }
    return output;
}

ULL tranPto10(std::string input, ULL base1)
{
    ULL len = input.length();
    ULL midle;
    ULL output = 0;
    for (ULL i = 0; i != len; ++i)
    {
        if ('A'<=input[i])
        {
            if ( (input[i]-55) >= base1)
            {
                throw "wrong integer";
            }
            midle = (input[i] - 55);
        }
        else
        {
            if ((input[i] - 48) >= base1)
            {
                throw "wrong integer";
            }
            midle = (input[i] - 48);
        }
        output += midle*pow(base1, len-1-i);
    }
    return output;
}

std::string tran10toP(ULL input, ULL base2)
{
    std::string output;
    ULL s;//Чтобы не вычеслять одно и тоже постоянно
    while (input != 0)
    {
        s = input % base2;
        if (s >= 10)
        {
            output += char(s + 55);
        }
        else
        {
            output += char(s + 48);
        }
        input /= base2;
    }
    ULL len = output.length();
    for (ULL i = 0; i != (len / 2); ++i)
    {
        std::swap(output[i], output[len - i - 1]);
    }
    return output;
}

int main()
{
    std::string Number;//ввод - N - число, которое надо перевести (в десятичной системе соответствующее число N целое
    std::cin >> Number;
    ULL base1;//ввод - p - основание системы счисления, в которой задано число
    std::cin >> base1;
    ULL base2;//ввод - p - основание системы счисления, в которую необходимо перевести число
    std::cin >> base2;
    try
    {
        std::cout << tran10toP(tranPto10(Number, base1), base2);
        return 0;
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cout << "ERROR!!!" << std::endl;
        return 0;
    }
    return 0;
}