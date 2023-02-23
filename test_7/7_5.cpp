#include <iostream>
using namespace std;
char *buildstr(char ch, int n);

int main(void)
{
    char ch;
    int times;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps; // new后释放内存

    return 0;
}
char *buildstr(char ch, int n)
{
    char *ps = new char[n + 1];
    ps[n] = '\0'; // 字符串结尾使'\0'
    for (int i = 0; i < n; i++)
    {
        ps[i] = ch;
    }

    return ps;
}