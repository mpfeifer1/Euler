#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int sumOfSquares = 0;
    int squareOfSum = 0;
    for(int i = 0; i <= 100; i++) {
        squareOfSum += i;
        sumOfSquares += pow(i,2);
    }
    squareOfSum = pow(squareOfSum,2);
    cout << squareOfSum - sumOfSquares << endl;
}
