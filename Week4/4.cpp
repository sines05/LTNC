#include <iostream>
using namespace std;

const int MAX = 1000;
char bomb[MAX][MAX];
int m, n;

int checkbomb(int x, int y) {
    if (bomb[x][y] == '*')
        return -1;

    int ans = 0;
    for (int i = max(0, x - 1); i <= min(m - 1, x + 1); i++) {
        for (int j = max(0, y - 1); j <= min(n - 1, y + 1); j++) {
            if (bomb[i][j] == '*')
                ans++;
        }
    }

    return ans;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> bomb[i][j];
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int result = checkbomb(i, j);
            if (result == -1)
                cout << "* ";
            else
                cout << result << " ";
        }
        cout << endl;
    }

    return 0;
}
