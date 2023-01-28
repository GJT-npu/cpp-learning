#include<iostream>

int main()
{
    using namespace std;

    int carrots;   //声明语句创建变量

    carrots = 20;  //赋值语句给变量提供一个值
    cout << "I have ";
    cout << carrots;
    cout << " carrots.";
    cout << endl;
    
    carrots -= 1;
    cout << "Cruch, Cruch, Now I have " << carrots << " carrots." << endl;

    return 0;
}