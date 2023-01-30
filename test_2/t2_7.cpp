#include<iostream>
using namespace std;
void Time(int a, int b);

int main(void)
{
    int hour,min;

    cout << "Enter the number of hours: ";
    cin >> hour;
    cout << "Enter the number of minutes: ";
    cin >> min;

    Time(hour, min);

    return 0;
}

void Time(int a, int b)
{
    cout << "Time: " << a << ":" << b;
}