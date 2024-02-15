/*
CH-230-A
a9_p9.c
Santiago Dominguez
sdominguez@jacobs-university.de
 */

#include <iostream>

using namespace std;

void printUnderscores(string word);
int generateRandomInt(int max);

int main(int argc, char** argv){
    //Initialize wordlist and variables used in game loop
    string words[] = {"computer","television","keyboard","laptop","mouse",
    "mercury","moon","mars","jupiter","kazakhstan","mexico","azerbaijan",
    "turkey","albania","deutschland","hanseatic","mercator"};
    int numTries = 0;
    char playAgain;
    string currGuess;

    //Get first guess word and print output
    string guessWord = words[generateRandomInt(17)];
    cout << "Welcome to the guessing game! Your word is: " << endl;
    printUnderscores(guessWord);

    //Main game loop
    while(1){
        //read user input and increase # of tries
        numTries++;
        cin >> currGuess;

        //Compare user input to target word
        int quitCmd = currGuess.compare("quit");
        int result = currGuess.compare(guessWord);

        if(quitCmd == 0){
            //If the word entered is 'quit', end loop and exit game immediately.
            cout << "Quitting game." << endl;
            exit(0);
            break;
        } else if(result == 0){
            //If word matches target, end game and print number of tries
            cout << "Congratulations!!! Number of tries: " << numTries << endl;
            
            //Ask if player wants to play again
            cout << "Do you wish to play again? [Y/N]" << endl;
            cin >> playAgain;
            if(playAgain == 'N' || playAgain == 'n'){
                break;
            } else if (playAgain == 'Y' || playAgain == 'y'){
                //If yes, generate new word and start loop
                numTries = 0;
                guessWord = words[generateRandomInt(17)];
                cout << "Welcome to the guessing game! Your word is: " << endl; 
                printUnderscores(guessWord);
            }
        } else {
            cout << "Wrong answer! Try again." << endl;
        }
    }

    return 0;
}

void printUnderscores(string word){
    //Initialize bool flag and char vowel array
    char vowels[] = {'a','e','i','o','u'};
    bool flag;

    //Iterate through string; print vowels as '_'
    for(int i = 0; i < (int)word.size(); i++){
        flag = false;
        for(int j = 0; j < 5; j++){
            if(word[i] == vowels[j]){
                cout << '_';
                flag = true;
                break;
            }
        }
        if(!flag){
            cout << word[i];
        }
    }
    cout << endl;
}

int generateRandomInt(int max){
    //Generate random number between 1 and max
    int randomNumber;
    srand(static_cast<unsigned int>(time(0)));
    randomNumber = rand();
    return (randomNumber % max);
}