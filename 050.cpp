#include <iostream>
#include <cmath>

using namespace std;

long int getPrime(int index);
bool isPrime(long int number);

int main() {
    cout << "0: " << getPrime(0) << endl;
    cout << "1: " << getPrime(1) << endl;
    cout << "2: " << getPrime(2) << endl;
    cout << "3: " << getPrime(3) << endl;
    cout << "100: " << getPrime(100) << endl;
    cout << "100: " << getPrime(100) << endl;
}

long int getPrime(int index) {
    // Create an array, fill with all primes under 1million, then use it to check
    static long int primes[79000]; // Guess of the number of primes under 1 million
    static int calculated = 2;

    primes[0] = 0;
    primes[1] = 1;

    if(primes[index]) { // If the specified value exists
        return primes[index];
    } else { // Calculate to that point and return
        for(; calculated <= index; calculated++) {
            primes[calculated] = primes[calculated-1] + primes[calculated-2];
        }
        return primes[index];
    }
}

bool isPrime(long int number) {
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}
