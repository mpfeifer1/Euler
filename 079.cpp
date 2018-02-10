#include <bits/stdc++.h>

using namespace std;

int main() {
    vector<set<int>> adj(10);
    freopen("sources/079.txt", "r", stdin);

    set<int> all;

    vector<int> deg(10,0);
    string s;
    while(cin >> s) {
        int a, b, c;
        a = s[0] - '0';
        b = s[1] - '0';
        c = s[2] - '0';

        all.insert(a);
        all.insert(b);
        all.insert(c);

        if(adj[a].count(b) == 0) {
            adj[a].insert(b);
            deg[b]++;
        }
        if(adj[b].count(c) == 0) {
            adj[b].insert(c);
            deg[c]++;
        }
    }

    queue<int> zeroin;
    for(auto i : all) {
        if(deg[i] == 0) {
            zeroin.push(i);
        }
    }

    string ans;
    while(!zeroin.empty()) {
        int curr = zeroin.front();
        zeroin.pop();
        ans.push_back(curr + '0');

        for(auto i : adj[curr]) {
            deg[i]--;
            if(deg[i] == 0) {
                zeroin.push(i);
            }
        }
    }

    for(int i = 0; i < adj.size(); i++) {
        cout << i << ": ";
        for(auto j : adj[i]) {
            cout << j << " ";
        }
        cout << endl;
    }

    cout << ans << endl;
}
