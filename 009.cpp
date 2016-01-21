#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
    setprecision(12);
    int desired = 1000;
    for(int i = 1; i < desired / 2; i++) {
        for(int j = 1; j < desired / 2; j++) {
            double number = sqrt(pow(i,2) + pow(j,2));
            if(floor(number) == number) {
                if(number + i + j == desired) {
                    cout << "Answer is: " << number * i * j << fixed << endl;
                }
            }
        }
    }
}