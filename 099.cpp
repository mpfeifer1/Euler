#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef long double ld;

struct num {
    ld first, second;
    int pos;
};

bool cmp(num& p1, num& p2) {
    ld l = log10((ld)p1.first) * p1.second;
    ld r = log10((ld)p2.first) * p2.second;
    return l < r;
}

int main() {
    freopen("sources/099.txt", "r", stdin);

    vector<num> v(1000);
    int idx = 1;
    for(auto& i : v) {
        cin >> i.first;
        cin.ignore();
        cin >> i.second;
        i.pos = idx;
        idx++;
    }

    sort(v.begin(), v.end(), cmp);

    for(auto& i : v) {
        cout << i.first << " " << i.second << " " << i.pos << endl;
    }
}
