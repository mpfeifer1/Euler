#include <iostream>

using namespace std;

int pentagon(int number);

int main() {
    int search = 100; // How many pentagonal numbers to search
    for(int i = 1; i < search; i++) {
        for(int j = 1; j < search; j++) {
            // Check
            if() { // If it's found, break out
                
                break;
            }
        }
    }
}

int pentagon(int number) {
    return (number * (3 * number - 1)) / 2;
}

bool isPentagon(int number) {
    double root = sqrt(1 + 24 * n);
    return (root == int(root) && root % 6 == 5);
}
