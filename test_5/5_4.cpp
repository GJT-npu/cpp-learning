#include<iostream>
using namespace std;

int main(void)
{
    char name[20];

    cout << "Your first namem please: ";
    cin >> name;

    cout << "Here is your name: " << endl;

    int i = 0;
    while(name[i]!='\0')
    {
        cout << name[i] << ": " << (int)name[i] << endl;
        i++;
    }

    return 0;
}