#include <iostream>
#include <cmath>

using namespace std;

int getNextPrime(int number) {
    while(true) {
        bool isPrime = true;
        number++;
        int root = (int)sqrt(number);
        for(int i = 2; i <= root; i++) {
            if(number % i == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) {
            return number;
        }
    }
}

int main() {
    int max = 10;
    long int currentPrime = 2;
    long int sum = 0;
    while(currentPrime < max) {
        cout << "Current Prime: " << currentPrime << endl;
        sum += currentPrime;
        currentPrime = getNextPrime(currentPrime);
    }
    cout << "Sum: " << sum << endl;
}
