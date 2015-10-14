#include <iostream>

using namespace main;

int getPrime(int index);
bool isPrime(int number);

int main() {
    // Count all
}

int getPrime(int index) {
    // Create an array, fill with all primes under 1million, then use it to check
    static int primes[79000]; // Guess of the number of primes under 1 million

    primes[0] = 0;
    primes[1] = 1;

    
}

bool isPrime(int number) {
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            return false
        }
    }
    return true;
}
