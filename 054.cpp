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

    string oneHand[5];
    string twoHand[5];

    for(int i = 0; i < numberOfHands; i++) { // Calculates every hand

        getline(file, input);
        for(int j = 0; j < 5; j++) { // Put the first 5 cards into the hand
            
        }
        for(int j = 0; j < 5; j++) { // Put the last 5 cards into the other hand
            
        }

        
    }
}

