#include <iostream>

using namespace std;

int main()
{

    cout << "Enter a number: ";
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        for (int j = 0 ; j < i; ++j) {
            cout << " ";
        }

        for (int k = 1; k <= 2*(num - i - 1) + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
