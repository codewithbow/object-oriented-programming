#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void getUserInput();
void addFractions(int numerator1, int denominator1, int numerator2, int denominator2);
int gcd(int numerator, int denominator);

int numerator1, denominator1, numerator2, denominator2;

int main() {

	getUserInput();
	cout << endl;

	cout << numerator1 << "/" << denominator1 << " + " << numerator2 << "/" << denominator2 << " = ";
	addFractions(numerator1, denominator1, numerator2, denominator2);
	cout << endl;
}

void getUserInput() {
	cout << "Enter numerator 1: ";
	cin >> numerator1;
	cout << "Enter denominator 1: ";
	cin >> denominator1;
	cout << endl;
	cout << "Enter numerator 2: ";
	cin >> numerator2;
	cout << "Enter denominator 2: ";
	cin >> denominator2;
}

void addFractions(int numerator1, int denominator1, int numerator2, int denominator2) {
	int combinedNumerator = numerator1 * denominator2 + numerator2 * denominator1;
	int commonDenominator = denominator1 * denominator2;
	
	if (combinedNumerator == commonDenominator) {
		cout << "1";
	}
	else {
		int divisor = gcd(combinedNumerator, commonDenominator);
		int newNumerator = combinedNumerator / divisor;
		int newDenominator = commonDenominator / divisor;

		if (newNumerator > newDenominator) {
			int wholeNum = newNumerator / newDenominator;
			newNumerator = newNumerator - (wholeNum * newDenominator);
			cout << to_string(wholeNum) + " " + to_string(newNumerator) + "/" + to_string(newDenominator);
		}
		else {
			cout << to_string(newNumerator) << "/" << to_string(newDenominator);
		}
	}
}

int gcd(int num1, int num2) {
	int max = std::max(num1, num2);
	int min = std::min(num1, num2);
	int remainder = max % min;
	int factor = remainder;

	while (remainder != 0) {
		factor = remainder;
		remainder = min % remainder;
		min = factor; 
	}
	return factor;
}