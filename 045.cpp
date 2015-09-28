#include <iostream>

using namespace std;

int getTriangle(int index);
int getPentagon(int index);
int getHexagon(int index);

int main() {
    bool found = false;

    int triIndex = 284;
    int pentIndex = 164;
    int hexIndex = 143;

    do {
        int triangle = getTriangle(triIndex);
        int pentagon = getPentagon(pentIndex);
        int hexagon = getHexagon(hexIndex);

        cout << "Hex is " << hexagon << endl;
        cout << "Pent is " << pentagon << endl;
        cout << "Tri is " << triangle << endl;
        cout << endl;

        if(triangle == pentagon && pentagon == hexagon && triangle == hexagon) {
            cout << "Tri-Pent-Hex number is " << getTriangle(triIndex) << endl;
            found = true;
        }

        if(triangle < pentagon && triangle < hexagon) {
            triIndex++;
        } else if(pentagon < triangle && pentagon < hexagon) {
            pentIndex++;
        } else if(hexagon < triangle && hexagon < pentagon) {
            hexIndex++;
        } else {
            cout << "All numbers are equal" << endl;
        }

    } while(!found);
}

int getTriangle(int index) {
    return index * (index + 1) / 2;
}

int getPentagon(int index) {
    return index * (3 * index - 1) / 2;
}

int getHexagon(int index) {
    return index * (2 * index - 1);
}
