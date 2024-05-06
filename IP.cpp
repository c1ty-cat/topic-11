#include <iostream>
#include <cmath>
using namespace std;

bool checkOctet(string octet)
{
    bool isOK = true;
    for (int i = 0; i < octet.length(); i++)
    {
        if (octet[i] < '0' || octet[i] > '9')
        {
            isOK = false;
            return isOK;
        }
        if (octet[0] == '0')
        {
            if (octet.length() > 1)
            {
                isOK = false;
                return isOK;
            }
        }
    }
    if (stoi(octet) > 255)
    {
        isOK = false;
        return isOK;
    }
    return isOK;
}

bool globalDotsCheck(string input)
{
    int counter = 0;
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == '.')
        {
            counter++;
        }
    }
    return counter == 3 ? true : false;
}

string getOctet(string input, int octetNum)
{
    string output = "";
    int currentOctet = 0;
    int i = 0;
    while (true)
    {
        if (currentOctet == octetNum)
        {
            int k = 0;
            do
            {
                output += input[k + i];
                k++;
            } while ((input[k + i] != '.') && (k + i < input.length()));
            return output;
        }
        else
        {
            if (input[i] == '.')
            {
                currentOctet++;
            }
        }
        i++;
    }
}

string checkIP(string input)
{
    bool isOK = true;
    isOK = checkOctet(getOctet(input, 0)) &&
           checkOctet(getOctet(input, 1)) &&
           checkOctet(getOctet(input, 2)) &&
           checkOctet(getOctet(input, 3)) &&
           globalDotsCheck(input);

    return (isOK == true ? "Valid\n" : "Invalid\n");
}

int main()
{
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "----------OK IP------------\n";
    cout << checkIP("127.0.0.1");
    cout << checkIP("255.255.255.255");
    cout << checkIP("1.2.3.4");
    cout << checkIP("55.77.213.101");
    cout << "----------BAD IP------------\n";
    cout << checkIP("255.256.257.258");
    cout << checkIP("10.55.33.22.");
    cout << checkIP("11.00.000.0");
    cout << checkIP("a.b.c.d");
}