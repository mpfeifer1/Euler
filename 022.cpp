#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("sources/042.txt");
    string names[5000]; // Array of names
    string nameList; // String of names (copy of text file)
    getline(file, nameList); // copies names to namelist

    int index = 0;
    int lengthToQuote = 0;
    string currentWord = "";

    while(index < nameList.length()) {
        while(nameList[index] != '"') {
            index++;
        }
        lengthToQuote = 1;
        while(nameList[index + lengthToQuote] != '"') {
            lengthToQuote++;
        }

        currentWord = nameList.substr(index, lengthToQuote);
        cout << currentWord << endl;

        index += currentWord.length() + 1;
    }
}
