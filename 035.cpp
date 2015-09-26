#include <iostream>
#include <cmath>

using namespace std;

int rotate(int number);
bool isPrime(int number);

int main() {
    int max = 1000;
    for(int i = 2; i < max; i++) {
        cout << "I is " << i << endl;
        for(int j = i; j > 0; j /= 10) {
            j = rotate(j);
            cout << "J is " << j << endl;
        }
    }
}

int rotate(int number) { // Moves the last digit to the first spot
    int length = 0;
    for(int i = number; i > 0; i /= 10) {
        length++;
    }
    int extraDigit = number % 10;
    number /= 10;
    number += extraDigit * pow(10, length - 1);
    return number;
}

bool isPrime(int number) {
    return false;
}
