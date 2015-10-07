#include <iostream>

using namespace std;

void swapIndex(int i, int j, int number[]);

int main() {
    int number[] = {0, 1, 2}; // Leave it in numerical order
    int size = 3; // Number of values in above array
    int permutations = 1; // Times to permute number

    swapIndex(2,1, number);

    // Print out number
    cout << "Number is ";
    for(int i = 0; i < size; i++) {
        cout << number[i];
    }
    cout << endl;
}

void swapIndex(int i, int j, int number[]) {
    int temp = number[i];
    number[i] = number[j];
    number[j] = temp;
}
