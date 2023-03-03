#include<iostream>
using namespace std;
const int Size = 10;

int Fill_array(double arr[], int n);
void Show_array(double arr[], int n);
void Reverse_array(double arr[], int n);

int main(void)
{
    double arr[Size];

    //填入数组元素
    int fac = Fill_array(arr, Size);
    //cout << "You have entered " << count << " numbers.\n";
    Show_array(arr, fac);

    //反转所有元素
    Reverse_array(arr, fac);
    Show_array(arr, fac);

    //反转除第一、最后两个元素的所有元素
    Reverse_array(arr, fac);
    Show_array(arr, fac);

    return 0;
}

int Fill_array(double arr[], int n)
{
    int i = 0;
    double temp = 0;
    for (i = 0; i < n; i++)
    {
        cout << "Enter number, No." << i + 1 << ": ";
        cin >> temp;
        if (!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                ;
            cout << "Invailed input, terminate." << endl;
            break;
        }
        else
            arr[i] = temp;
    }
    return i;
}
void Show_array(double arr[], int n)
{
    cout << "\n********The array********\n";
    for (int i = 0; i < n; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    }
}
void Reverse_array(double arr[], int n)
{
    int a, b;
    cout << "Please enter the number(a to b) you want to reverse: ";
    cin >> a >> b;

    double tem;

    while (a < b)
    {
        tem = arr[a - 1];
        arr[a - 1] = arr[b - 1];
        arr[b - 1] = tem;

        a++;
        b--;
    }
}