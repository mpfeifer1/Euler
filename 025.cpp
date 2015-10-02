#include <iostream>

using namespace std;

int main() {
    int desiredLength = 4;
    int array1[desiredLength];
    int array2[desiredLength];

    // Initializes array 1 to 0
    for(int i = desiredLength -1; i >= 0; i--) {
        array1[i] = 0;
    }

    // Initializes array 2 to 0
    for(int i = desiredLength -1; i >= 0; i--) {
        array2[i] = 0;
    }

    // Sets both arrays to ...001
    array1[0] = 1;
    array2[0] = 1;

    // Outuputs array 1
    for(int i = desiredLength -1; i >= 0; i--) {
        cout << array1[i];
    }
    cout << endl << endl;

    // Outputs array 2
    for(int i = desiredLength -1; i >= 0; i--) {
        cout << array2[i];
    }
    cout << endl << endl;

    while(array1[desiredLength - 1] == 0 || array2[desiredLength - 1] == 0) {
        // Adds array 1 to array 2
        int carry1 = 0;
        for(int i = 0; i < desiredLength -1; i++) {
            int temp = array1[i] + array2[i] + carry1;
            if(temp > 9) {
                array1[i] = (temp % 10);
                carry1 = 1;
            } else {
                array1[i] = temp;
                carry1 = 0;
            }
        }

        // Adds array 2 to array 1
        int carry2 = 0;
        for(int i = 0; i < desiredLength -1; i++) {
            int temp = array1[i] + array2[i] + carry2;
            if(temp > 9) {
                array2[i] = (temp % 10);
                carry2 = 1;
            } else {
                array2[i] = temp;
                carry2 = 0;
            }
        }

        // Outputs array 1
        for(int i = desiredLength -1; i >= 0; i--) {
            cout << array1[i];
        }
        cout << endl << endl;

        // Outputs array 2
        for(int i = desiredLength -1; i >= 0; i--) {
            cout << array2[i];
        }
        cout << endl << endl;

    }
}
