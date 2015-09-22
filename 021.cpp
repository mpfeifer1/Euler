#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int findPair(int number);

int main() {
    vector<int> pairs = {0};
    int max = 10000;

    for(int i = 220; i < max; i++) { // Starts at 220, the first amicable number
        if(findPair(i) > 0 && findPair(i) != i && find(pairs.begin(), pairs.end(), i) == pairs.end() ) { // If i has a pair, doesn't equal itself, and isn't in the list
            pairs.push_back(i);
            pairs.push_back(findPair(i));
        }
    }

    int sum = 0;
    for(int i: pairs) {
        sum += i;
    }

    cout << "Total is " << sum << endl;
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
