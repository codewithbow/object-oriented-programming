#include <iostream>
#include <vector>
using namespace std;

int factor(int num);
vector<int> perfectNums();

int main() {

	int num;

	cout << "How many Pefect Numbers do you want to see? (From 1 to 4): ";
	cin >> num;

	for (int i = 0; i < num; i++) {
		cout << perfectNums()[i] << endl;
	}

}

int factor(int num) {
	int sum = 0;
	int temp = num - 1;

	for (int counter = 1; counter < num; counter += 1) {
		if (num % temp == 0) {
			sum += temp;
		}
		temp -= 1;
	}
	return sum;
}

vector<int> perfectNums() {
	vector<int> perfectNums;
	for (int i = 1; i < 10000; i++) {
		if (factor(i) == i) {
			perfectNums.push_back(i);
		}
	}
	return perfectNums;
}
