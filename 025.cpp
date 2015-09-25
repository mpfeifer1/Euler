#include <iostream>

using namespace std;

int main() {
    int search = 1000;
    int past = 1;
    int current = 1;
    while(current < search) {
        past += current;
        swap(current, past);
        cout << current << endl;;
    }
}
