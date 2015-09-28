#include <iostream>

using namespace std;

long int getTriangle(long int index);
long int getPentagon(long int index);
long int getHexagon(long int index);

int main() {
    bool found = false;

    long int triIndex = 286;
    long int pentIndex = 166;
    long int hexIndex = 145;

    do {
        long int triangle = getTriangle(triIndex);
        long int pentagon = getPentagon(pentIndex);
        long int hexagon = getHexagon(hexIndex);

        if(triangle == pentagon && pentagon == hexagon && triangle == hexagon) {
            cout << "Tri-Pent-Hex number is " << getTriangle(triIndex) << endl;
            found = true;
        }

        if(triangle < pentagon || triangle < hexagon) {
            triIndex++;
        } else if(pentagon < triangle || pentagon < hexagon) {
            pentIndex++;
        } else if(hexagon < triangle || hexagon < pentagon) {
            hexIndex++;
        } else {
            cout << "All numbers are equal" << endl;
        }

    } while(!found);
}

long int getTriangle(long int index) {
    return index * (index + 1) / 2;
}

long int getPentagon(long int index) {
    return index * (3 * index - 1) / 2;
}

long int getHexagon(long int index) {
    return index * (2 * index - 1);
}
