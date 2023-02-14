#include<iostream>
#include<cctype>
using namespace std;

int main(void)
{
    cout << "Enter text for analysis, and type @ to terminate input.\n";

    char ch;

    cin.get(ch);
    while (ch != '@')
    {
        if(isdigit(ch))
        {
            cin >> ch;
            continue;
        }
        else if(islower(ch))
            ch = tolower(ch);
        else if(isupper(ch))
            ch = toupper(ch);
        else
            ;

        cout << ch;
        cin.get(ch); // 更新条件
    }

    cout << endl;

    return 0;
}
