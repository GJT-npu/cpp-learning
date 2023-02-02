//输入秒数，以天、小时、分钟、秒的方式显示
#include<iostream>
using namespace std;

int main(void)
{
    long sec;
    int seconds, mintues, hours, days;

    cout << "Enter the number of seconds: ";
    cin >> sec;

    seconds = sec % 60;
    mintues = sec / 60;
    
    hours = mintues / 60;
    mintues %= 60;

    days = hours / 24;
    hours %= 60;

    cout << sec << " seconds = " << days << " days, " << hours << " hours, " << mintues << " minutues, " << seconds << " seconds" << endl;

    return 0;
}