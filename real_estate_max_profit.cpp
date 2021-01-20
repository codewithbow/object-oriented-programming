#include <iostream>
using namespace std;

int numApts;
double rentAmt, increaseAmt, maintenanceAmt; 

void getUserInput();
int calcNumUnits(int numApts, double rentAmt, double increaseAmt, double maintenanceAmt);

int main() {

	getUserInput();

	int unitsMaxProfit = calcNumUnits(numApts, rentAmt, increaseAmt, maintenanceAmt);

	cout << endl << "To maximize profits, " << unitsMaxProfit << " apartments should be rented." << endl;
}

void getUserInput() {
	cout << "How many apartment units are in the complex?: ";
	cin >> numApts;
	cout << "What is the rent when all units are occupied?: ";
	cin >> rentAmt;
	cout << "What is the rent increase that results in a vacant unit?: ";
	cin >> increaseAmt;
	cout << "How much does it cost to maintain a rented unit?: ";
	cin >> maintenanceAmt;
}

int calcNumUnits(int numApts, double rentAmt, double increaseAmt, double maintenanceAmt) {
	int originalProfit = (numApts * rentAmt) - (maintenanceAmt * numApts);
	int newProfit = originalProfit;

	while (newProfit >= originalProfit) {
		originalProfit = newProfit;
		rentAmt += increaseAmt;
		numApts -= 1;
		newProfit = (numApts * rentAmt) - (maintenanceAmt * numApts);
	}

	return numApts + 1;
}
