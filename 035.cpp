#include <iostream>
#include <cmath>

using namespace std;

int rotate(int number);
bool isPrime(int number);

int main() {
    cout << rotate(970) << endl;
    /*
    int max = 1000;
    for(int i = 2; i < max; i++) {
        cout << "I is " << i << endl;
        bool prime = true;
        int j;
        int count;
        for(j = i, count = i; count > 0; count /= 10) {
            j = rotate(j);
            prime = prime && isPrime(j);
            //cout << "J is " << prime << " prime" << endl;
        }
        if(prime) {
            cout << j << " is prime" << endl;
        }
    }
    */
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
    bool prime = true;
    for(int i = 3; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            prime = false;
        }
    }
    return prime;
}
