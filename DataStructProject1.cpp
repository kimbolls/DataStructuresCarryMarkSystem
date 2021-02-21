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
	float test, assignment, labTest, totalCarryMark;
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
						if (cin.fail()) {
							cin.clear();
							cin.sync();
							cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							temp = -1;
						}
						if (temp == -1 || temp > limit || temp < 0)
						{
							cout << "\nPlease enter number within 0 - 15 only " << endl;
							temp = -1;
						}
							
					} while (temp == -1);

					MyStudent->quiz[i] = temp;

					
				}
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
				cout << "\nEnter Test mark (50) : ";
				cin >> MyStudent->test;
				already[1] = true;
			}
			else
			{
				cout << "\nTest mark already exists. " << endl;
				cout << "Choose UPDATE option in MAIN MENU to update." << endl;
			}
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