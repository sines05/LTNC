#include <iostream>
#include <cmath>
using namespace std;

// Định nghĩa thứ nhất với hàm floor và ceil
int rnd1(double num) {
    return num - floor(num) <= 0.5 ? floor(num) : ceil(num);
}

// Định nghĩa thứ hai không sử dụng floor và ceil
int rnd2(double num) {
    return ((num - (int)num) >= 0.5) ? (int)(num + 1) : (int)num;
}

int main() {
    double num;
    cout << "Enter a real number: ";
    cin >> num;
    cout << "Rounded number (using floor and ceil): " << rnd1(num) << "\n";
    cout << "Rounded number (without using floor and ceil): " << rnd2(num) << "\n";

    return 0;
}
