#include <bits/stdc++.h>

using namespace std;

int find(vector<int>& d, int a) {
    if(d[a] == -1) {
        return a;
    }
    return d[a] = find(d, d[a]);
}

void join(vector<int>& d, int a, int b) {
    a = find(d, a);
    b = find(d, b);

    if(a == b) {
        return;
    }

    d[a] = b;
}

int next(int a) {
    int t = 0;
    while(a > 0) {
        int n = a % 10;
        t += n*n;
        a /= 10;
    }
    return t;
}

int main() {
    vector<int> d(10000001, -1);
    int total = 0;
    for(int i = 1; i < 10000000; i++) {
        join(d, i, next(i));
    }
    for(int i = 1; i < 10000000; i++) {
        if(find(d, i) == find(d, 89)) {
            total++;
        }
    }
    cout << total << endl;
}
