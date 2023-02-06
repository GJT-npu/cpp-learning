#include<iostream>
#include<cstring>
using namespace std;
char *getname();

int main(void)
{
    char *name;
    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    name = getname();
    cout << name << " at " << (int *)name << endl;
    delete[] name;

    return 0;
}

char *getname()
{
    char arr[80];
    cout << "Enter last name: ";
    cin >> arr;
    char *pn = new char[strlen(arr) + 1];
    strcpy(pn, arr);

    return pn;
}