#include <iostream>
#include <fstream>

template <typename T>
T* add(T Input[], int* len,T New)
{
    T* output = new T[*len+1];
    for (int i = 0; i < *len; ++i)
    {
        output[i] = Input[i];
    }
    output[*len] = New;
    ++(*len);
    delete[]Input;
    return output;
}

int main()
{
    std::fstream fs;
    fs.open("readme.txt", std::ios_base::in);
    int len = 0;
    int* arrive = new int[len];
    char midle;
    while (true)
    {
        fs.get(midle);
        if (fs.eof())
        {
            break;
        }
        arrive = add(arrive, &len, midle - 48);
    }
    for (int i = 0; i < len; ++i)
    {
        std::cout << arrive[i] << " ";
    }
    std::cout << std::endl;
    delete[]arrive;
    return 0;
}