#include <iostream>

using namespace std;

bool isAbundant(int number);
int getSumOfFactors(int number);

int main() {
    int sum = 0;
    int min = 12; // Smallest Abundant Number
    int max = 28123; // Largest Abundant Number necessary
    int abundants[max]; // Calculated total number of Abundants under 28123
    int abundantsSize = 0;
    bool sumOfAbundants = false;
    bool canBeAbundant[max + 1];

    // Fills List with all abundant numbers, defaults canBeAbundant to false
    for(int i = min; i <= max; i++) {
        if(isAbundant(i)) {
            abundants[abundantsSize] = i;
            abundantsSize++;
        }
        canBeAbundant[i] = false;
    }


    // Fills canBeAbundant list with true if a number can be written as a sum of abundants
    for(int i = 0; i <= abundantsSize; i++) {
        for(int j = i; j <= abundantsSize; j++) {
            if(abundants[i] + abundants[j] <= max) {
                canBeAbundant[abundants[i] + abundants[j]] = true;
            } else {
                break;
            }
        }
    }

    // Sums all numbers that can't be abundant
    for(int i = 0; i <= max; i++) {
        if(!canBeAbundant[i]) {
            sum += i;
        }
    }

    cout << "Sum is " << sum << endl;
}

// Gets the sum of factors
int getSumOfFactors(int number) {
    int sum = 0;
    for(int i = 1; i <= number / 2; i++) {
        if(number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

// Determinese whether number is abundant
bool isAbundant(int number) {
    return number < getSumOfFactors(number);
}
