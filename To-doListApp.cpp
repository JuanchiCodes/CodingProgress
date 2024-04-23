#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

using namespace std;

int main() {
    // Create a vector to store the to-do list items
    vector<string> lists = {};

    // Print the application title
    cout << "This is my To-do list application\n" << endl;

    // Main loop for the application
    bool retry1 = true;
    while (retry1) {
        // Prompt the user to choose an action
        cout << "Would you like to add items, remove items, look at the list, or quit the application? ";

        // Get user input and convert it to uppercase
        string choice;
        getline(cin, choice);
        transform(choice.begin(), choice.end(), choice.begin(), ::toupper);

        // Handle user choices
        if (choice == "ADD") {
            // Loop to add items to the list
            bool add = true;
            while (add) {
                // Prompt the user to add an item
                string item;
                cout << "What would you like to add? ";
                cin >> item;
                // Add the item to the list
                lists.push_back(item);
                // Loop to handle adding another item
                bool badsyntax = true;
                while (badsyntax) {
                    // Prompt the user to add another item
                    cout << "Would you like to add another item? (Y/N)";
                    char choice;
                    cin >> choice;
                    cin.ignore();
                    // Handle user choice
                    if (choice == 'Y' || choice == 'y') {
                        cout << "Okay" << endl;
                        badsyntax = false;
                    }
                    else if (choice == 'n' || choice == 'N') {
                        cout << "Okay!!" << endl;
                        add = false;
                        badsyntax = false;
                    }
                    else {
                        cout << "Invalid syntax. Try again." << endl;
                    }
                }
            }
        }
        else if (choice == "LOOK") {
            // Display the current list of items
            cout << "Okay, let's look at the list:" << endl;
            for (const string& display : lists) {
                cout << display << endl;
            }
        }
        else if (choice == "QUIT") {
            // Exit the application
            cout << "Thank you for using the app!! :D";
            return 0;
        }
        else if (choice == "REMOVE") {
            // Remove an item from the list
            if (lists.empty()) {
                cout << "The list is already empty." << endl;
            }
            else {
                // Display the current list of items
                cout << "Here is the current list:" << endl;
                for (const string& display : lists) {
                    cout << display << endl;
                }

                // Prompt the user to enter the item to remove
                string itemToRemove;
                cout << "Enter the item you want to remove: ";
                cin >> itemToRemove;
                cin.ignore();

                // Find the item in the list and remove it
                auto it = find(lists.begin(), lists.end(), itemToRemove);
                if (it != lists.end()) {
                    lists.erase(it);
                    cout << "Item removed successfully." << endl;
                }
                else {
                    cout << "Item not found in the list." << endl;
                }
            }
        }
        else {
            // Handle invalid user input
            cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}



