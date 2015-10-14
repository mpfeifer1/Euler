#include <iostream>
#include <cmath>

using namespace std;

int getPrime(int index);
bool isPrime(int number);

int main() {
    cout << "Initializing: " << getPrime(-1) << endl;
    cout << "0: " << getPrime(0) << endl;
    cout << "1: " << getPrime(1) << endl;
    cout << "2: " << getPrime(2) << endl;
    cout << "3: " << getPrime(3) << endl;
    cout << "4: " << getPrime(4) << endl;
    cout << "5: " << getPrime(5) << endl;
    cout << "6: " << getPrime(6) << endl;
    cout << "7: " << getPrime(7) << endl;
    cout << "8: " << getPrime(8) << endl;
    cout << "9: " << getPrime(9) << endl;
    cout << "8: " << getPrime(8) << endl;
    cout << "1000: " << getPrime(1000) << endl;
    cout << "1000: " << getPrime(1000) << endl;
}

int getPrime(int index) {
    // Create an array, fill with all primes under 1million, then use it to check
    static const int length = 79000; // Guess of number of primes under 1million
    static int primes[length];
    static bool run = false;
    static int prime = 2;

    if(run) { // If the specified value exists
        return primes[index];
    } else { // Calculate to that point and return
        primes[1] = 2;
        for(int i = 2; i < length; i++) {
            while(!isPrime(prime)) {
                prime++;
            }
            primes[i] = prime;
            prime++;
        }
        run = true;
        return 1;
    }
}

bool isPrime(int number) {
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}
