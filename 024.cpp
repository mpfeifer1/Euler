#include <iostream>
#include <vector>

using namespace std;

void removeIndex(int i, vector<int> number);
int factorial(int number);

int main() {
    static const int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Initialize array in numeric order
    vector<int> initial (arr, arr + sizeof(arr) / sizeof(arr[0])); // Copy array to vector

    string permuted = "";
    int remain = 1000000 - 1; // Times to permute number

    // Combinatorics
    // The last 9 digits can be ordered in 9! ways, so the first 362880 permutations start with 0
    for(int i = 1; i < 10; i++) {
        // Calculates how many permutations for the first number
        int j = remain / factorial(initial[initial.size() - i]);
        remain %= factorial(initial.size() - i);

        // Places the number of permutations found in the next "Available" slot in the number
        permuted += initial[j];
        initial.erase(initial.begin() + i);
        if(remain == 0) {
            break;
        }
    }

    // Print out number
    cout << "Number is ";
    for(int i = 0; i < initial.size(); i++) {
        cout << initial[i];
    }
    cout << endl;
}

// Calculates a number's factorial
int factorial(int number) {
    int product = 1;
    for(int i = number; number > 0; number--) {
        product *= number;
    }
    return product;
}
