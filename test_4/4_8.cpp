#include<iostream>
using namespace std;

int main(void)
{
    int nights = 1001;
    int *pt = new int;
    *pt = 1001;

    cout << "nights value = " << nights << ",location = " << &nights << endl;
    cout << "int value = " << *pt << ", location = " << pt << endl;

    double *pd = new double;
    *pd = 27348.39;

    cout << "double value = " << *pd << ", location = " << pd << endl;

    cout << "*pd location = " << &pd << endl;//取出指针的地址

    cout << "size of pt = " << sizeof(pt) << "; size of *pt = " << sizeof(*pt) << endl;
    cout << "size of pd = " << sizeof(pd) << "; size of *pd = " << sizeof(*pd) << endl;

    return 0;
}