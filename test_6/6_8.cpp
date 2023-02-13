#include<iostream>
#include<fstream>                 //1. 包含fstream头文件
#include<cstdlib>
using namespace std;
const int SIZE = 20;

int main(void)
{
    char filename[SIZE];

    cout << "Enter name of the data file: ";
    cin.getline(filename, SIZE);

    ifstream inFile;              //2. 创建对象
    inFile.open(filename);        //3. 关联文件

    //判断文件是否打开成功
    if(!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }
    cout << "Sucees open txt file.\n";  //打开成功

    //读取文件内容
    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;       //读取文件
    while(inFile.good())   //读取成功，计数
    {
        ++count;
        sum += value;
        inFile >> value;
    }

    if(inFile.eof())           //读取完成，到最后识别到文件末尾
    {
        cout << "End of file reached.\n";
    }
    else if(inFile.fail())     //读取失败,类型不匹配
    {
        cout << "Input terminated by data mismached.\n";
    }
    else
    {
        cout << "Input terminated by unknow reason.\n";
    }

    //显示读取后处理数据结果
    if(count == 0)
    {
        cout << "No data processed.\n";
    }
    else
    {
        cout << "Items read: " << count << endl;
        cout << "Sum: " << sum << endl;
        cout << "Average: " << sum / count << endl;
    }

    inFile.close();
    return 0;
}