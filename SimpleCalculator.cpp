#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\nSimple Calculator\n";
    std::cout << "-----------------\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
    std::cout << "-----------------\n";
}

double getNumber(const std::string& prompt) {
    double number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid input. Please enter a number.\n";
        } else {
            return number;
        }
    }
}

int getChoice() {
    int choice;
    while (true) {
        std::cout << "Choose an operation (1-5): ";
        std::cin >> choice;
        if (std::cin.fail() || choice < 1 || choice > 5) {
            std::cin.clear(); // clear the error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
            std::cout << "Invalid choice. Please select a number between 1 and 5.\n";
        } else {
            return choice;
        }
    }
}

void performCalculation(int choice) {
    double num1 = getNumber("Enter the first number: ");
    double num2 = getNumber("Enter the second number: ");
    double result;

    switch (choice) {
        case 1:
            result = num1 + num2;
            std::cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
            break;
        case 2:
            result = num1 - num2;
            std::cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
            break;
        case 3:
            result = num1 * num2;
            std::cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
            break;
        case 4:
            if (num2 == 0) {
                std::cout << "Error: Division by zero is not allowed.\n";
            } else {
                result = num1 / num2;
                std::cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
            }
            break;
        default:
            std::cout << "Invalid operation.\n";
            break;
    }
}

int main() {
    int choice;
    do {
        displayMenu();
        choice = getChoice();
        if (choice == 5) {
            std::cout << "Exiting the calculator. Goodbye!\n";
            break;
        }
        performCalculation(choice);
    } while (choice != 5);

    return 0;
}
