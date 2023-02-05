#include<iostream>
using namespace std;

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    inflatable *ps = new inflatable;
    cout << "Enter name of inflatable item: ";
    cin.get(ps->name, 20);//结构体指针访问成员，使用->
    cout << "Enter volume in cubic feet: ";
    cin >> ps->volume;
    cout << "Enter price $";
    cin >> ps->price;

    cout << "Nanme: " << ps->name << endl;
    cout << "Volume: " << ps->volume << endl;
    cout << "Price: $" << ps->price << endl;
    delete ps;

    return 0;
}