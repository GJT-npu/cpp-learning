#include<iostream>
using namespace std;

inline double square(double x)
{
    return x * x;
}

int main(void)
{
    double a, b;
    double c = 13.0;

    a = square(5.0);
    b = square(4.5 + 7.5);

    cout << "a = " << a << ", b = " << b << endl;
    cout << "c = " << c << endl;
    cout << "Now c = " << square(c++) << endl;
    cout << "C = " << c << endl;

    return 0;
}