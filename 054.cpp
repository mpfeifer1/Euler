#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool betterHand(string handOne, string handTwo); // Returns true if first is better, false if second is better

int hasRoyalFlush    (string hand); // All methods return -1 if they don't have it
int hasStraightFlush (string hand); // Otherwise, they return the highest card in it
int hasFourOfAKind   (string hand);
int hasFullHouse     (string hand);
int hasFlush         (string hand);
int hasStraight      (string hand);
int hasThreeOfAKind  (string hand);
int hasTwoPairs      (string hand);
int hasOnePair       (string hand);
int highestCard      (string hand);

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

        cout << handOne << endl;
        cout << highestCard(handOne) << endl;

        //if(betterHand(handOne)) {
        //    oneWins++;
        //}
    }

    cout << "Player 1 won " << oneWins << " times" << endl;
}

int hasFlush(string hand) {
    if(hand.find("H") == 5 || hand.find("C") == 5 ||
       hand.find("D") == 5 || hand.find("S") == 5) {
        return highestCard(hand);
    }
    return -1;
}

int highestCard(string hand) {

    if(hand.find_first_of('K')) {
        return 13;
    } else if(hand.find("Q")) {
        return 12;
    } else if(hand.find("J")) {
        return 11;
    } else if(hand.find("T")) {
        return 10;
    } else if(hand.find("9")) {
        return 9;
    } else if(hand.find("8")) {
        return 8;
    } else if(hand.find("7")) {
        return 7;
    } else if(hand.find("6")) {
        return 6;
    } else if(hand.find("5")) {
        return 5;
    } else if(hand.find("4")) {
        return 4;
    } else if(hand.find("3")) {
        return 3;
    } else if(hand.find("2")) {
        return 2;
    } else if(hand.find("A")) {
        return 1;
    } else {
        cout << "Highest number can't find a valid nunber" << endl;
    }

    return -1;
}
