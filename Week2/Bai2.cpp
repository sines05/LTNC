#include <iostream>
using namespace std;

int main() {
    int n {};
    cout << "Enter a number: ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            cout << " ";
        }

        for (int k = n - i; k > 0; --k) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
