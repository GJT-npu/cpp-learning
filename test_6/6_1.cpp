#include<iostream>
using namespace std;
const int SIZE = 6;

int main(void)
{
    float value[SIZE];
    float temp;
    int i = 0;

    cout << "Enter six numbers and compare with your level." << endl;
    cout << "Terinate condition, when you make 6 number or enter a nagative number" << endl;

    cout << "First value: ";
    cin >> temp;

    while(i < SIZE && temp >= 0)
    {
        value[i] = temp;
        ++i;
        if(i < SIZE)
        {
            cout << "Next value: ";
            cin >> temp;
        }
    }
    if(i == 0)
    {
        cout << "No data--bye.\n";
    }
    else
    {
        cout << "Enter your level: ";
        float level;
        cin >> level;
        int count = 0;
        for (int j = 0; j < i; j++)
        {
            if(value[j] > level)
            {
                count++;
            }
        }
        cout << count << " numbers are bigger the your level.\n";
    }

    return 0;
}