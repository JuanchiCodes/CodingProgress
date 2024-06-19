#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

using namespace std;

vector<string> itemsShoppedFor;

// Forward declaration
void display(const vector<string>& itemsShoppedFor);
void shop();
void mainMenu();

void display(const vector<string>& itemsShoppedFor) {
    for (const string& item : itemsShoppedFor) {
        cout << ". " << item << " " << endl;
    }
    cout << endl;
}

void mainMenu() {
    string action;
    bool wrongInput = true;
    while (wrongInput) {
        cout << "What would you like to do?" << endl;
        cout << "Shop." << endl;
        cout << "View Cart." << endl;
        cout << "Stop shopping." << endl;

        getline(cin, action);

        transform(action.begin(), action.end(), action.begin(), ::toupper);

        if (action == "SHOP") {
            wrongInput = false;
            shop();
        }
        else if (action == "VIEW CART") {
            wrongInput = false;
            display(itemsShoppedFor);
        }
        else if (action == "STOP SHOPPING") {
            cout << "Thank you for using the app :)";
            return;
        }
        else {
            cout << "Invalid input. Please enter 'Shop', 'View Cart', or 'Quit'." << endl;
            wrongInput = true;
        }
    }
}

void shop() {
    cout << "Shopping application" << endl;
    bool newItem = true;

    while (newItem) {
        cout << "Enter item to be added to the shopping cart please: ";
        string item;
        bool hasDigit = false;

        // Read input and check for digits
        getline(cin, item);
        cout << item << " Added to the cart!" << endl;
        for (char d : item) {
            if (isdigit(d)) {
                cout << "Must enter valid item (no digits allowed)" << endl;
                hasDigit = true;
                break;
            }
        }

        // If input contains digit, skip adding to vector
        if (hasDigit) {
            continue;
        }

        // Add item to shopping cart
        itemsShoppedFor.push_back(item);

        // Ask if user wants to add another item
        bool repickingItem = true;
        while (repickingItem) {
            cout << "Would you like to add another item? (Y/N): ";
            char choiceForRepick;
            cin >> choiceForRepick;
            cin.ignore(); // Clear newline character from input buffer

            if (choiceForRepick == 'Y' || choiceForRepick == 'y') {
                break;
            }
            else if (choiceForRepick == 'N' || choiceForRepick == 'n') {
                cout << "Main Menu:" << endl;
                mainMenu(); // Go back to the main menu
                newItem = false;
                repickingItem = false;
            }
            else {
                cout << "Must enter yes (Y) or no (N)" << endl;
            }
        }
    }
}

int main() {
    mainMenu(); // Start the main menu loop

    return 0;
}
