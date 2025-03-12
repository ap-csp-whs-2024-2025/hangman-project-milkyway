/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

std::vector<std::string> hint = std::vector<std::string>(8, "_");    // Note that hint is globally available; we want it to be like this for this project

bool getHint(std::string secret, char guessLetter)
{
    // TODO: Write code that updates the hint based on the secret
    // and based on the guess letter.  Use the hint from above.

    // The procedure should return true if the letter was in the word,
    // and return false if the letter was not in the word.
    
    
    for each (int i = 0 i; i + 1) 
    if (guessLetter == secret[curr_index])
    {
        hint[curr_index] = guessLetter;
    }
    curr_index + 1;

    
    return false;
} 
int main()
{
    srand(time(0)); // seeding the random number generator

    // Creating a word bank
    std::vector<std::string> wordList = {
        "education",
        "solution",
        "mountain",
        "thypham",
        "alphabet",
        "qlphabet",
        "elevator",
        "diamonds",
        "fragrant",
        "fragrant",
        "velocity",
        "nebraska",
        "tropical",
        "evidence",
        "involved",
        "shopping",
        "charlies",
        "amongus",
        "milkyway",
        "animals"
    };
    
    std::string answer = wordList[rand() % length(wordList)];
    char letterGuess;
    std::string wordGuess = "";
    int lives = 10;

    std::cout << "Welcome to Hangman!\n";
    
    while (true)    // TODO: update this condition to run when the game should be played
    {
        std::cout << "\nEnter your guess: ";
        std::cin >> letterGuess;

        
        
        // TODO: Write code that displays the hint; you can either manually display or use the
        // custom display procedure that I wrote for you
        // TODO: Display hangman person if applicable; or you can display the number of lives left
        if (getHint(answer, letterGuess) == false)
        {
            lives = lives - 1;
            // TODO: Update hangman person if you are using a hangman person
        }
        std::cout << "number of lives: " << lives <<
        display(hint);

        // TODO: Write code below that asks you whether you want to guess the word
        // and allow the user to guess the word using the variable wordGuess
        std::cout << "Would you like to guess the word (y/n)?\n"; 
        
    }

    std::cout << "Some winning or losing message here";
    return 0;
}
