#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int power = 4;
    int sum = 0;

    int digits = 4; // A guess of the number of digits in 2^1000
    int number[digits];
    number[0] = 1;
    for(int i = 1; i < digits - 1; i++) {
        number[i] = 0;
    }

    bool carryNext = false;
    bool carryThis = false;

    for(int i = 0; i < power; i++) {
        cout << "i is " << i << endl;
        for(int j = 0; j < digits - 1; j++) {
            //cout << "j is " << j << endl;
            int temp = number[i];
            if((temp * 2) % 10 == temp * 2) {
                number[i] = temp * 2;
            } else {
                number[i] = (temp * 2) % 10;
                carryNext = true;
            }

            if(carryThis) {
                number[i] += 1;
                carryThis = false;
            }

            if(carryNext) {
                carryNext = false;
                carryThis = true;
            }
        }
    }
    cout << "Successfully carried" << endl;

    for(int i = digits - 1; i >= 0; i--) {
        cout << number[i];
    }
    cout << endl;

    cout << "Sum of the digits is " << sum << endl;
}
