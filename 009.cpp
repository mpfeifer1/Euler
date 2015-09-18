#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int desired = 1000;
    int answer = 0;
    for(int i = 1; i < desired / 3; i++) {
        for(int j = 1; j < desired / 3; j++) {
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
