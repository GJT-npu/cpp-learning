#include<iostream>
#include<string>
using namespace std;

int main(void)
{
    string s1 = "penguin";
    string s2, s3;

    cout << "You can assign one string object to another: s2 = s1\n";
    s2 = s1; //可以直接赋值
    cout << "s1: " << s1 << ", s2: " << s2 << endl;

    cout << "You can assign a C-style string to a string object.\n";
    s2 = "buzzard"; //赋值进行更改
    cout << "s2: " << s2 << endl;

    cout << "You can concatennate strings: s3 = s1 + s2\n";
    s3 = s1 + s2;//加号 进行字符串合并
    cout << "s3: " << s3 << endl;

    s1 += s2; //+=附加一个字符串
    cout << "s1 += s2 yields s1 = " << s1 << endl;

    s2 += " for a day."; //+=附加字符串
    cout << "s2 =+ \" for a day\" yields s2 = " << s2 << endl;

    return 0;
}