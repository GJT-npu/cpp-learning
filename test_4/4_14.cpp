#include<iostream>
using namespace std;

struct aye
{
    int year;
};

int main(void)
{
    aye s1, s2, s3;

    s1.year = 1998;

    aye *pa = &s2;
    pa->year = 1999;

    aye trio[3];
    trio[0].year = 2003;

    cout << trio->year << endl;

    const aye *arp[3] = {&s1, &s2, &s3};
    cout << arp[1]->year << endl;

    const aye **ppa = arp;
    cout << (*ppa)->year << endl;  //*ppa = arp[0]

    auto ppb = arp;
    cout << (*(ppb + 1))->year << endl;

    return 0;
}