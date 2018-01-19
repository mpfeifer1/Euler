// Michael Pfeifer
// Version 02, 2018/01/17

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ld  pi   = 4.0*atanl(1.0);
const int iinf = 1e9 + 10;
const ll  inf  = 1e18 + 10;
const int mod  = 1000000007;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map;
#define uset unordered_set;

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("sources/107.txt",  "r", stdin);
    if(!a) cout << "uh oh" << endl;
}

ll readint(){
    char r;
    bool start=false,neg=false;
    ll ret=0;
    while(true){
        r=getchar();
        if((r-'0'<0 || r-'0'>9) && r!='-' && !start){
            continue;
        }
        if((r-'0'<0 || r-'0'>9) && r!='-' && start){
            break;
        }
        if(start)ret*=10;
        start=true;
        if(r=='-')neg=true;
        else ret+=r-'0';
    }
    if(!neg) return ret;
    else return -ret;
}





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

struct edge {
    int n1, n2, w;
};

bool cmp(edge e1, edge e2) {
    return e1.w < e2.w;
}

int N = 40;

int main() {
    file();
    //fast();

    vector<edge> v;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(cin.peek() == '-') {
                cin.ignore();
                cin.ignore();
                continue;
            }

            int w;
            cin >> w;

            if(i >= j) {
                v.push_back({i,j,w});
            }
            cin.ignore();
        }
    }

    sort(v.begin(), v.end(), cmp);

    int saved = 0;
    vector<int> d(N, -1);
    for(auto i : v) {
        if(find(d, i.n1) != find(d, i.n2)) {
            join(d, i.n1, i.n2);
        }
        else {
            saved += i.w;
        }
    }

    cout << saved << endl;
}
