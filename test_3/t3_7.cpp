#include<iostream>
using namespace std;

int main(void)
{
    double ec, uc;

    cout << "Enter the fuel consume in europe(L/100km): ";
    cin >> ec;

    uc = 3.875 / ec * 62.14;

    cout << "The fuel consume in US is: " << uc << " mile/gallon." << endl;

    return 0;
}
