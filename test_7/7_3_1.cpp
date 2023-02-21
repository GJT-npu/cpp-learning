// const int *pt;  ==  int const *pt;
// int *const pt;
// const int *const pt;

#include<iostream>
using namespace std;

int main(void)
{
    int n = 10;
    int m = 100;
    const int *pt = &n; // 指针设置为常量，不能通过指针修改指向的内容

    cout << "1) n = " << n << endl;
    //*pt = 20;
    pt = &m;
    n = 20;
    cout << "2) n = " << n << endl;
    cout << "*pt = " << *pt << endl;
    cout << "m = " << m << endl;

    return 0;
}