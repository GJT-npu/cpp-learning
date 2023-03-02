#include<iostream>
using namespace std;

int main(void)
{
    double arr[10] = {0};
    int i = 0;
    double total = 0;

    cout << "Enter the scores of golf(up to 10, 'q' to quit): ";
    while(cin >> arr[i])
    {
        i++;
        if (i < 10)
            cout << "Enter again" << i + 1 << ": ";
        else
            break;
    }

    cout << "The scores are: ";

    for (int j = 0; j < i; j++)
    {
        total += arr[j];
        cout << arr[j] << " ";
    }

    cout << "\nThe avarage is " << total / i << endl;

    return 0;
}