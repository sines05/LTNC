#include <iostream>
using namespace std;

int countPalindromes(int a, int b) {
    int ans = 0;

    for (int i = a; i <= b; ++i) {
        int num = i;
        int reversed = 0;

        // Reverse the number
        while (num > 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }


        if (i == reversed) {
            ans++;
        }
    }

    return ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        cout << countPalindromes(a, b) << endl;
    }
    return 0;
}
