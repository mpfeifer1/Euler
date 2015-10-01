#include <iostream>

using namespace std;

long int factorial(int movesNeeded, int sideLength);

int main() {
    int sideLength = 2;

    int movesNeeded = 2 * sideLength;
    long int permutations = factorial(movesNeeded, sideLength);

    cout << permutations << " different paths" << endl;
}

long int factorial(int movesNeeded, int sideLength) {
    long int sum = 1;

    for(int i = sideLength + 1; i <= movesNeeded; i++) {
        sum *= i;
    }

    sum /= sideLength;
    return sum;
}
