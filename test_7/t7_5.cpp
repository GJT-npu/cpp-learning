#include<iostream>
using namespace std;

long long factorial(unsigned int n);

int main(void)
{
    int number;
    long long fac;

    cout << "Enter a number and output it's factorial: ";
    
    while (cin >> number)
    {
        fac = factorial(number);
        cout << number << "! = " << fac << endl;
        cout << "Next number (q to quit): ";
    }

    return 0;
}

long long factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}