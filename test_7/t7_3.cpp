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
    box abc = {"hab", 10, 27, 23, 29};

    show_box(abc);

    set_box(&abc);

    cout << endl;
    show_box(abc);

    return 0;
}

void show_box(box abc)
{
    cout << abc.maker << endl;
    cout << abc.height << endl;
    cout << abc.width << endl;
    cout << abc.length << endl;
    cout << abc.volume << endl;
}

void set_box(box *pa)
{
    pa->volume = pa->height * pa->length * pa->width;
}