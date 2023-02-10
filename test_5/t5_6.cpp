#include<iostream>
#include<string>
using namespace std;
const int YEARS = 3;
const int MONTHS = 12;

int main(void)
{
    const string year[YEARS] =
        {
            "The sales of 2020: ",
            "The sales of 2021: ",
            "The sales of 2022: ",
        };
    int sales[YEARS][MONTHS] =
        {
            {10,10,10,10,10,10,10,10,10,10,10,10},
            {20,20,20,20,20,20,20,20,20,20,20,20},
            {30,30,30,30,30,30,30,30,30,30,30,30},
        };
    int sum_3 = 0;
    for (int i = 0; i < YEARS; i++)
    {
        cout << year[i];
        int sum = 0;
        for (int j = 0; j < MONTHS; j++)
        {
            sum += sales[i][j];
        }
        cout << sum << endl;
        sum_3 += sum;
    }
    cout << endl
         << "The sales of three years: " << sum_3 << endl;

    return 0;
}