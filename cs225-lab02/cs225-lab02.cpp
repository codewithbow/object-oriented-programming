#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int userNumToBeSquared, userNumToBeCubed;
	int userNum1, userNum2;
	int squaredResult, cubedResult, modulusResult;

	cout << "Enter an integer to be squared: ";
	cin >> userNumToBeSquared;
	squaredResult = pow(userNumToBeSquared, 2);
	cout << userNumToBeSquared << " squared equals " << squaredResult << endl;
	cout << endl;

	cout << "Enter an integer to be cubed: ";
	cin >> userNumToBeCubed;
	cubedResult = pow(userNumToBeCubed, 3);
	cout << userNumToBeCubed << " cubed equals " << cubedResult << endl;
	cout << endl;

	cout << "Enter integer 1: ";
	cin >> userNum1;
	cout << "Enter integer 2: ";
	cin >> userNum2;
	modulusResult = userNum1 % userNum2;
	cout << "The remainder of " << userNum1 << " divided by " << userNum2 << " equals " << modulusResult << endl;
}