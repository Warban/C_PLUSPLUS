/* filename:	Manager.cpp
 * purpose:		Contains the class implementation for the Manager Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#include "Manager.h"

//call the StaffMember Contructor.
Manager::Manager(string name,double salary, double wage) : StaffMember(name, "Manager")
{
	this ->_salary = salary;
}

//call the StaffMember Contructor.
Manager::Manager(int id, string name, double salary, double wage) : StaffMember(id, name, "Manager")
{
	this ->_salary = salary;
}

double Manager::get_salary()
{
		return this->_salary;
}


void Manager::set_salary(double value)
{
	this ->_salary = value;
}

double Manager::wage()
{
	return _salary / 25;
}