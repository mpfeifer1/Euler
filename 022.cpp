#include <iostream>
#include <fstream>

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

    //for(int i = 0; i < 6000; i++) {
    //    cout << names[i] << " ";
    //}

    cout << endl;
}

void sort(char arr[][30], int left, int right) {
    
}

void swap(char arr[][30], int index1, int index2) {
    char name1[31] = arr[index1];
    char name2[31] = arr[index2];

    arr[index2] = name1;
    arr[index1] = name2;
}
