#include <iostream>
#include <string>

using namespace std;

bool permutate(string &s);
bool divisible02(string s);
bool divisible03(string s);
bool divisible05(string s);
bool divisible07(string s);
bool divisible11(string s);
bool divisible13(string s);
bool divisible17(string s);

int main() {
    string i = "0123456789";
    int sum = 0;
    do {
        // Check that substrings are divisible
        bool divisible = true;
        divisible &= divisible02(i);
        divisible &= divisible03(i);
        divisible &= divisible05(i);
        divisible &= divisible07(i);
        divisible &= divisible11(i);
        divisible &= divisible13(i);
        divisible &= divisible17(i);

        if(divisible) {
            cout << i << endl;
            sum += stoi(i);
        }

        cout << i << endl;

    } while(permutate(i));

    cout << "The answer is: " << sum << endl;

    return 0;
}

// Return next permutation of s
bool permutate(string &s) {
    // Calculate highest index j such that s[j] < s[j+1]
    int i = 9;
    while(i > 0 && s.at(i-1) >= s.at(i)) {
        i--;
    }
    cout << "1";
    // Quit if last permutation
    if(i == 0) {
        return false;
    }
    cout << "2";
    // Calculate highest index k such that s[k] > s[j]
    int j = 8;
    while(s.at(j) <= s.at(i-1)) {
        j--;
        cout << "Decremented\n";
    }
    cout << "3";
    // Swap first two numbers
    swap(s.at(i), s.at(j));
    cout << "4";
    // Swap the rest down the line
    j = 8;
    while(i < j) {
        swap(s.at(i), s.at(j));
        i++;
        j--;
    }

    return true;
}

bool divisible02(string s) {
    s = s.substr(1,3);
    int i = stoi(s);
    return i % 2 == 0;
}

bool divisible03(string s) {
    s = s.substr(2,3);
    int i = stoi(s);
    return i % 3 == 0;
}

bool divisible05(string s) {
    s = s.substr(3,3);
    int i = stoi(s);
    return i % 5 == 0;
}

bool divisible07(string s) {
    s = s.substr(4,3);
    int i = stoi(s);
    return i % 7 == 0;
}

bool divisible11(string s) {
    s = s.substr(5,3);
    int i = stoi(s);
    return i % 11 == 0;
}

bool divisible13(string s) {
    s = s.substr(6,3);
    int i = stoi(s);
    return i % 13 == 0;
}

bool divisible17(string s) {
    s = s.substr(7,3);
    int i = stoi(s);
    return i % 17 == 0;
}
