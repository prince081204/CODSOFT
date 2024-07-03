#include <iostream>
#include <cstdlib>
#include <ctime>

void printMotivationalMessage(int attempts) {
    if (attempts <= 3) {
        std::cout << "Amazing! You guessed it in just " << attempts << " attempts! You have a sharp mind!" << std::endl;
    } else if (attempts <= 6) {
        std::cout << "Good job! You guessed it in " << attempts << " attempts! Keep it up!" << std::endl;
    } else {
        std::cout << "You got it! It took you " << attempts << " attempts, but persistence pays off!" << std::endl;
    }
}

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr))); // Seed for random number generation
    int randomNumber = std::rand() % 100 + 1; // Generate a random number between 1 and 100
    int guess;
    int attempts = 0;
    const int maxAttempts = 10; // Limiting the number of attempts to 10

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I have selected a number between 1 and 100." << std::endl;
    std::cout << "You have " << maxAttempts << " attempts to guess the correct number. Good luck!" << std::endl;

    while (attempts < maxAttempts) {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        attempts++;

        if (guess < randomNumber) {
            std::cout << "Too low! Try again." << std::endl;
        } else if (guess > randomNumber) {
            std::cout << "Too high! Try again." << std::endl;
        } else {
            std::cout << "Congratulations! You've guessed the correct number." << std::endl;
            printMotivationalMessage(attempts);
            break;
        }

        if (attempts == maxAttempts) {
            std::cout << "Sorry, you've used all " << maxAttempts << " attempts. Better luck next time!" << std::endl;
            std::cout << "The correct number was: " << randomNumber << std::endl;
        }
    }

    return 0;
}