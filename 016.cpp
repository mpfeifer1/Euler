#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int power = 1000;
    long int sum = 0;
    long unsigned double number = pow(2, power);
    cout << "Number is " << number << endl;

    while(number > 0) {
        int digit = number fmod(10);
        number /= 10;
        sum += digit;
    }

    cout << "Sum of the digits is " << sum << endl;
}
