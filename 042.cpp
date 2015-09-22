#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool isTriangle(string word);
int charToInt(char c);

int main() {
    // Saves text file to a string
    ifstream file("sources/042.txt");
    string wordList;
    getline(file, wordList);

    int index = 0; // Current spot in the string

    // cout << word << endl; // Prints entire text file
}

bool isTriangle(string word) {
    cout << "Processing word " << word << endl;
    wordValue = 0;
    for(int i = 0; i < length; i++) {
        wordValue += charToInt((char)word.substr(i,1));
    }

    int n = 1;
    int currentTriangle = 1;
    while(currentTriangle <= wordValue) {
        currentTriangle = (1.0 / 2.0) * (n + 1);
        cout << "Current triangle is " << currentTriangle << endl;
        n++;
        if(currentTriangle == wordValue) {
            return true;
        }
    }
    return false;
}

int charToInt(char c) {
    switch(c) {
        case a:
            return 1;
        case b:
            return 2;
        case c:
            return 3;
        case d:
            return 4;
        case e:
            return 5;
        case f:
            return 6;
        case g:
            return 7;
        case h:
            return 8;
        case i:
            return 9;
        case j:
            return 10;
        case k:
            return 11;
        case l:
            return 12;
        case m:
            return 13;
        case n:
            return 14;
        case o:
            return 15;
        case p:
            return 16;
        case q:
            return 17;
        case r:
            return 18;
        case s:
            return 19;
        case t:
            return 20;
        case u:
            return 21;
        case v:
            return 22;
        case w:
            return 23;
        case x:
            return 24;
        case y:
            return 25;
        case z:
            return 26;
        default:
            return -1; // Just in case of error
    }
}
