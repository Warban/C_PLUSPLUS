/* filename:	Casual.cpp
 * purpose:		Contains the class implementation for the Casual Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		08/05/2012
 */
#include "Casual.h"

//call the StaffMember Contructor.
Casual::Casual(string name, int Hours, double Rate, double wage) : StaffMember(name, "Casual")
{
	this->_Hours = Hours;
	this ->_Rate = Rate;
}

//call the StaffMember Contructor.
Casual::Casual(int id, string name, int Hours, double Rate, double wage) : StaffMember(id, name, "Casual")
{
	this->_Hours = Hours;
	this ->_Rate = Rate;
}

unsigned int Casual::get_Hours()
{
	return this->_Hours;
}

double Casual::get_Rate()
{
		return this->_Rate;
}

void Casual::set_Hours(unsigned int value)
{
	this ->_Hours = value;
}

void Casual::set_rate(double value)
{
	this ->_Rate = value;
}

double Casual::wage()
{
	return _Hours * _Rate;
}

