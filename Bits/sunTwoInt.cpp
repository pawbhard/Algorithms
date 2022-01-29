#include <iostream>

using namespace std;

int getSum(int a, int b) {
    while(b != 0) {
        
        unsigned int carry  = a & b;
        a = a ^ b;
        b = carry << 1;
    }
    return a;
}

int main() {
    cout<<getSum(17,18);
    return 0;
}