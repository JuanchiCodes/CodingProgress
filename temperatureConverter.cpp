#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    cout << "This is my temperature converter :D\n";
    string tempType;
    string convertedtemp;
    double fahrenheit;
    double kelvin;
    double celsius;
    bool returning = true;
    bool retry = true;
    while (returning) {
        cout << "Choose the type of temperature you would like to convert (celsius, fahrenheit, kelvin): ";
        cin >> tempType;

        if (tempType == "celsius") {
            cout << "Your chosen temperature is celsius\n";
            cout << "Enter temperature in celsius: ";
            while (!(cin >> celsius)) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "What would you like to convert it to? (fahrenheit, kelvin): ";
            cin >> convertedtemp;
            while (convertedtemp != "fahrenheit" && convertedtemp != "kelvin") {
                cout << "Invalid input. Please enter either 'fahrenheit' or 'kelvin': ";
                cin >> convertedtemp;
            }

            if (convertedtemp == "fahrenheit") {
                fahrenheit = (9.0 / 5.0) * celsius + 32.0;
                cout << "Converted Temperature = " << fahrenheit << " Fahrenheit\n";
            }
            else if (convertedtemp == "kelvin") {
                kelvin = celsius + 273.15;
                cout << "Converted Temperature = " << kelvin << " Kelvin\n";
            }
        }

        else if (tempType == "fahrenheit") {
            cout << "Your chosen temperature is fahrenheit\n";
            cout << "Enter temperature in fahrenheit: ";
            while (!(cin >> fahrenheit)) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "What would you like to convert it to? (celsius, kelvin): ";
            cin >> convertedtemp;
            while (convertedtemp != "celsius" && convertedtemp != "kelvin") {
                cout << "Invalid input. Please enter either 'celsius' or 'kelvin': ";
                cin >> convertedtemp;
            }

            if (convertedtemp == "celsius") {
                celsius = (5.0 / 9.0) * (fahrenheit - 32.0);
                cout << "Converted Temperature = " << celsius << " Celsius\n";
            }
            else if (convertedtemp == "kelvin") {
                kelvin = (fahrenheit + 459.67) * 5.0 / 9.0;
                cout << "Converted Temperature = " << kelvin << " Kelvin\n";
            }
        }

        else if (tempType == "kelvin") {
            cout << "Your chosen temperature type is kelvin\n";
            cout << "Enter temperature in kelvin: ";
            while (!(cin >> kelvin)) {
                cout << "Invalid input. Please enter a valid number: ";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
            cout << "What would you like to convert it to? (celsius, fahrenheit): ";
            cin >> convertedtemp;
            while (convertedtemp != "celsius" && convertedtemp != "fahrenheit") {
                cout << "Invalid input. Please enter either 'celsius' or 'fahrenheit': ";
                cin >> convertedtemp;
            }

            if (convertedtemp == "celsius") {
                celsius = kelvin - 273.15;
                cout << "Converted Temperature = " << celsius << " Celsius\n";
            }
            else if (convertedtemp == "fahrenheit") {
                fahrenheit = kelvin * 9.0 / 5.0 - 459.67;
                cout << "Converted Temperature = " << fahrenheit << " Fahrenheit\n";
            }
        }

        else {
            cout << "You must enter celsius, fahrenheit or kelvin\n";
        }

        // Asking user if they want to try again
        bool retry = true;
        while (retry) {
            cout << "Would you like to try again? (y/n): ";
            char choice;
            cin >> choice;
            if (choice != 'y' && choice != 'n' && choice != 'Y' && choice != 'N') {
                cout << "Invalid entry. Please enter 'y' for yes or 'n' for no.\n";
            }
            else if (choice == 'n' || choice == 'N') {
                cout << "Thank you for using my app :D";
                return 0;
            }
            else {
                cout << "Okayy\n";
                break;
            }
        }
    }
    return 0;
}
