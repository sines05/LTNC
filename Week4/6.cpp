#include <iostream>
using namespace std;

const int MAX = 1000;
int number[MAX][MAX];

int main() {
    int N;
    cin >> N;
    int x = 0, y = N / 2;
    number[x][y] = 1;

    int index = 2;

    while (index <= N * N) {
        int x1 = (x - 1 + N) % N;
        int y1 = (y + 1) % N;
        int x2 = (x + 1) % N;

        if (!number[x1][y1]) {
            x = x1;
            y = y1;
        } else {
            x = x2;
        }
        number[x][y] = index++;
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            cout << number[i][j] << " ";
        cout << endl;
    }

    return 0;
}
