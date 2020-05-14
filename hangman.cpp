/* CISC 1600
 * Roger Vo
 * Final Project
 */

#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

//These variables are defined in the global scope
//This string includes the letters that are already guessed
string used_letter = "";
//This string sorts the letters that are not in the puzzle
string missed_letter = "";
char guess;
int chances;


void user_guess();

string check_guess(string puzzle, string word);

void win_or_lose(int chances, string word);


int main()
{
    cout <<"\nWelcome to the Hangman Game!\n" <<endl;

    char choice, replay;
    string word;
    bool hangman = true;

// This do-while allows the user to play the game again if they wish
do { 
// This do-while includes a switch statement in which the user enters their
// choice of difficulty.
    do {
        cout <<"Please choose your level of difficulty." <<endl;
        cout <<"('e' for easy, 'm' for medium-hard, and 'h' for hard): ";
        cin >> choice;
        switch (choice)
        {
            case 'e':
                word = "crypt";
                chances = 6;
                break;
            case 'm':
                word = "ecstatic";
                chances = 8;
                break;
            case 'h':
                word = "extraordinary";
                chances = 10;
                break;
            default:
                cout <<"Not a valid input." <<endl;
                break;
         }
     } while (choice != 'e' && choice != 'm' && choice != 'h');
 
    string puzzle(word.size(), '-');

    while ((chances > 0) && (puzzle != word))
    {
        cout << "You have " << chances << " wrong guesses remaining.\n" <<endl;
        cout << puzzle <<"\n" <<endl;
        cout << "Used letters: " << used_letter <<"\n" << endl;
        cout << "Missed letters: " << missed_letter <<"\n" <<endl;
 
        user_guess();

        puzzle = check_guess(puzzle, word);
    }
 
    win_or_lose(chances, word);

//This is where the program asks the user to play again or not
    cout <<"Would you like to play again? ('y' for yes, 'n' for no): ";
    cin >> replay;

    do {
       switch (replay) {
          case 'Y':
          case 'y':
              used_letter.clear();
              missed_letter.clear();
              break;
          case 'N':
          case 'n':
              cout <<"\nThank you for playing Hangman!\n" <<endl;
              exit(1);
          default: 
              cout <<"Not a valid input.";
      }
    } while (replay != 'y' && replay != 'y' && replay != 'n' && replay != 'n');
 } while (hangman == true);
    return 0;
}

//This function asks the user to enter a letter to guess. If the user enters a 
//guess that is already chosen, the program will let the user know and ask for
//another guess
void user_guess()
{
    cout << "Enter a letter to guess: ";
    cin >> guess;
    while (used_letter.find(guess) != string::npos)
    {
        cout << "\nThis letter is already guessed!\n" <<endl;
        cout << "Enter another letter to guess: ";
        cin >> guess;
    }
 
    used_letter += guess;
}

//This function checks to see if the player's guess is in the puzzle. It takes 
//in the parameter of the word, and the puzzle with the dashes.
string check_guess(string puzzle, string word)
{
    if (word.find(guess) != string::npos)
    {
        cout << "\nGood! The letter " << guess << " is in the puzzle.\n" <<endl;
 
        for (int i = 0; i < word.length(); ++i)
        {
            if (word[i] == guess) {
                puzzle[i] = guess;
            }
        }
    }  else  {
        cout << "\nSorry, " << guess << " isn't in the word.\n" <<endl;
        chances = chances - 1;
        missed_letter += guess;
    }
    return puzzle;
}


//This function takes in the number of chances and the word as parameters, and 
//consider whether the player wins or loses the game. If the player has 0 
//chances remaining, the game will end and the program will print the game over
//message. Otherwise, the player wins the game and print the congrats message.
void win_or_lose(int chances, string word)
{
    if (chances == 0) {
        cout <<"\nGame over :(\n" <<endl;
    } else {
        cout <<"Congratulations, you solved the puzzle" <<endl;
    }
}
