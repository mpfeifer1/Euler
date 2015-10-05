#include <iosteam>

using namespace std;

bool isPrime(int number);

int main() {
    int current = 9;
    bool found = false;
    while(!found) {
        for(int i = 2; i < current; i = nextPrime(i)) {
            for(int j = 1; j < sqrt(current / 2.0) + 1; j ++) {
                if(current == i + (j * j * 2)) {

                }
            }
        }
    }
}

bool isPrime(int number) {
    for(int i = 2; i < sqrt(number) + 1; i++) {
        if(number % i == 0) {
            return false;
        }
    }
    return true;
}

int nextPrime(int number) {
    number += 2;
    if(number % 2 == 0) {
        number--;
    }
    while(!isPrime(number)) {
        number += 2;
    }
}

bool isGoldbach(int number) {

}
