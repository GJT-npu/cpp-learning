#include<iostream>
using namespace std;
void countdown(int n);

int main(void)
{
    countdown(4);

    return 0;
}

void countdown(int n)
{
    //statement1
    cout << "counting down... " << n << "(n at address: " << &n << " )" << endl;

    //test
    if (n > 0)
    {
        countdown(n-1);
    }

    //statement2
    cout << n << ": Kadoom"
         << "(n at address: " << &n << " )" << endl;
}