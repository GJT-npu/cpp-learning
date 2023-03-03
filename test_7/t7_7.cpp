#include <iostream>
using namespace std;

const int MAX = 5;

double *fill_array(double *begin, double *end);
void show_array(double *begin, double *end);
void revalue(double r, double *begin, double *end);

int main(void)
{
    double properties[MAX];

    // 读入房地产价值数组
    double *pa = fill_array(properties, properties + MAX);

    // 显示数组
    show_array(properties, pa);

    // 重新评估房地产价值
    if ((pa - properties) > 0)
    {
        cout << "Enter revalution factor: "; // 比例系数，调整价格
        double factor;
        while (!(cin >> factor)) // 只要输入不是数字，就重新输入
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input: input process terminated." << endl;
        }
        revalue(factor, properties, pa);
        show_array(properties, pa);
    }

    return 0;
}

double *fill_array(double *begin, double *end)
{
    double temp = 0;
    double *pt;

    for (pt = begin; pt != end; pt++)
    {
        cout << "Enter value #" << (pt - begin) + 1 << ": ";
        cin >> temp; // 不能小于0；不能为字符
        if (!cin)    // cin失败，读入字符，结束输入
        {
            cin.clear();
            while (cin.get() != '\n')
                continue;
            cout << "Bad input: input process terminated." << endl;
            break;
        }
        else if (temp < 0) // cin失败。读入负数
            break;
        else
            *pt = temp;
    }
    return pt;
}

void show_array(double *begin, double *end) // 不能通过指针修改原地址变量
{
    for (double *pt = begin; pt != end; pt++)
    {
        cout << "Property #" << (pt - begin) + 1 << ": $";
        cout << *pt << endl;
    }
}

void revalue(double r, double *begin, double *end)
{
    for (double *pt = begin; pt != end; pt++)
    {
        *pt *= r;
    }
}
