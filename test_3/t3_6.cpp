#include<iostream>
using namespace std;

int main(void)
{
    double miles, gallon;

    cout << "Enter the distance in miles: ";
    cin >> miles;
    cout << "Enter the fuel consume in gallon: ";
    cin >> gallon;

    double consume = miles / gallon;
    cout << "The fuel consume is " << consume << " miles/gallon." << endl;

    return 0;
}