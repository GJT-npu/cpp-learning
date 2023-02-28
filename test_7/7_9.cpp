#include<iostream>
using namespace std;

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int levels);

int main(void)
{
    char ruler[Len];

    for (int i = 0; i < Len; i++)
        ruler[i] = ' ';

    int min = 0;
    int max = Len - 2;
    ruler[Len - 1] = '\0';
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;  //打印第一行

    for (int i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
    }

    return 0;
}

void subdivide(char ar[], int low, int high, int levels)
{
    if(levels == 0)
        return;

    int mid = (low + high) / 2;
    ar[mid] = '|';

    subdivide(ar, low, mid, levels - 1);
    subdivide(ar, mid, high, levels - 1);
}