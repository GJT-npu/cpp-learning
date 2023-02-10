#include<iostream>
using namespace std;

int main(void)
{
    int year, bj = 100;
    int Daph = 100, Cleo = 100;

    for (year = 1; Cleo <= Daph; year++)
    {
        Daph = 0.1 * bj + Daph;
        Cleo = 0.05 * Cleo + Cleo;
    }

    cout << year - 1 << " years later. The investment value of Cleo exceeds the investment value of Daphne.\n\n";
    cout << "Daphne: " << Daph << ", Cleo: " << Cleo << endl;

    return 0;
}