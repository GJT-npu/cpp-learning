#include<iostream>
using namespace std;

int main(void)
{
    int year;

    cout << "What year was your house built?" << endl;
    cin >> year;//回车保留在了缓冲区，需要清除
    cin.get();//read enter
    cout << "What is its street address?" << endl;
    char address[80];
    cin.getline(address, 80);

    cout << "Year built: " << year << endl;
    cout << "Address: " << address << endl;

    return 0;
}