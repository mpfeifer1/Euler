#include <iostream>

using namespace std;

bool isAbundant(int number);
bool isSumOfTwoAbundant(int number);
int getSumOfFactors(int number);

int main() {
    int sum = 0;
    /*
    for(int i = 0; i <= 28123; i++)
        if(!isSumOfTwoAbundant(i)) {
            sum += i;
        }
    }
    */
    cout << "Sum is " << sum << endl;
}

int getSumOfFactors(int number) {
    int sum = 0;
    for(int i = 1; i <= number / 2; i++) {
        if(number % i == 0) {
            sum += i;
        }
    }
    return sum;
}

bool isAbundant(int number) {
    return number < getSumOfFactors(number);
}
