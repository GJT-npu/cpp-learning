#include<iostream>
#include<string>
using namespace std;
struct William
{
    string name;
    double diameter;
    double weight;
};

int main(void)
{
    William pizza[3];
    
    cout << "Enter the name of the pizza company: ";
    getline(cin, pizza[0].name);
    cout << "Enter the diameter of the pizza in inches: ";
    cin >> pizza[0].diameter;
    cout << "Enter the weight of the pizza in pounds: ";
    cin >> pizza[0].weight;

    cout << "Pizza company is: " << pizza[0].name << ", diameter in inches: " << pizza[0].diameter << ", weight in pounds: " << pizza[0].weight << "." << endl;

    return 0;
}