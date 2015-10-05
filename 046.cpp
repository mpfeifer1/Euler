#include <iosteam>

using namespace std;

bool isPrime(int number);

int main() {
    int current = 9;
    bool found = false;
    while(!found) {
        
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
