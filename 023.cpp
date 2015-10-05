#include <iostream>

using namespace std;

bool isAbundant(int number);
bool isSumOfTwoAbundant(int number);

int main() {
    int sum = 0;
    for(int i = 0; i <= 28123; i++)
        if(!isSumOfTwoAbundant(i)) {
            sum += i;
        }
    }
}
