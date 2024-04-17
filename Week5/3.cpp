#include<iostream>
using namespace std;

int main() {
    int N;
    cout << "Nhap so luong phan tu: ";
    cin >> N;

    int arr[N];
    cout << "Nhap day so: ";

    for(int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int count[10] = {0};

    for(int i = 0; i < N; ++i) {
        count[arr[i]]++;
    }

    for(int i = 0; i < 10; ++i) {
        cout << "So " << i << " xuat hien " << count[i] << " lan\n";
    }

    return 0;
}
