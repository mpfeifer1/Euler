#include <iostream>

using namespace std;

int main() {
    int maxChain = 0;

    for(int i = 1; i < 1000000; i++) {
        int chain = 0;
        int n = i;

        while(n > 1) {
            if(n % 2 == 0) {
                n = n/2;
            }
            else {
                n = (3 * n) + 1;
            }
            chain++;
        }

        if(chain > maxChain) {
            maxChain = chain;
        }
    }

    cout << "Longest chain is " << maxChain << endl;
}
