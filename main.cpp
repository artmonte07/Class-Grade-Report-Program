#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

struct  Gradebook {
	string firstName{};
	string lastName{};
	double test1{}, test2{}, test3{}, test4{}, finalTest{};
	double averageGrade{};
	char letterGrade{};
};

struct Gradebook students[30];


class Student {
public:
	double studentCount{};
	double studentScoreTotal{}; // keeps track of total student points

	double test1ScoreTotal{};
	double averageTest1Grade{};

	double test2ScoreTotal{};
	double averageTest2Grade{};

	double test3ScoreTotal{};
	double averageTest3Grade{};

	double test4ScoreTotal{};
	double averageTest4Grade{};

	double finalTestScoreTotal{};
	double averageFinalTestGrade{};

	double averageScoreTotal{};
	double averageGrade{};
	char averageLetterGrade{};

	double studentsHighestTestGrade{};
	double highestOverallTestGrade{};

	double highestClassGrade{};
	string highestStudentName{};

	double secondClassGrade{};
	string secondStudentName{};

	double thirdClassGrade{};
	string thirdStudentName{};

	int readFile(ifstream& inputFile, string& fileName) {
		// Inputting the file
		inputFile.open(fileName);

		if (!inputFile) {
			cerr << "Problem opening file" << endl;
			return 1;
		}
		int i{ 0 };
		// Read text file
		while (!inputFile.eof()) {
			inputFile >> students[i].firstName
				>> students[i].lastName
				>> students[i].test1
				>> students[i].test2
				>> students[i].test3
				>> students[i].test4
				>> students[i].finalTest;
			studentCount++;
			i++;
		}
		inputFile.close();
		printHeader();
		processStudent();
		printStudent();
		printFooter();
		return 0;
	}
public:
	void printHeader() {
		cout << endl;
		//cout << "123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890" << endl;
		cout << setw(16) << left << "Student Name" << setw(10) << right << "First Test" << setw(15) << right << "Second Test"
			<< setw(15) << right << "Third Test" << setw(15) << right << "Fourth Test" << setw(15) << right << "Final Test"
			<< setw(13) << right << "Average" << setw(17) << right << "Final Grade" << endl;
		cout << setw(120) << setfill('-') << "" << endl;
		cout << setfill(' ');
	}

public:
	void calcStudentAverage() {
		for (int i = 0; i < studentCount; i++) {
			studentScoreTotal = students[i].test1 + students[i].test2 + students[i].test3 + students[i].test4 + students[i].finalTest + students[i].finalTest;
			students[i].averageGrade = studentScoreTotal / 6;
		}
	}

public:
	void calcScoreTotals() {
		for (int i = 0; i < studentCount; i++) {
			test1ScoreTotal = test1ScoreTotal + students[i].test1;
			test2ScoreTotal = test2ScoreTotal + students[i].test2;
			test3ScoreTotal = test3ScoreTotal + students[i].test3;
			test4ScoreTotal = test4ScoreTotal + students[i].test4;
			finalTestScoreTotal = finalTestScoreTotal + students[i].finalTest;
			averageScoreTotal = averageScoreTotal + students[i].averageGrade;
		}

	}

public:
	void calcAverageTestGrades() {
		averageTest1Grade = test1ScoreTotal / studentCount;
		averageTest2Grade = test2ScoreTotal / studentCount;
		averageTest3Grade = test3ScoreTotal / studentCount;
		averageTest4Grade = test4ScoreTotal / studentCount;
		averageFinalTestGrade = finalTestScoreTotal / studentCount;
		averageGrade = averageScoreTotal / studentCount;
	}
public:
	void findStudentLetterGrade() {
		for (int i = 0; i < studentCount; i++) {
			if (students[i].averageGrade >= 90 && students[i].averageGrade <= 100) {
				students[i].letterGrade = 'A';
			}
			else if (students[i].averageGrade >= 80 && students[i].averageGrade < 90) {
				students[i].letterGrade = 'B';
			}
			else if (students[i].averageGrade >= 70 && students[i].averageGrade < 80) {
				students[i].letterGrade = 'C';
			}
			else if (students[i].averageGrade >= 60 && students[i].averageGrade < 70) {
				students[i].letterGrade = 'D';
			}
			else if (students[i].averageGrade >= 0 && students[i].averageGrade < 60) {
				students[i].letterGrade = 'F';
			}
			else {
				students[i].letterGrade = 'U';
			}
		}
	}
public:
	void findAverageLetterGrade() {

		if (averageGrade >= 90 && averageGrade <= 100) {
			averageLetterGrade = 'A';
		}
		else if (averageGrade >= 80 && averageGrade < 90) {
			averageLetterGrade = 'B';
		}
		else if (averageGrade >= 70 && averageGrade < 80) {
			averageLetterGrade = 'C';
		}
		else if (averageGrade >= 60 && averageGrade < 70) {
			averageLetterGrade = 'D';
		}
		else if (averageGrade >= 0 && averageGrade < 60) {
			averageLetterGrade = 'F';
		}
		else {
			averageLetterGrade = 'U';
		}
	}

public:
	void findHighestGrades() {
		for (int i = 0; i < studentCount; i++) {

			if (students[i].test1 > studentsHighestTestGrade) {
				studentsHighestTestGrade = students[i].test1;
			}
			if (students[i].test2 > studentsHighestTestGrade) {
				studentsHighestTestGrade = students[i].test2;
			}
			if (students[i].test3 > studentsHighestTestGrade) {
				studentsHighestTestGrade = students[i].test3;
			}
			if (students[i].test4 > studentsHighestTestGrade) {
				studentsHighestTestGrade = students[i].test4;
			}
			if (students[i].finalTest > studentsHighestTestGrade) {
				studentsHighestTestGrade = students[i].finalTest;
			}

			if (studentsHighestTestGrade > highestOverallTestGrade) {
				highestOverallTestGrade = studentsHighestTestGrade;
			}

			if (students[i].averageGrade > highestClassGrade) {
				thirdClassGrade = secondClassGrade;
				thirdStudentName = secondStudentName;
				secondClassGrade = highestClassGrade;
				secondStudentName = highestStudentName;
				highestClassGrade = students[i].averageGrade;
				highestStudentName = students[i].firstName + ' ' + students[i].lastName;

			}
			else if (students[i].averageGrade > secondClassGrade) {
				thirdClassGrade = secondClassGrade;
				thirdStudentName = secondStudentName;
				secondClassGrade = students[i].averageGrade;
				secondStudentName = students[i].firstName + ' ' + students[i].lastName;
			}
			else if (students[i].averageGrade > thirdClassGrade) {
				thirdClassGrade = students[i].averageGrade;
				thirdStudentName = students[i].firstName + ' ' + students[i].lastName;
			}
			//cout << highestStudentName << secondStudentName << thirdStudentName << endl;
		}
	}
public:
	void processStudent() {
		calcStudentAverage();
		calcScoreTotals();
		calcAverageTestGrades();
		findStudentLetterGrade();
		findAverageLetterGrade();
		findHighestGrades();
	}

public:
	void printStudent() {
		int i{};
		for (i = 0; i < studentCount; i++) {
			cout << setprecision(2) << fixed;
			cout << setw(15) << left << students[i].firstName + ' ' + students[i].lastName
				<< setw(8) << right << students[i].test1
				<< setw(15) << right << students[i].test2
				<< setw(15) << right << students[i].test3
				<< setw(15) << right << students[i].test4
				<< setw(15) << right << students[i].finalTest
				<< setw(15) << right << students[i].averageGrade
				<< setw(15) << right << students[i].letterGrade << endl;
		}
		cout << setw(120) << setfill('-') << "" << endl;
		cout << setfill(' ');


	}

	void printFooter() {
		cout << setprecision(2) << fixed;
		cout << setw(15) << left << "Average Scores"
			<< setw(8) << right << averageTest1Grade
			<< setw(15) << right << averageTest2Grade
			<< setw(15) << right << averageTest3Grade
			<< setw(15) << right << averageTest4Grade
			<< setw(15) << right << averageFinalTestGrade
			<< setw(15) << right << averageGrade
			<< setw(15) << right << averageLetterGrade << endl;
		cout << setw(15) << left << "Highest Test Grade:"
			<< setw(7) << right << highestOverallTestGrade << endl;
		cout << setw(15) << left << "Students with the Highest Grades:" << endl
			<< setw(15) << left << highestStudentName
			<< setw(11) << right << highestClassGrade << endl
			<< setw(15) << left << secondStudentName
			<< setw(11) << right << secondClassGrade << endl
			<< setw(15) << left << thirdStudentName
			<< setw(11) << right << thirdClassGrade << endl;
	}

	void GradeReport(ofstream& outFile) {
		outFile.open("GradeReport.txt");
		outFile << setw(16) << left << "Student Name" << setw(10) << right << "First Test" << setw(15) << right << "Second Test"
			<< setw(15) << right << "Third Test" << setw(15) << right << "Fourth Test" << setw(15) << right << "Final Test"
			<< setw(13) << right << "Average" << setw(17) << right << "Final Grade" << endl;
		outFile << setw(120) << setfill('-') << "" << endl;
		outFile << setfill(' ');

		for (int i = 0; i < studentCount; i++) {
			outFile << setprecision(2) << fixed;
			outFile << setw(15) << left << students[i].firstName + ' ' + students[i].lastName
				<< setw(8) << right << students[i].test1
				<< setw(15) << right << students[i].test2
				<< setw(15) << right << students[i].test3
				<< setw(15) << right << students[i].test4
				<< setw(15) << right << students[i].finalTest
				<< setw(15) << right << students[i].averageGrade
				<< setw(15) << right << students[i].letterGrade << endl;
		}
		outFile << setw(120) << setfill('-') << "" << endl;
		outFile << setfill(' ');

		outFile << setprecision(2) << fixed;
		outFile << setw(15) << left << "Average Scores"
			<< setw(8) << right << averageTest1Grade
			<< setw(15) << right << averageTest2Grade
			<< setw(15) << right << averageTest3Grade
			<< setw(15) << right << averageTest4Grade
			<< setw(15) << right << averageFinalTestGrade
			<< setw(15) << right << averageGrade
			<< setw(15) << right << averageLetterGrade << endl;
		outFile << setw(15) << left << "Highest Test Grade:"
			<< setw(7) << right << highestOverallTestGrade << endl;
		outFile << setw(15) << left << "Students with the Highest Grades:" << endl
			<< setw(15) << left << highestStudentName
			<< setw(11) << right << highestClassGrade << endl
			<< setw(15) << left << secondStudentName
			<< setw(11) << right << secondClassGrade << endl
			<< setw(15) << left << thirdStudentName
			<< setw(11) << right << thirdClassGrade << endl;
	}
};

	int main() {

		Student math;
		ifstream in_file;
		string fileName;
		cin >> fileName;
		math.readFile(in_file, fileName);
		ofstream out_file;
		math.GradeReport(out_file);

		return 0;
	}