#include<iostream>
using namespace std;

int main(void)
{
    double arr[5] = {21.1, 53.2, 763.2, 63.98, 273.7};
    double *pa = arr;

    cout << "*pa = " << *pa << endl;
    cout << "*++pa = " << *++pa << endl;
    cout << "++*pa = " << ++*pa << endl;
    cout << "(*pa)++ = " << (*pa)++ << endl;
    cout << "*pa = " << *pa << endl;
    cout << "*pa++ = " << *pa++ << endl; //指针先用后挪到下一个
    cout << "*pa = " << *pa << endl;

    return 0;
}