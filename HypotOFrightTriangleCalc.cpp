#include <iostream>
#include <cmath>
using namespace std;

int main() {

	cout << "Calculates the hypothenuse of a right triangle" << endl;
	cout << "Formula: C = SQRT(a^2 + b^2) " << endl;

	double a, b, c;
	cout << "Enter first Number: " << endl;
		cin >> a;
		cout << "Enter second number" << endl;
		cin >> b;

		c = sqrt(pow(a, 2) + pow(b, 2));

		cout << "The result: " << c;
	return 0;
}

