#include <iostream>

using namespace std;

bool isAbundant(int number);
int getSumOfFactors(int number);

int main() {
    int sum = 0;
    int min = 12; // Smallest Abundant Number
    int max = 28123; // Largest Abundant Number necessary
    int abundants[6965]; // Calculated total number of Abundants under 28123
    int abundantsSize = 0;
    bool found = false;
    int i;
    int j;

    for(int i = min; i <= max; i++) {
        if(isAbundant(i)) {
            abundants[abundantsSize] = i;
            abundantsSize++;
        }
    }
    cout << "Abundants list complete" << endl;

    for(int num = 1; num < max; num++) {
        cout << "Num is " << num << endl;
        found = false;
        for(int i = 0; i < abundantsSize && !found; i++) {
            for(int j = 0; j < abundantsSize && !found; j++) {
                if(abundants[i] + abundants[j] != num) {
                    sum += num;
                    found = true;
                }
            }
        }
    }
    cout << "Sum is " << sum << endl;
}

int getSumOfFactors(int number) {
    int sum = 0;
    for(int i = 1; i <= number / 2; i++) { // Add a +1 to the number/2 ???
        if(number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool isAbundant(int number) {
    return number < getSumOfFactors(number);
}
