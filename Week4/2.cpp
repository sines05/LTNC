#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1;
    cin >> s1;
    int n = s1.size();

    bool isPalindrome = true;
    for (int i = 0; i < n / 2; ++i) {
        if (s1[i] != s1[n - i - 1]) {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
