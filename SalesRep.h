#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
struct salesRep {
	string firstName{};
	string lastName{};
	string shortAddress{};
	double salesToDate{};
};

vector <salesRep> salesReps{ 10 };

class SalesRep {
public:
	void printMenu() {
		cout << "R - Print Sales Rep Roster" << endl
			<< "I - Print Sales Rep Info" << endl
			<< "A - Add New Sales Rep" << endl
			<< "U - Update Sales Rep Info" << endl
			<< "B - Find who gets the Sale Bonus" << endl
			<< "W - Export to a File" << endl
			<< "Q - Quit" << endl;
	}
	// reads salesRep file
public:
	int readFile(ifstream& inputFile, string& fileName) {
		inputFile.open(fileName);
		if (!inputFile) {
			cerr << "Problem opening file" << endl;
			return 1;
		}
		int i{};
		while (!inputFile.eof()) {
			for (i = 0; i < 10; i++) {
				inputFile >> salesReps[i].firstName;
				inputFile >> salesReps[i].lastName;
				inputFile >> salesReps[i].shortAddress;
				inputFile >> salesReps[i].salesToDate;
			}
		}
		inputFile.close();
		return 0;
	}
public:
	// print current salesReps
	void printRoster() {

		for (int i = 0; i < salesReps.size(); i++) {
			cout << salesReps[i].firstName << " " << salesReps[i].lastName << endl;

		}
	}
	// print salesReps info
public:
	void printSalesRepInfo() {
		//cout << "12345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		for (int i = 0; i < salesReps.size(); i++) {
			cout << setprecision(2) << fixed;
			cout << setw(20) << left << salesReps[i].firstName + " " + salesReps[i].lastName
				<< setw(30) << left << salesReps[i].shortAddress
				<< setw(4) << right << salesReps[i].salesToDate << endl;
		}
	}
	// add new sales rep
public:
	void addNewSalesRep() {
		salesReps.push_back(salesRep());
		cout << "Enter Sales Rep Info" << endl;
		int index = salesReps.size() - 1;
		cin >> salesReps[index].firstName;
		cin >> salesReps[index].lastName;
		cin >> salesReps[index].shortAddress;
		cin >> salesReps[index].salesToDate;
	}
public:
	int findSalesRep(string& firstName, string& lastName) {
		for (int i = 0; i < salesReps.size(); i++) {
			if (salesReps[i].firstName == firstName) {
				if (salesReps[i].lastName == lastName) {
					return i;
				}
			}
		}
		return -1;
	}
	// update salesrep info
public:
	void updateSalesRepInfo() {
		string firstName{};
		string lastName{};
		int index{};
		cout << "Enter first and last name: " << endl;
		cin >> firstName;
		cin >> lastName;
		index = findSalesRep(firstName, lastName);

		if (index == -1) {
			cout << "Sales Rep not found" << endl;
		}
		else {
			cout << "Enter short address" << endl;
			cin >> salesReps[index].shortAddress;
			cout << "Enter sales to date" << endl;
			cin >> salesReps[index].salesToDate;
		}

	}
	// calculate sales bonus
public:
	void calcSalesBonus() {
		int mostSales{};
		int index{};
		for (int i = 0; i < salesReps.size(); i++) {
			if (salesReps[i].salesToDate > mostSales) {
				mostSales = salesReps[i].salesToDate;
				index = i;
			}
		}
		cout << salesReps[index].firstName << " " << salesReps[index].lastName << " is receiving the Sales Bonus" << endl;
	}
	// write salesrep info to a file
public:
	void salesRepReport(ofstream& outFile) {
		outFile.open("SalesRepReport.txt");
		for (int i = 0; i < salesReps.size(); i++) {
			outFile << setprecision(2) << fixed;
			outFile << setw(20) << left << salesReps[i].firstName + " " + salesReps[i].lastName
				<< setw(30) << left << salesReps[i].shortAddress
				<< setw(4) << right << salesReps[i].salesToDate << endl;
		}
	}
};