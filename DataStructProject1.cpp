#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstdbool>
#include <fstream>
#include <iomanip>

using namespace std;

struct Student {
	string idNo;
	float carryMark;
	float quiz[3] = { 0,0,0 };
	float test, assignment, labTest, totalCarryMark, totalQuizMark = 0;
	bool already[4] = { false };
};

void ShowMenu()
{
	cout << "\nCARRY MARK PROGRAM" << endl;
	cout << "[1] Add New Student" << endl;
	cout << "[2] Update New Assessment" << endl;
	cout << "[3] Carry Mark Summary" << endl;
	cout << "[4] Carry Mark Summary (Save to File)" << endl;
	cout << "[5] Exit " << endl;
}	

int inputCheck(float temp, float limit)
{
	if (cin.fail()) {
		cin.clear();
		cin.sync();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		temp = -1;
	}
	if (temp == -1 || temp > limit || temp < 0)
	{
		cout << "\nPlease enter number within 0 - " << limit << " only " << endl;
		temp = -1;
	}
	return temp;
}

//option: 1-quiz, 2-test, 3-assignment, 4-labTest
float percentCalcu(float totalMark, int option)
{
	switch (option)
	{
	case 1: return totalMark / 45 * 15;
		break;
	case 2: return totalMark / 50 * 25;
		break;
	case 3: return totalMark / 20 * 20;
		break;
	case 4: return totalMark / 10 * 10;
		break;
	}
}

void AddStudent(Student *MyStudent)
{
	int option;
	float limit,temp;
	char repeat = 'Y';
	cout << "\nEnter student ID : ";
	cin >> ws;
	getline(cin, MyStudent->idNo);

	do {
		cout << "\nAssessment Menu :" << endl;
		cout << "[1] Quiz " << endl;
		cout << "[2] Test " << endl;
		cout << "[3] Assignment " << endl;
		cout << "[4] Lab Test " << endl;
		cout << "Select option :";
		cin >> option;

		switch (option)
		{
		case 1:

			if (MyStudent->already[0] == false)
			{
				limit = 15;
				for (int i = 0; i < sizeof(MyStudent->quiz) / sizeof(MyStudent->quiz[0]); i++)
				{
					do {
						cout << "Enter Quiz [" << i + 1 << "] mark (15) : ";
						cin >> temp;
						temp = inputCheck(temp, limit);
							
					} while (temp == -1);

					MyStudent->quiz[i] = temp;
					MyStudent->totalQuizMark += temp;
				}
			
				cout << "Total Quiz mark (45m) : " << MyStudent->totalQuizMark << endl;
				cout << "Percentage of Quiz is " << percentCalcu(MyStudent->totalQuizMark, 1) << "%" << endl;
				MyStudent->already[0] = true;
			}
			else
			{
				cout << "\nQuiz mark already exists. " <<endl;
				cout << "Choose UPDATE option in MAIN MENU to update." <<endl;
			}
			break;
		
		case 2:
			if (MyStudent->already[1] == false)
			{
				limit = 50;
				do {
					cout << "\nEnter Test mark (50) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);
				
				cout << "Percentage of Test is " << percentCalcu(temp, 2) << "%" << endl;
				MyStudent->test = temp;
				MyStudent->already[1] = true;
			}
			else
			{
				cout << "\nTest mark already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		case 3:
			if (MyStudent->already[2] == false)
			{
				limit = 20;
				do {
					cout << "\nEnter Assignment mark (20) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);

				cout << "Percentage of Assignment is " << percentCalcu(temp, 3) << "%" << endl;
				MyStudent->assignment= temp;
				MyStudent->already[2] = true;
			}
			else
			{
				cout << "\nTest Assignment already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		case 4:
			if (MyStudent->already[3] == false)
			{
				limit = 10;
				do {
					cout << "\nEnter Lab Test mark (10) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);

				cout << "Percentage of Lab Test is " << percentCalcu(temp, 4) << "%" << endl;
				MyStudent->labTest = temp;
				MyStudent->already[3] = true;
			}
			else
			{
				cout << "\nLab Test mark already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		default:
			cout << "\nEnter value [1-4] only" << endl;
		}
		cout << "Add another assessment [Y/N] : ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');

}

void UpdateAssessment(vector<Student> *V1)
{
	int option, tempOption;
	bool flag = false;
	float limit, tempInput;
	char repeat = 'Y';
	string  tempID;
	cout << "\nEnter student ID : ";
	cin >> ws;
	getline(cin, tempID);

	vector<Student>::iterator itr;
	for (itr = V1->begin(); itr != V1->end(); itr++)
	{
		if (itr->idNo == tempID)
		{
			flag = true;
			break;
		}
	}

	if (flag == true)
	{
		do {
			cout << "\nAssessment Menu :" << endl;
			cout << "[1] Quiz " << endl;
			cout << "[2] Test " << endl;
			cout << "[3] Assignment " << endl;
			cout << "[4] Lab Test " << endl;
			cout << "Select option :";
			cin >> option;

			switch (option)
			{
			case 1: limit = 15;
				cout << "\n\nQuiz 1 mark (15) : " << itr->quiz[0] << endl;
				cout << "Quiz 2 mark (15) : " << itr->quiz[1] << endl;
				cout << "Quiz 3 mark (15) : " << itr->quiz[2] << endl;
				cout << "Current Percenage of Quiz : " << percentCalcu(itr->totalQuizMark, 1) << "%" << endl;

				cout << "\nEnter Quiz No to update [1 to 3]: ";
				cin >> tempOption;

				itr->totalQuizMark -= itr->quiz[tempOption-1];

				do {
					cout << "\nEnter Quiz " << tempOption << " mark (15) : ";
					cin >> tempInput;
					tempInput = inputCheck(tempInput, limit);

				} while (tempInput == -1);

				itr->quiz[tempOption-1] = tempInput;
				itr->totalQuizMark += itr->quiz[tempOption-1];

				cout << "\nNew Total Quiz mark (45): " << itr->totalQuizMark << endl;
				cout << "New Percentage of Quiz is " << percentCalcu(itr->totalQuizMark, 1) << "%" << endl;
				break;

			case 2:limit = 50;
				cout << "\n\nCurrent Test mark (50) : " << itr->test << endl;

				do {
					cout << "\nEnter new Test mark (50) : ";
					cin >> tempInput;
					tempInput = inputCheck(tempInput, limit);

				} while (tempInput == -1);

				itr->test = tempInput;
				cout << "\nNew Test mark (50): " << itr->test << endl;
				cout << "New Percentage of Test is " << percentCalcu(itr->test, 2) << "%" << endl;
				break;
			case 3:limit = 20;
				cout << "\n\nCurrent Assignment mark (20) : " << itr->assignment << endl;

				do {
					cout << "\nEnter new Assignment mark (20) : ";
					cin >> tempInput;
					tempInput = inputCheck(tempInput, limit);

				} while (tempInput == -1);

				itr->assignment = tempInput;
				cout << "\nNew Assignment mark (20): " << itr->assignment << endl;
				cout << "New Percentage of Assignment is " << percentCalcu(itr->assignment, 3) << "%" << endl;
				break;
			case 4:limit = 10;
				cout << "\n\nCurrent Lab Test mark (10) : " << itr->labTest << endl;

				do {
					cout << "\nEnter new Lab Test mark (10) : ";
					cin >> tempInput;
					tempInput = inputCheck(tempInput, limit);

				} while (tempInput == -1);

				itr->labTest = tempInput;
				cout << "\nNew Lab Test mark (10): " << itr->labTest << endl;
				cout << "New Percentage of Lab Test is " << percentCalcu(itr->labTest, 3) << "%" << endl;
				break;
			default:
				cout << "\nEnter value [1-4] only" << endl;
			}


			cout << "Add another assessment [Y/N] : ";
			cin >> repeat;
		} while (repeat == 'Y' || repeat == 'y');
	}
	else
	{
		cout << "Student ID do not exist" << endl;
	}
}

void Summary(vector<Student>* V1)
{
	int option, tempOption, total = 0;
	bool flag = false;
	float limit, tempInput;
	char repeat = 'Y';
	string  tempID;
	cout << "\nDisplay Menu :" << endl;
	cout << "[1] Individual " << endl;
	cout << "[2] All " << endl;
	cout << "[3] Highest carry mark " << endl;
	cout << "Select option :";
	cin >> option;
	vector<Student>::iterator itr;

	switch (option)
	{
	case 1:
		cout << "\nEnter student ID : ";
		cin >> ws;
		getline(cin, tempID);
		for (itr = V1->begin(); itr != V1->end(); itr++)
		{
			if (itr->idNo == tempID)
			{
				flag = true;
				break;
			}
		}
		if (flag == true)
		{
			itr->totalCarryMark = percentCalcu(itr->totalQuizMark, 1) + percentCalcu(itr->test, 2) + percentCalcu(itr->assignment, 3) + percentCalcu(itr->labTest, 3);
			cout << "\n::Carry Mark Details::" << endl;
			cout << "Student ID                 : " << itr->idNo << endl;
			cout << "Quiz                       : " << percentCalcu(itr->totalQuizMark, 1) << "%" << endl;
			cout << "Test                       : " << percentCalcu(itr->test, 2) << "%" << endl;
			cout << "Assignment                 : " << percentCalcu(itr->assignment, 3) << "%" << endl;
			cout << "Lab Test                   : " << percentCalcu(itr->labTest, 3) << "%" << endl;
			cout << "Total Carry Mark           : " << itr->totalCarryMark << "%" << endl;
			cout << "\nEnd of Summary" << endl;
			break;
		}
		else
		{
			cout << "Student ID do not exist" << endl;
		}

	case 2:
		cout << "\n::Carry Mark Details::" << endl;
		for (itr = V1->begin(); itr != V1->end(); itr++)
		{
			itr->totalCarryMark = percentCalcu(itr->totalQuizMark, 1) + percentCalcu(itr->test, 2) + percentCalcu(itr->assignment, 3) + percentCalcu(itr->labTest, 3);
			cout << "Student ID                 : " << itr->idNo << endl;
			cout << "Quiz                       : " << percentCalcu(itr->totalQuizMark, 1) << "%" << endl;
			cout << "Test                       : " << percentCalcu(itr->test, 2) << "%" << endl;
			cout << "Assignment                 : " << percentCalcu(itr->assignment, 3) << "%" << endl;
			cout << "Lab Test                   : " << percentCalcu(itr->labTest, 3) << "%" << endl;
			cout << "Total Carry Mark           : " << itr->totalCarryMark << "%\n" << endl;
		}
		cout << "\nEnd of Summary" << endl;
		break;

	case 3:

		cout << "\n::Carry Mark Details::" << endl;
		float tempCarry = 0;
		for (itr = V1->begin(); itr != V1->end(); itr++)
		{
			itr->totalCarryMark = percentCalcu(itr->totalQuizMark, 1) + percentCalcu(itr->test, 2) + percentCalcu(itr->assignment, 3) + percentCalcu(itr->labTest, 3);
			if (itr->totalCarryMark > tempCarry)
			{
				tempCarry = itr->totalCarryMark;
			}
		}
		for (itr = V1->begin(); itr != V1->end(); itr++)
		{
			if (itr->totalCarryMark == tempCarry)
			{
				cout << "Student ID                 : " << itr->idNo << endl;
				cout << "Quiz                       : " << percentCalcu(itr->totalQuizMark, 1) << "%" << endl;
				cout << "Test                       : " << percentCalcu(itr->test, 2) << "%" << endl;
				cout << "Assignment                 : " << percentCalcu(itr->assignment, 3) << "%" << endl;
				cout << "Lab Test                   : " << percentCalcu(itr->labTest, 3) << "%" << endl;
				cout << "Total Carry Mark           : " << itr->totalCarryMark << "%\n" << endl;
			}
		}
		cout << "\nEnd of Summary" << endl;
		break;
	default:
		cout << "";
	}
}

void OutputToFile(vector<Student> *V1)
{
	string fileName;
	ofstream fileOutput;
	cout << "\nEnter file name: ";
	cin >> ws;
	getline(cin, fileName);
	fileOutput.open(fileName + ".txt");
	
	vector<Student>::iterator itr;
	fileOutput << left << setprecision(2) << fixed;
	fileOutput << setw(15) << "StudentID" << setw(15) << "Quiz" << setw(15) << "Test" << setw(15) << "Assignment" << setw(15) << "LabTest" << setw(15) << "Total" << setw(15) << endl;
	
	for (itr = V1->begin(); itr != V1->end(); itr++)
	{
		itr->totalCarryMark = percentCalcu(itr->totalQuizMark, 1) + percentCalcu(itr->test, 2) + percentCalcu(itr->assignment, 3) + percentCalcu(itr->labTest, 4);
		fileOutput << left;
		fileOutput << setw(15) << itr->idNo << setw(15) << percentCalcu(itr->totalQuizMark, 1) << setw(15) << percentCalcu(itr->test, 2) << setw(15) << percentCalcu(itr->assignment, 3) << setw(15) << percentCalcu(itr->labTest, 4) << setw(15) << itr->totalCarryMark << setw(15) << endl;
	}
	fileOutput.close();
	cout << "File " << fileName << ".txt is saved" << endl;
}

int main()
{
	vector<Student>V1;
	Student MyStudent, reset;
	int option;

	do {
		ShowMenu();
		cout << " Select Menu : ";
		cin >> option;
		switch (option)
		{
		case 1:
			AddStudent(&MyStudent);
			V1.push_back(MyStudent);
			MyStudent = reset;
			break;
		case 2:
			UpdateAssessment(&V1);			//todo: check if already is true
			break;
		case 3:
			Summary(&V1);
			break;
		case 4:
			OutputToFile(&V1);			//todo: maybe check for data existance before output
			break;
		case 5:
			break;
		default:
			cout << "\n Please Enter numbers from 1 to 5 only " << endl;
			break;
		}
	} while (option !=5);

	return 0;
}