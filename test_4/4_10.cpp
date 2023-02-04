#include<iostream>
using namespace std;

int main(void)
{
    double wages[3] = {100.0, 200.0, 299.9};
    short stacks[3] = {3, 2, 1};

    double *pw = wages;      //数组名表示数组首元素地址
    short *ps = &stacks[0];

    cout << "pw = " << pw << ", *pw = " << *pw << endl;
    pw += 1;
    cout << "add 1 to the pw pointer:" << endl;
    cout << "pw = " << pw << ", pw = " << *pw << endl;

    cout << endl;

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps += 1;
    cout << "add 1 to the ps pointer:" << endl;
    cout << "ps = " << ps << ", ps = " << *ps << endl;

    cout << endl;

    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    cout << "*stacks = " << *stacks << ", *(stacks+1) = " << *(stacks + 1) << endl;

    cout << "size of wages array = " << sizeof(wages) << endl;
    cout << "size of pw pointer = " << sizeof(pw) << endl;
 
    return 0;
}