#include <bits/stdc++.h>

using namespace std;

int build(vector<int>& perm) {
    int ans = 0;
    for(auto& i : perm) {
        ans *= 10;
        ans += i;
    }
    return ans;
}

bool works(vector<int>& v) {
    // split into 2
    // 4,5
    vector<int> v1(v.begin()+0,v.begin()+4);
    vector<int> v2(v.begin()+4,v.begin()+9);
    int i1 = build(v1);
    int i2 = build(v2);

    if(i1 / 1 == i2 / 2) {
        return true;
    }

    // split into 3
    // 3,3,3

    // split into 4
    // 2,2,2,3

    // split into 5
    // 1,2,2,2,2

    // split into 6
    // 1,1,1,2,2,2

    // split into 7
    // 1,1,1,1,1,2,2

    // split into 8
    // 1,1,1,1,1,1,1,2

    // split into 9
    // 1,1,1,1,1,1,1,1,1

    return false;
}

int main() {
    vector<int> perm = {9,8,7,6,5,4,3,2,1};

    do {
        int actual = build(perm);
        if(works(perm)) {
            cout << actual << endl;
            break;
        }
    } while(prev_permutation(perm.begin(), perm.end()));
}
