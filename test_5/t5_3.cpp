#include<iostream>
using namespace std;

int main(void)
{
    double sum, input;

    //cout << "Enter a number to add: ";
    // cin >> input;
    // while (input)
    // {
    //     sum += input;
    //     cout << "The sum = " << sum << endl;
    //     cin >> input;
    // }

    do
    {
        cout << "Enter a number to add: ";
        cin >> input;
        sum += input;
        cout << "The sum = " << sum << endl;
    } while (input != 0);

    cout << endl << "Game over, the sum = " << sum << endl;

    return 0;
}