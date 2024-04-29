#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two positive integers a and b: ";
    cin >> a >> b;

    int d = gcd(a, b);

    cout << "The greatest common divisor of a and b is " << d << "\n";

    if (d == 1) {
        cout << "a and b are coprime numbers.\n";
    } else {
        cout << "a and b are not coprime numbers.\n";
    }

    return 0;
}
