#include<iostream>
using namespace std;
double GJT(int lines);
double CBC(int lines);
void estimate(int lines, double (*pf)(int));

int main(void)
{
    int code = 0;

    cout << "How many lines code do you need?: ";
    cin >> code;
    cout << "Here is GJT's estimate: " << endl;
    estimate(code, GJT);
    cout << "Here is CBC's estimate: " << endl;
    estimate(code, CBC);

    return 0;
}
double GJT(int lines)
{
    return lines * 0.05;
}
double CBC(int lines)
{
    return lines * 0.03 + 0.004 * lines * lines;
}
void estimate(int lines, double (*pf)(int))
{
    cout << lines << " lines code will take " << (*pf)(lines) << " seconds." << endl;
}