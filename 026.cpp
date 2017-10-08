#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if(n < 2) {
        return false;
    }
    for(int i = 2; i < sqrt(n) + 1; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    for(int i = 0; i <= 1000; i++) {
        cout.precision(17);
        if(isPrime(i)) {
            cout << i << " " << fixed << 1.0/i << endl;
        }
    }
}
