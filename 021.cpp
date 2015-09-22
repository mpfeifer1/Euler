#include <iostream>
#include <vector>

using namespace std;

int findPair(int number);

int main() {
    vector<int> pairs;
    int max = 1000;

    for(int i = 220; i < max; i++) { // Starts at 220, the first amicable number
        if(findPair(i) > 0 && true) { // Change to "if i isn't in pairs"
            
        }
    }
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
