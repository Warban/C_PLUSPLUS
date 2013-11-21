/* filename:	StaffMember.cpp
 * purpose:		Contains the class implementation for the StaffMember Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#include "StaffMember.h"


/* Initialise the static class Member Variables. */
int StaffMember::_nextId = 1;

/* Implement Member Functions. */
StaffMember::StaffMember(string name, string type)
{
	this->_name = name;
	this->_type = type;

	//set our id to the next one avaiable for StaffMembers..
	this->_Id = _nextId;

	//increment the nextId ready for the next StaffMember.
	_nextId++;
}

StaffMember::StaffMember(int id, string name, string type)
{
	this->_name = name;
	this->_type = type;

	//set the id to the given value.
	this->_Id = id;
	
	/* make sure that the class variable is bigger than my
	   id so that we dont get conflicting ID's */
	_nextId = this->_Id + 1;
}

int StaffMember::get_Id()
{
	return this->_Id;
}

string StaffMember::get_name()
{
	return this->_name;
}

string StaffMember::get_type()
{
	return this->_type;
}

void StaffMember::set_name(string value)
{
	if(value.length() > 0 && value.length() < 40)
	{
		this->_name = value;
	}
}
