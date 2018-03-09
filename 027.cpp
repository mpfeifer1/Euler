#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

vector<bool> primes(1000000, false);

bool isprime(ll n) {
    if(n < 2) {
        return false;
    }
    if(n == 2) {
        return true;
    }
    for(ll i = 2; i <= sqrt(n)+1; i++) {
        if(n % i == 0) {
            return false;
        }
    }
    return true;
}

ll calc(ll a, ll b, bool print = false) {
    ll n = 0;
    while(true) {
        ll oldprime = (n-1)*(n-1) + a*(n-1) + b;
        ll newprime = n*n + a*n + b;
        if(newprime < 0) {
            break;
        }
        if(!primes[newprime]) {
            break;
        }
        if(print) {
            cout << newprime << " ";
        }
        n++;
    }
    if(print) {
        cout << endl;
    }
    return n;
}

int main() {
    for(ll i = 0; i < 1000000; i++) {
        if(isprime(i)) {
            primes[i] = true;
        }
    }

    ll mostprimes = 0;
    vector<pair<ll,ll>> best;
    ll num = 1000;
    for(ll i = -num; i <= num; i++) {
        for(ll j = -num; j <= num; j++) {
            ll primeshere = calc(i, j);
            if(primeshere == mostprimes) {
                best.push_back({i,j});
            }
            if(primeshere > mostprimes) {
                mostprimes = primeshere;
                best.clear();
                best.push_back({i,j});
            }
        }
    }

    for(auto i : best) {
        cout << i.first << " " << i.second << " " << i.first*i.second << endl;
        calc(i.first, i.second, true);
    }

    /*
    cout << endl << endl;
    calc(1,41,true);
    cout << endl << endl;
    calc(-79,1601,true);
    cout << endl << endl;
    */
}
