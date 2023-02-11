#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string arr;
    int i = 0;

    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> arr;

    while (arr != "done")
    {
        cin >> arr;
        i++;
    }

    cout << "You entered a total of " << i << " words.\n";

    return 0;
}