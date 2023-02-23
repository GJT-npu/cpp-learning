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

3. `const int *const pt;` pt 指针只能指向一个内容，且不能修改指向地址中的内容

## 函数和二维数组

二位数组传参，数组名表示数组首元素地址

```cpp
int sum(int (*pt)[4], int size);  //1
int sum(int pt2[][4], int size);  //2

//引用
int total = sum(a, 10);
```

二维数组的元素引用可以写成：
`ar2[r][c] == *(*(ar2 + r) + c)`

## 函数和 C 风格的字符串

### 将 C 风格字符串作为参数的函数

表示字符串的方法：

1. `char`数组
2. 用双引号引用起来的字符串常量
3. 被设置为字符串的地址的`char`指针

```cpp
#include<iostream>
using namespace std;
unsigned int c_in_str(const char *str, char ch);

int main(void)
{
    char mmm[15] = "minimum";
    const char *wail = "ululate";  //字符串常量，定义const指针使指针不能更改地址的内容

    unsigned int ms = c_in_str(mmm, 'm');
    unsigned int us = c_in_str(wail, 'u');

    cout << ms << " m characters in " << mmm << endl;
    cout << us << " u characters in " << wail << endl;

    return 0;
}

unsigned int c_in_str(const char *str, char ch)
{
    unsigned int count = 0;

    while (*str)
    {
        if(*str == ch)
            count++;

        str++;
    }

    return count;
}
```

输出结果：

```cpp
3 m characters in minimum
2 u characters in ululate
```

### 返回 C—风格字符串的函数

函数无法返回一个字符串，**但可以返回字符串的地址**，这样效率更高

```cpp
#include<iostream>
using namespace std;
char *buildstr(char ch, int n);

int main(void)
{
    char ch;
    int times;

    cout << "Enter a character: ";
    cin >> ch;
    cout << "Enter an integer: ";
    cin >> times;

    char *ps = buildstr(ch, times);
    cout << ps << endl;
    delete[] ps;  //new后释放内存

    return 0;
}
char *buildstr(char ch, int n)
{
    char *ps = new char[n + 1];
    ps[n] = '\0';  //字符串结尾使'\0'
    for (int i = 0; i < n; i++)
    {
        ps[i] = ch;
    }

    return ps;
}
```

输出结果：

```cpp
Enter a character: v
Enter an integer: 10
vvvvvvvvvv
```

## 函数和结构

传递的是结构体的副本

函数也可以返回结构

结构名只是结构体的名称，要获得结构体的地址，需要使用`&`

```cpp
#include<iostream>
using namespace std;

const int Min_per_hr = 60;

struct travel_time
{
    int hours;
    int mins;
};

travel_time sum(travel_time t1, travel_time t2);
void show_time(travel_time t);

int main(void)
{
    travel_time day1 = {5, 45};
    travel_time day2 = {4, 55};

    travel_time trip = sum(day1, day2);
    cout << "Two days total: ";
    show_time(trip);

    travel_time day3 = {4, 32};
    cout << "Three days total: ";
    show_time(sum(trip, day3));

    return 0;
}

travel_time sum(travel_time t1, travel_time t2)
{
    travel_time total;

    total.mins = (t1.mins + t2.mins) % Min_per_hr;
    total.hours = t1.hours + t2.hours + (t1.mins + t2.mins) / Min_per_hr;

    return total;
}
void show_time(travel_time t)
{
    cout << t.hours << " Hours, " << t.mins << " Minutes.\n";
}
```
输出结果：
```cpp
Two days total: 10 Hours, 40 Minutes.  
Three days total: 15 Hours, 12 Minutes.
```

## 函数和`string`对象

`string`对象和结构体的使用相似

可以将一个对象赋给另一个对象；可以将对象作为完整的实体进行传递。

如果需要多个字符串，可以声明一个`string`对象数组，而不是一个二维数组

声明一个string对象数组，并将其传递给函数以显示其内容：
```cpp
#include<iostream>
#include<string>
using namespace std;

const int SIZE = 5;

void display(const string *sa, int n);

int main(void)
{
    string list[SIZE];

    cout << "Enter: " << SIZE << " favorite food: " << endl;

    for (int i = 0; i < SIZE; i++)
    {
        cout << i + 1 << ": ";
        getline(cin, list[i]);
    }

    cout << "Your list: " << endl;
    display(list, SIZE);

    return 0;
}

void display(const string *sa, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ": " << sa[i] << endl;
    }
}
```
输出结果：
```cpp
Enter: 5 favorite food: 
1: milk
2: cake
3: icecream
4: salad
5: break
Your list: 
1: milk    
2: cake    
3: icecream
4: salad
5: break
```

## 函数和`array`对象

