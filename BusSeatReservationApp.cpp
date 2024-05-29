#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    // Initialize the list of available seats
    vector<string> Seats = { "1A", "1B", "1C", "1D" };

    // Display welcome message
    cout << "Bus seat Reservation app\n\n";

    // Variable to control the main loop
    bool returning = true;

    // Display the available seats
    cout << "These are the available seats: \n";
    for (string element : Seats) {
        cout << element << " " << endl;
    }

    // Main loop for reservation process
    while (returning == true) {
        // Variable to ensure valid input
        bool invalidInput = true;

        // Loop until a valid seat choice is made
        while (invalidInput) {
            cout << "Reserve a seat" << endl;
            string choice;

            // Get the seat choice from user input
            getline(cin, choice);

            // Check and process the seat choice
            if (choice == "1A" || choice == "1B" || choice == "1C" || choice == "1D") {
                // Attempt to remove the chosen seat from the list
                auto new_end = remove(Seats.begin(), Seats.end(), choice);
                if (new_end != Seats.end()) {
                    // Erase the removed seat
                    Seats.erase(new_end, Seats.end());
                    cout << "Reserved seat: " << choice << endl;
                } else {
                    // Handle case where seat is not found or already reserved
                    cout << "Seat not found or already reserved :(" << endl;
                }
                invalidInput = false; // Exit the input loop after a valid seat is reserved
            } else {
                // Handle invalid seat choice
                cout << "Invalid input. Try again" << endl;
            }
        }

        // Display the remaining seats
        cout << endl;
        cout << "Seats left: " << endl;
        for (string element : Seats) {
            cout << element << " " << endl;
        }

        // Variable to ensure valid retry choice
        bool invalidRetryChoice = true;

        // Loop until a valid retry choice is made
        while (invalidRetryChoice) {
            cout << "Would you like to reserve another seat? (Y/N)" << endl;
            char retry;
            cin >> retry;

            if (retry == 'y' || retry == 'Y') {
                cin.ignore(); // Ignore the newline character left in the buffer
                invalidRetryChoice = false; // Exit the retry choice loop
            } else if (retry == 'n' || retry == 'N') {
                cout << "Thank you for using the app :D" << endl;
                return 0; // Exit the program
            } else {
                // Handle invalid retry choice
                cout << "Invalid input. Try again\n";
            }
        }
    }

    return 0;
}

