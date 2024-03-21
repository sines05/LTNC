#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* number = new int[n];
    bool success = false;
    for (int i = 0; i < n; ++i) {
        cin >> number[i];
        if (i > 0 && number[i] == number[i - 1]) {
            success = true;
        }
    }

    if (success) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    delete[] number;
    return 0;
}
