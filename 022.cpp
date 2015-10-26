#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

void sort(char arr[][30], int left, int right);
void swap(char arr[][30], int index1, int index2);
void copy(char destination[30], char source[30]);
int calculate(char arr[][30]);

int main() {
    ifstream file("sources/022.txt");
    char names[6000][30] = {'\0'}; // Array of names
    char temp[31];

    for(int i = 0; i < 6000; i++) {
        file.getline(temp, 31, '"'); // Gets rid of comma
        file.getline(names[i], 31, '"');
    }

    sort(names, 0, 6000 - 1);

    for(int i = 0; i < 6000; i++) {
        if(names[i][0]) {
            cout << names[i] << " ";
        }
    }

    cout << endl;
    cout << "Total score is " << calculate(names) << endl;
}

void sort(char arr[][30], int left, int right) {
    int i = left, j = right;
    char tmp[30];
    char pivot[30] = {'\0'};
    copy(pivot, arr[(left + right) / 2]);

    while(i <= j) {
        while(strcmp(arr[i], pivot) < 0) {
            i++;
        }
        while(strcmp(arr[j], pivot) > 0) {
            j--;
        }
        if(i <= j) {
            copy(tmp, arr[i]);
            copy(arr[i], arr[j]);
            copy(arr[j], tmp);
            i++;
            j--;
        }
    }

    if(left < j) {
        sort(arr, left, j);
    }
    if(i < right) {
        sort(arr, i, right);
    }
}

void swap(char arr[][30], int index1, int index2) {
    char name1[30] = {'\0'};
    char name2[30] = {'\0'};

    copy(name1, arr[index1]);
    copy(name2, arr[index2]);

    copy(arr[index2], name1);
    copy(arr[index1], name2);
}

void copy(char destination[30], char source[30]) {
    for(int i = 0; i < 30; i++) {
        destination[i] = source[i];
    }
}

int calculate(char arr[][30]) {
    int sum = 0;
    for(int i = 0; i < 6000; i++) {
        int j = 6000 - 1;
        int product = 0;
        while(arr[i][j]) {
            product += arr[i][j];
            j--;
        }
        product *= i;
        sum += product;
    }
}
