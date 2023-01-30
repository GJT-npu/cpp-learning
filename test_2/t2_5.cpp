#include<iostream>
using namespace std;
double CeltoFah(double cel);

int main(void)
{
    double Cel;
    
    cout << "Please enter a Celsius value: ";
    cin >> Cel;

    double Fah = CeltoFah(Cel);
    cout << Cel << " degrees Celsius is " << Fah << " degrees Fahrenheit." << endl;

    return 0;
}

double CeltoFah(double cel)
{
    return cel * 1.8 + 32.0;
}