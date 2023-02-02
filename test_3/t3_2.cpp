//输入英尺英寸转化为米，磅转化为千克，计算BMI
#include<iostream>
using namespace std;
const int FOOT_TO_INCH = 12;
const double INCH_TO_METER = 0.0254;
const double KILLGRAM_TO_POUND = 2.2;

int main(void)
{
    int h_foot, h_inch;
    double w_pound;

    cout << "Please enter your height foot: ";
    cin >> h_foot;
    cout << "Please enter your height inches: ";
    cin >> h_inch;
    cout << "Please enter your weight in pounds: ";
    cin >> w_pound;

    double h = (h_foot * FOOT_TO_INCH + h_inch) * INCH_TO_METER;
    double w = (w_pound / KILLGRAM_TO_POUND);

    double bmi = w / (h * h);

    cout << "Your BMI is " << bmi << endl;

    return 0;
}
