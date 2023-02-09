#include<iostream>
using namespace  std;

const int SIZE = 16;

int main(void)
{
    long long fac[SIZE];

    fac[0] = fac[1] = 1;
    for (int i = 2; i < SIZE; i++)
    {
        fac[i] = i * fac[i - 1];
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "! = " << fac[i] << endl;
    }

        return 0;
} 
