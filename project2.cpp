#include <iostream>
#include <random>
#include <vector>
#include <ctime>

using namespace std;

int main() {

	cout << "This is my number guessing game" << endl;

	int number;
	bool retry = true;
	int tries = 3;

	while (retry == true) {

		cout << "Player choose your random number: ";

		if (!(cin >> number)){
			cout << "Invalid input";
			return 0;
		}


		vector<int>randnumbers = { 1,2,3,4,5,6,7,8,9,10 };

		mt19937 rng(time(nullptr));

		uniform_int_distribution<int> dist(0, randnumbers.size() - 1);

		int randomindex = dist(rng);

		cout << "The random number is: " << randnumbers[randomindex] << endl;


		if (number == randnumbers[randomindex]) {
			cout << "Yayyy you got it right" << endl;
			cout << "thank you for playing!!!";
			return 0;
		}

		else if (number != randnumbers[randomindex]) {
			cout << "Awwww you got it wrong" << endl;
		}

		else {
			cout << "invalid input by player :(";
			retry = false;
			return 0;
		}

		char answer;

		cout << "would you like to try again?(Y/N)" << endl;

		cin >> answer;


		if (answer == 'Y' || answer == 'y') {
			tries--;
			if (tries == 0) {
				cout << "Out of tries, thank you for playing :D";
				break;
				cout << "Okay lets try again" << endl;
			}
		}

		else if (answer == 'N' || answer == 'n') {
			cout << "Thank you for playing :D";
			return 0;
		}
		else if (answer != 'N' && answer != 'n' && answer != 'y' && answer != 'Y') {
			cout << "invalid input, try again" << endl;

		}
		cout << "you have " << tries << "/ 3 " << "tries" << endl;
	}


		return 0;
	}

