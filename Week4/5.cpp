#include <iostream>
using namespace std;

const int MAX = 1000;
int tornado[MAX][MAX];
int x, y;

int main() {
    cin >> x >> y;
    int number = 1;
    int up = 0, down = x - 1, left = 0, right = y - 1;

    while (number <= x * y) {
        for (int i = left; i <= right && number <= x * y; i++)
            tornado[up][i] = number++;

        for (int i = up + 1; i <= down && number <= x * y; i++)
            tornado[i][right] = number++;

        for (int i = right - 1; i >= left && number <= x * y; i--)
            tornado[down][i] = number++;

        for (int i = down - 1; i > up && number <= x * y; i--)
            tornado[i][left] = number++;

        up++; down--; left++; right--;
    }

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++)
            cout << tornado[i][j] << "   ";
        cout << endl;
    }

    return 0;
}
