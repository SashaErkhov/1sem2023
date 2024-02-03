#include <iostream>

void isNumber(const char Input[], int len)//Проверка: Число ли? Проверка на смесь систем
{
    for (size_t i = 0; i != len; ++i)
    {
        if (!('0' <= Input[i] and Input[i] <= '9'))
        {
            throw "wrong integer";
        }
    }
}

void isNotLongNumber(const char Input[], int len)//Проверка: Не слишком ли большое число?
{
    if (len > 4)
    {
        throw "wrong integer";
    }
    if (len == 4)
    {
        if (Input[0] > '3')
        {
            throw "wrong integer";
        }
    }
}

void isRuman(const char Input[], int len)//Проверка: Римское ли число? Проверка на смесь
{
    for (size_t i = 0; i != len; ++i)
    {
        if (!(Input[i] == 'I' or Input[i] == 'X' or Input[i] == 'C' or Input[i] == 'M'
            or Input[i] == 'V' or Input[i] == 'L' or Input[i] == 'D'))
        {
            throw "wrong integer";
        }
    }
}

void isNormalRuman(const char Input[], int len)// Проверка: Проверка на слишком длинные
//последовательности из римских цифр
{
    int count = 1;//Динамический счетчик повторяющихся цифр
    int maxCnt = 0;//Максимальное кол-во повторяющтхся цифр
    for (size_t i = 0; i != len - 1; ++i)
    {
        if (Input[i] == Input[i + 1])
        {
            ++count;
            if (count > maxCnt)
            {
                maxCnt = count;
            }
        }
        else
        {
            count = 1;
        }
    }
    if (maxCnt > 3)
    {
        throw "wrong integer";
    }
}

void isNormalRuman2(const int Input[], int len)//Проверка на остальные правила римской системы
//нумерации: нельзя, чтобы рядом стояли слишком сильно отличающийеся цифры и чтобы до большой
//цифры стояли больше одной более маленькой цифры
{
    if (len == 1)
    {
        return;
    }
    if (Input[1] / Input[0] > 10)
    {
        throw "wrong integer";
    }
    for (size_t i = 2; i != len; ++i)
    {
        if (Input[i] / Input[i - 1] > 10)
        {
            throw "wrong integer";
        }
        if (Input[i] > Input[i - 1] and Input[i] > Input[i - 2] and Input[i - 1] >= Input[i - 2])
        {
            throw "wrong integer";
        }
    }
}

void inRuman(const char Input[], int len)//Алгоритм перевода в римские
{
    int count = len;// счетчик тысячи-сотни-десятки-единицы
    int midle;// отдельная циферка в разряде
    for (int i = 0; i != len; ++i)
    {
        midle = Input[i] - 48;
        if (count == 4)
        {
            for (int i = 0; i != midle; ++i)
            {
                std::cout << "M";
            }
        }
        else if (count == 3)
        {
            if (midle == 9)
            {
                std::cout << "CM";
            }
            else if (midle > 4)
            {
                std::cout << "D";
                int size = midle - 5;
                for (int i = 0; i != size; ++i)
                {
                    std::cout << "C";
                }
            }
            else if (midle == 4)
            {
                std::cout << "CD";
            }
            else
            {
                for (int i = 0; i != midle; ++i)
                {
                    std::cout << "C";
                }
            }
        }
        else if (count == 2)
        {
            if (midle == 9)
            {
                std::cout << "XC";
            }
            else if (midle > 4)
            {
                std::cout << "L";
                int size = midle - 5;
                for (int i = 0; i != size; ++i)
                {
                    std::cout << "X";
                }
            }
            else if (midle == 4)
            {
                std::cout << "XL";
            }
            else
            {
                for (int i = 0; i != midle; ++i)
                {
                    std::cout << "X";
                }
            }
        }
        else if (count == 1)
        {
            if (midle == 9)
            {
                std::cout << "IX";
            }
            else if (midle > 4)
            {
                std::cout << "V";
                int size = midle - 5;
                for (int i = 0; i != size; ++i)
                {
                    std::cout << "I";
                }
            }
            else if (midle == 4)
            {
                std::cout << "IV";
            }
            else
            {
                for (int i = 0; i != midle; ++i)
                {
                    std::cout << "I";
                }
            }
        }
        --count;
    }
}

int main(int argc, char* argv[])
{
    int len = 0;//длина Number и arriveRuman
    for (size_t i = 0; i != 1000; ++i)
    {
        if (argv[1][i] == '\0')
        {
            break;
        }
        ++len;
    }
    bool ok;//Если десятичная - true, если римские - false
    try//проверка почти всех исключений
    {
        if (argv[1][0] > '9')
        {
            isRuman(argv[1], len);
            isNormalRuman(argv[1], len);
            ok = false;
        }
        else
        {
            isNumber(argv[1], len);
            isNotLongNumber(argv[1], len);
            ok = true;
        }
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cout << "ERROR!" << std::endl;
        return 0;
    }
    if (ok)
    {
        inRuman(argv[1], len);
        return 0;
    }
    int* arriveRuman = new int[len];

    for (size_t i = 0; i != len; ++i)
    {
        if (argv[1][i] == 'I')
        {
            arriveRuman[i] = 1;
        }
        else if (argv[1][i] == 'X')
        {
            arriveRuman[i] = 10;
        }
        else if (argv[1][i] == 'C')
        {
            arriveRuman[i] = 100;
        }
        else if (argv[1][i] == 'M')
        {
            arriveRuman[i] = 1000;
        }
        else if (argv[1][i] == 'V')
        {
            arriveRuman[i] = 5;
        }
        else if (argv[1][i] == 'L')
        {
            arriveRuman[i] = 50;
        }
        else if (argv[1][i] == 'D')
        {
            arriveRuman[i] = 500;
        }
    }
    try//Не всё проверил, нужно есчо, для этого нужны были арабские эквиваленты
    {
        isNormalRuman2(arriveRuman, len);
    }
    catch (const char* error)
    {
        std::cout << error << std::endl;
        return 0;
    }
    catch (...)
    {
        std::cout << "ERROR!" << std::endl;
        return 0;
    }
    int output = arriveRuman[len - 1];
    for (size_t i = 0; i != len - 1; ++i)
    {
        output += (arriveRuman[i] >= arriveRuman[i + 1]) ? arriveRuman[i] : (-arriveRuman[i]);
    }
    std::cout << output << std::endl;
    delete[] arriveRuman;
    return 0;
}