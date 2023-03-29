#include<iostream>
using namespace std;

int main(void)
{
    int rats = 101;
    int &rodents = rats;

    cout << "rats = " << rats << endl;
    cout << "rodnets = " << rodents << endl;

    // rodents++;
    // cout << "rats = " << rats << endl;
    // cout << "rodnets = " << rodents << endl;

    // cout << "&rats = " << &rats << endl;
    // cout << "&rodents = " << &rodents << endl;

    int bummies = 50;
    rodents = bummies;  //纯赋值，并没有和bummies关联起来
    cout << "bummies = " << rats << endl;
    cout << "rodnets = " << rodents << endl;
    cout << "rats = " << rats << endl;

    return 0;
}