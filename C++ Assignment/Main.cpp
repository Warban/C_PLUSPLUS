/* filename:	Company.cpp
 * purpose:		Contains the main function for the Company project.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#include "Company.h"
#include "StaffMember.h"
#include "Casual.h"
#include "Manager.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;


int showMenu();

void addDefaultTestData(Company* Store);

void loadCompany(Company* store);

void saveCompany(Company* Store);

void showReport(Company* Store);

void saveHtmlReport(Company* Store);

void saveCsvReport(Company* Store);

void addStaffMember(Company* Store);

void editStaffMember(Company* Store);

void deleteStaffMember(Company* Store);

int main()
{

	

	Company* Store = new Company("The Wonder Emporium");
	int iInput = 0;
	string sInput = "N";

	addDefaultTestData(Store);

	do
	{
		iInput = showMenu();
	
		
		switch(iInput)
		{
		case 1:
			showReport(Store);
			break;
		case 2:
			saveHtmlReport(Store);
			break;
		case 3:
			saveCsvReport(Store);
			break;
		case 4:
			loadCompany(Store);
			break;
		case 5:
			addStaffMember(Store);
			break;
		case 6:
			editStaffMember(Store);
			break;
		case 7:
			deleteStaffMember(Store);
			break;
		case 8:
			//saveCompany(Store);
			break;
		}
	}
	while(iInput !=9);
	delete Store;
	return 0;
}
	


int showMenu()
{
	int iInput = 0;

	cout << "ITC 140 Assignment 3 -Welcome to The Wonder Emporium!" << endl << endl;
	cout << "=====================================================" << endl << endl;
	cout << "Please select one of the numbers below for the action you which to perform" << endl;
	cout << "1- View report (Console)" << endl;
	cout << "2- View report (HTML)" <<endl;
	cout << "3- View report (CSV)" <<endl;
	cout << "4- Load Company from file" <<endl;
	cout << "5- Add new staff member" <<endl;
	cout << "6- Edit new staff member" <<endl;
	cout << "7- Remove an existing employee" <<endl;
	cout << "8- Save current data" <<endl;
	cout << "9- Exit Program" <<endl;
	cin >> iInput;

	return iInput;
}

void addDefaultTestData(Company* Store)
{
		Casual* casual1 = new Casual("Robert Metcalfe", 30, 20,23.50);
		Casual* casual2 = new Casual("gdsagsag", 20, 10,50);

		Manager* manager1 = new Manager("Bob Brown", 15000,2300);
		Manager* manager2 = new Manager("Robert Metcalfe", 20000,1500);

		

		Store->addStaffMember(casual1);
		Store->addStaffMember(casual2);
		Store->addStaffMember(manager1);
		Store->addStaffMember(manager2);
}

void showReport(Company* Store)
	{
		double totalWage =0;
		cout << "-- Show Report (Console)" << endl;

			//print the StaffMembers details from the Company.
	vector<StaffMember*> _allStaffMembers = Store->getAll();

	
	cout << "--------------------" << endl;
	cout << "ID\tType\tName\tWage" << endl;
	cout << "====================" << endl;
	for(unsigned int i = 0; i < _allStaffMembers.size(); i++)
	{
		StaffMember* temp = _allStaffMembers.at(i);
		cout << temp->get_Id() <<  "\t" << temp->get_name() << "\t" << temp->get_type() << "\t"<< temp->wage() << endl;

		totalWage+=temp->wage();
	}

		cout << "====================" << endl;
		cout << "Total Wage:\t\t\t" << endl;
		cout << "====================" << endl;
	}

void addStaffMember(Company* Store)
{
	string type = "";
	string name = "";
	int	id = 001;
	int	rate = 0;
	int menu = 0;
	double hrs = 0.0;
	double sal = 0.0;
	double wage = 0.0;
	
			system("CLS");
			cout << "-- Add new Staff Member" << endl;
			cout << "What kind of staff member do wish to add? M (Manager)/C (Casual)" << endl;
			cin >> type;

			if(type == "M")
			{
				cout << endl << "Please enter managers name:" << endl;
				cin >> name;

				cout << endl << "What is this managers salary?" << endl;
				cin >> sal;
				
				StaffMember* manager = new Manager(name, sal, wage);
				Store->addStaffMember(manager);
			}

			else if (type == "C")
			{
				cout << endl << "Please enter casuals name" << endl;
				cin >> name;

				cout << endl << "What is there hourly pay" <<endl;
				cin >> rate;

				cout << endl << "How many hours a week will the casual be working?" <<endl;
				cin >> hrs;

				StaffMember* casual = new Casual(name, hrs, rate, wage);
				Store->addStaffMember(casual);
			}

	showReport(Store);
}

void editStaffMember(Company* Store)
{
	string userInput = "";
	string type = "";
	string name = "";
	int	id = 001;
	int	rate = 0;
	int menu = 0;
	double hrs = 0.0;
	double sal = 0.0;
	double wage = 0.0;

	cout << "-- Edit existing Staff Member" << endl;
	showReport(Store);
	StaffMember* edit;
		
		do
		{
			cout << "Enter the ID of the staff you wish to change";
			cin >> id;

			edit = Store->getStaffMemberById(id);
		}
		while(edit == NULL);
	
	
		if(edit->get_type() == "Manager")
		{
			Manager* manager = (Manager*) edit;

			cout << "Do you wish to change the salary of this Manager? Y/N ";
			cin >> userInput;

			if(userInput == "Y")
			{
				cout << endl << "What will this Manager's annual salary be:" << endl;
				cin >> sal;

				manager->set_salary(sal);

				int ID = manager->get_Id();

				int POS = Store->findPositionById(ID);

				Store->_StaffMembers[POS] = manager;



			}

		}
		else if(edit->get_type() == "Casual")
		{
			Casual* casual = (Casual*)edit;

			cout << "Do you wish to change the hourly rate of this Casual? Y/N" <<endl;
			cin >> userInput;

			if(userInput == "Y")
			{
				cout << endl << "What is this casuals new hourly rate?" <<endl;
				cin >> rate;

				casual->set_rate(rate);

				int ID = casual->get_Id();

				int POS = Store->findPositionById(ID);

				Store->_StaffMembers[POS] = casual;
			}

			cout << "Do you wish to change the hours in which this casual works? Y/N" <<endl;
			cin >> userInput;

			if(userInput == "Y")
			{
				cout << endl << "How many hours will this casual work a week?" <<endl;
				cin >> hrs;

				casual->set_Hours(hrs);

				int ID = casual->get_Id();

				int POS = Store->findPositionById(ID);

				Store->_StaffMembers[POS] = casual;

			}
		}
}

void deleteStaffMember(Company* Store)
{
	cout << "-- Delete Staff Member" << endl;
	showReport(Store);
	int iInput = 0;
	cout <<"Please enter the id of the person to delete: >>";
	cin >> iInput;

	bool result = Store->removeStaffMember(iInput);
	if(!result)
	{
			cout << "Failed to remove Staff Member" << endl;
			system("PAUSE");
	}
}
		
	
void saveCsvReport(Company* Store){

	
	ofstream file;
	file.open ("outputCSV.csv");

	
	

	//print the StaffMembers details from the Company.
	vector<StaffMember*> _allStaffMembers = Store->getAll();

	

	for(unsigned int i = 0; i < _allStaffMembers.size(); i++)
	{
		StaffMember* temp = _allStaffMembers.at(i);
		file << temp->get_Id() <<  "," << temp->get_name() << "," << temp->get_type() << ","<< temp->wage() << endl;
	}
		
	return;

}

void saveHtmlReport(Company* Store){


	ofstream file;
	file.open ("outputhtml.html");

	

	//print the StaffMembers details from the Company.
	vector<StaffMember*> _allStaffMembers = Store->getAll();

	
	
	file << "<HTML>"<< endl;
	file << "<HEAD>"<< endl;
	file << "</HEAD>"<< endl;
	file << "</HEAD>"<< endl;
	file << "<BODY>"<< endl;
	
	file << "<TABLE border='1'>" << endl;

	

	

	for(unsigned int i = 0; i < _allStaffMembers.size(); i++)
	{
		file << "<TR>"<< endl;
		file << "<TD>"<< endl;
		StaffMember* temp = _allStaffMembers.at(i);
		
		file << temp->get_Id() <<  "</TD><TD>" << temp->get_name() << "</TD><TD>" << temp->get_type() << "</TD><TD>"<< temp->wage() << endl;
		file << "</TD>"<< endl;
		file << "</TR>"<< endl;
	}
		

			
	file << "</TABLE>";
	file << "</BODY>";
	file << "</HTML>";


	return;
	
	



}

void loadCompany(Company* Store){


	return;

}