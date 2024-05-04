#include <iostream>
#include <cmath>
using namespace std;

string encrypt_caesar(string input, int code)
{
    string output = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (int(input[i]) >= int('A') && int(input[i]) <= int('Z'))
        {
            int shift = int(input[i]) - int('A');
            shift += code;
            shift %= 26;
            shift += int('A');
            output += char(shift);
        }
        else if (int(input[i]) >= int('a') && int(input[i]) <= int('z'))
        {
            int shift = int(input[i]) - int('a');
            shift += code;
            shift %= 26;
            shift += int('a');
            output += char(shift);
        }
        else
        {
            output += input[i];
        }
    }
    return output;
}

int main()
{
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << encrypt_caesar("aBxZ*", 67);
    cout << "-------------------------------\n";
    cout << encrypt_caesar("The quick brown fox jumps over the lazy dog", 3);
}