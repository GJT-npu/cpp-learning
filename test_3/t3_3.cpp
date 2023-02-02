#include<iostream>
using namespace std;

int main(void)
{
    int deg, min, sec;

    cout << "Enter a latitude in degrees,minutes, and seconds: " << endl;
    cout << "First, enter the degree: ";
    cin >> deg;
    cout << "Next, enter the minutes of arc: ";
    cin >> min;
    cout << "Finally, enter the seconds of arc: ";
    cin >> sec;

    double wei = deg + min / 60.0 + sec / 60.0 / 60.0;

    cout << deg << " degrees, " << min << " minutes, " << sec << " seconds = " << wei << " degrees" << endl;

    return 0;
}
