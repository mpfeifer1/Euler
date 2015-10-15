#include <iostream>
#include <string>

using namespace std;

bool permutated(long int number1, long int number2);
bool permutatedMultiple(long int number);

int main() {
    long int number = 1;
    bool found = false;
    while(!found && number < 1000000) {
        if(permutatedMultiple(number)) {
            found = true;
            cout << "Permutated Multiple: " << number << endl;
        }
        number++;
    }
}

bool permutated(long int number1, long int number2) {
    string num1 = to_string(number1);
    string num2 = to_string(number2);
    cout << "num1: " << num1 << endl;
    return false;
}

bool permutatedMultiple(long int number) {
    return (permutated(number, 2 * number) &&
            permutated(number, 3 * number) &&
            permutated(number, 4 * number) &&
            permutated(number, 5 * number) &&
            permutated(number, 6 * number));
}
