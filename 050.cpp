#include <bits/stdc++.h>

using namespace std;

int MAX = 1000000;

void sieve(vector<bool>& isprime, vector<int>& primes) {
    isprime[0] = false;
    isprime[1] = false;
    for(int i = 2; i <= sqrt(MAX); i++) {
        if(isprime[i]) {
            for(int j = i*2; j <= MAX; j+=i) {
                isprime[j] = false;
            }
        }
    }

    for(int i = 0; i <= MAX; i++) {
        if(isprime[i]) {
            primes.push_back(i);
        }
    }
}

int main() {
    vector<bool> isprime(MAX+1, true);
    vector<int> primes;
    sieve(isprime, primes);

    int bestlen = 0;
    int bestval = 0;
    for(int i = 0; i < primes.size(); i++) {
        int total = 0;
        for(int j = i; j < primes.size(); j++) {
            total += primes[j];

            if(total >= MAX) {
                break;
            }

            if(isprime[total] && j-i > bestlen) {
                bestlen = j-i;
                bestval = total;
            }
        }
    }

    cout << bestval << endl;
}

