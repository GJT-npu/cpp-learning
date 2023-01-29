#include<iostream>
void simon(int n);      //函数原型声明

int main()
{
    using namespace std;

    simon(3);          //函数调用
    cout << "Pick an integer: ";
    int count;
    cin >> count;
    simon(count);
    cout << "Done!" << endl;

    return 0;
}

void simon(int n)      //函数定义
{
    using namespace std;

    cout << "Simon sys touch your toes " << n << " times. " << endl;
}