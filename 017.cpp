#include <iostream>

using namespace std;

int countLetters(int number);

int main() {
    int number = 5;
    cout << "Letters in " << number << ": " << countLetters(number) << endl;
}


// Maxes out at 1000;
int countLetters(int number) {
    int letters = 0;

    int numberCopy = number;
    // Count tens/hundreds/thousand
    if(number == 1000) {
        letters += 8; // 8 letters in "thousand"
    }

    // For thousands and hundreds
    switch(digit) {
        case: 1
            count += 3;
            break
        case: 2
            count += 3;
            break;
        case: 3
            count += 5;
            break;
        case: 4
            count += 4;
            break
        case: 5
            count += 4;
            break;
        case: 6
            count += 3;
            break;
        case: 7
            count += 5;
            break;
        case: 8
            count += 5;
            break;
        case: 9
            count += 4;
            break;
    }
}
