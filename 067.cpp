#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int S = 100;

int main() {
    ifstream fin;
    fin.open("sources/067.txt");

    vector<vector<int>> n;
    n.resize(S);

    for(int i = 0; i < S; i++) {
        for(int j = 0; j < i + 1; j++) {
            int temp;
            fin >> temp;
            n[i].push_back(temp);
        }
    }

    for(int i = S-2; i >= 0; i--) {
        for(int j = 0; j < i+1; j++) {
            int a = n[i+1][j];
            int b = n[i+1][j+1];
            a = max(a,b);
            n[i][j] += a;
        }
    }

    cout << n[0][0] << endl;
}
