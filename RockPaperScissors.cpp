#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

int main() {
	// Introduction to the game
	cout << "This is my rock paper scissors game" << endl;
	cout << "Player 1 choose your move: " << endl;

	// Variable to control whether to play again
	bool playagain = true;
	while (playagain) {
		// Player's move
		string move;
		cin >> move;

		// Possible moves for AI
		vector<string> Aimove = { "rock", "paper", "scissors" };

		// Random number generator initialization
		mt19937 rng(time(nullptr));

		// Distribution for selecting AI's move
		uniform_int_distribution<int> dist(0, Aimove.size() - 1);

		// Generate random index for AI's move
		int randomAimove = dist(rng);

		// Displaying player and AI moves
		cout << "Player 1 choose your move: " << endl;
		cout << "Player's move: " << move << endl;
		cout << "AI's move: " << Aimove[randomAimove] << endl;

		// Determining the winner
		if ((move == "rock" && Aimove[randomAimove] == "paper") ||
			(move == "paper" && Aimove[randomAimove] == "scissors") ||
			(move == "scissors" && Aimove[randomAimove] == "rock")) {
			cout << "AI wins!!" << endl;
		}
		else if ((move == "paper" && Aimove[randomAimove] == "rock") ||
				 (move == "scissors" && Aimove[randomAimove] == "paper") ||
				 (move == "rock" && Aimove[randomAimove] == "scissors")) {
			cout << "Player 1 wins" << endl;
		}
		else if (move == Aimove[randomAimove]) {
			cout << "IT'S A TIE" << endl;
		}
		else {
			cout << "Invalid input by player";
			return 0;
		}

		// Asking if the player wants to play again
		char playChoice;
		cout << "Would you like to play again? (Y/N)";
		cin >> playChoice;
		if (playChoice == 'Y' || playChoice == 'y') {
			playagain = true;
			cout << "Choose move (rock/paper/scissors)";
		}
		else if (playChoice == 'N' || playChoice == 'n') {
			playagain = false;
			cout << "Thank you for playing :D";
			return 0;
		}
		else {
			cout << "Invalid input by player";
			return 0;
		}
	}

	return 0;
}
