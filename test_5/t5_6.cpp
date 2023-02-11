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
    const char *months[MONTHS] =
        {
            "Enter the sales in Jan. :",
            "Enter the sales in Feb. :",
            "Enter the sales in Mar. :",
            "Enter the sales in Apr. :",
            "Enter the sales in May. :",
            "Enter the sales in Jun. :",
            "Enter the sales in Jul. :",
            "Enter the sales in Aug. :",
            "Enter the sales in Sep. :",
            "Enter the sales in Oct. :",
            "Enter the sales in Nov. :",
            "Enter the sales in Dec. :",
        };
    int sales[YEARS][MONTHS];
    //     {
    //         {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10},
    //         {20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20, 20},
    //         {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30}
    //     };
    int sum_3 = 0;
    for (int i = 0; i < YEARS; i++)
    {
        cout << "Starting " << i + 1 << " year's date: " << endl;
        int sum = 0;
        for (int j = 0; j < MONTHS; j++)
        {
            cout << months[j];
            cin >> sales[i][j];
            sum += sales[i][j];
        }
        cout  << year[i];
        cout << sum << endl
             << endl;
        sum_3 += sum;
    }
    cout << "Input Done!" << endl;
    cout << "The sales of three years: " << sum_3 << endl;

    return 0;
}