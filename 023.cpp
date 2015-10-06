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
    bool sumOfAbundants = false;

    // Tested, Working
    for(int i = min; i <= max; i++) {
        if(isAbundant(i)) {
            abundants[abundantsSize] = i;
            abundantsSize++;
            cout << i << endl;
        }
    }

    cout << "Abundants list complete" << endl;

    for(int num = 1; num <= max; num++) {
        //cout << "Num is " << num << endl;
        sumOfAbundants = true;

        for(int i = 0; i <= abundantsSize && sumOfAbundants; i++) {
            for(int j = i; j <= abundantsSize && sumOfAbundants; j++) {

                if(abundants[i] + abundants[j] == num) {
                    sumOfAbundants = true;
                }
                else {
                    sumOfAbundants = false;
                }

            }
        }

        if(!sumOfAbundants) {
            sum += num;
        }
    }
    cout << "Sum is " << sum << endl;
}

// Tested, Working
int getSumOfFactors(int number) {
    int sum = 0;
    for(int i = 1; i <= number / 2; i++) {
        if(number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// Tested, Working
bool isAbundant(int number) {
    return number < getSumOfFactors(number);
}
