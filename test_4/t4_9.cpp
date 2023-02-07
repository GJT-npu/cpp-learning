#include<iostream>
#include<string>
using namespace std;
const int SIZE = 3;

struct CandyBar
{
    string brand;
    double weight;
    int calorie;
};

int main(void)
{
    CandyBar *pc = new CandyBar[SIZE];

    cout << "Enter the snack's name: ";
    getline(cin, pc->brand);
    cout << "Enter the snack's weight: ";
    cin >> pc->weight;
    cout << "Enter the snack's calorie: ";
    cin >> pc->calorie;

    cout << "This snack is: " << pc->brand << ", " << pc->weight << ", " << pc->calorie << endl;

    delete[] pc; //不要忘记释放内存

    return 0;
}