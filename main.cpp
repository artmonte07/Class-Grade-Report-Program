#include "SalesRep.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;



int main() {
	SalesRep dataBase;
	ifstream in_file;
	ofstream out_file;
	string fileName;
	cin >> fileName;
	cout << endl;
	dataBase.readFile(in_file, fileName);

	char selection{};

	do {
		dataBase.printMenu();
		cout << endl;
		cin >> selection;
		cout << endl;
		switch (selection) {
		case 'R':
			dataBase.printRoster();
			cout << endl;
			break;
		case 'I':
			dataBase.printSalesRepInfo();
			cout << endl;
			break;
		case 'A':
			dataBase.addNewSalesRep();
			cout << endl;
			break;
		case 'U':
			dataBase.updateSalesRepInfo();
			cout << endl;
			break;
		case 'B':
			dataBase.calcSalesBonus();
			cout << endl;
			break;
		case 'W':
			dataBase.salesRepReport(out_file);
			cout << endl;
			break;
		case 'Q':
			cout << "Closing Program . . ." << endl;
			break;
		default:
			cout << "Try Again - Unknown command." << endl;
		}

	} while (selection != 'Q');

	//random.calcSalesBonus();
	return 0;
}