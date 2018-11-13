#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void decrypt(string v, vector<int> arr) {
    for(int i = 0; i < v.size(); i++) {
        v[i] ^= arr[i%3];
    }

    if( v.find("the") != string::npos &&
        v.find("if") != string::npos &&
        v.find("human") != string::npos &&
        v.find("}") == string::npos) {

        int sum = 0;
        for(auto i : v) {
            sum += i;
        }
        cout << v << endl;
        cout << sum << endl;
    }
}

int main() {
    string v;

    int i;
    while(cin >> i) {
        v.push_back(i);
        cin.ignore();
    }

    for(int i = 'a'; i <= 'z'; i++) {
        for(int j = 'a'; j <= 'z'; j++) {
            for(int k = 'a'; k <= 'z'; k++) {
                decrypt(v,{i,j,k});
            }
        }
    }
}
