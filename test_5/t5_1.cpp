#include<iostream>
using namespace std;

int main(void)
{
    int m, n;
    cout << "Please enter two numbers: " << endl;
    cin >> m;  //m存小数
    cin >> n;  //n存大数
    int temp;
    if(m >= n)
    {
        temp = m;
        m = n;
        n = temp;
    }

    temp = 0;
    for (int i = m; i <= n; i++)
    {
        temp += i;
    }

    cout << "The sum of all the numbers between " << m << " and " << n << " = " << temp << endl;

    return 0;
}