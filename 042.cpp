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
    int lengthToQuote = 0; // Distance until next (")
    int triangleWords = 0;
    string currentWord = "";

    while(index < wordList.length()) {
        while(wordList[index] != '"' ) { // Loops until next (")
            index++;
        }
        lengthToQuote = 1;
        while(wordList[index + lengthToQuote] != '"') { // Finds the following (")
            lengthToQuote++;
        }

        currentWord = wordList.substr(index, lengthToQuote); // Creates a word to process

        if(isTriangle(currentWord)) { // Checks if triangle
            triangleWords++;
        }

        index += currentWord.length() + 1; // Moves index forward length of word (+2 to account for the ,")
    }

    cout << "File has " << triangleWords << " triangle words" << endl;
}

bool isTriangle(string word) {
    int wordValue = 0;
    for(int i = 0; i < word.length(); i++) {
        char temp = word[i];
        wordValue += charToInt(temp);
    }

    int n = 1;
    int currentTriangle = 1;
    while(currentTriangle <= wordValue) {
        currentTriangle = (1.0 / 2.0) * n * (n + 1);
        n++;
        if(currentTriangle == wordValue) {
            return true;
        }
    }
    return false;
}

int charToInt(char c) {
    switch(c) {
        case 'A':
        case 'a':
            return 1;
        case 'B':
        case 'b':
            return 2;
        case 'C':
        case 'c':
            return 3;
        case 'D':
        case 'd':
            return 4;
        case 'E':
        case 'e':
            return 5;
        case 'F':
        case 'f':
            return 6;
        case 'G':
        case 'g':
            return 7;
        case 'H':
        case 'h':
            return 8;
        case 'I':
        case 'i':
            return 9;
        case 'J':
        case 'j':
            return 10;
        case 'K':
        case 'k':
            return 11;
        case 'L':
        case 'l':
            return 12;
        case 'M':
        case 'm':
            return 13;
        case 'N':
        case 'n':
            return 14;
        case 'O':
        case 'o':
            return 15;
        case 'P':
        case 'p':
            return 16;
        case 'Q':
        case 'q':
            return 17;
        case 'R':
        case 'r':
            return 18;
        case 'S':
        case 's':
            return 19;
        case 'T':
        case 't':
            return 20;
        case 'U':
        case 'u':
            return 21;
        case 'V':
        case 'v':
            return 22;
        case 'W':
        case 'w':
            return 23;
        case 'X':
        case 'x':
            return 24;
        case 'Y':
        case 'y':
            return 25;
        case 'Z':
        case 'z':
            return 26;
        default:
            return 0; // Just in case of error
    }
}
