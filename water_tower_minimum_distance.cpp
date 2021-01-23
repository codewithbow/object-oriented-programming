#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

vector<int> homes;
int const NUMHOMES = 3;
int xTower, yTower;
void getUserInput();
double distance(int x1, int y1, int x2, int y2);
double minDistance(vector<int> coordinates);
int maxX(vector<int> coordinates);
int maxY(vector<int> coordinates);

int main() {
	getUserInput();

	cout << fixed << showpoint << setprecision(3) << endl;
	cout << "Minimum distance is: " << minDistance(homes) << endl;
	cout << "Tower's x, y location is: (" << xTower << "," << yTower << ")" << endl;
}

void getUserInput() {
	int x, y;
	for (int i = 1; i <= NUMHOMES; i++) {
		cout << "What is the x, y location (seperated by spaces) of house #" << i << "?: ";
		cin >> x >> y;
		homes.push_back(x);
		homes.push_back(y);
	}
}

double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow((x2 - x1), 2.0) + pow((y2 - y1), 2.0));
}

int maxX(vector<int> coordinates) {
	int temp = coordinates[0];
	for (int i = 0; i < coordinates.size(); i += 2) {
		if (temp <= coordinates[i]) {
			temp = coordinates[i];
		}
	}
	return temp;
}

int maxY(vector<int> coordinates) {
	int temp = coordinates[1];
	for (int i = 0; i < coordinates.size(); i += 2) {
		if (temp <= coordinates[i]) {
			temp = coordinates[i];
		}
	}
	return temp;
}

double minDistance(vector<int> coordinates) {
	double totalDistance = 0;
	double minTotalDistance = 0;
	
	for (int i = 0; i < coordinates.size(); i += 2) {
		minTotalDistance += distance(0, 0, coordinates[i], coordinates[i + 1]);
	}

	for (int row = 1; row <= maxY(coordinates); row++) {
		for (int col = 1; col <= maxX(coordinates); col++) {
			for (int i = 0; i < coordinates.size(); i += 2) {
				totalDistance += distance(col, row, coordinates[i], coordinates[i + 1]);
			}
			if (totalDistance < minTotalDistance) {
				xTower = col;
				yTower = row;
				minTotalDistance = totalDistance;
			}
			totalDistance = 0;
		}
	}
	return minTotalDistance;
}
