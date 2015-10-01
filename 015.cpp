#include <iostream>

using namespace std;

long int factorial(long int number);

int main() {
    long int height = 2;
    long int length = 2;

    long int movesNeeded = height+length;
    long int permutations = factorial(movesNeeded) /
                       (factorial(length) * factorial(height));

    cout << permutations << " different paths" << endl;
}

long int factorial(long int number) {
    long int sum = 1;
    for(int i = number; i > 1; i--) {
        sum *= i;
    }
    return sum;
}
