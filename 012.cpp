#include <iostream>
#include <cmath>

using namespace std;

int getNumDivisors(int number);
int getNextTriangle(int number);

int main() {
    long int currentTriangle = 1;
    int i = 0;

    while((int)getNumDivisors(currentTriangle) < 500) {
        i++;
        currentTriangle = getNextTriangle(i);
    }

    cout << "First triangle number with 500 divisors is " << currentTriangle << endl;
}

int getNumDivisors(int number) {
    int divisors = 0;
    int root = sqrt(number);
    for(int j = 1; j <= root; j++) {
        if(number % j == 0) {
            divisors += 2;
        }
    }

    if(root * root == number) {
        divisors--;
    }
    return divisors;
}

int getNextTriangle(int number) {
    long int sum = 0;
    for(int i = 0; i <= number; i++) {
        sum += i;
    }
    return sum;
}
