#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool betterHand(); // Returns true if first is better, false if second is better

int hasRoyalFlush();    // All methods return -1 if they don't have it
int hasStraightFlush(); // Otherwise, they return the highest card in it
int hasFourOfAKind();
int hasFullHouse();
int hasFlush();
int hasStraight();
int hasThreeOfAKind();
int hasTwoPairs();
int hasOnePair();
int highestCard();

int main() {
    int oneWins = 0;
    int numberOfHands = 5;

    ifstream file("sources/054.txt");
    string input;

    string handTwo;
    string handOne;

    for(int i = 0; i < numberOfHands; i++) { // Calculates every hand

        getline(file, input);
        input.erase(remove(input.begin(), input.end(), ' '), input.end());

        handOne = input.substr(0, 10);
        handTwo = input.substr(10,10);

        if(betterHand(handOne)) {
            oneWins++;
        }
    }

    cout << "Player 1 won " << oneWins << " times" << endl;
}

