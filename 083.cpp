#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll S = 80;
ll inf = (ll)1 << 60;

void bfs(vector<vector<ll>>& v, vector<vector<ll>>& vis, int i) {
    queue<pair<int,int>> q;
    vis[i][0] = v[i][0];
    q.push({i,0});

    while(!q.empty()) {
        ll x = q.front().first;
        ll y = q.front().second;
        q.pop();

        // Go down
        if(x+1 < S) {
            if(vis[x+1][y] > vis[x][y] + v[x+1][y]) {
                vis[x+1][y] = vis[x][y] + v[x+1][y];
                q.push({x+1,y});
            }
        }

        // Go up
        if(x-1 >= 0) {
            if(vis[x-1][y] > vis[x][y] + v[x-1][y]) {
                vis[x-1][y] = vis[x][y] + v[x-1][y];
                q.push({x-1,y});
            }
        }

        // Go right
        if(y-1 >= 0) {
            if(vis[x][y-1] > vis[x][y] + v[x][y-1]) {
                vis[x][y-1] = vis[x][y] + v[x][y-1];
                q.push({x,y-1});
            }
        }

        // Go right
        if(y+1 < S) {
            if(vis[x][y+1] > vis[x][y] + v[x][y+1]) {
                vis[x][y+1] = vis[x][y] + v[x][y+1];
                q.push({x,y+1});
            }
        }
    }
}

int main() {
    vector<vector<ll>> v;
    v.resize(S, vector<ll>(S));
    freopen("sources/083.txt", "r", stdin);
    //freopen("thing.thing", "r", stdin);

    for(ll i = 0; i < S; i++) {
        for(ll j = 0; j < S; j++) {
            cin >> v[i][j];
            cin.ignore();
        }
    }

    // Check that input was read in correctly
    /*
    for(ll i = 0; i < S; i++) {
        for(ll j = 0; j < S; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    */

    // Set up visited
    vector<vector<ll>> vis;
    vis.resize(S, vector<ll>(S, inf));

    bfs(v, vis, 0);

    // Check that output is correct
    /*
    for(ll i = 0; i < S; i++) {
        for(ll j = 0; j < S; j++) {
            cout << vis[i][j] << " ";
        }
        cout << endl;
    }
    */

    cout << vis[S-1][S-1] << endl;
}
