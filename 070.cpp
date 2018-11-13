#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

ll phi(ll n) {
    ll result = n;
    for(ll i = 2; i*i < n; i++) {
        if(n % i == 0) {
            while(n % i == 0) {
                n /= i;
            }
            result -= result / i;
        }
    }

    if(n > 1) {
        result -= result / n;
    }

    return result;
}

bool perm(ll a, ll b) {
    vector<int> ca(10,0);
    vector<int> cb(10,0);

    while(a > 0) {
        ca[a%10]++;
        a /= 10;
    }

    while(b > 0) {
        cb[b%10]++;
        b /= 10;
    }

    return ca == cb;
}

int main() {
    ld ans = 2;

    cout << fixed;
    cout.precision(20);

    for(ll i = 10000000 - 1; i > 1; i--) {
        ll t = phi(i);
        if(perm(i, t)) {
            ld next = ld(i) / ld(t);
            if(next < ans) {
                ans = next;
                cout << i << " " << ans << endl;
            }
        }
    }

}
