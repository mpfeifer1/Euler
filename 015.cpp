#include <iostream>

using namespace std;

void permute(string s, int i, int n);

int main() {
    int height = 2;
    int length = 2;
    string path = "";

    for(int i = 0; i < length; i++) {
        path += "R";
    }
    for(int i = 0; i < height; i++) {
        path += "D";
    }

    permute(path, 0, path.length() - 1);
}

void permute(string s, int l, int r) {
    int i;
    if(l ==r) {
        cout << s << endl;
    } else {
        for(i = l; i < s.length(); i++) {
            swap(s[l], s[i]);
            permute(s, l+1, r);
            swap(s[l], s[i]);
        }
    }
}
