#include<iostream>
#include<string>
using namespace std;
struct CandyBar
{
    string brand;
    double weight;
    int calorie;
} snack =
    {
        "Mocha Munch",2.3,350
    };
int main(void)
{
    cout << "This snack is: " << snack.brand << ", " << snack.weight << ", " << snack.calorie << endl;

    return 0;
}