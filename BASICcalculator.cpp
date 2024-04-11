#include <iostream>


int main() {
    char operations;
    float num1;
    float num2;
    bool retry = true;

    // Displaying a welcome message
    std::cout << "This is my very simple calculator app" << std::endl;

    // Main loop of the calculator program
    while (retry == true) {
        // Prompting the user to choose an operation
        std::cout << "Which operation would you like to perform (+, -, *, /): ";
        std::cin >> operations;

        // Checking if the entered operation is valid
        if (operations != '+' && operations != '-' && operations != '/' && operations != '*') {
           std::cout << "Invalid operation";
            return 0; // Exiting the program if the operation is invalid
        }

        // Prompting the user to enter two numbers
        std::cout << "Choose numbers for calculation: " << std::endl;
        std::cout << "First number: ";
        if (!(std::cin >> num1)) {
            std::cout << "Invalid input. must enter a number";
            return 0; // Exiting the program if the input is not a number
        }
        std::cout << "Second number: ";
        if (!(std::cin >> num2)) {
            std::cout << "Invalid input. must enter a number";
            return 0; // Exiting the program if the input is not a number
        }

        // Performing the selected operation based on the user's input
        switch (operations) {
        case '+':
            std::cout << "You chose addition" << std::endl << num1 << " + " << num2 << " = : " << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << "You chose subtraction" << std::endl << num1 << " - " << num2 << " = " << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << "You chose multiplication" << std::endl << num1 << " * " << num2 << " = " << num1 * num2 << std::endl;
            break;
        case '/':
            if (num2 == 0) {
                std::cout << "Cannot divide by zero";
                break;
            }
            else {
                std::cout << "You chose division" << std::endl << num1 << " / " << num2 << " = " << num1 / num2 << std::endl;
            }
        }

        char choice;
        bool retry2 = true;

        // Loop for handling retry option
        while (retry2 == true) {
            // Prompting the user to choose whether to use the calculator again
            std::cout << "Would you like to try and use the calculator again? (Y/N): ";
            std::cin >> choice;

            // Handling the user's choice
            if (choice == 'Y' || choice == 'y') {
                std::cout << "Okayyy :D ";
                retry2 = false; // Exiting the retry loop if the user chooses to continue
            }
            else if (choice == 'n' || choice == 'N') {
                std::cout << "Okayyy, thank you for using the calculator" << std::endl;
                retry = false; // Exiting the main loop if the user chooses not to continue
                return 0;
            }
            else {
                std::cout << "Invalid input, you must choose (Y/N)" << std::endl;
                continue; // Restarting the loop if the input is invalid
            }
        }
    }
    return 0; // Exiting the program
}
