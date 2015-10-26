#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void sort(char arr[][30]);

int main() {
    ifstream file("sources/022.txt");
    char names[6000][30] = {'\0'}; // Array of names
    char temp[31];

    for(int i = 0; i < 6000; i++) {
        file.getline(temp, 31, '"'); // Gets rid of comma
        file.getline(names[i], 31, '"');
    }

    //sort(names);

    for(int i = 0; i < 6000; i++) {
        cout << names[i] << " ";
    }

    cout << endl;
}

void sort(char arr[][30]) {
    /*
    while(!isSorted(arr)) {
        int index = 0;
        cout << "Item being sorted: " << arr[index] << endl;
        if(arr[index] > arr[index + 1]) {
            swap(arr[index], arr[index+1]);
        }
        index++;
    }
    */
}
