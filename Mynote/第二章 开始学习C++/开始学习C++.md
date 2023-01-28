# 开始学习c++

## 进入c++
1. c++程序必须包含main函数
2. 注释：// 注释本行 ；/*  */ 注释一段文字
3. 使用cin cout 必须包含文件iostream
4. 必须包含`#include<iostream>`,`using namespace std`

### 头文件名
c++去掉了.h后缀，加上前缀c；例如：`math.h`->`cmath`

### 名称空间
目的是解决同名函数的冲突问题。

名称空间编译指令：`using namespace std` ，那么后面不必使用`std::`前缀，对于简单程序而言，一次设置，简化写法。
```cpp
#include<iostream>
int main()
{
    using namespace std;
    return 0;
}
```

### 使用`cout`进行C++输出
显示消息:`<<`（插入运算符）表示把字符串发送给`cout`
```cpp；将字符串插入到输出流当中。
cout << "Come up and C++ me some time.";  
```

#### 控制符`endl`
`cout endl` 的作用：重起一行

#### 换行符`\n`
`cout << "\n"`
`cout << endl`

### C++源代码的格式化
以一定的格式编写，提高程序可阅读性。

#### 源代码风格
1. 源代码当中的**标记和空白**
2. 每条语句**占用一行**
3. 函数用**花括号**括起来，并独立占用一行
4. 函数体相对于花括号进行**缩进**
5. 增加注释
6. 增加空行
7. 函数名称的圆括号附近没有空白`int main()`

## C++语句

### 声明语句和变量
声明变量，可以避免拼写产生的编译错误；C++,通常是在**首次**使用变量前进行声明。

### 赋值语句
```cpp
carrots = 20;
```

### cout新花样
`cout <<` 根据其后的数据类型相应的调整行为，智能地调整输出内容
```cpp
#include<iostream>

int main()
{
    using namespace std;

    int carrots;   //声明语句创建变量

    carrots = 20;  //赋值语句给变量提供一个值
    cout << "I have ";
    cout << carrots;
    cout << " carrots.";
    cout << endl;
    
    carrots -= 1;
    cout << "Cruch, Cruch, Now I have " << carrots << " carrots." << endl;

    return 0;
}
```
## 其他C++语句

### 使用`cin`
从键盘输入赋值`cin >> carrots;`
```cpp
#include<iostream>

int main()
{
    using namespace std;

    int carrots;

    cout << "How many carrots do you have?" << endl;
    cin >> carrots;  //程序输入流流入carrots中
    cout << "Here are two more." << endl;  //不加 endl 两句话将连在一起，不会因为中间有其他语句而分开
    carrots += 2;
    cout << "Now you have " << carrots << " carrots." << endl;

    return 0;
}
```

### 类简介
类是用户定义的一种数据类型。

类包含：能够表述什么养的信息 、可对数据进行哪些操作。（数据以及操作数据的方法）  

`类(iostream)->对象(cout、cin)` 就像 `类型(int)->变量(carrots)` 

类定义描述的是**数据格式**及其**用法** 对象是类的**具体实例化**





