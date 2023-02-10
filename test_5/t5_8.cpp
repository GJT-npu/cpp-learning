#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    char arr[100];
    int i = 0;

    cout << "Enter words (to stop, type the word done): " << endl;
    cin >> arr;

    while(strcmp(arr,"done") != 0)
    {
        cin >> arr;
        i++;
    }

    cout << "You entered a total of " << i << " words.\n";

    return 0;
}