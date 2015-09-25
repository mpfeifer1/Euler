#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool isSorted(vector<string> arr);
vector<string> sort(vector<string> arr);

int main() {
    ifstream file("sources/042.txt");
    vector<string> names(5000); // Array of names
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

        currentWord = nameList.substr(index + 1, lengthToQuote - 1);
        index += currentWord.length() + 2;
    }

    sort(names);

    for(int i = 0; i < 5000; i++) {
        cout << names[i] << endl;
    }
}

bool isSorted(vector<string> arr) {
    return false;
}

vector<string> sort(vector<string> arr) {
    while(!isSorted(arr)) {
        int index = 0;
        cout << "Item being sorted: " << arr[index] << endl;
        if(arr[index] > arr[index + 1]) {
            swap(arr[index], arr[index+1]);
        }
        index++;
    }
    return arr;
}
