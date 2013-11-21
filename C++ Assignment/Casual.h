/* filename:	Casual.h
 * purpose:		Contains the class declaration for the Casual Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#ifndef CASUAL_H
#define CASUAL_H

/* Include our 'Parent' so we can inherit from it. */
#include "StaffMember.h"

/* Represents an Casual in the program.
 * This class inherits from StaffMember - so Casuals have everything that StaffMembers have plus more.
 */
class Casual : public StaffMember
{
private:
	//instance members specific to Casuals only
	int _Hours;
	double _Rate;

public:
	
	/* Build an Casual Object.
	 * - Calls the StaffMember(string, string) constructor passing "Casual" as a type.
	 * - thanks to the StaffMember(string, string) contructor the Casual gets a unique Id.
	 * - used when creating a new Casual from the program menu/code.
	 * params:
	 *			string name = the name for this new StaffMember.
	 *			
	 */
	Casual(string name, int Hours, double _Rate, double wage);

	/* Build an Casual Object.
	 * - Calls the StaffMember(int, string, string) constructor passing "Casual" as a type.
	 * - used when creating a new Casual from the program menu/code.
	 * params:
	 *			int id = this Casuals existing ID.
	 *			string name = the name for this new Casual.
	 *			
	 */
	Casual(int id, string name, int Hours, double _Rate, double wage);

	/* unsigned int get_Hours(void)
	 * - get the number of Hours this Casual works.
	 * params:
	 *			n/a
	 * returns:
	 *			unsigned int - the number of hours the Casual works.
	 */
	unsigned int get_Hours();

	/* unsigned double get_Rate(void)
	 * - get the rate at which the Casual works
	 * params:
	 *			n/a
	 * returns:
	 *			unsigned double - the rate at which the Casual works.
	 */
	double get_Rate();

	/* void increment_Hours(void);
	 * - Adds to the hours the Casual works and times their wage by this hours to work our their weekly pay..
	 * params:
	 *			n/a
	 * returns:
	 *			n/a
	 */
	
	void set_Hours(unsigned int value);
	void set_rate(double value);
	
	virtual double wage();
	
	/* Destructor
	 */
};

#endif