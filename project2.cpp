#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

int main() {

	cout << "This is my rock paper scissors game" << endl;
	cout << "Player 1 choose your move: " << endl;

	bool playagain = true;
	while (playagain = true) {
		string move;
		cin >> move;


	vector<string>Aimove = { "rock", "paper", "scissors" };

	mt19937 rng(time(nullptr));

	uniform_int_distribution<int> dist(0, Aimove.size() - 1);

	int randomAimove = dist(rng);


		cout << "Player 1 choose your move: " << endl;
		cout << "player move: " << move << endl;

		cout << "Ai move: " << Aimove[randomAimove] << endl;
		;

		if (move == "rock" && Aimove[randomAimove] == "paper"
			|| move == "paper" && Aimove[randomAimove] == "scissors"
			|| move == "scissors" && Aimove[randomAimove] == "rock") {
			cout << "Ai wins!!" << endl;
		}
		else if (move == "paper" && Aimove[randomAimove] == "rock"
			|| move == "scissors" && Aimove[randomAimove] == "paper"
			|| move == "rock" && Aimove[randomAimove] == "scissors") {
			cout << "Player 1 wins" << endl;
		}

		else {
			cout << "ITS A TIE" << endl;
		}

		char playChoice;
		cout << "Would you like to play again? (Y/N)";
		cin >> playChoice;
		if (playChoice == 'Y' || playChoice == 'y') {
			playagain = true;
			cout << "choose move:";
		}

		else if (playChoice == 'N' || playChoice == 'n'){
			playagain = false;
			cout << "Thank you for playing";
			return 0;
		}
	}
		


	return 0;

}