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
    William *pw = new William;

    cout << "Enter the diameter of the pizza: ";
    cin >> pw->diameter;
    cin.get();
    cout << "Enter the name of the pizza company: ";
    getline(cin, pw->name);
    cout << "Enter the weight of the pizza: ";
    cin >> pw->weight;

    cout << "Pizza company is: " << pw->name << ", diameter in inches: " << pw->diameter << ", weight in pounds: " << pw->weight << "." << endl;

    delete pw;

    return 0;
}