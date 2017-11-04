#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int S = 80;

int main() {
    vector<vector<ll>> v;

    v.resize(S, vector<ll>(S));

    for(int i = 0; i < S; i++) {
        for(int j = 0; j < S; j++) {
            cin >> v[i][j];
        }
    }

    for(int i = S-2; i >= 0; i--) {
        v[i][S-1] += v[i+1][S-1];
        v[S-1][i] += v[S-1][i+1];
    }

    for(int i = S-2; i >= 0; i--) {
        for(int j = S-2; j >= 0; j--) {
            v[j][i] += min(v[j+1][i], v[j][i+1]);
        }
    }

    cout << v[0][0] << endl;
}
