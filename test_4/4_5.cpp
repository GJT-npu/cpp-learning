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
    inflatable guest =
    {
        "Glorious Gloria",
        1.88,
        29.99
    };
    inflatable pal =
    {
        "Audacious Arthur",
        3.12,
        32.99
    };

    cout << "Enter your guest list with " << guest.name << " and " << pal.name << endl;
    cout << "You can have both for $" << guest.price + pal.price << endl;

    return 0;
}