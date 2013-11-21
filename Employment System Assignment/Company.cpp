/* filename:	Company.cpp
 * purpose:		Contains the class implementation for the Company Class.
 * author:		Robert Metcalfe - 11420940.
 * date:		14/05/2012
 */
#include "Company.h"


 Company::Company(string name)
{
	this->_CompanyName = name;
}

string  Company::get_CompanyName()
{
	return this->_CompanyName;
}

void  Company::addStaffMember(StaffMember* sm)
{
	this->_StaffMembers.push_back(sm);
}

bool  Company::removeStaffMember(int Id)
{
	int position = findPositionById(Id);

	if(position != -1)
	{

		//remove the pointer from the vector.
		_StaffMembers.erase(_StaffMembers.begin() + position);
		return true;
	}
	return false;

}

StaffMember* Company::getStaffMemberById(int Id)
{
	int position = findPositionById(Id);

	if(position != -1)
	{
		return _StaffMembers.at(position);
	}

	return NULL;
}

int Company::findPositionById(int Id)
{
	//look for an StaffMember with this id.. 
	for(unsigned int i = 0; i < this->_StaffMembers.size(); i++)
	{
		if(_StaffMembers.at(i)->get_Id() == Id)
		{
			return i;
		}
	}

	//couldnt find one.. so return an 'error code'
	return -1;
}

vector<StaffMember*>& Company::getAll()
{
	return this->_StaffMembers;
}

Company::~Company()
{
	_StaffMembers.clear();
}