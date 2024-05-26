#include "hangman.h"
#include <fstream>
#include <time.h>
#include <string>

void THangman::setDifficultyLevel()
{
        system("cls");

        cout << " _________________________\n"
            << "||=======================||\n"
            << "||\t HANGMAN \t ||\n"
            << "||=======================||\n";
        cout << "|| \t  Select \t ||\n"
            << "||    game difficulty    ||\n"
            << "|+-----------------------+|\n"
            << "|| 1: Easy\t\t ||\n"
            << "|| 2: Medium\t\t ||\n"
            << "|| 3: Hard\t\t ||\n"
            << "|+-----------------------+|\n"
            << "||\t [0] EXIT \t ||\n"
            << "|+-----------------------+|\n"
            << "||Your choice:\t\t ||"
            << "\b\b\b\b\b\b\b\b\b\b\b\b\b";
        cin >> difficulty;
                                                /*a recursive condition that is active when player chooses a number less than 0 and greater than 3*/
    if(difficulty > 3 || difficulty < 0) this->setDifficultyLevel();
    
    switch(difficulty)
    {
        case 1:
        {
                    /*this condition is active when player chooses a number equal 1*/
            this->loadWords();
        }
        break;

        case 2:
        {
                    /*this condition is active when player chooses a number equal 2*/
            this->loadPhrases();
        }
        break;

        case 3:
        {
                    /*this condition is active when player chooses a number equal 3*/
            this->loadSentences();
        }
        break;
                    /*this condition is active when player chooses a number equal 0*/
        default: return;
    }
}

bool THangman::startGame(string toGuess)
{
    system("cls");

    vector<char> mystery(toGuess.begin(), toGuess.end());
    for(char &i : mystery){
                    /*this loop, sets '_' for every single character*/
        if(i != ' ') i = '_';
    }
    short negativePoints = 0;
    string character;

    do{
                    /*this loop is the main operation of the game*/
            system("cls");
        cout << " _________________________\n"
            << "||=======================||\n"
            << "||\t HANGMAN \t ||\n"
            << "||=======================||\n\n"
            << "  Guess:  ";

        for(char i : mystery)
            cout << i;

        cout << "\n\n";
        this->printHangman(negativePoints);

        if(negativePoints > -8) cin >> character;

        if(negativePoints > -8){
            negativePoints = this->checkCharacter(mystery, character, toGuess, negativePoints);
        }
        
        if(negativePoints < -7){
            system("cls");
                this->printHangman(-8);

            cout << "\nYOU HAVE LOST!\n"
                << "Your word was \"" << toGuess << "\"\n";

            cout << "\n(exit game by clicking any key)\n";
            _getch();
            return false;
        }
    }while(negativePoints > -8 && negativePoints != 1);

    cout << "\nYOU HAVE WON!\n"
        << "Your word was \"" << toGuess << "\"\n";

    cout << "\n(exit game by clicking any key)\n";
    _getch();
    return true;
}

void THangman::loadWords()
{
                                /*opening words.db file by using <fstream> library*/
    ifstream wordsFile("database/words.db");
        if(!wordsFile.good()){
                                /*this notifications are active when a file is missing or corrupted in the database folder*/
            cout << "There's a problem with your database file.\n"
                 << "-words.db\n"
                 << "Does it exist? Try to re-downlaod your game.\n";
                 getchar();
            return;
        }

                                /*drawing a word by using rand() function of <time.h> library*/
    srand(time(nullptr));
    short wordNumber = rand() % 100 + 1;
    cout << wordNumber << '\n';

    string word;

                                /*searching for a word by decrementing value of wordNumber variable*/
    while(getline(wordsFile, word)){
        if(wordNumber < 2){
            break;
        }
        wordNumber--;
    }

    cout << word;
    this->startGame(word);
}

void THangman::loadPhrases()
{
                                /*opening phrases.db file by using <fstream> library*/
    ifstream phrasesFile("database/phrases.db");
        if(!phrasesFile.good()){
                                /*this notifications are active when a file is missing or corrupted in the database folder*/
            cout << "There's a problem with your database file.\n"
                 << "-phrases.db\n"
                 << "Does it exist? Try to re-downlaod your game.\n";
                 getchar();
            return;
        }

                                /*drawing a phrase by using rand() function of <time.h> library*/
    srand(time(nullptr));
    short phraseNumber = rand() % 100 + 1;
    cout << phraseNumber << '\n';

    string phrase;

                                /*searching for a phrase by decrementing value of phraseNumber variable*/
    while(getline(phrasesFile, phrase)){
        if(phraseNumber < 2){
            break;
        }
        phraseNumber--;
    }

    cout << phrase;
    this->startGame(phrase);
}

void THangman::loadSentences()
{
                                /*opening sentences.db file by using <fstream> library*/
    ifstream sentencesFile("database/sentences.db");
        if(!sentencesFile.good()){
                                /*this notifications are active when a file is missing or corrupted in the database folder*/
            cout << "There's a problem with your database file.\n"
                 << "-sentences.db\n"
                 << "Does it exist? Try to re-downlaod your game.\n";
                 getchar();
            return;
        }

                                /*drawing a sentence by using rand() function of <time.h> library*/
    srand(time(nullptr));
    short sentenceNumber = rand() % 100 + 1;
    cout << sentenceNumber << '\n';

    string sentence;

                                /*searching for a sentence by decrementing value of sentenceNumber variable*/
    while(getline(sentencesFile, sentence)){
        if(sentenceNumber < 2){
            break;
        }
        sentenceNumber--;
    }

    cout << sentence;
    this->startGame(sentence);
}

void THangman::printHangman(short points)
{
                        /*hangman printing cases*/
    switch(points)
    {
        case -8:
        {
            cout << "\n\t====/====+=|\n"
                   << "\t  |/     |\n"
                   << "\t  /\t O\n"
                   << "\t  | \t/0\\ \n"
                   << "\t  |\t /\\ \n"
                   << "\t=====\t*  *\n\n";
        }
        break;

        case -7:
        {
            cout << "\n\t====/====+=|\n"
                   << "\t  |/     |\n"
                   << "\t  /\t O\n"
                   << "\t  | \t/0\\ \n"
                   << "\t  |\t /\\ \n"
                   << "\t=====\n\n";
        }
        break;

        case -6:
        {
            cout << "\n\t====/====+=|\n"
                   << "\t  |/     |\n"
                   << "\t  /\t O\n"
                   << "\t  | \t/0\\ \n"
                   << "\t  |\n"
                   << "\t=====\n\n";
        }
        break;

        case -5:
        {
            cout << "\n\t====/====+=|\n"
                   << "\t  |/     |\n"
                   << "\t  /\t O\n"
                   << "\t  |\n"
                   << "\t  |\n"
                   << "\t=====\n\n";
        }
        break;

        case -4:
        {
            cout << "\n\t====/====+=|\n"
                   << "\t  |/     |\n"
                   << "\t  /\n"
                   << "\t  |\n"
                   << "\t  |\n"
                   << "\t=====\n\n";
        }
        break;

        case -3:
        {
            cout << "\n\t====/======|\n"
                   << "\t  |/\n"
                   << "\t  /\n"
                   << "\t  |\n"
                   << "\t  |\n"
                   << "\t=====\n\n";
        }
        break;
        
        case -2:
        {
            cout << "\n\n"
                   << "\t  |/\n"
                   << "\t  /\n"
                   << "\t  |\n"
                   << "\t  |\n"
                   << "\t=====\n\n";
        }
        break;

        case -1:
        {
            cout << "\n\n\n\n\n\n\t=====\n\n";
        }
        //case 0:
        //{
        //    cout << "\n\n\n\n\n\n\n\n";
        //}
        break;
    }
}

int THangman::checkCharacter(vector<char> &mystery, string character, string toGuess, short points)
{
    bool flag = false;
    short counter = 0;
    for(int i=0; i<toGuess.size(); i++){
                                            /*this loop is checking is character guessed by user exist in his word/sentence/phrase*/
        if(character[0] > 96){
            if(toGuess[i] == character[0] || toGuess[i] == character[0] - 32){
                mystery[i] = toGuess[i];
                flag = true;
            }
        }else{
            if(toGuess[i] == character[0] || toGuess[i] == character[0] + 32){
                mystery[i] = toGuess[i];
                flag = true;
            }
        }
            if(toGuess[i] == mystery[i]) counter++;
    }

    if(!flag){
        points--;
    }
                                            /*this condition checks whether the user has guessed each character, the points variable is set to 1, which stops the game*/
    if(counter == toGuess.size()) points = 1;

    return points;
}