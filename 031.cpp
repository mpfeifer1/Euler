#include <iostream>

using namespace std;

int main() {
    int goal = 3;
    int total = 0;

    // Define money face values
    int a = 200;
    int b = 100;
    int c = 50;
    int d = 20;
    int e = 10;
    int f = 5;
    int g = 2;
    int h = 1;

    for(int i = 0; a * i < goal; i++) {
        int goal1 = goal;
        for(int j = 0; b * i < goal1; j++) {
            int goal2 = goal1
            for(int k = 0; c * i < goal2; k++) {
                int goal3 = goal2;
                for(int l = 0; d * i < goal3; l++) {
                    int goal4 = goal3;
                    for(int m = 0; e * i < goal4; m++) {
                        int goal5 = goal4;
                        for(int n = 0; f * i < goal5; n++) {
                            int goal6 = goal5;
                            for(int o = 0; g * i < goal6; o++) {
                                int goal7 = goal6;
                                for(int p = 0; h * i < goal7; p++) {
                                    
                                }
                                goal7 = -= g;
                            }
                            goal6 -= f;
                        }
                        goal5 -= e;
                    }
                    goal4 -= d;
                }
                goal3 -= c;
            }
            goal2 -= b;
        }
        goal1 -= a;
    }
}
