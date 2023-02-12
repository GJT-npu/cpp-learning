#include<iostream>
using namespace std;
void showmenu(void);
void report();
void comfort();

int main(void)
{
    showmenu();

    int choice;
    cin >> choice;
    while(choice != 5)
    {
        switch(choice)
        {
            case 1:
                cout << "warning!!!" << endl;
                break;
            case 2:
                report();
                break;
            case 3:
                cout << "The boss was in all day." << endl;
                break;
            case 4:
                comfort();
                break;
            default:
                cout << "That is not a choice." << endl;
        }
        cout << endl;
        showmenu();
        cin >> choice;
    }

    cout << "Game over." << endl;

    return 0;
}

void showmenu(void)
{
    cout << "Please enter 1, 2, 3, 4, or 5:" << endl;
    cout << "1) alarm           2) report" << endl;
    cout << "3) alibi           3) comfrt" << endl;
    cout << "5) quit" << endl;
}
void report()
{
    cout << "Sales are up 120%, expenses are down 35%." << endl;
}
void comfort()
{
    cout << "You are the best CEO!" << endl;
}