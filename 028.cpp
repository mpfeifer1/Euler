#include <iostream>

using namespace std;

int main() {
    const int SIZE = 1001;

    long int sum     = 1; // Starts at 1 for center point
    int numToSkip    = 1; // Number of items to skip
    int timesSkipped = 0;
    int cornersHit   = 0;

    for(int i = 2; i <= (SIZE * SIZE); i++) {
        if(timesSkipped == numToSkip) {
            sum += i;
            timesSkipped = 0;
            cornersHit++;
        } else {
            timesSkipped++;
        }
        if(cornersHit == 4) {
            numToSkip += 2;
            cornersHit = 0;
        }
    }

    cout << "Sum is " << sum << endl;

    return 0;
}
