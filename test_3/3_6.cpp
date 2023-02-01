#include<iostream>
using namespace std;

int main(void)
{
    cout.setf(ios_base::fixed, ios_base::floatfield);

    float tub = 10.0 / 3.0;
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << " , A million tubs = " << tub * million << endl;
    cout << "Ten million tubs = " << 10 * tub * million << endl;

    double mint = 10.0 / 3.0;

    cout << "mint = " << mint;
    cout << " , A million mints = " << mint * million << endl;
    cout << "Ten million mints = " << 10 * mint * million << endl;

    return 0;
}