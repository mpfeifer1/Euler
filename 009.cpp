#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int desired = 1000;
    for(int i = 1; i < desired / 2; i++) {
        for(int j = 1; j < desired / 2; j++) {
            double number = sqrt(i * i + j * j);
            if(floor(number) == number) {
                if(number + i + j == desired) {
                    cout << "Answer is: " << number * i * j << endl;
                }
            }
        }
    }
}
