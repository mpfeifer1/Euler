#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int e = 0;
    int sum = 0;
    int number = 0;
    int powers = 0;

    for(a = 0; a < 10; a++) {
        for(b = 0; b < 10; b++) {
            for(c = 0; c < 10; c++) {
                for(d = 0; d < 10; d++) {
                    for(e = 0; e < 10; e++) {
                        number = (a * 10000) +
                                 (b * 1000) +
                                 (c * 100) +
                                 (d * 10) +
                                 (e * 1);
                        powers = pow(a, 5) +
                                 pow(b, 5) +
                                 pow(c, 5) +
                                 pow(d, 5) +
                                 pow(e, 5);
                        if(number == powers) {
                            cout << "Solution: " << number << endl;
                            sum += number;
                        }
                    }
                }
            }
        }
    }
    cout << "Sum is " << sum << endl;
}
