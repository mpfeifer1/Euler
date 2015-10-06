#include <iostream>

using namespace std;

int main() {
    int number[] = {0, 1, 2}; // Leave it in numerical order
    int size = 3; // Number of values in above array
    int permutations = 1; // Times to permute number

    for(int i = 0; i < permutations; i++) {
        int temp = number[i];
        number[i] = number[i+1];
        number[i+1] = temp;
    }

    // Print out number
    cout << "Number is ";
    for(int i = 0; i < size; i++) {
        cout << number[i];
    }
    cout << endl;
}
