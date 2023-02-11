#include<iostream>
#include<cstring>
using namespace std;
const char DONE[] = "done";

int main(void)
{
    char arr[100];
    int counter = 0;

    cout << "Enter words (to stop, type the word done): " << endl;

    do
    {
        cin >> arr;  //cin会忽略空白符和换行符
        counter++;
    } while (strcmp(arr, DONE) != 0);

    cout << "You entered a total of " << counter - 1 << " words.\n";

    return 0;
}