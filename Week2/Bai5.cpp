#include <iostream>
#include <string>
using namespace std;

string ones[] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };

string tens[] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };

string numToWords(int num, string s)
{
    string str = "";
    if (num > 19)
        str += tens[num / 10] + ones[num % 10];
    else
        str += ones[num];

    if (num)
        str += s;

    return str;
}

string convertToWords(long num)
{
    string out;

    out += numToWords((num / 10000000), "crore ");

    out += numToWords(((num / 100000) % 100), "lakh ");

    out += numToWords(((num / 1000) % 100), "thousand ");

    out += numToWords(((num / 100) % 10), "hundred ");

    if (num > 100 && num % 100)
        out += "and ";

    out += numToWords((num % 100), "");

    return out;
}

int main()
{
    long num;
    cout << "Enter a number: ";
    cin >> num;

    if (num<0)
    {
       cout<<"negative ";
       num = -num;
    }else if (num==0)
    {
       cout<<"zero";
       return 0;
    }

    cout << convertToWords(num) << endl;
    return 0;
}
