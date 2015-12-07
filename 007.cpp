#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int number) {
    for(int j = 2; j < sqrt(number) + 1; j++) {
        if(number % j == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int desired = 10001;
    int primes[desired];
    primes[0] = 2;
    int newNumber;
    for(int i = 1; i <= desired; i++) {
        bool found = false;
        newNumber = primes[i-1] + 1;
        while(!found) {
            if(isPrime(newNumber)) {
                primes[i] = newNumber;
                found = true;
            }
            newNumber++;
        }
    }
    cout << desired << "th prime: " << primes[desired - 1] << endl;
}
