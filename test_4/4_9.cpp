#include<iostream>
using namespace std;

int main(void)
{
    double *p3 = new double[3];
    p3[0] = 0.2;
    p3[1] = 0.5;
    p3[2] = 0.8;

    cout << "p3[1] is " << p3[1] << endl;
    cout << "(p3 + 1) is: " << *(p3 + 1) << endl;

    delete[] p3;//与new配套，释放内存

    return 0;
}