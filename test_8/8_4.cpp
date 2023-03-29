#include<iostream>
#include<string>
using namespace std;

struct free_throws
{
    string name;
    int made;
    int attempts;
    float precent;
};

int main(void)
{
    free_throws one = {"GJT", 13, 14};
    free_throws two = {"JACK", 10, 16};
    free_throws three = {"Ferry", 3, 4};
    free_throws four = {"Mick", 24, 30};
    free_throws five = {"Jason",7, 38};
    free_throws six = {"Rose", 7, 9};

    set_pc(one);

    return 0;
}

void set_pc(free_throws & ft)
{
    
}