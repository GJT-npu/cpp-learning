#include<iostream>
using namespace std;

int main()
{
    double distance;

    cout << "Please input the distance: ";
    cin >> distance;

    double ma = distance * 220;
    cout << distance << " long = " << ma << " yard.";

    return 0;
}