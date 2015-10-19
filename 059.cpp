#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int xor(char data, char cipher);
int toAscii(char c);

int main() {
    // Import from file
    ifstream file("sources/059.txt");
    string message;
    getline(file, message);

    // Parse file to array
    vector<int> characters();
    int index = 0;
    while(still stuff in message) {
        get stuff until ,
        move forward index
    }

    // Find encryption key

    // Decrypt file

    // (Temporary) Output message

    // Sum ASCII characters
}

int xor(char data, char cipher) {
    return toAscii(data) ^ toAscii(cipher);
}

int toAscii(char c) {
    return (int)c;
}
