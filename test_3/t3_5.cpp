#include<iostream>
using namespace std;

int main(void)
{
    long long wp, up;

    cout << "Enter the world's population: ";
    cin >> wp;
    cout << "Enter the population of the US: ";
    cin >> up;

    double pre = (double)up / (double)wp * 100;

    cout << "THe population of the US is " << pre << "% "
         << "of the world population." << endl;

    return 0;
}