#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>
#include <cstdbool>

using namespace std;

struct Student {
	string idNo;
	float carryMark;
	float quiz[3] = { 0,0,0 };
	float test, assignment, labTest, totalCarryMark, totalQuizMark = 0;
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
	case 1: totalMark / 45 * 15;
		break;
	case 2: totalMark / 50 * 25;
		break;
	case 3: totalMark / 20 * 20;
		break;
	case 4: totalMark / 10 * 10;
		break;
	}
}

void AddStudent(Student *MyStudent)
{
	int option;
	bool already[4] = { false };
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

			if (already[0] == false)
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
				already[0] = true;
			}
			else
			{
				cout << "\nQuiz mark already exists. " <<endl;
				cout << "Choose UPDATE option in MAIN MENU to update." <<endl;
			}
			break;
		
		case 2:
			if (already[1] == false)
			{
				limit = 50;
				do {
					cout << "\nEnter Test mark (50) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);
				
				cout << "Percentage of Test is " << percentCalcu(temp, 2) << "%" << endl;
				MyStudent->test = temp;
				already[1] = true;
			}
			else
			{
				cout << "\nTest mark already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		case 3:
			if (already[2] == false)
			{
				limit = 20;
				do {
					cout << "\nEnter Assignment mark (20) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);

				cout << "Percentage of Assignment is " << percentCalcu(temp, 3) << "%" << endl;
				MyStudent->assignment= temp;
				already[2] = true;
			}
			else
			{
				cout << "\nTest Assignment already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		case 4:
			if (already[3] == false)
			{
				limit = 10;
				do {
					cout << "\nEnter Lab Test mark (10) : ";
					cin >> temp;
					temp = inputCheck(temp, limit);

				} while (temp == -1);

				cout << "Percentage of Lab Test is " << percentCalcu(temp, 4) << "%" << endl;
				MyStudent->labTest = temp;
				already[3] = true;
			}
			else
			{
				cout << "\nLab Test mark already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
			break;
		}
		cout << "Add another assessment [Y/N] : ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');

}

void UpdateAssessment(vector<Student> *V1)
{
	int option;
	bool already[4] = { false }, flag = false;
	float limit, temp;
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
			
		}
	}

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
			break;
		}


		cout << "Add another assessment [Y/N] : ";
		cin >> repeat;
	} while (repeat == 'Y' || repeat == 'y');
}

int main()
{
	vector<Student>V1;
	Student MyStudent;
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
			break;
		case 2:
			UpdateAssessment(&V1);
			break;
		case 3:
			break;
		case 4:
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