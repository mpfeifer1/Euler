#include <iostream>

using namespace std;

void removeIndex(int i, int length, int number[]);
int factorial(int number);

int main() {
    int initial[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Leave it in numerical order
    int length = 10;
    string permuted = "";
    int remain = 1000000 - 1; // Times to permute number

    // Combinatorics
    // The last 9 digits can be ordered in 9! ways, so the first 362880 permutations start with 0
    for(int i = 1; i < 10; i++) {
        // Calculates how many permutations for the first number
        int j = remain / factorial(length - i);
        int remain %= factorial(length - i);

        // Places the number of permutations found in the next "Available" slot in the number
        permuted += initial[j];
        initial.
    }

    // Print out number
    cout << "Number is ";
    for(int i = 0; i < size; i++) {
        cout << number[i];
    }
    cout << endl;
}

// Swaps 2 array values
void removeIndex(int i, int length, int number[]) {
    for(int j = i; j < length; j++) {
        
    }
}

// Calculates a number's factorial
int factorial(int number) {
    int product = 0;
    for(int i = number; number > 0; number--) {
        product *= number;
    }
    return product;
}
