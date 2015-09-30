#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool betterHand(string handOne, string handTwo); // Returns true if first is better, false if second is better
string toCardNotation(int num);

int hasRoyalFlush    (string hand); // All methods return -1 if they don't have it
int hasStraightFlush (string hand); // Otherwise, they return the highest card in it
int hasFourOfAKind   (string hand);
int hasFullHouse     (string hand);
int hasFlush         (string hand);
int hasStraight      (string hand);
int hasThreeOfAKind  (string hand);
int hasTwoPairs      (string hand);
int hasPair          (string hand);
int highestCard      (string hand);

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
        cout << hasPair(handOne) << endl;

        //if(betterHand(handOne)) {
        //    oneWins++;
        //}
    }

    cout << "Player 1 won " << oneWins << " times" << endl;
}

int hasRoyalFlush(string hand) {
    return hasFlush(hand) &&
           hand.find("A") != string::npos &&
           hand.find("K") != string::npos &&
           hand.find("Q") != string::npos &&
           hand.find("J") != string::npos &&
           hand.find("T") != string::npos &&
}

int hasStraightFlush(string hand) {
    if(hasFlush(hand) && hasStraight(hand)) {
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
    if(hasPair(hand) && hasThreeOfAKind(hand)) {
        return highestCard(hand);
    }
    return -1;
}

int hasFourOfAKind(string hand) {
    if(count(hand.begin(), hand.end(), 'A') == 4 ||
       count(hand.begin(), hand.end(), '2') == 4 ||
       count(hand.begin(), hand.end(), '3') == 4 ||
       count(hand.begin(), hand.end(), '4') == 4 ||
       count(hand.begin(), hand.end(), '5') == 4 ||
       count(hand.begin(), hand.end(), '6') == 4 ||
       count(hand.begin(), hand.end(), '7') == 4 ||
       count(hand.begin(), hand.end(), '8') == 4 ||
       count(hand.begin(), hand.end(), '9') == 4 ||
       count(hand.begin(), hand.end(), 'T') == 4 ||
       count(hand.begin(), hand.end(), 'K') == 4 ||
       count(hand.begin(), hand.end(), 'Q') == 4 ||
       count(hand.begin(), hand.end(), 'J') == 4) {
        return highestCard(hand);
    }
    return -1;
}

int hasThreeOfAKind(string hand) {
    if(count(hand.begin(), hand.end(), 'A') == 3 ||
       count(hand.begin(), hand.end(), '2') == 3 ||
       count(hand.begin(), hand.end(), '3') == 3 ||
       count(hand.begin(), hand.end(), '4') == 3 ||
       count(hand.begin(), hand.end(), '5') == 3 ||
       count(hand.begin(), hand.end(), '6') == 3 ||
       count(hand.begin(), hand.end(), '7') == 3 ||
       count(hand.begin(), hand.end(), '8') == 3 ||
       count(hand.begin(), hand.end(), '9') == 3 ||
       count(hand.begin(), hand.end(), 'T') == 3 ||
       count(hand.begin(), hand.end(), 'K') == 3 ||
       count(hand.begin(), hand.end(), 'Q') == 3 ||
       count(hand.begin(), hand.end(), 'J') == 3) {
        return highestCard(hand);
    }
    return -1;
}

int hasPair(string hand) {
    if(count(hand.begin(), hand.end(), 'A') == 2 ||
       count(hand.begin(), hand.end(), '2') == 2 ||
       count(hand.begin(), hand.end(), '3') == 2 ||
       count(hand.begin(), hand.end(), '4') == 2 ||
       count(hand.begin(), hand.end(), '5') == 2 ||
       count(hand.begin(), hand.end(), '6') == 2 ||
       count(hand.begin(), hand.end(), '7') == 2 ||
       count(hand.begin(), hand.end(), '8') == 2 ||
       count(hand.begin(), hand.end(), '9') == 2 ||
       count(hand.begin(), hand.end(), 'T') == 2 ||
       count(hand.begin(), hand.end(), 'K') == 2 ||
       count(hand.begin(), hand.end(), 'Q') == 2 ||
       count(hand.begin(), hand.end(), 'J') == 2) {
        return highestCard(hand);
    }
    return -1;
}

int hasTwoPairs(string hand) {

}

int hasStraight(string hand) {
    int highest = highestCard(hand);
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

string toCardNotation(int num) {
    switch(num) {
        case 13:
            return "K";
        case 12:
            return "Q";
        case 11:
            return "J";
        case 10:
            return "T";
        case 1:
            return "A";
    }
    return num;
}
