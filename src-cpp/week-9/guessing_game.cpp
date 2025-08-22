/*
CH-230-A
a9_p5.c
Santiago Dominguez
1 November 2022
Number guessing game from 1-100, with feedback for high/low guesses
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main(int argc, char** argv){
    //Read player name
    string playerName;
    cout << "Welcome to the number guessing game! What is your name?" << endl;
    getline(cin, playerName);

    //Generate random number between 1 and 100
    int guessNum;
    int randomNumber;
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();
    guessNum = (randomNumber % 100) + 1;

    //Start game and initialize variables
    cout << "I am thinking of a number between 1 and 100. Guess!" << endl;
    int currGuess;
    int numTries;
    
    //Main game loop, continue asking for guess until it matches the random num
    while(1){
        numTries++;
        cin >> currGuess;
        if(currGuess > guessNum){
            cout << "Too high! Try again." << endl;
        } else if (currGuess < guessNum){
            cout << "Too low! Try again." << endl;
        } else if (currGuess == guessNum){
            cout << "Congratulations, " << playerName 
            << "!!! Number of tries: " << numTries << endl;
            break;
        } else {
            cout << "Error." << endl;
            break;
        }
    }

    return 0;
}