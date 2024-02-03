#include <iostream>

template <typename T>
T pow(T Num, int len)
{
    T output = 1;
    for (int i = 0; i < len; ++i)
    {
        output *= Num;
    }
    return output;
}

int myAtoi(const char M[], int sizeM)
{
    int count = pow(10, sizeM - 1);
    int output = 0;
    for (int i = 0; i < sizeM; ++i)
    {
        output += (M[i]-48) * count;
        count /= 10;
    }
    return output;
}

int main(int argc, char* argv[])
{
    //Если в командную сторку ничего не закинули?
    if (argc == 1)
    {
        std::cout << "Unknown" << std::endl;
        return 0;
    }
    int len = 0;//Длина строки
    for (size_t i = 0; i != 1000; ++i)
    {
        if (argv[1][i] == '\0')
        {
            break;
        }
        ++len;
    }
    int countDot = 0;//кол-во точек
    int positions[2];//позиции точек
    bool ok=false;//вспомогательный буль для перехода с точку на точку
    //Проверки на формат
    for (size_t i = 0; i < len; ++i)
    {
        if (!((argv[1][i] == '.') or (argv[1][i] <= '9')))
        {
            std::cout << "Unknown" << std::endl;
            return 0;
        }
        if (argv[1][i] == '.')
        {
            ++countDot;
            if (!ok)
            {
                positions[0] = i;
                ok = true;
            }
            else
            {
                positions[1] = i;
            }
        }
    }
    if (countDot != 2)
    {
        std::cout << "Unknown" << std::endl;
        return 0;
    }
    if (positions[1] - positions[0] == 1)
    {
        std::cout << "Unknown" << std::endl;
        return 0;
    }
    int day;
    int month;
    if (positions[0] == 1)
    {
        day = argv[1][0] - 48;
        if (positions[1] == 3)
        {
            month = argv[1][2] - 48;
        }
        else if (positions[1] == 4)
        {
            month = (argv[1][2] - 48)*10+ (argv[1][3] - 48);
        }
        else
        {
            std::cout << "Unknown" << std::endl;
            return 0;
        }
    }
    else if (positions[0] == 2)
    {
        day = (argv[1][0] - 48) * 10 + (argv[1][1] - 48);
        if (positions[1] == 4)
        {
            month = argv[1][3] - 48;
        }
        else if (positions[1] == 5)
        {
            month = (argv[1][3] - 48)*10+(argv[1][4] - 48);
        }
        else
        {
            std::cout << "Unknown" << std::endl;
            return 0;
        }
    }
    else
    {
        std::cout << "Unknown" << std::endl;
        return 0;
    }
    if (day > 31 or month > 12 or day==0 or month ==0)
    {
        std::cout << "Unknown" << std::endl;
        return 0;
    }
    int lenYearStart = len - positions[1] - 1;
    char* yearStart = new char[lenYearStart];
    for (int i = 0; i < lenYearStart; ++i)
    {
        yearStart[i] = argv[1][positions[1] + i+1];
    }
    int year = myAtoi(yearStart,lenYearStart);//Со встроенным атои была утечка памяти
    delete [] yearStart;
    if (month == 2 and day==29)
    {
        if (year % 100 == 0)
        {
            if (year % 400 != 0)
            {
                std::cout << "Unknown" << std::endl;
                return 0;
            }
        }
        else
        {
            if (year % 4 != 0)
            {
                std::cout << "Unknown" << std::endl;
                return 0;
            }
        }
    }
    //Основная часть - нахождение искомого
    int a = (14 - month) / 12;
    int y = year - a;
    int m = month + 12 * a - 2;
    int d = (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7;
    if (d == 0)
    {
        std::cout << "Sunday" << std::endl;
    }
    else if (d == 1)
    {
        std::cout << "Monday" << std::endl;
    }
    else if (d == 2)
    {
        std::cout << "Tuesday" << std::endl;
    }
    else if (d == 3)
    {
        std::cout << "Wednesday" << std::endl;
    }
    else if (d == 4)
    {
        std::cout << "Thursday" << std::endl;
    }
    else if (d == 5)
    {
        std::cout << "Friday" << std::endl;
    }
    else if (d == 6)
    {
        std::cout << "Saturday" << std::endl;
    }

    if (day == 29 and month == 2)
    {
        for (int i = year + 4; i < 1000000; i+=4)
        {
            y = i - a;
            if (5 == (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7)
            {
                std::cout << i << std::endl;
                return 0;
            }
        }
    }

    for (int i = year + 1; i < 1000000; ++i)
    {
        y = i - a;
        if (5 == (day + y + y / 4 - y / 100 + y / 400 + 31 * m / 12) % 7)
        {
            std::cout << i << std::endl;
            return 0;
        }
    }
    std::cout << "Unknown" << std::endl;
    return 0;
}