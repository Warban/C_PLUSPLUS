/* filename:	Manager.h
 * purpose:		Contains the class declaration for the Manager Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#ifndef MANAGER_H
#define MANAGER_H

/* Include our 'Parent' so we can inherit from it. */
#include "StaffMember.h"

/* Represents an Manager in the program.
 * This class inherits from StaffMember - so Managers have everything that StaffMembers have plus more.
 */
class Manager : public StaffMember
{
private:
	//instance members specific to Managers only
	double _salary;

public:
	
	/* Build an Manager Object.
	 * - Calls the StaffMember(string, string) constructor passing "Manager" as a type.
	 * - thanks to the StaffMember(string, string) contructor the Manager gets a unique Id.
	 * - used when creating a new Manager from the program menu/code.
	 * params:
	 *			string name = the name for this new StaffMember.
	 *			
	 */
	Manager(string name, double _Salary, double wage);

	/* Build an Manager Object.
	 * - Calls the StaffMember(int, string, string) constructor passing "Manager" as a type.
	 * - used when creating a new Manager from the program menu/code.
	 * params:
	 *			int id = this Managers existing ID.
	 *			string name = the name for this new Manager.
	 *			
	 */
	Manager(int id, string name, double _salary, double wage);



	/* unsigned double get_Salary(void)
	 * - get the salary at which the Manager works
	 * params:
	 *			n/a
	 * returns:
	 *			unsigned double - the salary at which the Manager works.
	 */
	double get_salary();

	/* void increment_Hours(void);
	 * - Adds to the hours the Manager works and times their wage by this hours to work our their weekly pay..
	 * params:
	 *			n/a
	 * returns:
	 *			n/a
	 */
	
	void set_salary(double value);
	
	virtual double wage();
	
	/* Destructor
	 */
};

#endif