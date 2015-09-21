#include <iostream>

using namespace std;

int countLetters(int number);
int digitToLetters(int digit);
int tensToLetters(int number);

int main() {
    int number = 5;
    cout << "Letters in " << number << ": " << tensToLetters(number) << endl;
}


// Maxes out at 1000;
int countLetters(int number) {
    int letters = 0;

    int numberCopy = number;
    // Count tens/hundreds/thousand
    if(number == 1000) {
        letters += 8; // 8 letters in "thousand"
    }
}

int digitToLetters(int digit) {
    switch(digit) {
        case 0:
            return 0;
        case 1:
            return 3;
        case 2:
            return 3;
        case 3:
            return 5;
        case 4:
            return 4;
        case 5:
            return 4;
        case 6:
            return 3;
        case 7:
            return 5;
        case 8:
            return 5;
        case 9:
            return 4;
    }
}

int tensToLetters(int number) {

    int count = 0;

    if(number >= 20) { // If number isn't already accounted for, add 2nd digit
        count += digitToLetters(number % 10);
    }

    if(number >= 90) {
        count += 6;
    } else if(number >= 80) {
        count += 6;
    } else if(number >= 70) {
        count += 7;
    } else if(number >= 60) {
        count += 5;
    } else if(number >= 50) {
        count += 5;
    } else if(number >= 40) {
        count += 6;
    } else if(number >= 30) {
        count += 6;
    } else if(number >= 20) {
        count += 6;
    } else if(number == 19) {
        count += 8;
    } else if(number == 18) {
        count += 8;
    } else if(number == 17) {
        count += 9;
    } else if(number == 16) {
        count += 7;
    } else if(number == 15) {
        count += 7;
    } else if(number == 14) {
        count += 8;
    } else if(number == 13) {
        count += 8;
    } else if(number == 12) {
        count += 6;
    } else if(number == 11) {
        count += 6;
    } else if(number == 10) {
        count += 3;
    } else {
        count += digitToLetters(number);
    }

    return count;

}
