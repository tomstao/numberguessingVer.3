#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cctype>

int guess = 0 ,chances = 0,num = 0,tries = 7,modeRange = 0,maximum = 100;
char replay = 'Y';

void clearInput();
void modeSelection();
void guessingGame();

int main()
{
    srand(time(NULL)); // Seed the random number generator
    std::cout << "Welcome to the number guessing game!\n";

    do {
        modeSelection();
        guessingGame();

        std::cout << "Press Y to play again, any other key to exit: ";
        std::cin >> replay;
        replay = toupper(replay);

    } while (replay == 'Y');

    std::cout << "Thanks for playing!" << std::endl;

    return 0;
}
void clearInput() {
    std::cin.clear();
    std::cin.ignore(1000, '\n');
}
void guessingGame() {
    std::cout << "Please enter an integer between 1 and " << maximum << ":\n";
    std::cout << "You have " << tries << " tries!" << std::endl;

    int attempts = tries;

    while (attempts > 0) {
        std::cout << "Enter your guess: ";

        while (!(std::cin >> guess)) {  // Handle invalid input
            clearInput();
            std::cout << "Invalid input! Please enter a valid number between 1 and " << maximum << ": ";
        }
        attempts--;

        if (guess > num) {
            std::cout << "Too high!" << std::endl;
        } else if (guess < num) {
            std::cout << "Too low!" << std::endl;
        } else {
            std::cout << "Correct! You got it in " << (tries - attempts) << " tries!" << std::endl;
            break;  // Win condition
        }

        if ((tries - attempts) == 4) {
            // Provide a hint after 4 attempts
            if (num <= maximum / 2) {
                std::cout << "Hint: The number is in the lower half: 1-" << maximum / 2 << std::endl;
            } else {
                std::cout << "Hint: The number is in the upper half: " << maximum / 2 << '-' << maximum << std::endl;
            }
            std::cout << "Hint: The units digit is " << num % 10 << std::endl;
        }

        std::cout << "Tries remaining: " << attempts << std::endl;
    }

    std::cout << "You lose! The correct number was " << num << std::endl;// Loss condition
}

void modeSelection() {
    std::cout << "Select difficulty mode:\n";
    std::cout << "1. Range 1-50\n";
    std::cout << "2. Range 1-500\n";
    std::cout << "Any other key: Range 1-100\n";

    std::cin >> modeRange;
    clearInput();

    if (modeRange == 1) {
        maximum = 50;
        num = (rand() % 50) + 1;
        tries = 5;
    } else if (modeRange == 2) {
        maximum = 500;
        num = (rand() % 500) + 1;
        tries = 9;
    } else {
        maximum = 100;
        num = (rand() % 100) + 1;
        tries = 7;
    }
    chances = tries;  // Store initial tries for later use
}