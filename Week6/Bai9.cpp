#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int randomLessThanN(int N) {
    return rand() % N;
}

int main() {

    srand(time(0));

    int N;
    cout << "Enter a positive integer N: ";
    cin >> N;

    // In ra một số ngẫu nhiên nhỏ hơn N
    cout << "Random number less than N: " << randomLessThanN(N) << "\n";

    return 0;
}
