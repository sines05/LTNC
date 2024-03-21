#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 1e7;
int minute[MAX];

int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> minute[i];

    sort(minute, minute + N);

    long long waitTime = 0;


    for (int i = 0; i < N; i++)
        waitTime += (long long)minute[i] * (N - i - 1);

    cout << waitTime << endl;
}
