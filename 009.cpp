#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    setprecision(12);
    int desired = 1000;
    double answer = 0;
    for(int i = 1; i < desired / 2; i++) {
        for(int j = 1; j < desired / 2; j++) {
            double number = sqrt(pow(i,2) + pow(j,2));
            if(floor(number) == number) {
                cout << "Pyth triplet: " << i << " " << j << " " << number << endl;
                if(number + i + j == desired) {
                    answer = number * i * j;
                    cout << "Answer is: " << answer << fixed << endl;
                }
            }
        }
    }
}
