#include<iostream>
using namespace std;
double harmonic_average(int x, int y);

int main(void)
{
    double x, y;

    cout << "Please enter two number: ";
    while(cin>>x>>y)
    {
        if(x!=0 && y!=0)
        {
            double ha = harmonic_average(x, y);
            cout << "The harmonic average is " << ha << endl;
            cout << "Enter two number again: ";
        }
        else
        {
            cout << "Over!\n";
            break;
        }
    }

    return 0;
}

double harmonic_average(int x, int y)
{
    return 2.0 * x * y / (x + y);
}