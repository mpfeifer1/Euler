#include <iostream>
#include <cmath>

using namespace std;

int rotate(int number);
bool isPrime(int number);

int main() {
    int max = 1000000;
    int sum = 1; // Starts at 1 to include 2, which is skipped by this method
    for(int i = 3; i < max; i += 2) { // Skips every other because no even number is prime
        //cout << "I is " << i << endl;
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
            sum++;
        }
    }
    cout << "Sum is " << sum << endl;
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
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            prime = false;
        }
    }
    return prime;
}
