#include <iostream>
using namespace std;

int main(void)
{
    char ch = 'M'; // 存储的是M对应的ASCII值
    int i = ch;    // 赋值的时候把ch里面存储的ASCII取了出来
    cout << "The ASCII code fot " << ch << " is " << i << endl;

    cout << "Add one to the character code: " << endl;
    ch = ch + 1;
    i = ch;
    cout << "The ASCII code for " << ch << " is " << i << endl;
    
    cout << "Displaying char ch using cout.put(ch): ";
    cout.put(ch);
    cout.put('!');

    cout << endl
         << "Done" << endl;

    return 0;
}