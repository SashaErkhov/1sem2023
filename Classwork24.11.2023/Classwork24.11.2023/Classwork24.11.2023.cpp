#include <iostream>

struct complex
{
    double re;
    double im;
};

void print(const complex &x)
{
    std::cout << x.re;
    if (x.im >= 0)
    {
        std::cout << " + " << x.im << "i" << std::endl;
    }
    else
    {
        std::cout << " " << x.im << "i" << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const complex& x)
{
    out << x.re;
    if (x.im >= 0)
    {
        out << "+";
    }
    out << x.im << "i";
    return out;
}

complex operator+(const complex& x, const complex& y)
{
    complex z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}

void print(complex M[], int size)
{
    for (int i = 0; i < size; ++i)
    {
        std::cout << M[i] << " ";
    }
}

int main()
{
    complex x;
    complex y = { -5.4,-6.7 };
    x.re = 2;
    x.im = 4;
    print(x);
    std::cout << std::endl;
    print(y);
    std::cout<<"x= " << x << std::endl;
    std::cout << "x+y= " << x + y << std::endl;
    //x+y
    //operator+(x+y)

    complex M[3] = { {1,2},{-4,-2.1} };
    print(M,3);

    struct
    {
        int a;
        int b;
        char ch;
        double M[4];
    } X, Y, * p, S[10];

    X.a = 1;
    X.b = 2;
    X.ch = 'x';
    X.M[0] = 1.2;
    X.M[1] = -0.3;
    Y.a = 3;
    Y.b = 2;
    Y.ch = 'y';
    Y.M[0] = 4.3;
    p = &X;
    (*p).a = 3;
    p->a = 3;//то же самое но круче
    p = &Y;
    p->b = 5;
    S[0].a = 5;
    S[0].M[3] = 6.5;
    return 0;
}