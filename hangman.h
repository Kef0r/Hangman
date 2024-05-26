#include <iostream>
#include <vector>
#include <conio.h>
using namespace std;

class THangman
{
                /*the loadWords() method, is used to load the database of words into the game and select a word by drawing the number of lines in the database file*/
    void loadWords();
                /*the loadPhrases() method, is used to load the database of phrases into the game and select a phrase by drawing the number of lines in the database file*/
    void loadPhrases();
                /*the loadSentences() method, is used to load the database of sentences into the game and select a sentence by drawing the number of lines in the database file*/
    void loadSentences();
                /*the checkGuess() method, used to check whether the character guessed by the user is available in his word/phrase/sentence*/
    int checkCharacter(vector<char> &mystery, string character, string toGuess, short points);
public:
    int difficulty;
                /*setDifficultyLevel() is a startup method, which asks player about game difficulty*/
    void setDifficultyLevel();
                /*startGame() is the main method, that manages the course of the game*/
    bool startGame(string toGuess);
                /*printHangman() is a method for printing current state of the game*/
    void printHangman(short points);

};