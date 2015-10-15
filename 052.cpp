#include <iostream>

using namespace std;

bool permutated(long int number1, long int number2);
bool permutatedMultiple(long int number);

int main() {
    long int number = 1;
    bool found = false;
    while(!found) {
        if(permutatedMultiple(number)) {
            found = true;
            cout << "Permutated Multiple: " << number << endl;
        }
        number++;
    }
}

bool permutated(long int number1, long int number2) {
    
}

bool permuatedMultiple(long int number) {
    return (permutated(number, 2 * number) &&
            permutated(number, 3 * number) &&
            permutated(number, 4 * number) &&
            permutated(number, 5 * number) &&
            permutated(number, 6 * number));
}
