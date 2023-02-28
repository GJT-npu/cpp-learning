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