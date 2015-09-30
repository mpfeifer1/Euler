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
    int numberOfHands = 50;

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
        cout << hasFlush(handOne) << endl;

        //if(betterHand(handOne)) {
        //    oneWins++;
        //}
    }

    cout << "Player 1 won " << oneWins << " times" << endl;
}

int hasRoyalFlush(string hand) {
    return hasFlush(hand) && hasStraight(hand);
}

int hasFlush(string hand) {
    if(count(hand.begin(), hand.end(), 'H') == 5 ||
       count(hand.begin(), hand.end(), 'C') == 5 ||
       count(hand.begin(), hand.end(), 'D') == 5 ||
       count(hand.begin(), hand.end(), 'S') == 5) {
        return highestCard(hand);
    }
    return -1;
}

int highestCard(string hand) {

    if(hand.find("K") != string::npos) {
        return 13;
    } else if(hand.find("Q") != string::npos) {
        return 12;
    } else if(hand.find("J") != string::npos) {
        return 11;
    } else if(hand.find("T") != string::npos) {
        return 10;
    } else if(hand.find("9") != string::npos) {
        return 9;
    } else if(hand.find("8") != string::npos) {
        return 8;
    } else if(hand.find("7") != string::npos) {
        return 7;
    } else if(hand.find("6") != string::npos) {
        return 6;
    } else if(hand.find("5") != string::npos) {
        return 5;
    } else if(hand.find("4") != string::npos) {
        return 4;
    } else if(hand.find("3") != string::npos) {
        return 3;
    } else if(hand.find("2") != string::npos) {
        return 2;
    } else if(hand.find("A") != string::npos) {
        return 1;
    } else {
        cout << "Highest number can't find a valid nunber" << endl;
    }

    return -1;
}
