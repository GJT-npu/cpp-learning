#include <iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "How many carrots do you have?" << endl;
    cin >> carrots;                       // 程序输入流流入carrots中
    cout << "Here are two more." << endl; // 不加 endl 两句话将连在一起，不会因为中间有其他语句而分开
    carrots += 2;
    cout << "Now you have " << carrots << " carrots." << endl;

    return 0;
}