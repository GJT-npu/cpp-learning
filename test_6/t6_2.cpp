#include<iostream>
using namespace std;
const int MAX = 10;

int main(void)
{
    double Donation[MAX] = {0};

    cout << "Please enter the donation.\n";
    cout << "You may enter up to 10 donations <not number to terminate>.\n";

    //输入最多10个donation
    cout << "donation #1: ";
    int i = 0;
    while (i < MAX && cin >> Donation[i])
    {
        if(++i < MAX)
        {
            cout << "donation #" << i + 1 << ": ";
        }
    }

    //计算平均值
    double total;
    for (int j = 0; j < MAX; j++)
    {
        total += Donation[j];
    }
    double average = total / i;

    //计数
    int count = 0, count_t = 0;
    for (int j = 0; (j < MAX) && (Donation[j] != 0) ; j++)
    {
        ++count;
        if (Donation[j] > average)
            ++count_t;
    }

    if (0 == i)
    {
        cout << "No donation.\n";
    }
    else
    {
        cout << "Average of " << count << " donations = " << average << ", and " << count_t << " donations are upper than average.\n";
    }

        return 0;
}