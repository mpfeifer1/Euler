#include <iostream>

using namespace std;

long int factorial(int number);

int main() {
    int height = 20;
    int length = 20;

    int movesNeeded = height+length;
    long int permutations = factorial(movesNeeded) /
                       (factorial(length) * factorial(height));

    cout << permutations << " different paths" << endl;
}

long int factorial(int number) {
    long int sum = 1;
    for(int i = number; i > 1; i--) {
        sum *= i;
    }
    return sum;
}
