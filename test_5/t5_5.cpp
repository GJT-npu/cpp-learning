#include<iostream>
using namespace std;
const int SIZE = 12;

int main(void)
{
    const char *months[SIZE] =
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

    int sales[SIZE];
    int sum = 0;
    for (int i = 0; i < SIZE; i++)
    {
        cout << months[i];
        cin >> sales[i];
        sum += sales[i];
    }

    cout << endl
         << "Input Done!" << endl;
    cout << "The sales of this year: " << sum << endl;

    return 0;
}