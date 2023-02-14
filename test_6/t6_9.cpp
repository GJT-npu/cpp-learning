#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
using namespace std;
struct donor
{
    string Name;
    double Figure;
};

int main(void)
{
    string filename;

    cout << "Enter the name of the file: ";
    getline(cin, filename);

    ifstream inFile;
    inFile.open(filename);
    if(!inFile.is_open())
    {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);
    }

    //读取文件
    int num, i = 0;

    inFile >> num;                    //读出需要存储的捐款人数
    if(num <= 0)
        exit(EXIT_FAILURE);
    donor *pd = new donor[num];       //生成动态分配的结构数组

    inFile.get();                     //消耗回车

    while((!inFile.eof()) && (i < num))
    {

        getline(inFile, (pd + i)->Name);
        cout << "Read name #" << i + 1 << ": " << (pd + i)->Name << endl;
        inFile >> (pd + i)->Figure;
        cout << "Donation #" << i + 1 << ": " << (pd + i)->Figure << endl;

        i++;
        inFile.get();
    }

    int count_gp = 0, count_p = 0;

    for (int i = 0; i < num; i++)
    {
        if (((pd + i)->Figure) >= 10000)
            count_gp++;
        else
            count_p++;
    }

    cout << endl
         << "**********Grand Patrons**********\n";
    if (count_gp > 0)
    {
        for (int i = 0; i < num; i++)
        {
            if (((pd + i)->Figure) >= 10000)
            {
                cout << (pd + i)->Name << ": " << (pd + i)->Figure << endl;
            }
        }
    }
    else
    {
        cout << "none.\n";
    }

    cout << "*************Patrons*************\n";
    if (count_p > 0)
    {
        for (int i = 0; i < num; i++)
        {
            if (((pd + i)->Figure) < 10000)
            {
                cout << (pd + i)->Name << ": " << (pd + i)->Figure << endl;
            }
        }
    }
    else
    {
        cout << "none.\n";
    }

    inFile.close();
    return 0;
}