#include <iostream>

using namespace std;

int main()
{

    cout << "Enter a number: ";
    int num;
    cin >> num;
    for (int i = 0; i < num; ++i) {
        for (int j = num - i - 1; j > 0; --j) {
            cout << " ";
        }

        for (int k = 1; k <= 2*i + 1; ++k) {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}
