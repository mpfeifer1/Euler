#include <iostream>

using namespace std;

void multiply(int factorial[], int number);

#define SIZE 160

int main() {
    int factorial[SIZE] = {1}; // Threre are 158 digits in 100!

    for(int i = 1; i < 100; i++) {
        multiply(factorial, i);
    }

/*
    for(int i = 0; i < SIZE; i++) {
        cout << factorial[i];
    }
    cout << endl;
*/

    int sum = 0;
    for(int i = 0; i < SIZE; i++) {
        sum += factorial[i];
    }
    cout << "Sum is " << sum << endl;

    return 0;
}

void multiply(int factorial[], int number) {
    int carry = 0;
    for(int i = 0; i < SIZE; i++) {
        factorial[i] = (factorial[i] * number) + carry;
        carry = factorial[i] / 10;
        factorial[i] %= 10;
    }
}
