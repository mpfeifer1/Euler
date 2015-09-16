#include <iostream>

using namespace std;

int Reverse(int number) {
    int reverse = 0;
    for( ; number!= 0 ; ) {
        reverse = reverse * 10;
        reverse = reverse + number % 10;
        number = number / 10;
    }
    return reverse;
}

int main() {
    int biggestPalindrome = 0;
    for(int i = 100; i < 1000; i++) {
        for(int j = 100; j < 1000; j++) {
            if(i * j == Reverse(i * j)) {
                cout << "Palindrome: " << i * j << endl;
                if(i * j > biggestPalindrome) {
                    biggestPalindrome = i * j;
                }
            }
        }
    }
    cout << "Biggest Palindrome: " << biggestPalindrome << endl;
}
