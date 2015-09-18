#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int desired = 25;
    int answer = 0;
    for(int i = 0; i < sqrt(desired); i++) {
        for(int j = 0; j < sqrt(desired); j++) {
            double number = sqrt(pow(i,2) + pow(j,2));
            if(floor(number) == number) {
                cout << "Pyth triplet: " << i << " " << j << " " << number << endl;
                if(number + i + j == desired) {
                    cout << "Answer is: " << number * i * j << endl;
                }
            }
        }
    }
}
