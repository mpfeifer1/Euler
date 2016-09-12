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
    int j = -1;
    for(int i = 9; i > 0; i--) {
        if(s.at(i) < s.at(i+1)) {
            j = i;
        }
    }

    // Quit if last permutation
    if(j == -1) {
        return false;
    }

    // Calculate highest index k such that s[k] > s[j]
    int k = -1;
    for(int i = j + 1; i < 10; i++) {
        if(s.at(i) > s.at(j)) {
            k = i;
        }
    }

    // Swap first two numbers
    swap(s.at(j), s.at(k));

    // Swap the rest down the line
    for(int i = j+1; i < 9; i++) {
        swap(s.at(i), s.at(i+1));
    }

    return true;
}

bool divisible02(string s) {
    s = s.substr(1,3);
    int i = stoi(s);
    //cout << s << endl;
    //cout << ((i % 2) == 0) << endl;
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
