#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("sources/013.txt");
    string numbers[100];
    long int sum = 0;

    for(int i = 0; i < 100; i++) {
        getline(file, numbers[i]);
        numbers[i] = numbers[i].substr(0,11);
        sum += stod(numbers[i].c_str());
    }

    while(sum > 10000000000) {
        sum = sum / 10;
    }

    cout << "Sum is " << sum << endl;
}
