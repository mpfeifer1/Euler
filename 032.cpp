#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

map<ll,ll> seen(ll n) {
    map<ll,ll> m;
    while(n > 0) {
        m[n%10]++;
        n /= 10;
    }
    return m;
}

bool works(ll a, ll b, ll c) {
    map<ll,ll> m1, m2, m3;
    m1 = seen(a);
    m2 = seen(b);
    m3 = seen(c);

    for(int i = 0; i < 10; i++) {
        int t = m1[i] + m2[i] + m3[i];
        if(i == 0) {
            if(t > 0) {
                return false;
            }
        }
        else {
            if(t != 1) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    set<int> s;
    for(ll i = 0; i < 10000; i++) {
        for(ll j = i+1; j < 10000; j++) {
            if(works(i,j,i*j)) {
                s.insert(i*j);
            }
        }
    }

    int total = 0;
    for(auto i : s) {
        total += i;
    }
    cout << total << endl;
}
