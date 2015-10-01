#include <algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

using namespace std;

bool betterHand(string handOne, string handTwo); // Returns true if first is better, false if second is better
char toCardNotation(int num);

int hasRoyalFlush    (string hand); // All methods return -1 if they don't have it
int hasStraightFlush (string hand); // Otherwise, they return the highest card in it
int hasFourOfAKind   (string hand);
int hasFullHouse     (string hand);
int hasFlush         (string hand);
int hasStraight      (string hand);
int hasThreeOfAKind  (string hand);
int hasTwoPairs      (string hand);
int hasPair          (string hand);
int hasPair          (string hand, int skip);

int highestCard      (string hand);
int highestValue     (string hand);

int main() {
    int oneWins = 0;
    int numberOfHands = 10;

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
        //cout << hasPair(handOne) << endl;

        if(betterHand(handOne, handTwo)) {
            oneWins++;
            cout << "PLayer One Wins" << endl;
        } else {
            cout << "Player Two Wins" << endl;
        }
    }

    cout << "Player 1 won " << oneWins << " times" << endl;
}

bool betterHand(string handOne, string handTwo) {
    if(hasRoyalFlush(handOne) != hasRoyalFlush(handTwo)) {
        return hasRoyalFlush(handOne) > hasRoyalFlush(handTwo);
    }
    if(hasStraightFlush(handOne) != hasStraightFlush(handTwo)) {
        return hasStraightFlush(handOne) > hasStraightFlush(handTwo);
    }
    if(hasFourOfAKind(handOne) != hasFourOfAKind(handTwo)) {
        return hasFourOfAKind(handOne) > hasFourOfAKind(handTwo);
    }
    if(hasFullHouse(handOne) != hasFullHouse(handTwo)) {
        return hasFullHouse(handOne) > hasFullHouse(handTwo);
    }
    if(hasFlush(handOne) != hasFlush(handTwo)) {
        return hasFlush(handOne) > hasFlush(handTwo);
    }
    if(hasStraight(handOne) != hasStraight(handTwo)) {
        return hasStraight(handOne) > hasStraight(handTwo);
    }
    if(hasThreeOfAKind(handOne) != hasThreeOfAKind(handTwo)) {
        return hasThreeOfAKind(handOne) > hasThreeOfAKind(handTwo);
    }
    if(hasTwoPairs(handOne) != hasTwoPairs(handTwo)) {
        return hasTwoPairs(handOne) > hasTwoPairs(handTwo);
    }
    if(hasPair(handOne) != hasPair(handTwo)) {
        return hasPair(handOne) > hasPair(handTwo);
    }
    return highestCard(handOne) > highestCard(handTwo);
}

int hasRoyalFlush(string hand) {
    return hasFlush(hand) > 0 &&
           hand.find("A") != string::npos &&
           hand.find("K") != string::npos &&
           hand.find("Q") != string::npos &&
           hand.find("J") != string::npos &&
           hand.find("T") != string::npos;
}

int hasStraightFlush(string hand) {
    if(hasFlush(hand) > 0 && hasStraight(hand) > 0) {
        return highestCard(hand);
    }
    return -1;
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

int hasFullHouse(string hand) {
    if(hasPair(hand) > 0 && hasThreeOfAKind(hand) > 0) {
        return highestCard(hand);
    }
    return -1;
}

int hasFourOfAKind(string hand) {
    for(int a = 1; a <= 13; a++) {
        if(count(hand.begin(), hand.end(), toCardNotation(a)) == 4) {
            return a;
        }
    }
    return -1;
}

int hasThreeOfAKind(string hand) {
    for(int a = 1; a <= 13; a++) {
        if(count(hand.begin(), hand.end(), toCardNotation(a)) == 3) {
            return a;
        }
    }
    return -1;
}

int hasPair(string hand) {
    return hasPair(hand, -1);
}

int hasPair(string hand, int skip) {
    for(int a = 1; a <= 13; a++) {
        if(a == skip) {
            a++;
        }
        if(count(hand.begin(), hand.end(), toCardNotation(a)) == 2) {
            return a;
        }
    }
    return -1;
}

int hasTwoPairs(string hand) {
    if(hasPair(hand) > 0) {
        int valueOne = hasPair(hand);
        int valueTwo = hasPair(hand, valueOne);
        return valueTwo;
    }
    return -1;
}

int hasStraight(string hand) {
    int highest = highestValue(hand);
    bool hasStraight = true;
    for(int i = 1; i < 5; i++) {
        if(!(hand.find(toCardNotation(highest - i)) != string::npos)) {
            hasStraight = false;
        }
    }
    if(hasStraight) {
        return highest;
    }
    return -1;
}

int highestCard(string hand) {

    if(hand.find("A") != string::npos) {
        return 1;
    } else if(hand.find("K") != string::npos) {
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
    } else {
        cout << "Highest number can't find a valid nunber" << endl;
    }

    return -1;
}

int highestValue(string hand) {

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

char toCardNotation(int num) {
    switch(num) {
        case 13:
            return 'K';
        case 12:
            return 'Q';
        case 11:
            return 'J';
        case 10:
            return 'T';
        case 1:
            return 'A';
    }
    return char(num);
}
