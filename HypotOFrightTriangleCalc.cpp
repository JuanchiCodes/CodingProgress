#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cout << "Calculates the hypothenuse of a right triangle" << endl;
	cout << "Formula: C = SQRT(a^2 + b^2) " << endl;

	double a, b, c;
	cout << "Enter size A: " << endl;
		cin >> a;
		cout << "Enter size B: " << endl;
		cin >> b;

		c = sqrt(pow(a, 2) + pow(b, 2));

		cout << "Side C: " << c;
	return 0;
}

