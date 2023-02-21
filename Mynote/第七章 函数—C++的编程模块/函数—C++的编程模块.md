# 函数——C++的编程模块

## 复习函数的基本知识

- 提供函数定义
- 提供函数原型
- 调用函数

### 定义函数

```cpp
typeName functionName(parameterList)
{
    statement;
    return value;
}
```

## 函数参数和按值传参

定义单参数函数

```cpp
double cube(double x)
```

使用函数时，将传递一个名称为 x 的副本变量，值为 5

### 多个参数

调用时使用逗号分隔参数

```cpp
n_chars('R', 25);
```

定义函数时，使用逗号分隔参数声明列表：

```cpp
void n_chars(float a, float b)
```

```cpp
#include<iostream>
using namespace std;
void n_chars(char c, int n);

int main(void)
{
    int times;
    char ch;

    cout << "Enter a character: ";
    cin >> ch;
    while(ch != 'q')
    {
        cout << "Enter an integer: ";
        cin >> times;
        n_chars(ch, times);
        cout << endl;
        cout << "Enter another character or press q_key to quit: ";
        cin >> ch;
    }

    return 0;
}

void n_chars(char c, int n)
{
    while(n-- > 0)
        cout << c;
}
```

输出结果：

```cpp
Enter a character: a
Enter an integer: 20
aaaaaaaaaaaaaaaaaaaa
Enter another character or press q_key to quit: b
Enter an integer: 20
bbbbbbbbbbbbbbbbbbbb
Enter another character or press q_key to quit: q
```

## 函数和数组

```cpp
int sum_arr(int arr[], int n);
```

传递的是数组的地址，下标引用运算符`arr[1]`的作用相当于`*(arr + 1)`

### 函数如何使用指针来处理数组

数组名：

- 将数组名视为指针
- 数组声明使用数组名来标记内存位置
- 对数组名使用`sizeof`将返回整个数组的长度（以字节为单位）
- 将地址运算符用于数组名时，将返回整个数组的地址

### 将数组作为参数意味着什么

传递数组地址可以节省计算机开销，通过地址直接找到原始数据，对其操作

使用原始数据增加了破坏数据的风险，`const`限定符解决了这一问题

### 更多数组函数示例

```cpp
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
```

输出结果：

```cpp
Enter value #1: 10000
Enter value #2: 20000
Enter value #3: 30000
Enter value #4: 88889
Enter value #5: 27777
Property #1: $10000
Property #2: $20000
Property #3: $30000
Property #4: $88889
Property #5: $27777
Enter revalution factor: 1.2
Property #1: $12000
Property #2: $24000
Property #3: $36000
Property #4: $106667
Property #5: $33332.4
```

### `const`与指针的用法

1. `const int *pt;` `const`修饰的指针，不能通过指针修改指向的内容

```cpp
// const int *pt;

#include<iostream>
using namespace std;

int main(void)
{
    int n = 10;
    int m = 100;
    const int *pt = &n; // 指针设置为常量，不能通过指针修改指向的内容

    cout << "1) n = " << n << endl;
    //*pt = 20;
    pt = &m;
    n = 20;
    cout << "2) n = " << n << endl;
    cout << "*pt = " << *pt << endl;
    cout << "m = " << m << endl;

    return 0;
}
```

输出结果：

```cpp
1) n = 10
2) n = 20
*pt = 100
m = 100
```

2. `int *const pt;` pt 指针只能指向一个变量，且可以修改指向地址的内容

```cpp
// int *const pt;

#include <iostream>
using namespace std;

int main(void)
{
    int n = 10;
    //int m = 100;
    int *const pt = &n;  //pt指针只能指向一个变量，且可以修改指向地址中的内容

    cout << "1) n = " << n << endl;
    *pt = 20;
    cout << "2) n = " << n << endl;

    // pt = &m;
    // cout << "*pt = " << *pt << endl;
    // cout << "m = " << m << endl;

    return 0;
}
```
输出结果：
```cpp
1) n = 10
2) n = 20
```

3. `const int *const pt;` pt指针只能指向一个内容，且不能修改指向地址中的内容


