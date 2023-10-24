#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator with the current time
    srand(time(0));
    
    // Generate a random number between 1 and 100 (you can adjust the range as needed)
    int secretNumber = rand() % 100 + 1;
    int userGuess;
    
    std::cout << "Welcome to the Number Guessing Game!" << std::endl;

    while (true) {
        std::cout << "Guess the number (between 1 and 100): ";
        std::cin >> userGuess;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a valid number." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        } else if (userGuess == secretNumber) {
            std::cout << "Congratulations! You guessed the correct number." << std::endl;
            break;
        } else if (userGuess < secretNumber) {
            std::cout << "Too low! Try a higher number." << std::endl;
        } else {
            std::cout << "Too high! Try a lower number." << std::endl;
        }
    }

    return 0;
}
