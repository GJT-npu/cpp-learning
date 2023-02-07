#include<iostream>
#include<string>
using namespace std;
struct message
{
    string first_name;
    string last_name;
    char l_grade;
    int age;
};

int main(void)
{
    message GJT;

    cout << "What is your first name? ";
    getline(cin, GJT.first_name);
    cout << "What is your last name? ";
    cin >> GJT.last_name;
    cout << "What latter grade do you deserve? ";
    cin >> GJT.l_grade;
    cout << "What is your age? ";
    cin >> GJT.age;

    cout << "Name: " << GJT.last_name << ", " << GJT.first_name << endl;
    cout << "Grade: " << char(GJT.l_grade + 1) << endl;
    cout << "Age: " << GJT.age << endl;

    return 0;
}