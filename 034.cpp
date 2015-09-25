#include <iostream>

using namespace std;

long int sumFactorials(long int number);
long int factorial(long int number);

int main() {
    int sum = 0;
    for(long int i = 3; i <  10000; i++) { // Skips 1 and 2 as they are not sums
        if(i == sumFactorials(i)) {
            sum += i;
            cout << "Added " << i << endl;
        }
    }
    cout << "Sum is " << sum << endl;
}

long int sumFactorials(long int number) {
    long int sum = 0;
    cout << "Processing " << number << endl;
    while(number > 0) {
        sum += factorial(number % 10);
        number /= 10;
    }
    //cout << "Sum is " << sum << endl;
    return sum;
}

long int factorial(long int number) {
    long int product = 1;
    for(long int i = number; i > 1; i--) {
        product *= i;
        // cout << "i is " << i << endl;
    }
    //cout << "Factorial is " << product << endl;
    return product;
}
