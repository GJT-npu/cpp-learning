#include<iostream>
#include<string>
#include<cctype>
using namespace std;

int main(void)
{
    string ch;
    cout << "Enter wods (q to quit): " << endl;

    int vowel = 0;
    int consonant = 0;
    int other = 0;

    while((cin >> ch) && (ch != "q"))
    {
        if (isalpha(ch[0]))
        {
            switch (ch[0])
            {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                ++vowel;
                break;
            default:
                ++consonant;
                break;
            }
        }
        else
        {
            ++other;
        }
    }

    cout << vowel << " words beginning with vowels\n";
    cout << consonant << " words beginning with consonants\n";
    cout << other << " others\n";

    return 0;
}