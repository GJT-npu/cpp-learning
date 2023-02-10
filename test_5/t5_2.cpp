#include<iostream>
#include<array>
using namespace std;
const int SIZE = 16;

int main(void)
{
    array<long double, SIZE> factorials;
    factorials[0] = factorials[1] = 1;

    for (int i = 2; i < SIZE; i++)
    {
        factorials[i] = i * factorials[i - 1];
    }
    for (int i = 0; i < SIZE; i++)
    {
        cout << i << "! = " << factorials[i] << endl;
    }

        return 0;
}