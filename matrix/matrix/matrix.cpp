#include <iostream>
#include <fstream>
#include <cmath>
#define MY_NULL 0.00000001

long double det(long double** Matrix, int m)
{
    //Делаю через унитреугольную матрицу
    //Это нужно было для того, чтобы переписать в инверсионную матрицу
    //и сделать тоже самое, только для единичной матрицы
    long double detEq = 1.0;
    for (int i = 0; i < m - 1; ++i)
    {
        int Index = i;
        while (true)//Нахожу первый не ноль, чтобы в диагонали были единички
        {
            if (fabsl(Matrix[Index][i]) < MY_NULL)
            {
                if (Index >= (m - 1))
                {
                    return 0;
                }
                ++Index;
            }
            else
            {
                if (Index != i)
                {
                    std::swap(Matrix[i], Matrix[Index]);
                    detEq *= -1;
                }
                break;
            }
        }
        long double coef = Matrix[i][i];
        detEq *= coef;
        for (int j = i; j < m; ++j)
        {
            Matrix[i][j] /= coef;
        }
        for (int j = i + 1; j < m; ++j)
        {
            long double coef2 = Matrix[j][i];
            for (int k = i; k < m; ++k)
            {
                Matrix[j][k] = Matrix[j][k] - (coef2 * Matrix[i][k]);
            }
        }
    }
    return detEq * Matrix[m - 1][m - 1];
}

long double** powforMatrix(long double** Matrix, long double** Matrix2, int m)
{
    //Умножение матриц, результат в первую матрицу
    long double** NewMatrix = new long double* [m];
    for (int i = 0; i < m; ++i)
    {
        NewMatrix[i] = new long double[m];
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            long double sum = 0.0;
            for (int k = 0; k < m; ++k)
            {
                sum += Matrix[i][k] * Matrix2[k][j];
            }
            NewMatrix[i][j] = sum;
        }
    }
    for (int i = 0; i < m; ++i)
    {
        delete[]Matrix[i];
    }
    delete[]Matrix;
    Matrix = NewMatrix;
    return Matrix;
}

long double* poly(long double** Matrix, int m)
{
    //По методу Лаверье
    long double* Poly = new long double[m + 1];//Ответ, коэфф. хор-ого полинома
    Poly[0] = 1.0;
    long double** A = new long double* [m];//Для степеней
    long double* s = new long double[m];//следы
    for (int i = 0; i < m; ++i)
    {
        A[i] = new long double[m];
        for (int j = 0; j < m; ++j)
        {
            A[i][j] = Matrix[i][j];
        }
    }
    long double sum = 0.0;//Для нахождения следов
    for (int j = 0; j < m; ++j)
    {
        sum += A[j][j];
    }
    s[0] = sum;
    for (int i = 1; i < m; ++i)
    {
        A = powforMatrix(A, Matrix, m);
        sum = 0.0;
        for (int j = 0; j < m; ++j)
        {
            sum += A[j][j];
        }
        s[i] = sum;
    }
    for (int i = 1; i < m + 1; ++i)
    {
        long double answer = s[i - 1];//Для коэфф.
        int index = 1;
        for (int j = i - 1; j > 0; --j)
        {
            answer += s[j - 1] * Poly[index];
            ++index;
        }
        if (answer == 0.0)//Чтобы не было -0
        {
            Poly[i] = 0.0;
        }
        else
        {
            Poly[i] = -1.0 * (answer / double(i));
        }
    }
    for (int i = 0; i < m; ++i)
    {
        delete[]A[i];
    }
    delete[]A;
    delete[]s;
    return Poly;
}

long double** inv(long double** Matrix, int m)
{
    long double** Inv = new long double* [m];//Ответ - обратная матрицы
    for (int i = 0; i < m; ++i)
    {
        //Делаю единичную матрицу
        Inv[i] = new long double[m];
        for (int j = 0; j < m; ++j)
        {
            Inv[i][j] = 0.0;
            if (i == j)
            {
                Inv[i][j] = 1.0;
            }
        }
    }
    long double detEq = 1.0;
    for (int i = 0; i < m - 1; ++i)
    {
        int Index = i;
        while (true)
        {
            if (fabsl(Matrix[Index][i]) < MY_NULL)
            {
                if (Index >= (m - 1))
                {
                    throw "error";
                }
                ++Index;
            }
            else
            {
                if (Index != i)
                {
                    std::swap(Matrix[i], Matrix[Index]);
                    std::swap(Inv[i], Inv[Index]);
                    detEq *= -1;
                }
                break;
            }
        }
        long double coef = Matrix[i][i];
        detEq *= coef;
        for (int j = i; j < m; ++j)
        {
            if (Matrix[i][j] != 0)
            {
                Matrix[i][j] /= coef;
            }
        }
        for (int j = 0; j < m; ++j)
        {
            if (Inv[i][j] != 0)
            {
                Inv[i][j] /= coef;
            }
        }
        for (int j = i + 1; j < m; ++j)
        {
            long double coef2 = Matrix[j][i];
            for (int k = i; k < m; ++k)
            {
                Matrix[j][k] = Matrix[j][k] - (coef2 * Matrix[i][k]);
            }
            for (int k = 0; k < m; ++k)
            {
                Inv[j][k] = Inv[j][k] - (coef2 * Inv[i][k]);
            }
        }
    }
    detEq *= Matrix[m - 1][m - 1];
    if (detEq == 0)
    {
        throw "error";
    }
    for (int i = 0; i < m; ++i)
    {
        if (Inv[m - 1][i] != 0)
        {
            Inv[m - 1][i] /= Matrix[m - 1][m - 1];
        }
    }
    long double coef;
    for (int i = m - 1; i > 0; --i)
    {
        for (int j = i - 1; j > -1; --j)
        {
            coef = Matrix[j][i];
            for (int k = 0; k < m; ++k)
            {
                Inv[j][k] = Inv[j][k] - (coef * Inv[i][k]);
            }
        }
    }
    for (int i = 0; i < m; ++i)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    return Inv;
}

int main(int argc, char* argv[])
{
    if (argc < 4)
    {
        std::cout << "error" << std::endl;
        return 0;
    }
    std::fstream InFile;
    std::fstream OutFile;
    InFile.open(argv[2], std::ios_base::in);
    if (!InFile.is_open())
    {
        std::cout << "Can't open file" << std::endl;
        return 0;
    }
    OutFile.open(argv[3], std::ios_base::out);
    if (!OutFile.is_open())
    {
        InFile.close();
        std::cout << "Can't open file" << std::endl;
        return 0;
    }
    if (InFile.peek() == EOF)//Если файл вообще пустой
    {
        OutFile << "error";
        InFile.close();
        OutFile.close();
        return 0;
    }
    int m;//Кол-во строчек
    InFile >> m;
    if (InFile.peek() == EOF)//Если файл только из одного числа
    {
        OutFile << "error";
        InFile.close();
        OutFile.close();
        return 0;
    }
    if (m == 0)//Как это - 0 строчек?
    {
        OutFile << "error";
        InFile.close();
        OutFile.close();
        return 0;
    }
    int n;//Кол-во столбиков
    InFile >> n;
    if (InFile.peek() == EOF)//Если файл только из двух чисел?
    {
        OutFile << "error";
        InFile.close();
        OutFile.close();
        return 0;
    }
    long double** Matrix = new long double* [m];
    for (int i = 0; i < m; ++i)
    {
        Matrix[i] = new long double[n];
    }
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            InFile >> Matrix[i][j];
        }
    }
    if (m != n)
    {
        OutFile << "error";
        InFile.close();
        OutFile.close();
        for (int i = 0; i < m; ++i)
        {
            delete[] Matrix[i];
        }
        delete[] Matrix;
        return 0;
    }
    if (argv[1][1] == 'd')
    {
        OutFile << det(Matrix, m);
    }
    else if (argv[1][1] == 'p')
    {
        long double* Poly = poly(Matrix, m);
        OutFile << 1 << " " << m + 1 << "\n";
        for (int i = 0; i < m + 1; ++i)
        {
            OutFile << Poly[i] << " ";
        }
        delete[]Poly;
    }
    else if (argv[1][1] == 'i')
    {
        try
        {
            Matrix = inv(Matrix, m);
        }
        catch (...)
        {
            OutFile << "singular";
            InFile.close();
            OutFile.close();
            for (int i = 0; i < m; ++i)
            {
                delete[] Matrix[i];
            }
            delete[] Matrix;
            return 0;
        }
        OutFile << m << " " << m << "\n";
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < m; ++j)
            {
                OutFile << Matrix[i][j] << " ";
            }
            OutFile << "\n";
        }
    }
    InFile.close();
    OutFile.close();
    for (int i = 0; i < m; ++i)
    {
        delete[] Matrix[i];
    }
    delete[] Matrix;
    return 0;
}