#include<iostream>
using namespace std;
const int MAX = 5;

int main(void)
{
    int golf[MAX];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << MAX << " rounds.\n";
    
    int i;
    for (i = 0; i < MAX; i++)
    {
        cout << "Round#: " << i + 1 << ": " << endl;
        while (!(cin >> golf[i]))
        {
            cin.clear();
            while(cin.get() != '\n')
                ;
            cout << "Please enter a number: ";
        }
    }

    double total = 0.0;
    for (i = 0; i < MAX; i++)
    {
        total += golf[i];
    }
    cout << "Average score: " << total / MAX << ".\n";

    return 0;
}