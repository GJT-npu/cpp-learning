#include <iostream>
using namespace std;
struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main(void)
{
    inflatable guests[2] =
        {
            {"Bambi", 0.5, 21.99},
            {"Godazilla", 2000, 565.99}};

    cout << "The guests " << guests[0].name << " and " << guests[1].name << " have a combined volume of "
         << guests[0].volume + guests[1].volume << " cubic feet." << endl;

    return 0;
}