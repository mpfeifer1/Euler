#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int power = 1000;
    int sum = 0;

    int digits = 500; // A guess of the number of digits in 2^1000
    int number[digits];
    number[0] = 1;
    for(int i = 1; i < digits - 1; i++) {
        number[i] = 0;
    }

    int carry = 0;

    for(int i = 0; i < power; i++) {
        cout << "i is " << i << endl;
        for(int j = 0; j < digits - 1; j++) {
            //cout << "j is " << j << endl;
            int temp = number[j] * 2;
            if(temp > 9) {
                number[j] = (temp % 10) + carry;
                carry = 1;
            } else {
                number[j] = temp + carry;
                carry = 0;
            }
        }
    }

    for(int i = digits - 1; i >= 0; i--) {
        cout << number[i];
        sum += number[i];
    }
    cout << endl;

    cout << "Sum of the digits is " << sum << endl;
}
