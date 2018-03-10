// Michael Pfeifer
// Version 04, 2018/02/17

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
const ld  prec = .000001;

#define enld endl
#define endl '\n'
#define pb push_back
#define debug(x) cout<<#x<<" -> "<<x<<'\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define uni(x) (x).erase(unique(all(x)), (x).end())
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep1(i, n) for (ll i = 1; i <= (ll)(n); ++i)
#define umap unordered_map
#define uset unordered_set

template<class TIn>
using indexed_set = tree<
        TIn, null_type, less<TIn>,
        rb_tree_tag, tree_order_statistics_node_update>;

void fast() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

void file() {
    auto a = freopen("a.in",  "r", stdin);
    auto b = freopen("a.out", "w", stdout);
    if(!a || !b) cout << "uh oh" << endl;
}





bool valid(int n) {
    return n%10 != 0;
}

int reverse(int n) {
    int ans = 0;
    while(n > 0) {
        ans *= 10;
        ans += n%10;
        n /= 10;
    }
    return ans;
}

bool odd(int n) {
    bool works = true;
    while(n > 0) {
        int val = n%10;
        if(val%2==0) {
            return false;
        }
        n /= 10;
    }
    return works;
}

int main() {
    //file();
    //fast();

    uset<int> s;

    for(int i = 1; i < 500000000; i++) {
        int rev = reverse(i);
        if(valid(i) && valid(rev) && odd(i+rev)) {
            s.insert(i);
            s.insert(rev);
        }
    }

    cout << s.size() << endl;

    return 0;
}
