#include<iostream>
int stonetolb(int sts);

int main()
{
    using namespace std;

    int stone;
    cout << "Enter the weight in stone: ";
    cin >> stone;

    int pounds = stonetolb(stone);
    cout << stone << " stone = "
         << pounds << " pounds." << endl;

    return 0;
}

//1 stone = 14 lbs
int stonetolb(int sts)
{
    return 14 * sts;
}