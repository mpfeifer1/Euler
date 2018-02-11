#include <bits/stdc++.h>

using namespace std;

int MAX = 1000000;

int phi(int n) {
    int result = n;
    for(int i = 2; i*i < n; i++) {
        if(n % i == 0) {
            while(n % i  == 0) {
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

int main() {
    double bestrat = 0;
    int best = 0;
    for(int i = 1; i <= MAX; i++) {
        int tot = phi(i);
        double rat = (double)i / tot;
        if(rat > bestrat) {
            bestrat = rat;
            best = i;
        }
    }

    cout << best << endl;
}
