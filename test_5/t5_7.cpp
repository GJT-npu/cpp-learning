#include<iostream>
#include<string>
using namespace std;
struct car
{
    string manufactruler;
    int manu_year;
};

int main(void)
{
    int num;
    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();   //数字字符混合输入一定要读出空字符再输入字符串
    car *pc = new car[num];
    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ":\n";
        cout << "Please enter the make: ";
        getline(cin, pc[i].manufactruler);
        cout << "Please enter the year made: ";
        (cin >> pc[i].manu_year).get();   //数字字符混合输入一定要读出空字符再输入字符串
    }
    cout << "Here is your collection: \n";
    cout << pc->manu_year << " " << pc->manufactruler << endl;
    cout << (pc + 1)->manu_year << " " << (pc + 1)->manufactruler << endl;

    delete[] pc;

    return 0;
}