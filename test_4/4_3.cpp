#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    char arr1[20];
    char arr2[20] = "jaguar";
    string str1;
    string str2 = "panther";

    cout << "Enter a kind of feline: ";
    cin >> arr1;
    cout << "Enter another kind of feline: ";
    cin >> str1;
    cout << "Here are some felines:\n";
    cout << arr1 << " " << arr2 << " " << str1 << " " << str2 << endl;

    cout << "The third letter in " << arr2 << " is " << arr2[2] << endl;
    cout << "The third letter in " << str2 << " is " << str2[2] << endl;

    cout << sizeof(str2) << endl;

    return 0;
}