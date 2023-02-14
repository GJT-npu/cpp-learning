#include<iostream>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;

int main(void)
{
    string filename;

    cout << "Enter the name of the file: ";
    cin >> filename;

    ifstream inFile;
    inFile.open(filename);

    //判断文件是否打开成功，打开文件后的必须操作
    if (!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);            //打开失败
    }
    cout << "Sucees open txt file.\n"; // 打开成功

    //读取文件，必须验证读取文件是否成功 inFile.good()
    int count = 0;
    char ch;

    while(inFile >> ch)
    {
        ++count;
    }

    //判断是否读取完成
    if (inFile.eof()) // 读取完成，到最后识别到文件末尾
    {
        cout << "End of file reached.\n";
    }
    else if (inFile.fail()) // 读取失败,类型不匹配
    {
        cout << "Input terminated by data mismached.\n";
    }
    else
    {
        cout << "Input terminated by unknow reason.\n";
    }

    //显示读取信息
    if (count == 0)
    {
        cout << "No data processed.\n";
    }
    else
    {
        cout << "This txt has " << count << " characters.\n";
    }

    inFile.close();
    return 0;
}