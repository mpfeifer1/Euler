#include <iostream>
#include <cmath>

using namespace std;

boolean isPrime(int number) {
    boolean prime = true;
    for(int j = 0; j < sqrt(number) + 1; j++) {
        if((double)number / j == (double)number % j) {
            prime = false;
        }
    }
    return prime;

int main() {
    int primes [10001];
    primes [0] = 2;
    for(int i = 1; i <= 10001; i++) {
        bool found = false;
        int newNumber = primes[i-1] + 1;
        while(!found) {
            if(isPrime(newNumber)) {
                primes[i] = newNumber;
            }
            newNumber++;
        }
    }
}