#include <iostream>

using namespace std;

bool contains4680(int number);
bool isPrime(int number);
bool leftTrunc(int number);
bool rightTrunc(int number);
int getFirstDigit(int number);

int main() {
    int sum = 0;
    for(int i = 9, truncPrimes = 0; truncPrimes < 11; i += 2) { // Starts at 9 because 2-7 aren't truncatable primes, counts until it's found all truncatable primes, counts by 2 to skip even numbers
        if(!contains4680(i)) {
            if(leftTrunc(i) && rightTrunc(i)) {
                cout << i << " is a truncatable prime" << endl;
                truncPrimes++;
                sum += i;
            }
        }
    }
    cout << "Sum is " << sum << endl;
}

bool contains4680(int number) {
    bool contains = false;
    for(int i = number; i > 0; i /= 10) {
        int digit = i % 10;
        switch(i) {
            case 0:
                contains = true;
                break;
            case 4:
                contains = true;
                break;
            case 6:
                contains = true;
                break;
            case 8:
                contains = true;
                break;
        }
    }
    return contains;
}

bool isPrime(int number) {
    int prime = true;
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            prime = false;
        }
    }
    return prime;
}

bool leftTrunc(int number) {
    prime = true;
    for(int i = number; i > 0; i ) {
        prime = prime && isPrime(i);
    }
}

bool rightTrunc(int number) {
    int prime = true;
    for(int i = number; i > 0; i /= 10) {
        prime = prime && isPrime(i);
    }
    return prime;
}
