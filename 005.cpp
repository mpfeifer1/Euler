#include <iostream>

using namespace std;

bool divisible(int divisor);

int main() {
    bool found = false;
    int divisor = 0;
    while(!found) {
        divisor += 20;
        if(divisible(divisor)) {
            found = true;
        }
    }
    cout << "Smallest Integer: " << divisor << endl;
}

bool divisible(int divisor) {
    bool divisible = true;
    for(int i = 1; i <= 20; i++) {
        if(divisor % i != 0) {
            divisible = false;
        }
    }
    return divisible;
}
