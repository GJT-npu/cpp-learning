#include<iostream>
#include<string>
using namespace std;
struct car
{
    string manufacturer;
    int manu_year;
};

int main(void)
{
    int num;

    cout << "How many cars do you wish to catalog? ";
    (cin >> num).get();   //数字字符混合输入一定要读出空字符再输入字符串

    car *pc = new car[num];  //delete不要忘

    for (int i = 0; i < num; i++)
    {
        cout << "Car #" << i + 1 << ":\n";
        cout << "Please enter the make: ";
        getline(cin, (pc + i)->manufacturer);
        cout << "Please enter the year made: ";
        (cin >> (pc + i)->manu_year).get(); // 数字字符混合输入一定要读出空字符再输入字符串
    }
    cout << "Here is your collection: \n";
    for (int i = 0; i < num; i++)
    {
        cout << (pc + i)->manu_year << " " << (pc + i)->manufacturer << endl;
    }

    delete[] pc;

    return 0;
}