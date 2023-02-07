#include<iostream>
#include<string>
using namespace std;
struct CandyBar
{
    string brand;
    double weight;
    int calorie;
};

int main(void)
{
    CandyBar snack[3];

    cout << "Enter the brand of the snack: ";
    getline(cin, snack[0].brand);
    cout << "Enter the weight of the snack: ";
    cin >> snack[0].weight;
    cout << "Enter the calorie of the snack: ";
    cin >> snack[0].calorie;

    cout << "This snack is: " << snack[0].brand << ", " << snack[0].weight << ", " << snack[0].calorie << endl;

    return 0;
}