#include <iostream>
using namespace std;
int main() {
    int num, num_pre;

    cin >> num;
    while (num >= 0) {
        if(num != num_pre || num_pre == 0){
           cout << num << " ";
           num_pre = num;
        }
        cin >> num;
    }
    std::cout << num << " ";
    return 0;
}
