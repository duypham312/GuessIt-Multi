//
//  main.cpp
//  GuessIt Multi
//
//  Created by Duy on 2/23/20.
//  Copyright © 2020 Duy. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RandomNumber();
int Input();
void result(int guess, int number);
void playGuessIt();
int Restart();

int main() {
    cout << "Please choose an option below!" << endl;
    cout << "1. Start - (S)" << endl;
    cout << "2. Exit - (E)" << endl << endl;
    cout << "My option is ";
    char c;
    do {
        cin >> c;
        cout << endl;
        if (c == 'S' or c == 's') {
            playGuessIt();
            Restart();
            return 0;
        }
        else if (c == 'E' or c == 'e') {
            cout << "See you again!" << endl << endl;
            return 0;
        }
        else cout << "Invalid! Please try again!" << endl;
    } while (c != 'S' and c != 's' and c != 'E' and c != 'e');
    return 0;
}

void playGuessIt() {
    cout << endl;
    srand(static_cast<unsigned int>(time(NULL)));
    cout << "Welcome to GuessIt <3" << endl;
    cout << "I've picked a secret number." << endl;
    cout << "You need to guess a number from 1 to 100 to find the number I've picked." << endl;
    cout << "Alright. Let's start!" << endl;
    int number = RandomNumber();
    int guess;
    int turns = 0;
    do {
        guess = Input();
        result(guess, number);
        turns++;
    } while (guess != number);
    cout << endl << "You guessed " << turns << " times." << endl;
    cout << "Your score: " << 100 - turns << endl << endl;
}

int Restart() {
    char s;
    cout << "Good job! Please choose an option below!" << endl;
    cout << "1. New game - (N)" << endl;
    cout << "2. Exit - (E)" << endl << endl;
    cout << "My option is ";
    do {
        cin >> s;
        cout << endl;
        if (s == 'N' or s == 'n') {
            playGuessIt();
            Restart();
        } else {
            cout << "See you again. <3" << endl << endl;
            return 0;
        }
    } while (s != 'E' and s != 'e' and s != 'N' and s != 'n');
    return 0;
}

int RandomNumber() {
    
    return rand() % 100 + 1;
}

int Input() {
    int guess;
    cout << endl << "Please pick a number from 1 to 100." << endl << endl;
    cin >> guess;
    cout << endl;
    return guess;
}

void result(int guess, int number) {
    if (guess == number) {
        cout << "Congratulation! You won." << endl;
        cout << "You did it!" << endl;
    }
    if (guess < number) {
        cout << "The number you picked is too small. Don't give up!" << endl;
        cout << "Let's try again." << endl;
    }
    if (guess > number) {
        cout << "The number you picked is too big. Come on. You can do it!."  << endl;
        cout << "One more time!" << endl;
    }
}
