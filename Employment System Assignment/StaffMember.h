/* filename:	StaffMember.h
 * purpose:		Contains the class declaration for the StaffMember Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#ifndef STAFFMEMBER_H
#define STAFFMEMBER_H

/* StaffMember Hierarchy Includes. */
#include <string>
using namespace std;

/* Represents an StaffMember in the program.

 */
class StaffMember
{
	/* All sub classes will have private access to these members */
protected:
	// Instance Members
	int		_Id;
	string	_type;
	string	_name; 

	// Class Member - shared amongst all StaffMembers - 
	// any changes made by any StaffMember are seen by all StaffMembers.
private:
	static int _nextId;

public:
	
	/* Build an StaffMember Object.
	 * - Generates the id for the new object from the class member _nextId.
	 * - used when creating a new StaffMember from the program menu/code.
	 * params:
	 *			string name = the name for this new StaffMember.
	 *			string type = what type of StaffMember is this.
	 */
	/* auto id */
	StaffMember(string name, string type);

	/* Build an StaffMember Object.
	 * - Uses the given id for the new object, and sets _nextId to be one greater than the given Id..
	 * - used when creating a new StaffMember when loading from file..
	 * params:
	 *			int id = this StaffMembers existing ID.
	 *			string name = the name for this new StaffMember.
	 *			string type = what type of StaffMember is this.
	 */
	StaffMember(int id, string name, string type);

	/* int get_Id(void)
	 * - Gets this StaffMembers Id Number.
	 * params:
	 *			n/a
	 * returns: 
	 *			int - this StaffMembers Registration number.
	 */
	int get_Id();

	/* string get_name(void)
	 * - Gets this StaffMembers Name.
	 * params:
	 *			n/a
	 * returns: 
	 *			string - this StaffMembers name as a std::string object.
	 */
	string get_name();

	/* string get_type(void)
	 * - Gets what kind of StaffMember this object is.
	 * params:
	 *			n/a
	 * returns: 
	 *			int - this StaffMembers Registration number.
	 */
	string get_type();

	/* string set_name(string)
	 * - Give this StaffMember a new name.
	 * - The new name must not be zero length or have more than 20 characters..
	 * params:
	 *			string value = the desired name for this StaffMember.
	 * returns: 
	 *			n/a (void) - however if the given value fails the test, it will not be accepted.
	 */
	void set_name(string value);

	virtual double wage() = 0;

	/* Destructor
	 * - virtual for safety.
	 */
};

#endif