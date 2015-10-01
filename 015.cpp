#include <iostream>

using namespace std;

long int factorial(int movesNeeded, int sideLength);

int main() {
    int sideLength = 20;

    int movesNeeded = 2 * sideLength;
    long int permutations = factorial(movesNeeded, sideLength);

    cout << permutations << " different paths" << endl;
}

long int factorial(int movesNeeded, int sideLength) {
    long double sum = 1;

    for(int i = 1; i <= movesNeeded; i++) {
        sum *= i;
        if(i <= sideLength) {
            sum /= (i * i);
        }
        cout << "Sum is " << sum << endl;
    }

    return (long int)sum;
}
