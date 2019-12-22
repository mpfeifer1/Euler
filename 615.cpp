#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef map<ll,ll> bigint;

const ll sz = 1e5;
const ll target = 1e6;
const ll mod = 123454321;

vector<ll> primes;
bool isprime(ll n) {
    for(ll i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) return false;
    }
    return true;
}
void buildprimes() {
    ll curr = 2;
    while(primes.size() < sz) {
        if(isprime(curr)) primes.push_back(curr);
        curr++;
    }
}

void print(bigint b) {
    ll ans = 1;

    for(auto i : b) {
        cout << primes[i.first] << ": " << i.second << endl;
        for(ll j = 0; j < i.second; j++) {
            ans *= primes[i.first];
            ans %= mod;
        }
    }

    cout << ans << endl;
    cout << endl;
}


struct cmp {
    bool operator()(const bigint& b1, const bigint& b2) const {
        // TODO: maybe instead compare the log2 of these numbers instead of the diff
        set<ll> all;
        for(auto i : b1) all.insert(i.first);
        for(auto i : b2) all.insert(i.first);

        ld diff = 1;
        for(auto i : all) {
            ld lhs = b1.count(i) ? b1.at(i) : 0;
            ld rhs = b2.count(i) ? b2.at(i) : 0;
            diff *= pow(ld(primes[i]), lhs-rhs);
        }
        return diff > 1;
    }
};

vector<bigint> getnexts(bigint b) {
    vector<bigint> v;

    set<ll> factors;
    for(auto i : b) factors.insert(i.first);

    // Swap factors
    for(auto idx : factors) {
        b[idx]--;
        if(b[idx] == 0) b.erase(idx);
        b[idx+1]++;

        v.push_back(b);

        b[idx+1]--;
        if(b[idx+1] == 0) b.erase(idx+1);
        b[idx]++;
    }

    // Add factor
    b[0]++;
    v.push_back(b);

    // Return list
    return v;
}

int main() {
    buildprimes();
    for(auto i : primes) {
        cout << i << " ";
    }
    cout << endl;

    bigint num;
    num[0] = target;

    priority_queue<bigint, vector<bigint>, cmp> q;
    q.push(num);
    ll ct = 0;

    set<bigint> seen;

    while(q.size() > 0) {
        bigint curr = q.top();
        q.pop();

        if(seen.count(curr)) continue;
        seen.insert(curr);

        ct++;

        // Check to see if we need a bigger prime
        if(curr.count(sz-1) > 0) {
            cout << "Need a bigger prime" << endl;
            for(auto j : curr) {
                cout << primes[j.first] << ": " << j.second << endl;
            }
            cout << endl;
            return 0;
        }

        // Print temporary answers
        if(ct % 10000 == 1) {
            cout << ct << ": ";
            print(curr);
        }

        // Print answer
        if(ct == target) {
            cout << ct << ": ";
            print(curr);
            break;
        }

        // Add new states to queue
        vector<bigint> nexts = getnexts(curr);
        for(auto i : nexts) {
            q.push(i);
        }
    }
}
