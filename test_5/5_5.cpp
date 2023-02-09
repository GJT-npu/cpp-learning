//延时

#include<iostream>
#include<ctime>
using namespace std;

int main(void)
{
    cout << "Enter the delay time, in seconds: ";

    float secs;
    cin >> secs;
    clock_t delay = secs * CLOCKS_PER_SEC;  //延时的时钟节拍
    //获得当前的时钟节拍

    clock_t start = clock();
    while(clock()-start<delay)
        ;
    cout << "Done!" << endl;

    return 0;
}