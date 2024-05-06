#include <iostream>
#include <cmath>
using namespace std;

bool checkFirstHalf(string input)
{
    string allowedSymbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.!#$%&'*+-/=?^_`{|}~";
    bool isFirstHalfOk = true;
    if (input.length() < 1 || input.length() > 64)
    {
        isFirstHalfOk = false;
        return isFirstHalfOk;
    }
    if (input[0] == '.' || input[input.length() - 1] == '.')
    {
        isFirstHalfOk = false;
        return isFirstHalfOk;
    }
    for (int i = 0; i < input.length(); i++)
    {
        if (allowedSymbols.find(input[i]) == std::string::npos)
        {
            isFirstHalfOk = false;
            return isFirstHalfOk;
        }
        if (input[i] == '.')
        {
            if (input[i - 1] == '.')
            {
                isFirstHalfOk = false;
                return isFirstHalfOk;
            }
        }
    }
    return isFirstHalfOk;
}

bool checkSecondHalf(string input)
{
    string allowedSymbols = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-.";
    bool isSecondHalfOk = true;
    if (input.length() < 1 || input.length() > 63)
    {
        isSecondHalfOk = false;
        return isSecondHalfOk;
    }
    if (input[0] == '.' || input[input.length() - 1] == '.')
    {
        isSecondHalfOk = false;
        return isSecondHalfOk;
    }
    for (int i = 0; i < input.length(); i++)
    {
        if (allowedSymbols.find(input[i]) == std::string::npos)
        {
            isSecondHalfOk = false;
            return isSecondHalfOk;
        }
        if (input[i] == '.')
        {
            if (input[i - 1] == '.')
            {
                isSecondHalfOk = false;
                return isSecondHalfOk;
            }
        }
    }
    return isSecondHalfOk;
}

void checkEmail(string input)
{
    bool isOk = true;
    int k = 0;
    string firstHalf = "";
    string secondHalf = "";
    for (int i = 0; input[i] != '@'; i++)
    {
        firstHalf += input[i];
        k = i + 2;
    }
    for (; k < input.length(); k++)
    {
        secondHalf += input[k];
    }
    isOk = checkFirstHalf(firstHalf) && checkSecondHalf(secondHalf);
    cout << (isOk == true ? "Yes\n" : "No\n");
}

int main()
{
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "-------------------------------\n";
    cout << "----------OK EMAILS------------\n";
    checkEmail("simple@example.com");
    checkEmail("very.common@example.com");
    checkEmail("disposable.style.email.with+symbol@example.com");
    checkEmail("fully-qualified-domain@example.com");
    checkEmail("user.name+tag+sorting@example.com");
    checkEmail("x@example.com");
    checkEmail("example-indeed@strange-example.com");
    checkEmail("admin@mailserver1");
    checkEmail("example@s.example");
    checkEmail("mailhost!username@example.org");
    checkEmail("user%example.com@example.org");
    cout << "----------BAD EMAILS------------\n";
    checkEmail("John..Doe@example.com");
    checkEmail("Abc.example.com");
    checkEmail("A@b@c@example.com");
    checkEmail("a\"b(c)d,e:f;g<h>i[j\\k]l@example.com");
    checkEmail("1234567890123456789012345678901234567890123456789012345678901234+x@example.com");
    checkEmail("i_like_underscore@but_its_not_allow_in _this_part.example.com");
}