#include <iostream>

using namespace std;

bool isAbundant(int number);
bool isSumOfTwoAbundant(int number);
int getSumOfFactors(int number);
int getNextAbundant(int number);

int main() {
    int sum = 0;
    int min = 12; // Smallest Abundant Number
    int max = 28123; // Largest Abundant Number necessary
    int abundants[6965]; // Calculated total number of Abundants under 28123
    int index = 0;

    for(int i = min; i <= max; i++) {
        if(isAbundant(i)) {
            abundants[index] = i;
            index++;
            cout << "Added " << i << endl;
        }
    }

    for(int num = 1; num < max; num++) {
        cout << "Num is " << num << endl;
        for(int& i : abundants) {
            for(int& j : abundants) {
                if(i + j == num) {
                    sum += i;
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
    if(number < 12) {
        return false;
    }
    return number < getSumOfFactors(number);
}

int getNextAbundant(int number) {
    number++;
    while(!isAbundant(number)) {
        number++;
    }
    return number;
}
