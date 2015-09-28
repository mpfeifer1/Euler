#include <iostream>
#include <cmath>

using namespace std;

bool contains4680(int number);
bool isPrime(int number);
bool leftTrunc(int number);
bool rightTrunc(int number);

int main() {
    int sum = 0;
    for(int i = 999, truncPrimes = 0; truncPrimes < 11 && i < 100000000; i += 2) { // Starts at 999 for 3-digit nums, counts until all trunc primes found, counts by 2 to skip even numbers
        if(!contains4680(i)) {
            if(leftTrunc(i) && rightTrunc(i)) {
                cout << i << " is a truncatable prime" << endl;
                truncPrimes++;
                sum += i;
            }
        }
    }
    cout << "Sum is " << sum << endl;
    return 0;
}

bool contains4680(int number) {
    for(int i = number; i > 0; i /= 10) {
        int digit = i % 10;
        switch(i) {
            case 0:
                return true;
            case 4:
                return true;
            case 6:
                return true;
            case 8:
                return true;
        }
    }
    return false;
}

bool isPrime(int number) {
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0 && i != number) {
            return false;
        }
    }
    return true;
}

bool leftTrunc(int number) {
    for(int i = 10; i < number; i *= 10) {
        if(!isPrime(number % i)) {
            return false;
        }
    }
    return true;
}

bool rightTrunc(int number) {
    for(int i = number; i > 0; i /= 10) {
            if(!isPrime(i)) {
            return false;
        }
    }
    return true;
}

