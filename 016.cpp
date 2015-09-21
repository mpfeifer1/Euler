#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int power = 15; // Change to 1000
    long int sum = 0;
    long int number = pow(2, power);

    while(number > 0) {
        int digit = number % 10;
        number /= 10;
        sum += digit;
    }

    cout << "Sum of the digits is " << sum << endl;
}
