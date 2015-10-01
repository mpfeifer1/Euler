#include <iostream>

using namespace std;

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

    // Calculate all unique permutations, like (RRDD), (RDRD)
}
