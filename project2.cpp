#include <iostream>
#include <random> // This header is not used in your code, you can remove it
#include <vector> // This header is not used in your code, you can remove it
#include <ctime> // This header is not used in your code, you can remove it

using namespace std;

int main() {
    char operations;
    float num1;
    float num2;
    bool retry = true;

    // Displaying a welcome message
    cout << "This is my very simple calculator app" << endl;

    // Main loop of the calculator program
    while (retry == true) {
        // Prompting the user to choose an operation
        cout << "Which operation would you like to perform (+, -, *, /): ";
        cin >> operations;

        // Checking if the entered operation is valid
        if (operations != '+' && operations != '-' && operations != '/' && operations != '*') {
            cout << "Invalid operation";
            return 0; // Exiting the program if the operation is invalid
        }

        // Prompting the user to enter two numbers
        cout << "Choose numbers for calculation: " << endl;
        cout << "First number: ";
        if (!(cin >> num1)) {
            cout << "Invalid input, must enter a number";
            return 0; // Exiting the program if the input is not a number
        }
        cout << "Second number: ";
        if (!(cin >> num2)) {
            cout << "Invalid input, must enter a number";
            return 0; // Exiting the program if the input is not a number
        }

        // Performing the selected operation based on the user's input
        switch (operations) {
        case '+':
            cout << "You chose addition" << endl << num1 << " + " << num2 << " = : " << num1 + num2 << endl;
            break;
        case '-':
            cout << "You chose subtraction" << endl << num1 << " - " << num2 << " = " << num1 - num2 << endl;
            break;
        case '*':
            cout << "You chose multiplication" << endl << num1 << " * " << num2 << " = " << num1 * num2 << endl;
            break;
        case '/':
            if (num2 == 0) {
                cout << "Cannot divide by zero";
                break;
            }
            else {
                cout << "You chose division" << endl << num1 << " / " << num2 << " = " << num1 / num2 << endl;
            }
        }

        char choice;
        bool retry2 = true;

        // Loop for handling retry option
        while (retry2 == true) {
            // Prompting the user to choose whether to use the calculator again
            cout << "Would you like to try and use the calculator again? (Y/N): ";
            cin >> choice;

            // Handling the user's choice
            if (choice == 'Y' || choice == 'y') {
                cout << "Okayyy :D ";
                retry2 = false; // Exiting the retry loop if the user chooses to continue
            }
            else if (choice == 'n' || choice == 'N') {
                cout << "Okayyy, thank you for using the calculator" << endl;
                retry = false; // Exiting the main loop if the user chooses not to continue
                return 0;
            }
            else {
                cout << "Invalid input, you must choose (Y/N)" << endl;
                continue; // Restarting the loop if the input is invalid
            }
        }
    }
    return 0; // Exiting the program
}
