#include<iostream>
using namespace std;
const int SIZE = 80;

int main(void)
{
    char line[SIZE];
    int spaces = 0;

    cout << "Enter a line of text: \n";
    cin.get(line, SIZE);

    cout << "Complete line: " << line << endl;

    for (int i = 0; line[i] != '\0'; i++)
    {
        cout << line[i];

        //碰到句号，结束循环
        if(line[i] == '.')
            break;

        //不是空格就跳过，进行下一次循环
        if(line[i] != ' ')
            continue;

        //计算空格数量
        spaces++;
    }
    cout << endl;
    cout << "Spaces = " << spaces << endl;

    return 0;
}