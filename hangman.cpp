#include <cstdlib>
#include <vector>
#include <fstream>
#include <algorithm>
#include <stdio.h>
#include <string>
#include "draw.h"


string chooseWord(const char* filePath)
{
     vector <string> wordList;
     ifstream filein(filePath);
     if (filein.is_open()){
         string word;
         while (filein >> word){
             wordList.push_back(word);
         }
     }
     filein.close();
     int randomIndex = rand() % wordList.size();
     return getAllWordLowerCase(wordList[randomIndex]);
 }


string getAllWordLowerCase(string word)
{
    string res = word;
    transform(word.begin(), word.end(), res.begin(), ::tolower);
    return res;
}

void renderGame (const string guessWord, int badGuessCount)
{
    cout << FIGURE[badGuessCount] << endl;
    cout << guessWord << endl;
    cout << "Number of wrong word: " << badGuessCount << endl;
    cout << "These wrong word you have guessed is: " << wrongGuessedWord << endl;
}

char readGuess() 
{
    char input;
    cout << "Your guess: ";
    cin >> input;
    return input;
}

bool contains(string word, char c){
    return (word.find_first_of(c) != string::npos);
}

void update(string &guessedWord, string word, char guess, vector <int> &arrayCount){
    for (int i = word.length()-1; i>=0; --i){
        if (word[i] == guess) {
            guessedWord[i] = guess;
            arrayCount[i] ++;
        }
    }
}


void record(int badGuessCount)
{
     time_t now = time(0);

 // convert now to string form
    char* dt = ctime(&now);
    string name;
    int j;
    cout << "Enter your nickname: " << "\n";  
    cin >> name;
    system("CLS");
    ofstream outfile;
    outfile.open("record.txt", ios_base::app);
    outfile << dt << endl;
    outfile << name << endl;
    outfile << "Number of your wrong word is: " << badGuessCount << endl;
    outfile << string(10, '_') << "\n\n\n";
    outfile.close();
}

void seeRecord()
{
    ifstream filein;
    filein.open("record.txt",ios_base::in);
    string data;
    while (!filein.eof())
	{
		char temp[255];
		filein.getline(temp, 255);
		string line = temp;
		cout << line << endl;
	}
}

void alertDupli(string word, const vector <int> &arrayCount) 
{
    for (int i = word.length()-1; i>=0; --i) {
        if (arrayCount[i] > 1) {
        cout <<  " You have typed this corret letter before, please type other letter!" << endl;
        break;
        }
    }
}


void afterGame(string guessedWord, const int &badGuessCount, const string &word)
{
    renderGame(guessedWord, badGuessCount);
    if (badGuessCount < MAX_BAD_GUESSED){
        cout << "Congragulation! You win! \n";
    }
    else 
        cout << "You lost. The correct word is: " << word << endl;
        
    	record(badGuessCount);
    	char isSee;
    	cout << "Wanna see the past records press 'y' \n";
        cin >> isSee;
        if (isSee == 'y'){
            seeRecord();
            cout << "Do you want reset the record ? \n";
            char isDelete;
            cin >> isDelete;
            if (isDelete == 'y'){
                remove("record.txt");
            }
        }
}


bool continuePlaying()
{
    char isContinued;
	cout << "Do you want to continue playing?" << endl;
	cout << "Y to continue, N to exit: ";
	cin >> isContinued;
    if(isContinued=='y' || isContinued=='Y')
    {
		return true;
	}
	return false;
}

void playGame(){
    string word = chooseWord(DATA_PATH);
    int lengthOfWord = word.length();
    vector <int> arrCount(lengthOfWord , 0);
    string guessedWord = string(word.length(), '-');
    int badGuessCount = 0;
    do {
        renderGame(guessedWord, badGuessCount);
        char guess = readGuess();
        system("CLS");
        if (contains(word, guess)){
            update(guessedWord, word, guess, arrCount);
            cout << endl;
            alertDupli(word, arrCount);
        }
        else {
            wrongGuessedWord += guess;
        	badGuessCount ++;
		}

    } while (badGuessCount < MAX_BAD_GUESSED && guessedWord != word);

    afterGame(guessedWord, badGuessCount, word);
}
