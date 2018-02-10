#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

int cycle(int n) {
    unordered_map<int,int> seen;
    int remainder = 1;
    int length = 0;
    while(remainder > 0 && seen.count(remainder) == 0) {
        seen[remainder] = length;
        length++;
        remainder *= 10;
        remainder %= n;
    }
    if(remainder != 0) {
        return length - seen[remainder];
    }
    return 0;
}

int main() {
    int best = 0;
    int bestcycle = 0;
    for(int i = 1; i <= 1000; i++) {
        int here = cycle(i);

        if(here > bestcycle) {
            bestcycle = here;
            best = i;
        }

        cout << "I: " << i << " " << here << endl;
    }
    cout << "Best: " << best << endl;
}
