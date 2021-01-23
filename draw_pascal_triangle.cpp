#include<iostream>
#include<string>
using namespace std;

int input;
void getUserInput();
int factorial(int num);
int pascalNum(int row, int elem);
void drawTriangle(int rows);

int main() {
	getUserInput();
	drawTriangle(input);
}

void getUserInput() {
	cout << "Enter an integer form 1 to 10: ";
	cin >> input;
	while (input < 1 || input > 10) {
		cout << "Invaid input. Please try again." << endl << endl;
		cout << "Enter an integer form 1 to 10: ";
		cin >> input;
	}
}

int factorial(int num) {
	if (num > 1) {
		return num * factorial(num - 1);
	}
	else {
		return 1;
	}
}

int pascalNum(int row, int elem) {
	return factorial(row) / (factorial(elem) * factorial(row - elem));
}

void drawTriangle(int rows) {
	int spacesBefore = rows * 2;
	int rowCounter = 0;

	while (rowCounter < rows) {
		for (int i = 0; i < spacesBefore; i++) {
			cout << " ";
		}
		for (int i = 0; i <= rowCounter; i++) {
			int pNum = pascalNum(rowCounter, i);
			cout << pNum;
			if (to_string(pNum).length() == 1) {
				cout << "   ";
			}
			else if (to_string(pNum).length() == 2) {
				cout << "  ";
			}
			else if (to_string(pNum).length() == 3) {
				cout << " ";
			}
		}
		spacesBefore -= 2;
		rowCounter += 1;
		cout << endl;
	}
}
