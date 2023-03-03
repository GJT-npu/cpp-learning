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