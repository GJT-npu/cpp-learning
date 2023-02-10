#include<iostream>
using namespace std;

const int Cities = 5;
const int Years = 4;

int main(void)
{
    const char *cities[Cities] =
        {
            "Gribble City",
            "Gribbletown",
            "New Gribble",
            "San Gribble",
            "Gribble Vista"
        };
    int maxtemps[Years][Cities] =
        {
            {96,100,27,101,105},
            {96,98,91,107,104},
            {97,101,93,108,107},
            {98,103,95,109,108}
        };

    cout << "Maximun temperatures for 2008 ~ 2011\n\n";
    for (int j = 0; j < Cities; j++) //城市
    {
        cout << cities[j] << ": \t";
        for (int i = 0; i < Years; i++)  //年份
        {
            cout << maxtemps[i][j] << "\t";
        }
        cout << endl;
    }

        return 0;
}