#include<iostream>
using namespace std;
void showmenu(void);

int main(void)
{
    showmenu();

    char ch;
    cin >> ch;
    while(1)
    {
        switch(ch)
        {
            case 'c':
                cout << "A maple is a carnivore.\n";
                break;
            case 'p':
                cout << "A maple is pianist.\n";
                break;
            case 't':
                cout << "A maple is a tree.\n";
                break;
            case 'g':
                cout << "A maple is a game.\n";
                break;
            default:
                cout << "Please enter a c, p, t, or g: ";
        }
        if(ch == 'c' || ch == 'p' || ch == 't' || ch == 'g')
            break;   
        else
            cin >> ch;
    }

    return 0;
}

void showmenu(void)
{
    cout << "Please enter one of the following choices:\n";
    cout << "c)canivore         p)pianist" << endl;
    cout << "t)tree             g)game" << endl;
}