#include <iostream>
using namespace std;

int main()
{
    int age;

    cout << "Please enter your age: ";
    cin >> age;
    cout << "Your age in month is " << age * 12 << "." << endl;

    return 0;
}