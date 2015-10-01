#include <iostream>
#include <strings.h>
#include <algorithm>
#include <string>

using namespace std;

int factorial(int number);

int main() {
    int height = 2;
    int length = 2;

    int movesNeeded = height+length;
    int permutations = factorial(movesNeeded) /
                       (factorial(length) * factorial(height));

    cout << permutations << "different paths" << endl;
}

int factorial(int number) {
    int sum = 0;
    for(int i = number; i > 1; i--) {
        sum *= i;
    }
    return sum;
}
