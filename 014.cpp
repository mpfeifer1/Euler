#include <iostream>

using namespace std;

int main() {
    long int maxChain = 0;
    long int maxStart = 0;

    for(long int i = 1000000; i > 1; i--) {
        long int chain = 1;
        long int n = i;

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
            maxStart = i;
        }
    }

    cout << "Longest chain starts from " << maxStart << endl;
    cout << "Longest chain is length   " << maxChain << endl;
}
