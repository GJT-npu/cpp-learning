#include<iostream>
using namespace std;
const int SIZE = 20;
const int userSize = 5;
void showmenu(void);

struct bop
{
    char fullname[SIZE];
    char tile[SIZE];
    char bopname[SIZE];
    int perference;
};

void show(bop arr[], int size, char ch);

int main(void)
{
    showmenu();

    bop CXY[userSize] =
        {
            {"Wimp Macho", "Senior Programmer", "DAVIS", 0},
            {"Raki Rhodes", "Junior Programmer", "MIKE", 1},
            {"Celia Laiter", "Analyst Trainee", "MIPS", 2},
            {"Hoppy Hipam", "Analyst Trainee", "CURRY", 1},
            {"Pat Hand", "Junior Programmer", "LOOPY", 2}
        };

    cout << "Enter your choice: ";
    char choice;
    cin >> choice;
    while(1)
    {
        switch (choice)
        {
            case 'a':
                show(CXY,userSize,'a');
                break;
            case 'b':
                show(CXY,userSize,'b');
                break;
            case 'c':
                show(CXY,userSize,'c');
                break;
            case 'd':
                show(CXY,userSize,'d');
                break;
            case 'q':
                cout << "Bye!\n";
                break;
            default:
                cout << "Please enter a a, b, c, d, or q: ";
        }

        if (choice == 'a' || choice == 'b' || choice == 'c' || choice == 'd')
        {
            cout << endl << "Next choice: ";
            cin >> choice;
        }
        else if(choice == 'q')
        {
            break;
        }
        else
        {
            cin >> choice;
        }
    }

    return 0;
}

void showmenu(void)
{
    cout << "Benevolent order of Programmers Report\n";
    cout << "a. display by name      b. display by title\n";
    cout << "c. display by bopname   d. display by preference\n";
    cout << "q. quit\n";
}
void show(bop arr[], int size, char ch)
{
    switch(ch)
    {
        case 'a':
            for (int j = 0; j < size; j++)
            {
                cout << arr[j].fullname << endl;
            }
            break;
        case 'b':
            for (int j = 0; j < size; j++)
            {
                cout << arr[j].tile << endl;
            }
            break;
        case 'c':
            for (int j = 0; j < size; j++)
            {
                cout << arr[j].bopname << endl;
            }
            break;
        case 'd':
            for (int j = 0; j < size; j++)
            {
                switch(arr[j].perference)
                {
                    case 0:
                        cout << arr[j].fullname << endl;
                        break;
                    case 1:
                        cout << arr[j].tile << endl;
                        break;
                    case 2:
                        cout << arr[j].bopname << endl;
                        break;
                }
            }
            break;
    }
}