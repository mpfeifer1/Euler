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

int HANDS = 1000;
void file() {
    auto a = freopen("sources/054.txt",  "r", stdin);
    //auto a = freopen("temp.txt",  "r", stdin);
    if(!a) cout << "uh oh" << endl;
}





struct card {
    int val;
    char suit;
};

card getcard(string s) {
    card c;
    c.suit = s[1];
    c.val = s[0] - '0';
    c.val++;

    if(s[0] == 'A') {
        c.val = 15;
    }
    if(s[0] == 'K') {
        c.val = 14;
    }
    if(s[0] == 'Q') {
        c.val = 13;
    }
    if(s[0] == 'J') {
        c.val = 12;
    }
    if(s[0] == 'T') {
        c.val = 11;
    }
    return c;
}

bool cmp1(card& c1, card& c2) {
    if(c1.val == c2.val) {
        return c1.suit < c2.suit;
    }
    return c1.val < c2.val;
}

int royalflush(vector<card> hand) {
    bool works = true;
    sort(all(hand), cmp1);
    for(int i = 0; i <= 3; i++) {
        if(hand[i].suit != hand[i+1].suit) {
            works = false;
        }
        if(hand[i].val+1 != hand[i+1].val) {
            works = false;
        }
    }
    if(hand[4].val != 15) {
        works = false;
    }

    if(works) {
        return 1;
    }
    return 0;
}

int straightflush(vector<card> hand) {
    bool works = true;
    sort(all(hand), cmp1);
    for(int i = 0; i <= 3; i++) {
        if(hand[i].suit != hand[i+1].suit) {
            works = false;
        }
        if(hand[i].val+1 != hand[i+1].val) {
            works = false;
        }
    }

    if(works) {
        return 1;
    }
    return 0;
}

int fourofakind(vector<card> hand) {
    map<int,int> c;
    for(auto i : hand) {
        c[i.val]++;
    }
    for(auto i : c) {
        if(i.second == 4) {
            return i.first;
        }
    }
    return 0;
}

int fullhouse(vector<card> hand) {
    map<int,int> c;
    for(auto i : hand) {
        c[i.val]++;
    }
    int two = 0;
    int three = 0;
    for(auto i : c) {
        if(i.second == 2) {
            two = i.first;
        }
        if(i.second == 3) {
            three = i.first;
        }
    }
    if(two && three) {
        return three*100+two;
    }
    return 0;
}

int flush(vector<card> hand) {
    set<char> seen;
    for(auto i : hand) {
        seen.insert(i.suit);
    }

    if(seen.size() == 1) {
        return 1;
    }
    return 0;
}

int straight(vector<card> hand) {
    bool works = true;
    sort(all(hand), cmp1);
    for(int i = 0; i <= 3; i++) {
        if(hand[i].val+1 != hand[i+1].val) {
            works = false;
        }
    }

    if(works) {
        return 1;
    }
    return 0;
}

int threeofakind(vector<card> hand) {
    map<int,int> c;
    for(auto i : hand) {
        c[i.val]++;
    }
    for(auto i : c) {
        if(i.second == 3) {
            return i.first;
        }
    }
    return 0;
}

int twopairs(vector<card> hand) {
    map<int,int> c;
    for(auto i : hand) {
        c[i.val]++;
    }

    int pair1 = 0;
    int pair2 = 0;

    for(auto i : c) {
        if(i.second == 2) {
            if(pair1 == 0) {
                pair1 = i.first;
            }
            else {
                pair2 = i.first;
            }
        }
    }

    if(pair2 == 0) {
        return 0;
    }

    if(pair1 > pair2) {
        swap(pair1,pair2);
    }

    return pair2*100+pair1;
}

int onepair(vector<card> hand) {
    map<int,int> c;
    for(auto i : hand) {
        c[i.val]++;
    }

    int best = 0;
    for(auto i : c) {
        if(i.second == 2) {
            best = max(best, i.first);
        }
    }

    return best;
}

int highcard(vector<card> hand1, vector<card> hand2) {
    // Returns true if hand1 wins
    sort(all(hand1), cmp1);
    sort(all(hand2), cmp1);
    reverse(all(hand1));
    reverse(all(hand2));

    for(int i = 0; i < 5; i++) {
        if(hand1[i].val > hand2[i].val) {
            return 1;
        }
        if(hand1[i].val < hand2[i].val) {
            return 0;
        }
    }

    return 1;
}

int main() {
    file();
    //fast();

    int wins1 = 0;
    int wins2 = 0;

    for(int i = 0; i < HANDS; i++) {
        vector<card> hand1(5);
        vector<card> hand2(5);

        for(auto&i : hand1) {
            string s;
            cin >> s;
            i = getcard(s);
        }
        for(auto&i : hand2) {
            string s;
            cin >> s;
            i = getcard(s);
        }

        vector<int> val1(10,false);
        vector<int> val2(10,false);

        val1[0] = royalflush(hand1);
        val1[1] = straightflush(hand1);
        val1[2] = fourofakind(hand1);
        val1[3] = fullhouse(hand1);
        val1[4] = flush(hand1);
        val1[5] = straight(hand1);
        val1[6] = threeofakind(hand1);
        val1[7] = twopairs(hand1);
        val1[8] = onepair(hand1);

        val2[0] = royalflush(hand2);
        val2[1] = straightflush(hand2);
        val2[2] = fourofakind(hand2);
        val2[3] = fullhouse(hand2);
        val2[4] = flush(hand2);
        val2[5] = straight(hand2);
        val2[6] = threeofakind(hand2);
        val2[7] = twopairs(hand2);
        val2[8] = onepair(hand2);

        bool added = false;
        for(int i = 0; i < 9; i++) {
            if(val1[i] == val2[i] && val1[i] > 0) {
                break;
            }
            if(val1[i] == val2[i] && val1[i] == 0) {
                continue;
            }

            added = true;
            if(val1[i] > val2[i]) {
                wins1++;
            }
            if(val1[i] < val2[i]) {
                wins2++;
            }

            break;
        }

        if(!added) {
            if(highcard(hand1,hand2)) {
                wins1++;
            }
            else {
                wins2++;
            }
        }


    }
    cout << wins1 << " " << wins2 << endl;

    return 0;
}
