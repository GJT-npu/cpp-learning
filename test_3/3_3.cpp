#include <iostream>
using namespace std;

int main(void)
{
    int chest = 42;
    int waist = 0x42;
    int inseam = 042;

    cout << "Monsieur cuts a striking figure!" << endl;
    cout << "chest = " << chest << " (in decimal)" << endl;

    cout << hex;
    cout << "waist = " << waist << " (in hex)" << endl;

    cout << oct;
    cout << "inseam = " << inseam << " (in octal)" << endl;

    return 0;
}
