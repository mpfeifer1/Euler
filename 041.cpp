#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

typedef long long ll;

bool isprime(ll n) {
    for(int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    string s = "7654321";

    while(prev_permutation(s.begin(), s.end())) {
        if(isprime(stoll(s))) {
            cout << s << endl;
            break;
        }
    }
}
