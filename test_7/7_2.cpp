#include<iostream>
using namespace std;

const int MAX = 5;

int fill_array(double arr[], int limit);
void show_array(const double arr[], int n);
void revalue(double r, double arr[], int n);

int main(void)
{
    double properties[MAX];

    //读入房地产价值数组
    int size = fill_array(properties, MAX);

    //显示数组
    show_array(properties, MAX);

    //重新评估房地产价值
    if(size > 0)
    {
        cout << "Enter revalution factor: ";  //比例系数，调整价格
        double factor;
        while(!(cin >> factor))   //只要输入不是数字，就重新输入
        {
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input: input process terminated." << endl;
        }
        revalue(factor, properties, size);
        show_array(properties, size);
    }

    return 0;
}

int fill_array(double arr[], int limit)
{
    double temp = 0;
    int i = 0;

    for (i = 0; i < MAX; i++)
    {
        cout << "Enter value #" << i + 1 << ": ";
        cin >> temp;   //不能小于0；不能为字符
        if(!cin)       //cin失败，读入字符，结束输入
        {
            cin.clear();
            while(cin.get() != '\n')
            {
                continue;
            }
            cout << "Bad input: input process terminated." << endl;
            break;
        }
        else if(temp < 0)  //cin失败。读入负数
            break;
        else
            arr[i] = temp;
    }
    return i;
}

void show_array(const double arr[], int n)   //不能通过指针修改原地址变量
{
    for (int i = 0; i < n; i++)
    {
        cout << "Property #" << i + 1 << ": $";
        cout << arr[i] << endl;
    }
}

void revalue(double r, double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] *= r;
    }
}
