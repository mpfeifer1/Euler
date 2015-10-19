#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int toAscii(char c);

int main() {
    ifstream file("sources/059.txt");
    string message;
    getline(file, message);
}

int xor(char data, char cipher) {
    return toAscii(data) ^ toAscii(cipher);
}

int toAscii(char c) {
    return (int)c;
}
