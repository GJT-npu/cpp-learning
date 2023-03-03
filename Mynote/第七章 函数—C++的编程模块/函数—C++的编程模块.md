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

1. 可以将一个对象赋给另一个对象；
2. 可以将对象作为完整的实体进行传递。

如果需要多个字符串，可以声明一个`string`对象数组，而不是一个二维数组

声明一个 string 对象数组，并将其传递给函数以显示其内容：

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

1. 按值传递 传递副本
2. 传递指向对象的指针，这使得函数可以操作原始对象

## 递归

### 包含一个递归调用的递归

```cpp
void recurs(argumentlist)
{
    statements1
    if (test)
        recurs(arguments)
    statements2
}
```

例如：

```cpp
#include<iostream>
using namespace std;
void countdown(int n);

int main(void)
{
    countdown(4);

    return 0;
}

void countdown(int n)
{
    //statement1
    cout << "counting down... " << n << endl;

    //test
    if (n > 0)
    {
        countdown(n-1);
    }

    //statement2
    cout << n << ": Kadoom" << endl;
}
```

输出结果：

```cpp
counting down... 4
counting down... 3
counting down... 2
counting down... 1
counting down... 0
0: Kadoom
1: Kadoom
2: Kadoom
3: Kadoom
4: Kadoom
```

### 包含多个递归调用的递归

```cpp
#include<iostream>
using namespace std;

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int levels);

int main(void)
{
    char ruler[Len];

    for (int i = 0; i < Len; i++)
        ruler[i] = ' ';

    int min = 0;
    int max = Len - 2;
    ruler[Len - 1] = '\0';
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;  //打印第一行

    for (int i = 1; i <= Divs; i++)
    {
        subdivide(ruler, min, max, i);
        cout << ruler << endl;
    }

    return 0;
}

void subdivide(char ar[], int low, int high, int levels)
{
    if(levels == 0)
        return;

    int mid = (low + high) / 2;
    ar[mid] = '|';

    subdivide(ar, low, mid, levels - 1);
    subdivide(ar, mid, high, levels - 1);
}
```

输出结果：

```cpp
|                                                               |
|                               |                               |
|               |               |               |               |
|       |       |       |       |       |       |       |       |
|   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | | |
|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
```

## 函数指针

函数的地址：存储机器语言代码的内存的开始地址。

可以编写另一个函数的地址作为参数的函数。**意味着可以在不同的时间使用不同的函数**

### 函数指针的基础知识

设计一个名为`estimate()`的函数，估算编写指定行数的代码所需要的时间。函数将有一部分是相同的，但该函数允许每个程序员提供自己的算法来估算时间。为实现这种目标，采用的机制是，将程序员要使用的算法函数的地址传递给`estimate()`。为此，它必须可以完成以下功能：

1. 获取函数的地址：

   **使用函数名，不用带参数**，函数名就是函数的地址 `process(think);`

2. 声明一个函数指针:

   函数原型：`double pam(int);`

   正确的指针类型：`double (*pf)(int);`

   用`(*pf)`替换函数名 **这是一种类型函数的指针 不是某特定类型函数的指针**

   对于`estimste()`：代码行数、估算算法，函数原型是：

   ```cpp
   void estimate(int lines, double (*pf)(int));
   ```

3. 使用函数指针来调用函数

   将(\*pf)看作函数名

```cpp
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
```

输出结果：

```cpp
How many lines code do you need?: 29
Here is GJT's estimate:
29 lines code will take 1.45 seconds.
Here is CBC's estimate:
29 lines code will take 4.234 seconds.
```

### 深入探讨函数指针

```cpp
#include<iostream>
using namespace std;

const double *f1(const double *pa, int n);
const double *f2(const double *pa, int n);
const double *f3(const double *pa, int n);

int main(void)
{
    double ap[3] = {1112.3, 1542.6, 2227.9};

    //part1
    //p1(p2): pointer to a function
    const double *(*p1)(const double *, int) = f1;                     //(*p1)代替函数名
    auto p2 = f2;
    cout << "********PART1********" << endl;
    cout << "Address         Value" << endl;
    cout << (*p1)(ap, 3) << ":       " << *(*p1)(ap, 3) << endl;       //(*p1)(ap, 3) == p1(ap, 3) == f1(ap, 3)
    cout << p2(ap, 3) << ":       " << *p2(ap, 3) << endl;

    //part2
    //pa(pb) is an array of pointers
    const double *(*pa[3])(const double *, int) = {f1, f2, f3};
    auto pb = pa;
    cout << endl;
    cout << "********PART2********" << endl;
    cout << "Address         Value" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << pa[i](ap, 3) << ":       " << *pa[i](ap, 3) << endl;
    }
    for (int i = 0; i < 3;i++)
    {
        cout << pb[i](ap, 3) << ":       " << *pb[i](ap, 3) << endl;
    }

    //part3
    //pc(pd) is a pointer to the array(pa) of three elements(funstion pointers)
    auto pc = &pa;
    const double *(*(*pd)[3])(const double *, int) = &pa;
    cout << endl;
    cout << "********PART3********" << endl;
    cout << "Address         Value" << endl;
    cout << (*pc)[0](ap, 3) << ":       " << *(*pc)[0](ap, 3) << endl; //(*pc) == pa
    const double *pdb = (*pd)[1](ap, 3);
    cout << pdb << ":       " << *pdb << endl;
    //cout << (*pd)[2](ap, 3) << ":       " << *(*pd)[2](ap, 3) << endl;
    cout << (*(*pd)[2])(ap, 3) << ":       " << *(*(*pd)[2])(ap, 3) << endl;

    return 0;
}

//返回数组第一个元素的地址
const double *f1(const double *pa, int n)
{
    return pa;
}

//返回数组第二个元素的地址
const double *f2(const double *pa, int n)
{
    return pa + 1;
}

//返回数组第三个元素的地址
const double *f3(const double *pa, int n)
{
    return pa + 2;
}
```

输出结果：

```cpp
********PART1********
Address         Value
0x61fdc0:       1112.3
0x61fdc8:       1542.6

********PART2********
Address         Value
0x61fdc0:       1112.3
0x61fdc8:       1542.6
0x61fdd0:       2227.9
0x61fdc0:       1112.3
0x61fdc8:       1542.6
0x61fdd0:       2227.9

********PART3********
Address         Value
0x61fdc0:       1112.3
0x61fdc8:       1542.6
0x61fdd0:       2227.9
```

## 复习题

![](2023-02-28-23-04-44.png)

1. 函数的定义；函数的调用；函数的原型
2. 函数原型
   ```cpp
   void igor(void);
   float tofu(int);
   double mpg(double, double);
   long summation(long arr[], int n);
   double doctor(const char*str);
   void ofcourse(boss bs);
   char * plot(map *pm);
   ```
3. ```cpp
   void set_array(int arr[], int size, int n)
   {
       for(int i = 0; i < size; i++)
           arr[i] = n;
   }
   ```
4. ```cpp
   void set_array(int *begin, int *end, int value)
   {
       for (int *pt = begin, pt != end, pt++)
           {
               *pt = value;
           }
   }
   ```
5. ```cpp
   double max_number(const double arr[], int size)
   {
       int max_value = arr[0];
       for(int i = 1, i < size, i++)
           {
               if(max_value < arr[i])
                   max_value = arr[i];
           }
       return max;
   }
   ```
6. 无
7. ```cpp
   char str[] = "Hello world!";
   "Hello world";
   char *pt = "Hello world!";
   ```
8. ```cpp
   int replace(char *str, char c1, char c2)
   {
       int count = 0;
       while(*str)
       {
           if(*str == c1)
           {
               *str = c2;
               count++;
           }
           str++;
       }
       return count;
   }
   ```
9. \*"pizza" -> p
   "tac0"[2] -> c
10. 无
11. ```cpp
    int judge(int (*pt)(const char *));
    ```
12. - ```cpp
      void show(applicant ap)
      {
          cout << ap.name << endl;
          for(int i =0; i < 3, i++)
              cout << ap.credit_ratings[i] << endl;
      }
      ```
    - ```cpp
      void show(const applicant *pt)
      {
          cout << pt->name << endl;
          for(int i = 0, i < 3, i++)
              cout << ap->credit_ratings[i] << endl;
      }
      ```
13. ```cpp
    typedef void (*p_f1)(applicant *a);
    p_f1 p1 = f1;
    typedef const char *(*p_f2)(const applicant *a1, const applicant *a2);
    p_f2 p2 = f2;

    p_f1 ap[5];
    p_f2 (*pa)[10];
    ```

## 编程练习

1. 编写一个程序，不断要求用户输入两个数，直到其中的一个为 0。对于每两个数，程序将使用一个函数来计算它们的调和平均数，并将结果返回给 main()，而后者将报告结果。调和平均数指的是倒数平均值的倒数，计算公式如下:
$$
调和平均数=2.0* x *y /(x+y)
$$

运行代码：
```cpp
#include<iostream>
using namespace std;
double harmonic_average(double x, double y);

int main(void)
{
    double x, y;

    cout << "Please enter two number: ";
    while(cin>>x>>y)
    {
        if(x!=0 && y!=0)
        {
            double ha = harmonic_average(x, y);
            cout << "The harmonic average is " << ha << endl;
            cout << "Enter two number again: ";
        }
        else
        {
            cout << "Over!\n";
            break;
        }
    }

    return 0;
}

double harmonic_average(double x, double y)
{
    return 2.0 * x * y / (x + y);
}
```
输出结果：
```cpp
Please enter two number: 5.8 9
The harmonic average is 7.05405
Enter two number again: 4 0    
Over!
```

2. 编写一个程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。程序允许用户提早结束输入，并在一行上显示所有成绩，然后报告平均成绩。请使用3个数组处理函数来分别进行输入、显示和计算平均成绩。

运行代码：
```cpp
#include<iostream>
using namespace std;

const int MAX = 10;

int fill_golf(double arr[], int n);
void show_golf(double arr[], int n);
double average_golf(double arr[], int n);

int main(void)
{
    double golf[MAX];

    int size = fill_golf(golf, MAX);

    if (size > 0)
    {
        show_golf(golf, size);
        cout << "Average:" << average_golf(golf, size) << endl;
    }
    else
        cout << "There is no scores!" << endl;

    return 0;
}

int fill_golf(double arr[], int n)
{
    int i = 0;
    double temp;
    for (i = 0; i < MAX; i++)
    {
        cout << "Enter golf score, NO." << i + 1 << ": ";
        cin >> temp;
        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                ;
            cout << "Invailed input, terminate." << endl;
            break;
        }
        else if(temp < 0)
            break;
        else
            arr[i] = temp;
    }
    return i;
}

void show_golf(double arr[], int n)
{
    cout << "GOLF RESULT : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

double average_golf(double arr[], int n)
{
    double average, sum = 0;

    for (int i = 0; i < n; i++)
        sum += arr[i];

    average = sum / n;

    return average;
}
```
输出结果：
```cpp
Enter golf score, NO.1: 9.0
Enter golf score, NO.2: 9.8
Enter golf score, NO.3: 6.6
Enter golf score, NO.4: 7.8
Enter golf score, NO.5: 9.7
Enter golf score, NO.6: 5.7
Enter golf score, NO.7: 6.0
Enter golf score, NO.8: a
Invailed input, terminate.
GOLF RESULT : 9 9.8 6.6 7.8 9.7 5.7 6 
Average:7.8
```

3. 下面是一个结构声明:
```cpp
struct box
{
char maker [40];
float height;
float width;
float length;
float volume;
};
```
a. 编写一个函数，按值传递box 结构，并显示每个成员的值。

b. 编写一个函数，传递box结构的地址，并将volume成员设置为其他三维长度的乘积。

c. 编写一个使用这两个函数的简单程序。

运行代码：
```cpp
#include<iostream>
using namespace std;
struct box
{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void show_box(box abc);
void set_box(box *pa);

int main(void)
{
    box abc = {"hab", 3, 4, 5};

    set_box(&abc);
    show_box(abc);

    return 0;
}

void show_box(box abc)
{
    cout << "maker: " << abc.maker << endl;
    cout << "height: " << abc.height << endl;
    cout << "width: " << abc.width << endl;
    cout << "length: " << abc.length << endl;
    cout << "volume: " << abc.volume << endl;
}

void set_box(box *pa)
{
    pa->volume = pa->height * pa->length * pa->width;
}
```
输出结果：
```cpp
maker: hab
height: 3 
width: 4  
length: 5 
volume: 60
```

4. 许多州的彩票发行机构都使用如程序清单7.4所示的简单彩票玩法的变体。在这些玩法中，玩家从一组被称为域号码(field number）的号码中选择几个。例如，可以从域号码1~47中选择5个号码;还可以从第二个区间(如1~27)选择一个号码（称为特选号码)。要赢得头奖，必须正确猜中所有的号码。中头奖的几率是选中所有域号码的几率与选中特选号码几率的乘积。例如，在这个例子中，中头奖的几率是从47个号码中正确选取5个号码的几率与从27个号码中正确选择1个号码的几率的乘积。请修改程序清单7.4，以计算中得这种彩票头奖的几率。

运行代码：
```cpp
#include<iostream>
using namespace std;
long double probability(unsigned numbers, unsigned picks);

int main(void)
{

    long double field = probability(47, 5);
    long double special = probability(27, 1);
    long double result = field * special;

    cout << result << endl;

    cout << "bye\n";

    return 0;
}

long double probability(unsigned numbers, unsigned picks)
{
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--)
    {
        result = result * n / p;
    }
    return result;
}
```
输出结果：
```cpp
4.14164e+07
bye 
```

5. 5．定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。前面讲过，3的阶乘写作3!，等于3 * 2!，依此类推;而0!被定义为1。通用的计算公式是，如果n大于零，则n!=n * (n-1)!。在程序中对该函数进行测试，程序使用循环让用户输入不同的值，程序将报告这些值的阶乘。

运行代码：
```cpp
#include<iostream>
using namespace std;

long long factorial(unsigned int n);

int main(void)
{
    int number;
    long long fac;

    cout << "Enter a number and output it's factorial: ";
    
    while (cin >> number)
    {
        fac = factorial(number);
        cout << number << "! = " << fac << endl;
        cout << "Next number (q to quit): ";
    }

    return 0;
}

long long factorial(unsigned int n)
{
    if (n == 0)
        return 1;
    else
        return n * factorial(n - 1);
}
```
输出结果：
```cpp
Enter a number and output it's factorial: 0
0! = 1
Next number (q to quit): 2
2! = 2
Next number (q to quit): 3
3! = 6
Next number (q to quit): 4
4! = 24
Next number (q to quit): 5
5! = 120
Next number (q to quit): 6
6! = 720
Next number (q to quit): 7
7! = 5040
Next number (q to quit): q
```

6. 编写一个程序，它使用下列函数:
   
   Fill_array()将一个double数组的名称和长度作为参数。它提示用户输入double值，并将这些值存储到数组中。当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字。

   Show_array()将一个 double数组的名称和长度作为参数，并显示该数组的内容。

   Reverse-array()将一个double数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。
   
   程序将使用这些函数来填充数组，然后显示数组;反转数组，然后显示数组;反转数组中除第一个和最后一个元素之外的所有元素，然后显示数组。

运行代码：
```cpp
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
```
输出结果：
```cpp
Enter number, No.1: 1
Enter number, No.2: 2
Enter number, No.3: 3
Enter number, No.4: 4
Enter number, No.5: 5
Enter number, No.6: q
Invailed input, terminate.

********The array******** 
arr[0] = 1
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 5
Please enter the number(a to b) you want to reverse: 1 5

********The array********
arr[0] = 5
arr[1] = 4
arr[2] = 3
arr[3] = 2
arr[4] = 1
Please enter the number(a to b) you want to reverse: 2 4

********The array********
arr[0] = 5
arr[1] = 2
arr[2] = 3
arr[3] = 4
arr[4] = 1
```

7. 修改程序清单7.7中的3个数组处理函数，使之使用两个指针参数来表示区间。fill_array()函数不返回实际读取了多少个数字，而是返回一个指针，该指针指向最后被填充的位置;其他的函数可以将该指针作为第二个参数，以标识数据结尾。

运行结果：
```cpp
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

```
输出结果：
```cpp
Enter value #1: 5
Enter value #2: 6
Enter value #3: 7
Enter value #4: 8
Enter value #5: 9
Property #1: $5
Property #2: $6
Property #3: $7
Property #4: $8
Property #5: $9
Enter revalution factor: 5
Property #1: $25
Property #2: $30
Property #3: $35
Property #4: $40
Property #5: $45
```

8. 在不使用array类的情况下完成程序清单7.15所做的工作。编写两个这样的版本:
   
   a．使用const char *数组存储表示季度名称的字符串，并使用double数组存储开支。

   b．使用const char*数组存储表示季度名称的字符串，并使用一个结构，该结构只有一个成员———个用于存储开支的double数组。这种设计与使用array类的基本设计类似。

运行代码：
```cpp
#include<iostream>
#include<string>
using namespace std;

const int Seasons = 4;

const char *Snames[] = {"Spring", "Summer", "Fall", "Winter"};

void fill(double arr[], int n);
void show(const double arr[], int n);

int main(void)
{
    double expenses[Seasons];

    fill(expenses, Seasons);
    show(expenses, Seasons);

    return 0;
}

void fill(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << Snames[i] << " expenses: ";
        cin >> arr[i];
    }
}
void show(const double arr[], int n)
{
    double total = 0;
    cout << "EXPENSES: " << endl;
    for(int i = 0; i < n; i++)
    {
        cout << Snames[i] << ": $" << arr[i] << endl;
        total += arr[i];
    }
    cout << "Total expenses: " << total << endl;
}
```
输出结果：
```cpp
Enter Spring expenses: 1000
Enter Summer expenses: 2000
Enter Fall expenses: 2843
Enter Winter expenses: 2848
EXPENSES:
Spring: $1000       
Summer: $2000       
Fall: $2843
Winter: $2848       
Total expenses: 8691
```

9. 这个练习让您编写处理数组和结构的函数。下面是程序的框架，请提供其中描述的函数，以完成该程序。

```cpp
#include <iostream>
using namespace std;
const int SLEN = 30 ;
struct student {
char fullname [SLEN];
char hobby [SLEN];
int ooplevel;
};
// getinfo() has two arguments: a pointer to the first element of
// an array of student structures and an int representing the
// number of elements of the array. The function solicits and
// stores data about students. It terminates input upon filling
// the array or upon encountering a blank line for the student
// name. The function returns the actual number of array elements
// filled.
int getinfo(student pa[] , int n);

// display1 ( ) takes a student structure as an argument and displays its contents
void display1 (student st);

// display2 ( ) takes the address of student structure as an argument and displays the structure's contents
void display2 (const student * ps);

// display3 ( ) takes the address of the first element of an array of student structures and the number of array elements as arguments and displays the contents of the structures
void display3(const student pa[] , int n);

int main(void)
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;

    while (cin.get ( ) != ' \n')
        continue;

    student * ptr_stu = new student [class_size];
    int entered = getinfo(ptr_stu,class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu [i]);
    }
    display3(ptr_stu,entered);
    delete [] ptr_stu;
    cout <<"Done\n" ;return 0;
}
```

运行代码：
```cpp
#include <iostream>
using namespace std;
const int SLEN = 30;
struct student
{
    char fullname[SLEN];
    char hobby[SLEN];
    int ooplevel;
};

int getinfo(student pa[], int n);
void display1(student st);
void display2(const student *ps);
void display3(const student pa[], int n);

int main(void)
{
    cout << "Enter class size: ";
    int class_size;
    cin >> class_size;

    while (cin.get() != '\n')
        continue;

    student *ptr_stu = new student[class_size];
    int entered = getinfo(ptr_stu, class_size);
    for (int i = 0; i < entered; i++)
    {
        display1(ptr_stu[i]);
        display2(&ptr_stu[i]);
    }
    display3(ptr_stu, entered);

    delete[] ptr_stu;
    cout << "Done\n";
    return 0;
}

int getinfo(student pa[], int n)
{
    int i = 0;
    for (i = 0; i < n; i++)
    {
        cout << "Enter the name of a student: ";
        cin >> (pa + i)->fullname;
        cout << "Enter the hobby of a student: ";
        cin >> (pa + i)->hobby;
        cout << "Enter the level of a student: ";
        cin >> pa[i].ooplevel;

        if(!cin)
        {
            cin.clear();
            while(cin.get() != '\n')
                ;
            break;
        }
    }
    return i;
}
void display1(student st)
{
    cout << "Name: " << st.fullname << endl;
    cout << "Hobby: " << st.hobby << endl;
    cout << "Level: " << st.ooplevel << endl;
}
void display2(const student *ps)
{
    cout << "Name: " << ps->fullname << endl;
    cout << "Hobby: " << ps->hobby << endl;
    cout << "Level: " << ps->ooplevel << endl;
}
void display3(const student pa[], int n)
{
    int i =0;
    for (i = 0; i < n; i++)
    {
        cout << "Name: " << (pa + i)->fullname << endl;
        cout << "Hobby: " << (pa + i)->hobby << endl;
        cout << "Level: " << (pa + i)->ooplevel << endl;
    }
}
```
输出结果：
```cpp
Enter class size: 4
Enter the name of a student: Rick
Enter the hobby of a student: eat
Enter the level of a student: 10
Enter the name of a student: Jerry
Enter the hobby of a student: sleep
Enter the level of a student: 9
Enter the name of a student: Jason
Enter the hobby of a student: play
Enter the level of a student: 8
Enter the name of a student: yiyi
Enter the hobby of a student: study
Enter the level of a student: 10
Name: Rick
Hobby: eat
Level: 10
Name: Rick
Hobby: eat
Level: 10
Name: Jerry
Hobby: sleep
Level: 9
Name: Jerry
Hobby: sleep
Level: 9
Name: Jason
Hobby: play
Level: 8
Name: Jason
Hobby: play
Level: 8
Name: yiyi
Hobby: study
Level: 10
Name: yiyi
Hobby: study
Level: 10
Name: Rick
Hobby: eat
Level: 10
Name: Jerry
Hobby: sleep
Level: 9
Name: Jason
Hobby: play
Level: 8
Name: yiyi
Hobby: study
Level: 10
Done
```

10. 设计一个名为calculate()的函数，它接受两个double值和一个指向函数的指针，而被指向的函数接受两个double参数，并返回一个double值。calculate()函数的类型也是double，并返回被指向的函数使用calculate()的两个double参数计算得到的值。例如，假设add()函数的定义如下:

```cpp
double add (double x,double y)
{
    return x+ y;
}
```

则下述代码中的函数调用将导致calculate( )把2.5和10.4传递给add()函数，并返回add()的返回值（12.9):

```cpp
double q = calculate(2.5，10.4, add);
```

请编写一个程序，它调用上述两个函数和至少另一个与add()类似的函数。该程序使用循环来让用户成对地输入数字。对于每对数字，程序都使用calculate()来调用add( )和至少一个其他的函数。如果读者爱冒险，可以尝试创建一个指针数组，其中的指针指向add()样式的函数，并编写一个循环，使用这些指针连续让 calculate()调用这些函数。提示:下面是声明这种指针数组的方式，其中包含三个指针:

```cpp
double (*pf[3]) (double, double);
```

可以采用数组初始化语法，并将函数名作为地址来初始化这样的数组。

运行代码：
```cpp
#include<iostream>
using namespace std;
double add(double x, double y);
double sub(double x, double y);
double caculate(double x, double y, double (*pt)(double, double));

int main(void)
{
    double result = caculate(3.5, 10.4, add);
    cout << "The result of add is: " << result << endl;

    result = caculate(3.5, 10.4, sub);
    cout << "The result of sub is: " << result << endl;

    return 0;
}

double add(double x, double y)
{
    return x + y;
}

double sub(double x, double y)
{
    return x - y;
}

double caculate(double x, double y, double (*pt)(double, double))
{
    return (*pt)(x, y);
}
```
输出结果：
```cpp
The result of add is: 13.9
The result of sub is: -6.9
```
