#include <iostream>
#include <string>
#include <vector>
using namespace std;

string convertDigits(int digits);

vector<string> teensPlace = { "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen" };

vector<string> onesPlace = { "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

vector<string> tensPlace = { "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety" };

int main() {

	int userNum;
	int tempNum;
	string output = "";

	cout << "Enter a positive integer: ";
	cin >> userNum;

	while (userNum >= 2147483647) {
		cin.clear();
		cin.ignore(numeric_limits<std::streamsize>::max(), '\n');
		cout << "Invalid input! Please try again!" << endl;
		cout << endl << "Enter an integer: ";
		cin >> userNum;
	}

	tempNum = userNum;

	if (tempNum >= 1000000000) {
		output += convertDigits(tempNum / 1000000000) + " billion ";
		tempNum %= 1000000000;
	}

	if (tempNum >= 1000000) {
		output += convertDigits(tempNum / 1000000) + " million ";
		tempNum %= 1000000;
	}

	if (tempNum >= 1000) {
		output += convertDigits(tempNum / 1000) + " thousand ";
		tempNum %= 1000;
	}
	
	output += convertDigits(tempNum);

	cout << endl << output << " dollars" << endl;
}

string convertDigits(int digits) {

	string digitsAsString = "";
	int indexer;
	int nextNum = digits;

	if (to_string(nextNum).length() == 3) {
		digitsAsString += onesPlace[nextNum / 100] + " hundred ";
		nextNum %= 100;
	}

	if (to_string(nextNum).length() == 2) {
		if (nextNum >= 10 && nextNum < 20) {
			digitsAsString += teensPlace[nextNum % 10];
			return digitsAsString;
		}
		else {
			digitsAsString += tensPlace[nextNum / 10] + " ";
			nextNum %= 10;
		}
	}

	digitsAsString += onesPlace[nextNum];
	return digitsAsString;
}
