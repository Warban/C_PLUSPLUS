/* filename:	Company.h
 * purpose:		Contains the class declaration for the Company Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */

#include "StaffMember.h"
#include "Casual.h"
#include "Manager.h"

#include <vector>
#include <string>
#include <fstream>
using namespace std;


/* Represents a Company in the program.
 * - Maintains a collection of StaffMembers that work for this company.
 * - StaffMembers are either Casuals or Managers.. 
 */
class Company
{
private:
	string _CompanyName;
	//store Casuals and Managers and StaffMember*
	

public:
	vector<StaffMember*> _StaffMembers;
	/* Build a Company.
	 * - sets the name to the given value.
	 * params:
	 *			string - the name for this Company.
	 */
	Company(string name);

	/* string get_CompanyName(void)
	 * params:
	 *			n/a
	 * returns:
	 *			string - the name of this street..
	 */
	string get_CompanyName();

	/* Add a given StaffMember to this Company vector.
	 * - StaffMember* can point to either a Casual or Manager.
	 * params:
	 *			StaffMember* - the StaffMember to add (Casual or Manager).
	 * returns:
	 *			n/a
	 */
	void addStaffMember(StaffMember* sm);

	/* Remove an StaffMember from this Company.
	 * - StaffMember to remove by ID.
	 * - removes the pointer from the vector and calls the StaffMembers destructor.
	 * params:
	 *			int ID - the id of the StaffMember to remove from the street.
	 * returns:
	 *			n/a
	 */
	bool removeStaffMember(int Id);

	/* Get an StaffMember by ID.
	 * params:
	 *			int Id - the id of the StaffMember to search for.
	 * returns:
	 *			StaffMember* - the StaffMember in this collection with the given ID.
	 *			null    - the no StaffMember has the given ID.
	 */


	StaffMember* getStaffMemberById(int Id);

	vector<StaffMember*>& getAll();

	/* Find the position of an StaffMember in the vector by ID.
	 * - the StaffMember by ID.
	 * params:
	 *			int Id - the id of the StaffMember to search for.
	 * returns:
	 *			int - '-1' if the StaffMember is not found.
	 *				  the position of the StaffMember in the vector.
	 */


	int findPositionById(int Id);
private:
	


	/* Destructor
	 * - Used to free up the dynamic memory used by the 
	 *   StaffMember* in the vector that this class maintains.
	 */

public:
	~Company();
};