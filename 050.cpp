#include <iostream>
#include <cmath>

using namespace std;

int getPrime(int index);
bool isPrime(int number);

int main() {

    getPrime(-1); // Initialization
    for(int n = 1; n <= 79000; n++) {
        int sum;
        for(int o = 1; o <= 79000; o++) {
            sum += getPrime(n);
            if(isPrime(sum) && sum > 0 && sum < 1000000) {
                cout << sum << endl;
            }
            if(sum > 1000000) {
                break;
            }
        }
    }
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

