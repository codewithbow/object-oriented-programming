#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

string input = "";
void getUserInput();
int binToInt(int binNum);
vector<int> convertStringToBinNums(string line);
string outputConverted(vector<int> binNums);

int main() {
	getUserInput();
	vector<int> binaryNumsAsInts = convertStringToBinNums(input);
	cout << outputConverted(binaryNumsAsInts);
}

void getUserInput() {
	cout << "Enter a series of eight-digit binary numbers separated by spaces: ";
	getline(cin, input);
}

int binToInt(int binNum) {
	int sum = 0;
	int temp = binNum;

	for (int i = 0; i < to_string(binNum).length(); i++) {
		int rightmostNum = temp % 10;
		sum += rightmostNum * (pow(2, i));
		temp /= 10;
	}
	return sum;
}

vector<int> convertStringToBinNums(string line) {
	vector<int> binaryNums;
	string numAsString = "";
	int index = 0;
	int counter = 0;

	while (counter < line.length()) {
		numAsString = line.substr(index + 1, line.find(" ", index) - 1);
		binaryNums.push_back(stoi(numAsString));
		index = line.find(" ", index) + 1;
		counter += 9;
		numAsString = "";
	}
	return binaryNums;
}

string outputConverted(vector<int> binNums) {
	string output = "";
	for (int i : binNums) {
		output += static_cast<char>(binToInt(i));
	}
	return output;
}
