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

std::vector<std::string> hint; // Note that hint is globally available; we want it to be like this for this project ; seen everywhere, no need to make 

bool getHint(std::string secret, char guessLetter)
{
    // TODO: Write code that updates the hint based on the secret
    // and based on the guess letter.  Use the hint from above.

    // The procedure should return true if the letter was in the word,
    // and return false if the letter was not in the word.

    bool isletter = false;
    for(int i = 0; i < secret.length(); i++) //assistance from ai for loop: i starts at zero which is the first value of the list secret. i < length of list so that i doesn't go out of bounds. i++ means it will add one each time so no need for curr_index
    {
        if (guessLetter == secret[i])
        {
            hint[i] = guessLetter; //letter is replaced in index in hint list where it corresponds with index at secret list ; for loop only checks elements, so make sure it has an index to know where to replace it or else it will appen 
            isletter = true;
        }
    }
    return isletter;
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
        "sunjae",
        "elevator",
        "drsarah",
        "lemonade",
        "ghost",
        "velocity",
        "nebraska",
        "tropical",
        "mrnguyen",
        "involved",
        "shopping",
        "charlies",
        "amongus",
        "milkyway",
        "animals"
    };
    
    std::string answer = wordList[rand() % length(wordList)];
    hint = std::vector<std::string>(answer.length(), "_");

    char letterGuess;
    std::string wordGuess = "";
    int lives = 10;
    

    std::cout << "Welcome to Hangman!\n";
    std::cout << "The answer is " << answer << std::endl;
    
    while (wordGuess != answer && lives > 0)   // TODO: update this condition to run when the game should be played
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
        std::cout << "number of lives: " << lives << std::endl;
        display(hint);

        // TODO: Write code below that asks you whether you want to guess the word
        // and allow the user to guess the word using the variable wordGuess 
        char choice;
        std::cout << "Would you like to guess the word (y/n)?\n";
        std::cin >> choice;
        if(choice == 'y')
        {
            std::cout << "Enter word guess: ";
            std::cin >> wordGuess;
        }
    }

    if (wordGuess == answer)
    {
        std::cout << "Congratulations! You guessed the word: " << answer << std::endl;
    }
    else{
        std::cout << "Game over! The correct word was: " << answer << std::endl;
    }

    std::cout << "lol";
    return 0;
}
