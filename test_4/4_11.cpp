#include<iostream>
#include<cstring>
using namespace std;

int main(void)
{
    char animal[20] = "bear";
    const char *bird = "wren";
    char *ps;

    cout << animal << " and " << bird << endl;

    cout << "Enter a kind of animal: ";
    cin >> animal;
    cout << animal << endl;

    ps = animal;
    cout << ps << endl;

    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    cout << "After using strcpy.\n";
    ps = new char[strlen(animal) + 1];
    strcpy(ps, animal);
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;
    delete[] ps;

    return 0;
}