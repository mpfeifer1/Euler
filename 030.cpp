#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int a;
    int b;
    int c;
    int d;
    int e;
    int sum;

    for(a = 0; a < 10; a++) {
        for(b = 0; b < 10; b++) {
            for(c = 0; c < 10; c++) {
                for(d = 0; d < 10; d++) {
                    int number = (a * 1000) + (b * 100) + (c * 10) + (d * 1);
                    int powers = pow(a, 4) + pow(b, 4) + pow(c, 4) + pow(d, 4);
                    if(number == powers) {
                        cout << "Solution: " << number << endl;
                        sum += number;
                    }
                }
            }
        }
    }
    sum -= 1; // Because 1 is not a sum
    cout << "Sum is " << sum << endl;
}
