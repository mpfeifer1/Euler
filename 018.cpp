#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int S = 15;

int maxPath(vector<vector<int>> n, int row, int col) {
    if(row == S) {
        return 0;
    }

    int l = maxPath(n, row+1, col);
    int r = maxPath(n, row+1, col+1);

    if(l > r) {
        return l + n[row][col];
    }

    return r + n[row][col];
}

int main() {
    ifstream fin;
    fin.open("sources/018.txt");

    vector<vector<int>> n;
    n.resize(S);

    for(int i = 0; i < S; i++) {
        for(int j = 0; j < i + 1; j++) {
            int temp;
            fin >> temp;
            n[i].push_back(temp);
        }
    }

    cout << maxPath(n, 0, 0) << endl;
}
