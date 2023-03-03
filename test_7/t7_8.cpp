#include<iostream>
#include<string>
using namespace std;

const int Seasons = 4;

const char *Snames[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double arr[], int n);
void show(const double arr[], int n);

int main(void)
{
    double expenses[Seasons];

    fill(expenses, Seasons);
    show(expenses, Seasons);

    return 0;
}

void fill(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}
void show(const double arr[], int n)
{
    double total = 0;
    cout << "EXPENSES: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << Snames[i] << ": $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total expenses: " << total << endl;
}