#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int pentagon(int number);
bool isPentagon(int number);

int main() {
    cout << fixed;
    int search = 10000; // How many pentagonal numbers to search
    for(int i = 1; i < search; i++) {
        for(int j = 1; j < search; j++) {
            if( isPentagon(abs(pentagon(j)-pentagon(i))) && isPentagon(pentagon(i)+pentagon(j)) ) { // If it's found, break out
                cout << "Difference is " << abs(pentagon(j) - pentagon(i)) << endl;
                break;
            }
        }
    }
}

int pentagon(int number) {
    return (number * (3 * number - 1)) / 2;
}

bool isPentagon(int number) {
    double root = sqrt(1 + 24 * number);
    return (root == int(root) && (int)root % 6 == 5);
}
