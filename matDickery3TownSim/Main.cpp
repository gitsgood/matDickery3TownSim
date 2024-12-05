#include "Town.h"

using namespace std;

void main() {
	vector<Inhabitant> Town;
	int year = 0;
    int passedYears;

	scrollingText(introduction);
	printAll(Town, year);
	scrollingText(invitation);
	scrollingText(explanation);
	Town.push_back(Inhabitant(1, genderAssignment())); Town.push_back(Inhabitant(1, genderAssignment()));
	scrollingText(inputBait);
    while (true) {
        if (cin >> passedYears) {
            year = year + passedYears;
            break;
        }
        else {
            cout << "Input is measured in integers.\n";
            cout << "\tAttempt an input again...\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    yearPassing(passedYears, Town);
    printAll(Town, year);
}