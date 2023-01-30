#include <iostream>
using namespace std;
double lttoas(double ly);

int main(void)
{
    double ltyear;

    cout << "Enter thr number of light years: ";
    cin >> ltyear;

    double asun = lttoas(ltyear);
    cout << ltyear << " light years = " << asun << " astronomical units.";

    return 0;
}

double lttoas(double ly)
{
    return ly * 63240;
}