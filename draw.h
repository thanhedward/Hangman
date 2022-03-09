#include <iostream>
#include <vector>

using namespace std;
#ifndef _HANGMAN_H
#define _HANGMAN_H
const string FIGURE[] = {
    // badGuessCount = 0
    "   --------------    \n"
    "   |                 \n"
    "   |                 \n"
    "   |                 \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 1
    "   --------------    \n"
    "   |            |     \n"
    "   |                 \n"
    "   |                 \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 2
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |                 \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 3
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |            |    \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 4
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |           /|    \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 5
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |           /|\\  \n"
    "   |                 \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 6
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |           /|\\  \n"
    "   |           /     \n"
    "   |     \n"
    " -----   \n",

    // badGuessCount = 7
    "   --------------    \n"
    "   |            |    \n"
    "   |            o    \n"
    "   |           /|\\  \n"
    "   |           / \\   \n"
    "   |     \n"
    " -----   \n",
};

const int MAX_BAD_GUESSED = 7;
const char DATA_PATH[] = "vocabulary.txt";
string wrongGuessedWord = "";


string chooseWord(const char* filePath);
void renderGame (const string guessWord, int badGuessCount);
char readGuess() ;
bool contains(string word, char c);
void update(string &guessedWord, string word, char guess, vector <int> &arrayCount);
bool checkError(string enterWord, char c);
void record(int badGuessPoint);
void seeRecord();
string getAllWordLowerCase(string word);
void alertDupli(string word, const vector <int> &arrayCount);
void afterGame(string guessedWord, const int &badGuessCount, const string &word);
void playGame();

#endif