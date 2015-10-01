#include <iostream>
#include <strings.h>
#include <algorithm>
#include <string>

using namespace std;

void permute(int k, string &s);

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

    permute(3, path);
}

void permute(int k, string &s) {
    for(int i = 1; i < s.size(); i++) {
        swap(s[k % (i + 1)], s[i]);
        k = k / (i + 1);
        cout << s << endl;
    }
}
