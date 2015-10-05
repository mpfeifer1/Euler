#include <iostream>

using namespace std;

bool isAbundant(int number);
bool isSumOfTwoAbundant(int number);
int getSumOfFactors(int number);
int getNextAbundant(int number);

int main() {
    int sum = 0;
    for(int i = 12; i <= 28123; i++) {
        if(!isSumOfTwoAbundant(i)) {
            sum += i;
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

bool isSumOfTwoAbundant(int number) {
    for(int i = 12; i < number; i = getNextAbundant(i)) {
        for(int j = 12; j < number; j = getNextAbundant(j)) {
            if(number == i + j) {
                return true;
            }
        }
    }
    return false;
}

int getNextAbundant(int number) {
    number++;
    while(!isAbundant(number)) {
        number++;
    }
    return number;
}
