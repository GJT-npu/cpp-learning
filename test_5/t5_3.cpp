#include<iostream>
using namespace std;

int main(void)
{
    double sum, input;

    cout << "Enter a number and Calculate the sum of all the numbers entered untill meeting number 0: ";
    cin >> input;
    while (input)
    {
        sum += input;
        cout << "The sum = " << sum << endl;
        cin >> input;
    }
    cout << "Game over, the sum = " << sum << endl;

    return 0;
}