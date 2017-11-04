#include <iostream>
#include <cmath>
#include <set>

using namespace std;

int T = 4;

int primefactors(int n) {
    set<int> factors;

    while(n > 1) {
        bool broken = false;
        for(int i = 2; i <= sqrt(n); i++) {
            if(n % i == 0) {
                n /= i;
                factors.insert(i);
                broken = true;
                break;
            }
        }
        if(!broken) {
            factors.insert(n);
            n = 1;
        }
    }

    return factors.size();
}

int main() {
    int i = 10;
    int found = 0;
    int ans = 0;
    while(found < T) {
        i++;

        if(primefactors(i) == T) {
            found++;
        }
        else {
            ans = i+1;
            found = 0;
        }
    }

    cout << ans << endl;
}
