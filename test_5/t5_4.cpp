#include<iostream>
using namespace std;

int main(void)
{
    int year, bj = 100;
    double Daph = 100, Cleo = 100;

    for (year = 0; Cleo <= Daph; year++)
    {
        Daph += 0.1 * bj;
        Cleo += 0.05 * Cleo;
    }

    cout << year << " years later. The investment value of Cleo exceeds the investment value of Daphne.\n\n";
    cout << "Daphne: " << Daph << "$, Cleo: " << Cleo << "$" << endl;

    return 0;
}