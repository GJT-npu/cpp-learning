#include<iostream>  //ostream -> cout   istream -> cin
#include<fstream>   // 1. #include<fstream>   ofstream         ifstream
using namespace std;

int main(void)
{
    char automoblie[50];
    int year;
    double a_price;
    double d_price;

    ofstream outFile;             //2. 创建对象
    outFile.open("6_7.txt");      //3. 关联文件

    cout << "Enter the make and model of automoblie: ";
    cin.getline(automoblie, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the orignal asking price: ";
    cin >> a_price;
    d_price = a_price * 0.913;

    //输出到屏幕
    cout << fixed;                 //不要用科学计数法
    cout.precision(2);             //小数点后两位
    cout.setf(ios_base::showpoint);//强制显示位数
    cout << endl
         << "Make and mobel: " << automoblie << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking: " << a_price << endl;
    cout << "Now aksing: " << d_price << endl;

    //输出到文件
    outFile << fixed;                  // 不要用科学计数法
    outFile.precision(2);              // 小数点后两位
    outFile.setf(ios_base::showpoint); // 强制显示位数
    outFile << "Make and mobel: " << automoblie << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking: " << a_price << endl;
    outFile << "Now aksing: " << d_price << endl;

    outFile.close();                   //关闭文件
    return 0;
}
