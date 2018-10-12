#include <bits/stdc++.h>

using namespace std;
typedef long double ld;
int targettop = 3;
int targetbot = 7;
ld target = (ld)targettop / targetbot;

int findtop(int n) {
    int top = floor(target * n);
    while(__gcd(top,n) != 1 && top > 0) {
        top--;
    }
    if(__gcd(top,n) == 1) {
        return top;
    }
    return 0;
}

bool cmp(pair<int,int>& p1, pair<int,int>& p2) {
    ld top = ld(p1.first) / p1.second;
    ld bot = ld(p2.first) / p2.second;
    return top < bot;
}

int main() {
    vector<pair<int,int>> p;
    int top;
    cout << "Pass in the max denominator: ";
    cin >> top;
    for(int i = 2; i <= top; i++) {
        if(i == targetbot) continue;
        int t = findtop(i);
        p.push_back({t,i});
    }
    sort(p.begin(), p.end(), cmp);

    cout << p.back().first << " ";
    cout << p.back().second << endl;
}
