#include<iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <random>

using namespace std;


void mainMenu();
void addingSong();
void removingSong();

vector<string> listOfsongs = {};


// Function for adding a song to the playlist
void addingSong() {
	string songs;
	cout << endl;

	cout << "Okay which song would you like to add?" << endl;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	getline(cin, songs); // Prompt user for input using getline to handle spaces.
	listOfsongs.push_back(songs); // Add the song to the back of the 'listOfsongs' vector.

	cout << "The song " << '"' << songs << '"' << " has been added." << endl << endl;
	mainMenu(); // Return to the main menu.
	cout << endl;
}

// Function for removing a song from the playlist
void removingSong() {
	if (listOfsongs.empty()) { // Check if the vector is empty.
		cout << "The list of songs is empty already." << endl;
	}

	else {
		cout << "Playlist\n" << endl;
		for (string currentSong : listOfsongs) { // Print out the current playlist.
			cout << currentSong << " " << endl;
		}

		cout << "Choose a song to remove please." << endl;
		string removedSong;
		cin.ignore(); // Clear previous input to avoid issues with getline.
		getline(cin, removedSong);

		auto it = find(listOfsongs.begin(), listOfsongs.end(), removedSong);  // Find the song to remove.
		if (it != listOfsongs.end()) {
			listOfsongs.erase(it); // Remove the song from the vector.
			cout << "The song " << '"' << removedSong << '"' << " has been removed." << endl << endl;
			cout << "Playlist\n" << endl;
			for (string currentSong : listOfsongs) {
				cout << currentSong << " " << endl << endl;
			}

			mainMenu(); // Return to the main menu.
			cout << endl;
		}
		else {
			cout << "This song is not in the list." << endl;
		}

	}

}

// Function to shuffle and play a random song from the playlist
void shuffleSongs() {
	if (!listOfsongs.empty()) { // Check if the playlist is not empty.

		cout << "Shuffling playlist..." << endl << endl;
		mt19937 rng(time(nullptr)); // Initialize random number generator.

		uniform_int_distribution<int> dist(0, static_cast<int>(listOfsongs.size()) - 1); // Uniform distribution for selecting a random song index.

		int randomSong = dist(rng); // Generate a random index.

		cout << "The song " << '"' << listOfsongs[randomSong] << '"' << " is now playing" << endl << endl;
		mainMenu(); // Return to the main menu.
	}
	else {
		cout << "Can't shuffle songs, the list is empty." << endl;
		mainMenu(); // Return to the main menu.
		cout << endl;

	}

}

// Main menu function to interact with the user
void mainMenu() {
	cout << "What would you like to do?" << endl;
	cout << "Add a song.\n";
	cout << "Remove song.\n";
	cout << "View songs.\n";
	cout << "Shuffle songs. \n";
	cout << "Play song (in progress.....)" << endl;
	cout << "Quit application\n";

	string action;
	cin >> action;

	transform(action.begin(), action.end(), action.begin(), ::toupper);  // Convert user input to uppercase for case-insensitive comparison.

	if (action == "ADD") {
		addingSong(); // Call addingSong function.

	}
	else if (action == "REMOVE") {
		removingSong(); // Call removingSong function.
	}

	else if (action == "SHUFFLE") {
		shuffleSongs(); // Call shuffleSongs function.
	}

	else if (action == "QUIT") {
		cout << "Thank you for using the app :D";
		return; // Exit the program.
	}
	else if (action == "VIEW") {
		if (listOfsongs.empty()) {
			cout << "The list is empty at the moment" << endl;
			mainMenu(); // Return to the main menu if the playlist is empty.
			cout << endl;
		}
		else {
			cout << "Displaying current Song list:" << endl;
			for (string currentSong : listOfsongs) {
				cout << currentSong << " " << endl << endl;
			}
			mainMenu(); // Return to the main menu.
			cout << endl;
		}

	}

	else {
		cout << "Invalid input. Please enter: 'add', 'remove', 'view', 'shuffle' or 'quit'" << endl;
		mainMenu(); // Return to the main menu for invalid input.
	}
}

// Entry point of the program
int main() {
	cout << "Music application" << endl;
	mainMenu(); // Start the main menu.

	return 0; // Exit the program.
}
