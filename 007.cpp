#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(long int number) {
    bool prime = true;
    for(long int j = 2; j < sqrt(number) + 1; j++) {
        cout << "j: " << j << endl;
        if(number % j == 0) {
            cout << "not prime";
            prime = false;
            break;
        }
    }
    return prime;
}

int main() {
    cout << isPrime(49) << endl;
/*
    int primes [10001];
    primes [0] = 2;
    for(int i = 1; i <= 10001; i++) {
        cout << "i: " << i << endl;
        bool found = false;
        long int newNumber = primes[i-1] + 1;
        while(!found) {
            if(isPrime(newNumber)) {
                primes[i] = newNumber;
            }
            newNumber++;
        }
    }
*/
}
