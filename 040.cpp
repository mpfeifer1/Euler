


#include <iostream>
#include <string>

using namespace std;

int main() {
    string champernowne = "";
    int total = 1;

    for(int i = 0; champernowne.length() <= 1000000; i++) {
        champernowne += to_string(i);
    }

    for(int i = 1; i <= 1000000; i *= 10) {
        total *= (int)champernowne[i];
        cout << "Cham: " << (int)champernowne[i] << endl;
        cout << "Prod: " << total << endl;
    }

    cout << total << endl;
}
