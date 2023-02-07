#include<iostream>
#include<array>
using namespace std;

int main(void)
{
    array<double, 3> grade;

    cout << "Enter three records of 40 meters: " << endl;
    cout << "Enter your first record of 40m: ";
    cin >> grade[0];
    cout << "Enter your second record of 40m: ";
    cin >> grade[1];
    cout << "Enter your third record of 40m: ";
    cin >> grade[2];

    double average = (grade[0] + grade[1] + grade[2]) / 3.0;

    cout << endl
         << "1st: " << grade[0] << "; 2nd: " << grade[1] << "; 3rd: " << grade[2] << endl;
    cout << "You ran 3 times, and you average record is: " << average << endl;

    return 0;
}