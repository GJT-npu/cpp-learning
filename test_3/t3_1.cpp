//英尺转换英寸
#include<iostream>
using namespace std;

const int FOOT_TO_INCH = 12;

int main(void)
{
    int h;

    cout << "Please enter your height int inches_";
    cin >> h;
    cout << "Your height convert to " << h / FOOT_TO_INCH;
    cout << " FOOT and " << h % FOOT_TO_INCH << " INCHES height." << endl;


    return 0;
}