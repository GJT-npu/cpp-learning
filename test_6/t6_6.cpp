#include<iostream>
#include<string>
using namespace std;
struct donor
{
    string Name;
    double Figure;
};

int main(void)
{
    int num;
    cout << "Enter the numbers of patrons: ";
    cin >> num;

    donor *pd = new donor[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Name #" << i + 1 << ": ";
        cin >> (pd + i)->Name;
        cout << "Figure #" << i + 1 << ": ";
        cin >> (pd + i)->Figure;
    }

    int count_gp = 0, count_p = 0;
    for (int i = 0; i < num; i++)
    {
        if(((pd+i)->Figure) >= 10000)
            count_gp++;
        else
            count_p++;
    }

    cout << endl
         << "**********Grand Patrons**********\n";
    if (count_gp > 0)
    {
        for (int i = 0; i < num; i++)
        {
            if (((pd + i)->Figure) >= 10000)
            {
                cout << (pd + i)->Name << ": " << (pd + i)->Figure << endl;
            }
        }
    }
    else
    {
        cout << "none.\n";
    }

    cout << "*************Patrons*************\n";
    if (count_p > 0)
    {
        for (int i = 0; i < num; i++)
        {
            if (((pd + i)->Figure) < 10000)
            {
                cout << (pd + i)->Name << ": " << (pd + i)->Figure <<endl ;
            }
        }
    }
    else
    {
        cout << "none.\n";
    }

        return 0;
}