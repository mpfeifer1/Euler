#include <iostream>

using namespace std;

int findPair(int number);

int main() {
    int number = 284;
    cout << number << "'s pair is " << findPair(number) << endl;
}

int findPair(int number) {
    int newNumber = 0; // The (hopefully) amicable pair for number
    for(int i = 1; i <= number / 2 + 1; i++) {
        if(number % i == 0) {
            newNumber += i;
        }
    }

    int oldNumber = 0; // If amicable, this will equal number
    for(int i = 1; i <= newNumber / 2 + 1; i++) {
        if(newNumber % i == 0) {
            oldNumber += i;
        }
    }

    if(number == oldNumber) {
        return newNumber; // Returns opposite pair if true
    }

    return -1; // Returns -1 if they're not a pair
}
