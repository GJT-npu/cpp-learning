#include<iostream>
using namespace std;
double add(double x, double y);
double sub(double x, double y);
double caculate(double x, double y, double (*pt)(double, double));

int main(void)
{
    double result = caculate(3.5, 10.4, add);
    cout << "The result of add is: " << result << endl;

    result = caculate(3.5, 10.4, sub);
    cout << "The result of sub is: " << result << endl;

    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double caculate(double x, double y, double (*pt)(double, double))
{
    return (*pt)(x, y);
}