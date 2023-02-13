#include<iostream>
using namespace std;
const int MAX = 5;

int main(void)
{
    double fish[MAX];

    cout << "Please enter the weights of your fish.\n";
    cout << "You may enter up to " << MAX << " fish <q to terminate.\n";

    cout << "fish #1: ";
    int i = 0;

    while(i < MAX && cin >> fish[i])
    {
        if(++i < MAX)
        {
            cout << "fish #" << i + 1 << ": ";
        }
    }

    double total = 0.0;
    for (int j = 0; j < i; j++)
    {
        total = +fish[j];
    }

    if(i==0)
    {
        cout << "No fish." << endl;
    }
    else
    {
        cout << "Average weight of " << i << " fish: " << total / i << endl;
    }

        return 0;
}